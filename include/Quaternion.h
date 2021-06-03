#ifndef _QUATERNION_H
#define _QUATERNION_H

#include "Vector3D.h"

/**
 * @brief Quaternion implementation using doubles for purpose of Vector3D.RotateAboutAxis and Vector3D.RotateAs
 * references:
 * - http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/index.htm
 * - https://www.3dgep.com/understanding-quaternions/
 * - http://www.ncsa.illinois.edu/People/kindr/emtc/quaternions/
 */
class Quaternion
{

public:
    /**
     * @brief direct construct quaternion q=[s, v]
     */
    Quaternion(V3DNR s, const Vector3D &v);

    /**
     * @brief build quaternion from axis and angle. axis will be subjected to normalization.
     */
    Quaternion(const Vector3D &axis, V3DNR alphaRad);

    Vector3D v;

    V3DNR s;

    /**
     * @brief Identity qi = [1, nullvector]     
     */
    const static Quaternion &Identity;

    /**
     * @brief Conjugate
     * q* = [s, -v]        
     */
    Quaternion Conjugate() const;    
};

/**
 * @brief Multiply
 * [sa, va] * [sb, vb] = [sa * sb - va * vb, va x vb + sa * vb + sb * va]
 */
Quaternion operator *(Quaternion qa, Quaternion qb);

#endif