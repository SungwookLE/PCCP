#include <bits/stdc++.h>
using namespace std;


int N;
int arr[26];

int main(){
    cin >> N;

    string name;    
    for(int i =0 ; i < N ; ++i){
        cin >> name;
        arr[name[0]-'a']++;
    }

    bool flg = false;

    for(int i =0 ; i < 26; ++i){

        if(arr[i] >= 5){
            cout << (char)(i+'a');
            flg = true;
        }

    }

    if (!flg){
        cout << "PREDAJA";
    }






    return 0;
}