#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> visited(26,0);
int main(){
    cin >> N;
    string s;

    int ret=0;
    for(int i =0 ;i < N ; ++i){

        cin >> s;

        visited[s[0]-'a'] = 1;

        for(int j = 1 ; j < s.size(); ++j){

            if (visited[s[j]-'a'] == 1){

                if ( s[j-1] != s[j] ){
                    ret+=1;
                    break;
                }

            }
            else{
                visited[s[j]-'a'] = 1;
            }

        }
        visited = vector<int>(26,0);


    }

    cout << N-ret ;



    return 0;
}