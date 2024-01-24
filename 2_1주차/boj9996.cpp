#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N;
    cin >> N;
    string pattern;
    cin >> pattern;

    int pos = pattern.find("*");
    string pre, suf;
    pre = pattern.substr(0,pos);
    suf = pattern.substr(pos+1);


    for (int i = 0; i < N; ++i)
    {

        string s;
        cin >> s;   

        if (pre.length() + suf.length() > s.length()){
            cout << "NE\n";
            continue;
        }

        if (pre == s.substr(0, pre.length()) && suf == s.substr(s.length() - suf.length()))
            cout << "DA\n";
        else
            cout << "NE\n";
       
    }

    return 0;
}