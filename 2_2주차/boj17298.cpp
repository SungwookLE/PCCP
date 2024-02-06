#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
stack<int> stk;

int main()
{
    cin >> N;
    nums = vector<int>(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; --i)
    {

        if (stk.empty())
            ans.push_back(-1);
        else if (nums[i] < stk.top())
            ans.push_back(stk.top());
        else
        {
            while (!stk.empty() && nums[i] >= stk.top())
            {
                stk.pop();
            }

            if (stk.empty())
                ans.push_back(-1);
            else
                ans.push_back(stk.top());
        }
        stk.push(nums[i]);
    }

    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << " ";

    return 0;
}