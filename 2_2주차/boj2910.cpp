#include <bits/stdc++.h>

using namespace std;
vector<int> input;

int main()
{

    int N, C;
    cin >> N >> C;

    input = vector<int>(N,0);
    map<int, int> mp_freq; // 맵은 이렇게 선언만 해도 그 값이 0으로 저절로 초기화됨
    map<int, int> mp_first;

    for(int i = 0 ; i < N; ++i){
        cin >> input[i];
        mp_freq[input[i]] ++;
        if(mp_first[input[i]] == 0) mp_first[input[i]] = i+1;
    }

    vector<pair<int, int>> V;
    for(auto it : mp_freq){
        V.push_back({it.second, it.first}); // 맵 자료구조는 바로 정렬할수가 없음
    }

    sort(V.begin(), V.end(), [&mp_first](auto a, auto b){
        if (a.first==b.first)
            return mp_first[a.second] < mp_first[b.second];
        else
            return a.first > b.first;
    });

    for(auto i : V){
        for(int j = 0 ; j < i.first; ++j){
            cout << i.second << " ";
        }
    }


    return 0;
}