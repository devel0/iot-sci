#include <Arduino.h>
#include <unity.h>

#include <Vector3D.h>
#include <Transform3D.h>
#include <CoordinateSystem3D.h>
#include <Arc3D.h>
#include <Circle3D.h>
#include <Matrix3D.h>

#include <number-utils.h>

// torefact_Arc3DTest

void torefact_Arc3DTest_001()
{
    auto o = Vector3D(4.4249, 1.0332, -3.7054);
    auto cs_ = CoordinateSystem3D(o,
                                  Vector3D(-.1201, 4.4926, 1.4138),
                                  Vector3D(-1.6282, 3.2952, 2.1837));

    // build cs for arc with same cad representation
    auto csCAD = CoordinateSystem3D(o, cs_.BaseZ(), CoordinateSystem3D::CoordinateSystem3DAutoEnum::AAA);

    auto r = 4.2753;
    auto ang1 = ::ToRad(63.97731);
    auto ange2 = ::ToRad(26.10878);
    auto arc = Arc3D(1e-4, csCAD, r, ang1, ange2);
    auto c = Circle3D(arc);

    auto seg_i = Line3D(2.2826, 10.2516, -3.7469, 1.3767, -3.7709, 1.5019);
    auto ip_circ = c.Intersect(1e-4, seg_i, true, false);
    auto ip_arc = arc.Intersect(1e-2, seg_i);

    // segment intersecting arc
    TEST_ASSERT_TRUE(ip_circ.size() == 1);
    TEST_ASSERT_TRUE(ip_circ[0].EqualsTol(1e-4, ip_arc[0]));
    TEST_ASSERT_TRUE(ip_circ[0].EqualsTol(1e-2, 1.83, 3.24, -1.12));

    // segment not intersecting arc
    auto seg_i2 = seg_i.Scale(seg_i.From, .3);
    TEST_ASSERT_TRUE(c.Intersect(1e-4, seg_i2, true, true).size() == 0);
    TEST_ASSERT_TRUE(arc.Intersect(1e-4, seg_i2, true, true).size() == 0);

    // segment not intersecting, but line intersecting arc
    TEST_ASSERT_TRUE(c.Intersect(1e-4, seg_i2, true, false).size() == 1);
    TEST_ASSERT_TRUE(c.Intersect(1e-4, seg_i2, true, false)[0].EqualsTol(1e-4, ip_arc[0]));

    // segment intresecting circle, but not arc
    auto seg_e = Line3D(2.4523, 9.6971, -1.8004, 4.6142, -.0631, -2.0519);
    TEST_ASSERT_TRUE(c.Intersect(1e-4, seg_e, true, false).size() == 1);
    TEST_ASSERT_TRUE(c.Intersect(1e-4, seg_e, true, false)[0].EqualsTol(1e-2, 3.53, 4.82, -1.93));
    TEST_ASSERT_TRUE(arc.Intersect(1e-4, seg_e).size() == 0);

    // Geometry
    auto vertexes = arc.Vertexes();
    TEST_ASSERT_TRUE(vertexes.size() == 2);
    {
        bool found = false;
        for (int i = 0; i < vertexes.size(); ++i)
        {
            if (vertexes[0].EqualsTol(1e-3, arc.From()))
            {
                found = true;
                break;
            }
        }
        TEST_ASSERT_TRUE(found);
    }
    {
        bool found = false;
        for (int i = 0; i < vertexes.size(); ++i)
        {
            if (vertexes[1].EqualsTol(1e-3, arc.To()))
            {
                found = true;
                break;
            }
        }
        TEST_ASSERT_TRUE(found);
    }

    // PtAngle and mid
    auto midpoint = arc.MidPoint();
    TEST_ASSERT_TRUE(arc.PtAtAngle(arc.AngleStart() + arc.Angle() / 2).EqualsTol(1e-3, midpoint));

    // segment
    TEST_ASSERT_TRUE(arc.Segment().EqualsTol(1e-3, Line3D(arc.From(), arc.To())));

    // arc equals
    TEST_ASSERT_TRUE(arc.EqualsTol(1e-3, Arc3D(1e-3, arc.From(), arc.MidPoint(), arc.To())));

    TEST_ASSERT_TRUE(arc.EqualsTol(1e-3, Arc3D(1e-3, arc.CS(), arc.Radius(), arc.AngleStart(), arc.AngleEnd())));
    TEST_ASSERT_FALSE(arc.EqualsTol(1e-3, Arc3D(1e-3, arc.CS(), arc.Radius() / 2, arc.AngleStart(), arc.AngleEnd())));
    TEST_ASSERT_FALSE(arc.EqualsTol(1e-3, Arc3D(1e-3, arc.CS().Move(Vector3D(1, 0, 0)),
                                                arc.Radius(), arc.AngleStart(), arc.AngleEnd())));
    TEST_ASSERT_FALSE(arc.EqualsTol(1e-3, Arc3D(1e-3, arc.CS(), arc.Radius(), arc.AngleStart() + 1, arc.AngleEnd() + 1)));

    // arc bulge
    TEST_ASSERT_TRUE(::EqualsTol(1e-3, arc.Bulge(1e-3, arc.From(), arc.To(), arc.CS().BaseZ()), V3DTAN(arc.Angle() / 4)));
    TEST_ASSERT_TRUE(::EqualsTol(1e-3, arc.Bulge(1e-3, arc.From(), arc.To(), -arc.CS().BaseZ()), -V3DTAN(arc.Angle() / 4)));

    // arc contains
    TEST_ASSERT_FALSE(arc.Contains(1e-3, Vector3D(3.084, 3.965, -1.843), false)); // out arc shape - in plane
    TEST_ASSERT_FALSE(arc.Contains(1e-3, Vector3D(2.821, 4.417, -2.795), false)); // out of plane

    TEST_ASSERT_TRUE(arc.Contains(1e-3, Vector3D(5.446, 3.708, -3.677), false));  // arc shape - in plane
    TEST_ASSERT_FALSE(arc.Contains(1e-3, Vector3D(5.142, 3.774, -4.713), false)); // out of plane
}

void torefact_Arc3DTest_002()
{
    auto p1 = Vector3D(20.175, 178.425, -56.314);
    auto p2 = Vector3D(1.799, 231.586, -18.134);
    auto p3 = Vector3D(262.377, 302.118, 132.195);

    auto c = Arc3D::CircleBy3Points(p1, p2, p3);
    auto cs = c.cs;

    // verify points contained in arc plane
    TEST_ASSERT_TRUE(cs.Contains(1e-3, p1));
    TEST_ASSERT_TRUE(cs.Contains(1e-3, p2));
    TEST_ASSERT_TRUE(cs.Contains(1e-3, p3));

    // cscad retrieved from cad using ucs align entity
    auto cscad = CoordinateSystem3D(Vector3D(165.221, 214.095, 24.351),
                                    Vector3D(-0.259, -0.621, 0.74),
                                    CoordinateSystem3D::CoordinateSystem3DAutoEnum::AAA);

    // assert cs and cscad are coplanar with same origin
    TEST_ASSERT_TRUE(cscad.Origin().EqualsTol(1e-3, cs.Origin()));
    TEST_ASSERT_TRUE(::EqualsTol(1e-3, (cscad.BaseX() + cs.Origin()).ToUCS(cs).Z, 0));
    TEST_ASSERT_TRUE(::EqualsTol(1e-3, (cscad.BaseY() + cs.Origin()).ToUCS(cs).Z, 0));

    TEST_ASSERT_TRUE(::EqualsTol(1e-3, c.radius, 169.758));

    // create a circle through p1,p2,p3 and states if the same as arc by 3 points
    auto c2 = Circle3D(1e-3, p1, p2, p3);
    TEST_ASSERT_TRUE(::EqualsTol(1e-3, c.radius, c2.Radius()));
    TEST_ASSERT_TRUE(c.cs.Origin().EqualsTol(1e-3, c2.CS().Origin()));
    TEST_ASSERT_TRUE(c.cs.IsParallelTo(1e-3, c2.CS()));
}

void torefact_Arc3DTest_003()
{
    auto p1 = Vector3D(20.175, 178.425, -56.314);
    auto p2 = Vector3D(1.799, 231.586, -18.134);
    auto p3 = Vector3D(262.377, 302.118, 132.195);

    auto c = Arc3D::CircleBy3Points(p1, p2, p3);
    auto cs = c.cs;

    auto arc = Arc3D(1e-3, p1, p2, p3, -cs.BaseZ());
    auto arcCs = arc.CS();

    // two cs share same origin
    TEST_ASSERT_TRUE(arc.CS().Origin().EqualsTol(1e-3, cs.Origin()));
    // two cs with discordant colinear Z
    TEST_ASSERT_TRUE(arc.CS().BaseZ().Colinear(1e-3, cs.BaseZ()) && !arc.CS().BaseZ().Concordant(1e-3, cs.BaseZ()));
    // two cs parallel
    TEST_ASSERT_TRUE(arc.CS().IsParallelTo(1e-3, cs));
}

void torefact_Arc3DTest_005()
{
    auto p1 = Vector3D(20.17459383, 178.42487311, -56.31435851);
    auto p2 = Vector3D(1.7990927, 231.58612295, -18.13420814);
    auto p3 = Vector3D(262.37695212, 302.11773752, 132.19450446);

    auto c = Arc3D(1e-3, p1, p2, p3);
    TEST_ASSERT_TRUE(Line3D(c.Center(), c.CS().BaseX(), Line3D::Line3DConstructMode::PointAndVector)
                         .SemiLineContainsPoint(1e-3, p1));
    auto radTol = ::RadTol(1e-1, c.Radius());
    auto degTol = ::ToDeg(radTol);
    {
        auto cinverse = Arc3D(1e-3, p3, p2, p1);
        TEST_ASSERT_TRUE(Line3D(c.Center(), cinverse.CS().BaseX(), Line3D::Line3DConstructMode::PointAndVector)
                             .SemiLineContainsPoint(1e-3, p3));
        TEST_ASSERT_TRUE(::EqualsTol(radTol, c.AngleStart(), cinverse.AngleStart()));
        TEST_ASSERT_TRUE(::EqualsTol(radTol, c.AngleEnd(), cinverse.AngleEnd()));
    }

    TEST_ASSERT_TRUE(::EqualsTol(degTol, ::ToDeg(c.AngleStart()), 0));
    TEST_ASSERT_TRUE(::EqualsTol(degTol, ::ToDeg(c.AngleEnd()), 154.14));

    TEST_ASSERT_TRUE(c.Contains(1e-3, p1, true));
    TEST_ASSERT_TRUE(c.Contains(1e-3, p2, true));
    TEST_ASSERT_TRUE(c.Contains(1e-3, p3, true));

    auto moveVector = Vector3D(-1998.843, -6050.954, -1980.059);
    auto cmoved = c.Move(1e-3, moveVector);

    auto p1moved = p1 + moveVector;
    auto p2moved = p2 + moveVector;
    auto p3moved = p3 + moveVector;

    TEST_ASSERT_TRUE(cmoved.Contains(1e-3, p1moved, true));
    TEST_ASSERT_TRUE(cmoved.Contains(1e-3, p2moved, true));
    TEST_ASSERT_TRUE(cmoved.Contains(1e-3, p3moved, true));

    TEST_ASSERT_TRUE(::EqualsTol(degTol, ::ToDeg(c.Angle()), 154.14));

    auto c2 = Arc3D(1e-3, c.CS(), c.Radius(), c.AngleEnd(), c.AngleStart());

    TEST_ASSERT_TRUE(::EqualsTol(degTol, ::ToDeg(c2.Angle()), 360.0 - 154.14));

    TEST_ASSERT_TRUE(::EqualsTol(1e-3, c.Length(), 456.67959116));
}

void torefact_Arc3DTest_007()
{
    auto tol = 1e-7;

    auto p1 = Vector3D(20.17459383, 178.42487311, -56.31435851);
    auto p2 = Vector3D(1.7990927, 231.58612295, -18.13420814);
    auto p3 = Vector3D(262.37695212, 302.11773752, 132.19450446);
    auto arc = Arc3D(tol, p1, p2, p3);

    auto cso = Vector3D(-153.32147396, 128.44203407, -156.2065643);
    auto csv1 = Line3D(cso, Vector3D(71.66072643, 278.03911571, -156.2065643));
    auto csv2 = Line3D(cso, Vector3D(-153.32147396, 128.44203407, 2.05865164));

    TEST_ASSERT_TRUE(arc.Intersect(1e-6, arc.CS().Move(arc.CS().BaseZ() * 1000)).size() == 0);

    auto csplane = CoordinateSystem3D(cso, csv1.V, csv2.V);
    auto ipts = arc.Intersect(tol, csplane);
    TEST_ASSERT_TRUE(ipts.size() == 2);
    auto ipLine = Line3D(ipts[0], ipts[1]);
    {
        auto found = false;
        for (int i = 0; i < ipts.size(); ++i)
        {
            if (ipts[i].EqualsTol(tol, Vector3D(1.7990927, 231.58612296, -18.13420814)))
            {
                found = true;
                break;
            }
        }
        TEST_ASSERT_TRUE(found);
    }
    {
        auto found = false;
        for (int i = 0; i < ipts.size(); ++i)
        {
            if (ipts[i].EqualsTol(tol, Vector3D(169.80266871, 343.29649219, 134.36668758)))
            {
                found = true;
                break;
            }
        }
        TEST_ASSERT_TRUE(found);
    }
}


void Circle3DTest_001()
{
    auto tol = 1e-7;

    auto c1 = Circle3D(tol, CoordinateSystem3D::WCS(), 102);

    auto c2 = c1;

    TEST_ASSERT_TRUE(c1.EqualsTol(tol, c2));
    TEST_ASSERT_FALSE(&c1 == &c2);
}

// torefact_CoordinateSystem3DTest

void torefact_CoordinateSystem3DTest_001()
{
    auto cs1cad = CoordinateSystem3D(Vector3D(-1, 77, .75),
                                     Vector3D(0, 0, 1),
                                     Vector3D(.619, -.785, 0),
                                     Vector3D(.785, .619, 0));

    auto rotationAxis = Line3D(Vector3D(.111, .652, 0), Vector3D::ZAxis(), Line3D::Line3DConstructMode::PointAndVector);

    auto cs2 = cs1cad.Rotate(rotationAxis, ::ToRad(74.1566195));
    auto cs2cad = CoordinateSystem3D(Vector3D(-73.639, 20.427, .75),
                                     Vector3D(0, 0, 1),
                                     Vector3D(.924, .381, 0),
                                     Vector3D(-.381, .924, 0));

    TEST_ASSERT_TRUE(cs2.Equals(1e-3, cs2cad));
}

void torefact_CoordinateSystem3DTest_002()
{
    auto p = Vector3D(53.0147, 34.5182, 20.1);

    auto o = Vector3D(15.3106, 22.97, 0);
    auto v1 = Vector3D(10.3859, 3.3294, 30);
    auto v2 = Vector3D(2.3515, 14.101, 0);

    auto cs = CoordinateSystem3D(o, v1, v2);

    auto u = p.ToUCS(cs);
    TEST_ASSERT_TRUE(u.EqualsTol(1e-4, 32.3623, 12.6875, -27.3984));
    TEST_ASSERT_TRUE(u.ToWCS(cs).EqualsTol(1e-4, p));

    TEST_ASSERT_TRUE(p.ToUCS(cs).EqualsTol(1e-4, cs.ToUCS(p)));
    TEST_ASSERT_TRUE(cs.ToWCS(u).EqualsTol(1e-4, u.ToWCS(cs)));
}

void torefact_CoordinateSystem3DTest_003()
{
    auto cs1cad = CoordinateSystem3D(Vector3D(-1, 77, .75),
                                     Vector3D(0, 0, 1),
                                     Vector3D(.619, -.785, 0),
                                     Vector3D(.785, .619, 0));

    auto cs2cad = CoordinateSystem3D(Vector3D(-20.74, 55.485, 0),
                                     Vector3D(0, 0, 1),
                                     Vector3D(.619, -.785, 0),
                                     Vector3D(.785, .619, 0));

    auto delta = Vector3D(-19.74, -21.515, -0.75);
    TEST_ASSERT_TRUE(cs1cad.Move(delta).Equals(1e-3, cs2cad));
}

void torefact_CoordinateSystem3DTest_004()
{
    auto cs1cad = CoordinateSystem3D(Vector3D(-1, 77, .75),
                                     Vector3D(0, 0, 1),
                                     Vector3D(.619, -.785, 0),
                                     Vector3D(.785, .619, 0));

    auto cs2cad = CoordinateSystem3D(Vector3D(-1, 77, .75),
                                     Vector3D(-0.649, .409, .642),
                                     Vector3D(-.108, -.884, .454),
                                     Vector3D(.753, .225, .618));

    auto vaxis = Vector3D(-.311, -1.15, -.75);
    TEST_ASSERT_TRUE(cs1cad.Rotate(vaxis, ::ToRad(60)).Equals(1e-3, cs2cad));

    auto pt = Vector3D(-1.379, 76.762, 1.298);
    TEST_ASSERT_TRUE(cs2cad.Contains(1e-3, pt) && !cs1cad.Contains(1e-3, pt));
}

void torefact_CoordinateSystem3DTest_005()
{
    auto cs1o = Vector3D(-2.67223215, -94.22126913, -293.08306335);
    auto cs1x = Line3D(cs1o, Vector3D(-221.37919777, 144.86810067, -168.96320246));
    auto cs1y = Line3D(cs1o, Vector3D(192.45964896, 5.43267925, -141.20969062));
    auto cs1 = CoordinateSystem3D(cs1o, cs1x.V, cs1y.V);

    auto cs2o = Vector3D(-187.42845697, 128.44203407, 25.92565607);
    auto cs2x = Line3D(cs2o, Vector3D(-9.40307509, 246.81618785, 25.92565607));
    auto cs2y = Line3D(cs2o, Vector3D(-187.42845697, 128.44203407, 224.4413331));
    auto cs2 = CoordinateSystem3D(cs2o, cs2x.V, cs2y.V);

    auto i12Line = cs1.Intersect(1e-4, cs2).Value();
    auto i21Line = cs2.Intersect(1e-4, cs1).Value();

    TEST_ASSERT_TRUE(i12Line.LineContainsPoint(1e-4, i21Line.From));
    TEST_ASSERT_TRUE(i12Line.LineContainsPoint(1e-4, i21Line.To()));
    TEST_ASSERT_TRUE(i12Line.LineContainsPoint(1e-4, Vector3D(-187.42845697, 128.44203407, -170.87092273)));
    TEST_ASSERT_TRUE(i12Line.LineContainsPoint(1e-4, Vector3D(29.37373838, 272.59999706, 25.92565607)));
}

// torefact_Line3DTest

void torefact_Line3DTest_001()
{
    auto l = Line3D(Vector3D(1, 2, 3), Vector3D(4, 5, 6));
    TEST_ASSERT_TRUE(l.From.EqualsTol(1e-1, 1, 2, 3) && l.To().EqualsTol(1e-1, 4, 5, 6));
}

void torefact_Line3DTest_002()
{
    auto l = Line3D(Vector3D(1, 2, 3), Vector3D(4, 5, 6), Line3D::Line3DConstructMode::PointAndVector);
    TEST_ASSERT_TRUE(l.From.EqualsTol(1e-1, 1, 2, 3) && l.To().EqualsTol(1e-1, 1 + 4, 2 + 5, 3 + 6));
}

void torefact_Line3DTest_003()
{
    auto l = Line3D(1, 2, 3, 4);
    TEST_ASSERT_TRUE(l.From.EqualsTol(1e-1, 1, 2, 0) && l.To().EqualsTol(1e-1, 3, 4, 0));
}

void torefact_Line3DTest_004()
{
    auto l = Line3D(1, 2, 3, 4, 5, 6);
    TEST_ASSERT_TRUE(l.From.EqualsTol(1e-1, 1, 2, 3) && l.To().EqualsTol(1e-1, 4, 5, 6));
}

void torefact_Line3DTest_005()
{
    auto l = Line3D(1, 2, 3, 4, 5, 6);
    TEST_ASSERT_TRUE(l.EqualsTol(1e-1, Line3D(Vector3D(1, 2, 3), Vector3D(4, 5, 6))));
}

void torefact_Line3DTest_006()
{
    auto l = Line3D(1, 2, 3, 4, 5, 6);
    auto l2 = Line3D(4, 5, 6, 7, 8, 9);
    TEST_ASSERT_TRUE(l.CommonPoint(1e-1, l2).Value().EqualsTol(1e-1, 4, 5, 6));
    auto l3 = Line3D(4.11, 5.11, 6.11, 7.11, 8.11, 9.11);
    // common point test only from,to
    TEST_ASSERT_TRUE(!l.CommonPoint(1e-1, l3).HasValue());
}

void torefact_Line3DTest_007()
{
    auto l = Line3D(1, 2, 3, 4, 5, 6);
    auto r = l.Reverse();
    TEST_ASSERT_TRUE(r.From.EqualsTol(1e-1, 4, 5, 6) && r.To().EqualsTol(1e-1, 1, 2, 3));
}

void torefact_Line3DTest_008()
{
    auto l = Line3D(1, 2, 3, 4, 5, 6);
    auto i = l.Inverted();
    TEST_ASSERT_TRUE(i.From.EqualsTol(1e-1, 1, 2, 3) && i.To().EqualsTol(1e-1, -2, -1, 0));
}

void torefact_Line3DTest_009()
{
    auto l = Line3D(
        Vector3D(16.423, 80.164, -18.989),
        Vector3D(218.367, 151.378, 63.243));

    auto p = Vector3D(119.015, 54.432, 5.66);
    auto l2 = l.Scale(p, .71);
    TEST_ASSERT_TRUE(l2.EqualsTol(1e-3, Line3D(
                                            Vector3D(46.175, 72.702, -11.841),
                                            Vector3D(189.555, 123.264, 46.544))));

    auto l4 = l.Scale(p, -1.5);
    TEST_ASSERT_TRUE(l4.EqualsTol(1e-3, Line3D(
                                            Vector3D(272.903, 15.834, 42.634),
                                            Vector3D(-30.013, -90.987, -80.715))));
}

void torefact_Line3DTest_LineContainsPointTest()
{
    auto l = Line3D(1.1885, -.6908, 1.0009, 3.0186, 7.0544, 4.4160);
    auto p = Vector3D(2.1035, 3.1818, 2.7085);
    TEST_ASSERT_TRUE(l.LineContainsPoint(1e-4, p.X, p.Y, p.Z));
    TEST_ASSERT_TRUE(l.LineContainsPoint(1e-4, p));

    // line contains point consider infinite line
    p = Vector3D(.2734, -4.5634, -.7066);
    TEST_ASSERT_TRUE(l.LineContainsPoint(1e-4, p.X, p.Y, p.Z));
    TEST_ASSERT_TRUE(l.LineContainsPoint(1e-4, p));
}

void torefact_Line3DTest_SegmentContainsPointTest()
{
    auto l = Line3D(1.1885, -.6908, 1.0009, 3.0186, 7.0544, 4.4160);
    auto p = Vector3D(2.1035, 3.1818, 2.7085);
    TEST_ASSERT_TRUE(l.SegmentContainsPoint(1e-4, p.X, p.Y, p.Z));
    TEST_ASSERT_TRUE(l.SegmentContainsPoint(1e-4, p));

    // line contains point consider infinite line
    p = Vector3D(.2734, -4.5634, -.7066);
    TEST_ASSERT_FALSE(l.SegmentContainsPoint(1e-4, p.X, p.Y, p.Z));
    TEST_ASSERT_FALSE(l.SegmentContainsPoint(1e-4, p));
}

void torefact_Line3DTest_IntersectTest()
{
    {
        auto l = Line3D(0, 0, 0, 10, 0, 0);
        auto l2 = Line3D(5, 1e-1, 0, 5, 1e-1, 10); // vertical line dst=1e-1

        // default intersection behavior : midpoint
        auto ip = l.Intersect(1e-1, l2).Value();
        TEST_ASSERT_TRUE(ip.EqualsTol(1e-2, l.Intersect(1e-1, l2, Line3D::LineIntersectBehavior::IntMidPoint).Value()));
        TEST_ASSERT_TRUE(ip.EqualsTol(1e-2, 5, 1e-1 / 2, 0));

        ip = l.Intersect(1e-1, l2, Line3D::LineIntersectBehavior::IntPointOnThis).Value();
        TEST_ASSERT_TRUE(ip.EqualsTol(1e-2, 5, 0, 0));

        ip = l.Intersect(1e-1, l2, Line3D::LineIntersectBehavior::IntPointOnOther).Value();
        TEST_ASSERT_TRUE(ip.EqualsTol(1e-2, 5, 1e-1, 0));

        TEST_ASSERT_TRUE(!l.Intersect(5e-2, l2).HasValue());
    }

    {
        auto l = Line3D(0, 0, 0, 10, 20, 30);

        // cs around l=cs.z
        auto cs = CoordinateSystem3D(l.From, l.V, CoordinateSystem3D::CoordinateSystem3DAutoEnum::AAA);

        // build a per line offsetted
        auto lperp_off = Line3D(l.MidPoint(), cs.BaseX(), Line3D::Line3DConstructMode::PointAndVector)
                             .Move(cs.BaseY() * 2e-1);

        auto ip = l.Intersect(2e-1, lperp_off).Value();
        TEST_ASSERT_TRUE(ip.EqualsTol(1e-4, 4.9641, 9.9283, 15.0598));

        TEST_ASSERT_TRUE(!l.Intersect(1e-1, lperp_off).HasValue());
    }
}

void torefact_Line3DTest_IntersectTest1()
{
    auto l1 = Line3D(0, 0, 0, 10, 0, 0);
    auto l2 = Line3D(5, -5, 0, 5, -10, 0);

    TEST_ASSERT_TRUE(!l1.Intersect(1e-1, l2, true, true).HasValue());
    TEST_ASSERT_TRUE(!l1.Intersect(1e-1, l2, false, true).HasValue());
    TEST_ASSERT_TRUE(l1.Intersect(1e-1, l2, true, false).Value().EqualsTol(1e-1, 5, 0, 0));
    TEST_ASSERT_TRUE(l1.Intersect(1e-1, l2, false, false).Value().EqualsTol(1e-1, 5, 0, 0));
}

void torefact_Line3DTest_IntersectTest2()
{
    auto l1 = Line3D(0, 0, 0, 10, 0, 0);
    auto l2 = Line3D(5, -5, 0, 5, -10, 0);

    TEST_ASSERT_TRUE(!l1.Intersect(1e-1, l2, true, true).HasValue());
    TEST_ASSERT_TRUE(!l1.Intersect(1e-1, l2, false, true).HasValue());
    TEST_ASSERT_TRUE(l1.Intersect(1e-1, l2, true, false).Value().EqualsTol(1e-1, 5, 0, 0));
    TEST_ASSERT_TRUE(l1.Intersect(1e-1, l2, false, false).Value().EqualsTol(1e-1, 5, 0, 0));
}

void torefact_Line3DTest_IntersectTest3()
{
    auto l1 = Line3D(3.4319, 6.0508, -4.7570, -0.4533, 1.3145, -1.4730);
    auto l2 = Line3D(3.4319, 6.0508, -4.7570, 10.3895, -.5522, 3.7099);
    auto pl = CoordinateSystem3D(l1.From, l1.V, l2.V);

    auto l3 = Line3D(1.3529, 5.5732, 0, 6.3351, .4489, -7.8931);

    auto q = l3.Intersect(1e-1, pl).Value();
    // intersect point of line w/plane is on the plane
    TEST_ASSERT_TRUE(::EqualsTol(1e-4, q.ToUCS(pl).Z, 0));
    TEST_ASSERT_TRUE(q.EqualsTol(1e-4, 3.0757, 3.8013, -2.7293));
}

void torefact_Line3DTest_PerpendicularTest()
{
    {
        auto l = Line3D(0, 0, 0, 10, 0, 0);
        auto p = Vector3D(5, 10, 0);
        auto lperp = l.Perpendicular(1e-1, p).Value();

        // perpendicular segment From equals to the given point
        TEST_ASSERT_TRUE(lperp.From.EqualsTol(1e-1, p));

        // perpendicular segment end to the line which is perpendicular
        TEST_ASSERT_TRUE(l.SegmentContainsPoint(1e-1, lperp.To()));

        // two seg are perpendicular
        TEST_ASSERT_TRUE(l.V.IsPerpendicular(lperp.V));
    }

    {
        auto l = Line3D(Vector3D(441.37, 689.699, -179.739), Vector3D(695.01, 759.599, 301.543));
        auto p = Vector3D(740.754, 286.803, 687.757);
        auto lPerp = l.Perpendicular(1e-2, p).Value();

        TEST_ASSERT_TRUE(l.LineContainsPoint(1e-2, l.Intersect(1e-2, lPerp).Value()));
        TEST_ASSERT_TRUE(l.V.IsPerpendicular(lPerp.V));
    }
}

void torefact_Line3DTest_SemiLineContainsPointTest()
{
    auto l = Line3D(0, 0, 0, 10, 10, 10);

    TEST_ASSERT_TRUE(l.SemiLineContainsPoint(1e-1, Vector3D(9, 9, 9)));
    TEST_ASSERT_FALSE(l.SemiLineContainsPoint(1e-1, Vector3D(-1, -1, -1)));
}

void torefact_Line3DTest_ColinearTest()
{
    auto l = Line3D(0, 0, 0, 10, 0, 0);
    auto l2 = Line3D(20, 0, 0, 30, 0, 0).Scale(Vector3D(20, 0, 0), 1e6);

    TEST_ASSERT_TRUE(l.Colinear(1e-1, l2));
    TEST_ASSERT_TRUE(l2.Colinear(1e-1, l));

    auto l3 = l.RotateAboutAxis(Line3D(0, 0, 0, 0, 0, 1), 1e-1);
    TEST_ASSERT_FALSE(l.Colinear(1e-1, l3));
    TEST_ASSERT_FALSE(l2.Colinear(1e-1, l3));
}

void torefact_Line3DTest_IsParallelToTest()
{
    auto l = Line3D(0, 0, 0, 10, 0, 0);

    TEST_ASSERT_TRUE(l.IsParallelTo(1e-4, CoordinateSystem3D::XY()));
    TEST_ASSERT_TRUE(l.IsParallelTo(1e-4, CoordinateSystem3D::XZ()));
    TEST_ASSERT_FALSE(l.IsParallelTo(1e-4, CoordinateSystem3D::YZ()));
}

void torefact_Line3DTest_RotateAboutAxisTest()
{
    auto l = Line3D(0, 0, 0, 10, 0, 0);
    auto axis = Line3D(3.6969, 2.5012, 0, 2.0024, 5.8572, 10);
    auto lrot = l.RotateAboutAxis(axis, ::ToRad(45.0));
    TEST_ASSERT_TRUE(lrot.EqualsTol(1e-4, Line3D(2.7475, -1.7326, 1.0470, 9.8923, 4.7402, -1.6091)));
}

void torefact_Line3DTest_SetLengthTest()
{
    auto l = Line3D(0, 0, 0, 10, 0, 0);
    auto l2 = l.SetLength(20);
    TEST_ASSERT_TRUE(l2.From.EqualsTol(1e-1, 0, 0, 0));
    TEST_ASSERT_TRUE(l2.To().EqualsTol(1e-1, 20, 0, 0));
}

void torefact_Line3DTest_MoveTest()
{
    auto l = Line3D(1, 2, 3, 10, 0, 0);
    auto delta = Vector3D(10, 20, 30);
    auto l2 = l.Move(delta);
    TEST_ASSERT_TRUE(l2.From.EqualsTol(1e-1, l.From + delta));
    TEST_ASSERT_TRUE(l2.V.EqualsTol(1e-1, l.V));
}

void torefact_Line3DTest_MoveMidpointTest()
{
    auto l = Line3D(0, 0, 0, 10, 0, 0);
    auto l2 = l.MoveMidpoint(Vector3D(0, 0, 0));
    TEST_ASSERT_TRUE(l2.From.EqualsTol(1e-1, -5, 0, 0));
    TEST_ASSERT_TRUE(l2.To().EqualsTol(1e-1, 5, 0, 0));
}

void torefact_Line3DTest_SplitTest()
{
    {
        auto l = Line3D(0, 0, 0, 10, 0, 0);
        auto ar = vector<Vector3D>({Vector3D(2, 0, 0), Vector3D(8, 0, 0)});
        auto segs = l.Split(1e-1, ar);
        TEST_ASSERT_TRUE(segs.size() == 3);
        TEST_ASSERT_TRUE(segs[0].EqualsTol(1e-1, Line3D(0, 0, 0, 2, 0, 0)));
        TEST_ASSERT_TRUE(segs[1].EqualsTol(1e-1, Line3D(2, 0, 0, 8, 0, 0)));
        TEST_ASSERT_TRUE(segs[segs.size() - 1].EqualsTol(1e-1, Line3D(8, 0, 0, 10, 0, 0)));
    }

    {
        auto l = Line3D(0, 0, 0, 10, 0, 0);
        auto ar = vector<Vector3D>({// external of extreme points skipped
                                    Vector3D(-1, 0, 0), Vector3D(0, 0, 0), Vector3D(10, 0, 0),
                                    Vector3D(2, 0, 0), Vector3D(8, 0, 0)});
        auto segs = l.Split(1e-1, ar);
        TEST_ASSERT_TRUE(segs.size() == 3);
        TEST_ASSERT_TRUE(segs[0].EqualsTol(1e-1, Line3D(0, 0, 0, 2, 0, 0)));
        TEST_ASSERT_TRUE(segs[1].EqualsTol(1e-1, Line3D(2, 0, 0, 8, 0, 0)));
        TEST_ASSERT_TRUE(segs[segs.size() - 1].EqualsTol(1e-1, Line3D(8, 0, 0, 10, 0, 0)));
    }

    {
        auto l = Line3D(0, 0, 0, 10, 0, 0);
        auto ar = vector<Vector3D>({Vector3D(8, 0, 0), Vector3D(2, 0, 0)});
        auto segs = l.Split(1e-1, ar);
        TEST_ASSERT_TRUE(segs.size() == 3);
        // splitted segments start from begin of line
        TEST_ASSERT_TRUE(segs[0].EqualsTol(1e-1, Line3D(0, 0, 0, 2, 0, 0)));
        TEST_ASSERT_TRUE(segs[1].EqualsTol(1e-1, Line3D(2, 0, 0, 8, 0, 0)));
        TEST_ASSERT_TRUE(segs[segs.size() - 1].EqualsTol(1e-1, Line3D(8, 0, 0, 10, 0, 0)));
    }
}

void torefact_Line3DTest_EnsureFromTest()
{
    auto l = Line3D(0, 0, 0, 10, 0, 0);

    auto l2 = l.EnsureFrom(1e-1, Vector3D(0, 0, 0));
    TEST_ASSERT_TRUE(l2.EqualsTol(1e-1, Line3D(0, 0, 0, 10, 0, 0)));

    // return reversed segment
    auto l3 = l.EnsureFrom(1e-1, Vector3D(10, 0, 0));
    TEST_ASSERT_TRUE(l3.EqualsTol(1e-1, Line3D(10, 0, 0, 0, 0, 0)));
}

void torefact_Line3DTest_NormalizedTest()
{
    auto l = Line3D(10, 20, 30, 40, 50, 60);
    auto ln = l.Normalized();
    TEST_ASSERT_TRUE(ln.From.EqualsTol(1e-6, 10, 20, 30));
    TEST_ASSERT_TRUE(ln.V.EqualsTol(1e-6, Vector3D(1, 1, 1).Normalized()));
}

V3DNR rad_tol = ::ToRad(1e-1);

void torefact_Line3DTest_BisectTest()
{
    {
        auto l1 = Line3D(-.2653, 6.7488, 1.4359, 1.8986, 3.1188, 1.0844);
        auto l2 = Line3D(1.8986, 3.1188, 1.0844, 8.1864, 2.4120, 1.7818);
        auto bisect = l1.Bisect(1e-4, l2).Value();

        // bisect segment from start from the intersection point of two lines
        auto ip = l1.CommonPoint(1e-4, l2).Value();
        TEST_ASSERT_TRUE(bisect.From.EqualsTol(1e-4, ip));

        auto l1_from_ip = l1.EnsureFrom(1e-4, ip);
        auto l2_from_ip = l2.EnsureFrom(1e-4, ip);

        // angle from bisect toward l1 equals angle from bisect toward l2
        auto bisect_ang_l1 = bisect.V.AngleRad(1e-4, l1_from_ip.V);
        auto bisect_ang_l2 = bisect.V.AngleRad(1e-4, l2_from_ip.V);
        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, bisect_ang_l1, bisect_ang_l2));
    }

    {
        auto l1 = Line3D(0, 0, 0, 10, 0, 0);
        auto l2 = Line3D(0, 0, 0, -5, 0, 0);
        {
            auto bisect = l1.Bisect(1e-4, l2);
            // two parallel lines not form a plane, then a fallback rotation axis must be given
            TEST_ASSERT_TRUE(!bisect.HasValue());
        }
        {
            // rotate right-hand Z+
            auto bisect = l1.Bisect(1e-4, l2, Vector3D::ZAxis()).Value();
            TEST_ASSERT_TRUE(bisect.EqualsTol(1e-4, Line3D(0, 0, 0, 0, 10, 0)));
        }
        {
            // rotate right-hand Z-
            auto bisect = l1.Bisect(1e-4, l2, -Vector3D::ZAxis()).Value();
            TEST_ASSERT_TRUE(bisect.EqualsTol(1e-4, Line3D(0, 0, 0, 0, -10, 0)));
        }
    }
}

void torefact_Line3DTest_LineOffseted()
{
    auto l = Line3D(Vector3D(441.37, 689.699, -179.739), Vector3D(695.01, 759.599, 301.543));
    auto p = Vector3D(740.754, 286.803, 687.757);

    auto off = 15.5;
    auto lOff = l.Offset(1e-2, p, off);

    TEST_ASSERT_TRUE(l.V.IsParallelTo(1e-2, lOff.V));

    auto dLO = l.From.Distance(1e-2, lOff);
    auto dOL = lOff.From.Distance(1e-2, l);
    TEST_ASSERT_TRUE(::EqualsTol(1e-2, dLO, dOL));
    TEST_ASSERT_TRUE(::EqualsTol(1e-2, dOL, off));
}

void torefact_old_Line3DTest()
{
    auto tolLen = 1e-4;

    // line contains point
    {
        auto tolLenExcess = tolLen + 1e-10;

        // line (0,0,0)-(1,0,0)
        auto l = Line3D(Vector3D::Zero(), Vector3D(1, 0, 0), Line3D::Line3DConstructMode::PointAndVector);
        TEST_ASSERT_TRUE(l.LineContainsPoint(tolLen, 2, 0, 0));
        TEST_ASSERT_FALSE(l.LineContainsPoint(tolLen, 2, 1, 0));
        TEST_ASSERT_FALSE(l.LineContainsPoint(tolLen, 2, 0, 1));

        TEST_ASSERT_TRUE(l.SegmentContainsPoint(tolLen, 1, 0, 0));
        TEST_ASSERT_TRUE(l.SegmentContainsPoint(tolLen, 0, 0, 0));
        TEST_ASSERT_FALSE(l.SegmentContainsPoint(tolLen, -tolLenExcess, 0, 0));

        TEST_ASSERT_TRUE(l.SegmentContainsPoint(tolLen, 0, tolLen, 0));
        TEST_ASSERT_FALSE(l.SegmentContainsPoint(tolLen, 0, tolLenExcess, 0));

        auto l2 = Line3D(Vector3D::Zero(), Vector3D(5, 0, 0), Line3D::Line3DConstructMode::PointAndVector);
        // point on line
        TEST_ASSERT_TRUE(l2.SegmentContainsPoint(.5, Vector3D(-.5, 0, 0)));
        TEST_ASSERT_FALSE(l2.SegmentContainsPoint(.5, Vector3D(-.5 - 1e-10, 0, 0)));
    }

    // line 3d intersection
    {
        auto l1 = Line3D(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
        auto l2 = Line3D(Vector3D(2, 0, 0), Vector3D(2, 0, 2));

        TEST_ASSERT_TRUE(l1.Intersect(tolLen, l2).Value().EqualsTol(tolLen, 2, 0, 0));
    }

    {
        auto l1 = Line3D(Vector3D(0, 0, 0), Vector3D(0, 1, 0));
        auto l2 = Line3D(Vector3D(0, 2, 0), Vector3D(2, 2, 0));

        TEST_ASSERT_TRUE(l1.Intersect(tolLen, l2).Value().EqualsTol(tolLen, 0, 2, 0));
    }

    {
        auto l1 = Line3D(Vector3D(0, 0, 0), Vector3D(0, 0, 1));
        auto l2 = Line3D(Vector3D(0, 0, 2), Vector3D(2, 0, 2));

        TEST_ASSERT_TRUE(l1.Intersect(tolLen, l2).Value().EqualsTol(tolLen, 0, 0, 2));
    }

    {
        auto l1 = Line3D(Vector3D(0, 0, 0), Vector3D(1.6206, 2, -1.4882));
        auto l2 = Line3D(Vector3D(1.2, .7, 2), Vector3D(.6338, .3917, .969));

        TEST_ASSERT_TRUE(l1.Intersect(tolLen, l2).Value().EqualsTol(tolLen, 0.0675, 0.0833, -0.062));
    }

    // project point on a line
    {
        auto p = Vector3D(1, 1, 0);
        auto perpLine = Line3D::XAxisLine().Perpendicular(tolLen, p).Value();
        TEST_ASSERT_TRUE(perpLine.From.EqualsTol(tolLen, p) && perpLine.To().EqualsTol(tolLen, 1, 0, 0));
    }

    // check two lines are colinear
    {
        TEST_ASSERT_TRUE(Line3D(Vector3D(0, 0, 0), Vector3D(1, 1, 1))
                             .Colinear(tolLen, Line3D(Vector3D(2, 2, 2), Vector3D(3, 3, 3))));

        TEST_ASSERT_FALSE(Line3D(Vector3D(0, 0, 0), Vector3D(1, 1, 1))
                              .Colinear(tolLen, Line3D(Vector3D(0, 0, 0), Vector3D(1, 1, 1.11))));

        {
            auto v1 = Vector3D::From2DCoords(vector<V3DNR>({22.646652351539, 13.9522716251755, 23.5544912108728, 15.1454145967669}));
            auto v2 = Vector3D::From2DCoords(vector<V3DNR>({32.1714356467077, 26.4617928826826, 23.5548859449172, 15.1451142433282}));
            auto s1 = Line3D(v1[0], v1[1]);
            auto s2 = Line3D(v2[0], v2[1]);
            TEST_ASSERT_TRUE(s1.Colinear(1e-3, s2) == s2.Colinear(1e-3, s1));
        }

        // TODO: merge colinear segments not implemented
    }
}

void torefact_old_Vector3DTest()
{
    auto tolLen = 1e-4;
    auto tolRad = 1e-3;

    // length
    TEST_ASSERT_TRUE(::EqualsTol(tolLen, Vector3D(1, 5.9, 4).Length(), 7.198));

    // normalized
    TEST_ASSERT_TRUE(Vector3D(1, 5.9, 4).Normalized().EqualsTol(
        NormalizedLengthTolerance,
        Vector3D(0.13893, 0.81968, 0.55572)));

    // distance
    TEST_ASSERT_TRUE(::EqualsTol(tolLen, Vector3D(1, 5.9, 4).Distance(Vector3D(3, 4.3, 1.03)), 3.9218));

    // dot product
    TEST_ASSERT_TRUE(::EqualsTol(tolLen, Vector3D(5, 1, 3).DotProduct(Vector3D(5, 4, 6)), 47));

    // cross product
    TEST_ASSERT_TRUE(Vector3D(2, 4, 12).CrossProduct(Vector3D(3, 6, 1)).EqualsTol(tolLen, Vector3D(-68, 34, 0)));

    // angle rad
    TEST_ASSERT_TRUE(::EqualsTol(tolRad, Vector3D(3.48412, 2.06577, 0).AngleRad(tolLen, Vector3D(1.4325, 2.70248, 0)), 0.548));

    TEST_ASSERT_TRUE(::EqualsTol(tolRad,
                                 Vector3D(.231334209442139, .143270492553711).AngleRad(NormalizedLengthTolerance, Vector3D(-.224979639053345, -.153055667877197)),
                                 ::ToRad(177.54306)));

    // angle rad
    TEST_ASSERT_TRUE(::EqualsTol(tolRad,
                                 Vector3D(3.48412, 2.06577, 0).AngleRad(tolLen, Vector3D(-3.48412, -2.066, 0)),
                                 PI));

    // angle contained
    TEST_ASSERT_TRUE(::AngleInRange(tolRad, ::ToRad(340), ::ToRad(330), ::ToRad(3)));
    TEST_ASSERT_TRUE(::AngleInRange(tolRad, ::ToRad(0), ::ToRad(330), ::ToRad(3)));

    // vector projection
    TEST_ASSERT_TRUE(Vector3D(101.546, 25.186, 1.3).Project(Vector3D(48.362, 46.564, 5)).EqualsTol(tolLen, Vector3D(64.9889, 62.5728, 6.719)));

    // vector vers
    TEST_ASSERT_TRUE(Vector3D(101.546, 25.186, 1.3).Concordant(tolLen, Vector3D(50.773, 12.593, .65)));
    TEST_ASSERT_FALSE(Vector3D(101.546, 25.186, 1.3).Concordant(tolLen, Vector3D(-50.773, -12.593, .65)));

    // angle toward
    TEST_ASSERT_TRUE(::EqualsTol(tolRad,
                                 Vector3D(120.317, 42.914, 0).AngleToward(tolLen, Vector3D(28.549, 63.771, 0), Vector3D::ZAxis()),
                                 0.80726));

    TEST_ASSERT_FALSE(::EqualsTol(tolRad,
                                  Vector3D(120.317, 42.914, 0).AngleToward(tolLen, Vector3D(28.549, 63.771, 0), -Vector3D::ZAxis()),
                                  0.80726));

    TEST_ASSERT_TRUE(::EqualsTol(tolRad,
                                 Vector3D(120.317, 42.914, 0).AngleToward(tolLen, Vector3D(28.549, 63.771, 0), -Vector3D::ZAxis()),
                                 2 * PI - 0.80726));

    TEST_ASSERT_TRUE(abs(
                         Vector3D(-6.95, -5.1725, 0).AngleToward(1e-6, Vector3D(6.95, 5.1725, 0), Vector3D(0, 0, 71.89775)) - PI) < 1e-6);

    // z-axis rotation
    TEST_ASSERT_TRUE(Vector3D(109.452, 38.712, 0).RotateAboutZAxis(::ToRad(50.0)).EqualsTol(tolLen, Vector3D(40.6992, 108.7286, 0)));

    // arbitrary axis rotation
    TEST_ASSERT_TRUE(Vector3D(747.5675, 259.8335, 0).RotateAboutAxis(Vector3D(123.151, 353.8977, 25.6), ::ToRad(50.0)).EqualsTol(tolLen, Vector3D(524.3462, 370.9603, -462.4069)));

    // rotate relative
    TEST_ASSERT_TRUE(
        Vector3D(69.1831, 157.1155, 300).RotateAs(tolLen, Vector3D(443.6913, 107.8843, 0), Vector3D(342.7154, 239.6307, 0)).EqualsTol(tolLen, Vector3D(7.3989, 171.5134, 300)));

    // vector parallel (1-d)
    TEST_ASSERT_TRUE(Vector3D(1, 0, 0).IsParallelTo(tolLen, Vector3D(-1, 0, 0)));
    TEST_ASSERT_TRUE(Vector3D(0, 1, 0).IsParallelTo(tolLen, Vector3D(0, -2, 0)));
    TEST_ASSERT_TRUE(Vector3D(0, 0, 1).IsParallelTo(tolLen, Vector3D(0, 0, -3)));

    // vector parallel (2-d)
    TEST_ASSERT_TRUE(Vector3D(1, 1, 0).IsParallelTo(tolLen, Vector3D(-2, -2, 0)));
    TEST_ASSERT_FALSE(Vector3D(1, 1, 0).IsParallelTo(tolLen, Vector3D(-2, 2, 0)));

    TEST_ASSERT_TRUE(Vector3D(1, 0, 1).IsParallelTo(tolLen, Vector3D(-2, 0, -2)));
    TEST_ASSERT_FALSE(Vector3D(1, 0, 1).IsParallelTo(tolLen, Vector3D(-2, 0, 2)));

    TEST_ASSERT_TRUE(Vector3D(0, 1, 1).IsParallelTo(tolLen, Vector3D(0, -2, -2)));
    TEST_ASSERT_FALSE(Vector3D(0, 1, 1).IsParallelTo(tolLen, Vector3D(0, -2, 2)));

    // vector parallel (3-d)
    TEST_ASSERT_TRUE(Vector3D(1, 1, 1).IsParallelTo(tolLen, Vector3D(-2, -2, -2)));
    TEST_ASSERT_TRUE(Vector3D(253.6625, 162.6347, 150).IsParallelTo(tolLen, Vector3D(380.4937, 243.952, 225)));

    // vector parallel ( tolerance checks )
    {
        // ensure mm tolerance 1e-1
        auto tmpTolLen = 1e-1;

        // Z component of first vector will be considered zero cause < 1e-1 model tolerance
        TEST_ASSERT_TRUE(Vector3D(10, 0, 0.05).IsParallelTo(tmpTolLen, Vector3D(-2, 0, 0)));

        // Z component of first vector will be considered not-zero cause > 1e-1 model tolerance
        TEST_ASSERT_FALSE(Vector3D(10, 0, 0.11).IsParallelTo(tmpTolLen, Vector3D(-2, 0, 0)));

        // X, Z components of first vector force internal usage of normalized tolerance 1e-4
        // cause the length of the shortest vector here is < 1.5 and may represents a normalized vector
        // or a result of such type of operation
        TEST_ASSERT_TRUE(Vector3D(0.09, 0, 0.09).IsParallelTo(tmpTolLen, Vector3D(-20, 0, -20)));
    }
}

void torefact_old_Vector3DTest2()
{
    // AngleRadTest
    {
        auto v1 = Vector3D(10, 0, 0);
        auto v2 = Vector3D(2, 5, 0);
        auto angv1v2 = v1.AngleRad(1e-4, v2);
        auto angv2v1 = v2.AngleRad(1e-4, v1);
        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, angv1v2, angv2v1));
        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, angv1v2, ::ToRad(68.2)));
    }

    // AngleTowardTest
    {
        auto v1 = Vector3D(10, 0, 0);
        auto v2 = Vector3D(2, 5, 0);

        auto angv1v2_zplus = v1.AngleToward(1e-4, v2, Vector3D::ZAxis());
        auto angv1v2_zminus = v1.AngleToward(1e-4, v2, -Vector3D::ZAxis());

        auto angv2v1_zplus = v2.AngleToward(1e-4, v1, Vector3D::ZAxis());
        auto angv2v1_zminus = v2.AngleToward(1e-4, v1, -Vector3D::ZAxis());

        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, angv1v2_zplus, angv2v1_zminus));
        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, angv1v2_zplus, ::ToRad(68.1)));

        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, angv2v1_zplus, angv1v2_zminus));
        TEST_ASSERT_TRUE(::EqualsTol(rad_tol, angv2v1_zplus, ::ToRad(291.8)));
    }

    // AxisTest
    {
        auto xaxis = Vector3D::Axis(0);
        TEST_ASSERT_TRUE(xaxis.EqualsTol(1e-6, Vector3D::XAxis()));

        auto yaxis = Vector3D::Axis(1);
        TEST_ASSERT_TRUE(yaxis.EqualsTol(1e-6, Vector3D::YAxis()));

        auto zaxis = Vector3D::Axis(2);
        TEST_ASSERT_TRUE(zaxis.EqualsTol(1e-6, Vector3D::ZAxis()));
    }

    // BBoxTest TODO: not impl

    // ColinearTest
    {
        auto v = Vector3D(1, 2, 3);
        auto v2 = v.ScaleAbout(Vector3D::Zero(), 2);
        TEST_ASSERT_TRUE(v.Colinear(1e-6, v2));
        auto v3 = v2.RotateAboutZAxis(rad_tol);
        TEST_ASSERT_FALSE(v.Colinear(1e-6, v3));
    }

    // ConcordantTest
    {
        auto v = Vector3D(1, 2, 3);
        auto v2 = v.ScaleAbout(Vector3D::Zero(), 2);
        auto v3 = v.ScaleAbout(Vector3D::Zero(), .5);
        auto v4 = v.ScaleAbout(Vector3D::Zero(), -.5);
        TEST_ASSERT_TRUE(v.Concordant(1e-6, v2));
        TEST_ASSERT_TRUE(v.Concordant(1e-6, v3));
        TEST_ASSERT_FALSE(v.Concordant(1e-6, v4));
    }

    // CrossProductTest
    {
        auto a = Vector3D(1, 2, 3);
        auto b = Vector3D(4, 5, 6);
        auto c = a.CrossProduct(b);
        TEST_ASSERT_TRUE(c.Normalized().EqualsTol(1e-6, Vector3D(-4.0825, 8.1650, -4.0825).Normalized()));
    }

    // DistanceTest
    {
        auto a = Vector3D(1, 2, 3);
        auto b = Vector3D(4, 5, 6);
        TEST_ASSERT_TRUE(::EqualsTol(1e-4, a.Distance(b), 5.1962));
    }

    // DivideTest : TODO: not implemented geom

    // DotProductTest
    {
        auto a = Vector3D(1, 2, 3);
        auto b = Vector3D(4, 5, 6);
        auto d = a.DotProduct(b);
        TEST_ASSERT_TRUE(::EqualsTol(1e-6, d, a.X * b.X + a.Y * b.Y + a.Z * b.Z));
    }

    // EqualsTol1Test
    {
        auto v1 = Vector3D(1, 2, 3);
        auto v2 = Vector3D(1.1, 2.1, 3.1);
        TEST_ASSERT_TRUE(v1.EqualsTol(.11, v2));
        TEST_ASSERT_FALSE(v1.EqualsTol(.09, v2));
    }

    // EqualsTol2Test
    {
        auto v1 = Vector3D(1, 2, 3);
        auto v2 = Vector3D(1.1, 2.1, 3.1);
        TEST_ASSERT_TRUE(v1.EqualsTol(.11, 1.1, 2.1, 3.1));
        TEST_ASSERT_FALSE(v1.EqualsTol(.09, 1.1, 2.1, 3.1));
    }

    // EqualsTol3Test
    {
        auto v1 = Vector3D(1, 2, 3);
        auto v2 = Vector3D(1.1, 2.1, 40);
        // test only x, y
        TEST_ASSERT_TRUE(v1.EqualsTol(.11, 1.1, 2.1));
        TEST_ASSERT_FALSE(v1.EqualsTol(.09, 1.1, 2.1));
    }

    // From2DCoordsTest
    {
        auto v = Vector3D::From2DCoords({1, 2, 3, 4, 5, 6});
        TEST_ASSERT_TRUE(v.size() == 3);
        TEST_ASSERT_TRUE(v[0].EqualsTol(1e-6, 1, 2, 0));
        TEST_ASSERT_TRUE(v[1].EqualsTol(1e-6, 3, 4, 0));
        TEST_ASSERT_TRUE(v[2].EqualsTol(1e-6, 5, 6, 0));
    }

    // From3DCoordsTest
    {
        auto v = Vector3D::From3DCoords({1, 2, 3, 4, 5, 6});
        TEST_ASSERT_TRUE(v.size() == 2);
        TEST_ASSERT_TRUE(v[0].EqualsTol(1e-6, 1, 2, 3));
        TEST_ASSERT_TRUE(v[1].EqualsTol(1e-6, 4, 5, 6));
    }

    // GetOrdTest
    {
        auto v = Vector3D(1, 2, 3);
        TEST_ASSERT_TRUE(::EqualsTol(1e-6, v.GetOrd(0), 1));
        TEST_ASSERT_TRUE(::EqualsTol(1e-6, v.GetOrd(1), 2));
        TEST_ASSERT_TRUE(::EqualsTol(1e-6, v.GetOrd(2), 3));
    }

    // IsParallelTest
    {
        auto v1 = Vector3D(2.5101, 1.7754, -2.1324);
        auto v2 = Vector3D(9.0365, 6.3918, -7.6768);
        TEST_ASSERT_TRUE(v1.IsParallelTo(1e-4, v2));
    }

    // IsPerpendicularTest
    {
        auto v1 = Vector3D(2.5101, 1.7754, -2.1324);
        auto v2 = Vector3D(-9.7136, 8.0369, -4.7428);
        TEST_ASSERT_TRUE(v1.IsPerpendicular(v2));
    }

    // MirrorTest
    {
        auto v = Vector3D(1.5925, 1.5075, 3);
        auto v2 = v.Mirror(Line3D(-1.5317, 1.9230, 1.5482, 3.1248, -0.9249, -1.9787));
        TEST_ASSERT_TRUE(v2.EqualsTol(1e-4, -2.316, .9075, -1.6758));
    }

    // NormalizedTest
    {
        auto v = Vector3D(-1, 2, 4.5);
        auto vn = v.Normalized();
        auto l = v.Length();
        TEST_ASSERT_TRUE(vn.EqualsTol(1e-6, v.X / l, v.Y / l, v.Z / l));
    }

    // ProjectTest
    {
        auto cs = CoordinateSystem3D(
            Vector3D(6.1776, -6.3366, -5.7131),  // o
            Vector3D(-2.8849, -7.6108, -1.8691), // v1
            Vector3D(-11.7294, 5.4484, 6.7873)); // v2

        auto v = Vector3D(1, 2, 3);
        auto vp = v.Project(cs);
        TEST_ASSERT_TRUE(vp.EqualsTol(1e-4, -.0151, 3.0158, .4304));
    }

    // Project2Test
    {
        auto v = Vector3D(1.5925, 1.5075, 3);
        auto v2 = v.Project(Line3D(-1.5317, 1.9230, 1.5482, 3.1248, -0.9249, -1.9787));
        // v2 is endpoint of perp line from v to projection line
        TEST_ASSERT_TRUE(v2.EqualsTol(1e-4, -.3617, 1.2075, .6621));
    }

    // Project3Test
    {
        auto v = Vector3D(1, 2, 3);
        auto v2 = Vector3D(4.5106, 1.8377, 0);
        auto vp = v.Project(v2);

        TEST_ASSERT_TRUE(v2.Colinear(1e-4, vp));
        TEST_ASSERT_TRUE(vp.EqualsTol(1e-4, 1.5565, .6341, 0));
    }

    // RelTest
    {
        auto v = Vector3D(1, 2, 3);
        TEST_ASSERT_TRUE(v.Rel(Vector3D(1, 2, 3)).EqualsTol(1e-4, Vector3D::Zero()));
        TEST_ASSERT_TRUE(v.Rel(Vector3D(-1, -2, -3)).EqualsTol(1e-4, 2, 4, 6));
    }

    // RotateAboutAxis1Test
    {
        auto v = Vector3D(1, 2, 3);
        auto vr = v.RotateAboutAxis(Line3D(6.1270, .9867, 2.3383, 5.2912, 5.8866, 1.3096), ::ToRad(16.5));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1.4394, 2.3514, 4.3169));
    }

    // RotateAboutAxis2Test
    {
        auto v = Vector3D(1, 2, 3);
        auto vr = v.RotateAboutAxis(Vector3D(2.4786, 1.9027, 3), ::ToRad(16.5));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1.0228, 1.6906, 3.1774));
    }

    // RotateAboutXAxisTest
    {
        auto v = Vector3D(1, 2, 3);
        auto vr = v.RotateAboutXAxis(::ToRad(16.5));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1, 1.0656, 3.4445));
    }

    // RotateAboutYAxisTest
    {
        auto v = Vector3D(1, 2, 3);
        auto vr = v.RotateAboutYAxis(::ToRad(16.5));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1.8109, 2, 2.5924));
    }

    // RotateAboutZAxisTest
    {
        auto v = Vector3D(1, 2, 3);
        auto vr = v.RotateAboutZAxis(::ToRad(16.5));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, .3908, 2.2017, 3));
    }

    // RotateAsTest
    {
        auto v = Vector3D(1, 2, 3);
        auto vr = v.RotateAs(1e-4, Vector3D(3.0258, 2.9241, 1), Vector3D(5.561, 2.304, 2));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1.4938, 1.146, 3.2335));
        vr = v.RotateAs(1e-4, Vector3D(3.0258, 2.9241, 1), Vector3D(5.561, 2.304, 2), 1.5);
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1.6205, .6586, 3.3076));
        vr = v.RotateAs(1e-4, Vector3D(3.0258, 2.9241, 1), Vector3D(5.561, 2.304, 2), 1.5, ::ToRad(11.2));
        TEST_ASSERT_TRUE(vr.EqualsTol(1e-4, 1.6602, 0.126, 3.3508));
    }

    // ScalarTest
    {
        auto v = Vector3D(1, 2, 3);
        auto s = Vector3D(1.1, 2.2, 3.3);
        auto vs = v.Scalar(s.X, s.Y, s.Z);
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, v.X * s.X, v.Y * s.Y, v.Z * s.Z));
    }

    // ScaleAbout1Test
    {
        auto v = Vector3D(1, 2, 3);
        auto vs = v.ScaleAbout(Vector3D(3.1899, 1.3738, 1), 2.2);
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, -1.6279, 2.7514, 5.4));
    }

    // ScaleAbout2Test
    {
        auto v = Vector3D(1, 2, 3);
        auto vs = v.ScaleAbout(Vector3D(3.1899, 1.3738, 1), Vector3D(1.1, 2.2, 3.3));
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, .781, 2.7514, 7.6));
    }

    // SetTest
    {
        auto v = Vector3D(1, 2, 3);
        auto vv = v.Set(0, 1.1);
        TEST_ASSERT_TRUE(vv.EqualsTol(1e-4, 1.1, v.Y, v.Z));
        vv = v.Set(1, 2.2);
        TEST_ASSERT_TRUE(vv.EqualsTol(1e-4, v.X, 2.2, v.Z));
        vv = v.Set(2, 3.3);
        TEST_ASSERT_TRUE(vv.EqualsTol(1e-4, v.X, v.Y, 3.3));
    }

    // ToString1Test
    {
        auto v = Vector3D(1.1234, 2.2345, 3.3456);
        auto vs = v.ToString();
        TEST_ASSERT_TRUE(vs == "(1.123, 2.235, 3.346)");
    }

    // ToString2Test
    {
        auto v = Vector3D(1.1234, 2.2345, 3.3456);
        auto vs = v.ToString(4);
        TEST_ASSERT_TRUE(vs == "(1.1234, 2.2345, 3.3456)");
    }

    // ToString3Test
    {
        auto v = Vector3D(1.1234, 2.2345, 3.3456);
        auto vs = v.ToString(1e-2);
        TEST_ASSERT_TRUE(vs == "(1.12, 2.23, 3.35)");
    }

    // ToUCSTest
    {
        auto v = Vector3D(1, 2, 3);
        auto cs = CoordinateSystem3D(
            Vector3D(1.8129, 1.8060, .2726),  // origin
            Vector3D(1.8404, 2.0375, 1.3964), // v1
            Vector3D(2.8872, .2899, 1.3186)); // v2
        auto v_ = v.ToUCS(cs);
        TEST_ASSERT_TRUE(v_.EqualsTol(1e-4, .8791, -.4619, -2.6742));
    }

    // ToWCSTest
    {
        auto v_ = Vector3D(.8791, -.4619, -2.6742);
        auto cs = CoordinateSystem3D(
            Vector3D(1.8129, 1.8060, .2726),  // origin
            Vector3D(1.8404, 2.0375, 1.3964), // v1
            Vector3D(2.8872, .2899, 1.3186)); // v2
        auto v = v_.ToWCS(cs);
        TEST_ASSERT_TRUE(v.EqualsTol(1e-4, 1, 2, 3));
    }

    // Vector3D1Test
    {
        auto v = Vector3D();
        TEST_ASSERT_TRUE(v.EqualsTol(1e-4, Vector3D::Zero()));
    }

    // Vector3D2Test
    {
        auto v = Vector3D({1.2, 3.4});
        TEST_ASSERT_TRUE(v.EqualsTol(1e-4, 1.2, 3.4, 0));

        v = Vector3D({1.2, 3.4, 5.6});
        TEST_ASSERT_TRUE(v.EqualsTol(1e-4, 1.2, 3.4, 5.6));
    }

    // Vector3D3Test
    {
        auto v = Vector3D(1.2, 3.4);
        TEST_ASSERT_TRUE(v.EqualsTol(1e-4, 1.2, 3.4, 0));
    }

    // Vector3D4Test
    {
        auto v = Vector3D(1.2, 3.4, 5.6);
        TEST_ASSERT_TRUE(v.EqualsTol(1e-4, 1.2, 3.4, 5.6));
    }

    // OperatorSub1Test
    {
        auto v = Vector3D(1, 2, 3);
        auto iv = -v;
        TEST_ASSERT_TRUE(iv.EqualsTol(1e-4, -v.X, -v.Y, -v.Z));
    }

    // OperatorSub2Test
    {
        auto v1 = Vector3D(1, 2, 3);
        auto v2 = Vector3D(4, 5, 6);
        auto vd = v1 - v2;
        TEST_ASSERT_TRUE(vd.EqualsTol(1e-4, v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z));
    }

    // OperatorScalarMul1Test
    {
        auto v = Vector3D(1.2, 3.4, 5.6);
        auto s = 7.8;
        auto vs = s * v;
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, v.X * s, v.Y * s, v.Z * s));
    }

    // OperatorScalarMul2Test
    {
        auto v = Vector3D(1.2, 3.4, 5.6);
        auto s = 7.8;
        auto vs = v * s;
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, v.X * s, v.Y * s, v.Z * s));
    }

    // OperatorMulTest
    {
        auto v1 = Vector3D(1.2, 3.4, 5.6);
        auto v2 = Vector3D(7.8, 9.0, 1.2);
        auto vs = v1 * v2;
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, v1.X * v2.X, v1.Y * v2.Y, v1.Z * v2.Z));
    }

    // OperatorDivide2Test
    {
        auto v = Vector3D(1.2, 3.4, 5.6);
        auto s = 7.8;
        auto vs = v / s;
        TEST_ASSERT_TRUE(vs.EqualsTol(1e-4, v.X / s, v.Y / s, v.Z / s));
    }

    // OperatorSumTest
    {
        auto v1 = Vector3D(1.2, 3.4, 5.6);
        auto v2 = Vector3D(7.8, 9.0, 1.2);
        auto vs1 = v1 + v2;
        auto vs2 = v2 + v1;
        TEST_ASSERT_TRUE(vs1.EqualsTol(1e-4, vs2));
        TEST_ASSERT_TRUE(vs1.EqualsTol(1e-4, v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z));
    }

    // Vector3D_Test001
    {
        auto tol = 1e-8;

        auto v1 = Vector3D(4.11641325, 266.06066703, 11.60392802);
        auto v2 = Vector3D(4.11641325, 266.06066703, 11.60392802);

        TEST_ASSERT_TRUE(v1.EqualsTol(tol, v2));

        auto v3 = Vector3D(-4.11641325, -266.06066703, -11.60392802);
        TEST_ASSERT_TRUE((-1 * v3).EqualsTol(tol, v1));
    }
}

void torefact_old_Matrix3DTest()
{
    auto m = Matrix3D({1, .5, 6,
                       .1, 2, .05,
                       .7, 11, .55});

    // det
    TEST_ASSERT_TRUE(::EqualsTol(1e-6, m.Determinant(), -1.260));

    // inv
    TEST_ASSERT_TRUE(m.Inverse().EqualsTol(1e-3, Matrix3D({-0.437, -52.163, 9.504,
                                                           0.016, 2.897, -0.437,
                                                           0.238, 8.452, -1.548})));

    // solve
    TEST_ASSERT_TRUE(m.Solve(1.1, 2.2, 3.3).EqualsTol(1e-3, Vector3D(-83.875, 4.95, 13.75)));
}

void torefact_old_Circle3DTest()
{
    auto tol = 1e-4;

    {
        auto circle = Circle3D(tol,
                               Vector3D(52.563, 177.463, 0),
                               Vector3D(180.94, 258.505, 0),
                               Vector3D(297.124, 112.916, 50));

        TEST_ASSERT_TRUE(::EqualsTol(tol, circle.Radius(), 129.6516));
        TEST_ASSERT_TRUE(::EqualsTol(tol, circle.Area(), 52808.7467));
        TEST_ASSERT_TRUE(circle.Center().EqualsTol(tol, 170.9181, 132.1797, 27.4052));
        TEST_ASSERT_TRUE(circle.CS().BaseX().EqualsTol(1e-4, -0.9128, 0.3492, -0.2113));
        TEST_ASSERT_TRUE(circle.CS().BaseY().EqualsTol(1e-4, 0.3837, 0.9107, -0.1526));
    }

    {
        tol = 4e-4;

        auto center = Vector3D(22.51209044, 14.12016062, 6.80146259);
        auto N = Vector3D(3.42020143, 2.43210347, -9.07673371);
        auto c = Circle3D(tol, CoordinateSystem3D(center, N), 6.39114677);

        auto ltangent = Line3D(
            Vector3D(12.87708949, 20.20572433, 4.80152252),
            Vector3D(30.90622113, 20.43217568, 11.65575191));
        auto lcoplanar = Line3D(
            Vector3D(13.64224068, 16.47774921, 4.09093100),
            Vector3D(30.67186845, 16.07799217, 10.40074559));
        auto l1point = Line3D(
            Vector3D(3.39057372, 13.97172849, -2.64691872),
            Vector3D(29.98782817, 12.34242299, 11.34548562));
        auto lout = Line3D(
            Vector3D(12.61618025, 9.11647552, 5.03700782),
            Vector3D(29.98782817, 8.95992883, 10.43914904));

        auto ips = c.Intersect(tol, ltangent, true, false);
        TEST_ASSERT_TRUE(ips.size() == 1 && ips[0].EqualsTol(tol, 21.89165531, 20.31895000, 8.22863722));

        ips = c.Intersect(tol, lcoplanar, true, false);
        auto found1 = false;
        auto found2 = false;
        for (auto p : ips)
        {
            if (p.EqualsTol(tol, 16.75040000, 16.40478763, 5.24256563))
                found1 = true;
            else if (p.EqualsTol(tol, 27.98738426, 16.14100832, 9.40609100))
                found2 = true;
        }
        TEST_ASSERT_TRUE(found1 && found2);

        ips = c.Intersect(tol, l1point, true, false);
        TEST_ASSERT_TRUE(ips.size() == 1 && ips[0].EqualsTol(tol, 16.68920095, 13.15707574, 4.34928345));

        ips = c.Intersect(tol, lout, true, false);
        TEST_ASSERT_TRUE(ips.size() == 0);
    }

    {
        tol = 1e-3;
        auto p = Vector3D(3.29679008, 9.48216033, 0);
        auto t = Line3D(Vector3D(18.14266304, 4.72460258, 0), Vector3D(1.29059103, 1.80128397, 0));
        auto r = 9.8191;

        auto circles = Circle3D::CircleRTanP(tol, p, t, r);

        TEST_ASSERT_TRUE(circles.size() == 2);
        auto found1 = false;
        auto found2 = false;
        for (auto c : circles)
        {
            TEST_ASSERT_TRUE(::EqualsTol(tol, c.Radius(), 9.81913052));
            if (c.Center().EqualsTol(tol, 12.18378030, 13.65597387))
                found1 = true;
            else if (c.Center().EqualsTol(tol, -6.47673267, 10.41894611))
                found2 = true;
        }
        TEST_ASSERT_TRUE(found1);
        TEST_ASSERT_TRUE(found2);
    }
}

//

void test_vector3d_normalized()
{
    auto tol = 1e-2;

    auto vx = -1.1;
    auto vy = 2.7;
    auto vz = 0.09;
    auto v = Vector3D(vx, vy, vz);

    auto l = v.Length();

    TEST_ASSERT_TRUE(v.Normalized().EqualsTol(tol, vx / l, vy / l, vz / l));
}

void test_vector3d_distance()
{
    auto tol = 1e-8;

    auto v1 = Vector3D(64.34945471, 108.89733154, -34.78875667);
    auto v2 = Vector3D(260.87876324, 240.36185984, 107.99814397);

    TEST_ASSERT_TRUE(::EqualsTol(tol, v1.Distance(v2), 276.215116));
}

void test_transform3d()
{
    auto tol = 1e-8;

    // red
    auto v1 = Vector3D(-91.65821493, 164.31850795, 69.55900266);

    // identity ( red )
    auto t = Transform3D();
    TEST_ASSERT_TRUE(t.Apply(v1).EqualsTol(tol, v1));

    // add rotate about zaxis ( green ) and compute from original v1
    t.RotateAboutZAxis(ToRad(12.1));
    auto v2 = t.Apply(v1);
    TEST_ASSERT_TRUE(v2.EqualsTol(tol, Vector3D(-124.06607557, 141.45461927, 69.55900266)));

    // add rotate about xaxis ( cyan ) and compute from original v1
    t.RotateAboutXAxis(ToRad(30.111));
    auto v3 = t.Apply(v1);
    TEST_ASSERT_TRUE(v3.EqualsTol(tol, Vector3D(-124.06607557, 87.46990325, 131.13687578)));

    // add rotate about yaxis ( magenta ) and compute from original v1
    t.RotateAboutYAxis(ToRad(-40.12));
    auto v4 = t.Apply(v1);
    TEST_ASSERT_TRUE(v4.EqualsTol(tol, Vector3D(-179.3762652, 87.46990325, 20.33289892)));

    // add rotate about arbitrary (1,2,3) axis (blue) and compute from original v1
    auto myaxis = Vector3D(10, 20, 30);
    t.RotateAboutAxis(myaxis, ToRad(55.3));
    auto v5 = t.Apply(v1);
    TEST_ASSERT_TRUE(v5.EqualsTol(tol, Vector3D(-149.09823237, -69.43406135, 114.84286438)));
}

void test_coordinate_system3d()
{
    auto p = Vector3D(53.0147, 34.5182, 20.1);

    auto o = Vector3D(15.3106, 22.97, 0);
    auto v1 = Vector3D(10.3859, 3.3294, 30);
    auto v2 = Vector3D(2.3515, 14.101, 0);

    auto cs = CoordinateSystem3D(o, v1, v2);

    auto u = p.ToUCS(cs);
    TEST_ASSERT_TRUE(u.EqualsTol(1e-4, 32.3623, 12.6875, -27.3984));
    TEST_ASSERT_TRUE(u.ToWCS(cs).EqualsTol(1e-4, p));

    TEST_ASSERT_TRUE(p.ToUCS(cs).EqualsTol(1e-4, cs.ToUCS(p)));
    TEST_ASSERT_TRUE(cs.ToWCS(u).EqualsTol(1e-4, u.ToWCS(cs)));
}

void test_arc3d_0001()
{
    auto tol = 1e-7;

    auto p1 = Vector3D(13.87329226, 134.93466652, -3.70729037);
    auto p2 = Vector3D(75.89230418, 224.11406806, 35.97437873);
    auto p3 = Vector3D(97.48181688, 229.31008314, 16.9314998);

    auto arc = Arc3D::Arc3DBy3Points(tol, p1, p2, p3);

    auto plo = Vector3D(-74.96786784, 178.50832685, -43.45380285);
    auto plx = Vector3D(61.65932598, 313.82398026, -33.75931542);
    auto ply = Vector3D(87.35160811, 8.94741958, 35.66234059);

    auto plcs = CoordinateSystem3D(plo, plx - plo, ply - plo);

    auto iSegmentPts = arc.Intersect(tol, plcs, false);

    auto i1 = iSegmentPts[0];
    auto i2 = iSegmentPts[1];
    auto iSegment = Line3D(i1, i2);

    TEST_ASSERT_TRUE(plcs.Contains(tol, i1));
    TEST_ASSERT_TRUE(plcs.Contains(tol, i2));

    TEST_ASSERT_TRUE(arc.Contains(tol, i1, false));
    TEST_ASSERT_TRUE(arc.Contains(tol, i2, false));

    TEST_ASSERT_TRUE(i1.EqualsTol(tol, Vector3D(40.09735573, 156.48945821, -7.46179105)));
    TEST_ASSERT_TRUE(i2.EqualsTol(tol, Vector3D(72.20796391, 188.29182351 - 5.18335819)));
}

void test_circle3d_0001()
{
    // 2 pts
    {
        auto tol = 1e-4;

        auto c1 = Circle3D(tol,
                           Vector3D(12652.2, -847.9),
                           Vector3D(12527.2, -722.9),
                           Vector3D(12402.2, -847.9));

        auto c2 = Circle3D(tol,
                           Vector3D(13357.5, 112.1),
                           Vector3D(12397.5, 1072.1),
                           Vector3D(11437.5, 112.1));

        auto qInt = c1.Intersect(tol, c2);

        TEST_ASSERT_TRUE(qInt.size() == 2);
        TEST_ASSERT_TRUE(qInt[1].EqualsTol(tol, 12402.20000052949, -847.888494720131, 0));
        TEST_ASSERT_TRUE(qInt[0].EqualsTol(tol, 12647.715463548095, -814.7183326852199, 0));
    }

    // 1 pt
    {
        auto tol = 1e-4;

        auto c1 = Circle3D(
            tol,
            CoordinateSystem3D::WCS().Move(Vector3D(12397.5233, 112.1186)),
            960);

        auto c2 = Circle3D(
            tol,
            CoordinateSystem3D::WCS().Move(Vector3D(13535.4631, -465.6793)),
            316.22776602);

        auto qInt = c1.Intersect(tol, c2);

        TEST_ASSERT_TRUE(qInt.size() == 1);
        TEST_ASSERT_TRUE(qInt[0].EqualsTol(tol, 13253.500741174445, -322.5106905459212, 0));
    }

    // 0 pt
    {
        auto tol = 1e-4;

        auto c1 = Circle3D(
            tol,
            CoordinateSystem3D::WCS().Move(Vector3D(12397.5233, 112.1186)),
            960);

        auto c2 = Circle3D(
            tol,
            CoordinateSystem3D::WCS().Move(Vector3D(13535.4631 + 1, -465.6793)),
            316.22776602);

        auto qInt = c1.Intersect(tol, c2);

        TEST_ASSERT_TRUE(qInt.size() == 0);
    }

    //
    {
        auto c = Circle3D(1e-3,
                          CoordinateSystem3D::WCS().Move(
                              Vector3D(250.21546070748141, -926.81833345210805)),
                          125).Move(1e-3, Vector3D::Zero());

        auto l = Line3D(
            Vector3D(0, -960), Vector3D(1, 0, 0),
            Line3D::Line3DConstructMode::PointAndVector);

        auto q = c.Intersect(1e-3, l);

        TEST_ASSERT_TRUE(q.size() == 2);
        TEST_ASSERT_TRUE(q[0].EqualsTol(1e-3, 370.731, -960, 0));
        TEST_ASSERT_TRUE(q[1].EqualsTol(1e-3, 129.7, -960, 0));
    }
}

void setup()
{
    UNITY_BEGIN();

    RUN_TEST(torefact_Arc3DTest_001);
    RUN_TEST(torefact_Arc3DTest_002);
    RUN_TEST(torefact_Arc3DTest_003);
    RUN_TEST(torefact_Arc3DTest_005);
    RUN_TEST(torefact_Arc3DTest_007);

    RUN_TEST(Circle3DTest_001);

    RUN_TEST(torefact_CoordinateSystem3DTest_001);
    RUN_TEST(torefact_CoordinateSystem3DTest_002);
    RUN_TEST(torefact_CoordinateSystem3DTest_003);
    RUN_TEST(torefact_CoordinateSystem3DTest_004);
    RUN_TEST(torefact_CoordinateSystem3DTest_005);

    RUN_TEST(torefact_Line3DTest_001);
    RUN_TEST(torefact_Line3DTest_002);
    RUN_TEST(torefact_Line3DTest_003);
    RUN_TEST(torefact_Line3DTest_004);
    RUN_TEST(torefact_Line3DTest_005);
    RUN_TEST(torefact_Line3DTest_006);
    RUN_TEST(torefact_Line3DTest_007);
    RUN_TEST(torefact_Line3DTest_008);
    RUN_TEST(torefact_Line3DTest_009);
    RUN_TEST(torefact_Line3DTest_LineContainsPointTest);
    RUN_TEST(torefact_Line3DTest_SegmentContainsPointTest);
    RUN_TEST(torefact_Line3DTest_IntersectTest);
    RUN_TEST(torefact_Line3DTest_IntersectTest1);
    RUN_TEST(torefact_Line3DTest_IntersectTest2);
    RUN_TEST(torefact_Line3DTest_IntersectTest3);
    RUN_TEST(torefact_Line3DTest_PerpendicularTest);
    RUN_TEST(torefact_Line3DTest_SemiLineContainsPointTest);
    RUN_TEST(torefact_Line3DTest_ColinearTest);
    RUN_TEST(torefact_Line3DTest_IsParallelToTest);
    RUN_TEST(torefact_Line3DTest_RotateAboutAxisTest);
    RUN_TEST(torefact_Line3DTest_SetLengthTest);
    RUN_TEST(torefact_Line3DTest_MoveTest);
    RUN_TEST(torefact_Line3DTest_MoveMidpointTest);
    RUN_TEST(torefact_Line3DTest_SplitTest);
    RUN_TEST(torefact_Line3DTest_EnsureFromTest);
    RUN_TEST(torefact_Line3DTest_NormalizedTest);
    RUN_TEST(torefact_Line3DTest_BisectTest);
    RUN_TEST(torefact_Line3DTest_LineOffseted);
    RUN_TEST(torefact_old_Line3DTest);
    RUN_TEST(torefact_old_Vector3DTest);
    RUN_TEST(torefact_old_Vector3DTest2);
    RUN_TEST(torefact_old_Matrix3DTest);
    RUN_TEST(torefact_old_Circle3DTest);

    RUN_TEST(test_vector3d_normalized);
    RUN_TEST(test_vector3d_distance);
    RUN_TEST(test_transform3d);
    RUN_TEST(test_coordinate_system3d);
    RUN_TEST(test_circle3d_0001);
    //RUN_TEST(test_arc3d_0001);

    UNITY_END();

    while (1)
        ;
}

void loop()
{
}
