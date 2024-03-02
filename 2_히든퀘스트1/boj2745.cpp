#include <bits/stdc++.h>

using namespace std;

string S;
int B;
int main(){
    cin >> S >> B;


    int E = 1;
    int sum = 0;
    for(int i =S.size()-1 ; i >= 0; --i){

        int temp;
        if (S[i] >= 'A'){
            temp = int(S[i] - 'A' + 10);
        }
        else{
            temp = int(S[i]-'0');
        }

        sum += E*temp;



        E*= B;
    }

    cout << sum;




    return 0;
}