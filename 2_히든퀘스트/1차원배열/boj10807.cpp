#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;

    int a;

    int arr[201] = {0,};
    for(int i = 0 ; i < N ; ++i){
        cin >> a;
        arr[a+100] += 1;
    }
    int v;
    cin >> v;
    cout << arr[v+100];


    return 0;
}