#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<string> input(N);
    for (int i = 0; i < N; ++i)
        cin >> input[i];

    vector<string> numbers;
    for (auto in : input)
    {
        string temp = "";
        for (auto k : in)
        {
            if (k >= '0' && k <= '9')
                temp += k;
            else
            {
                if (!temp.empty())
                { // 비어있는 문자열 일 경우 push_back 할 필요 없으니깐
                    while (temp.size() > 1 && temp[0] == '0')
                        temp.erase(temp.begin());
                    // 위랑 아래 라인이랑 같은 의미임, 끝 위치를 안적어주면 1글자만 지워줌
                    // temp.erase(temp.begin(), temp.begin() + 1);
                    numbers.push_back(temp);
                    temp = "";
                }
            }
        }
        if (!temp.empty())
        {
            while (temp.size() > 1 && temp[0] == '0')
                temp.erase(temp.begin());
            numbers.push_back(temp);
        }
    }

    sort(numbers.begin(), numbers.end(), [](auto a, auto b)
         {
             if (a.size() < b.size())
                 return true;
             else if (a.size() == b.size())
             {
                 if (a < b)
                     return true;
             }
             return false; });
    for (auto n : numbers)
        cout << n << "\n";

    return 0;
}