
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

#include "myMap.hpp"

template<typename InputIterator>
auto standardDeviation(InputIterator first, InputIterator last) {
    double a[last - first];
    double sum = 0.0;
    double sd = 0.0;
    int i = 0;

    for (auto it = first; it != last; ++it, ++i)a[i] = it->second;
    for (int i = 0; i < 10; ++i) sum += a[i];
    for (int i = 0; i < 10; ++i) sd += pow(a[i] - (sum / 10), 2);

    return sqrt(sd / 10);
}

int main() {
    myMap<string, int> m;
    string k;
    int v;
    ifstream is("../studentMarks.txt");
    while (is >> k >> v) m.add(k, v);
    cout << "=====================================" << endl;
    cout << "3.b)" << endl;
    cout << m;
    cout << "=====================================" << endl;
    cout << "3.d)" << endl;
    cout << "Standard Deviation: " << standardDeviation(m.my_vec.begin(), m.my_vec.end()) << endl;
    cout << "=====================================" << endl;
    cout << "3.e)" << endl;
    cout << m[5].first << " : " << m[5].second << endl;
    cout << "=====================================" << endl;
    cout << "3.f)" << endl;
    cout << "[Wiggim] : " << m["Wiggim"] << endl;
    return 0;
}