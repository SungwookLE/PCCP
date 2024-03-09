#include <bits/stdc++.h>

using namespace std;

deque<int> q;

int N;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> N;

    string o;
    int n ; 

    for(int i =0 ; i < N ; ++i){
        cin >> o;

        if (o=="push"){
            cin >> n;
            q.push_back(n);
        }
        
        else if (o=="front"){
            if (q.size()) cout << q.front()<< "\n";
            else cout << -1 << "\n";
        }

        else if (o=="pop"){
            if (q.size()){
                cout << q.front() << "\n";
                q.pop_front();
            } 
            else cout << -1 << "\n";
        }

        else if (o=="size"){
            cout << q.size() << "\n";
        }

        else if (o=="empty"){
            cout << q.empty() <<"\n";
        }

        else if (o=="back"){
            if(q.size()) cout << q.back() << "\n";
            else cout << -1 << "\n";
        }

    }



    return 0;
}