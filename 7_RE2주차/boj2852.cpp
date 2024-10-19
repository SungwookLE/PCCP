#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<string>> record;
map<int, vector<int>> ans;
map<int, int> board;

vector<int> mminus(vector<int> time1, vector<int> time2){

    int min1,sec1;
    int min2,sec2;

    min1 = time1[0];
    sec1 = time1[1];

    min2 = time2[0];
    sec2 = time2[1];

    int ret1= min2 - min1;
    int ret2 = 0;

    if (sec2>=sec1){
        ret2 = sec2-sec1;    
    }
    else{
        ret2 = 60+sec2 - sec1;
        ret1-=1;
    }
    


    return {ret1, ret2};
}

vector<int> pplus(vector<int> time1, vector<int> time2){

    int min1,sec1;
    int min2,sec2;

    min1 = time1[0];
    sec1 = time1[1];

    min2 = time2[0];
    sec2 = time2[1];

    int ret1=  min2 + min1;
    int ret2 = sec1 + sec2;

    while (ret2>=60){
        ret1+=1;
        ret2-=60;
    }
    
    return {ret1, ret2};
}

vector<int> split(string s){

    int min = stoi(s.substr(0,s.find(":")));
    int sec = stoi(s.substr(s.find(":")+1));

    return {min, sec};
}

int main(){

    cin >> N;
    for(int i =0 ; i < N ; ++i){
        string team;
        string time;
        cin >> team >> time;
        record.push_back({team,time});
    }
    record.push_back({"0","48:00"});

    ans[1] = {0,0};
    ans[2] = {0,0};
    board[1]=0;
    board[2]=0;

    vector<int> now_time = {0,0};
    for(int i = 0 ; i < record.size(); ++i){

        if (board[1]<board[2]) ans[2] = pplus(ans[2] , mminus(now_time, split(record[i][1])));
        if (board[1]>board[2]) ans[1] = pplus(ans[1] , mminus(now_time, split(record[i][1])));

        int now_team = stoi(record[i][0]);
        now_time = split(record[i][1]);
        board[now_team]+=1;
    }

    cout.fill('0');
    cout << setw(2) << ans[1][0] << ":" << setw(2) << ans[1][1] << endl;
    cout << setw(2) << ans[2][0] << ":" << setw(2) << ans[2][1] << endl;

    return 0;
}