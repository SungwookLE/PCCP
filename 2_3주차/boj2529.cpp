#include <bits/stdc++.h>

using namespace std;

int K;
vector<char> O;
vector<int> visited(10, 0);

vector<string> ret;

void dfs(int i, string nums)
{

    if (i == (K + 1))
    {
        ret.push_back(nums);
        return;
    }

    for (int j = 0; j < 10; ++j)
    {

        if (visited[j] == 0)
        {

            if (nums.size())
            {
                if (O[i - 1] == '>')
                {
                    if (nums.back() > j + '0')
                    {
                        visited[j] = 1;
                        nums.push_back(j + '0');

                        dfs(i + 1, nums);

                        visited[j] = 0;
                        nums.pop_back();
                    }
                }
                else if (O[i - 1] == '<')
                {
                    if (nums.back() < j + '0')
                    {
                        visited[j] = 1;
                        nums.push_back(j + '0');

                        dfs(i + 1, nums);

                        visited[j] = 0;
                        nums.pop_back();
                    }
                }
            }
            else
            {
                nums.push_back(j + '0');
                visited[j] = 1;

                dfs(i + 1, nums);

                visited[j] = 0;
                nums.pop_back();
            }
        }
    }

    return;
}

int main()
{
    cin >> K;
    O = vector<char>(K);
    for (int i = 0; i < K; ++i)
        cin >> O[i];

    dfs(0, "");

    sort(ret.begin(), ret.end());
    cout << ret.back() << "\n"
         << ret[0] << "\n";

    return 0;
}