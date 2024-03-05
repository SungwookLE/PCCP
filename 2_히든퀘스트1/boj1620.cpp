#include <bits/stdc++.h>

using namespace std;

int N, M;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    vector<string> names = vector<string>(N);
    map<string, int> m;

    string s;
    for(int i =0 ; i < N ; ++i){
        cin >> s;
        names[i] = s;
        m[s] = i+1;
    }


    for(int i =0 ; i < M ; ++i){
        cin >> s;

        if (s[0] >= '0' && s[0] <= '9'){
            cout << *(names.begin()+stoi(s)-1)<< "\n";
        }

        else{
            cout << m[s] <<"\n";
        }



    }



    return 0;
}