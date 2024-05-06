#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<long long> A;
vector<long long> tree;

void update(vector<long long>&tree, int i, long long diff){
    while ( i < tree.size() ){
        tree[i] += diff;
        i += (i&-i);
    }
}

long long sum(vector<long long>&tree, int i){
    long long ans = 0;
    while (i > 0){
        ans += tree[i];
        i -= (i&-i);
    }
    return ans;
}

int main(){

    cin >> N >> M >> K;
    A = vector<long long>(N+1,0);
    tree = vector<long long>(N+1,0);

    for(int i =1 ; i <= N ; ++i){
        cin >> A[i];
        update(tree, i, A[i]);
    } 

    long long a, b, c;
    for(int i = 1; i <= M+K; ++i){
        cin >> a >> b >> c;

        if(a==1){
            long long diff = c-A[b];
            A[b] = c;
            update(tree, b, diff);
        }
        else if(a==2){
            cout << sum(tree, c) - sum(tree, b-1) << endl;
        }
    }


    return 0;
}