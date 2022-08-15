//
// Created by yin_feng on 2022/8/15.
//
#include <iostream>
#include "sort_algorithm.h"

using namespace alg;

int main(){
    vector<int> a = {1,2,-2};
    Sort<int>::selection(a);
    std::cout << a;
    return 0;
}