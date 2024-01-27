#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;

    int is_odd = 0;
    char center_candidate = 0; // 문자 초기화 (아스키 NUL)
    string ret ="";

    vector<char> cstar(5000, 0);
    for(auto c: s) cstar[c] += 1;

    for(int i = 'Z'; i >= 'A'; --i){
        if (cstar[i] % 2 == 1){
            center_candidate = char(i);
            cstar[i]-=1; is_odd+=1;
        }
        if (is_odd >= 2) break;
        for(int j = 0 ; j < cstar[i] ; j += 2){
            // ret.insert(ret.begin(), (char)i);
            ret = char(i) + ret;
            ret += char(i);
        }
    }
    if (center_candidate) ret.insert(ret.begin() + ret.size()/2, center_candidate);
    if(is_odd >=2 ) cout << "I'm Sorry Hansoo\n" ;
    else cout << ret << "\n";    


}