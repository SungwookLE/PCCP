#include <bits/stdc++.h>

using namespace std;

string s;
int main(){
    cin >> s;

    vector<int> v(26,0);
    for(int i = 0 ; i < s.size(); ++i){

        if (s[i]>='a') v[s[i]-'a'] +=1;
        else if (s[i] >='A') v[s[i]-'A'] += 1;

    }


    bool duplicated = false;
    int ret = 0;
    int idx = 0;
    for(int i =0 ; i < v.size(); ++i){

        if (ret < v[i]){
            ret = v[i];
            idx =i;
            duplicated=false;
        }
        else if (ret == v[i]){
            duplicated = true;
        }

    }

    if(duplicated) cout << "?";
    else cout << char(idx+'A');
    


    return 0;
}