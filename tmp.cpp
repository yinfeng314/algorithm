//
// Created by yin_feng on 2022/8/7.
//
#include "src/data_structure/vector.h"
#include <algorithm>
#include <iostream>

using namespace alg;

//void test() {
//    std::vector a = {1, 2, 3, 4};
//    auto sum = 0;
//    std::for_each(a.begin(), a.end(), [&](auto vi) { sum += vi; });
//    std::cout << sum << std::endl;
//}

struct Pig {
    int x;
    int y;

    // 无参构造函数
    explicit Pig(int init_x = 0, int init_y = 0) : x(init_x), y(init_y) {}

    // 拷贝构造函数
    Pig(const Pig &a) = default;

    // 移动构造函数
    Pig(const Pig &&a) noexcept: x(a.x), y(a.y) {}

    // 析构函数
    ~Pig() = default;

    // 拷贝赋值函数
    Pig &operator=(const Pig &pig) = default;

    // 移动赋值函数
    Pig &operator=(Pig &&pig) noexcept {
        x = pig.x;
        y = pig.y;
        return *this;
    }

    void print() const {
//        std::cout << x << " " << y << std::endl;
//        std::cout << std::endl;
    }
};

//template<typename Type>
//std::ostream &print(std::ostream &os, const Type &t) {
//    return os << t;
//}
//
//template<typename Type, typename ...Args>
//std::ostream &print(std::ostream &os, const Type &t, const Args &...args) {
//    os << t << ", ";
//    return print(os, args...);
//}

int main() {
//    test();
//    Pig pig;
//    pig.print();
//    Pig pig1(1,2);
//    pig1.print();
//    Pig pig2(pig1);
//    pig2.print();
//    Pig pig3(2, static_cast<int>(3.1f));
//    pig3.print();
//    Pig pig4{2,static_cast<int>(1.1)};
//    Pig pig5 = Pig{1,2};
//    int a[] = {1, 2, 3, 4};
////    [&](int x) { return x + 1; };
//    vector<int> v1;    // 默认构造函数
//    std::cout << v1;
//    vector<int> v2(a, 0, 3);    // 将数组转化成vector
//    std::cout << v2;
//    vector<int> v3{v2};    // 拷贝构造函数
//    std::cout << v3;
//    vector<int> v4{4, 0};    // 使用参数构造vector
//    std::cout << v4;
//    vector<int> v5 = vector<int>{a, 0, 3};
//    std::cout << v5;
//    v5.push_back(2);
//    std::cout << v5;
//    for (int i = 0; i < 100; ++i) {
//        v5.push_back(i);
//    }
//    std::cout << v5;
//    v5.push_back(vector<int>{10,0});
//    //    v5.push_back(vector<int>{a,0,1});
//    std::cout << v5;
//    for (int i = 0; i < 50; ++i) {
//        std::cout << v5.pop_back() << " ";
//    }

    vector<int> v = {1, 2, 3};
    v.insert(2,2);
    v.pop_back();
//    v.pop_back();
//    v.pop_back();
//    v.pop_back();
    v.pop_back();
    std::cout << v;

    return 0;
}
