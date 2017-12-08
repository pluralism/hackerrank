#include <iostream>
#include <sstream>
#include <chrono>
#include <fstream>
#include "gtest/gtest.h"
#include "equal_stacks.h"
using namespace std;
using namespace std::chrono;

TEST(EqualStacksTest, test2)
{
    cin.clear(); // clears the error flag on cin so that future I/O operations will work correctly
    ifstream file("../test2.txt", std::ifstream::in);
    string s((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    istringstream iss(s);
    cin.rdbuf(iss.rdbuf());
    high_resolution_clock::time_point begin = std::chrono::high_resolution_clock ::now();
    int result = equal_stacks();
    high_resolution_clock::time_point end = std::chrono::high_resolution_clock ::now();;
    cout << '\n' << duration_cast<milliseconds>(end - begin).count() << '\n';
    EXPECT_EQ(result, 994749);
}

TEST(EqualStacksTest, test25)
{
    cin.clear(); // clears the error flag on cin so that future I/O operations will work correctly
    ifstream file("../test25.txt", std::ifstream::in);
    string s((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    istringstream iss(s);
    cin.rdbuf(iss.rdbuf());
    high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    int result = equal_stacks();
    high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    cout << '\n' << duration_cast<milliseconds>(end - begin).count() << '\n';
    EXPECT_EQ(result, 1357059);
}
