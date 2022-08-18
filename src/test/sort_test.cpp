//
// Created by yin_feng on 2022/8/15.
//
#include <iostream>
#include "sort_algorithm.h"

using namespace alg;
using std::cout;

int main() {
    vector<int> a = {1, 2, -2};
    Sort<int>::selection(a);
    cout << a;
    vector<int> b = {1, 2, -2};
    Sort<int>::insertion(b);
    cout << b;
    vector<int> c = {1, 2, -2, 9, 10};
    Sort<int>::bubble(c);
    cout << c;
    vector<int> d = {1, 2, -2, -10};
    Sort<int>::mergeUB(d);
    cout << d;
//    throw std::invalid_argument("");
//    throw std::bad_alloc();
    return 0;
}