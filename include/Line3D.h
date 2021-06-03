#ifndef _LINE3D_H
#define _LINE3D_H

#include "Vector3D.h"

#include <obj-utils.h>
#include <vector>
using namespace std;

class Line3D
{
    static Line3D *_XAxisLine;
    static Line3D *_YAxisLine;
    static Line3D *_ZAxisLine;

public:
    enum Line3DConstructMode
    {
        PointAndVector
    };

    enum Line3DSegmentMode
    {
        /**
         * @brief infinite line         
         */
        None,

        /**
         * @brief Semi-line start at From         
         */
        StartFrom,

        /**
         * @brief Semi-line ending at To         
         */
        EndTo,

        /**
         * @brief Segment from-to         
         */
        FromTo
    };

    enum LineIntersectBehavior
    {
        IntMidPoint,
        IntPointOnThis,
        IntPointOnOther
    };

    const static Line3D &XAxisLine();
    const static Line3D &YAxisLine();
    const static Line3D &ZAxisLine();

    Vector3D From;
    Vector3D V;

    Vector3D To() const;
    Vector3D Dir() const;

    /**
     * @brief null invalid line
     * 
     */
    Line3D();
    Line3D(const Vector3D &from, const Vector3D &to);
    Line3D(V3DNR x1, V3DNR y1, V3DNR x2, V3DNR y2);
    Line3D(V3DNR x1, V3DNR y1, V3DNR z1, V3DNR x2, V3DNR y2, V3DNR z2);
    Line3D(const Vector3D &from, const Vector3D &v, Line3DConstructMode mode);

    V3DNR Length() const;

    /**
     * @brief Checks if two lines are equals ( it checks agains swapped from-to too )
     */
    bool EqualsTol(V3DNR tol, const Line3D &other) const;

    /**
     * @brief returns the common point from,to between two lines or null if not consecutives
     */
    nullable<Vector3D> CommonPoint(V3DNR tol, const Line3D &other) const;

    /**
     * @brief return the segment with swapped from,to
     */
    Line3D Reverse() const;

    Vector3D MidPoint() const;

    /**
     * @brief scale from,to of this line using given refpt and factor
     */
    Line3D Scale(const Vector3D &refpt, V3DNR factor) const;

    /**
     * @brief scale from,to of this line using given factor and assuming refpt = MidPoint
     * 
     * @param factor factor to scale this segment
     * @return Line3D scaled segment
     */
    Line3D Scale(V3DNR factor) const;

    /**
     * @brief Infinite line contains point. 
     * Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors      
     */
    bool LineContainsPoint(V3DNR tol, V3DNR x, V3DNR y, V3DNR z, bool segmentMode = false) const;

    /**
     * @brief Infinite line contains point. 
     * Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors      
     */
    bool LineContainsPoint(V3DNR tol, const Vector3D &p, bool segmentMode = false, bool excludeExtreme = false) const;

    /**
     * @brief Finite segment contains point. 
     * Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors     
     */
    bool SegmentContainsPoint(V3DNR tol, const Vector3D &p, bool excludeExtreme = false) const;

    /**
     * @brief Finite segment contains point. 
     * Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors     
     */
    bool SegmentContainsPoint(V3DNR tol, V3DNR x, V3DNR y, V3DNR z) const;

    /**
     * @brief states if semiline From-To(inf) contains given point
     * 
     * @param tol len tolerance
     * @param p point to verify is it on semiline     
     */
    bool SemiLineContainsPoint(V3DNR tol, const Vector3D &p) const;

    /**
     * @brief Find intersection point between this and other line using given tolerance. 
     * Returns null if no intersection, otherwise it returns a point on 
     * the shortest segment ( the one that's perpendicular to either lines ) 
     * based on given behavior ( default midpoint ).      
     */
    nullable<Vector3D> Intersect(V3DNR tol, const Line3D &other, LineIntersectBehavior behavior = LineIntersectBehavior::IntMidPoint) const;

    /**
     * @brief Find apparent intersection between this and given other line 
     *  returning (shortest) segment perpendicular to either lines or null if lines parallels. 
     *  This method will used from Intersect to find intersection between lines when 
     *  perpendicular segment length not exceed given length tolerance.    
     * 
     * @param other other 3d line
     */
    nullable<Line3D> ApparentIntersect(const Line3D &other) const;

    /**
     * @brief Intersects two lines with arbitrary segment mode for each.
     */
    nullable<Vector3D> Intersect(V3DNR tol, const Line3D &other, bool thisSegment, bool otherSegment) const;

    /**
     * @brief Build a perpendicular vector to this one starting from the given point p.
     */
    nullable<Line3D> Perpendicular(V3DNR tol, const Vector3D &p) const;

    bool Colinear(V3DNR tol, const Line3D &other) const;

    bool IsParallelTo(V3DNR tol, const CoordinateSystem3D &cs) const;

    /**
     * @brief returns null if this line is parallel to the cs xy plane, the intersection point otherwise
     */
    nullable<Vector3D> Intersect(V3DNR tol, const CoordinateSystem3D &cs) const;

    /**
     * @brief rotate this segment about given axis     
     */
    Line3D RotateAboutAxis(const Line3D &axisSegment, V3DNR angleRad) const;

    /**
     * @brief resize this segment to a new one with same From
     */
    Line3D SetLength(V3DNR len) const;

    /**
     * @brief move this segment of given delta
     */
    Line3D Move(const Vector3D &delta) const;

    /**
     * @brief Move this segment midpoint to the given coord
     */
    Line3D MoveMidpoint(const Vector3D &newMidpoint) const;

    /**
     * @brief split current segment into one or more depending on which of given split points was found on the segment    
     * splitted segments start from begin of line; TODO: not optimize
     */
    vector<Line3D> Split(V3DNR tolLen, const vector<Vector3D> &splitPts) const;

    /**
     * @brief if this segment from matches the given point returns this; 
     *  if this segment to matches the given point return this with from,to swapped; 
     *  precondition: this segment must have from or to equals given from    
     */
    Line3D EnsureFrom(V3DNR tolLen, const Vector3D &pt) const;

    /**
     * @brief create offseted line toward refPt for given offset     
     */
    Line3D Offset(V3DNR tol, const Vector3D &refPt, V3DNR offset) const;

    /**
     * @brief build a segment with same from and vector normalized
     */
    Line3D Normalized() const;

    /**
     * @brief return segment with swapped from,to
     */
    Line3D Swapped() const;

    /**
     * @brief return inverted segment
     */
    Line3D Inverted() const;

    /**
     * @brief returns bisect of two given segment/lines 
     * ( if given segment not share nodes but intesects returned bisect start from ip ) 
     * bisect choosen will be the one between this and other withing shortest angle 
     * 
     * if two given lines are parallel and parallelRotationAxis is given then 
     * bisect results as this segment rotated PI/2 about given axis using To as rotcenter          
     */
    nullable<Line3D> Bisect(V3DNR tol_len, const Line3D &other, const nullable<Vector3D> &parallelRotationAxis = nullable<Vector3D>()) const;

};

/**
 * @brief multiply Length by given scalar factor
 * Note : this will change To
 */
Line3D operator*(V3DNR s, const Line3D &l);

/**
 * @brief multiply Length by given scalar factor
 * Note : this will change To
 */
Line3D operator*(const Line3D &l, V3DNR s);

/**
 * @brief Move this line of given delta adding value either at From, To
 */
Line3D operator+(const Line3D &l, const Vector3D &delta);

/**
 * @brief Move this line of given delta subtracting value either at From, To
 */
Line3D operator-(const Line3D &l, const Vector3D &delta);

#endif