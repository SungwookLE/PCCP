#include <bits/stdc++.h>

using namespace std;

int main()
{

    int T;
    cin >> T;

    string s;
    for (int i = 0; i < T; ++i)
    {
        cin >> s;

        stack<char> dish;
        while (!s.empty())
        {

            if (!dish.empty())
            {
                if (dish.top() == ')' && s.back() == '(')
                    dish.pop();
                else
                    dish.push(s.back());
            }
            else
                dish.push(s.back());
            s.pop_back();
        }

        if (dish.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}