//
// Created by yin_feng on 2022/8/7.
//

#ifndef ALGORITHM_SORT_ALGORITHM_H
#define ALGORITHM_SORT_ALGORITHM_H

#include "vector.h"
#include <vector>

namespace alg {
    template<typename Comparable>

    class Sort {    // 排序算法
    public:
        // 选择排序
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

        // 归并排序
        static void mergeUB(vector<Comparable> &a) {
            vector<Comparable> aux(a.size(), Comparable());
            mergeUB(aux, a, 0, a.size() - 1);
        }

        static void mergeUB(std::vector<Comparable> &a) {
            std::vector<Comparable> aux(a.size(), Comparable());
            mergeUB(aux, a, 0, a.size() - 1);
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

        static void mergeUB(std::vector<Comparable> &aux, std::vector<Comparable> &a, int lo, int hi) {
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
//               if (i > mid) a[k] = aux[j++];
//               else if (j > hi) a[k] = aux[i++];
//               else if (less(aux[i], aux[j])) a[k] = aux[i++];
//               else a[k] = aux[j++];
                if (i > mid || less(aux[j], aux[i]))
                    a[k] = aux[j++];
                else a[k] = aux[i++];
            }
        }

        static void mergeUB_base(std::vector<Comparable> &aux, std::vector<Comparable> &a, int lo, int mid, int hi) {
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; ++k) {    // 拷贝未排序的数组
                aux[k] = a[k];
            }
            for (int k = lo; k <= hi; ++k) {    // 将aux通过双指针回填到a中
//               if (i > mid) a[k] = aux[j++];
//               else if (j > hi) a[k] = aux[i++];
//               else if (less(aux[i], aux[j])) a[k] = aux[i++];
//               else a[k] = aux[j++];
                if (i <= mid && j <= hi){
                    a[k] = aux[(less(aux[i],aux[j])?(i++):(j++))];
                }else if (i > mid) a[k] = aux[j++];
                else a[k] = aux[i++];
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
