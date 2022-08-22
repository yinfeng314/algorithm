//
// Created by yin_feng on 2022/8/20.
//

#ifndef ALGORITHM_FORWARD_LIST_H
#define ALGORITHM_FORWARD_LIST_H

#include <ostream>
#include <initializer_list>

using std::ostream;
using std::out_of_range;
using std::initializer_list;

namespace alg {
    template<typename Item>
    class forward_list {
    public:
        forward_list() : _size(0), _head(new forward_list_node) {}

        explicit forward_list(int size, const Item &item = Item{}) : _size(size), _head(new forward_list_node) {
            forward_list_node *tmp = _head;
            while (size-- != 0) {
                tmp->_next = new forward_list_node(item);
                tmp = tmp->_next;
            }
        }

        forward_list(const Item *item, int lo, int hi) : _size(hi - lo), _head(new forward_list_node) {
            forward_list_node *tmp = _head;
            while (lo < hi) {
                tmp->_next = new forward_list_node(item[lo]);
                tmp = tmp->_next;
                lo++;
            }
        }

        forward_list(const initializer_list<Item> &il) : _size(il.size()), _head(new forward_list_node) {
            forward_list_node *tmp = _head;
            for (auto item: il) {
                tmp->_next = new forward_list_node(item);
                tmp = tmp->_next;
            }
        }

        forward_list(const forward_list &other) : _size(other._size), _head(nullptr) {
            if (_size == 0) return;
            _head = new forward_list_node(other._head->_item);
            forward_list_node *tmp = _head, other_tmp = other._head->_next;
            while (other_tmp != nullptr) {
                tmp->_next = new forward_list_node(other_tmp._item);
                tmp = tmp->_next;
                other_tmp = other_tmp._next;
            }
        }

        ~forward_list() {
            clear();
            delete _head;
        }

        friend ostream &operator<<(ostream &os, const forward_list &fl) {
            forward_list_node *tmp = fl._head;
            while (tmp->_next != nullptr) {
                tmp = tmp->_next;
                os << tmp->_item << ' ';
            }
            os << '\n';
            return os;
        }

        int size() { return _size; }

        bool empty() { return size() == 0; }

        bool check(int index) { return index < size() && index >= 0; }

        void clear() {
            _size = 0;
            while (_head != nullptr) {
                forward_list_node *tmp = _head->_next;
                delete _head;
                _head = tmp;
            }
            _head = new forward_list_node;
        }

        Item &get(int index) {    // 从0开始
            return move(index)->_item;
        }

        int search(const Item &item) {
            if (empty()) return -1;
            forward_list_node *tmp = _head->_next;
            int index = 0;
            while (tmp != nullptr) {
                if (tmp->_item == item) return index;
                tmp = tmp->_next;
                index++;
            }
            return index;
        }

        Item &operator[](int index) {
            return get(index);
        }

        void insert(int index, const Item &item) {
            forward_list_node *tmp = nullptr;
            if (empty() && index == 0)
                tmp = _head;
            else if (index == size())
                tmp = move(size() - 1);
            else if (check(index))
                tmp = move(index);
            else throw out_of_range("index out of range");

            if (tmp->_next == nullptr) {    // for push_front and push_back
                tmp->_next = new forward_list_node(item);
            } else
                tmp->_next = new forward_list_node(item, tmp->_next);
            _size++;
        }

        void push_front(const Item &item) { insert(0, item); }

        void push_back(const Item &item) { insert(size(), item); }

        void remove(int index) {
            if (!check(index)) throw out_of_range("index out of range");
            forward_list_node *forward = move(index - 1), *tmp = move(index);
            forward->_next = tmp->_next;
            delete tmp;
        }

        Item pop_front() { remove(0); }

        Item pop_back() { remove(size()); }

    private:
        struct forward_list_node {
            Item _item;
            forward_list_node *_next;

            forward_list_node() : _item(), _next(nullptr) {};    // 对于_head的构建

            explicit forward_list_node(const Item &item, forward_list_node *next = nullptr) : _item(item),
                                                                                              _next(next) {}

            ~forward_list_node() = default;
        };

        forward_list_node *_head;
        int _size;

        forward_list_node *move(int index) noexcept {    // unsafe
            forward_list_node *tmp = _head;
            while (index-- >= 0)
                tmp = tmp->_next;
            return tmp;
        }
    };
}

#endif //ALGORITHM_FORWARD_LIST_H
