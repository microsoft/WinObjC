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

#pragma once

#define CLIPTREE_MAX_NODES 128

// These classes form what I'm calling a Cull Tree.  The basic idea is that for each
// quad that is part of the tree, we break 2D space up into nine separate regions with the
// quad at the center.  There can then be 8 child nodes

class CullTree;

class CullTreeNode
{
    CGPoint _min;
    CGPoint _max;
    float _depth;

    CullTreeNode *_children[9];

public:
    void Init(const CGPoint& min, const CGPoint& max, float depth);

    // Both functions return true if the quad should be drawn.
    bool InsertQuad(CullTree *parent, const CGPoint& quadMin, const CGPoint& quadMax, float depth);
    bool TestOpaque(const CGPoint& quadMin, const CGPoint& quadMax, float depth) const;
    bool TestAlpha(const CGPoint& quadMin, const CGPoint& quadMax, float depth) const;

protected:
    int ClassifyPoint(float x, float y) const;
    CGPoint ClipMin(const CGPoint& p, int childNum) const;
    CGPoint ClipMax(const CGPoint& p, int childNum) const;
};

class CullTree
{
    CullTreeNode _nodes[CLIPTREE_MAX_NODES];
    size_t       _numNodes;
    bool         _limitReached;

public:
    CullTree();
    ~CullTree();

    void Reset();

    // Both functions return true if the quad should be drawn.
    bool InsertQuad(const CGPoint& min, const CGPoint& max, float depth);
    bool TestAlpha(const CGPoint& min, const CGPoint& max, float depth) const;

    CullTreeNode *Alloc();
};
