#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> V = {1, 1, 2, 2, 3, 3, 4};

    sort(V.begin(), V.end()); // 정렬을 먼저 해주어야 한다.
    auto it = unique(V.begin(), V.end()); // 중복되지 않은 요소로 앞을 채운 후 , 그 다음 이터레이터를 반환한다. 

    cout << it - V.begin() << "\n"; // 4

    // 앞에서부터 채운 후 중복된 요소들은 맨 뒤로 보내둔다 (지우지는 않음) 1,2,3,4,1,2,3
    for (int i : V)
        cout << i << " ";
    cout << "\n";

    // 지우고 싶으면 이렇게 지워야함
    V.erase(it, V.end());
    for (int i : V)
        cout << i << " ";
    cout << "\n";


    // 한 줄로 쓴다면
    V.erase(unique(V.begin(), V.end()), V.end());

    return 0;
}