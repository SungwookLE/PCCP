#include <bits/stdc++.h>

using namespace std;

int N;

int mx = -1000001;
int mn = 1000001;


int main(){
    cin >> N;

    int num;
    for(int i = 0 ; i < N ; ++i){
        cin >> num;

        if (num > mx) mx = num;

        if (num < mn) mn = num;



    }
    cout << mn << " " << mx ;


    return 0;
}