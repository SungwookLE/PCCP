#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> a = {1,2,3,0};
    sort(a.begin(), a.end()); // 항상 정렬이 되어 있어야 함
    for(auto aa: a)
        cout << aa << " ";
    cout << endl;

    while (next_permutation(a.begin(), a.end())){

        for(auto aa : a)
            cout << aa << " ";
        cout << endl;

    }

    /* 아래 코드가 더 낫겟네
    
    do{
        for(auto aa : a)
            cout << aa << " " ;
        cout << endl;
        
    }while(next_permutation(a.begin(), a.end()));
    // 또는, (next_permutation(&a[0], &a[0]+3)) , a 가 raw array 라면
    
    */


}