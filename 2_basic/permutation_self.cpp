#include <bits/stdc++.h>

using namespace std;
vector<int> V;

void print_V(){
    for(auto val: V)
        cout << val << " ";
    cout << endl;
}

void make_permutation(int n , int r, int depth){

    if ( r == depth ){
        print_V();
        return;
    }


    for(int i = depth ; i < n ; ++i){
        swap(V[i], V[depth]);
        make_permutation(n, r, depth+1);
        swap(V[i], V[depth]);
    }
}

int main(){

    int n, r;
    cin >> n >> r;
    V = vector<int>(n, 0);

    for(int i = 0 ; i < n ; ++i)
        cin >> V[i];


    make_permutation(n,r,0);



}