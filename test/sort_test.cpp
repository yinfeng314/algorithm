//
// Created by yin_feng on 2022/8/15.
//
#include <iostream>
#include "sort_algorithm.h"
#include "chrono.h"
#include "random.h"

using namespace alg;
using std::cout;

int main() {
    vector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(random::uniform(1, 1000));
    }

    auto selection = [&]() {
        vector<int> a = v;
        sort<int>::selection(a);
    };
    cout << time::count_time(selection, 100);

    auto insertion = [&]() {
        vector<int> a = v;
        sort<int>::insertion(a);
    };
    cout << time::count_time(insertion, 100);
    
    auto bubble = [&]() {
        vector<int> a = v;
        sort<int>::bubble(a);
    };
    cout << time::count_time(bubble, 100);

    auto shell = [&]() {
        vector<int> a = v;
        sort<int>::shell(a);
    };
    cout << time::count_time(shell, 100);

    auto merge = [&]() {
        vector<int> a = v;
        sort<int>::mergeUB(a);
    };
    cout << time::count_time(merge, 100);

    auto quick = [&]() {
        vector<int> a = v;
        sort<int>::quick(a);
    };
    cout << time::count_time(quick, 100);
    return 0;
}