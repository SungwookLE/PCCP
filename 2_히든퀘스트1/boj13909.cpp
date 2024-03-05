#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

    while(a%b){
        int mod = a %b;
        a = b;
        b = mod;
    }
    return b;

}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int N;
int main(){
    cin >> N;

    int ret =0;
    for(int i =1 ; i *i <= N; ++i)
        ret ++;
    cout << ret;

    return 0;
}