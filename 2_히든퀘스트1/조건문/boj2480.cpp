#include <bits/stdc++.h>

using namespace std;


int a, b, c;
int v[7];
int main(){

    cin >> a >> b >> c;
    v[a] += 1;
    v[b] += 1;
    v[c] += 1;


    int ret  = 0 ;
    for(int i = 6 ; i >= 1 ; --i){

        if ( v[i] == 1){
            if (ret < i*100) ret = i*100;
        } 
        else if (v[i] == 2){
        ret = (1000 + i*100);
        break;
        } 
        else if (v[i] == 3){
        ret = (10000 + i * 1000);
        break;
        }
    }

    cout << ret ;

    return 0;
}