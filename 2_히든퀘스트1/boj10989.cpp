#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;
    
    cin.tie(NULL);
    cout.tie(NULL);


    vector<int> v(10001,0);

    int num;
    for(int i = 0; i < N ; ++i){
        cin >> num;
        v[num] += 1;
    }

    for(int i = 1 ; i < 10001; ++i){

        while (v[i] != 0){
            cout << i << "\n";
            v[i] -=1;
        }

    }


    return 0;
}