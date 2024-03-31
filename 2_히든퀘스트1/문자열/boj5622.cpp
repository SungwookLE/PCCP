#include <bits/stdc++.h>

using namespace std;

string S;
map<char, int> m;

int main(){
    
    m['A'] = 2;
    m['B'] = 2;
    m['C'] = 2;
    m['D'] = 3;
    m['E'] = 3, 
    m['F'] = 3;
    m['G'] = 4;
    m['H'] = 4;
    m['I'] = 4;
    m['J'] = 5;
    m['K'] = 5;
    m['L'] = 5;
    m['M'] = 6;
    m['N'] = 6;
    m['O'] = 6;
    m['P'] = 7;
    m['Q'] = 7;
    m['R'] = 7;
    m['S'] = 7;
    m['T'] = 8;
    m['U'] = 8;
    m['V'] = 8;
    m['W'] = 9;
    m['X'] = 9;
    m['Y'] = 9;
    m['Z'] = 9;


    
    cin >> S;




    int sum =  0;
    for(int i = 0; i < S.size(); ++i){

        sum += m[S[i]]+1;

    }
    cout << sum ;

    return 0;
}