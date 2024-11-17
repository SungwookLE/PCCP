#include <bits/stdc++.h>

using namespace std;
// 괄호를 적절히 추가해 만들 수 있는 식의 최대값

int N;
string S;
vector<int> Ns;
vector<char> Os = {'+'};

int go(int idx, int ret)
{

    if (idx > N / 2)
    {
        return ret;
    }

    int res = -2147483648;
    if (Os[idx] == '+')
    {
        res = max(res, go(idx + 1, ret + Ns[idx]));
        if (idx + 1 < Os.size())
        {
            if (Os[idx + 1] == '+')
                res = max(res, go(idx + 2, ret + (Ns[idx] + Ns[idx + 1])));
            else if (Os[idx + 1] == '-')
                res = max(res, go(idx + 2, ret + (Ns[idx] - Ns[idx + 1])));
            else if (Os[idx + 1] == '*')
                res = max(res, go(idx + 2, ret + (Ns[idx] * Ns[idx + 1])));
        }
    }
    else if (Os[idx] == '-')
    {
        res = max(res, go(idx + 1, ret - Ns[idx]));
        if (idx + 1 < Os.size())
        {
            if (Os[idx + 1] == '+')
                res = max(res, go(idx + 2, ret - (Ns[idx] + Ns[idx + 1])));
            else if (Os[idx + 1] == '-')
                res = max(res, go(idx + 2, ret - (Ns[idx] - Ns[idx + 1])));
            else if (Os[idx + 1] == '*')
                res = max(res, go(idx + 2, ret - (Ns[idx] * Ns[idx + 1])));
        }
    }
    else if (Os[idx] == '*')
    {
        res = max(res, go(idx + 1, ret * Ns[idx]));
        if (idx + 1< Os.size())
        {
            if (Os[idx + 1] == '+')
                res = max(res, go(idx + 2, ret * (Ns[idx] + Ns[idx + 1])));
            else if (Os[idx + 1] == '-')
                res = max(res, go(idx + 2, ret * (Ns[idx] - Ns[idx + 1])));
            else if (Os[idx + 1] == '*')
                res = max(res, go(idx + 2, ret * (Ns[idx] * Ns[idx + 1])));
        }
    }

    return res;
}

int main()
{
    cin >> N >> S;

    for (int i = 0; i < N; ++i)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            Ns.push_back(S[i] - '0');
        }
        else
        {
            Os.push_back(S[i]);
        }
    }

    // 뒤에 있는 숫자를 지금 바로 연산하는 것과 한 타임 뒤
    cout << go(0, 0);

    return 0;
}