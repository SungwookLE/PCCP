#include <bits/stdc++.h>

using namespace std;

int main(){


    string s ;
    getline(cin, s);

    int alphabet_length = 26;
    int rot13 = 13;

    for(int i = 0 ; i < s.length(); ++i){


        if(s[i] >= 'A' && s[i] <= 'Z'){
            // 대문자
            s[i] = (s[i]-'A' + rot13)%alphabet_length + 'A';

        }
        else if( s[i] >= 'a' && s[i] <= 'z'){
            // 소문자
            s[i] = (s[i]-'a' + rot13)%alphabet_length + 'a';

        }
        else{
            // 그렇지 않은 문자
            ;
        }

    }

    cout << s << "\n";



    return 0;
}