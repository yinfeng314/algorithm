//
// Created by yin_feng on 2022/8/7.
//

#ifndef ALGORITHM_VECTOR_H
#define ALGORITHM_VECTOR_H

#include <ostream>

namespace alg {
    template<typename Item>
    class vector {    // RAII(Resource Acquisition Is Initialization)
    public:
        // -----------------------------  基础函数  -----------------------------
        explicit vector(size_t capacity = 0) : _item(nullptr), _size(0), _capacity(capacity) {}

        vector(const vector<Item> &other) :    // 拷贝构造函数
                _size(other._size), _capacity(other._capacity) {
            _item = new Item[_capacity];    // 当把这一步放在初始化列表中时会出错？
            for (int i = 0; i < other._size; ++i) {
                _item[i] = other._item[i];
            }
        }

        vector(vector<Item> &&other) noexcept: _size(other._size), _capacity(other._capacity) {
            // 移动构造函数
            _item = new Item[_capacity];
            for (int i = 0; i < _size; ++i) {
                _item[i] = other._item[i];
            }
            delete other;
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
//            _item = (Item *) realloc(_item, _capacity * sizeof(Item));
//            memcpy(_item,other._item);
            return *this;
        }

        vector<Item> &operator=(vector<Item> &&other) noexcept {    // 移动赋值函数
            _size = other._size;
            _capacity = other._capacity;
            std::move(_item, other._item);
            return *this;
        }

        ~vector() { delete[] _item; }

        // -------------------------- 其他构造函数 ------------------------
        explicit vector(size_t size, const Item &item) : _size(size), _capacity(size + kDefaultCapacity) {
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

        vector(std::initializer_list<Item> il) : _size(il.size()), _capacity(_size + kDefaultCapacity) {
            _item = new Item[_size];
            size_t i = 0;
            for (auto item: il) {
                _item[i++] = item;
            }
        }

        // -------------------------- 迭代器实现 --------------------------
        class iterator {

        };

        class OutOfRange{

        };

        // 公有函数接口
        Item &operator[](size_t index) {
            return _item[index];
        }

        friend std::ostream &operator<<(std::ostream &os, const vector<Item> &v) {
            for (size_t i = 0; i < v._size; ++i) {
                os << v._item[i] << ' ';
            }
            os << '\n';
            return os;
        }

        void push_back(const Item &item) {    // 将item插入尾部
            if (_size >= _capacity) resize(2 * _capacity);
            _item[_size++] = item;
        }

        void push_back(const vector<Item> &v) {    // 将vector插入尾部
            if (_size + v._size >= _capacity) resize(2 * (_capacity + v._capacity));
            for (size_t i = _size; i < _size + v._size; ++i) {
                _item[i] = v._item[i];
            }
            _size = _size + v._size;
        }

        void insert(size_t index, const Item &item) {    // 插入元素
            if (index >= _size) return;
            if (_size >= _capacity) resize(2 * _capacity);
            for (size_t i = _size; i > index; --i) {
                _item[i] = _item[i - 1];
            }
            _size++;
        }

        Item &pop_back() {    // 删除元素
            if (_size <= 0) throw OutOfRange();
            return _item[_size--];
        }

        size_t search(const Item &item) {    // 查找元素
            for (int i = 0; i < _size; ++i) {
                if (_item[i] == item) return i;
            }
            return _size;
        }

        void resize(size_t capacity) {    // 改变vector长度
            if (_capacity == capacity) return;
            Item *tmp = _item;
            _item = new Item[_capacity = capacity];
            for (size_t i = 0; i < _size; ++i) {
                _item[i] = tmp[i];
            }
            delete tmp;
        }

    private:
        const size_t kDefaultCapacity = 10;
        Item *_item;
        size_t _size;
        size_t _capacity;
        // 私有函数接口
    };
}
#endif //ALGORITHM_VECTOR_H
