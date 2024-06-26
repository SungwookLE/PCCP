#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> K;

map<vector<int>, string> mp;
map<int, int> result;
map<vector<int>, int> DP;

void go(int length, vector<int> number, string res){

    if (length == 0){
        if (mp.count(number)){
            int r = stoi(res+mp[number]);
            if (r!= 0) result[stoi(res+mp[number])] = stoi(res+mp[number]);
        }
        return;
    }

    for(int i = 0; i < 7 ; ++i){
        if (number[i] == 0){
            number[i] = 1;
            go(length-1, number, res);
            number[i] = 0;
        }
        if (mp.count(number)) go(length, vector<int>(7,0), res+mp[number]);
    }

    return;
}


int main(){
    // 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는
    // 가장 작은 수와 큰 수를 찾는 프로그램

    cin >> T;
    K = vector<int>(T,0);
    for(int i =0 ; i < T ; ++i) cin >> K[i];

    mp[{0,0,1,0,0,1,0}] = "1";
    mp[{1,0,1,1,1,0,1}] = "2";
    mp[{1,0,1,1,0,1,1}] = "3";
    mp[{0,1,1,1,0,1,0}] = "4";
    mp[{1,1,0,1,0,1,1}] = "5";
    mp[{1,1,0,1,1,1,1}] = "6";
    mp[{1,0,1,0,0,1,0}] = "7";
    mp[{1,1,1,1,1,1,1}] = "8";
    mp[{1,1,1,1,0,1,1}] = "9";
    mp[{1,1,1,0,1,1,1}] = "0";

    for(int i =0 ; i < T; ++i){
        go(K[i], vector<int>(7,0), {});
        cout << result.begin()->second << " " << result.rbegin()->second << "\n";
    }


    return 0;
}