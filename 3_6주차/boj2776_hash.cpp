#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for(int i =0 ; i < T ; ++i){
        unordered_map<int, int> dict; //map 은 정렬해서 값을 넣어주니까 시간초과했던 것임

        cin >> N;
        int a;
        for(int j =0 ; j < N ; ++j){
            cin >> a;
            dict[a] =1 ;
        }

        cin >> M;
        int b;
        for(int j =0 ; j < M ; ++j){
            cin >> b;
            if (dict[b] == 1) cout << "1\n" ;
            else cout << "0\n";
        }

    }



    return 0;
}