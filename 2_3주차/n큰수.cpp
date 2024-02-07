#include <bits/stdc++.h>

using namespace std;

int n;
const int INF = 1E6;
int cnt;
int main()
{

    cin >> n;

    int i = 2400;
    for (;; i++) // while(true)
    {

        string a = to_string(i);
        if (a.find("2400") != string::npos)
        {
            cnt++;
            if ( n == cnt){
                cout << cnt << " : " << a << "\n";
                break; 
            }
        }
    }
    return 0;
}