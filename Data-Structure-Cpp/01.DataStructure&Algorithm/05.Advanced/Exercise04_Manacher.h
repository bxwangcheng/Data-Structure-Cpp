#pragma once
#include "Exercise00_AdvancedTools.h" 

string Preprocess(string str);

int MaxPalindrome(string s) {
    if (s.size() < 1)
        return 0;
    string str = Preprocess(s);
    int max_radius = INT_MIN;
    for (int i = 0; i < str.size(); i++) {
        int R = 0;
        while (i - R >= 0 && i + R < str.size() && 
                (str[i - R] == str[i + R])) {
                R++;
        }
        max_radius = max(R, max_radius);
    }
	return max_radius - 1;
}

int Manacher(string s) {
    if (s.size() < 1)
        return 0;
    string str = Preprocess(s);
    vector<int> radius_arr(str.size(), 0);
    int max_radius = INT_MIN;
    int right_bound = -1;
    int center = -1;
    for (int i = 0; i < str.size(); i++) {
        radius_arr[i] = i < right_bound ? min(radius_arr[2 * center - i], right_bound - i) : 1;
        while (i - radius_arr[i] >= 0 && i + radius_arr[i] < str.size()) {
            if (str[i - radius_arr[i]] == str[i + radius_arr[i]]) {
                radius_arr[i]++;
            }
            else {
                break;
            }
        }
        if (i + radius_arr[i] > right_bound) {
            right_bound = i + radius_arr[i];
            center = i;
        }
        max_radius = max(max_radius, radius_arr[i]);
    }
    return max_radius - 1;
}

string Preprocess(string str) {
    if (str.size() < 1)
        return "";
    string res;
    res.resize(str.size() * 2 + 1);
    int j = 0;
    for (int i = 0; i < res.size(); i++) {
        if (i % 2) {
            res[i] = str[j++];
        }
        else {
            res[i] = '#';
        }
    }
    return res;
}