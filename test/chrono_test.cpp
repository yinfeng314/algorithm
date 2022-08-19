//
// Created by yin_feng on 2022/8/18.
//
#include <iostream>
#include "chrono.h"

using std::cout;
using namespace alg;

int main() {
    auto p = [](int a = 0){
        for (int i = 0; i < 1000; ++i) {
            a++;
        }
    };
    cout << time::count_time(p,1000);
    return 0;
}