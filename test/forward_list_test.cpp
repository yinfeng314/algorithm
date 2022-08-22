//
// Created by yin_feng on 2022/8/20.
//
#include <iostream>
#include "forward_list.h"

using std::cout;
using namespace alg;

int main() {
    forward_list<int> a = {1,2,3,4,5};
//    for (int i = 0; i < 10; ++i) {
//        a.push_front(1);
//    }
//    cout << a;
//    for (int i = 0; i < 10; ++i) {
//        a.push_back(2);
//    }
//    cout << a;
//    for (int i = 0; i < 10; ++i) {
//        a.insert(i, i);
//    }
    cout << a;
    cout << a.search(10) << '\n';
    a.remove(a.search(10));
    cout << a << '\n';
    return 0;
}