#include <bits/stdc++.h>

using namespace std;

int A, B, C;

int main(){
    cin >> A >> B>> C;

    if (A+B+C != 180) cout <<"Error";
    else{

        if (A==60 && B==60) cout<< "Equilateral";
        else if (A==B || A==C || B==C) cout << "Isosceles";
        else cout << "Scalene";



    }


    return 0;
}