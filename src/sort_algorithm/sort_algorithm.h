//
// Created by yin_feng on 2022/8/7.
//

#ifndef ALGORITHM_SORT_ALGORITHM_H
#define ALGORITHM_SORT_ALGORITHM_H

#include "vector.h"


namespace alg {
    template<typename Comparable>
    class Sort {    // 排序算法
    public:
        // 选择排序：从小到大查找元素，将其从头到尾进行排序
        // 时间复杂度：O(n^2)
        static void selection(vector<Comparable> &a) {
            int N = a.size();
            for (int i = 0; i < N; ++i) {
                int min = i;
                for (int j = i + 1; j < N; ++j) {
                    if (less(a[j], a[min])) min = j;
                }
                exch(a, i, min);
            }
        }

        // 基础函数
        static bool less(Comparable v, Comparable w) {    // 使用的类型必须重载<运算符
            return v < w;
        }

        static void exch(vector<Comparable> &a, int i, int j) {
            Comparable t = a[i];
            a[i] = a[j];
            a[j] = t;
        }

        static bool is_sorted(const vector<Comparable> &a) {
            for (int i = 0; i < a.size(); ++i) {
                if (less(a[i], a[i + 1]))return false;
            }
            return true;
        }
    };
}
#endif //ALGORITHM_SORT_ALGORITHM_H
