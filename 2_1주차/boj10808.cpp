#include <bits/stdc++.h>

using namespace std;

// 카운팅스타~ 맵또는배열!
map<char, int> A;
int main()
{
    string input;
    cin >> input;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < alphabet.length(); ++i)
        A[alphabet[i]] = 0;

    for (int i = 0; i < input.length(); ++i)
        A[input[i]] += 1;

    for (auto item : A)
        cout << item.second << " ";

    return 0;
}

// 이걸 위처럼 푸는거보다 알파벳은 아스키코드로 되어 있으니까 배열을 쓰는게 더 낫겠읍니다.
// 아스키코드 ~> A: 65, a: 97

void solve()
{
    vector<int> v(25, 0);
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); ++i)
        v[input[i] - 'a'] += 1;

    for (auto val : v)
        cout << val << " ";

    return;
}