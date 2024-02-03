#include <bits/stdc++.h>

using namespace std;
int N;

vector<int> score(3, 0);
vector<int> timer(3, 0);

int main()
{

    cin >> N;

    int team;
    string input;
    int mm, ss;
    char delimeter;

    int startSS = 0, endSS = 48 * 60;
    int winTeam = 0, prevWinTeam = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> team;

        score[team]++;
        cin >> input;

        istringstream sss(input); // string parsing
        sss >> mm >> delimeter >> ss;
        // 입력 끝

        if (score[1] > score[2])
            winTeam = 1;
        else if (score[1] == score[2])
            winTeam = 0;
        else
            winTeam = 2;

        if (winTeam == 1 && prevWinTeam != 1)
        {
            startSS = mm * 60 + ss;
            // cout << "win1 start: " << startSS << endl;
        }
        else if (winTeam == 2 && prevWinTeam != 2)
        {
            startSS = mm * 60 + ss;
            // cout << "win2 start: " << startSS << endl;
        }
        else if (winTeam == 1 && prevWinTeam == 1)
        {
            timer[1] += mm * 60 + ss - startSS;
            // cout << "win1 hold: " << mm*60+ss << " " << startSS << endl;
            startSS = mm * 60 + ss;
        }
        else if (winTeam == 2 && prevWinTeam == 2)
        {
            timer[2] += mm * 60 + ss - startSS;
            // cout << "win2 hold: " << mm*60+ss << " " << startSS << endl;
            startSS = mm * 60 + ss;
        }
        else if (winTeam == 0 && prevWinTeam == 1)
        {
            timer[1] += mm * 60 + ss - startSS;
            // cout << "win1 hold: " << mm*60+ss << " " << startSS << endl;
            startSS = mm * 60 + ss;
        }
        else if (winTeam == 0 && prevWinTeam == 2)
        {
            timer[2] += mm * 60 + ss - startSS;
            // cout << "win2 hold: " << mm*60+ss << " " << startSS << endl;
            startSS = mm * 60 + ss;
        }

        prevWinTeam = winTeam;
    }

    if (prevWinTeam == 1)
    {
        timer[1] += endSS - startSS;
        // cout << "win1 hold: " << endSS << " " << startSS << endl;
    }
    else if (prevWinTeam == 2)
    {
        timer[2] += endSS - startSS;
        // cout << "win2 hold: " << endSS << " " << startSS << endl;
    }

    cout << setfill('0') << setw(2) << timer[1] / 60 << ":" << setw(2) << timer[1] % 60 << "\n";
    cout << setfill('0') << setw(2) << timer[2] / 60 << ":" << setw(2) << timer[2] % 60 << "\n";

    return 0;
}