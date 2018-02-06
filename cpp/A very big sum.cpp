#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int n;
    long long int num, total = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        total += num;
    }
    
    cout << total << endl;
    return 0;
}
