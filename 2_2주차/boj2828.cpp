#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> apples;
int main()
{
    cin >> N >> M;

    int J;
    cin >> J;

    pair<int, int> basket = {1, M};

    int answer = 0;
    for (int i = 0; i < J; ++i)
    {
        int apple;
        cin >> apple;

        int diff = 0;
        if (basket.first <= apple && apple <= basket.second)
            continue;
        else if (apple > basket.second) // right
        {
            diff = apple - basket.second;
            basket.first += diff;
            basket.second += diff;
            answer += diff;
        }
        else if (apple < basket.first) // left
        {
            diff = apple - basket.first;
            basket.first += diff;
            basket.second += diff;
            answer += abs(diff);
        }
    }

    cout << answer << "\n";
    return 0;
}