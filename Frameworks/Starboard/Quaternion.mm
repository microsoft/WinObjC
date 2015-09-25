//******************************************************************************
//
// Adapted from: http://xith.org/archive/JavaCoolDude/JWS/Lwjgl/MagicRoom/source/MathUtils/Quaternion.java
//
// http://www.xith.org/
// Xith3D is released under the BSD license making its use feasible for both commercial and non-commercial
// (freeware/open-source) projects.
//
// http://opensource.org/licenses/bsd-license.php
//
//******************************************************************************

#include "Quaternion.h"
#include <cmath>
#include <cstring>

Quaternion Quaternion::Slerp(Quaternion q1, Quaternion q2, float t) {
    // Create a local quaternion to store the interpolated quaternion
    Quaternion qInterpolated;

    // This function is the milk and honey of our quaternion code, the rest of
    // the functions are an appendage to what is done here.  Everyone understands
    // the terms, "matrix to quaternion", "quaternion to matrix", "create quaternion matrix",
    // "quaternion multiplication", etc.. but "SLERP" is the stumbling block, even a little
    // bit after hearing what it stands for, "Spherical Linear Interpolation".  What that
    // means is that we have 2 quaternions (or rotations) and we want to interpolate between
    // them.  The reason what it's called "spherical" is that quaternions deal with a sphere.
    // Linear interpolation just deals with 2 points primarily, where when dealing with angles
    // and rotations, we need to use sin() and cos() for interpolation.  If we wanted to use
    // quaternions for camera rotations, which have much more instant and jerky changes in
    // rotations, we would use Spherical-Cubic Interpolation.  The equation for SLERP is this:
    //
    // q = (((b.a)^-1)^t)a
    //
    // Go here for an a detailed explanation and proofs of this equation:
    //
    // http://www.magic-software.com/Documentation/quat.pdf
    //
    // Now, Let's code it

    // Here we do a check to make sure the 2 quaternions aren't the same, return q1 if they are
    if (q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w)
        return q1;

    // Following the (b.a) part of the equation, we do a dot product between q1 and q2.
    // We can do a dot product because the same math applied for a 3D vector as a 4D vector.
    float result = (q1.x * q2.x) + (q1.y * q2.y) + (q1.z * q2.z) + (q1.w * q2.w);

    // If the dot product is less than 0, the angle is greater than 90 degrees
    if (result < 0.0f) {
        // Negate the second quaternion and the result of the dot product
        q2.x *= -1;
        q2.y *= -1;
        q2.z *= -1;
        q2.w *= -1;
        result *= -1;
    }

    // Set the first and second scale for the interpolation
    float scale0 = 1 - t, scale1 = t;

    // Next, we want to actually calculate the spherical interpolation.  Since this
    // calculation is quite computationally expensive, we want to only perform it
    // if the angle between the 2 quaternions is large enough to warrant it.  If the
    // angle is fairly small, we can actually just do a simpler linear interpolation
    // of the 2 quaternions, and skip all the complex math.  We create a "delta" value
    // of 0.1 to say that if the cosine of the angle (result of the dot product) between
    // the 2 quaternions is smaller than 0.1, then we do NOT want to perform the full on
    // interpolation using.  This is because you won't really notice the difference.

    // Check if the angle between the 2 quaternions was big enough to warrant such calculations
    if (1 - result > 0.1f) {
        // Get the angle between the 2 quaternions, and then store the sin() of that angle
        float theta = (float)acos(result);
        float sinTheta = (float)sin(theta);

        // Calculate the scale for q1 and q2, according to the angle and it's sine value
        scale0 = (float)sin((1 - t) * theta) / sinTheta;
        scale1 = (float)sin((t * theta)) / sinTheta;
    }

    // Calculate the x, y, z and w values for the quaternion by using a special
    // form of linear interpolation for quaternions.
    qInterpolated.x = (scale0 * q1.x) + (scale1 * q2.x);
    qInterpolated.y = (scale0 * q1.y) + (scale1 * q2.y);
    qInterpolated.z = (scale0 * q1.z) + (scale1 * q2.z);
    qInterpolated.w = (scale0 * q1.w) + (scale1 * q2.w);

    // Return the interpolated quaternion
    return qInterpolated;
}

void Quaternion::CreateMatrix(float* pMatrix) {
    // Fill in the rows of the 4x4 matrix, according to the quaternion to matrix equations
    // First row
    pMatrix[0] = 1.0f - 2.0f * (y * y + z * z);
    pMatrix[1] = 2.0f * (x * y - w * z);
    pMatrix[2] = 2.0f * (x * z + w * y);
    pMatrix[3] = 0.0f;

    // Second row
    pMatrix[4] = 2.0f * (x * y + w * z);
    pMatrix[5] = 1.0f - 2.0f * (x * x + z * z);
    pMatrix[6] = 2.0f * (y * z - w * x);
    pMatrix[7] = 0.0f;

    // Third row
    pMatrix[8] = 2.0f * (x * z - w * y);
    pMatrix[9] = 2.0f * (y * z + w * x);
    pMatrix[10] = 1.0f - 2.0f * (x * x + y * y);
    pMatrix[11] = 0.0f;

    // Fourth row
    pMatrix[12] = 0;
    pMatrix[13] = 0;
    pMatrix[14] = 0;
    pMatrix[15] = 1.0f;
    // Now pMatrix[] is a 4x4 homogeneous matrix that can be applied to an OpenGL Matrix
}

void Quaternion::CreateFromMatrix(float* pTheMatrix) {
    // This function is used to take in a 3x3 or 4x4 matrix and convert the matrix
    // to a quaternion.  If rowColumnCount is a 3, then we need to convert the 3x3
    // matrix passed in to a 4x4 matrix, otherwise we just leave the matrix how it is.
    // Since we want to apply a matrix to an OpenGL matrix, we need it to be 4x4.

    // Point the matrix pointer to the matrix passed in, assuming it's a 4x4 matrix
    float pMatrix[16];
    memcpy(pMatrix, pTheMatrix, sizeof(float) * 16);

    // The next step, once we made sure we are dealing with a 4x4 matrix, is to check the
    // diagonal of the matrix.  This means that we add up all of the indices that comprise
    // the standard 1's in the identity matrix.  If you draw out the identity matrix of a
    // 4x4 matrix, you will see that they 1's form a diagonal line.  Notice we just assume
    // that the last index (15) is 1 because it is not effected in the 3x3 rotation matrix.

    // Find the diagonal of the matrix by adding up it's diagonal indices.
    // This is also known as the "trace", but I will call the variable diagonal.
    float diagonal = pMatrix[0] + pMatrix[5] + pMatrix[10] + 1;
    float scale = 0.0f;

    // Below we check if the diagonal is greater than zero.  To avoid accidents with
    // floating point numbers, we substitute 0 with 0.00000001.  If the diagonal is
    // great than zero, we can perform an "instant" calculation, otherwise we will need
    // to identify which diagonal element has the greatest value.  Note, that it appears
    // that %99 of the time, the diagonal IS greater than 0 so the rest is rarely used.

    // If the diagonal is greater than zero
    if (diagonal > 0.00000001) {
        // Calculate the scale of the diagonal
        scale = (float)(sqrt(diagonal) * 2);
        // Calculate the x, y, x and w of the quaternion through the respective equation
        x = (pMatrix[9] - pMatrix[6]) / scale;
        y = (pMatrix[2] - pMatrix[8]) / scale;
        z = (pMatrix[4] - pMatrix[1]) / scale;
        w = 0.25f * scale;
    } else {
        // If the first element of the diagonal is the greatest value
        if (pMatrix[0] > pMatrix[5] && pMatrix[0] > pMatrix[10]) {
            // Find the scale according to the first element, and double that value
            scale = (float)sqrt(1.0f + pMatrix[0] - pMatrix[5] - pMatrix[10]) * 2.0f;
            // Calculate the x, y, x and w of the quaternion through the respective equation
            x = 0.25f * scale;
            y = (pMatrix[4] + pMatrix[1]) / scale;
            z = (pMatrix[2] + pMatrix[8]) / scale;
            w = (pMatrix[9] - pMatrix[6]) / scale;
        } else if (pMatrix[5] > pMatrix[10]) {
            // Find the scale according to the second element, and double that value
            scale = (float)sqrt(1.0f + pMatrix[5] - pMatrix[0] - pMatrix[10]) * 2.0f;
            // Calculate the x, y, x and w of the quaternion through the respective equation
            x = (pMatrix[4] + pMatrix[1]) / scale;
            y = 0.25f * scale;
            z = (pMatrix[9] + pMatrix[6]) / scale;
            w = (pMatrix[2] - pMatrix[8]) / scale;
        } else {
            // Find the scale according to the third element, and double that value
            scale = (float)sqrt(1.0f + pMatrix[10] - pMatrix[0] - pMatrix[5]) * 2.0f;
            // Calculate the x, y, x and w of the quaternion through the respective equation
            x = (pMatrix[2] + pMatrix[8]) / scale;
            y = (pMatrix[9] + pMatrix[6]) / scale;
            z = 0.25f * scale;
            w = (pMatrix[4] - pMatrix[1]) / scale;
        }
    }
}

float Quaternion::norm() const {
    return sqrtf(x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::fromEuler(float yaw, float pitch, float roll) {
    float c1 = cosf(yaw / 2), c2 = cosf(pitch / 2), c3 = cosf(roll / 2);
    float s1 = sinf(yaw / 2), s2 = sinf(pitch / 2), s3 = sinf(roll / 2);

    return Quaternion(c1 * c2 * c3 - s1 * s2 * s3,
                      s1 * s2 * c3 + c1 * c2 * s3,
                      s1 * c2 * c3 + c1 * s2 * s3,
                      c1 * s2 * c3 - s1 * c2 * s3);
}

float Quaternion::yaw() const {
    return atan2f(2 * (x * w + y * z), 1 - 2 * (z * z + w * w));
}

float Quaternion::pitch() const {
    return asinf(2 * (x * z - w * y));
}

float Quaternion::roll() const {
    return atan2f(2 * (x * y + z * w), 1 - 2 * (y * y + z * z));
}
