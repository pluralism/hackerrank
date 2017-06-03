#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;


int main() {
    map<char, int> lettersToRemove, occurs;
    map<char, vector<int>> occursIndex;
    string s;
    int N, countA = 0, countC = 0, countT = 0, countG = 0;
    cin >> N;
    cin >> s;
    N = N / 4;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c == 'A')
            countA++;
        else if(c == 'C')
            countC++;
        else if(c == 'T')
            countT++;
        else if(c == 'G')
            countG++;
    }

    if(countA > N) {
        lettersToRemove['A'] = countA - N;
        occursIndex['A'] = vector<int>();
    }
    if(countC > N) {
        lettersToRemove['C'] = countC - N;
        occursIndex['C'] = vector<int>();
    }
    if(countG > N) {
        lettersToRemove['G'] = countG - N;
        occursIndex['G'] = vector<int>();
    }
    if(countT > N) {
        lettersToRemove['T'] = countT - N;
        occursIndex['T'] = vector<int>();
    }

    int best = INT_MAX;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(lettersToRemove.find(c) != lettersToRemove.end()) {
            occurs[c]++;
            occursIndex[c].push_back(i);

            bool ready = true;
            for(map<char, int>::iterator it = lettersToRemove.begin(); it != lettersToRemove.end(); it++) {
                if(occurs[it->first] < lettersToRemove[it->first]) {
                    ready = false;
                    break;
                }
            }


            if(ready) {
                int minVal = INT_MAX, maxVal = 0;
                for(map<char, int>::iterator it = lettersToRemove.begin(); it != lettersToRemove.end(); it++) {
                    char tmp = it->first;
                    minVal = min(minVal, occursIndex[tmp][occursIndex[tmp].size() - lettersToRemove[tmp]]);
                    maxVal = max(maxVal, occursIndex[tmp].back());
                }
                best = min(best, maxVal - minVal + 1);
            }
        }
    }

    cout << (best == INT_MAX ? 0 : best) << endl;
    return 0;
}
