#include <bits/stdc++.h>

using namespace std;

int N;
int min_A=10001, max_A=-10001, min_B=10001, max_B=-10001;

int main(){
    cin >> N;

   
    int A, B;
    for(int i =0 ; i < N ;++i){
        cin >> A >> B;
        min_A = min(A, min_A);
        min_B = min(B, min_B);
        max_A = max(A, max_A);
        max_B = max(B, max_B);
    }

    cout << (max_A-min_A)*(max_B-min_B);




    return 0;
}