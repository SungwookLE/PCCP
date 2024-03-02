#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    for(int i =0 ; i < T ; ++i){
        string s;
        cin >> s;

        cout << *s.begin() << *(s.end()-1) << "\n";



    }


    return 0;
}