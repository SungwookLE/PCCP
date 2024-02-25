#include <bits/stdc++.h>

using namespace std;

int M;


class oper{

    public:

        void add(int n){
            visited[n] = 1;
        }
        int check(int n){
            if (visited[n] == 1){
                return 1;
            }
            else return 0;
        }
        void remove(int n){
            if (visited[n] == 1){
                visited[n] = 0;
            }
        }
        void toggle(int n){
            if (visited[n] == 1) remove(n);
            else add(n);
        }
        void all(){
            visited = vector<int>(21,1);
        }
        void empty(){
            visited = vector<int>(21,0);
        }

    private:
        vector<int> visited = vector<int>(21,0);
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    oper machine;

    string s; int n;

    for(int i = 0; i < M ; ++i){

        cin >> s;
        if (s=="add"){
            cin >> n;
            machine.add(n);
        } 
        else if (s=="remove"){
            cin >> n;
            machine.remove(n);
        } 
        else if (s=="check"){
            cin >> n;
            cout << machine.check(n) <<"\n";
        } 
        else if (s=="toggle"){
            cin >> n;
            machine.toggle(n);
        } 
        else if (s=="all") machine.all();
        else if (s=="empty") machine.empty();

    }


    return 0;
}