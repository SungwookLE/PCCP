#include <bits/stdc++.h>

using namespace std;
random_device rd;
mt19937 gen(rd());

int V[1000001];
int N;

void qSort(int A[], unsigned int L, unsigned int R){
    if (L>=R) return;

    uniform_int_distribution<int> dis(L, R); // 피봇을 랜덤하게 잡아야지만 O(NlogN)이 보장됨

    unsigned int i = L;
    unsigned int j = R;
    unsigned int Mid = dis(gen); // 원랜 (i+j)/2

    int Pivot = A[Mid];


    while (i <= j){
        // "<=" 조건으로 검사하는 것이 복잡도 측면에서 더 유리함
        // 왜냐면, i==j 시점에서 끝난 이후에 다음 재귀를 시작하게 되면 <i> 요소에 대해 중복으로 정렬을 수행하게 되는 것임
        while (A[i] < Pivot){
            i++;
        }

        while (Pivot < A[j]){
            j--;
        }

        if (i<=j){ // 반례: 7, 6, 5, 1, 2, 3, 4, 9 정렬에서 i<=j 조건이 없으면 안됨
                   // 이 조건으로 피봇이 움직였을 때에는 스왑하지 않게 됨
            if(i!=j){
                int T = A[i];
                A[i] = A[j];
                A[j] = T;
            }

            i++;
            if(j>0) j--;
            else break;
        }
    }

    if (i< R) qSort(A, i, R);
    if (L< j) qSort(A, L, j);

    return;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i =0 ; i < N ; ++i){
        cin >> V[i];
    }

    qSort(V, 0, N-1);

    for(int i =0 ; i < N ; ++i){
        printf("%d\n", V[i]);
    }

    return 0;
}