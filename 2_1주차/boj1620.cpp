#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 포켓몬의 개수와 문제의 개수
    cin >> N >> M;

    // 맵을 두개 만들어서 할것
    map<string, int> pockets1;  
    map<int, string> pockets2; 

    /*
     1. 맵을 두개 써야 한다.
     왜냐면, pockets 를 하나 써서, int 가 나오면 pockets.begin() + number 로 찾아가려고 했는데,
     맵같은 경우는 array와 다르게 순서대로 저장되는 형태가 아니기 떄문에 그래선 안된다.

     2. atoi(s.c_str()) 을 통과할 경우 int가 아닌 것들은 0이 리턴된다.
     이를 통해 int인지 아닌지 구분할 수 있다.
    */
    
    string ss;
    for (int i = 0; i < N; ++i)
    {
        cin >> ss;

        pockets1[ss] = i + 1;
        pockets2[i + 1] = ss;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> ss;
        int number = atoi(ss.c_str()); 
        
        if (number == 0)  // 문자라면,
            cout << pockets1[ss] << "\n";
        else
            cout << pockets2[number] << "\n";
    }

    return 0;
}