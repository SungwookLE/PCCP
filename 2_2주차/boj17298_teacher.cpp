#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums, ret;
stack<int> stk;

int main()
{
    cin >> N;
    nums = vector<int>(N, 0);
    ret = vector<int>(N, -1);

    for (int i = 0; i < N; ++i){
        cin >> nums[i];
        while (!stk.empty() && nums[stk.top()] < nums[i]) ret[stk.top()] = nums[i], stk.pop(); // 오큰수를 찾은 순간
        stk.push(i);
    }
    for(int i = 0 ; i < N ; ++i) cout << ret[i] << " ";


    return 0;
}