//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <AudioToolbox/AudioToolboxExport.h>
#import <AudioUnit/AudioUnitProperties.h>
#import <AudioToolbox/AudioConverter.h>
#import <AudioUnit/AudioUnitComponent.h>

enum { kAUNodeInteraction_Connection = 1, kAUNodeInteraction_InputCallback = 2 };

enum {
    kAUGraphErr_NodeNotFound = -10860,
    kAUGraphErr_InvalidConnection = -10861,
    kAUGraphErr_OutputNodeErr = -10862,
    kAUGraphErr_CannotDoInCurrentContext = -10863,
    kAUGraphErr_InvalidAudioUnit = -10864
};

typedef SInt32 AUNode;
struct AudioUnitNodeConnection {
    AUNode sourceNode;
    UInt32 sourceOutputNumber;
    AUNode destNode;
    UInt32 destInputNumber;
};
typedef struct AudioUnitNodeConnection AUNodeConnection;
struct AUNodeRenderCallback {
    AUNode destNode;
    AudioUnitElement destInputNumber;
    AURenderCallbackStruct cback;
};
typedef struct AUNodeRenderCallback AUNodeRenderCallback;
struct AUNodeInteraction {
    UInt32 nodeInteractionType;
    union {
        AUNodeConnection connection;
        AUNodeRenderCallback inputCallback;
    } nodeInteraction;
};
typedef struct OpaqueAUGraph* AUGraph;
typedef struct AudioUnitNodeConnection AudioUnitNodeConnection;
typedef struct AUNodeInteraction AUNodeInteraction;

AUDIOTOOLBOX_EXPORT OSStatus AUGraphAddNode(AUGraph inGraph, const AudioComponentDescription* inDescription, AUNode* outNode) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphAddRenderNotify(AUGraph inGraph, AURenderCallback inCallback, void* inRefCon) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphClearConnections(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphClose(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphConnectNodeInput(
    AUGraph inGraph, AUNode inSourceNode, UInt32 inSourceOutputNumber, AUNode inDestNode, UInt32 inDestInputNumber) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphCountNodeInteractions(AUGraph inGraph, AUNode inNode, UInt32* outNumInteractions) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphDisconnectNodeInput(AUGraph inGraph, AUNode inDestNode, UInt32 inDestInputNumber) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetCPULoad(AUGraph inGraph, Float32* outAverageCPULoad) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetIndNode(AUGraph inGraph, UInt32 inIndex, AUNode* outNode) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetInteractionInfo(AUGraph inGraph,
                                                       UInt32 inInteractionIndex,
                                                       AUNodeInteraction* outInteraction) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetMaxCPULoad(AUGraph inGraph, Float32* outMaxLoad) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetNodeCount(AUGraph inGraph, UInt32* outNumberOfNodes) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetNodeInteractions(AUGraph inGraph,
                                                        AUNode inNode,
                                                        UInt32* ioNumInteractions,
                                                        AUNodeInteraction* outInteractions) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphGetNumberOfInteractions(AUGraph inGraph, UInt32* outNumInteractions) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphInitialize(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphIsInitialized(AUGraph inGraph, Boolean* outIsInitialized) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphIsOpen(AUGraph inGraph, Boolean* outIsOpen) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphIsRunning(AUGraph inGraph, Boolean* outIsRunning) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphNodeInfo(AUGraph inGraph,
                                             AUNode inNode,
                                             AudioComponentDescription* outDescription,
                                             AudioUnit _Nullable* outAudioUnit) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphOpen(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphRemoveNode(AUGraph inGraph, AUNode inNode) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphRemoveRenderNotify(AUGraph inGraph, AURenderCallback inCallback, void* inRefCon) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphSetNodeInputCallback(AUGraph inGraph,
                                                         AUNode inDestNode,
                                                         UInt32 inDestInputNumber,
                                                         const AURenderCallbackStruct* inInputCallback) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphStart(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphStop(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphUninitialize(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AUGraphUpdate(AUGraph inGraph, Boolean* outIsUpdated) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus DisposeAUGraph(AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus NewAUGraph(AUGraph _Nullable* outGraph) STUB_METHOD;