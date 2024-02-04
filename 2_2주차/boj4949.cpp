
#include <bits/stdc++.h>

using namespace std;

bool isFinder(char a){
    return (a=='[' || a ==']' || a=='(' || a==')');
}

int main()
{

    string s;
    while (getline(cin, s))
    {
        if (s==".")
            break;

        stack<char> checker;
        while(!s.empty()){

            if (isFinder(s.back())){

                if (checker.empty())
                    checker.push(s.back());
                else{
                    if (checker.top() == ']' && s.back() == '[')
                        checker.pop();
                    else if (checker.top() == ')' && s.back() == '(')
                        checker.pop();
                    else
                        checker.push(s.back());
                }
            }
            s.pop_back();
        }

        if (checker.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}