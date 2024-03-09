#include <bits/stdc++.h>

using namespace std;

int X;
int main(){
    cin >> X;

    int n = 1;
    int div = n*(n+1)/2;


    while(X>div){

        n++;
        div = n*(n+1)/2;

    }

    int num, den;
    if (n%2==0){
        // 짝수

        den = n;
        num = 1;

        div -= n;
        
        for(int i =1 ; i < X-div; ++i){

            den--;
            num++;

        }

        cout << num << "/" << den ;


    }
    else{
        // 홀수

        num = n;
        den = 1;

        div -= n;

        for(int i =1 ; i < X-div; ++i){

            num--;
            den++;
            
        }
        cout << num << "/" << den ;



    }


  

    return 0;

}