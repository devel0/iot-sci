#ifndef _TRANSFORM3D_H
#define _TRANSFORM3D_H

#include "Quaternion.h"
#include "Vector3D.h"

/**
 * @brief Use quaternion to append rotate transformations 
 */
class Transform3D
{

    Quaternion q;

public:
    /**
     * @brief instantiate an identity transformation        
     */
    Transform3D();

    /**
     * @brief add rotation about X axis of given angle to the current rotation matrix        
     * 
     * @param angleRad rotation angle about X axis
     */
    void RotateAboutXAxis(double angleRad);

        /**
     * @brief add rotation about Y axis of given angle to the current rotation matrix        
     * 
     * @param angleRad rotation angle about Y axis
     */
    void RotateAboutYAxis(double angleRad);

        /**
     * @brief add rotation about Z axis of given angle to the current rotation matrix        
     * 
     * @param angleRad rotation angle about Z axis
     */
    void RotateAboutZAxis(double angleRad);

    /**
     * @brief add rotation about given axis of given angle to the current rotation matrix.
     * given axis will subjected to normalization        
     * 
     * @param axis custom rotation axis
     * @param angleRad rotation angle about given axis
     */
    void RotateAboutAxis(const Vector3D& axis, V3DNR angleRad);

    /**
     * @brief apply this transformation to given vector returning new one        
     * 
     * @param v vector to transform     
     */
    Vector3D Apply(const Vector3D& v);
};

#endif
