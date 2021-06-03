#include "Transform3D.h"

Transform3D::Transform3D() : q(Quaternion::Identity)
{
}

void Transform3D::RotateAboutXAxis(double angleRad)
{
    // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
    // q' = q2 * q1
    auto &q1 = q;
    auto q2 = Quaternion(Vector3D::XAxis(), angleRad);
    q = q2 * q1;
}

void Transform3D::RotateAboutYAxis(double angleRad)
{
    // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
    // q' = q2 * q1
    auto &q1 = q;
    auto q2 = Quaternion(Vector3D::YAxis(), angleRad);
    q = q2 * q1;
}

void Transform3D::RotateAboutZAxis(double angleRad)
{
    // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
    // q' = q2 * q1
    auto &q1 = q;
    auto q2 = Quaternion(Vector3D::ZAxis(), angleRad);
    q = q2 * q1;
}

void Transform3D::RotateAboutAxis(const Vector3D &axis, double angleRad)
{
    // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
    // q' = q2 * q1
    auto &q1 = q;
    auto q2 = Quaternion(axis, angleRad);
    q = q2 * q1;
}

Vector3D Transform3D::Apply(const Vector3D &v)
{
    // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
    // p' = qpq^(-1)
    auto q_1 = q.Conjugate();
    auto p = Quaternion(0, v);
    auto p_ = q * p * q_1;

    return p_.v;
}