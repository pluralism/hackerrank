#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main(int argc, char **argv)
{
  int N, I;
  unordered_map<int, int> vals_branches;
  unordered_map<int, unordered_set<int>> branches;

  cin >> N >> I;

  int n1, n2;
  int branch_num = 0;
  for(int i = 0; i < I; i++)
  {
    cin >> n1 >> n2;

    unordered_map<int, int>::const_iterator it = vals_branches.find(n1);
    if(it == vals_branches.end())
      it = vals_branches.find(n2);

    if(it == vals_branches.end())
    {
      vals_branches[n1] = branch_num;
      vals_branches[n2] = branch_num;

      unordered_set<int> tmp = { n1, n2 };
      branches[branch_num] = tmp;
      branch_num++;
    }
  }

  int branch_total_sum = 0;
  for(int i = 0; i < branches.size(); i++)
    branch_total_sum += branches[i].size();

  int sum = 0;
  for(int i = 0; i < branches.size() - 1; i++)
    sum += branches[i].size() * (branch_total_sum - branches[i].size());

  cout << sum << endl;

  return 0;
}
