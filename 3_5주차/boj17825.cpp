#include <bits/stdc++.h>

using namespace std;

struct node{
    int nodeId;
    node* next[2];
    int score;
} Node[41];

vector<int> mal(4,0);
#define GOAL 21
vector<int> dice(10,0);

void makeNode(){

    Node[0].next[0] = &Node[1];

    for(int i = 1; i<=20; ++i){
        Node[i].nodeId = i;
        Node[i].score = i*2;
        Node[i].next[0] = &Node[i+1];
    }
    Node[GOAL].nodeId = GOAL;

    Node[5].next[1] = &Node[22];
    Node[22].score = 13;
    Node[22].next[0]  = &Node[23];
    Node[22].nodeId = 22;

    Node[23].score = 16;
    Node[23].next[0] = &Node[24];
    Node[23].nodeId = 23;

    Node[24].score = 19;
    Node[24].next[0] = &Node[25];
    Node[24].nodeId = 24;

    Node[25].score = 25;
    Node[25].next[0] = &Node[26];
    Node[25].nodeId = 25;

    Node[26].score = 30;
    Node[26].next[0] = &Node[27];
    Node[26].nodeId = 26;

    Node[27].score = 35;
    Node[27].next[0] = &Node[20];
    Node[27].nodeId = 27;


    Node[10].next[1] = &Node[28];
    Node[28].score = 22;
    Node[28].next[0] = &Node[29];
    Node[28].nodeId = 28;


    Node[29].score = 24;
    Node[29].next[0] = &Node[25];
    Node[29].nodeId = 29;


    Node[15].next[1] = &Node[30];
    Node[30].score = 28;
    Node[30].next[0] = &Node[31];
    Node[30].nodeId = 30;

    Node[31].score = 27;
    Node[31].next[0] = &Node[32];
    Node[31].nodeId = 31;

    Node[32].score = 26;
    Node[32].next[0] = &Node[25];
    Node[32].nodeId = 32;

}

int moveH(int now, int delta){
    int ret;
    auto s = &Node[now];

    bool init = true;
    while(delta>0){

        if (s->next[1] != NULL && init){
            s = s->next[1];
        }
        else if (s->next[0] != NULL){
            s = s->next[0];
        }

        if (s->nodeId == GOAL) break;
   
        delta--;
        init = false;
    }

    ret = s->nodeId;
    return ret;
}

bool isMal(int nodeId, int idx){
    if (nodeId ==GOAL) return false;
    for(int i =0 ; i < 4 ; ++i){
        if (i == idx) continue;
        if (mal[i] == nodeId) return true;
    }

    return false;

}

int go(int here){
    // 필요 로직: 말의 중복 체크
    // 말이 있을 경우, 원복 로직

    if (here == 10){
        return 0;
    }

    int ret = 0;

    for(int i =0 ; i < 4 ; ++i){
        int prev_nodeId = mal[i];
        int nodeId = moveH(prev_nodeId, dice[here]);
        if (isMal(nodeId, i)) continue;
        mal[i] = nodeId;
        ret  = max(ret, go(here+1) + Node[nodeId].score);
        mal[i] = prev_nodeId;
    }

    return ret;
}

int main(){
    makeNode();
    for(int i =0 ; i < 10 ; ++i) cin >> dice[i];

    cout << go(0);

    return 0;
}

