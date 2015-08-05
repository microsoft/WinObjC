//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include <algorithm>

#include "Starboard.h"
#include "NativeUI/CullTree.h"

#define CURRENT_QUAD_IDX 4      // Index in the child array of the current quad region.
#define MIN_CULL_SIZE    100.0f // Minimum size of quad to be inserted into the cull tree

// The quad child indices are as follows:
//   x -->
//  y
//  |     0 | 1 | 2
//  |    ----------
//  v     3 | 4 | 5
//       ----------
//        6 | 7 | 8
//

void CullTreeNode::Init(const CGPoint& min, const CGPoint& max, float depth)
{
    _min = min;
    _max = max;
    _depth = depth;

    memset(_children, 0, sizeof(_children));
}

bool CullTreeNode::InsertQuad(CullTree *parent, const CGPoint& quadMin,
                              const CGPoint& quadMax, float quadDepth)
{
    int x1y1 = ClassifyPoint(quadMin.x, quadMin.y);
    int x1y2 = ClassifyPoint(quadMin.x, quadMax.y);
    int x2y1 = ClassifyPoint(quadMax.x, quadMin.y);
    int x2y2 = ClassifyPoint(quadMax.x, quadMax.y);

    // Check for complete occlusion.
    if (x1y1 == CURRENT_QUAD_IDX && x1y2 == CURRENT_QUAD_IDX &&
        x2y1 == CURRENT_QUAD_IDX && x2y2 == CURRENT_QUAD_IDX) return false;

    // Check children.  This is where things get a little weird.  We're basically
    // rasterizing across the 9 sub-regions of space and checking each child node.
    int rowStart = x1y1, rowEnd = x2y1;
    bool res = false;
    do {
        for (int i = rowStart; i <= rowEnd; i ++) {
            if (i == CURRENT_QUAD_IDX) continue;    // ignore current quad.
            if (_children[i]) {

                // Test against child.  If any one result is true, we need to draw.
                // But we want to make sure all child nodes perform the insert.
                bool childRes = _children[i]->InsertQuad(parent, ClipMin(quadMin, i),
                                                         ClipMax(quadMax, i), quadDepth);
                res = res || childRes;
            } else {

                // New child!
                CullTreeNode *n = parent->Alloc();
                if (n == NULL) return true;

                n->Init(ClipMin(quadMin, i), ClipMax(quadMax, i), quadDepth);
                _children[i] = n;
                res = true;
            }
        }
        rowStart += 3;
        rowEnd += 3;
    } while (rowStart <= x1y2);

    return res;
}

bool CullTreeNode::TestOpaque(const CGPoint& quadMin, const CGPoint& quadMax,
                             float quadDepth) const
{
    int x1y1 = ClassifyPoint(quadMin.x, quadMin.y);
    int x1y2 = ClassifyPoint(quadMin.x, quadMax.y);
    int x2y1 = ClassifyPoint(quadMax.x, quadMin.y);
    int x2y2 = ClassifyPoint(quadMax.x, quadMax.y);

    // Check for complete occlusion.
    if (x1y1 == CURRENT_QUAD_IDX && x1y2 == CURRENT_QUAD_IDX &&
        x2y1 == CURRENT_QUAD_IDX && x2y2 == CURRENT_QUAD_IDX) return false;

    // Check children.  This is where things get a little weird.  We're basically
    // rasterizing across the 9 sub-regions of space and checking each child node.
    int rowStart = x1y1, rowEnd = x2y1;
    do {
        for (int i = rowStart; i <= rowEnd; i ++) {
            if (i == CURRENT_QUAD_IDX) continue;    // ignore current quad.
            if (!_children[i]) return true;         // no child == space is unoccupied.

            if (_children[i]->TestOpaque(ClipMin(quadMin, i), ClipMax(quadMax, i),
                                        quadDepth)) return true;
        }
        rowStart += 3;
        rowEnd += 3;
    } while (rowStart <= x1y2);

    return false;
}

bool CullTreeNode::TestAlpha(const CGPoint& quadMin, const CGPoint& quadMax,
                             float quadDepth) const
{
    if (quadDepth >= _depth) return true; // ie, alpha blend occurred on or after I was drawn.

    int x1y1 = ClassifyPoint(quadMin.x, quadMin.y);
    int x1y2 = ClassifyPoint(quadMin.x, quadMax.y);
    int x2y1 = ClassifyPoint(quadMax.x, quadMin.y);
    int x2y2 = ClassifyPoint(quadMax.x, quadMax.y);

    // Check for complete occlusion.
    if (x1y1 == CURRENT_QUAD_IDX && x1y2 == CURRENT_QUAD_IDX &&
        x2y1 == CURRENT_QUAD_IDX && x2y2 == CURRENT_QUAD_IDX) return false;

    // Check children.  This is where things get a little weird.  We're basically
    // rasterizing across the 9 sub-regions of space and checking each child node.
    int rowStart = x1y1, rowEnd = x2y1;
    do {
        for (int i = rowStart; i <= rowEnd; i ++) {
            if (i == CURRENT_QUAD_IDX) continue;    // ignore current quad.
            if (!_children[i]) return true;         // no child == space is unoccupied.

            if (_children[i]->TestAlpha(ClipMin(quadMin, i), ClipMax(quadMax, i),
                                        quadDepth)) return true;
        }
        rowStart += 3;
        rowEnd += 3;
    } while (rowStart <= x1y2);

    return false;
}

// Determine child node number by table lookup on the less than/greater than test results.
int CullTreeNode::ClassifyPoint(float x, float y) const
{
    static int childIndices[16] = {
            // xltMin xltMax yltMin yltMax
        8,  // 0      0      0      0   bottom right
        5,  // 0      0      0      1   middle right
        -1, // 0      0      1      0   impossible
        2,  // 0      0      1      1   top right
        7,  // 0      1      0      0   bottom middle
        4,  // 0      1      0      1   exact middle (node's quad location)
        -1, // 0      1      1      0   impossible
        1,  // 0      1      1      1   top middle
        -1, // 1      0      0      0   impossible
        -1, // 1      0      0      1   impossible
        -1, // 1      0      1      0   impossible
        -1, // 1      0      1      1   impossible
        6,  // 1      1      0      0   bottom left
        3,  // 1      1      0      1   middle left
        -1, // 1      1      1      0   impossible
        0   // 1      1      1      1   top left
    };

    int xltMin = (x < _min.x)  ? 8 : 0;
    int xltMax = (x <= _max.x) ? 4 : 0;
    int yltMin = (y < _min.y)  ? 2 : 0;
    int yltMax = (y <= _max.y) ? 1 : 0;

    // TODO: BK: assert here!
    return childIndices[xltMin + xltMax + yltMin + yltMax];
}

CGPoint CullTreeNode::ClipMin(const CGPoint& p, int childNum) const
{
    CGPoint cp;

    switch (childNum) {
        case 1:
            cp.x = std::max(p.x, _min.x); cp.y = p.y;
            break;
        case 2:
            cp.x = std::max(p.x, _max.x); cp.y = p.y;
            break;
        case 3:
            cp.x = p.x; cp.y = std::max(p.y, _min.y);
            break;
        case 5:
            cp.x = std::max(p.x, _max.x); cp.y = std::max(p.y, _min.y);
            break;
        case 6:
            cp.x = p.x; cp.y = std::max(p.y, _max.y);
            break;
        case 7:
            cp.x = std::max(p.x, _min.x); cp.y = std::max(p.y, _max.y);
            break;
        case 8:
            cp.x = std::max(p.x, _max.x); cp.y = std::max(p.y, _max.y);
            break;
        default:
            cp = p;
            break;
    }

    return cp;
}

CGPoint CullTreeNode::ClipMax(const CGPoint& p, int childNum) const
{
    CGPoint cp;
    switch (childNum) {
        case 0:
            cp.x = std::min(p.x, _min.x); cp.y = std::min(p.y, _min.y);
            break;
        case 1:
            cp.x = std::min(p.x, _max.x); cp.y = std::min(p.y, _min.y);
            break;
        case 2:
            cp.x = p.x; cp.y = std::min(p.y, _min.y);
            break;
        case 3:
            cp.x = std::min(p.x, _min.x); cp.y = std::min(p.y, _max.y);
            break;
        case 5:
            cp.x = p.x; cp.y = std::min(p.y, _max.y);
            break;
        case 6:
            cp.x = std::min(p.x, _min.x); cp.y = p.y;
            break;
        case 7:
            cp.x = std::min(p.x, _max.x); cp.y = p.y;
            break;
        default:
            cp = p;
            break;
    }
    return cp;
}

CullTree::CullTree() :
    _numNodes(0),
    _limitReached(false)
{
}

CullTree::~CullTree()
{
}

void CullTree::Reset()
{
    _numNodes = 0;
    _limitReached = false;
}

bool CullTree::InsertQuad(const CGPoint& min, const CGPoint& max, float depth)
{
    if (!_numNodes) {
        CullTreeNode *n = Alloc();
        n->Init(min, max, depth);
        return true;
    }

    if ( fabs(min.x - max.x) < MIN_CULL_SIZE ||
         fabs(min.y - max.y) < MIN_CULL_SIZE ) {
        return _nodes[0].TestOpaque(min, max, depth);
    } else {
        return _nodes[0].InsertQuad(this, min, max, depth);
    }
}

bool CullTree::TestAlpha(const CGPoint& min, const CGPoint& max, float depth) const
{
    if (!_numNodes) return true;
    return _nodes[0].TestAlpha(min, max, depth);
}

CullTreeNode *CullTree::Alloc()
{
    if (_numNodes >= CLIPTREE_MAX_NODES) {

        // no log spam, please.
        if (!_limitReached) {
            EbrDebugLog("WARNING: max number of clip tree nodes reached!\n");
            _limitReached = true;
        }
        return NULL;
    }

    CullTreeNode *res = _nodes + _numNodes;
    _numNodes++;

    return res;
}
