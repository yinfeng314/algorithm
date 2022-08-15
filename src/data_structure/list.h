//
// Created by yin_feng on 2022/8/10.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#include <ostream>

namespace alg {
    template<typename Item>
    class list {
    public:
        // ---------------------- 基础构造函数和析构函数 ------------------------
        list() : _size(0), _head(new list_node), _tail(new list_node) {
            _head->_next = _tail;
            _head->_prev = nullptr;
            _tail->_prev = _head;
            _tail->_next = nullptr;
        }

        list(const list &other) : _size(other._size) {
            list_node *tmp = _head;
            list_node *other_tmp = other._head;
            while (other_tmp->_next != other._tail) {
                tmp->_next = new list_node(other_tmp->_item);
                other_tmp = other_tmp->_next;
                tmp = tmp->_next;
            }
            tmp->_next = _tail;
            _tail->_prev = tmp;
        }

        list &operator=(const list &other) {
            if (this == &other) return *this;
            this->~list();
            list_node *tmp = _head;
            list_node *other_tmp = other._head;
            while (other_tmp->_next != other._tail) {
                tmp->_next = new list_node(other_tmp->_item, tmp);
                tmp = tmp->_next;
                other_tmp = other_tmp->_next;
            }
            return *this;
        }

        ~list() {
            while (_head != _tail) {
                list_node *tmp = _head;
                _head = _head->_next;
                delete tmp;
            }
        }

        // -------------------------- 其他构造函数 ------------------------


        // --------------------- 公有函数接口 -----------------------
        friend std::ostream &operator<<(std::ostream &os, const list &l) {
            list_node *tmp = l._head->_next;
            while (tmp != l._tail) {
                os << tmp->_item;
                tmp = tmp->_next;
            }
            return os;
        }

        void push_back(const Item &item) {
            auto *n = new list_node(item, _tail->_prev, _tail);
            _tail->_prev->_next = n;
            _tail->_prev = n;
        }


    private:
        struct list_node {
            Item _item;
            list_node *_next;
            list_node *_prev;

            explicit list_node(const Item &item = Item(), list_node *n = nullptr, list_node *p = nullptr) :
                    _item(item), _prev(n), _next(p) {}

            list_node(const list_node &ln) : _item(ln._item), _next(ln._next), _prev(ln._prev) {}

            ~list_node() {
                delete _next, _prev;
            }

        };

        list_node *_head;
        list_node *_tail;
        size_t _size;

        // 私有函数接口
        void copy() {

        }
    };
}

#endif //ALGORITHM_LIST_H
