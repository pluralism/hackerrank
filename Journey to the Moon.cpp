#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
using namespace std;


int main(int argc, char **argv)
{
  int N, I;
  unordered_map<int, int> vals_branches;
  unordered_map<int, unordered_set<int>> branches;

  cin >> N >> I;

  int n1, n2, it1, it2, branch_num = 1;
  for(int i = 0; i < I; i++)
  {
    cin >> n1 >> n2;

    it1 = vals_branches.count(n1);
    it2 = vals_branches.count(n2);

    if(it1 == 0 && it2 == 0)
    {
      vals_branches[n1] = vals_branches[n2] = branch_num;
      branches[branch_num++] = { n1, n2 };
    } else if(it1 > 0 && it2 > 0)
    {
      if(vals_branches.count(n1) > 0 && vals_branches.count(n2) > 0 &&
      vals_branches[n1] == vals_branches[n2])
        continue;

      unordered_set<int> fst = branches[vals_branches[n1]],
        sec = branches[vals_branches[n2]];

      branches[vals_branches[n1]].insert(sec.begin(), sec.end());
      branches.erase(vals_branches[n2]);

      for(auto it = sec.begin(); it != sec.end(); it++)
        vals_branches[*it] = vals_branches[n1];
    } else if(it1 > 0 && it2 == 0)
    {
      branches[vals_branches[n1]].insert(n2);
      vals_branches[n2] = vals_branches[n1];
    } else if(it1 == 0 && it2 > 0)
    {
      branches[vals_branches[n2]].insert(n1);
      vals_branches[n1] = vals_branches[n2];
    }
  }

  for(int i = 0; i < N; i++)
  {
    if(vals_branches.count(i) == 0)
    {
      vals_branches[i] = branch_num;
      branches[branch_num++] = { i };
    }
  }

  long long sum = 0, proc_nums = 0;
  for(auto i = branches.begin(); i != branches.end() && next(i) != branches.end(); i++)
  {
    sum += (*i).second.size() * (N - (*i).second.size() - proc_nums);
    proc_nums += (*i).second.size();
  }

  cout << sum << endl;
  return 0;
}
