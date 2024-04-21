#include <bits/stdc++.h>

using namespace std;
int DP[101][101][101];

int W(int a, int b, int c){

    int&ret = DP[a+50][b+50][c+50];
    if (ret) return ret;

    if (a<=0 || b <=0 || c<=0) return ret=1;
    
    if (a>20 || b>20 || c>20) return ret=W(20,20,20);

    if ( a< b && b< c) return ret=W(a,b,c-1)+W(a,b-1,c-1) -W(a,b-1,c);

    return ret=W(a-1, b, c) + W(a-1, b-1, c) + W(a-1, b, c-1) - W(a-1, b-1, c-1);
}


int A,B, C;

int main(){
    while(true){
        cin >> A >> B >> C;
        if (A==-1 && B==-1 && C==-1) break;


        cout << "w(" << A << ", " << B << ", " << C <<") = " << W(A,B,C) << endl;

    }



    return 0;
}