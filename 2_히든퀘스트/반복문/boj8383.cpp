#include <bits/stdc++.h>

using namespace std;


int n ;


int sum(int n){


    if (n==1) return 1;
    
    int temp = sum(n-1) + n;

    return temp;

}


int main(){
    cin >> n;


    cout << sum(n);
    return 0;
}