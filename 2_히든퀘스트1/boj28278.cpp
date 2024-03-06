#include <bits/stdc++.h>

using namespace std;

class customStack{

public:

    void push(int X){
        v.push_back(X);
        return;
    }

    int top_and_pop(){
        int ret = -1;
        if (v.size()){
            ret = v.back();
            v.pop_back();
        }
        return ret;
    }

    int size(){
        return v.size();
    }

    bool empty(){
        return v.empty();
    }

    int top(){
        int ret = -1;
        if (v.size()){
            ret = v.back();
        }
        return ret;
    }


private:
    vector<int> v; // 일부러 벡터로 하였음

};


int N;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    customStack cS;

    int n;
    for(int i = 0; i < N ; ++i){
        cin >> n;

        switch (n)
        {
        case 1:
            cin >> n;
            cS.push(n);
            break;
        case 2:
            cout << cS.top_and_pop() << "\n";
            break;
        case 3:
            cout << cS.size() << "\n";
            break;
        case 4:
            cout << cS.empty() << "\n";
            break;
        case 5:
            cout << cS.top() << "\n";
            break;
        }

    }



    return 0;
}