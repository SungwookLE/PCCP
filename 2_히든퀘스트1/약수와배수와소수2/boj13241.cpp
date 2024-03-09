#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B;


ll gcd(ll a, ll b){

    while(a%b){

        ll mod = a%b;

        a= b;
        b = mod;
    }

    return b;


}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

int main(){
    cin >> A >> B;
    cout << lcm(A,B);




    return 0;
}