#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;

/**
10 7
0 2
1 8
1 4
2 8
2 6
3 5
6 9

23
*/
int main(int argc, char **argv)
{
  int N, I;
  // num, branch
  unordered_map<int, int> vals_branches;
  // branch, elems
  unordered_map<int, unordered_set<int>> branches;

  cin >> N >> I;

  int n1, n2, branch_num = 1;
  for(int i = 0; i < I; i++)
  {
    cin >> n1 >> n2;

    int it1 = vals_branches.count(n1);
    int it2 = vals_branches.count(n2);

    if(it1 == 0 && it2 == 0)
    {
      unordered_set<int> tmp = { n1, n2 };
      vals_branches[n1] = vals_branches[n2] = branch_num;
      branches[branch_num++] = tmp;
      cout << "created new branch" << endl;
    } else if(it1 > 0 && it2 > 0)
    {
      cout << "both elements were found" << endl;

      cout << "content of first branch" << endl;
      unordered_set<int> fst = branches[vals_branches[n1]];
      for(auto it = fst.begin(); it != fst.end(); it++)
        cout << *it << " ";
      cout << endl;

      unordered_set<int> sec = branches[vals_branches[n2]];
      cout << "content of second branch" << endl;
      for(auto it = sec.begin(); it != sec.end(); it++)
        cout << *it << " ";
      cout << endl;

      branches[vals_branches[n1]].insert(sec.begin(), sec.end());

      cout << "content of first branch after!!!" << endl;
      for(auto it = branches[vals_branches[n1]].begin(); it != branches[vals_branches[n1]].end(); it++)
        cout << *it << " ";
      cout << endl;

      branches.erase(vals_branches[n2]);

      for(auto it = sec.begin(); it != sec.end(); it++)
      {
        cout << "a mudar valor " << *it << " para branch " << vals_branches[n1] << endl;
        vals_branches[*it] = vals_branches[n1];
      }
    } else if(it1 > 0 && it2 == 0)
    {
      cout << "first element found" << endl;
      branches[vals_branches[n1]].insert(n2);
    } else if(it1 == 0 && it2 > 0)
    {
      cout << "second element found" << endl;
      branches[vals_branches[n2]].insert(n1);
    }
  }

  cout << "total branches: " << branches.size() << endl;

  int branch_total_sum = 0;
  for(auto i = branches.begin(); i != branches.end(); i++)
    branch_total_sum += (*i).second.size();

  int sum = 0;
  for(auto i = branches.begin(); i != branches.end() && next(i) != branches.end(); i++)
      sum += (*i).second.size() * (branch_total_sum - (*i).second.size());

  cout << sum << endl;

  return 0;
}
