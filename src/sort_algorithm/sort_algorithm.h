//
// Created by yin_feng on 2022/8/7.
//

#ifndef ALGORITHM_SORT_ALGORITHM_H
#define ALGORITHM_SORT_ALGORITHM_H

#include "vector.h"
#include <vector>

namespace alg {
    template<typename Comparable>
    class sort {    // 排序算法，构造函数默认调用快速排序，也可以指定其他排序算法
    public:
        // 构造函数调用快速排序
        explicit sort(vector<Comparable> &a, int index = 6) {
            switch (index) {
                case 1:
                    selection(a);
                case 2:
                    insertion(a);
                case 3:
                    bubble(a);
                case 4:
                    shell(a);
                case 5:
                    mergeUB(a);
                case 6:
                    quick(a);
                default:
                    break;
            }
        }

        // 重载为函数类
        void operator()(vector<Comparable> &a) {
            quick(a);
        }

        // 选择排序
        static void selection(vector<Comparable> &a) {
            if (is_sorted(a)) return;
            int N = a.size();
            for (int i = 0; i < N; ++i) {
                int min = i;
                for (int j = i + 1; j < N; ++j) {
                    if (less(a[j], a[min])) min = j;
                }
                exch(a, i, min);
            }
        }

        // 选择排序
        static void insertion(vector<Comparable> &a) {
            int N = a.size();
            for (int i = 1; i < N; ++i) {   // 从1开始遍历向量
                for (int j = i + 1; j > 0 && less(a[j], a[j - 1]); --j) {   // 当不满足顺序时进行交换
                    exch(a, j, j - 1);
                }
            }
        }

        // 冒泡排序
        static void bubble(vector<Comparable> &a) {
            int N = a.size();
            for (int i = 0; i < N; ++i) {    // 排序次数为N
                bool sorted = true;
                for (int j = 1; j < N - i; ++j) {
                    if (less(a[j], a[j - 1])) {
                        exch(a, j, j - 1);
                        sorted = false;
                    }
                }
                if (sorted) break;
            }
        }

        // 希尔排序
        static void shell(vector<Comparable> &a) {
            int N = a.size();
            int h = 1;
            while (h < N / 3) h = 3 * h + 1;    // 1, 4, 13, 40, ...
            while (h >= 1) {
                for (int i = 0; i < N; ++i) {
                    for (int j = i; j >= h && less(a[j], a[j - h]); j -= h) {
                        exch(a, j, j - h);
                    }
                    h /= 3;
                }
            }
        }

        // 归并排序
        static void mergeUB(vector<Comparable> &a) {
            vector<Comparable> aux(a.size(), Comparable());
            mergeUB(aux, a, 0, a.size() - 1);
        }

        static void mergeBU(vector<Comparable> &a) {
            int N = a.size();
            vector<Comparable> aux(N, Comparable());
            for (int sz = 1; sz < N; sz *= 2) {
                for (int lo = 0; lo < N - sz; lo += 2 * sz) {
                    mergeUB_base(aux, a, lo, lo + sz - 1, std::min(lo + 2 * sz - 1, N - 1));
                }
            }
        }

        // 快速排序
        static void quick(vector<Comparable> &a) {
            quick(a, 0, a.size() - 1);
        }

        static bool is_sorted(vector<Comparable> &a) {
            for (int i = 0; i < a.size(); ++i) {
                if (less(a[i], a[i + 1]))return false;
            }
            return true;
        }

    private:
        // 归并排序私有接口
        static void mergeUB(vector<Comparable> &aux, vector<Comparable> &a, int lo, int hi) {
            if (hi <= lo) return;
            int mid = lo + (hi - lo) / 2;
            mergeUB(aux, a, lo, mid);
            mergeUB(aux, a, mid + 1, hi);
            mergeUB_base(aux, a, lo, mid, hi);
        }

        // 原地归并
        static void mergeUB_base(vector<Comparable> &aux, vector<Comparable> &a, int lo, int mid, int hi) {
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; ++k) {    // 拷贝未排序的数组
                aux[k] = a[k];
            }
            for (int k = lo; k <= hi; ++k) {    // 将aux通过双指针回填到a中
                if (i <= mid && j <= hi)
                    a[k] = aux[(less(aux[i], aux[j])) ? i++ : j++];
                else if (i > mid) a[k] = aux[j++];
                else a[k] = aux[i++];
            }
        }

        // 快速排序私有接口
        static void quick(vector<Comparable> &a, int lo, int hi) {
            if (hi <= lo) return;
            int j = partition(a, lo, hi);
            quick(a, lo, j - 1);
            quick(a, j + 1, hi);
        }

        // 快速排序的切分
        static int partition(vector<Comparable> &a, int lo, int hi) {
            int i = lo, j = hi + 1;
            Comparable v = a[lo];
            while (true) {
                while (less(a[++i], v)) if (i == hi) break;
                while (less(v, a[--j])) if (j == lo) break;
                if (i >= j) break;
                exch(a, i, j);
            }
            exch(a, lo, j);
            return j;
        }

        // 基础函数
        static bool less(const Comparable v, const Comparable w) {    // 使用的类型必须重载<运算符
            return v < w;
        }

        static void exch(vector<Comparable> &a, int i, int j) {
            Comparable t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    };
}
#endif //ALGORITHM_SORT_ALGORITHM_H
