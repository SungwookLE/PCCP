#include <bits/stdc++.h>
// 카운팅 트리

using namespace std;

int T;
int n, m; // 영화의 숫자와, 보려는 영화의 개수

vector<int> tree(200004,0);
map<int, int> mp;

void update(int idx, int value){
    while (idx <200004){
        tree[idx] += value;
        idx += (idx&-idx);
    }
}
int sum(int idx){
    int ret = 0;
    while (idx>0){
        ret += tree[idx];
        idx -= (idx&-idx);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for(int i =0 ; i < T; ++i){

        cin >> n >> m;
        int update_idx = 100001;
        mp.clear();
        tree = vector<int>(200004, 0);

        for(int i =1 ; i <= n ; ++i){
            // 위로 쌓는 과정에서 음수 인덱스로 접근할 수 가 없으니, 좌표 이동하였음
            update(i+update_idx, 1); 
            mp[i] = i + update_idx;
        }

        int temp;
        for(int i = 0 ; i < m; ++i){
            cin >> temp;
            int idx = mp[temp];
            cout << sum(idx) -1 << " ";
            update(idx, -1); 
            update(--update_idx, 1);
            mp[temp] = update_idx;
        }
        cout << "\n";
    }

    return 0;
}