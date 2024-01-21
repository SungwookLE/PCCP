#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> combi;
vector<int> weights(9, 0);

void make_combination(int start, vector<int> v)
{

    if (v.size() == 7)
    {
        combi.push_back(v);
        return;
    }

    for (int i = start + 1; i < 9; ++i)
    {
        v.push_back(i);
        make_combination(i, v);
        v.pop_back();
    }

    return;
}

int main()
{

    for (int i = 0; i < 9; ++i)
        cin >> weights[i];

    vector<int> V;
    make_combination(-1, V);

    for (auto comb : combi)
    {
        int sum = 0;
        vector<int> forPrint;
        for (auto value : comb)
        {
            sum += weights[value];
            forPrint.push_back(weights[value]);
        }
        if (sum == 100)
        {
            // 오름차순 정렬
            sort(forPrint.begin(), forPrint.end());
            for (auto value : forPrint)
            {
                cout << value << "\n";
            }
            break;
        }
        forPrint.clear();
    }

    return 0;
}