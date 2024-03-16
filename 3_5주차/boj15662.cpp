#include <bits/stdc++.h>
using namespace std;
int T, K;
vector<vector<int>> G, tempG;
vector<vector<int>> I;

bool rotated(int number, int contact, string pos, int direction){
    
    // number: 기어의 번호

    // direction = 1: 시계방향
    // direction =-1: 반시계방향

    // contact: 접한 극 
    // N: 0, S: 1

    int idx = 0;
    if (pos == "RIGHT") idx = 6;
    else if (pos == "LEFT") idx = 2; 

    if(G[number][idx] != contact){

        if(direction == 1){
            for(int i = 1 ; i < 8; ++i){
                tempG[number][i] = G[number][i-1];
            }
            tempG[number][0] = G[number][7];
        }
        else if (direction == -1){
            for(int i = 0 ; i < 7 ; ++i){
                tempG[number][i] = G[number][i+1];
            }
            tempG[number][7] = G[number][0];
        }

        return true;
    }
    else return false;

}

void rotating(int number, int direction){
    
    // number: 기어의 번호

    // direction = 1: 시계방향
    // direction =-1: 반시계방향

    if(direction == 1){
        for(int i = 1 ; i < 8; ++i){
            tempG[number][i] = G[number][i-1];
        }
        tempG[number][0] = G[number][7];
    }
    else if (direction == -1){
        for(int i = 0 ; i < 7 ; ++i){
            tempG[number][i] = G[number][i+1];
        }
        tempG[number][7] = G[number][0];
    }

}

void debug(){
    cout << "DEBUG: " << endl;
    for(int i = 1 ; i <= T ; ++i){
        cout << "(" << i << ")" << endl;
        cout       << "  " <<  G[i][0]         << endl 
        << " " <<  G[i][7] << "  "       << G[i][1] << endl
        << G[i][6] << "    "      << G[i][2] << endl
        << " " << G[i][5] << "  "       << G[i][3] << endl
                    << "  " << G[i][4]   << endl;
        cout << endl;
    }
}

int main(){
    cin >> T;
    G = vector<vector<int>>(T+1, vector<int>(8,0));

    string s;
    for(int i = 1 ; i <= T ; ++i){
        cin >> s;
        for(int j =0 ; j < s.size(); ++j){
            G[i][j] = (s[j]-'0');
            // N극은 0, S극은 1
        }
    }
    tempG = G;

    cin >> K;
    for(int i =0 ; i < K ; ++i){
        int a, b;
        cin >> a >> b;
        I.push_back({a,b});
        // a:톱니바퀴의 번호
        // b:방향, 1이면 시계방향, -1이면 반시계방향
    }


    for(auto i : I){

        rotating(i[0], i[1]);

        // 왼쪽 기어들
        int dir = i[1];
        int contact = G[i[0]][6];
        for(int t = i[0]-1; t>=1 ; --t){
            if(!rotated(t, contact, "LEFT", -dir)) break;
            contact = G[t][6];
            dir *= -1;
        }

        // 오른쪽 기어들
        dir = i[1];
        contact = G[i[0]][2];
        for(int t = i[0]+1; t<=T ; ++t){
            if(!rotated(t, contact, "RIGHT", -dir)) break;
            contact = G[t][2];
            dir *= -1;
        }

        G = tempG;
        // debug();
    }
    int ans =0 ;
    for(auto g : G){
        ans += g[0];
    }

    cout << ans;
    


    return 0;
}