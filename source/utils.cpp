//
// Created by i0x0 on 6/30/24.
//

#include <switch.h>
#include "switch/kernel/random.h"
#include <cstdint>
#include <string>

extern "C" {
    uint32_t random32(){
        return (uint32_t)randomGet64();
    }
}

