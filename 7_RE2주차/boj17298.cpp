#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> Ns;
stack<int> stk;
vector<int> ans;

int main()
{
    cin >> N;
    Ns.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> Ns[i];
    }

    for (int i = Ns.size() - 1; i >= 0; --i)
    {

        if (stk.empty())
            ans.push_back(-1);
        else if (Ns[i] < stk.top())
            ans.push_back(stk.top());
        else
        {

            while (stk.size() && Ns[i] >= stk.top())
            {
                stk.pop();
            }

            if (stk.size())
                ans.push_back(stk.top());
            else
                ans.push_back(-1);
        }
        stk.push(Ns[i]);
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << " ";

    return 0;
}