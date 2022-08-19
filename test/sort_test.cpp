//
// Created by yin_feng on 2022/8/15.
//
#include <iostream>
#include "sort_algorithm.h"
#include "chrono.h"
#include "random.h"

using namespace alg;
using std::cout;
using std::endl;

int main() {
    const int len = 10000, times = 1;
    vector<int> v_down_up;
    vector<int> v_up_down;
    vector<int> v_random;
    vector<int> v;

    for (int i = 0; i < len; ++i) {
        v_down_up.push_back(i);
        v_up_down.push_back(len - i);
        v_random.push_back(random::uniform());
    }

    v = v_random;
    auto selection = [&]() {
        vector<int> a = v;
        sort<int>::selection(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "selection " << time::count_time(selection, times);

    auto insertion = [&]() {
        vector<int> a = v;
        sort<int>::insertion(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "insertion " << time::count_time(insertion, times);

    auto bubble = [&]() {
        vector<int> a = v;
        sort<int>::bubble(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "bubble    " << time::count_time(bubble, times);

    auto shell = [&]() {
        vector<int> a = v;
        sort<int>::shell(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "shell     " << time::count_time(shell, times);

    auto mergeUB = [&]() {
        vector<int> a = v;
        sort<int>::mergeUB(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "mergeUB   " << time::count_time(mergeUB, times);

    auto mergeBU = [&](){
        vector<int> a = v;
        sort<int>::mergeBU(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "mergeBU   " << time::count_time(mergeBU, times);

    auto quick = [&]() {
        vector<int> a = v;
        sort<int>::quick(a);
        cout << sort<int>::is_sorted(a) << ' ';
    };
    cout << "quick     "<< time::count_time(quick, times);
    return 0;
}