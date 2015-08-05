//----------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All Rights Reserved
//----------------------------------------------------------------

PropSchemaGen

To be used only with ClangCompile. This generates an xml meant to be used with 
Visual Studio's PropSchema interface. Whereas Visual Studio's .Net tool 
components such as CL are generated from XMLs, we work the other way around. 

Everything is based on reflection. The Attributes are all defined in 
ClangCompile\PropertyPageAttributes.cs. 