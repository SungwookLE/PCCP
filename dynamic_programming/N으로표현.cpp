#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;
// https://school.programmers.co.kr/learn/courses/30/lessons/42895#

int solution(int N, int number)
{
    int answer = 0;

    vector<unordered_set<int>> dp(9);
    dp[1] = {-N, N};

    for (auto data : dp[1])
        if (data == number)
            return 1;

    int num = N;
    for (int i = 2; i <= 8; ++i)
    {
        num = 10 * num + N;
        dp[i].insert(num);
        dp[i].insert(-num);

        for (int j = i - 1; j > 0; --j)
        {
            for (auto element1 : dp[i - j])
            {
                for (auto element2 : dp[j])
                {
                    dp[i].insert(element1 + element2);
                    dp[i].insert(element1 * element2);
                    dp[i].insert(element1 - element2);
                    if (element2 != 0)
                        dp[i].insert(element1 / element2);
                }
            }
        }

        for (auto data : dp[i])
            if (data == number)
                return i;
    }

    return -1;
}