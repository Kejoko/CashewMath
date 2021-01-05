#ifndef CASHEW_LINEAR_SPECIALTYPES_H_INCLUDE
#define CASHEW_LINEAR_SPECIALTYPES_H_INCLUDE

#include "Cashew/Linear/Matrix.h"
#include "Cashew/Linear/Vector.h"

namespace Cashew {

    typedef Vector<double, 3> Vec3d;
    typedef Vector<double, 4> Vec4d;

    typedef Matrix<double, 3, 3> Mat3d;
    typedef Matrix<double, 4, 4> Mat4d;

    template<>
    double Vec3d::dot(const Vec3d& rhs) const {
        
        return 0;
    }

}

#endif // CASHEW_LINEAR_SPECIALTYPES_H_INCLUDE
