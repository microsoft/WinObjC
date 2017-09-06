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

#pragma once

#include <cor.h>
#include <Windows.h>
#include <string>
#include <memory>
#include <wrl/def.h>
#include <wrl/client.h>
#include <atlbase.h>
#include <assert.h>

// STL:
#include <unordered_map>
#include <functional>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
#include <numeric>

#include <caparser.h>

#include <MetadataScope.h>
#include <ObjectModel.h>
typedef std::map<std::wstring, std::shared_ptr<ObjectModel::Symbol>> SymbolTable;
