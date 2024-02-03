#include <bits/stdc++.h>

using namespace std;
vector<string> words;
bool isMoum(char in)
{
    return (in == 'a' || in == 'i' || in == 'e' || in == 'o' || in == 'u');
}

void recurse(int i, string append, bool rule1, bool rule2, bool rule3, const string word)
{

    if (append == word)
    {
        if (rule1 == true && rule2 == false && rule3 == false)
        {
            cout << "<" << word << ">"
                 << " is acceptable.\n";
            return;
        }
        else
        {
            cout << "<" << word << ">"
                 << " is not acceptable.\n";
            return;
        }
    }

    if (!rule1)
        if (isMoum(word[i]))
            rule1 = true;

    if (!rule2)
        if (i >= 2)
        {
            int count1 = 0, count2 = 0;

            for (int k = i; k > i - 3; --k) // 이 부분을 시간복잡도를 줄일수도 있겠음
            {
                if (isMoum(word[k]))
                    count1 += 1;
                else
                    count2 += 1;
            }

            if (count1 == 3 || count2 == 3)
                rule2 = true;
        }

    if (!rule3)
        if (i >= 1)
        {
            if (word[i - 1] == word[i])
            {
                if (word[i - 1] == 'e' || word[i - 1] == 'o')
                    ;
                else
                {
                    rule3 = true;
                }
            }
        }

    append += word[i];
    i += 1;
    recurse(i, append, rule1, rule2, rule3, word);

    return;
}

int main()
{

    string a;
    while (cin >> a)
    {
        if (a == "end")
            break;
        words.push_back(a);
    }

    for (auto word : words)
    {
        recurse(0, "", false, false, false, word);
    }

    return 0;
}