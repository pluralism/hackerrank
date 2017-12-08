#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

template<typename T>
vector<T> create_vec(T lim)
{
    vector<T> vec(lim);
    for(T i {0}; i < lim; i++)
    {
        T tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    return vec;
}

template<typename T>
unordered_set<T> create_set(T lim, vector<T> vec)
{
    unordered_set<T> set1(lim);
    int sum = 0;
    for(auto x {vec.rbegin()}; x != vec.rend(); x++)
    {
        sum += *x;
        set1.insert(sum);
    }
    return set1;
}

int main(int argc, char **argv)
{
    int_fast32_t n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int_fast32_t> vec1 {create_vec<int_fast32_t>(n1)};
    vector<int_fast32_t> vec2 {create_vec<int_fast32_t>(n2)};
    vector<int_fast32_t> vec3 {create_vec<int_fast32_t>(n3)};

    unordered_set<int_fast32_t> set1 {create_set<int_fast32_t>(n1, vec1)};
    unordered_set<int_fast32_t> set2 {create_set<int_fast32_t>(n2, vec2)};
    int_fast32_t max {0}, sum {0};
    for(auto x {vec3.rbegin()}; x != vec3.rend(); x++)
    {
        sum += *x;
        if(set1.count(sum) > 0 && set2.count(sum) > 0)
        {
            max = sum;
        }
    }
    cout << max << '\n';
    return 0;
}
