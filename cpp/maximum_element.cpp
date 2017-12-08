#include <iostream>
#include <stack>
using namespace std;

struct element_node {
    long pos {};
    long value {};

    element_node(long pos, long value) : pos(pos), value(value) { }
};

ostream& operator<<(ostream& os, const element_node& el)
{
    os << el.value;
    return os;
}

int main(int argc, char **argv)
{
    stack<element_node> nums {};
    stack<element_node> max_values {};
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            if(long num {}; cin >> num)
            {
                element_node element { i, num };
                if(nums.empty() || num >= max_values.top().value)
                {
                    max_values.push(element);
                }
                nums.push(element);   
            }
        } else if(type == 2)
        {
            element_node top_node = nums.top();
            if(top_node.pos == max_values.top().pos)
            {
                max_values.pop();
            }
            nums.pop();
        } else if(type == 3)
        {
            cout << max_values.top() << '\n';
        }
    }
    return 0;
}
