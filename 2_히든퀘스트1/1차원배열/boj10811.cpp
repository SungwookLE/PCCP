#include <bits/stdc++.h>

using namespace std;

int N , M;
vector<int> nums;

int main(){
    cin >> N >> M;

    nums = vector<int>(N+1,0);

    for(int i =1 ; i <= N ; ++i){
        nums[i] = i;
    }
    

    int p, q;
    for(int i =0 ; i < M ; ++i){
        cin >> p >> q;
        reverse(nums.begin()+p, nums.begin()+q+1);

    }

    for(int i = 1 ; i <= N ; ++i){
        cout << nums[i] << " ";
    }



    return 0;
}