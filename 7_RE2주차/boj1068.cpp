#include <bits/stdc++.h>

using namespace std;

int N, Node;
typedef struct Tree_st{
    Tree_st* Parent;
    vector<Tree_st*> Child;
} Tree;

Tree T[50];

int dfs(Tree *node){
    int ret =0 ;

    bool isEmpty = true;
    for(auto c : node->Child){
        if (c != nullptr){
            isEmpty=false;
            break;
        }
    }
    if (isEmpty) return 1;
    
    for(auto c : node->Child){
        if (c!=nullptr){
            ret += dfs(c);
        }
    }

    return ret;    
}

int main(){
    int root = 0;
    cin >> N;
    for(int i =0 ; i < N ; ++i){
        int num;
        cin >> num;

        if (num == -1){
            root = i;
            T[i].Parent = nullptr;
        }
        else{
            T[i].Parent = &T[num];
            T[num].Child.push_back(&T[i]);
        }
    }

    cin >> Node;
    if (Node == root){
        cout << 0 ;
    }
    else{
        if (T[Node].Parent){
            for(auto& c: T[Node].Parent->Child){
                if (c==&T[Node]) c=nullptr;
            }
            T[Node].Parent = nullptr;
        }
        for(auto& c : T[Node].Child){ c = nullptr; }

        int ans =0;
        ans = dfs(&T[root]);
        cout << ans;
    }
    return 0;
}