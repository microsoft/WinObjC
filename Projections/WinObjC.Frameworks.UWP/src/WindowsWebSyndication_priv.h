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

// WindowsWebSyndication_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsDataXmlDom_priv.h"
#include "WindowsSecurityCredentials_priv.h"
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationAttributeFactory> WWSISyndicationAttributeFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationNodeFactory> WWSISyndicationNodeFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationGeneratorFactory> WWSISyndicationGeneratorFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationTextFactory> WWSISyndicationTextFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationContentFactory> WWSISyndicationContentFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationLinkFactory> WWSISyndicationLinkFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationPersonFactory> WWSISyndicationPersonFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationCategoryFactory> WWSISyndicationCategoryFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeedFactory> WWSISyndicationFeedFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationItemFactory> WWSISyndicationItemFactory_inst();
static ComPtr<ABI::Windows::Web::Syndication::ISyndicationClientFactory> WWSISyndicationClientFactory_inst();
ComPtr<ABI::Windows::Web::Syndication::ISyndicationErrorStatics> WWSISyndicationErrorStatics_inst();
@interface WWSRetrievalProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Web::Syndication::RetrievalProgress)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Web::Syndication::RetrievalProgress*)internalStruct;
@end
inline WWSRetrievalProgress* WWSRetrievalProgress_create(ABI::Windows::Web::Syndication::RetrievalProgress val) {
    return [WWSRetrievalProgress createWith:val];
}
@interface WWSTransferProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Web::Syndication::TransferProgress)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Web::Syndication::TransferProgress*)internalStruct;
@end
inline WWSTransferProgress* WWSTransferProgress_create(ABI::Windows::Web::Syndication::TransferProgress val) {
    return [WWSTransferProgress createWith:val];
}

id RTProxiedNSMutableArray_RTObject_WWSISyndicationNode_create(IInspectable* val);
id RTProxiedNSMutableArray_WWSSyndicationAttribute_create(IInspectable* val);
id RTProxiedNSMutableArray_WWSSyndicationCategory_create(IInspectable* val);
id RTProxiedNSMutableArray_WWSSyndicationItem_create(IInspectable* val);
id RTProxiedNSMutableArray_WWSSyndicationLink_create(IInspectable* val);
id RTProxiedNSMutableArray_WWSSyndicationPerson_create(IInspectable* val);

@class RTProxiedNSMutableArray_RTObject_WWSISyndicationNode, RTProxiedNSMutableArray_WWSSyndicationAttribute,
    RTProxiedNSMutableArray_WWSSyndicationCategory;
@class RTProxiedNSMutableArray_WWSSyndicationItem, RTProxiedNSMutableArray_WWSSyndicationLink, RTProxiedNSMutableArray_WWSSyndicationPerson;
