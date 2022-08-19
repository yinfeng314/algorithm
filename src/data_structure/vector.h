//
// Created by yin_feng on 2022/8/7.
//

#ifndef ALGORITHM_VECTOR_H
#define ALGORITHM_VECTOR_H

#include <ostream>
#include "base.h"

using std::ostream;
using std::initializer_list;

namespace alg {
    template<typename Item>
    class vector {    // RAII(Resource Acquisition Is Initialization)
    public:
        // -----------------------------  基础函数  -----------------------------
        explicit vector(size_t capacity = _const_capacity) :
                _item(new Item[capacity]), _size(0), _capacity(capacity) {}

        vector(const vector<Item> &other) :    // 拷贝构造函数
                _size(other._size), _capacity(other._capacity) {
            _item = new Item[_capacity];    // 当把这一步放在初始化列表中时会出错？
            for (int i = 0; i < other._size; ++i) {
                _item[i] = other._item[i];
            }
        }

        vector(vector<Item> &&other) noexcept: _size(other._size), _capacity(other._capacity), _item(other._item) {
            // 移动构造函数
            other._size = 0;
            other._capacity = 0;
            other._item = nullptr;
        }

        vector<Item> &operator=(const vector<Item> &other) {    // 拷贝赋值函数
            if (this == &other) return *this;
            _size = other._size;
            _capacity = other._capacity;
            delete[] _item;
            _item = new Item[_capacity];
            for (int i = 0; i < _size; ++i) {
                _item[i] = other._item[i];
            }
//            _item = (Comparable *) realloc(_item, _capacity * sizeof(Comparable));
//            memcpy(_item,other._item);
            return *this;
        }

        vector<Item> &operator=(vector<Item> &&other) noexcept {    // 移动赋值函数
            if (*this != &other) {
                _size = other._size;
                other._size = 0;
                _capacity = other._capacity;
                other._capacity = 0;
                delete[] _item;
                _item = other._item;
                other._item = nullptr;
            }
            return *this;
        }

        ~vector() {
            delete[] _item;
        }

        // -------------------------- 其他构造函数 ------------------------
        explicit vector(size_t size, const Item &item) : _size(size), _capacity(size + _const_capacity) {
            // 使用特定参数构造vector
            _item = new Item[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                _item[i] = item;
            }
        }

        vector(const Item *arr, int lo, int hi) : _size(0), _capacity(2 * (hi - lo)) {
            // 将内置数组转换成vector
            _item = new Item[_capacity];
            while (lo < hi) {
                _item[_size++] = arr[lo++];
            }
        }

        vector(initializer_list <Item> il) : _size(il.size()), _capacity(_size + _const_capacity) {
            _item = new Item[_capacity];
            size_t i = 0;
            for (auto item: il) {
                _item[i++] = item;
            }
        }

        // -------------------------- 迭代器实现 --------------------------

        // 公有函数接口
        Item &operator[](size_t index) {    // 访问
            return _item[index];
        }

        Item &at(size_t index) {    // 访问-可抛出异常
            if (index >= _size)
                throw std::out_of_range("Array subscript out of range");
            return _item[index];
        }

        friend ostream &operator<<(ostream &os, const vector<Item> &v) {    // 输出
            for (size_t i = 0; i < v._size; ++i) {
                os << v._item[i] << ' ';
            }
            os << '\n';
            return os;
        }

        size_t size() { return _size; }

        size_t capacity() { return _capacity; }

        bool empty() { return _size == 0; }

        void insert(size_t index, const Item &item) {    // 插入元素
            if (index >= _size) return;
            if (_size == _capacity) reserve(2 * _capacity);
            for (size_t i = _size; i > index; --i) {
                _item[i] = _item[i - 1];
            }
            _item[index] = item;
            _size++;
        }

        void push_back(const Item &item) {    // 将item插入尾部
            if (_size == _capacity) reserve(2 * _capacity);
            _item[_size++] = item;
        }

        void push_back(const vector<Item> &v) {    // 将vector插入尾部
            if (v._size == 0) return;
            if (_size + v._size >= _capacity) reserve(2 * (_capacity + v._capacity));
            for (size_t i = _size; i < _size + v._size; ++i) {
                _item[i] = v._item[i - _size];
            }
            _size = _size + v._size;
        }

        Item &pop_back() {    // 删除元素
            if (_size <= 0) throw std::out_of_range("");
            return _item[_size--];
        }

        size_t search(const Item &item) {    // 查找元素
            for (int i = 0; i < _size; ++i) {
                if (_item[i] == item) return i;
            }
            return _size;
        }

        void reserve(size_t capacity) {    // 改变vector长度
            if (_capacity >= capacity) return;
            _capacity = capacity;
//            Item* tmp = new Item[_capacity];
//            for (size_t i = 0; i < _size; ++i) {
//                tmp[i] = _item[i];
//            }
//            delete[] _item;
//            _item = tmp;
            Item *tmp = _item;
            _item = new Item[_capacity];
            for (int i = 0; i < _size; ++i) {
                _item[i] = tmp[i];
            }
            delete[] tmp;
        }

    private:
        const static size_t _const_capacity = 10;
        Item *_item;
        size_t _size;
        size_t _capacity;
        // 私有函数接口
    };
}
#endif //ALGORITHM_VECTOR_H
