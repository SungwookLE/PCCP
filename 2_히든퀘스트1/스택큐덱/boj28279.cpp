#include <bits/stdc++.h>

using namespace std;

deque<int> d;


int N;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    cin >> N;

    int n;
    for(int i =0 ; i < N ; ++i){
        cin >> n;
        switch (n)
        {
        case 1:
            cin >> n;
            d.push_front(n);
            break;
        
        case 2:
            cin >> n;
            d.push_back(n);
            break;

        case 3:
            if(d.size()) {
                cout << d.front() <<"\n";
                d.pop_front();
            }
            else cout << "-1\n";
            break;
        case 4:
            if(d.size()) {
                cout << d.back() <<"\n";
                d.pop_back();
            }
            else cout << "-1\n";
            break;
        
        case 5:
            cout << d.size() << "\n";
            break;
        
        case 6:
            cout << d.empty() << "\n";
            break;
        
        case 7:
            if (d.size()) cout << d.front() <<"\n";
            else cout << "-1\n";
            break;
        case 8:
            if (d.size()) cout << d.back() << "\n";
            else cout << "-1\n";
            break;
        }



    }


    return 0;
}