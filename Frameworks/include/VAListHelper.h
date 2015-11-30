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

#include <vector>
#include <type_traits>

template <typename T>
struct VATraits;

template <>
struct VATraits<id> {
    static bool IsTerminalObject(const id& item) {
        return (item == nil);
    }
};

template <typename TArg>
std::vector<typename std::remove_reference<typename std::remove_cv<TArg>::type>::type> ConvertVAListToVector(TArg&& firstItem,
                                                                                                             va_list& argumentList) {
    using DecayedType = typename std::remove_reference<typename std::remove_cv<TArg>::type>::type;

    std::vector<DecayedType> toReturn;
    if (!VATraits<DecayedType>::IsTerminalObject(firstItem)) {
        toReturn.emplace_back(firstItem);

        DecayedType currentArgument = va_arg(argumentList, DecayedType);

        while (!VATraits<DecayedType>::IsTerminalObject(currentArgument)) {
            toReturn.emplace_back(currentArgument);
            currentArgument = va_arg(argumentList, DecayedType);
        }
    }
    return toReturn;
}
