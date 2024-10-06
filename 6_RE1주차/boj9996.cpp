#include <bits/stdc++.h>

using namespace std;

int N;
string pattern;


int main(){
    cin >> N ;
    cin >> pattern;

    int npos = pattern.find('*');
    string pfix, sfix;
    pfix = pattern.substr(0, npos);
    sfix = pattern.substr(npos+1);

    string cmp;
    for(int i =0 ; i < N ; ++i){
        cin >> cmp;

        if (cmp.size()>=pfix.size()+sfix.size()){

            if (cmp.substr(0,pfix.size()) == pfix &&
                cmp.substr(cmp.size()-sfix.size()) == sfix){
                    cout << "DA\n";
                }
            else{
                cout <<"NE\n";
            }

        }
        else{
            cout <<"NE\n";
        }


    }

  

    return 0;
}