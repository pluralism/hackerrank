#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    int T, C;
    
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> C;
        bool doubleHeight = true;
        int currentHeight = 1;
        
        for(int j = 0; j < C; j++)
        {
            doubleHeight ? currentHeight *= 2 : currentHeight += 1;
            doubleHeight = !doubleHeight;
        }
        cout << currentHeight << endl;
    }
    return 0;
}