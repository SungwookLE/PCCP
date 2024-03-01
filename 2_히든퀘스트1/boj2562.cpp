#include <bits/stdc++.h>

using namespace std;

int mx = 0;
int main(){

    int num;
    int idx = 0;
    for(int i = 0; i < 9 ; ++i){
        cin >> num;

        if (mx < num){
            mx = num;
            idx = i;
        }
        


        
    }

    cout << mx << endl << idx+1 << endl;


    return 0;
}