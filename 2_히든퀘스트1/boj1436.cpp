#include <bits/stdc++.h>

using namespace std;


int N;
int main(){
    cin >> N;

    for(int i = 666; ;i++){

        string cmp = to_string(i);
        if (cmp.find("666")!=string::npos){
            N--;
            if (N==0){ cout << cmp ; return 0;}
        }

        


    }





    return 0;
}