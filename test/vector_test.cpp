//
// Created by yin_feng on 2022/8/11.
//

#include "vector.h"
#include <iostream>

using namespace alg;
using std::cout;
using std::move;
using std::initializer_list;

int main() {
    // 构造函数测试
    vector<int> x1{10, 2};    // or use () but can't be =() for it's false and ={} for it will be initializer_list
    cout << x1;
    const vector<int> &x2 = x1;    // if x2 will not be change, use the const reference
    cout << x2;
    int tmp[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    vector<int> x3{tmp, 0, 5};    // or use () but can't be =() and ={}
    cout << x3;
    vector<int> x4{1, 2, 3, 4, 5};    // or use ={} but can't be () or =()
    cout << x4;
    vector<int> x5{move(x4)};   // now x4 is moved; or use (), =(), =, {}, ={}
    cout << x5;
    for (int i = 0; i < 10; ++i) {
        x5.push_back(i);
    }
    cout << x5;

    // 公有函数测试
    vector<int> b = {1,2,3};
    for (int i = 0; i < 100; ++i) {
        b.push_back(100-i);
    }
    cout << b;
}
