#include <bits/stdc++.h>

using namespace std;

int N;
struct node{
    int id, v;
    node* prev_;
    node* next_;
} NODE[1002];

int main(){
    cin >> N;

    int n;
    for(int i =1 ; i <= N; ++i){
        cin >> n;
        NODE[i].v = n;
        NODE[i].id = i;
        NODE[i].prev_ = &NODE[i-1];
        NODE[i].next_ = &NODE[i+1];
    } 
    NODE[1].prev_ = &NODE[N];
    NODE[N].next_ = &NODE[1];

    node* cur = &NODE[1];

    while(1){
        cout << cur->id << " ";
        cur->next_->prev_ = cur->prev_; //실제로 삭제하지 않고도 삭제의 효과 (시간복잡도1)
        cur->prev_->next_ = cur->next_; //실제로 삭제하지 않고도 삭제의 효과 (시간복잡도1)

        if (cur->next_ == cur || cur->prev_ == cur) break;

        int mov = cur->v;

        if (mov > 0){
            while(mov--) cur = cur->next_;
        }
        else if (mov <0 ){
            while(mov++) cur = cur->prev_;
        }
    }
    
   
    return 0;
}