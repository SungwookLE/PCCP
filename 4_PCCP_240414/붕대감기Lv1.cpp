#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int max_health = health;    

    int idx = 0;
    int cont = 0;
    for(int sec = 0 ; sec <= attacks.back()[0]; ++sec){



        if (sec == attacks[idx][0]){
            health -= attacks[idx][1];
            idx ++;
            cont = 0;
        }
        else{
            health += bandage[1];
            cont ++;

            if (cont == bandage[0]){
                health += bandage[2];
                cont = 0;
            }
            health = min(health, max_health);
        }


        if (health <= 0 ){
            answer =-1;
            break;
        }
        answer = health;
    }

    




    return answer;
}