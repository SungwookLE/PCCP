#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

    while(a%b){

        int mod = a%b;
        
        a = b;
        b = mod;


    }
    return b;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}


int A, B, C, D;
int main(){
    cin >> A >> B;
    cin >> C >> D;

    int den = lcm(B,D);
    int multiplier1 = den/B;
    int multiplier2 = den/D;

    int num = A*multiplier1 + C*multiplier2;


    int common = gcd(den, num);

    cout << num/common << " "<< den/common ;



    return 0;
}