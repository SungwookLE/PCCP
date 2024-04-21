#include <vector>
#include <iostream>
#include <map>

using namespace std;

int N, M, C;
vector<int> W, visited;
map<pair<vector<int>, vector<int>>, int> mp;

int go(int bag, int remain){


    if (bag == 0){
        return 0;
    }

    int& ret = mp[{visited, {bag, remain}}];
    if (ret) return ret;

    for(int i = 0 ; i < W.size(); ++i){
        if(visited[i] == 0){
            if (remain - W[i]>=0){
                visited[i] = 1;
                ret = max(ret, go(bag, remain-W[i])+1);
                visited[i] = 0;
            }
            else if (bag > 0){
                ret = max(ret, go(bag-1, C));
            }
        }
    }


    return ret;
}

int main(){
    cin >> N >> M >> C;
    W = vector<int>(N,0);
    visited = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i) cin >> W[i];

    cout << go(M, C);

    return 0;
}