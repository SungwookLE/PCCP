#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int bill;
    cin >> bill;

    vector<int> coins(bill + 1, -1);

    coins[3] = 1;
    coins[5] = 1;

    for (int i = 6; i <= bill; ++i)
    {
        if ((coins[i - 3] != -1) && (coins[i - 5] != -1))
        {
            coins[i] = min(coins[i - 3], coins[i - 5]) + 1;
        }
        else if (coins[i - 3] != -1 || coins[i - 5] != -1)
            coins[i] = max(coins[i - 3], coins[i - 5]) + 1;
    }

    cout << coins[bill] << endl;

    return 0;
}