#ifndef CASHEW_LINEAR_SPECIALTYPES_H_INCLUDE
#define CASHEW_LINEAR_SPECIALTYPES_H_INCLUDE

#include "Cashew/Linear/Matrix.h"
#include "Cashew/Linear/Vector.h"

#include "Cashew/Util/Sqrt.h"

namespace Cashew {

    typedef Vector<double, 3> Vec3d;
    typedef Vector<double, 4> Vec4d;

    typedef Matrix<double, 3, 3> Mat3d;
    typedef Matrix<double, 4, 4> Mat4d;

    template<>
    double Vec3d::normSquared() const {
        return mData[0] * mData[0] + mData[1] * mData[1] + mData[2] * mData[2];
    }

    template<>
    double Vec4d::normSquared() const {
        return mData[0] * mData[0] + mData[1] * mData[1] + mData[2] * mData[2] + mData[3] * mData[3];
    }

}

#endif // CASHEW_LINEAR_SPECIALTYPES_H_INCLUDE
