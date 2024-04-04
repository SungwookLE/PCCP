#include <bits/stdc++.h>

using namespace std;

int T;
int n;

// n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.

vector<set<vector<int>>> DP;

int main(){

    cin >> T;
    for(int i =0 ; i < T ; ++i){
        

        cin >> n;
        DP = vector<set<vector<int>>>(n+1);
        DP[1].insert({1});

        for(int i = 2; i <= n ; ++i){
            
            auto it = DP[i-1].begin();
            while(it != DP[i-1].end()){

                vector<int> temp = *it;
                temp.push_back(1);
                DP[i].insert(temp);

                temp.pop_back();
                if (*temp.rbegin()+1 <= 3){
                    *temp.rbegin()= *temp.rbegin()+1;

                    DP[i].insert(temp);
                }

                it++;
            }
        }

        for(auto d : DP[n]){
            for(auto v: d){
                cout << v << " ";
            }
            cout << endl;

        }

        cout <<DP[n].size() << endl;





    }



    return 0;
}