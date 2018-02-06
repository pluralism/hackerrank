#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    int T;
    
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, K, num, onTime = 0;
        
        cin >> N >> K;
        for(int j = 0; j < N; j++)
        {
            cin >> num;
            if(num <= 0)
                onTime++;
        }
        
        if(onTime < K)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}