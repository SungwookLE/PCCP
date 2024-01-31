#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> deltas = {
    {1, 0},
    {0, 1},
    {1, 1}};
int N ;
vector<vector<int>> datas;



int main()
{

    cin >> N;
    datas = vector<vector<int>>(N, vector<int>(N,0));

    string s;
    for(int i = 0; i < N ; ++i){
        cin >> s;

        for(int j =0 ; j < N; ++j){
            datas[i][j] = s[j]-'0';
        }
    }

    for(auto d : datas){
        for(auto dd : d){
            cout << dd ;
        }
        cout << endl;
    }


    // (8, 8) -> (4, 4) * 4개 -> (2, 2) -> 16개

    vector<int> answer;

    
   



    return 0;
}