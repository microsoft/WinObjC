//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

//
//  Template class which implements a symbol table that reflects the
//  Windows Runtime type case sensitivity rules.
//
#pragma once

#include <map>
#include <memory>
#include <ios>
#include <iostream>

template <class TString, class TNode>
class SymbolTable;
template <class TString, class TNode>
class SymbolNode;

//  Note that this function does *not* return anything.  This is quite
//  intentional - if we ever hit the templated version, it's an error.
template <class T>
bool CompareStringLess(T left, T right) {
    assert(FALSE);
};

//
//  A symbol node is either an intermediate node (in which case it's a
//  string) or a leaf node (in which case it's a node type).
//
template <class TString, class TNode>
class SymbolNode {
    //  Compare two nodes case insensitively.
    struct Less : public std::less<TString> {
        bool operator()(const TString& left, const TString& right) const {
            return CompareStringLess<const TString&>(left, right);
        }
    };

public:
    bool FLeafNode() const {
        return _fLeafNode;
    }

    const TNode& Leaf() {
        assert(_fLeafNode);
        return _nodeLeaf;
    }

    SymbolNode() {
    }
    SymbolNode(/*const TString &strName, */ const TNode node) : _fLeafNode(true), _nodeLeaf(node) {
    }

    bool FindSymbol(_In_ const TString& strSymbol, _Out_ std::shared_ptr<SymbolNode>& spSymbol, _Out_ TString* nameFound = nullptr) const {
        auto tNode = _symbolTable.find(strSymbol);
        if (tNode != _symbolTable.end()) {
            spSymbol = tNode->second;
            if (nameFound) {
                *nameFound = tNode->first;
            }
            return true;
        }
        return false;
    }

    void InsertNode(const TString strSymbol, const std::shared_ptr<SymbolNode>& spSymbol) {
        _symbolTable.insert(std::pair<const TString, std::shared_ptr<SymbolNode>>(strSymbol, spSymbol));
    }

private:
    //  Copy Constructor and move constructors. Included for completeness mostly.
    SymbolNode(const SymbolNode& that) : _fLeafNode(that._fLeafNode), _nodeLeaf(that._nodeLeaf), _symbolTable(that._symbolTable) {
    }
    SymbolNode(const SymbolNode&& that)
        : _fLeafNode(that._fLeafNode), _nodeLeaf(std::move(that._nodeLeaf)), _symbolTable(std::move(that._symbolTable)) {
    }
    bool _fLeafNode = false;
    TNode _nodeLeaf;
    std::map<const TString, std::shared_ptr<SymbolNode>, Less> _symbolTable;
};

//
//  Template class which implements a symbol table.  It takes two
//  template parameters - a string class (either std::string or
//  std::wstring) and a node type (either const named_node * (for
//  midlrt) or std::shared_ptr<CMetadataType> (for mdmerge)).
//
//
//  The MIDLRT case sensitivity algorithm matches elements of a type
//  name piece-wise.  In other words, if you have two types:
//
//          Foo.Bar.Baz
// and
//          Foo.BAR.Boo.
//
//  The algorithm first matches "Foo" against "Foo", then "Bar" against
//  "BAR" and finally "Baz" against "Boo".
//
//  Each of the comparisons is done case insensitively (using the
//  invariant culture).  If any two elements match, we will combine the
//  two nodes.
//
//  When inserting into the tree, if we find a node which has an
//  intermediate element ("Foo" or "Bar" in the example above) whose
//  name differs from an existing element only by case, we will return
//  the distinguished error:  FailedCaseInsensitiveMatch.
//
//  If we find a type in the table whose name matches an existing type
//  case insensitively, we will fail the request with
//  FailedAlreadyPresent.
//
//  If a type name found matches a prefix of another type (for instance
//  if the type "Foo.Bar" was added), we will fail the insert request
//  with FailedIsIntermediateNode.
//
template <class TString, class TNode>
class WinrtSymbolTable {
    std::shared_ptr<SymbolNode<TString, TNode>> _nodeMap;

public:
    enum class InsertResult { Inserted, FailedAlreadyPresent, FailedIsIntermediateNode, FailedCaseInsensitiveMatch };

    WinrtSymbolTable() : _nodeMap(new SymbolNode<TString, TNode>()) {
    }

    size_t ExtractElement(const TString& strSymbol, const size_t iPosBegin, __out TString& strElement) const {
        size_t iPosEnd = strSymbol.find('.', iPosBegin);
        //
        //  Extract the next element of the string.
        //
        if (iPosEnd != TString::npos) {
            strElement = strSymbol.substr(iPosBegin, iPosEnd - iPosBegin);
        } else {
            strElement = strSymbol.substr(iPosBegin);
        }
        return iPosEnd;
    }

    bool FindSymbol(const TString& strSymbol, __out TNode& value) const {
        std::shared_ptr<SymbolNode<TString, TNode>> spNode(_nodeMap);

        if (spNode) {
            size_t iPosBegin = 0;
            size_t iPosEnd = 0;
            do {
                TString strElement;
                iPosEnd = ExtractElement(strSymbol, iPosBegin, strElement);
                iPosBegin = iPosEnd + 1;

                //
                //  Look that element up.  If we found it, we might be
                //  done.
                //
                //  If we didn't find it, fail the lookup.
                //
                std::shared_ptr<SymbolNode<TString, TNode>> spNodeFound;
                if (spNode->FindSymbol(strElement, spNodeFound)) {
                    //  If we hit a leaf node, we're done, return that we
                    //  found the node.
                    if (spNodeFound->FLeafNode()) {
                        value = spNodeFound->Leaf();
                        return true;
                    }
                } else {
                    //  We didn't find the node during our lookup, fail the
                    //  lookup.
                    return false;
                }
                //
                //  We found the node, keep looking until we hit the end of
                //  the string.
                //
                spNode = spNodeFound;
            } while (iPosEnd != TString::npos);
        }
        return false;
    }

    enum class InsertResult InsertSymbol(const TString& strSymbol, TNode node) {
        std::shared_ptr<SymbolNode<TString, TNode>> spNode(_nodeMap);

        size_t iPosBegin = 0;
        size_t iPosEnd = 0;
        do {
            TString strElement;
            iPosEnd = ExtractElement(strSymbol, iPosBegin, strElement);
            iPosBegin = iPosEnd + 1;

            //  Look that element up.
            std::shared_ptr<SymbolNode<TString, TNode>> spNodeFound;
            TString nameFound;
            if (spNode->FindSymbol(strElement, spNodeFound, &nameFound)) {
                //  We found a node whose name matches this node.
                //  If we matched case insensitively, we need to fail
                //  the call (because it means that an intermediate
                //  node
                if (!spNodeFound->FLeafNode() && strElement != nameFound) {
                    return InsertResult::FailedCaseInsensitiveMatch;
                }

                //  If we're at the end of the string, we need to
                //  fail the call - there's no way there are other
                //  nodes on the list.  Return a distinguished
                //  error depending on whether we're at a leaf node
                //  or at an intermediate node.
                if (iPosEnd == TString::npos) {
                    //  We found a leaf node - that means that the type
                    //  was already present.
                    if (spNodeFound->FLeafNode()) {
                        return InsertResult::FailedAlreadyPresent;
                    } else {
                        return InsertResult::FailedIsIntermediateNode;
                    }
                }
                //  Skip to the next node in the string.
                spNode = spNodeFound;
            } else {
                std::shared_ptr<SymbolNode<TString, TNode>> spNewNode;
                //  If we're at the end of the source string, we
                //  want to insert a leaf node.
                if (iPosEnd == TString::npos) {
                    // create a leaf node.
                    spNewNode.reset(new SymbolNode<TString, TNode>(node));
                } else {
                    //  Insert an intermediate node.
                    spNewNode.reset(new SymbolNode<TString, TNode>());
                }
                //  Insert the new node
                spNode->InsertNode(strElement, spNewNode);

                spNode = spNewNode;
            }
            //  Keep looking until we hit the end of
            //  the string.
        } while (iPosEnd != TString::npos);

        return InsertResult::Inserted;
    }
};
