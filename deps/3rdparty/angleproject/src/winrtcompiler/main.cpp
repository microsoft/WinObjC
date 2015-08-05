#include <iostream>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include "libGLESv2/main.h"
#include "libGLESv2/Context.h"
#include "common/winrtangle.h"

#include <stdio.h>
#include <io.h>
#include <assert.h>
#include <vector>
#include <string>
#include <iostream>

static void usage();
static GLuint createShader(GLenum shaderType, const char **source, unsigned sourceCount);

#using <Windows.winmd>
#using <Platform.winmd>
using namespace Platform;
using namespace std;

namespace egl
{
struct Current
{
    EGLint error;
    EGLenum API;
    EGLDisplay display;
    EGLSurface drawSurface;
    EGLSurface readSurface;
};

static Current glContext;

void setCurrentError(EGLint error)
{
    glContext.error = error;
}

EGLint getCurrentError()
{
    return  glContext.error;
}

void setCurrentAPI(EGLenum API)
{
     glContext.API = API;
}

EGLenum getCurrentAPI()
{
    return glContext.API;
}

void setCurrentDisplay(EGLDisplay dpy)
{
    glContext.display = dpy;
}

EGLDisplay getCurrentDisplay()
{
    return glContext.display;
}

void setCurrentDrawSurface(EGLSurface surface)
{
    glContext.drawSurface = surface;
}

EGLSurface getCurrentDrawSurface()
{
    return glContext.drawSurface;
}

void setCurrentReadSurface(EGLSurface surface)
{
    glContext.readSurface = surface;
}

EGLSurface getCurrentReadSurface()
{
    return glContext.readSurface;
}

void error(EGLint errorCode)
{
    egl::setCurrentError(errorCode);
}

}

namespace gl
{

static gl::Current glContext;

void makeCurrent(Context *context, egl::Display *display, egl::Surface *surface)
{
    Current *current = (Current*)&glContext;

    current->context = context;
    current->display = display;

    if (context && display && surface)
    {
        context->makeCurrent(surface);
    }
}

Context *getContext()
{
    Current *current = (Current*)&glContext;

    return current->context;
}

Context *getNonLostContext()
{
    Context *context = getContext();
    
    if (context)
    {
        if (context->isContextLost())
        {
            gl::error(GL_OUT_OF_MEMORY);
            return NULL;
        }
        else
        {
            return context;
        }
    }
    return NULL;
}

egl::Display *getDisplay()
{
    Current *current = (Current*)&glContext;

    return current->display;
}

// Records an error code
void error(GLenum errorCode)
{
    gl::Context *context = glGetCurrentContext();

    if (context)
    {
        switch (errorCode)
        {
          case GL_INVALID_ENUM:
            context->recordInvalidEnum();
            TRACE("\t! Error generated: invalid enum\n");
            break;
          case GL_INVALID_VALUE:
            context->recordInvalidValue();
            TRACE("\t! Error generated: invalid value\n");
            break;
          case GL_INVALID_OPERATION:
            context->recordInvalidOperation();
            TRACE("\t! Error generated: invalid operation\n");
            break;
          case GL_OUT_OF_MEMORY:
            context->recordOutOfMemory();
            TRACE("\t! Error generated: out of memory\n");
            break;
          case GL_INVALID_FRAMEBUFFER_OPERATION:
            context->recordInvalidFramebufferOperation();
            TRACE("\t! Error generated: invalid framebuffer operation\n");
            break;
          default: UNREACHABLE();
        }
    }
}
}


bool InitializeAngle(EGLDisplay& display, EGLContext& context, ANGLE_D3D_FEATURE_LEVEL featureLevel)
{
	// setup EGL
	EGLint configAttribList[] = {
		EGL_RED_SIZE,       8,
		EGL_GREEN_SIZE,     8,
		EGL_BLUE_SIZE,      8,
		EGL_ALPHA_SIZE,     8,
		EGL_DEPTH_SIZE,     8,
		EGL_STENCIL_SIZE,   8,
		EGL_SAMPLE_BUFFERS, 0,
		EGL_NONE
	};

	EGLint surfaceAttribList[] = {
		EGL_NONE, EGL_NONE
	};

	EGLint numConfigs;
	EGLint majorVersion;
	EGLint minorVersion;
	EGLConfig config;
	EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };



    IUnknown* dummy = nullptr;
    Microsoft::WRL::ComPtr<IWinrtEglWindow> eglWindow;
    HRESULT result = CreateWinrtEglWindow(WINRT_EGL_IUNKNOWN(dummy), featureLevel, eglWindow.GetAddressOf());
    if(!SUCCEEDED(result))
    {
        cout << "InitializeAngle: unable to create IWinrtEglWindow. HRESULT: " << result << endl;
        return false;
    }

	display = eglGetDisplay(eglWindow);
	if(display == EGL_NO_DISPLAY){
        cout << "InitializeAngle: couldn't get EGL display" << endl;
		return false;
	}

	if(!eglInitialize(display, &majorVersion, &minorVersion)){
        cout << "InitializeAngle: failed to initialize EGL" << endl;
		return false;
	}

	// Get configs
	if ( !eglGetConfigs(display, NULL, 0, &numConfigs) ){
        cout << "InitializeAngle: failed to get display configurations" << endl;
		return false;
	}

	// Choose config
	if(!eglChooseConfig(display, configAttribList, &config, 1, &numConfigs)){
        cout << "InitializeAngle: failed to choose display configurations" << endl;
		return false;
	}

	// Create a GL context
	context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
	if(context == EGL_NO_CONTEXT){
        cout << "InitializeAngle: failed to create EGL context" << endl;
		return false;
	}   

	// Make the context current
    // Note: we are not using a surface
	if (!eglMakeCurrent(display, NULL, NULL, context)){
        cout << "InitializeAngle: failed to make EGL context current" << endl;
		return false;
	}

    return true;
}

GLuint createShader(GLenum shaderType, const char **source, unsigned sourceCount)
{
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, sourceCount, source, NULL);
    glCompileShader(shader);
    int compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

    if(compileStatus != GL_TRUE)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &compileStatus);
        char *sourceBuffer = new char[compileStatus];
        char *shaderTypeName = (shaderType == GL_VERTEX_SHADER) ? "vertex shader(s)" : "fragment shader(s)";
        glGetShaderInfoLog(shader, compileStatus, NULL, sourceBuffer);
        printf("Failed to compile %s due to:\n%s\n", shaderTypeName, sourceBuffer);
        delete [] sourceBuffer;
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

//
//   print usage to stdout
//
void usage()
{
    printf("Usage: glslPrecompiler [-o=[file]  -p=[platform] -a=[variable]] -v=[vertex_shader_1] ... -v=[vertex_shader_1] -f=[fragment_shader_1] ... -f=[fragment_shader_n]\n"
        "Where: filename : filename ending in .frag or .vert\n"
        "       -o=[file] : output file\n"
        "       -p=[platform] : wp8 or winrt\n"
        "       -v=[variable] : output to char array named [variable] in header file, omit for binary file\n"
		"       -s : output to shader archive (.SAR)\n");
}

// -p=wp8 -o=shader.h -a=gProgram -v=shader.vert -f=shader.frag

#define SAR_MAGIC	"SAR10\0\0\0"
#define SAR_SHADER	'sENT'

typedef struct
{
	unsigned int type;
	unsigned int vertexShaderLen;
	unsigned int pixelShaderLen;
	unsigned int binaryShaderLen;
	/*
	unsigned char vertexShaderSrc[vertexShaderLen];
	unsigned char pixelShaderSrc[pixelShaderLen];
	unsigned char binaryShaderSrc[binaryShaderLen];
	*/
} CompiledShader;

typedef struct
{
	unsigned char magic[8];
	/*
	CompiledShader Shaders[];
	*/
} SARchive;

[Platform::MTAThread]
int __cdecl main(int argc, char* argv[])
{
    EGLDisplay display = nullptr;
    EGLContext context = nullptr;

    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    bool usageFail = false;
    bool outputToHeaderFile = false;
	bool outputToArchiveFile = false;
    std::string outputFile = "shader.file";
    char variableName[1024];
    std::vector<std::string> vertexShaders;
    std::vector<std::string> fragmentShaders;
    std::string platform = "";

    if (argc < 3)
        usageFail = TRUE;
    

    argc--;
    argv++;
    for (; (argc >= 1) && !usageFail; argc--, argv++) {
        if (argv[0][0] == '-') {
            switch (argv[0][1]) {
            case 'p':
                if (argv[0][2] == '=' && strlen(argv[0] + 3)) {
                    platform = argv[0] + 3;
                }
                break;
            case 'o':
                if (argv[0][2] == '=' && strlen(argv[0] + 3)) {
                    outputFile = argv[0] + 3;
                }
                break;
            case 'a':
                if (argv[0][2] == '=') {
                    strcpy(variableName, argv[0] + 3);
                    outputToHeaderFile = true;
                }
                break;
			case 's':
				outputToArchiveFile = true;
				break;
			case 'v':
            case 'f':
                {
                    if(argv[0][2] != '=')
                        break;

                    FILE *fp = fopen(argv[0] + 3, "r");
                    if(!fp)
                    {
                        printf("Can't open %s, aborting\n", argv[0]);
                        return 0;
                    }
                    fseek(fp, 0, SEEK_END);
                    int fileSize = ftell(fp);
                    rewind(fp);
                    char *sourceBuffer = new char[fileSize + 1];
                    fileSize = fread(sourceBuffer, 1, fileSize, fp);
                    fclose(fp);
                    sourceBuffer[fileSize] = 0;
                    if(argv[0][1] == 'v')
                        vertexShaders.push_back(sourceBuffer);
                    else
                        fragmentShaders.push_back(sourceBuffer);
                    delete [] sourceBuffer;
                }
                break;
            default: usageFail = true;
            }
        }
    }

    if (usageFail)
    {
        usage();
        return -1;
    }

    // we need to select the correct DirectX feature level depending on the platform
    // default is D3D_FEATURE_LEVEL_9_3 Windows Phone 8.0
    ANGLE_D3D_FEATURE_LEVEL featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_1;

    if(platform == "winrt")
    {
#if (_MSC_VER >= 1800)
    // WinRT on Windows 8.1 can compile shaders at run time so we don't care about the DirectX feature level
        featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_ANY;
        cout << "Compiling for WinRT at ANGLE_D3D_FEATURE_LEVEL_ANY" << endl;
#else
        featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_1;
        cout << "Compiling for WinRT at ANGLE_D3D_FEATURE_LEVEL_9_1" << endl;
#endif
    }
    else if(platform == "wp8")
    {
        featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_3;
        cout << "Compiling for Windows Phone 8 at ANGLE_D3D_FEATURE_LEVEL_9_3" << endl;
    }
    else
    {
#if (_MSC_VER >= 1800)
        cout << "Unknown target platform. Default to ANGLE_D3D_FEATURE_LEVEL_ANY" << endl;
        cout << "Compiling for WinRT at ANGLE_D3D_FEATURE_LEVEL_ANY" << endl;
#else
        cout << "Unknown target platform. Default to ANGLE_D3D_FEATURE_LEVEL_9_1" << endl;
#endif
    }

    if(!InitializeAngle(display, context, featureLevel))
    {
        return -1;
    }

    std::vector<const char*> vertexSources;
    std::vector<const char*> fragmentSources;
    for(unsigned i = 0; i < vertexShaders.size(); ++i)
        vertexSources.push_back(vertexShaders[i].c_str());
    for(unsigned i = 0; i < fragmentShaders.size(); ++i)
        fragmentSources.push_back(fragmentShaders[i].c_str());

    GLuint program = glCreateProgram();
    vertexShader = createShader(GL_VERTEX_SHADER, &vertexSources[0], vertexSources.size());
    if(!vertexShader)
        return 0;
    fragmentShader = createShader(GL_FRAGMENT_SHADER, &fragmentSources[0], vertexSources.size());
    if(!fragmentShader)
        return 0;
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);
    int linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

    if(linkStatus != GL_TRUE)
    {
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &linkStatus);
        char *infoLog = new char[linkStatus];
        glGetProgramInfoLog(program, linkStatus, NULL, infoLog);
        printf("Failed to link the shaders into a program due to:\n%s\n", infoLog);
        delete [] infoLog;
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return 0;
    }
    glGetProgramiv(program, GL_PROGRAM_BINARY_LENGTH_OES, &linkStatus);

    unsigned char *binary = new unsigned char[linkStatus];
    GLenum binaryFormat;
    glGetProgramBinaryOES(program, linkStatus, NULL, &binaryFormat, binary);

	if (outputToArchiveFile)
	{
		cout << "Writing to shader archive\n" << endl;
		FILE *fp = fopen(outputFile.c_str(), "a+b");
		if (!fp) {
			cout << "Unable to open " << outputFile << " for write\n" << endl;
			return -1;
		}
		SARchive header;
		memset(&header, 0, sizeof(header));
		fread(&header, 1, sizeof(header), fp);
		if ( memcmp(header.magic, SAR_MAGIC, sizeof(header.magic)) == 0 ) 
		{
			cout << "Appending to archive\n" << endl;

			//  Existing archive - append shader
			fseek(fp, SEEK_END, 0);
		} else 
		{
			cout << "Writing new archive\n" << endl;

			//  Write header
			memcpy(header.magic, SAR_MAGIC, sizeof(header.magic));
			fseek(fp, SEEK_SET, 0);
			_chsize(_fileno(fp), 0);
			fwrite(&header, 1, sizeof(header), fp);
		}

		CompiledShader shaderHeader;
		shaderHeader.type = SAR_SHADER;
		shaderHeader.vertexShaderLen = strlen(vertexSources[0]);
		shaderHeader.pixelShaderLen = strlen(fragmentSources[0]);
		shaderHeader.binaryShaderLen = linkStatus;

		fwrite(&shaderHeader, 1, sizeof(shaderHeader), fp);
		fwrite(vertexSources[0], 1, strlen(vertexSources[0]), fp);
		fwrite(fragmentSources[0], 1, strlen(fragmentSources[0]), fp);
		fwrite(binary, 1, linkStatus, fp);

		fclose(fp);
	} else if(outputToHeaderFile)
    {
		FILE *fp = fopen(outputFile.c_str(), "w");
		fprintf(fp, "static unsigned char %s[%d] = {\n", "vertexShaderSrc", strlen(vertexSources[0]));
		fprintf(fp, "%3i, ", vertexSources[0][0]);
		for (int i = 1; i < strlen(vertexSources[0]) - 1; ++i)
		{
			if (i % 8 == 0)
				fprintf(fp, "\n");
			fprintf(fp, "%3i, ", vertexSources[0][i]);
		}
		if ((strlen(vertexSources[0]) - 1) % 8 == 0)
			fprintf(fp, "\n");
		fprintf(fp, "%3i\n};", vertexSources[0][strlen(vertexSources[0]) - 1]);

		fprintf(fp, "static unsigned char %s[%d] = {\n", "fragmentShaderSrc", strlen(fragmentSources[0]));
		fprintf(fp, "%3i, ", fragmentSources[0][0]);
		for (int i = 1; i < strlen(fragmentSources[0]) - 1; ++i)
		{
			if (i % 8 == 0)
				fprintf(fp, "\n");
			fprintf(fp, "%3i, ", fragmentSources[0][i]);
		}
		if ((strlen(fragmentSources[0]) - 1) % 8 == 0)
			fprintf(fp, "\n");
		fprintf(fp, "%3i\n};", fragmentSources[0][strlen(fragmentSources[0]) - 1]);

		fprintf(fp, "static unsigned char %s[%d] = {\n", "compiledProgram", linkStatus);
		fprintf(fp, "%3i, ", binary[0]);
		for (int i = 1; i < linkStatus - 1; ++i)
		{
			if (i % 8 == 0)
				fprintf(fp, "\n");
			fprintf(fp, "%3i, ", binary[i]);
		}
		if ((linkStatus - 1) % 8 == 0)
			fprintf(fp, "\n");
		fprintf(fp, "%3i\n};", binary[linkStatus - 1]);
		fclose(fp);
	}
    else
    {
        FILE *fp = fopen(outputFile.c_str(), "wb");
        fwrite(binary, linkStatus, 1, fp);
        fclose(fp);
    }
    delete [] binary;
    printf("Compilation successful\n");
    eglMakeCurrent(NULL, NULL, NULL, NULL);

    if(display && context)
    {
        eglDestroyContext(display, context);
    }
    if(display)
    {
        eglTerminate(display);
   }

    return 0;
}


