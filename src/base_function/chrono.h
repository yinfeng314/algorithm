//
// Created by yin_feng on 2022/8/15.
//

#ifndef ALGORITHM_CHRONO_H
#define ALGORITHM_CHRONO_H

#include <chrono>

using namespace std::chrono;

namespace alg {
    class time {
    public:
        template<typename Func>
        static auto count_time(Func func, int times = 0) {
            auto start = system_clock::now();
            for (int i = 0; i < times; ++i) {
                func();
            }
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            return "cost " +
                   std::to_string(double(duration.count()) * microseconds::period::num / microseconds::period::den) +
                   " seconds\n";
        }
    };
}

#endif //ALGORITHM_CHRONO_H
