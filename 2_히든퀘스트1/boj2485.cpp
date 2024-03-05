#include <bits/stdc++.h>

using namespace std;

int N;

int gcd(int a, int b){


    while(a%b){

        int mod = a%b;
        
        a=b;
        b=mod;


    }
    return b;
}


int main(){
    cin >> N;
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> m;
    vector<int> n(N,0);
    vector<int> d(N-1,0);

    int prev_n;
    for(int i= 0 ; i < N ; ++i){
        cin >> n[i];
        m[n[i]] = 1;

        if(i>=1) d[i-1] = n[i]-prev_n;
        prev_n = n[i];
    }


    int g = d[0];
    for(int i = 0 ; i < N-1; ++i){
        g = gcd(d[i],g);
    }

    int ans = (n.back()-n.front())/g-(N-1);

    cout << ans;



}