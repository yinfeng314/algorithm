#include <iostream>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;

template<typename Func>
void call_twice(Func const &func) {
    cout << func(1) << endl;
    cout << func(2) << endl;
    cout << sizeof(func) << endl;
}

auto make_twice(int n) {
    return [=](int a) {
        return n + 2 + a;
    };
}

int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
//    auto p = make_twice(3);
//    call_twice(p);
//    cout << sizeof p;
    vector<int> a = {2, 5};
    cout << searchInsert(a, 3);
    return 0;
}
