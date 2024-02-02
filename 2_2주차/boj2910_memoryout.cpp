#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N, C;
    cin >> N >> C;

    vector<pair<int, int>> nums(C+1, {0,-1});
    vector<int> original;

    int mn = N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        original.push_back(num);
        nums[num].first += 1; // 빈도
        if (nums[num].second == -1)
            nums[num].second = i;
    }

    sort(nums.begin(), nums.end(), [](auto a, auto b)
         {

        if (a.first > b.first)
            return true;
        else{
            if (a.first == b.first){
                if (a.second < b.second )
                    return true;
            }
        }

        return false; });

    


    for(int i = 0 ; i < nums.size(); ++i){
        
        while(nums[i].first > 0){
            cout << original[nums[i].second] << " ";
            nums[i].first -= 1;
        }
    }

    return 0;
}