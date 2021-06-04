#ifndef _CIRCLE3D_H
#define _CIRCLE3D_H

#include "Arc3D.h"

class Circle3D : public Arc3D
{
public:
    Circle3D(V3DNR tol_len, const CoordinateSystem3D &cs, V3DNR r);
    Circle3D(const Arc3D &arc);
    Circle3D(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3);

    bool Contains(V3DNR tol, const Vector3D &p, bool onlyPerimeter);

    /**
     * @brief build 3d circle that tangent to lines t1,t2 and that intersects point p
     * note: point p must contained in one of t1,t2
     * circle will be inside region t1.V toward t2.V
     * they are 4 circles
     */
    static vector<Circle3D> CirclesTan12P(V3DNR tol_len, const Line3D &t1, const Line3D &t2, const Vector3D &p);

    /**
     * @brief build 3d circle through point p, tangent to given t line, with given radius r            
     * they can be two
     */
    static vector<Circle3D> CircleRTanP(V3DNR tol_len, const Vector3D &p, const Line3D &t, V3DNR r);

    /**
     * @brief intersect this 3d circle with given 3d line
     */
    vector<Vector3D> Intersect(V3DNR tol, const Line3D &l, bool only_perimeter = true, bool segment_mode = false) const;

    /**
     * @brief intersect this 3d circle with given other
     */
    vector<Vector3D> Intersect(V3DNR tol, const Circle3D &other) const;

    V3DNR Area() const;

    /**
     * @brief Circle perimeter
     */
    V3DNR Length() const;
};

#endif