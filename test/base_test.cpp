//
// Created by yin_feng on 2022/8/19.
//
#include <iostream>
#include "base.h"

using namespace alg;
using std::cout;

void print(int a[], int len){
    for (int i = 0; i < len; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main(){
    int a[10] = {1,2,3,8,9,1,2,2,3,4};
    int b[10] = {};
    print(b,10);
    copy(a,a+10,b);
    print(b,10);
    copy_backward(b,b+3,b+5);
    print(b,10);
}