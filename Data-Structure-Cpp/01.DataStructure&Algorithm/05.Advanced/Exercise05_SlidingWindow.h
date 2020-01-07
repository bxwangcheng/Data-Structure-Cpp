#pragma once
#include "Exercise00_AdvancedTools.h"

// [L..R)
class SlideWindow {

public:
    SlideWindow(const vector<int>& arr) :
        arr(arr),
        left(0),
        right(0),
        q(deque<int>())
    {}

    int Max() {
        if (q.empty()) {
            return INT_MIN;
        }
        return arr[q.front()];
    }

    vector<int> Window() {
        auto l = arr.begin() + left;
        auto r = arr.begin() + right;
        vector<int> window(l, r);
        return window;
    }

    void MoveRightSlider() {
        if (arr.size() < 1 || right + 1 == arr.size()) {
            return;
        }
        right++;
        if (q.empty()) {
            q.push_back(right - 1);
        }
        else {
            while (!q.empty()) {
                if (arr[q.back()] < arr[right - 1]) {
                    q.pop_back();
                }
                else {
                    break;
                }
            }
            q.push_back(right - 1);
        }
    }

    void MoveLeftSlider() {
		if (arr.size() < 1 || left > right) {
            return;
        }
        if (q.front() == left++) {
            q.pop_front();
        }
    }

public:
    vector<int> arr;
    int left;
    int right;
    deque<int> q;
};