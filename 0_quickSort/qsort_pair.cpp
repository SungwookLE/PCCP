#include <iostream>
using namespace std;
// x는 내림차순 정렬하고, x가 같다면 y를 기준으로 오름차순

int A[100000][2];


void qSortPairKey(int (*V)[2], unsigned int L, unsigned int R)
{   
    if (L>=R) return; // 재귀호출할 때, 조건을 보고 호출하긴 하지만, 명확하게 기재해둔 기저 종료 조건임

    unsigned int i = L;
    unsigned int j = R;
    unsigned int mid = (i+j)/2;
    int PivotCompare1 = V[mid][0];
    int PivotCompare2 = V[mid][1];

    while (i <= j) // i==j 인 경우에도 한번 더 통과하게 해서 재귀호출시, i==j인 상황에 호출되지 않게 함으로서 시간을 좀 더 절약하기 위함
    {

        while ( V[i][0] > PivotCompare1 || ((V[i][0] == PivotCompare1) && (V[i][1] < PivotCompare2)) ){
            i++;
        }

        while ( PivotCompare1 > V[j][0] || ((V[j][0] == PivotCompare1) && (PivotCompare2 < V[j][1])) ) 
        {
            j--;
        }

        if (i <= j) // 피봇이 움직인 경우에는 swap 하지 않게 하기 위함
        {   
            if(i!=j){ 
                // swap
                int T[2] = {V[i][0], V[i][1]};
                V[i][0] = V[j][0];
                V[i][1] = V[j][1];
                V[j][0] = T[0];
                V[j][1] = T[1];
            }

            i++;
            if(j>0) j--;
            else break; // anti-underflow
        }
    }

    if (i<R) qSortPairKey(V, i, R);
    if (L<i) qSortPairKey(V, L, j);

    return;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0; j < 2; ++j) cin >> A[i][j];
    }

    qSortPairKey(A, 0, N-1);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 2; ++j) cout << A[i][j] << " ";
        cout << "\n";
    }
}
