//
// Created by yin_feng on 2022/8/18.
//
#include <iostream>
#include "random.h"

using namespace alg;
using std::cout;
using std::move;

int main() {
    for (int i = 0; i < 100; ++i) {
        cout << random::uniform() << ' ';
    }
    cout << '\n';
    return 0;
}