#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);
    arr[1] = 3; // 초항

    for (int i = 2; i <= N; ++i)
        arr[i] = arr[i - 1] * 2 - 4; // 점화식

    cout << arr[N] << endl;

    return 0;
}