#include "Quaternion.h"

Quaternion::Quaternion(V3DNR s, const Vector3D &v)
{
    this->s = s;
    this->v = v;
}

Quaternion::Quaternion(const Vector3D &axis, V3DNR alphaRad)
{
    // general form of quaternion:
    // q = [s, v] = [cos(0.5 * alpha), sin(0.5 * alpha) * axis]
    s = V3DCOS(alphaRad / 2);
    v = V3DSIN(alphaRad / 2) * axis.Normalized();
}

const Quaternion &Quaternion::Identity = Quaternion(1, Vector3D::Zero());

Quaternion Quaternion::Conjugate() const
{
    return Quaternion(s, -v);
}

Quaternion operator*(Quaternion qa, Quaternion qb)
{
    return Quaternion(
        // sa * sb - va * vb
        qa.s * qb.s - qa.v.DotProduct(qb.v),
        // va x vb + sa * vb + sb * va
        qa.v.CrossProduct(qb.v) + qa.s * qb.v + qb.s * qa.v);
}