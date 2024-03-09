#include <bits/stdc++.h>

using namespace std;



/*

MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        for j <- 1 to n
            sum <- sum + A[i] × A[j]; # 코드1
    return sum;
}

*/

// 시간복잡도 O(N^2)


int main(){
    long long N;
    cin >> N;

    cout << (long long)(N*N) << "\n" << 2 ;


    return 0;
}