#include <bits/stdc++.h>

using namespace std;
int N;

int A, B, o;
int Asum, Bsum;
string s;
string prevTime = "00:00";

int changeToInt(string a)
{
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

string print(int a)
{
    string d = "00" + to_string(a / 60);
    string e = "00" + to_string(a % 60);

    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

void duration(int &sum, string a)
{
    sum += changeToInt(a) - changeToInt(prevTime);
}

int main()
{

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> o >> s;
        if (A > B)
            duration(Asum, s);
        if (B > A)
            duration(Bsum, s);
        o == 1 ? A++ : B++;

        prevTime = s;
    }

    if (A > B)
        duration(Asum, "48:00");
    if (B > A)
        duration(Bsum, "48:00");

    cout << print(Asum) << endl;
    cout << print(Bsum) << endl;

    return 0;
}