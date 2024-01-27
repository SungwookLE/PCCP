#include <bits/stdc++.h>

using namespace std;

map<string, bool> dict;
vector<vector<char>> input(5, vector<char>(5,' '));
vector<vector<int>> visited(5, vector<int>(5, 0));

int answer = 0;
vector<vector<int>> deltas = {{-1, -1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};


/*
// '24.1.25.
// 이 문제 어떻게 푸는게 맞는걸까? ㅎㅎ;;;;
// DP로 풀수있는걸까?
// 그리디?? -> 특별한 자료구조가 필요하다고 함.

문제 풀지 않고 넘어가기로 함
*/

void make_word(int i , int j, string v){

    if (dict.find(v) != dict.end() && dict[v] ==false ){
        dict[v] = true;
        answer +=1 ;
        return;
    }
    else if ( v.size() == 8) // 이렇게 안두면 알고리즘이 끝나지 않기 때문에.. 임시로
        return;



    for(auto d :deltas){
        int next_i = i + d[0], next_j = j + d[1];
        if (next_i >= 0 && next_j >= 0 && next_i < 5 && next_j < 5 && visited[next_i][next_j] == 0){
            visited[next_i][next_j] = 1;
            v.push_back(input[next_i][next_j]);
            make_word(next_i, next_j, v);
            v.pop_back();
            visited[next_i][next_j] = 0;

        }
    }

    return;
}


int main(){

    ifstream is;
    is.open("dict.txt");

    string s;
    while (is>>s) dict[s] = false;

    for(int i = 0 ; i < 5; ++i)
        for(int j = 0 ; j < 5; ++j)
            cin >> input[i][j];

    for(int i = 0 ; i < 5; ++i)
        for(int j = 0 ; j < 5; ++j)
            make_word(i,j,{});

    cout << answer << "\n";
    return 0;
}