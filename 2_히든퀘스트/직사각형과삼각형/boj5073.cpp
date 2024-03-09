#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int main(){



    while(cin >> A >> B >> C){


        if(A==0 && B==0 && C==0) break;

        if (A<B){
            int temp = A;
            A = B;
            B = temp;
        }
        if (A<C){
            int temp = A;
            A = C;
            C = temp;
        }
        if (B<C){
            int temp = B;
            B = C;
            C = temp;
        }


        if (A==B && A==C) cout << "Equilateral\n";
        else{
            if (A >= (B+C)) cout << "Invalid\n";
            else{
                if (A==B || A==C || B==C) cout << "Isosceles\n";
                else cout << "Scalene\n";
            }
        }
    }



    return 0;
}