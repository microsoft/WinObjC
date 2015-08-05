#include "pch.h"
#include "Simple_Instancing_winrt.h"
#include "BasicTimer.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace concurrency;

PFNGLVERTEXATTRIBDIVISORANGLEPROC glVertexAttribDivisorANGLE;
PFNGLDRAWARRAYSINSTANCEDANGLEPROC glDrawArraysInstancedANGLE;
PFNGLDRAWELEMENTSINSTANCEDANGLEPROC glDrawElementsInstancedANGLE;

///
// Create a simple 2x2 texture image with four different colors
//
GLuint CreateSimpleTexture2D( )
{
   // Texture object handle
   GLuint textureId;
   
   // 2x2 Image, 3 bytes per pixel (R, G, B)
   GLubyte pixels[4 * 3] =
   {  
      255,   0,   0, // Red
        0, 255,   0, // Green
        0,   0, 255, // Blue
      255, 255,   0  // Yellow
   };

   // Use tightly packed data
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );

   // Load the texture
   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels );

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

   return textureId;

}


///
// Initialize the shader and program object
//
int Init ( ESContext *esContext )
{
    // init instancing functions
    char *extensionString = (char*) glGetString(GL_EXTENSIONS);

   UserData *userData = (UserData*)esContext->userData;
   GLbyte vShaderStr[] =  
      "attribute vec3 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "attribute vec3 a_instancePos;\n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = vec4(a_position.xyz + a_instancePos.xyz, 1.0); \n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";
   
   GLbyte fShaderStr[] =  
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
      "}                                                   \n";

    if (strstr(extensionString, "GL_ANGLE_instanced_arrays"))
    {
        glVertexAttribDivisorANGLE = (PFNGLVERTEXATTRIBDIVISORANGLEPROC)eglGetProcAddress("glVertexAttribDivisorANGLE");
        glDrawArraysInstancedANGLE = (PFNGLDRAWARRAYSINSTANCEDANGLEPROC)eglGetProcAddress("glDrawArraysInstancedANGLE");
        glDrawElementsInstancedANGLE = (PFNGLDRAWELEMENTSINSTANCEDANGLEPROC)eglGetProcAddress("glDrawElementsInstancedANGLE");
    }

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram ( (const char*)vShaderStr, (const char*)fShaderStr );

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation ( userData->programObject, "a_position" );
   userData->texCoordLoc = glGetAttribLocation ( userData->programObject, "a_texCoord" );
   userData->instancePosLoc = glGetAttribLocation ( userData->programObject, "a_instancePos" );
   
   // Get the sampler location
   userData->samplerLoc = glGetUniformLocation ( userData->programObject, "s_texture" );

   // Load the texture
   userData->textureId = CreateSimpleTexture2D ();

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw ( ESContext *esContext )
{
   UserData *userData = (UserData*) esContext->userData;
   GLfloat vVertices[] = { -0.2f,  0.2f, 0.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0 
                           -0.2f, -0.2f, 0.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            0.2f, -0.2f, 0.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            0.2f,  0.2f, 0.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };

   GLfloat instanceVerts [] = { -0.3f, -0.3f, 0.0f, 0.3f, 0.3f, 0.0f };
      
   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex position
   glVertexAttribPointer ( userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 5 * sizeof(GLfloat), vVertices );
   // Load the texture coordinate
   glVertexAttribPointer ( userData->texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 5 * sizeof(GLfloat), &vVertices[3] );

   // Load the instance position
   glVertexAttribPointer ( userData->instancePosLoc, 3, GL_FLOAT, 
                           GL_FALSE, 3 * sizeof(GLfloat), instanceVerts );

   glEnableVertexAttribArray ( userData->positionLoc );
   glEnableVertexAttribArray ( userData->texCoordLoc );
   glEnableVertexAttribArray ( userData->instancePosLoc );

   // Enable instancing
   //glVertexAttribDivisorANGLE( userData->instancePosLoc, 1 );

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, userData->textureId );

   // Set the sampler texture unit to 0
   glUniform1i ( userData->samplerLoc, 0 );

   //glDrawElementsInstancedANGLE ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices, 2 );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );
   
   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

///
// Cleanup
//
void ShutDown ( ESContext *esContext )
{
   UserData *userData = (UserData*) esContext->userData;

   // Delete texture object
   glDeleteTextures ( 1, &userData->textureId );

   // Delete program object
   glDeleteProgram ( userData->programObject );
}

Simple_Instancing_winrt::Simple_Instancing_winrt() :
	m_windowClosed(false),
	m_windowVisible(true)
{
}

void Simple_Instancing_winrt::Initialize(CoreApplicationView^ applicationView)
{
	applicationView->Activated +=
        ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &Simple_Instancing_winrt::OnActivated);

	CoreApplication::Suspending +=
        ref new EventHandler<SuspendingEventArgs^>(this, &Simple_Instancing_winrt::OnSuspending);

	CoreApplication::Resuming +=
        ref new EventHandler<Platform::Object^>(this, &Simple_Instancing_winrt::OnResuming);

	//m_renderer = ref new CubeRenderer();
    esInitContext ( &m_esContext );
    m_esContext.userData = &m_userData;
   
    //esMainLoop ( &esContext );

    //ShutDown ( &esContext );
}

void Simple_Instancing_winrt::SetWindow(CoreWindow^ window)
{
    window->SizeChanged +=
        ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &Simple_Instancing_winrt::OnWindowSizeChanged);

    window->VisibilityChanged +=
        ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &Simple_Instancing_winrt::OnVisibilityChanged);

    window->Closed +=
        ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &Simple_Instancing_winrt::OnWindowClosed);

    window->PointerCursor = ref new CoreCursor(CoreCursorType::Arrow, 0);

    window->PointerPressed +=
        ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &Simple_Instancing_winrt::OnPointerPressed);

    window->PointerMoved +=
        ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &Simple_Instancing_winrt::OnPointerMoved);

    // we need to select the correct DirectX feature level depending on the platform
    // default is for WinRT on Windows 8.0
    ANGLE_D3D_FEATURE_LEVEL featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_1;

    //m_renderer->Initialize(CoreWindow::GetForCurrentThread());
#if (_MSC_VER >= 1800)
    // WinRT on Windows 8.1 can compile shaders at run time so we don't care about the DirectX feature level
    featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_ANY;
#elif WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE)
    // Windows Phone 8.0 uses D3D_FEATURE_LEVEL_9_3
    featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_3;
#endif 

    HRESULT result = CreateWinrtEglWindow(WINRT_EGL_IUNKNOWN(CoreWindow::GetForCurrentThread()), featureLevel, m_eglWindow.GetAddressOf());    
    if (SUCCEEDED(result))
    {
        m_esContext.hWnd = m_eglWindow;
        //title, width, and height are unused, but included for backwards compatibility
        if (esCreateWindow(&m_esContext, TEXT("Simple Instancing"), 320, 240, ES_WINDOW_RGB) != GL_TRUE)
            return;

        if (!Init(&m_esContext))
            return; 

        esRegisterDrawFunc(&m_esContext, Draw);
    }
}

void Simple_Instancing_winrt::Load(Platform::String^ entryPoint)
{
}

void Simple_Instancing_winrt::Run()
{
	BasicTimer^ timer = ref new BasicTimer();

	while (!m_windowClosed)
	{
		if (m_windowVisible)
		{
			timer->Update();
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
            if ( m_esContext.updateFunc != NULL )
                m_esContext.updateFunc ( &m_esContext, timer->Delta );
            if ( m_esContext.drawFunc )
                m_esContext.drawFunc ( &m_esContext );
			//m_renderer->Update(timer->Total, timer->Delta);
			//m_renderer->Render();
			//m_renderer->Present(); // This call is synchronized to the display frame rate.
		}
		else
		{
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
		}
	}
}

void Simple_Instancing_winrt::Uninitialize()
{
}

void Simple_Instancing_winrt::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	//m_renderer->UpdateForWindowSizeChange();
}

void Simple_Instancing_winrt::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	m_windowVisible = args->Visible;
}

void Simple_Instancing_winrt::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
	m_windowClosed = true;
    ShutDown ( &m_esContext );
}

void Simple_Instancing_winrt::OnPointerPressed(CoreWindow^ sender, PointerEventArgs^ args)
{
	// Insert your code here.
}

void Simple_Instancing_winrt::OnPointerMoved(CoreWindow^ sender, PointerEventArgs^ args)
{
	// Insert your code here.
}

void Simple_Instancing_winrt::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
	CoreWindow::GetForCurrentThread()->Activate();
}

void Simple_Instancing_winrt::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
	// Save app state asynchronously after requesting a deferral. Holding a deferral
	// indicates that the application is busy performing suspending operations. Be
	// aware that a deferral may not be held indefinitely. After about five seconds,
	// the app will be forced to exit.
	SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();

	create_task([this, deferral]()
	{
		// Insert your code here.

		deferral->Complete();
	});
}
 
void Simple_Instancing_winrt::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
	// Restore any data or state that was unloaded on suspend. By default, data
	// and state are persisted when resuming from suspend. Note that this event
	// does not occur if the app was previously terminated.
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
    return ref new Simple_Instancing_winrt();
}

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DApplicationSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}
