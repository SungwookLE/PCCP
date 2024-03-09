#include <bits/stdc++.h>

using namespace std;

int n;

map<string, int, greater<string>> m;
int main(){
    cin >> n;

    string name, record;
    for(int i =0 ; i < n ; ++i){


        cin >> name >> record;

        if (record == "enter") m[name] = 1;
        else m[name] = 0;

    }


    for(auto it = m.begin(); it != m.end(); ++it){

        if (it->second == 1) cout << it->first << "\n";

    }







    return 0;
}