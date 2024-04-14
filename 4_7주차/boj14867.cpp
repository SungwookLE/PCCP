#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
#define INF 987654321

int visited[10001][10001];

int go (int now_a, int now_b, int a, int b, int c, int d, int cnt){
    int ret = INF;

    // cout << now_a << " " << now_b << endl;
    if (now_a == c && now_b == d){
        return cnt;
    }

    // fill A
    if (visited[a][now_b] == 0 && now_a != a){
        visited[a][now_b] = 1;
        ret = min(ret, go(a, now_b, a, b, c, d, cnt+1));
        visited[a][now_b] = 0;
    }

    // fill B
    if (visited[now_a][b] == 0  && now_a != b){
        visited[now_a][b] = 1;
        ret = min(go(now_a, b, a, b, c , d , cnt+1), ret);
        visited[now_a][b] = 0;
    }
    // move A->B
    int temp = b-now_b;
    if (visited[max(now_a-temp, 0)][min(b, now_a+now_b)] == 0 && now_a != 0){
        visited[max(now_a-temp, 0)][min(b, now_a+now_b)] = 1;
        ret = min(go(max(now_a-temp, 0), min(b, now_a+now_b), a, b, c, d, cnt+1), ret);
        visited[max(now_a-temp, 0)][min(b, now_a+now_b)] = 0;
    }

    // move B->A
    int temp2 = a-now_a;
    if (visited[min(a, now_a + now_b)][max(now_b-temp2, 0)] == 0 && now_b != 0){
        visited[min(a, now_a + now_b)][max(now_b-temp2, 0)]  = 1;
        ret = min(go(min(a, now_a + now_b), max(now_b-temp2, 0), a, b, c, d, cnt+1), ret);
        visited[min(a, now_a + now_b)][max(now_b-temp2, 0)]  = 0;
    }
    // Empty A
    if (visited[0][now_b] == 0 && now_a != 0){
        visited[0][now_b] = 1;
        ret = min(go(0, now_b, a, b, c, d, cnt+1), ret);
        visited[0][now_b] = 0;
    }

    // Empty B
    if (visited[now_a][0] == 0 && now_b != 0){
        visited[now_a][0] = 1;
        ret = min(go(now_a, 0, a, b, c, d, cnt+1), ret);
        visited[now_a][0] = 0;
    }

    return ret;
}



int main(){
    cin >> a >> b >> c >> d;

    int ret = go(0, 0, a, b, c, d, 0);
    if(ret>=INF) cout << -1;
    else cout << ret;

    return 0;
}