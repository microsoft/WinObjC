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

#include "Starboard.h"
#include <utility>
#include <functional>

#ifdef __OBJC__
#pragma push_macro("interface")
#ifndef interface
#define interface struct
#endif
#pragma push_macro("Nil")
#undef Nil
#endif

#include <COMIncludes.h>
#include <wrl\client.h>
#include <wrl\async.h>
#include <wrl\event.h>
#include <wrl\wrappers\corewrappers.h>
#include <windows.foundation.h>
#include <windows.foundation.collections.h>
#include <COMIncludes_End.h>

namespace WRLHelpers {

namespace Private {

// Dispatcher class template declaration for generically working with WRL types
// Main issue is that ABI types will either be IFoo* or HSTRING or a few other
// value types. IFoo* and HSTRING have similar lifetime concerns but don't have a
// common type to work with them generically. This solves that by using a type that has a
// .Get() and .GetAddressOf() to get and assign to them.
template <typename T>
struct TypeTraits;

template <class Q>
struct TypeTraits<Q*> {
    using type = Microsoft::WRL::ComPtr<Q>;
};

template <>
struct TypeTraits<HSTRING> {
    using type = Microsoft::WRL::Wrappers::HString;
};
}

// Helps with iterating an iterable container (like a vector, map, etc.)  Calls a functor on each
// element in the iterable range with the value it found.
template <typename T, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IIterable<T>* iterable, Q&& functor) {
    boolean more;
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterator<T>> iter;

    RETURN_IF_FAILED(iterable->First(&iter));
    RETURN_IF_FAILED(iter->get_HasCurrent(&more));

    while (more) {
        boolean stop = false;
        typename Private::TypeTraits<T>::type current;

        RETURN_IF_FAILED(iter->get_Current(current.GetAddressOf()));

        RETURN_IF_FAILED(functor(current.Get(), &stop));

        if (stop) {
            break;
        }

        RETURN_IF_FAILED(iter->MoveNext(&more));
    }

    return S_OK;
}

// Helps with iterating an IVector<T>. Calls a functor on each element with the value it found.
template <typename T, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IVector<T>* vector, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<T>> iter;

    RETURN_IF_FAILED(vector->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating an IVectorView<T>. Calls a functor on each element with the value it found.
template <typename T, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IVectorView<T>* vector, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<T>> iter;

    RETURN_IF_FAILED(vector->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating collections.  Calls a functor on each element with the value it found.
// Required because the other overloads take M*, but ComPtr<M> has no implicit conversion to M*.
template <typename T, typename Q>
HRESULT ForEach(const Microsoft::WRL::ComPtr<T>& source, Q&& functor) {
    return ForEach(source.Get(), functor);
}

// Helps with iterating an IPropertySet. Calls a functor on each element with the value it found.
template <typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IPropertySet* propertySet, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<
        ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING, IInspectable*>*>> iter;

    RETURN_IF_FAILED(propertySet->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating an IMapView. Calls a functor on each element with the value it found.
template <typename K, typename V, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IMapView<K, V>* mapView, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<K, V>*>>
        iter;

    RETURN_IF_FAILED(mapView->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating an IMap. Calls a functor on each element with the value it found.
template <typename K, typename V, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IMap<K, V>* map, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<K, V>*>>
        iter;

    RETURN_IF_FAILED(map->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

#pragma region Async Helpers
struct ActionCallback : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
                                                            ABI::Windows::Foundation::IAsyncActionCompletedHandler> {
public:
    HRESULT RuntimeClassInitialize() {
        m_completedEvent = CreateEventEx(nullptr, nullptr, 0, EVENT_ALL_ACCESS);
        RETURN_LAST_ERROR_IF_FALSE(m_completedEvent != NULL);

        return S_OK;
    }

    ~ActionCallback() {
        if (m_completedEvent != NULL) {
            CloseHandle(m_completedEvent);
            m_completedEvent = NULL;
        }
    }

    IFACEMETHOD(Invoke)(ABI::Windows::Foundation::IAsyncAction* pAction, AsyncStatus status) override {
        m_result = pAction->GetResults();
        SetEvent(m_completedEvent);

        return S_OK;
    }

    void Wait() {
        THROW_LAST_ERROR_IF(WAIT_FAILED == WaitForMultipleObjects(1, &m_completedEvent, TRUE, INFINITE));
    }

    HRESULT m_result;
    HANDLE m_completedEvent;
};

template <typename TI, typename TPFN, typename... Args>
HRESULT Await(TI* pThing, TPFN pfn, Args&&... args) {
    Microsoft::WRL::ComPtr<ActionCallback> completion;
    RETURN_IF_FAILED(Microsoft::WRL::MakeAndInitialize<ActionCallback>(&completion));

    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncAction> action;
    RETURN_IF_FAILED((pThing->*pfn)(std::forward<Args>(args)..., &action));
    RETURN_IF_FAILED(action->put_Completed(completion.Get()));

    completion->Wait();

    RETURN_IF_FAILED(completion->m_result);

    return S_OK;
}

template <typename T>
struct OperationCallback : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
                                                               ABI::Windows::Foundation::IAsyncOperationCompletedHandler<T>> {
public:
    HRESULT RuntimeClassInitialize() {
        m_completedEvent = CreateEventEx(nullptr, nullptr, 0, EVENT_ALL_ACCESS);
        RETURN_LAST_ERROR_IF_FALSE(m_completedEvent != NULL);

        return S_OK;
    }

    ~OperationCallback() {
        if (m_completedEvent != NULL) {
            CloseHandle(m_completedEvent);
            m_completedEvent = NULL;
        }
    }

    IFACEMETHOD(Invoke)(ABI::Windows::Foundation::IAsyncOperation<T>* pOp, AsyncStatus status) {
        m_op = pOp;
        SetEvent(m_completedEvent);
        return S_OK;
    }

    void Wait() {
        THROW_LAST_ERROR_IF(WAIT_FAILED == WaitForMultipleObjects(1, &m_completedEvent, TRUE, INFINITE));
    }

    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncOperation<T>> m_op;
    HANDLE m_completedEvent;
};

template <typename InnerType, typename OutThing>
HRESULT AwaitOperationResult(ABI::Windows::Foundation::IAsyncOperation<InnerType>* pOperation, OutThing&& out) {
    Microsoft::WRL::ComPtr<OperationCallback<InnerType>> completer;
    RETURN_IF_FAILED(Microsoft::WRL::MakeAndInitialize<OperationCallback<InnerType>>(&completer));

    RETURN_IF_FAILED(pOperation->put_Completed(completer.Get()));
    completer->Wait();

    RETURN_IF_FAILED(pOperation->GetResults(out));

    completer->m_op = nullptr;

    return S_OK;
}

template <typename InnerType, typename StartThing, typename OutThing>
HRESULT AwaitResultHelper(const StartThing& starter, OutThing&& out) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncOperation<InnerType>> operation;
    RETURN_IF_FAILED((starter)(&operation));

    return AwaitOperationResult(operation.Get(), out);
}

template <typename TI, typename OI, typename RI>
HRESULT AwaitResult(TI* pThing, HRESULT (STDMETHODCALLTYPE TI::*pfn)(ABI::Windows::Foundation::IAsyncOperation<OI>**), RI&& out) {
    return AwaitResultHelper<OI>([&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) { return (pThing->*pfn)(ppOp); }, out);
}

template <typename TI, typename OI, typename P1, typename A1, typename RI>
HRESULT AwaitResult(TI* pThing,
                    HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, ABI::Windows::Foundation::IAsyncOperation<OI>**),
                    A1&& p1,
                    RI&& out) {
    return AwaitResultHelper<OI>(
        [&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) { return (pThing->*pfn)(std::forward<A1>(p1), ppOp); }, out);
}

template <typename TI, typename OI, typename P1, typename P2, typename A1, typename A2, typename RI>
HRESULT AwaitResult(
    TI* pThing, HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, P2, ABI::Windows::Foundation::IAsyncOperation<OI>**), A1&& p1, A2&& p2, RI&& out) {
    return AwaitResultHelper<OI>([&](ABI::Windows::Foundation::IAsyncOperation<OI>**
                                         ppOp) { return (pThing->*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), ppOp); },
                                 out);
}

template <typename TI, typename OI, typename P1, typename P2, typename P3, typename A1, typename A2, typename A3, typename RI>
HRESULT AwaitResult(TI* pThing,
                    HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, P2, P3, ABI::Windows::Foundation::IAsyncOperation<OI>**),
                    A1&& p1,
                    A2&& p2,
                    A3&& p3,
                    RI&& out) {
    return AwaitResultHelper<OI>(
        [&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) {
            return (pThing->*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), std::forward<A3>(p3), ppOp);
        },
        out);
}

template <typename OI,
          typename P1,
          typename P2,
          typename P3,
          typename P4,
          typename P5,
          typename A1,
          typename A2,
          typename A3,
          typename A4,
          typename A5,
          typename RI>
HRESULT AwaitStaticResult(HRESULT(STDMETHODCALLTYPE* pfn)(P1, P2, P3, P4, P5, ABI::Windows::Foundation::IAsyncOperation<OI>**),
                          A1&& p1,
                          A2&& p2,
                          A3&& p3,
                          A4&& p4,
                          A5&& p5,
                          RI&& out) {
    return AwaitResultHelper<OI>(
        [&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) {
            return (
                *pfn)(std::forward<A1>(p1), std::forward<A2>(p2), std::forward<A3>(p3), std::forward<A4>(p4), std::forward<A5>(p5), ppOp);
        },
        out);
}

template <typename TI,
          typename OI,
          typename P1,
          typename P2,
          typename P3,
          typename P4,
          typename A1,
          typename A2,
          typename A3,
          typename A4,
          typename RI>
HRESULT AwaitResult(TI* pThing,
                    HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, P2, P3, P4, ABI::Windows::Foundation::IAsyncOperation<OI>**),
                    A1&& p1,
                    A2&& p2,
                    A3&& p3,
                    A4&& p4,
                    RI&& out) {
    return AwaitResultHelper<OI>(
        [&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) {
            return (pThing->*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), std::forward<A3>(p3), std::forward<A4>(p4), ppOp);
        },
        out);
}

template <typename OI, typename RI>
HRESULT AwaitStaticResult(HRESULT(STDMETHODCALLTYPE* pfn)(ABI::Windows::Foundation::IAsyncOperation<OI>**), RI&& out) {
    return AwaitResultHelper<OI>([&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) { return (*pfn)(ppOp); }, out);
}

template <typename OI, typename P1, typename A1, typename RI>
HRESULT AwaitStaticResult(HRESULT(STDMETHODCALLTYPE* pfn)(P1, ABI::Windows::Foundation::IAsyncOperation<OI>**), A1&& p1, RI&& out) {
    return AwaitResultHelper<OI>([&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) { return (*pfn)(std::forward<A1>(p1), ppOp); },
                                 out);
}

template <typename OI, typename P1, typename P2, typename A1, typename A2, typename RI>
HRESULT AwaitStaticResult(HRESULT(STDMETHODCALLTYPE* pfn)(P1, P2, ABI::Windows::Foundation::IAsyncOperation<OI>**),
                          A1&& p1,
                          A2&& p2,
                          RI&& out) {
    return AwaitResultHelper<OI>(
        [&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) { return (*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), ppOp); },
        out);
}

template <typename OI, typename P1, typename P2, typename P3, typename A1, typename A2, typename A3, typename RI>
HRESULT AwaitStaticResult(
    HRESULT(STDMETHODCALLTYPE* pfn)(P1, P2, P3, ABI::Windows::Foundation::IAsyncOperation<OI>**), A1&& p1, A2&& p2, A3&& p3, RI&& out) {
    return AwaitResultHelper<OI>([&](ABI::Windows::Foundation::IAsyncOperation<OI>**
                                         ppOp) { return (*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), std::forward<A3>(p3), ppOp); },
                                 out);
}

template <typename OI, typename P1, typename P2, typename P3, typename P4, typename A1, typename A2, typename A3, typename A4, typename RI>
HRESULT AwaitStaticResult(HRESULT(STDMETHODCALLTYPE* pfn)(P1, P2, P3, P4, ABI::Windows::Foundation::IAsyncOperation<OI>**),
                          A1&& p1,
                          A2&& p2,
                          A3&& p3,
                          A4&& p4,
                          RI&& out) {
    return AwaitResultHelper<OI>(
        [&](ABI::Windows::Foundation::IAsyncOperation<OI>** ppOp) {
            return (*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), std::forward<A3>(p3), std::forward<A4>(p4), ppOp);
        },
        out);
}

template <typename T, typename Q>
struct ProgressCompleteCallback
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
                                          ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<T, Q>> {
public:
    HRESULT RuntimeClassInitialize() {
        m_completedEvent = CreateEventEx(nullptr, nullptr, 0, EVENT_ALL_ACCESS);
        RETURN_LAST_ERROR_IF_FALSE(m_completedEvent != NULL);

        return S_OK;
    }

    ~ProgressCompleteCallback() {
        if (m_completedEvent != NULL) {
            CloseHandle(m_completedEvent);
            m_completedEvent = NULL;
        }
    }

    IFACEMETHOD(Invoke)(ABI::Windows::Foundation::IAsyncOperationWithProgress<T, Q>* pOp, AsyncStatus status) override {
        m_op = pOp;
        SetEvent(m_completedEvent);
        return S_OK;
    }

    void Wait() {
        THROW_LAST_ERROR_IF(WAIT_FAILED == WaitForMultipleObjects(1, &m_completedEvent, TRUE, INFINITE));
    }

    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<T, Q>> m_op;
    HANDLE m_completedEvent;
};

template <typename InnerType, typename ProgressType, typename StartThing, typename OutThing>
HRESULT AwaitProgressCompleteHelper(const StartThing& starter, OutThing&& out) {
    typedef ProgressCompleteCallback<InnerType, ProgressType> ProgressCallback;
    Microsoft::WRL::ComPtr<ProgressCallback> completer;
    RETURN_IF_FAILED(Microsoft::WRL::MakeAndInitialize<ProgressCallback>(&completer));

    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<InnerType, ProgressType>> operation;
    RETURN_IF_FAILED((starter)(&operation));

    RETURN_IF_FAILED(operation->put_Completed(completer.Get()));
    completer->Wait();

    RETURN_IF_FAILED(operation->GetResults(out));

    completer->m_op = nullptr;

    return S_OK;
}

template <typename TI, typename OI, typename PI, typename RI>
HRESULT AwaitProgressComplete(TI* pThing,
                              HRESULT (STDMETHODCALLTYPE TI::*pfn)(ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>**),
                              RI&& out) {
    return AwaitProgressCompleteHelper<OI, PI>(
        [&](ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>** ppOp) { return (pThing->*pfn)(ppOp); }, out);
}

template <typename TI, typename OI, typename PI, typename P1, typename A1, typename RI>
HRESULT AwaitProgressComplete(TI* pThing,
                              HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>**),
                              A1&& p1,
                              RI&& out) {
    return AwaitProgressCompleteHelper<OI, PI>(
        [&](ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>** ppOp) { return (pThing->*pfn)(std::forward<A1>(p1), ppOp); },
        out);
}

template <typename TI, typename OI, typename PI, typename P1, typename P2, typename A1, typename A2, typename RI>
HRESULT AwaitProgressComplete(TI* pThing,
                              HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, P2, ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>**),
                              A1&& p1,
                              A2&& p2,
                              RI&& out) {
    return AwaitProgressCompleteHelper<OI, PI>([&](ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>**
                                                       ppOp) { return (pThing->*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), ppOp); },
                                               out);
}

template <typename TI, typename OI, typename PI, typename P1, typename P2, typename P3, typename A1, typename A2, typename A3, typename RI>
HRESULT AwaitProgressComplete(
    TI* pThing,
    HRESULT (STDMETHODCALLTYPE TI::*pfn)(P1, P2, P3, ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>**),
    A1&& p1,
    A2&& p2,
    A3&& p3,
    RI&& out) {
    return AwaitProgressCompleteHelper<OI, PI>(
        [&](ABI::Windows::Foundation::IAsyncOperationWithProgress<OI, PI>** ppOp) {
            return (pThing->*pfn)(std::forward<A1>(p1), std::forward<A2>(p2), std::forward<A3>(p3), ppOp);

        },
        out);
}

template <typename TDelegateInterface, typename... Args>
::Microsoft::WRL::ComPtr<TDelegateInterface> MakeAgileCallbackNoThrow(Args&&... args) WI_NOEXCEPT {
    using namespace Microsoft::WRL;
    return Callback<Implements<RuntimeClassFlags<ClassicCom>, TDelegateInterface, FtmBase>>(wistd::forward<Args>(args)...);
}

template <typename TDelegateInterface, typename... Args>
::Microsoft::WRL::ComPtr<TDelegateInterface> MakeAgileCallback(Args&&... args) {
    auto result = MakeAgileCallbackNoThrow<TDelegateInterface, Args...>(wistd::forward<Args>(args)...);
    THROW_IF_NULL_ALLOC(result);
    return result;
}

#pragma endregion
}

#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#endif
