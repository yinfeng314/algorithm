//
// Created by yin_feng on 2022/8/15.
//

#ifndef ALGORITHM_RANDOM_H
#define ALGORITHM_RANDOM_H

#include <random>
#include "vector.h"

namespace alg {
    class random {
    public:
        static int uniform(int lo = 1, int hi = 100) {
            std::random_device rd;
            std::default_random_engine generator(rd());
            std::uniform_int_distribution<int> distribution(lo, hi);
            return distribution(generator);
        }
    };
}
#endif //ALGORITHM_RANDOM_H
