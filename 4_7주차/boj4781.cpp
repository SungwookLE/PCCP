#include <bits/stdc++.h>

using namespace std;

int n,m,p,q;
int Calory, Price;

vector<int> DP;

int main(){

    while(true){
        scanf("%d %d.%d", &n, &p, &q);
        
        if (n==0) break;

        m = p*100 + q;
        DP = vector<int>(100004,0);

        for(int j = 0; j < n ;++j){
            scanf("%d %d.%d", &Calory, &p, &q); // 포맷이 주어진 입력을 받을 때
            Price = p*100+q;

            for(int i = Price; i <= m ; ++i){
                DP[i] = max(DP[i], DP[i-Price] + Calory);
            }
        }
        cout << DP[m] << endl;
    }

    return 0;
}


{
    {
        {
            {
                {
                    {
                        {
                            [
                                [
                                    [
                                        {
                                            {
                                                {
                                                    {
                                                        {
                                                            {
                                                                {
                                                                    {
                                                                        {
                                                                            {
                                                                                {
                                                                                    {
                                                                                        {
                                                                                            {
                                                                                                
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    ]
                                ]
                            ]
                        }
                    }
                }
            }
        }
    }
}