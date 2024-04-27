#include <iostream>
using namespace std;

// boj11650, x먼저 정렬 후 y

int A[100000][2];


void qSort_byPairKey(int (*V)[2], unsigned int L, unsigned int R)
{   
    if (L>=R) return;

    unsigned int i = L;
    unsigned int j = R;
    unsigned int mid = (i+j)/2;
    int PivotCompare1 = V[mid][0];
    int PivotCompare2 = V[mid][1];

    while (i <= j)
    {

        while ( V[i][0] < PivotCompare1 || ((V[i][0] == PivotCompare1) && (V[i][1] < PivotCompare2)) ){
            i++;
        }

        while ( PivotCompare1 < V[j][0] || ((V[j][0] == PivotCompare1) && (PivotCompare2 < V[j][1])) ) 
        {
            j--;
        }

        if (i <= j)
        {   
            if(i!=j){
                int T[2] = {V[i][0], V[i][1]};
                V[i][0] = V[j][0];
                V[i][1] = V[j][1];
                V[j][0] = T[0];
                V[j][1] = T[1];
            }

            i++;
            if(j>0) j--;
            else break;
        }
    }

    if (i<R) qSort_byPairKey(V, i, R);
    if (L<i) qSort_byPairKey(V, L, j);

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

    qSort_byPairKey(A, 0, N-1);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 2; ++j) cout << A[i][j] << " ";
        cout << "\n";
    }
}
