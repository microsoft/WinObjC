/*
Copyright 2009 Johannes Vuorinen

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "MatrixStack.h"
#include "../OpenGLESUtil.h"
#include "OpenGLESState.h"
#include "../OpenGLESImplementation.h"
#include "../OpenGLESConfig.h"

using namespace OpenGLES::OpenGLES2;
using namespace OpenGLES;

MatrixStack::MatrixStack(OpenGLESState* s, OpenGLESImplementation* impl) : openGLESState(s), implementation(impl) {
}

MatrixStack::~MatrixStack() {
    for (size_t i = 0; i < modelViewStack.size(); i++) {
        delete modelViewStack[i];
    }

    for (size_t i = 0; i < projectionStack.size(); i++) {
        delete projectionStack[i];
    }

    for (unsigned int i = 0; i < implementation->maxTextureImageUnits; i++) {
        for (size_t j = 0; j < textureStacks[i].size(); j++) {
            delete textureStacks[i][j];
        }
    }

    delete[] textureStacks;
}

void MatrixStack::init() {
    modelViewStack.push_back(new Matrix4x4<GLfloat>());
    OpenGLESMath::loadIdentity(modelViewStack[0]);

    projectionStack.push_back(new Matrix4x4<GLfloat>());
    OpenGLESMath::loadIdentity(projectionStack[0]);

    textureStacks = new std::vector<Matrix4x4<GLfloat>*>[implementation->maxTextureImageUnits];
    for (int i = 0; i < implementation->maxTextureImageUnits; i++) {
        textureStacks[i].push_back(new Matrix4x4<GLfloat>());
        OpenGLESMath::loadIdentity(textureStacks[i][0]);
    }

    currentStack = &modelViewStack;
}

void MatrixStack::setMatrixMode(GLenum m) {
    mode = m;

    switch (mode) {
        case GL_MODELVIEW:
            currentStack = &modelViewStack;
            break;
        case GL_PROJECTION:
            currentStack = &projectionStack;
            break;
        case GL_TEXTURE:
            currentStack = &textureStacks[openGLESState->getActiveTexture()];
            openGLESState->setTextureMatrix(
                openGLESState->getActiveTexture(),
                true); // TODO: could be optimized more.. only true when non-identity matrix.
            break;
        default:
            LOG_MESSAGE(__FILE__, __LINE__, "ERROR: Unknown matrix mode.");
            break;
    }
}

void MatrixStack::loadIdentity() {
    OpenGLESMath::loadIdentity(currentStack->back());
}

void MatrixStack::loadMatrix(const GLfloat* newMat) {
    Matrix4x4<GLfloat>* mat = currentStack->back();
    *mat = newMat;
}

void MatrixStack::translate(GLfloat x, GLfloat y, GLfloat z) {
    Matrix4x4<GLfloat> m;

    OpenGLESMath::loadIdentity(&m);
    OpenGLESMath::translate(&m, x, y, z);
    OpenGLESMath::multiply(currentStack->back(), &m, currentStack->back()->m);
}

void MatrixStack::rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    Matrix4x4<GLfloat> m;

    OpenGLESMath::loadIdentity(&m);
    OpenGLESMath::rotate(&m, angle, x, y, z);
    OpenGLESMath::multiply(currentStack->back(), &m, currentStack->back()->m);
}

void MatrixStack::scale(GLfloat x, GLfloat y, GLfloat z) {
    Matrix4x4<GLfloat> m;

    OpenGLESMath::loadIdentity(&m);
    OpenGLESMath::scale(&m, x, y, z);
    OpenGLESMath::multiply(currentStack->back(), &m, currentStack->back()->m);
}

void MatrixStack::frustum(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar) {
    OpenGLESMath::frustum(currentStack->back(), left, right, bottom, top, zNear, zFar);
}

void MatrixStack::ortho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar) {
    OpenGLESMath::ortho(currentStack->back(), left, right, bottom, top, zNear, zFar);
}

void MatrixStack::multiply(const GLfloat* m) {
    // OpenGLESMath::multiply(currentStack->back(), currentStack->back(), m);
    Matrix4x4<GLfloat> m2;
    memcpy(m2.m, m, sizeof(float) * 16);

    OpenGLESMath::multiply(currentStack->back(), &m2, currentStack->back()->m);
}

void MatrixStack::pushMatrix() {
    currentStack->push_back(new Matrix4x4<GLfloat>(currentStack->back()));
}

void MatrixStack::popMatrix() {
    if (currentStack->size() == 1) {
        return;
    }
    delete currentStack->back();
    currentStack->pop_back();
}

Matrix4x4<GLfloat>* MatrixStack::getModelViewMatrix() {
    return modelViewStack.back();
}

Matrix4x4<GLfloat>* MatrixStack::getProjectionMatrix() {
    return projectionStack.back();
}

Matrix4x4<GLfloat>* MatrixStack::getTextureMatrix(int index) {
    return textureStacks[index].back();
}
