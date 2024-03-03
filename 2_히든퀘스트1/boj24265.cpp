#include <bits/stdc++.h>

using namespace std;

/*

MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 1
        for j <- i + 1 to n
            sum <- sum + A[i] × A[j]; # 코드1
    return sum;
}




(1)일 때    (N-1)회 
(2)일 때    (N-2)회
(3)일 때    (N-3)회 
...
(N-1)일 때  (1)회 


시간복잡도 O((N-1)*N/2) 회



*/

int main(){

    long long N ;
    cin >> N;
    cout << (N-1)*N/2 << endl << 2;





    return 0;
}