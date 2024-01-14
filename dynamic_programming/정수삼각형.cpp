#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;

    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {

            if (j != 0 && j != i)
            {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            else if (j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1];
        }
    }

    for (auto ele : triangle.back())
    {

        if (answer < ele)
            answer = ele;
    }

    return answer;
}