#include <bits/stdc++.h>

using namespace std;
string S;
int arr[26] = {0,};

int main(){
    cin >> S;

    for(int i =0 ; i < S.size(); ++i){

        arr[S[i]-'a'] ++;

    }

    for (int i =0 ; i < 26 ; ++i){
        cout << arr[i] << " ";
    }
    


    return 0;
}