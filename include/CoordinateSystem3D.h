#ifndef _COORDINATE_SYSTEM_3D_H
#define _COORDINATE_SYSTEM_3D_H

#include "Vector3D.h"

#include "Matrix3D.h"

#include <obj-utils.h>

const double aaaSmall = 1.0 / 64;

class CoordinateSystem3D
{
    Vector3D origin;
    Vector3D baseX;
    Vector3D baseY;
    Vector3D baseZ;

    static CoordinateSystem3D *_XY;
    static CoordinateSystem3D *_XZ;
    static CoordinateSystem3D *_YZ;
    static CoordinateSystem3D *_WCS;

public:
    const Vector3D &Origin() const;
    const Vector3D &BaseX() const;
    const Vector3D &BaseY() const;
    const Vector3D &BaseZ() const;

    /**
     * @brief right handed XY ( Z ) : top view
     */
    const static CoordinateSystem3D &XY();

    /**
     * @brief right handed XZ ( -Y ) : front view
     */
    const static CoordinateSystem3D &XZ();

    /**
     * @brief right handed YZ ( X ) : side view
     */
    const static CoordinateSystem3D &YZ();

    /**
     * @brief world cs : basex=(1,0,0) basey=(0,1,0) basez=(0,0,1)     
     */
    const static CoordinateSystem3D &WCS();

    Matrix3D m;
    Matrix3D mInv;

    // const static CoordinateSystem3D &XY;

    enum CoordinateSystem3DAutoEnum
    {
        /**
         * @brief Arbitrary Axis Alghoritm ( dxf spec )         
         */
        AAA,

        /**
         * @brief Strand7 ( Element Library : Beam Principal Axis System ; Default principal axes of a beam element )
         * Note: Normal must beam Start to End direction
         */
        St7
    };

    enum SmartCsMode
    {
        /**
         * @brief first vector must parallel csXaxis ; second vector must lie on desired csXY plane and not parallel to csXaxis ;
         * csZaxis is computed as csXaxis cross second vector         
         */
        X_YQ,

        /**
         * @brief first vector must parallel to csZaxis ; second vector must parallel to csXaxis        
         */
        Z_X,

        /**
         * @brief first vector must parallel to csZaxis ; second vector must parallel to csYaxis         
         */
        Z_Y
    };

    /**
     * @brief default cs (wcs)     
     */
    CoordinateSystem3D();

    /**
     * @brief build coordinate system with given origin and given BaseZ on given vector normal;
     * given normal will subjected to normalization;
     * depending on csAutoType one or another arbitrary axis alghoritm will used to build cs from a point and a normal.
     * 
     * @param o origin of cs
     * @param normal Z vector of cs
     * @param csAutoType auto cs type
     */
    CoordinateSystem3D(const Vector3D &o, const Vector3D &normal,
                       CoordinateSystem3DAutoEnum csAutoType = CoordinateSystem3DAutoEnum::AAA);

    /**
     * @brief construct a coordinate system with the given origin and orthonormal bases
     * note that given bases MUST already normalized        
     * 
     * @param o cs origin<
     * @param baseX cs X base ( must already normalized )
     * @param baseY cs Y base ( must already normalized )
     * @param baseZ cs Z base ( must already normalized )
     */
    CoordinateSystem3D(const Vector3D &o, const Vector3D &baseX, const Vector3D &baseY, const Vector3D &baseZ);

    /**
     * @brief Construct a right-hand coordinate system with the given origin and two vector
     * 
     * @param o cs origin
     * @param v1 first vector
     * @param v2 second vector
     * @param mode specify how to consider first and second vector to build the cs
     */
    CoordinateSystem3D(const Vector3D &o, const Vector3D &v1, const Vector3D &v2, SmartCsMode mode = SmartCsMode::X_YQ);

    /**
     * @brief Transform wcs point to given cs
     * 
     * @param p wcs point
     * @param evalCSOrigin if true CS origin will subtracted from wcs point before transform     
     */
    Vector3D ToUCS(const Vector3D &p, bool evalCSOrigin = true) const;

    /**
     * @brief Transform ucs point to given wcs
     * 
     * @param p wcs point
     * @param evalCSOrigin f true CS origin will added after transform
     */
    Vector3D ToWCS(const Vector3D &p, bool evalCSOrigin = true) const;

    /**
     * @brief verify if this cs XY plane contains given wcs point
     * 
     * @param tol calc tolerance
     * @param point point to verify
     * @param evalCSOrigin if true CS origin will subtracted before transform test
     * @return true if point contained in cs, else otherwise      
     */
    bool Contains(V3DNR tol, const Vector3D &point, bool evalCSOrigin = true);

    /**
     * @brief verify is this cs is equals to otherByLayer ( same origin, x, y, z base vectors )            
     * 
     * @param tol calc tolerance ( for origin check )
     * @param other cs to check equality against
     * @return true if this cs equals the given on, false otherwise     
     */
    bool Equals(V3DNR tol, const CoordinateSystem3D &other);

    /**
     * @brief states if this cs have Z base parallel to the other given cs
     */
    bool IsParallelTo(V3DNR tol, const CoordinateSystem3D &other) const;

    /**
     * @brief return another cs with origin translated
     */
    CoordinateSystem3D Move(const Vector3D &delta) const;

    /**
     * @brief return another cs rotated respect given axis
     */
    CoordinateSystem3D Rotate(const Line3D &axis, V3DNR angleRad) const;

    /**
     * @brief return another cs with same origin and base vector rotated about given vector            
     */
    CoordinateSystem3D Rotate(const Vector3D &vectorAxis, V3DNR angleRad) const;

    /**
     * @brief return intersect line between two cs xy planes
     * 
     * @param tol len tolernace
     * @param other other cs
     * @return Line3D null if cs parallel to the given other
     */
    nullable<Line3D> Intersect(V3DNR tol, const CoordinateSystem3D &other) const;
};

#endif