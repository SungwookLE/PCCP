#include <bits/stdc++.h>

using namespace std;

/*

MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 2
        for j <- i + 1 to n - 1
            for k <- j + 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
}


시간복잡도

(1)일 때    N-2회       --> (2)일 때, N-2회
                      --> (3)일 때, N-3회
                      --> (4)일 때, N-4회
                      ...
                      --> (N-1)일 때, 1회

(2)일 때    N-3회     --> (3)일 때, N-3회
                    ...
                    --> (N-1)일 때, 1회

...

*/

int main(){
    long long N;
    cin >> N;


    long long sum = 0;
    while(N>2){

        sum += (N-2)*(N-1)/2;
        N--;

    }

    cout << sum << endl<< 3;




    return 0;
}