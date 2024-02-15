#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N;
string s;
vector<int> nums;
vector<char> opers;
vector<int> ret;

int operate(int left, int right, char oper){
    if (oper == '+') return left+right;
    else if (oper =='*') return left*right;
    else if (oper == '-') return left-right;
}

void go(int here, int _num){

    if (here == nums.size()-1){
        ret.push_back(_num);
        return;
    } 

    go(here+1, operate(_num, nums[here+1] , opers[here]));
    if (here < nums.size() - 2 ){

        int temp = operate(nums[here+1], nums[here+2], opers[here+1]);
        go(here+2, operate(_num , temp, opers[here]));
    }
}

int main(){
    cin >> N;
    cin >> s;

    for(int i = 0 ; i < N ; ++i){
        if (i&1) opers.push_back(s[i]);
        else nums.push_back(s[i]-'0');
    }

    go(0, nums[0]);
    sort(ret.begin(), ret.end());
    cout << ret.back();

    return 0;
}

