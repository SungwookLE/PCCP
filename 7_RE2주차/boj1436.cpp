#include <bits/stdc++.h>

using namespace std;

int N;


int main(){
    cin >> N;

    N--;
    long long cmp = 666;



    while(N){

        cmp ++;
        string str = to_string(cmp);
        auto it = str.find("666");
        if (it > str.size()){
            ;
        }
        else{
            N--;
        }
    }

    cout << cmp << "\n";


    return 0;
}