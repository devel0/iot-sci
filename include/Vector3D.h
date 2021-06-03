#ifndef _VECTOR_3D_H
#define _VECTOR_3D_H

#include <Arduino.h>

#include <string-utils.h>
#include <sys-debug.h>
#include <vector>

using namespace std;

#ifndef V3DNR
#define V3DNR double
#define V3DSQRT(x) sqrt(x)
#define V3DACOS(x) acos(x)
#define V3DCOS(x) cos(x)
#define V3DSIN(x) sin(x)
#define V3DPOW(x, y) pow(x, y)
#define V3DTAN(x) tan(x)
#define V3DASIN(x) asin(x)
#endif

#define NormalizedLengthTolerance 1e-5

class CoordinateSystem3D;
class Line3D;

/**
 * @brief can be used to describe a wcs point or a vector x,y,z components from some reference origin
 */
class Vector3D
{

    static Vector3D *_Zero;
    static Vector3D *_XAxis;
    static Vector3D *_YAxis;
    static Vector3D *_ZAxis;
    static Vector3D *_One;

public:
    V3DNR X, Y, Z;

    /**
     * @brief zero vector     
    */
    Vector3D();

    /**
     * @brief build a vector by given components            
     */
    Vector3D(V3DNR x, V3DNR y, V3DNR z);

    /**
     * @brief build a vector (x,y,0) by given components            
     */
    Vector3D(V3DNR x, V3DNR y);

    ~Vector3D();

    /**
     * @brief zero vector (0,0,0)            
     */
    const static Vector3D &Zero();

    /**
     * @brief xaxis vector (1,0,0)                 
     */
    const static Vector3D &XAxis();

    /**
     * @brief yaxis vector (0,1,0)                 
     */
    const static Vector3D &YAxis();

    /**
     * @brief zaxis vector (0,0,1)                 
     */
    const static Vector3D &ZAxis();

    /**
     * @brief one vector (1,1,1)                 
     */
    const static Vector3D &One();

    /**
     * @brief retrieve wcs axis by given index            
     * 
     * @param ord 0:(1,0,0) 1:(0,1,0) 2:(0,0,1)
     */
    const static Vector3D &Axis(int ord);

    V3DNR GetOrd(int index) const;

    /**
     * @brief indexed vector component
     */
    V3DNR operator[](int index) const;

    /**
     * @brief vector sum
     */
    Vector3D operator+(const Vector3D &b) const;

    /**
     * @brief vector diff
     */
    Vector3D operator-(const Vector3D &b) const;

    /**
     * @brief vector scalar
     */
    Vector3D operator*(V3DNR s) const;

    /**
     * @brief vector scalar
     */
    Vector3D operator/(V3DNR s) const;

    /**
     * @brief dot product ( a b = |a| |b| cos(alfa) )
     */
    V3DNR operator*(const Vector3D &b) const;

    /**
     * @brief invert components sign
     */
    Vector3D operator-() const;

    /**
     * @brief Length of this vector
     */
    V3DNR Length() const;

    /**
     * @brief create a normalized version of this vector
     */
    Vector3D Normalized() const;

    /**
     * @brief compute distance between this point and the other given
     */
    V3DNR Distance(const Vector3D &other) const;

    /**
     * @brief compute perpendicular(min) distance of this point from given line            
     * 
     * @param tol length tolerance ( used to check if point contained in line )
     * @param other line     
     */
    V3DNR Distance(V3DNR tol, const Line3D &other) const;

    /**
     * @brief compute distance of this point from the given in 2d ( x,y ) without consider z component            
     * 
     * @param other other point     
     */
    V3DNR Distance2D(const Vector3D &other) const;

    /**
     * @brief compute dot product of this vector for the given one `a b = |a| |b| cos(alfa)`
     * @param other second vector     
     */
    V3DNR DotProduct(const Vector3D &other) const;

    /**
     * @brief states is this vector is perpendicular to the given one            
     * 
     * @param other other vector
     */
    bool IsPerpendicular(const Vector3D &other) const;

    /**
     * @brief Cross product ( not normalized ) `a x b = |a| |b| sin(alfa)` ;
     * 
     * `a x b = |  x  y  z |       | ax ay az |      | bx by bz |`
     * 
     * [reference](https://en.wikipedia.org/wiki/Cross_product) ;          
     * 
     * @param other other vector     
     */
    Vector3D CrossProduct(const Vector3D &other) const;

    /**
     * @brief angle between this and given vector
     * 
     * @param tolLen geometric tolerance to test vector equalities ( use Constants.NormalizedLengthTolerance when comparing normalized vectors )
     * @param to other vector
     * @return V3DNR angle between two vectors (rad)
     */
    V3DNR AngleRad(V3DNR tolLen, const Vector3D &to) const;

    /**
     * @brief project this vector to the given one
     * 
     * @param to other vector
     * @return Vector3D projected vector ( will be colinear to the given one )
     */
    Vector3D Project(const Vector3D &to) const;

    /**
     * @brief project this point to the given line
     * 
     * @param line line to project the point onto
     * @return Vector3D projected point onto the line ( perpendicularly )
     */
    Vector3D Project(const Line3D &line) const;

    /**
     * @brief create a point copy of this one with component changed
     * 
     * @param ordIdx component to change ( 0:x 1:y 2:z )
     * @param value value to assign to the component
     * @return Vector3D new vector with component changed
     */
    Vector3D Set(int ordIdx, V3DNR value);

    /**
     * @brief create new vector with X changed
     * 
     * @param value input vector
     * @return Vector3D output vector with X changed
     */
    Vector3D SetX(V3DNR value);

    /**
     * @brief create new vector with Y changed
     * 
     * @param value input vector
     * @return Vector3D output vector with Y changed
     */
    Vector3D SetY(V3DNR value);

    /**
     * @brief create new vector with Z changed
     * 
     * @param value input vector
     * @return Vector3D output vector with Z changed
     */
    Vector3D SetZ(V3DNR value);

    /**
     * @brief create a vector relative to given origin from this point and given origin
     * 
     * @param origin origin to make this point relative to
     * @return Vector3D vector
     */
    Vector3D Rel(const Vector3D &origin) const;

    /**
     * @brief Note: tol must be Constants.NormalizedLengthTolerance if comparing normalized vectors        
     */
    bool IsParallelTo(V3DNR tol, const Vector3D &other) const;

    /**
     * @brief states if this vector is colinear to the given one
     * 
     * @param tol geometric tolerance
     * @param other other vector
     */
    bool Colinear(V3DNR tol, const Vector3D &other) const;

    /**
     * @brief states if this vector concord to the given one
     * 
     * @param tol geometric tolerance
     * @param other other vector
     */
    bool Concordant(V3DNR tol, const Vector3D &other) const;

    /**
     * @brief compute angle required to make this point go to the given one 
     * if rotate right-hand around given reference axis
     * 
     * @param tolLen geometric tolerance ( use Constants.NormalizedLengthTolerance if working with normalized vectors )
     * @param to point toward rotate this one
     * @param refAxis reference axis to make right-hand rotation of this point toward given one
     * @return V3DNR 
     */
    V3DNR AngleToward(V3DNR tolLen, const Vector3D &to, const Vector3D &refAxis) const;

    /**
     * @brief rotate this point around x-axis using quaternion
     * 
     * @param angleRad angle (rad) of rotation
     * @return Vector3D rotated point
     */
    Vector3D RotateAboutXAxis(V3DNR angleRad) const;

    /**
     * @brief rotate this point around y-axis using quaternion
     * 
     * @param angleRad angle (rad) of rotation
     * @return Vector3D rotated point
     */
    Vector3D RotateAboutYAxis(V3DNR angleRad) const;

    /**
     * @brief rotate this point around z-axis using quaternion
     * 
     * @param angleRad angle (rad) of rotation
     * @return Vector3D rotated point
     */
    Vector3D RotateAboutZAxis(V3DNR angleRad) const;

    /**
     * @brief rotate this point right-hand around given axis using quaternion
     * 
     * @param axis rotation axis
     * @param angleRad angle (rad) of rotation
     * @return Vector3D rotated point
     */
    Vector3D RotateAboutAxis(const Vector3D &axis, V3DNR angleRad) const;

    /**
     * @brief rotate this point right-hand around given segment using quaternion
     * 
     * @param axisSegment rotation axis segment
     * @param angleRad angle (rad) of rotation
     * @return Vector3D rotated point
     */
    Vector3D RotateAboutAxis(const Line3D &axisSegment, V3DNR angleRad) const;

    /**
     * @brief rotate this point using rotation like point from goes toward point to
     * 
     * @param tol geometric tolerance ( use Constants.NormalizedLengthTolerance if vectors are normalized )
     * @param from point from describing rotation path
     * @param to point to describing rotation path
     * @param angleFactor optional angle rotation scaler
     * @param angleAddictionalRad optional angle (rad) component (added after angleFactor scaler)
     * @return Vector3D 
     */
    Vector3D RotateAs(V3DNR tol, const Vector3D &from, const Vector3D &to, V3DNR angleFactor = 1.0, V3DNR angleAddictionalRad = 0) const;

    /**
     * @brief Scale this point about the given origin with the given factor.
     */
    Vector3D ScaleAbout(const Vector3D &origin, V3DNR factor) const;

    /**
     * @brief Scale this point about the given origin with the given factor as (sx,sy,sz).
     */
    Vector3D ScaleAbout(const Vector3D &origin, const Vector3D &factor) const;

    /**
     * @brief mirror this point about given axis
     */
    Vector3D Mirror(const Line3D &axis) const;

    /**
     * @brief Convert this wcs point to given cs coord
     * 
     * @param cs dest CS
     * @param evalCSOrigin if true CS origin will subtracted before transform     
     */
    Vector3D ToUCS(const CoordinateSystem3D &cs, bool evalCSOrigin = true) const;

    /**
     * @brief Convert this ucs considered vector using given cs to the wcs
     * 
     * @param cs ucs point
     * @param evalCSOrigin if true CS origin will added after transform     
     */
    Vector3D ToWCS(const CoordinateSystem3D &cs, bool evalCSOrigin = true) const;

    /**
     * @brief Scalar multiply each components
     */
    Vector3D Scalar(V3DNR xs, V3DNR ys, V3DNR zs) const;

    /**
     * @brief wcs coord of projected coord to the given cs
     * 
     * @param cs cs to project
     * @param evalCSOrigin if true cs origin will subtracted before transform, then readded to obtain wcs point     
     */
    Vector3D Project(const CoordinateSystem3D &cs, bool evalCSOrigin = true) const;

    /**
     * @brief checks vector component equality vs other given                       
     * 
     * @param tol geometric tolerance ( note: use Constants.NormalizedLengthTolerance )
     * @param other vector to compare to this 
     */
    bool EqualsTol(V3DNR tol, const Vector3D &other) const;

    /**
     * @brief checks only x,y            
     * 
     * @param tol geometric tolerance ( note: use Constants.NormalizedLengthTolerance )     
     */
    bool EqualsTol(V3DNR tol, V3DNR x, V3DNR y) const;

    /**
     * @brief checks vector component equality vs other given                        
     * 
     * @param tol geometric tolerance ( note: use Constants.NormalizedLengthTolerance )     
     */
    bool EqualsTol(V3DNR tol, V3DNR x, V3DNR y, V3DNR z) const;

    /**
     * @brief Create an array of Vector3D from given list of 2d coords ( eg. { 100, 200, 300, 400 }
     *  will create follow list of vector3d = { (100,200,0), (300,400,0) }     
     */
    static vector<Vector3D> From2DCoords(const vector<V3DNR> &coords);

    /**
     * @brief Create an array of Vector3D from given list of 3d coords ( eg. { 100, 200, 10, 300, 400, 20 }
     * will create follow list of vector3d = { (100,200,10), (300,400,20) }                
     */
    static vector<Vector3D> From3DCoords(const vector<V3DNR> &coords);

    string ToString(int decimals = 3) const;

    /**
     * @brief hash string with given tolerance
     */
    string ToString(V3DNR tol) const;
};

/**
 * @brief vector scalar
 * 
 * @param s scalar
 * @param v vector 
 */
Vector3D operator*(V3DNR s, Vector3D v);

/**
 * @brief scalar multiply vector components V1 * V2 =
 * (V1.x * V2.x, V1.y * V2.y, V1.z * V2.z)
 */
Vector3D operator*(const Vector3D &v1, const Vector3D &v2);

#endif
