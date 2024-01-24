#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> cstar(26, 0);

    int people;
    cin >> people;

    string answer = "";

    for (int i = 0; i < people; ++i)
    {

        string name;
        cin >> name;

        cstar[name[0] - 'a'] += 1;
    }

    for (int i = 0; i < cstar.size(); ++i)
    {

        if (cstar[i] >= 5)
            answer += i + 'a'; // (char)(i+(int)('a')); 주석과 해당 라인은 서로 같은 것이다. 아스키코드(숫자<->문자) 매핑됨.
    }

    if (answer.empty())
        cout << "PREDAJA\n";
    else
        cout << answer << "\n";

    return 0;
}