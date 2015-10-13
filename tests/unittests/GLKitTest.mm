#include "gtest-api.h"

#import <GLKit/GLKit.h>

#include <math.h>
#include "Frameworks/GLKit/ShaderGen.h"
#include "Frameworks/GLKit/ShaderInfo.h"

using namespace GLKitShader;

NSString* stripSource(NSString* s, NSString* searchStr)
{
    NSRange r;
    while ((r = [s rangeOfString:searchStr]).location != NSNotFound) {
        NSRange searchRange;
        searchRange.location = r.location + r.length;
        searchRange.length = s.length;
        NSRange endRange = [s rangeOfString:@"\n" options:0 range:searchRange];
        if (endRange.location != NSNotFound) {
            r.length = endRange.location - r.location;
        } else {
            r.length = s.length - r.location;
        }
        s = [s stringByReplacingCharactersInRange:r withString:@""];
    }

    return s;
}

int countOccurrences(NSString* s, NSString* searchStr)
{
    int count = 0;

    NSRange r;
    r.location = 0;
    r.length = s.length;
    
    while ((r = [s rangeOfString:searchStr options:0 range:r]).location != NSNotFound) {
        count ++;

        r.location = r.location + r.length;
        r.length = s.length - r.location;
    }

    return count;
}

void printShader(GLKShaderPair* p)
{
    LOG_INFO("\n\n-[ VERTEX SHADER ]----------------------\n%s"
             "\n\n-[ PIXEL SHADER ]-----------------------\n%s\n\n",
             [p.vertexShader UTF8String], [p.pixelShader UTF8String]);
}

bool hasVariable(GLKShaderPair* p, const char* varName, bool checkVS = true, bool checkPS = true)
{
    if (checkVS) {
        if ([p.vertexShader rangeOfString: [NSString stringWithCString: varName]].location != NSNotFound) {
            return true;
        }
    }

    if (checkPS) {
        if ([p.pixelShader rangeOfString: [NSString stringWithCString: varName]].location != NSNotFound) {
            return true;
        }
    }

    return false;
}

TEST(GLKit, DeadCodeElimination)
{
    GLKVector4 clr = GLKVector4White();
    
    // Simple shader.
    ShaderDef vsh({
        {"output1", new ShaderAdditiveCombiner({
                        new ShaderVarRef("input1"),
                        new ShaderVarRef("input2"),
                        new ShaderVarRef("input3"),
                        new ShaderVarRef("input4")})}
    });
    ShaderDef psh({{"gl_FragColor", new ShaderVarRef("output1")}});
    ShaderContext ctx(vsh, psh);

    // Some materials (nothing in m4).
    ShaderMaterial m, m2, m3, m4;
    m.addMaterialVar("input1", clr);
    m.addMaterialVar("input2", clr);
    m.addMaterialVar("input3", clr);
    m.addMaterialVar("input4", clr);

    m2.addMaterialVar("input2", clr);
    m2.addMaterialVar("input4", clr);

    m3.addMaterialVar("input3", clr);

    // Generate
    GLKShaderPair* p = ctx.generate(m);
    GLKShaderPair* p2 = ctx.generate(m2);
    GLKShaderPair* p3 = ctx.generate(m3);
    GLKShaderPair* p4 = ctx.generate(m4);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");
    
    // Check results.
    EXPECT_TRUE_MSG(hasVariable(p, "input1"), "Variable must be present");
    EXPECT_TRUE_MSG(hasVariable(p, "input2"), "Variable must be present");
    EXPECT_TRUE_MSG(hasVariable(p, "input3"), "Variable must be present");
    EXPECT_TRUE_MSG(hasVariable(p, "input4"), "Variable must be present");

    EXPECT_FALSE_MSG(hasVariable(p2, "input1"), "Variable should be optimized away");
    EXPECT_TRUE_MSG(hasVariable(p2, "input2"), "Variable must be present");
    EXPECT_FALSE_MSG(hasVariable(p2, "input3"), "Variable should be optimized away");
    EXPECT_TRUE_MSG(hasVariable(p2, "input4"), "Variable must be present");

    EXPECT_FALSE_MSG(hasVariable(p3, "input1"), "Variable should be optimized away");
    EXPECT_FALSE_MSG(hasVariable(p3, "input2"), "Variable should be optimized away");
    EXPECT_TRUE_MSG(hasVariable(p3, "input3"), "Variable must be present");
    EXPECT_FALSE_MSG(hasVariable(p3, "input4"), "Variable should be optimized away");

    EXPECT_FALSE_MSG(hasVariable(p4, "input1"), "Variable should be optimized away");
    EXPECT_FALSE_MSG(hasVariable(p4, "input2"), "Variable should be optimized away");
    EXPECT_FALSE_MSG(hasVariable(p4, "input3"), "Variable should be optimized away");
    EXPECT_FALSE_MSG(hasVariable(p4, "input4"), "Variable should be optimized away");
}

TEST(GLKit, DeadCodeElimination2)
{
    GLKVector4 clr = GLKVector4White();
    
    // Simple shader -- generates opName(input1, input2).
    ShaderDef vsh({
            {"output1", new ShaderOp(new ShaderVarRef("input1"),
                                     new ShaderVarRef("input2"),
                                     "opName",
                                     false)}
    });
    ShaderDef psh({{"gl_FragColor", new ShaderVarRef("output1")}});
    ShaderContext ctx(vsh, psh);

    ShaderMaterial m, m2, m3, m4;
    m.addMaterialVar("input1", clr);
    m.addMaterialVar("input2", clr);

    m2.addMaterialVar("input1", clr);

    m3.addMaterialVar("input2", clr);

    // add nothing to m4.

    // Generate
    GLKShaderPair* p = ctx.generate(m);
    GLKShaderPair* p2 = ctx.generate(m2);
    GLKShaderPair* p3 = ctx.generate(m3);
    GLKShaderPair* p4 = ctx.generate(m4);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    EXPECT_TRUE_MSG(hasVariable(p, "opName"), "Operator must be present if both inputs are present");
    EXPECT_TRUE_MSG(hasVariable(p, "input1"), "Input must be present.");
    EXPECT_TRUE_MSG(hasVariable(p, "input2"), "Input must be present.");

    EXPECT_FALSE_MSG(hasVariable(p2, "opName"), "Operator must not be present if an input is missing");
    EXPECT_TRUE_MSG(hasVariable(p2, "input1"), "Input must be present.");
    EXPECT_FALSE_MSG(hasVariable(p2, "input2"), "Input is not used and must not be present.");

    EXPECT_FALSE_MSG(hasVariable(p3, "opName"), "Operator must not be present if an input is missing");
    EXPECT_FALSE_MSG(hasVariable(p3, "input1"), "Input is not used and must not be present.");
    EXPECT_TRUE_MSG(hasVariable(p3, "input2"), "Input must be present.");

    EXPECT_FALSE_MSG(hasVariable(p4, "opName"), "Operator must not be present if an input is missing");
    EXPECT_FALSE_MSG(hasVariable(p4, "input1"), "Input is not used and must not be present.");
    EXPECT_FALSE_MSG(hasVariable(p4, "input2"), "Input is not used and must not be present.");
}

TEST(GLKit, TextureCheck)
{
    ShaderDef vsh({
        {"output1", new ShaderTexRef("tex1", 
                                     "modeVar", 
                                     new ShaderCustom("float2(1, 1"), 
                                     new ShaderCustom("float4(1, 1, 1, 1)"))},
    });
    ShaderDef psh({
        {"gl_FragColor", new ShaderTexRef("tex2", 
                                          "modeVar", 
                                          new ShaderCustom("float2(1, 1"), 
                                          new ShaderVarRef("output1")) }
    });
    ShaderContext ctx(vsh, psh);

    // Textures should just pass through in vertex shader mode.
    ShaderMaterial m;
    m.addTexture("tex1", 1);
    m.addTexture("tex2", 2);

    GLKShaderPair* p = ctx.generate(m);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    EXPECT_FALSE_MSG(hasVariable(p, "texture2D", true, false), "Texturing call must not be in vertex shader");
    EXPECT_TRUE_MSG(hasVariable(p, "texture2D", false, true), "Texturing call expected in pixel shader");
}

TEST(GLKit, TextureCheckCube)
{
    ShaderDef vsh({
        {"output1", new ShaderCubeRef("tex1",
                                      "modeVar",
                                      new ShaderCustom("float4(1, 1, 1, 1)"),
                                      new ShaderCustom("float3(1, 1, 1)"), 
                                      new ShaderCustom("float4(1, 1, 1, 1)"), 
                                      new ShaderCustom("float4(1, 1, 1, 1)"))},
    });
    ShaderDef psh({
        {"gl_FragColor", new ShaderCubeRef("tex2", 
                                           "modeVar",
                                           new ShaderCustom("float4(1, 1, 1, 1)"),
                                           new ShaderCustom("float3(1, 1, 1)"), 
                                           new ShaderCustom("float4(1, 1, 1, 1)"), 
                                           new ShaderVarRef("output1")) }
    });
    ShaderContext ctx(vsh, psh);

    // Textures should just pass through in vertex shader mode.
    ShaderMaterial m;
    m.addTexCube("tex1", 1);
    m.addTexCube("tex2", 2);

    GLKShaderPair* p = ctx.generate(m);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    EXPECT_FALSE_MSG(hasVariable(p, "textureCube", true, false), "Texturing call must not be in vertex shader");
    EXPECT_TRUE_MSG(hasVariable(p, "textureCube", false, true), "Texturing call expected in pixel shader");
}

TEST(GLKit, TextureCheckSpecular)
{
    ShaderDef vsh({
            {"output1", new ShaderSpecularTex("tex1", 
                                              new ShaderCustom("float2(1, 1"), 
                                              new ShaderCustom("float4(1, 1, 1, 1)"))},
    });
    ShaderDef psh({
            {"gl_FragColor", new ShaderSpecularTex("tex2", 
                                                   new ShaderCustom("float2(1, 1"), 
                                                   new ShaderVarRef("output1")) }
    });
    ShaderContext ctx(vsh, psh);

    // Textures should just pass through in vertex shader mode.
    ShaderMaterial m;
    m.addTexture("tex1", 1);
    m.addTexture("tex2", 2);

    GLKShaderPair* p = ctx.generate(m);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    EXPECT_FALSE_MSG(hasVariable(p, "texture2D", true, false), "Texturing call must not be in vertex shader");
    EXPECT_TRUE_MSG(hasVariable(p, "texture2D", false, true), "Texturing call expected in pixel shader");
}

TEST(GLKit, DeadCodeBackPropagation)
{
    ShaderDef vsh({
            {"output1", new ShaderCustom("float4(1, 1, 1, 1)")},
            {"output2", new ShaderCustom("float4(1, 1, 1, 1)")},
            {"output3", new ShaderCustom("float4(1, 1, 1, 1)")},
            {"output4", new ShaderCustom("float4(1, 1, 1, 1)")},
    });
    ShaderDef psh({
            {"gl_FragColor", new ShaderAdditiveCombiner({new ShaderVarRef("output1"),
                                                         new ShaderVarRef("output3"),
                    })}
    });
    ShaderContext ctx(vsh, psh);

    ShaderMaterial m;
    GLKShaderPair* p = ctx.generate(m);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    // Remove comments and intermediate variables.
    p.vertexShader = stripSource(stripSource(p.vertexShader, @"//"), @"varying");
    p.pixelShader = stripSource(stripSource(p.pixelShader, @"//"), @"varying");

    EXPECT_TRUE_MSG(hasVariable(p, "output1"), "Variable is used in pixel shader and must be present in vertex shader.");
    EXPECT_FALSE_MSG(hasVariable(p, "output2"), "Variable is not used in pixel shader and must be eliminated in vertex shader.");
    EXPECT_TRUE_MSG(hasVariable(p, "output3"), "Variable is used in pixel shader and must be present in vertex shader.");
    EXPECT_FALSE_MSG(hasVariable(p, "output4"), "Variable is not used in pixel shader and must be eliminated in vertex shader.");
}

TEST(GLKit, ConditionalShaderNodes)
{
    ShaderDef vsh({
        {"output1", new ShaderAdditiveCombiner({
                        new ShaderPixelOnly(new ShaderCustom("pixelOnly")),
                        new ShaderVertexOnly(new ShaderCustom("vertexOnly")),
                        new ShaderCustom("float4(1, 1, 1, 1)"),
                        new ShaderInputVarCheck("generateThis", new ShaderCustom("inputVarOK"))})}
    });
    
    ShaderDef psh({
        {"gl_FragColor", new ShaderAdditiveCombiner({
                             new ShaderVarRef("output1"), 
                             new ShaderPixelOnly(new ShaderCustom("pixelOnly")),
                             new ShaderVertexOnly(new ShaderCustom("vertexOnly")),
                             new ShaderInputVarCheck("generateThis", new ShaderCustom("inputVarOK"))})}
    });
    ShaderContext ctx(vsh, psh);

    ShaderMaterial m, m2;
    m.addInputVar("generateThis", 1);

    GLKShaderPair* p = ctx.generate(m);
    GLKShaderPair* p2 = ctx.generate(m2);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    // Check input var.
    EXPECT_TRUE_MSG(hasVariable(p, "inputVarOK", true, false), "Input variable must be present in vertex shader");
    EXPECT_TRUE_MSG(hasVariable(p, "inputVarOK", false, true), "Input variable must be present in pixel shader");
    EXPECT_FALSE_MSG(hasVariable(p2, "inputVarOK", true, false), "Input variable should not be generated when disabled");
    EXPECT_FALSE_MSG(hasVariable(p2, "inputVarOK", false, true), "Input variable should not be generated when disabled");

    // Check VS/PS specific stuff.
    EXPECT_FALSE_MSG(hasVariable(p, "pixelOnly", true, false), "Pixel-only nodes must not appear in vertex shader");
    EXPECT_TRUE_MSG(hasVariable(p, "pixelOnly", false, true), "Pixel-only nodes must appear in pixel shader");
    EXPECT_TRUE_MSG(hasVariable(p, "vertexOnly", true, false), "Vertex-only nodes must appear in vertex shader");
    EXPECT_FALSE_MSG(hasVariable(p, "vertexOnly", false, true), "Vertex-only nodes must not appear in the pixel shader");
}

static bool fallbackContextTest(ShaderContext& ctx)
{
    GLKVector4 clr = GLKVector4White();
    
    const int numVars = 4;
    const char* varNames[numVars] = { "var1", "var2", "var3", "var4" };

    for (int i = 0; i < numVars; i ++) {
        ShaderMaterial m;
        m.addMaterialVar(varNames[i], clr);
        GLKShaderPair* p = ctx.generate(m);

        if (ctx.numVSTempFuncs() != 0 || ctx.numPSTempFuncs() != 0) {
            return false;
        }

        for (int j = 0; j < numVars; j ++) {
            if (i == j) {
                if (!hasVariable(p, varNames[j])) {
                    return false;
                }
            } else {
                if (hasVariable(p, varNames[j])) {
                    return false;
                }
            }
        }
    }

    return true;
}

TEST(GLKit, FallbackShaderNodes)
{
    ShaderDef vsh({{"output1", new ShaderFallbackRef({"var1", "var2", "var3", "var4"})}});
    ShaderDef vsh2({{"output1", new ShaderFallbackNode({
                                    new ShaderVarRef("var1"),
                                    new ShaderVarRef("var2"),
                                    new ShaderVarRef("var3"),
                                    new ShaderVarRef("var4")})}
    });
    ShaderDef psh({{"gl_FragColor", new ShaderVarRef("output1") }});
    
    ShaderContext ctx(vsh, psh);
    ShaderContext ctx2(vsh2, psh);

    EXPECT_TRUE_MSG(fallbackContextTest(ctx), "FallbackRef node not correctly falling back.");
    EXPECT_TRUE_MSG(fallbackContextTest(ctx2), "FallbackNode node not correctly falling back.");
}

TEST(GLKit, TemporaryShaderNodes)
{
    ShaderDef vsh({    
        {"output1", new ShaderAdditiveCombiner({
                        new ShaderTempRef(GLKS_FLOAT4, "tempResult", new ShaderCustom("commonResult")),
                        new ShaderTempRef(GLKS_FLOAT4, "tempResult", new ShaderCustom("commonResult")),
                        new ShaderTempRef(GLKS_FLOAT4, "tempResult", new ShaderCustom("commonResult"))})}
    });
              
    ShaderDef psh({{"gl_FragColor", new ShaderVarRef("output1") }});
    ShaderContext ctx(vsh, psh);

    ShaderMaterial m;
    GLKShaderPair* p = ctx.generate(m);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    EXPECT_EQ_MSG(countOccurrences(p.vertexShader, @"commonResult"), 1,
                  "The common result variable should only be used once.");
    EXPECT_EQ_MSG(countOccurrences(p.vertexShader, @"tempResult"), 4,
                  "The temporary result is not being reused the correct number of times.");
}

TEST(GLKit, BasicMath)
{
    BOOL invertible = FALSE;

    GLKVector4 v = GLKVector4Make(3.f, 2.f, 1.f, 1.f);

    GLKMatrix4 rot = GLKMatrix4MakeXRotation(2.f);
    GLKMatrix4 trans = GLKMatrix4MakeTranslation(5.f, 5.f, 5.f);

    auto mc = GLKMatrix4Multiply(trans, rot);
    auto mcInverse = GLKMatrix4Invert(mc, &invertible);
    EXPECT_TRUE_MSG(invertible, "Expected to be able to calculate matrix inverse.");

    auto v2 = GLKMatrix4MultiplyVector4(mcInverse, GLKMatrix4MultiplyVector4(mc, v));
    EXPECT_TRUE_MSG(GLKVector4AllEqualToVector4(v, v2),
                    "Matrix multiplication yielded unexpected result.");
}

TEST(GLKit, Rotations)
{
    GLKVector4 v = GLKVector4Make(3.f, 2.f, 1.f, 0.f);
    
    GLKMatrix4 mx = GLKMatrix4MakeXRotation(M_PI);
    GLKMatrix4 my = GLKMatrix4MakeYRotation(M_PI);
    GLKMatrix4 mz = GLKMatrix4MakeZRotation(M_PI);

    auto projx = GLKVector4MultiplyScalar(GLKVector4Project(v, GLKVector4Make(1.f, 0.f, 0.f, 0.f)), 2.f);
    auto projy = GLKVector4MultiplyScalar(GLKVector4Project(v, GLKVector4Make(0.f, 1.f, 0.f, 0.f)), 2.f);
    auto projz = GLKVector4MultiplyScalar(GLKVector4Project(v, GLKVector4Make(0.f, 0.f, 1.f, 0.f)), 2.f);

    auto dx = GLKMatrix4MultiplyVector4(mx, v);
    auto dy = GLKMatrix4MultiplyVector4(my, v);
    auto dz = GLKMatrix4MultiplyVector4(mz, v);

    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(GLKVector4Subtract(GLKVector4Add(v, dx), projx), 0.f),
                    "Unexpected vector addition result.");
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(GLKVector4Subtract(GLKVector4Add(v, dy), projy), 0.f),
                    "Unexpected vector addition result.");
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(GLKVector4Subtract(GLKVector4Add(v, dz), projz), 0.f),
                    "Unexpected vector addition result.");

    GLKMatrix4 m = GLKMatrix4MakeRotation(M_PI / 2.f, 1.f, 1.f, 1.f);
    v = GLKVector4Make(4.f, 5.f, 6.f, 0.f);

    auto v2 = GLKMatrix4MultiplyVector4(m, v);
    auto v3 = GLKMatrix4MultiplyVector4(m, v2);
    auto v4 = GLKMatrix4MultiplyVector4(m, v3);

    GLKVector4 dv = GLKVector4Make(GLKVector4Distance(v, v2),
                                   GLKVector4Distance(v2, v3),
                                   GLKVector4Distance(v3, v4),
                                   GLKVector4Distance(v4, v));
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(dv, dv.x), "Unexpected vector distance result.");
}

TEST(GLKit, Interpolation)
{
    GLKVector4 a = GLKVector4Make(4.f, 3.f, 2.f, 1.f);
    GLKVector4 b = GLKVector4Negate(a);

    auto res = GLKVector4Lerp(a, b, 0.5f);
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(res, 0.f), "Unexpected interpolation result.");
    
    float dist = GLKVector4Distance(a, b);
    EXPECT_LE_MSG(fabsf(dist - 2.f * sqrtf(GLKVector4DotProduct(a, a))), COMPARISON_EPSILON,
                  "Interpolation not within acceptable error.");
}
