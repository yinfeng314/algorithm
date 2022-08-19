//
// Created by yin_feng on 2022/8/19.
//

#ifndef ALGORITHM_BASE_H
#define ALGORITHM_BASE_H

namespace alg {
    template<typename InIterator, typename OutIterator>
    void copy(InIterator _first, InIterator _last, OutIterator _result) {
        InIterator tmp = _result;
        for (InIterator iterator = _first; iterator != _last; ++iterator) {
            *tmp++ = *iterator;
        }
    }

    template<typename Iterator>
    void copy_backward(Iterator _first, Iterator _end, Iterator _result) {
        Iterator tmp = _result - 1;
        for (Iterator iterator = _end; iterator != _first; --iterator) {
            *tmp-- = *(iterator - 1);
        }
    }
}

#endif //ALGORITHM_BASE_H
