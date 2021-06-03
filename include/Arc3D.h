#ifndef _ARC_3D_H
#define _ARC_3D_H

#include "Vector3D.h"
#include "CoordinateSystem3D.h"
#include "Line3D.h"

struct CircleBy3PointsNfo
{
    CircleBy3PointsNfo(CoordinateSystem3D cs, V3DNR radius)
    {
        this->cs = cs;
        this->radius = radius;
    }
    CoordinateSystem3D cs;
    V3DNR radius;
};

// TODO: bbox, divide, split actually missing

class Arc3D
{

protected:
    V3DNR radius;
    const CoordinateSystem3D cs;
    V3DNR tol_rad;
    V3DNR angle_start;
    V3DNR angle_end;

public:
    V3DNR Radius() const;
    const CoordinateSystem3D &CS() const;

    /**
     * @brief construct 3d arc
     * 
     * @param tol_len tolerance over length
     * @param cs coordinate system with origin at arc center, XY plane of cs contains the arc, angle is 0 at cs x-axis and increase right-hand around cs z-axis
     * @param r arc radius
     * @param angleRadStart arc angle start (rad). is not required that start angle less than end. It will normalized 0-2pi
     * @param angleRadEnd arc angle end (rad). is not require that end angle great than start. It will normalized 0-2pi
     */
    Arc3D(V3DNR tol_len, const CoordinateSystem3D &cs,
          V3DNR r, V3DNR angleRadStart, V3DNR angleRadEnd);

    /**
     * @brief build 3d arc by given 3 points
     * 
     * @param tol_len tolerance over length
     * @param p1 first constraint point
     * @param p2 second constraint point
     * @param p3 third constraint point
     * @param normal the inside CS will centered in the arc center and Xaxis toward p1
     */
    Arc3D(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3,
          const nullable<Vector3D> &normal = nullable<Vector3D>());

    /**
     * @brief start angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis 
     * note that start angle can be greather than end angle     
     */
    V3DNR AngleStart() const;

    /**
     * @brief end angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis 
     * note that start angle can be greather than end angle     
     */
    V3DNR AngleEnd() const;

    /**
     * @brief helper to build circle by given 3 points
     * 
     * @param p1 first constraint point
     * @param p2 second constraint point
     * @param p3 third constraint point
     * @return cs and radius that describe a 3d circle
     */
    static CircleBy3PointsNfo CircleBy3Points(const Vector3D &p1, const Vector3D &p2, const Vector3D &p3);

    /**
     * @brief build 3d arc by given 3 points
     * 
     * @param tol_len tolerance over length
     * @param p1 first constraint point
     * @param p2 second constraint point
     * @param p3 third constraint point
     * @param normal the inside CS will centered in the arc center and Xaxis toward p1
     * 
     * @return 3d arc passing for given points with angles 0-2pi
     */
    static Arc3D Arc3DBy3Points(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3,
                                const nullable<Vector3D> &normal = nullable<Vector3D>());

    /**
     * @brief create an arc copy with origin moved
     * 
     * @param tol_len length tolerance
     * @param delta new arc origin delta     
     */
    Arc3D Move(V3DNR tol_len, const Vector3D &delta) const;

    /**
     * @brief Arc (rad) angle length.
     * 
     * @return V3DNR angle between start-end or end-start depending on what start is less than end or not
     */
    V3DNR Angle() const;

    /**
     * @brief Length of Arc from start to end    
     */
    V3DNR Length() const;

    /**
     * @brief point on the arc circumnfere at given angle (rotating cs basex around cs basez)
     */
    Vector3D PtAtAngle(V3DNR angleRad) const;

    /**
     * @brief mid point eval as arc point at angle start + arc angle/2
     */
    Vector3D MidPoint() const;

    /**
     * @brief return the angle (rad) of the point respect cs x axis rotating around cs z axis 
     * to reach given point angle alignment
     */
    V3DNR PtAngle(V3DNR tolLen, const Vector3D &pt) const;

    const Vector3D &Center() const;

    /**
     * @brief point at angle start
     */
    Vector3D From() const;

    /**
     * @brief point at angle end
     */
    Vector3D To() const;

    vector<Vector3D> Vertexes() const;

    /**
     * @brief return from,to segment
     */
    const Line3D Segment() const;

    /**
     * @brief Checks if two arcs are equals ( it checks agains swapped from-to too )
     */
    bool EqualsTol(V3DNR tolLen, const Arc3D &other) const;

    /**
     * @brief http://www.lee-mac.com/bulgeconversion.html     
     */
    V3DNR Bulge(V3DNR tolLen, const Vector3D &from, const Vector3D &to, const Vector3D &N) const;

    /**
     * @brief statis if given point contained in arc perimeter/shape or circle perimeter/shape depending on specified mode
     * 
     * @param tol_len len tolerance
     * @param pt point to test
     * @param inArcAngleRange true if point angle must contained in arc angles, false to test like a circle
     * @param onlyPerimeter true to test point contained only in perimeter, false to test also contained in area
     */
    bool Contains(V3DNR tol_len, const Vector3D &pt, bool inArcAngleRange, bool onlyPerimeter) const;

    /**
     * @brief states if given point relies on this arc perimeter or shape depending on arguments
     * 
     * @param tol_len length tolerance
     * @param pt point to check
     * @param onlyPerimeter if true it checks if point is on perimeter; if false it will check in area too 
     */
    bool Contains(V3DNR tol_len, const Vector3D &pt, bool onlyPerimeter) const;

    /**
     * @brief intersect this 3d circle with given 3d line
     */
    vector<Vector3D> IntersectCircle(V3DNR tol, const Line3D &l, bool segment_mode = false) const;

    /**
     * @brief states if this arc intersect given line
     * 
     * @param tol len tolerance
     * @param l line to test intersect
     * @param only_perimeter check intersection only along perimeter; if false it will check intersection along arc area shape border too
     * @param segment_mode if true line treat as segment instead of infinite
     * @param circle_mode if true arc treat as circle     
     */
    vector<Vector3D> Intersect(V3DNR tol, const Line3D &l, bool only_perimeter, bool segment_mode, bool circle_mode) const;

    /**
     * @brief find ips of intersection between this arc and given line
     * 
     * @param tol length tolerance
     * @param l line
     * @param only_perimeter check intersection only along perimeter; if false it will check intersection along arc area shape border too
     * @param segment_mode if true treat given line as segment; if false as infinite line
     * @return vector<Vector3D> 
     */
    vector<Vector3D> Intersect(V3DNR tol, const Line3D &l, bool only_perimeter = true, bool segment_mode = false) const;

    /**
     * @brief find ips of intersect this arc to the given cs plane; 
     * return empty set if arc cs plane parallel to other given cs
     * 
     * @param tol len tolerance
     * @param cs cs xy plane
     * @param only_perimeter if false it will check in the arc area too, otherwise only on arc perimeter     
     */
    vector<Vector3D> Intersect(V3DNR tol, const CoordinateSystem3D &cs, bool only_perimeter = true) const;
};

/**
     * @brief compute angle rad tolerance by given arc length tolerance as (lenTol / radius)
     * 
     * @param lenTol length tolerance on the arc
     * @param radius radius of the arc     
     */
V3DNR RadTol(V3DNR lenTol, V3DNR radius);

/**
     * @brief Normalize given angle(rad) into [maxRad-2PI,maxRad) range.
     * 
     * @param angle_rad angle(rad) to normalize
     * @param tol_rad tolerance over rad
     * @param maxRadExcluded normalization range (excluded) max value ( minimum will computed as max-2PI )     
     */
V3DNR NormalizedAngle(V3DNR tol_rad, V3DNR angle_rad, V3DNR maxRadExcluded = 2 * PI);

/**
 * @brief retrieve angle between from and to given; angles will subjected to normalization [0,2pi) and angle from can be greather than to  
 */
V3DNR Angle(V3DNR tol_rad, V3DNR angleFrom, V3DNR angleTo, bool normalizeAngles = true);

/**
 * @brief states if given angle is contained in from, to angle range; 
 * multiturn angles are supported because test will normalize to [0,2pi) automatically.
 * 
 * @param tol_rad angle(rad) tolerance
 * @param pt_angle angle(rad) to test
 * @param angle_from angle(rad) from
 * @param angle_to angle(rad) to
 */
bool AngleInRange(V3DNR tol_rad, V3DNR pt_angle, V3DNR angle_from, V3DNR angle_to);

#endif
