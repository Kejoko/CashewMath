// Keegan Kochis
// 2020 December 27th

#ifndef CASHEW_GENERATOR_H_INCLUDE
#define CASHEW_GENERATOR_H_INCLUDE

#include <cstdint>

#include "Cashew/Util/uint128_t.h"

namespace Cashew {

class Generator {
  public:
    uint32_t lehmer32();
    uint64_t lehmer64(); // Needs 128 bit unsigned int for state and variables
    
  private:
    uint32_t mState;
};

}


#endif //CASHEW_GENERATOR_H_INCLUDE
