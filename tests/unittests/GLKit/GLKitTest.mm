#include <TestFramework.h>

#import <GLKit/GLKit.h>

#include <math.h>
#include "Frameworks/GLKit/ShaderGen.h"
#include "Frameworks/GLKit/ShaderInfo.h"

using namespace GLKitShader;

NSString* stripSource(NSString* s, NSString* searchStr) {
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

int countOccurrences(NSString* s, NSString* searchStr) {
    int count = 0;

    NSRange r;
    r.location = 0;
    r.length = s.length;

    while ((r = [s rangeOfString:searchStr options:0 range:r]).location != NSNotFound) {
        count++;

        r.location = r.location + r.length;
        r.length = s.length - r.location;
    }

    return count;
}

void printShader(GLKShaderPair* p) {
    LOG_INFO(
        "\n\n-[ VERTEX SHADER ]----------------------\n%s"
        "\n\n-[ PIXEL SHADER ]-----------------------\n%s\n\n",
        [p.vertexShader UTF8String],
        [p.pixelShader UTF8String]);
}

bool hasVariable(GLKShaderPair* p, const char* varName, bool checkVS = true, bool checkPS = true) {
    if (checkVS) {
        if ([p.vertexShader rangeOfString:[NSString stringWithCString:varName]].location != NSNotFound) {
            return true;
        }
    }

    if (checkPS) {
        if ([p.pixelShader rangeOfString:[NSString stringWithCString:varName]].location != NSNotFound) {
            return true;
        }
    }

    return false;
}

TEST(GLKit, DeadCodeElimination) {
    GLKVector4 clr = GLKVector4White();

    // Simple shader.
    ShaderDef vsh(
        { { "output1",
            new ShaderAdditiveCombiner(
                { new ShaderVarRef("input1"), new ShaderVarRef("input2"), new ShaderVarRef("input3"), new ShaderVarRef("input4") }) } });
    ShaderDef psh({ { "gl_FragColor", new ShaderVarRef("output1") } });
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

TEST(GLKit, DeadCodeElimination2) {
    GLKVector4 clr = GLKVector4White();

    // Simple shader -- generates opName(input1, input2).
    ShaderDef vsh({ { "output1", new ShaderOp(new ShaderVarRef("input1"), new ShaderVarRef("input2"), "opName", false) } });
    ShaderDef psh({ { "gl_FragColor", new ShaderVarRef("output1") } });
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

TEST(GLKit, TextureCheck) {
    ShaderDef vsh({
        { "output1", new ShaderTexRef("tex1", "modeVar", new ShaderCustom("float2(1, 1"), new ShaderCustom("float4(1, 1, 1, 1)")) },
    });
    ShaderDef psh(
        { { "gl_FragColor", new ShaderTexRef("tex2", "modeVar", new ShaderCustom("float2(1, 1"), new ShaderVarRef("output1")) } });
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

TEST(GLKit, TextureCheckCube) {
    ShaderDef vsh({
        { "output1",
          new ShaderCubeRef("tex1",
                            "modeVar",
                            new ShaderCustom("float4(1, 1, 1, 1)"),
                            new ShaderCustom("float3(1, 1, 1)"),
                            new ShaderCustom("float4(1, 1, 1, 1)"),
                            new ShaderCustom("float4(1, 1, 1, 1)")) },
    });
    ShaderDef psh({ { "gl_FragColor",
                      new ShaderCubeRef("tex2",
                                        "modeVar",
                                        new ShaderCustom("float4(1, 1, 1, 1)"),
                                        new ShaderCustom("float3(1, 1, 1)"),
                                        new ShaderCustom("float4(1, 1, 1, 1)"),
                                        new ShaderVarRef("output1")) } });
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

TEST(GLKit, TextureCheckSpecular) {
    ShaderDef vsh({
        { "output1", new ShaderSpecularTex("tex1", new ShaderCustom("float2(1, 1"), new ShaderCustom("float4(1, 1, 1, 1)")) },
    });
    ShaderDef psh({ { "gl_FragColor", new ShaderSpecularTex("tex2", new ShaderCustom("float2(1, 1"), new ShaderVarRef("output1")) } });
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

TEST(GLKit, DeadCodeBackPropagation) {
    ShaderDef vsh({
        { "output1", new ShaderCustom("float4(1, 1, 1, 1)") },
        { "output2", new ShaderCustom("float4(1, 1, 1, 1)") },
        { "output3", new ShaderCustom("float4(1, 1, 1, 1)") },
        { "output4", new ShaderCustom("float4(1, 1, 1, 1)") },
    });
    ShaderDef psh({ { "gl_FragColor",
                      new ShaderAdditiveCombiner({
                          new ShaderVarRef("output1"), new ShaderVarRef("output3"),
                      }) } });
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

TEST(GLKit, ConditionalShaderNodes) {
    ShaderDef vsh({ { "output1",
                      new ShaderAdditiveCombiner({ new ShaderPixelOnly(new ShaderCustom("pixelOnly")),
                                                   new ShaderVertexOnly(new ShaderCustom("vertexOnly")),
                                                   new ShaderCustom("float4(1, 1, 1, 1)"),
                                                   new ShaderInputVarCheck("generateThis", new ShaderCustom("inputVarOK")) }) } });

    ShaderDef psh({ { "gl_FragColor",
                      new ShaderAdditiveCombiner({ new ShaderVarRef("output1"),
                                                   new ShaderPixelOnly(new ShaderCustom("pixelOnly")),
                                                   new ShaderVertexOnly(new ShaderCustom("vertexOnly")),
                                                   new ShaderInputVarCheck("generateThis", new ShaderCustom("inputVarOK")) }) } });
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

static bool fallbackContextTest(ShaderContext& ctx) {
    GLKVector4 clr = GLKVector4White();

    const int numVars = 4;
    const char* varNames[numVars] = { "var1", "var2", "var3", "var4" };

    for (int i = 0; i < numVars; i++) {
        ShaderMaterial m;
        m.addMaterialVar(varNames[i], clr);
        GLKShaderPair* p = ctx.generate(m);

        if (ctx.numVSTempFuncs() != 0 || ctx.numPSTempFuncs() != 0) {
            return false;
        }

        for (int j = 0; j < numVars; j++) {
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

TEST(GLKit, FallbackShaderNodes) {
    ShaderDef vsh({ { "output1", new ShaderFallbackRef({ "var1", "var2", "var3", "var4" }) } });
    ShaderDef vsh2({ { "output1",
                       new ShaderFallbackNode(
                           { new ShaderVarRef("var1"), new ShaderVarRef("var2"), new ShaderVarRef("var3"), new ShaderVarRef("var4") }) } });
    ShaderDef psh({ { "gl_FragColor", new ShaderVarRef("output1") } });

    ShaderContext ctx(vsh, psh);
    ShaderContext ctx2(vsh2, psh);

    EXPECT_TRUE_MSG(fallbackContextTest(ctx), "FallbackRef node not correctly falling back.");
    EXPECT_TRUE_MSG(fallbackContextTest(ctx2), "FallbackNode node not correctly falling back.");
}

TEST(GLKit, TemporaryShaderNodes) {
    ShaderDef vsh({ { "output1",
                      new ShaderAdditiveCombiner({ new ShaderTempRef(GLKS_FLOAT4, "tempResult", new ShaderCustom("commonResult")),
                                                   new ShaderTempRef(GLKS_FLOAT4, "tempResult", new ShaderCustom("commonResult")),
                                                   new ShaderTempRef(GLKS_FLOAT4, "tempResult", new ShaderCustom("commonResult")) }) } });

    ShaderDef psh({ { "gl_FragColor", new ShaderVarRef("output1") } });
    ShaderContext ctx(vsh, psh);

    ShaderMaterial m;
    GLKShaderPair* p = ctx.generate(m);

    EXPECT_EQ_MSG(ctx.numVSTempFuncs(), 0, "No vertex shader temporary functions should be present.");
    EXPECT_EQ_MSG(ctx.numPSTempFuncs(), 0, "No pixel shader temporary functions should be present.");

    EXPECT_EQ_MSG(countOccurrences(p.vertexShader, @"commonResult"), 1, "The common result variable should only be used once.");
    EXPECT_EQ_MSG(countOccurrences(p.vertexShader, @"tempResult"),
                  4,
                  "The temporary result is not being reused the correct number of times.");
}

TEST(GLKit, BasicMath) {
    BOOL invertible = FALSE;

    GLKVector4 v = GLKVector4Make(3.f, 2.f, 1.f, 1.f);

    GLKMatrix4 rot = GLKMatrix4MakeXRotation(2.f);
    GLKMatrix4 trans = GLKMatrix4MakeTranslation(5.f, 5.f, 5.f);

    auto mc = GLKMatrix4Multiply(trans, rot);
    auto mcInverse = GLKMatrix4Invert(mc, &invertible);
    EXPECT_TRUE_MSG(invertible, "Expected to be able to calculate matrix inverse.");

    auto v2 = GLKMatrix4MultiplyVector4(mcInverse, GLKMatrix4MultiplyVector4(mc, v));
    EXPECT_TRUE_MSG(GLKVector4AllEqualToVector4(v, v2), "Matrix multiplication yielded unexpected result.");

    float values[16] = { 0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f };
    GLKMatrix4 m = GLKMatrix4MakeWithArray(values);
    EXPECT_TRUE_MSG(m.m[0] == values[0] && m.m[1] == values[1] && m.m[2] == values[2] && m.m[3] == values[3] && m.m[4] == values[4] &&
                        m.m[5] == values[5] && m.m[6] == values[6] && m.m[7] == values[7] && m.m[8] == values[8] && m.m[9] == values[9] &&
                        m.m[10] == values[10] && m.m[11] == values[11] && m.m[12] == values[12] && m.m[13] == values[13] &&
                        m.m[14] == values[14] && m.m[15] == values[15],
                    "GLKMatrix4MakeWithArray yielded unexpected result.");

    m = GLKMatrix4MakeWithArrayAndTranspose(values);
    EXPECT_TRUE_MSG(m.m[0] == values[0] && m.m[1] == values[4] && m.m[2] == values[8] && m.m[3] == values[12] && m.m[4] == values[1] &&
                        m.m[5] == values[5] && m.m[6] == values[9] && m.m[7] == values[13] && m.m[8] == values[2] && m.m[9] == values[6] &&
                        m.m[10] == values[10] && m.m[11] == values[14] && m.m[12] == values[3] && m.m[13] == values[7] &&
                        m.m[14] == values[11] && m.m[15] == values[15],
                    "GLKMatrix4MakeWithArrayAndTranspose yielded unexpected result.");

    m = GLKMatrix4MakeWithRows(GLKVector4Make(0.f, 1.f, 2.f, 3.f),
                               GLKVector4Make(4.f, 5.f, 6.f, 7.f),
                               GLKVector4Make(8.f, 9.f, 10.f, 11.f),
                               GLKVector4Make(12.f, 13.f, 14.f, 15.f));
    EXPECT_TRUE_MSG(m.m[0] == values[0] && m.m[1] == values[4] && m.m[2] == values[8] && m.m[3] == values[12] && m.m[4] == values[1] &&
                        m.m[5] == values[5] && m.m[6] == values[9] && m.m[7] == values[13] && m.m[8] == values[2] && m.m[9] == values[6] &&
                        m.m[10] == values[10] && m.m[11] == values[14] && m.m[12] == values[3] && m.m[13] == values[7] &&
                        m.m[14] == values[11] && m.m[15] == values[15],
                    "GLKMatrix4MakeWithRows yielded unexpected result.");

    m = GLKMatrix4MakeWithColumns(GLKVector4Make(0.f, 1.f, 2.f, 3.f),
                                  GLKVector4Make(4.f, 5.f, 6.f, 7.f),
                                  GLKVector4Make(8.f, 9.f, 10.f, 11.f),
                                  GLKVector4Make(12.f, 13.f, 14.f, 15.f));
    EXPECT_TRUE_MSG(m.m[0] == values[0] && m.m[1] == values[1] && m.m[2] == values[2] && m.m[3] == values[3] && m.m[4] == values[4] &&
                        m.m[5] == values[5] && m.m[6] == values[6] && m.m[7] == values[7] && m.m[8] == values[8] && m.m[9] == values[9] &&
                        m.m[10] == values[10] && m.m[11] == values[11] && m.m[12] == values[12] && m.m[13] == values[13] &&
                        m.m[14] == values[14] && m.m[15] == values[15],
                    "GLKMatrix4MakeWithColumns yielded unexpected result.");

    GLKMatrix3 m3 = GLKMatrix3MakeWithRows(GLKVector3Make(0.f, 1.f, 2.f), GLKVector3Make(3.f, 4.f, 5.f), GLKVector3Make(6.f, 7.f, 8.f));
    EXPECT_TRUE_MSG(m3.m[0] == values[0] && m3.m[1] == values[3] && m3.m[2] == values[6] && m3.m[3] == values[1] && m3.m[4] == values[4] &&
                        m3.m[5] == values[7] && m3.m[6] == values[2] && m3.m[7] == values[5] && m3.m[8] == values[8],
                    "GLKMatrix3MakeWithRows yielded unexpected result.");

    m3 = GLKMatrix3MakeWithColumns(GLKVector3Make(0.f, 1.f, 2.f), GLKVector3Make(3.f, 4.f, 5.f), GLKVector3Make(6.f, 7.f, 8.f));
    EXPECT_TRUE_MSG(m3.m[0] == values[0] && m3.m[1] == values[1] && m3.m[2] == values[2] && m3.m[3] == values[3] && m3.m[4] == values[4] &&
                        m3.m[5] == values[5] && m3.m[6] == values[6] && m3.m[7] == values[7] && m3.m[8] == values[8],
                    "GLKMatrix3MakeWithColumns yielded unexpected result.");

    m3 = GLKMatrix3MakeWithArray(values);
    EXPECT_TRUE_MSG(m3.m[0] == values[0] && m3.m[1] == values[1] && m3.m[2] == values[2] && m3.m[3] == values[3] && m3.m[4] == values[4] &&
                        m3.m[5] == values[5] && m3.m[6] == values[6] && m3.m[7] == values[7] && m3.m[8] == values[8],
                    "GLKMatrix3MakeWithArray yielded unexpected result.");

    m3 = GLKMatrix3MakeWithArrayAndTranspose(values);
    EXPECT_TRUE_MSG(m3.m[0] == values[0] && m3.m[1] == values[3] && m3.m[2] == values[6] && m3.m[3] == values[1] && m3.m[4] == values[4] &&
                        m3.m[5] == values[7] && m3.m[6] == values[2] && m3.m[7] == values[5] && m3.m[8] == values[8],
                    "GLKMatrix3MakeWithArrayAndTranspose yielded unexpected result.");
}

TEST(GLKit, Quaternions) {
    float values[4] = { 0.f, 1.f, 2.f, 3.f };
    GLKQuaternion q = GLKQuaternionMake(0.f, 1.f, 2.f, 3.f);
    GLKQuaternion q2 = GLKQuaternionMakeWithArray(values);
    GLKQuaternion q3 = GLKQuaternionMakeWithVector3(GLKVector3Make(0.f, 1.f, 2.f), 3.f);
    EXPECT_TRUE_MSG(q.x == q2.x && q.y == q2.y && q.z == q2.z && q.w == q2.w, "Basic quaternion construction failed!");
    EXPECT_TRUE_MSG(q.x == q3.x && q.y == q3.y && q.z == q3.z && q.w == q3.w, "Basic quaternion construction failed!");

    q = GLKQuaternionNormalize(q);
    EXPECT_TRUE_MSG(fabsf(GLKQuaternionLength(q) - 1.f) <= COMPARISON_EPSILON, "Normalized quaternion has bad length.");

    q = GLKQuaternionMakeWithAngleAndAxis(M_PI, 0.f, 1.f, 0.f);
    q2 = GLKQuaternionMakeWithAngleAndVector3Axis(M_PI, GLKVector3YAxis());
    EXPECT_TRUE_MSG(q.x == q2.x && q.y == q2.y && q.z == q2.z && q.w == q2.w, "Quaternion angle/axis construction failed!");

    GLKVector3 axis = GLKQuaternionAxis(q);
    float angle = GLKQuaternionAngle(q);
    EXPECT_TRUE_MSG(fabsf(angle - (float)M_PI) <= COMPARISON_EPSILON, "Incorrect angle extracted!");
    EXPECT_TRUE_MSG(GLKVector3AllEqualToVector3(axis, GLKVector3YAxis()), "Incorrect rotation axis extracted!");

    GLKVector3 rotated = GLKQuaternionRotateVector3(q, GLKVector3XAxis());
    EXPECT_TRUE_MSG(GLKVector3AllEqualToScalar(GLKVector3Add(rotated, GLKVector3XAxis()), 0.f), "Quaternion rotation appears incorrect.");

    GLKMatrix3 xrot = GLKMatrix3MakeXRotation(M_PI / 3.f);
    GLKMatrix3 xrot2 = GLKMatrix3Make(1.f, 0.f, 0.f, 0.f, -1.f, 0.f, 0.f, 0.f, -1.f);
    GLKMatrix3 yrot = GLKMatrix3Make(-1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, -1.f);
    GLKMatrix3 zrot = GLKMatrix3Make(-1.f, 0.f, 0.f, 0.f, -1.f, 0.f, 0.f, 0.f, 1.f);

    q = GLKQuaternionMakeWithMatrix3(xrot);
    EXPECT_TRUE_MSG(fabsf(GLKQuaternionLength(q) - 1.f) <= COMPARISON_EPSILON, "Quaternion length incorrect");
    axis = GLKQuaternionAxis(q);
    angle = GLKQuaternionAngle(q);
    EXPECT_TRUE_MSG(fabsf(angle - ((float)M_PI / 3.f)) <= COMPARISON_EPSILON, "Quaternion angle extracted incorrectly!");
    EXPECT_TRUE_MSG(GLKVector3AllEqualToVector3(axis, GLKVector3XAxis()), "Incorrect rotation axis extracted!");

    q = GLKQuaternionMakeWithMatrix3(xrot2);
    EXPECT_TRUE_MSG(fabsf(GLKQuaternionLength(q) - 1.f) <= COMPARISON_EPSILON, "Quaternion length incorrect");
    axis = GLKQuaternionAxis(q);
    angle = GLKQuaternionAngle(q);
    EXPECT_TRUE_MSG(fabsf(angle - (float)M_PI) <= COMPARISON_EPSILON, "Quaternion angle extracted incorrectly!");
    EXPECT_TRUE_MSG(GLKVector3AllEqualToVector3(axis, GLKVector3XAxis()), "Incorrect rotation axis extracted!");

    q = GLKQuaternionMakeWithMatrix3(yrot);
    EXPECT_TRUE_MSG(fabsf(GLKQuaternionLength(q) - 1.f) <= COMPARISON_EPSILON, "Quaternion length incorrect");
    axis = GLKQuaternionAxis(q);
    angle = GLKQuaternionAngle(q);
    EXPECT_TRUE_MSG(fabsf(angle - (float)M_PI) <= COMPARISON_EPSILON, "Quaternion angle extracted incorrectly!");
    EXPECT_TRUE_MSG(GLKVector3AllEqualToVector3(axis, GLKVector3YAxis()), "Incorrect rotation axis extracted!");

    q = GLKQuaternionMakeWithMatrix3(zrot);
    EXPECT_TRUE_MSG(fabsf(GLKQuaternionLength(q) - 1.f) <= COMPARISON_EPSILON, "Quaternion length incorrect");
    axis = GLKQuaternionAxis(q);
    angle = GLKQuaternionAngle(q);
    EXPECT_TRUE_MSG(fabsf(angle - (float)M_PI) <= COMPARISON_EPSILON, "Quaternion angle extracted incorrectly!");
    EXPECT_TRUE_MSG(GLKVector3AllEqualToVector3(axis, GLKVector3ZAxis()), "Incorrect rotation axis extracted!");
}

TEST(GLKit, Rotations) {
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

    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(GLKVector4Subtract(GLKVector4Add(v, dx), projx), 0.f), "Unexpected vector addition result.");
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(GLKVector4Subtract(GLKVector4Add(v, dy), projy), 0.f), "Unexpected vector addition result.");
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(GLKVector4Subtract(GLKVector4Add(v, dz), projz), 0.f), "Unexpected vector addition result.");

    GLKMatrix4 m = GLKMatrix4MakeRotation(M_PI / 2.f, 1.f, 1.f, 1.f);
    v = GLKVector4Make(4.f, 5.f, 6.f, 0.f);

    auto v2 = GLKMatrix4MultiplyVector4(m, v);
    auto v3 = GLKMatrix4MultiplyVector4(m, v2);
    auto v4 = GLKMatrix4MultiplyVector4(m, v3);

    GLKVector4 dv =
        GLKVector4Make(GLKVector4Distance(v, v2), GLKVector4Distance(v2, v3), GLKVector4Distance(v3, v4), GLKVector4Distance(v4, v));
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(dv, dv.x), "Unexpected vector distance result.");
}

TEST(GLKit, Interpolation) {
    GLKVector4 a = GLKVector4Make(4.f, 3.f, 2.f, 1.f);
    GLKVector4 b = GLKVector4Negate(a);

    auto res = GLKVector4Lerp(a, b, 0.5f);
    EXPECT_TRUE_MSG(GLKVector4AllEqualToScalar(res, 0.f), "Unexpected interpolation result.");

    float dist = GLKVector4Distance(a, b);
    EXPECT_LE_MSG(fabsf(dist - 2.f * sqrtf(GLKVector4DotProduct(a, a))), COMPARISON_EPSILON, "Interpolation not within acceptable error.");

    GLKVector3 v = GLKVector3Make(0.f, 1.f, 1.f);
    GLKVector3 proj = GLKVector3Project(v, GLKVector3ZAxis());
    EXPECT_TRUE_MSG(GLKVector3AllEqualToVector3(proj, GLKVector3ZAxis()), "GLKVector3 projection failed!");

    GLKVector4 v4 = GLKVector4Make(0.f, 1.f, 1.f, 0.f);
    GLKVector4 zAxis = GLKVector4MakeWithVector3(GLKVector3ZAxis(), 0.f);
    GLKVector4 proj4 = GLKVector4Project(v4, zAxis);
    EXPECT_TRUE_MSG(GLKVector4AllEqualToVector4(proj4, zAxis), "GLKVector4 projection failed!");
}
