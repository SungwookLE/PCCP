#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> A;
int main(){
    cin >> N;   A =vector<int>(N,0);
    for(int i =0 ; i < N ; ++i) cin >> A[i];
    cin >> X;

    sort(A.begin(), A.end());

    vector<int>::iterator s = A.begin();
    auto e = A.end()-1;

    int ret = 0;
    while (s<e){

        if (*s+*e == X){
            s++;
            e--;
            ret++;
        }
        else if (*s+*e > X){
            e--;
        }
        else{
            s++;
        }
    }
    
    cout << ret;

    return 0;
}