#include <iostream>
#include <cstring>
using namespace std;

void calculateFactorial(int arr[], int num)
{
    if(num < 1)
        return;
    
    int carry = 0;
    for(int i = 1999; i >= 0; i--)
    {
        arr[i] = (arr[i] * num) + carry;
        carry = arr[i] / 10;
        arr[i] %= 10;
    }
    calculateFactorial(arr, num - 1);
}


int main(int argc, const char * argv[]) {
    int n;
    int *arr = new int[2000];
    memset(arr, 0, sizeof(int));
    arr[1999] = 1;
    
    cin >> n;
    calculateFactorial(arr, n);
    bool valid = false;
    for(int i = 0; i < 2000; i++)
    {
        if(!valid && arr[i] != 0)
            valid = true;
        
        if(valid)
            cout << arr[i];
    }
    return 0;
}
