//
// Created by Daniel Shin on 2018-11-26.
//

#ifndef MIDTERM2_MYMAP_HPP
#define MIDTERM2_MYMAP_HPP


#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

template<class K = string, class V = int>
class myMap {
public:
    vector<pair<K, V>> my_vec;

    void add(K k, V v) {
        int index = exists(k);
        if (index == -1) {
            my_vec.push_back(make_pair(k, v));
            sort(my_vec.begin(), my_vec.end(), [](auto i, auto j) {
                return i.first < j.first;
            });
        } else {
            my_vec[index].second = v;
        }
    }

    int exists(K k) {
        int i = 0;
        for (auto pair:my_vec) {
            if (pair.first == k) return i;
            ++i;
        }
        return -1;
    }

    pair<K, V> operator[](int i) {
        return my_vec[i];
    };

    V operator[](K key) {
        int index = exists(key);
        if (index == -1) return NULL;
        else return my_vec[index].second;
    }

    friend ostream &operator<<(ostream &os, const myMap m) {
        for (int i = 0; i < m.my_vec.size(); ++i)
            os << m.my_vec[i].first << " : " << m.my_vec[i].second << endl;
        return os;
    }
};


#endif //MIDTERM2_MYMAP_HPP
