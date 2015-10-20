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

//  Derived from
//  http://xith.org/archive/JavaCoolDude/JWS/Xith3D/Quake3/source/org/xith3d/loaders/md3/md3math/CQuaternion.java

class Quaternion {
    union {
        struct {
            float w, x, y, z;
        }; // Q = ix + jy + kz + w
        float q[4];
    };

public:
    Quaternion() : x(0), y(0), z(0), w(1) {
    }
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {
    }

    static Quaternion fromEuler(float /* yaw/azimuth/heading */, float /* pitch/attitude */, float /* roll/bank */);

    // This interface is really ugly and should be fixed...
    void CreateMatrix(float* pMatrix);
    void CreateFromMatrix(float* pTheMatrix);

    Quaternion conjugate() const {
        return Quaternion(-x, -y, -z, w);
    }
    float norm() const;

    Quaternion inverse() const {
        return conjugate() / norm();
    }

    static Quaternion Slerp(Quaternion q1, Quaternion q2, float t);

    Quaternion& operator=(const Quaternion& r) {
        for (int i = 0; i < 4; ++i)
            q[i] = r.q[i];
        return *this;
    }

    Quaternion operator/(float d) const {
        return Quaternion(x / d, y / d, z / d, w / d);
    }

    Quaternion operator*(const Quaternion& r) const {
        return Quaternion(r.q[0] * q[0] - r.q[1] * q[1] - r.q[2] * q[2] - r.q[3] * q[3],
                          r.q[0] * q[1] + r.q[1] * q[0] - r.q[2] * q[3] + r.q[3] * q[2],
                          r.q[0] * q[2] + r.q[1] * q[3] + r.q[2] * q[0] - r.q[3] * q[1],
                          r.q[0] * q[3] - r.q[1] * q[2] + r.q[2] * q[1] + r.q[3] * q[0]);
    }

    void operator*=(const Quaternion& r) {
        *this = *this * r;
    }

    float yaw() const;
    float pitch() const;
    float roll() const;
};