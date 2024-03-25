#include <bits/stdc++.h>

using namespace std;

#define threshold 3
#define distance_object_to_line 20

const int width = 300;
const int height = 300;
const double jump = 5;
const int start_x = 0;
const int start_y = 0;
const int des_x = 280;
const int des_y = 263;

struct Node {
    int x = 0;
    int y = 0;
    Node* parent = nullptr;
};

vector<Node*> nodeList;
vector<pair<int, int>> objectList;

double getRandomPoint(int size){

    random_device random_device;
    mt19937 engine(random_device());
    uniform_int_distribution<int> distribution(0.0, size);

    return distribution(engine);
}

double getDistance(Node* A, Node* B){
    return sqrt(pow(A->x - B->x, 2) + pow(A->y - B->y, 2));
}

double getDistance(pair<int, int>A, pair<int, int> B){
    return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

double getAngle(Node* Parent, Node* Child){
    return atan2(Child->y - Parent->y, Child->x - Parent->x);
}

bool Sampling(Node* sample, pair<double, double> randomPoint){

    double dist = 0.0;
    double angle= 0.0;
    double min_dist = 10*(width + height);

    int i = 0;
    int index = 0;
    sample->x = randomPoint.first;
    sample->y = randomPoint.second;

    for(auto node: nodeList){
        dist = getDistance(node, sample);

        if (dist < min_dist){
            min_dist = dist;
            index = i;
            angle = getAngle(node, sample);

            if (dist == 0){
                return false;
            }
        }
        i++;
    }
    sample->x = nodeList[index]->x + jump * cos(angle);
    sample->y = nodeList[index]->y + jump * sin(angle);
    sample->parent = nodeList[index];

    return true;
}

bool collision(Node* sample){

    Node* parent = sample->parent;
    double tmpDist;
    double lineGrad;
    double interceptY;
    double tmpX, tmpY;

    if ((sample->x - parent->x) != 0)
        lineGrad = (sample->y - parent->y) / (sample->x - parent->x);
    else lineGrad = 0;

    interceptY = (parent->y - lineGrad * parent->x);
    if (sample->x > width || sample->x < 0) return true;
    else if (sample->y > height || sample->y < 0) return true;
    else if ((sample->x - parent->x) == 0){

        for(auto obj : objectList){

            if (parent->y < sample->y){
                for(int y1 = parent->y; y1 <= sample->y; ++y1){

                    tmpX = parent->x;
                    tmpY = y1;
                    tmpDist = getDistance(obj, {tmpX, tmpY});
                    if (tmpDist < distance_object_to_line){
                        return true;
                    }
                }
            }
            else{
                for(int y1 = parent->y; y1 >= sample->y; --y1){

                    tmpX = parent->x;
                    tmpY = y1;
                    tmpDist = getDistance(obj, {tmpX, tmpY});
                    if (tmpDist < distance_object_to_line){
                        return true;
                    }
                }
            }
        }
    }
    else{

        for(auto obj: objectList){

            if (sample->x > parent-> x){

                for(int x1 = parent->x; x1 <= sample->x ; ++x1){

                    tmpX = x1;
                    tmpY = lineGrad * tmpX + interceptY;

                    tmpDist = getDistance(obj, {tmpX, tmpY});
                    if (tmpDist < distance_object_to_line) return true;
                }
            }
            else{
                for(int x1 = parent->x ; x1 >= sample->x; --x1){
                    tmpX = x1;
                    tmpY = lineGrad * tmpX + interceptY;

                    tmpDist = getDistance(obj, {tmpX, tmpY});
                    if (tmpDist < distance_object_to_line) return true;
                }
            }
        }
    }

    return false;
}

int main(){
    ifstream fobject("object.txt"); // 장애물
    ofstream fsample("sampling.txt"); // 생성된 샘플
    ofstream ftree("tree.txt"); // 찾은 경로

    Node* here = nullptr;
    double dist = 0;

    bool pathfound = false;
    Node* desNode = new Node;

    desNode->x = des_x;
    desNode->y = des_y;

    Node* rootNode = new Node;
    rootNode->x = start_x;
    rootNode->y = start_y;

    nodeList.push_back(rootNode);


    string line;
    while(getline(fobject, line)){
        istringstream iss(line);

        string X, Y;
        iss >> X >> Y;

        objectList.push_back({stoi(X), stoi(Y)});
        cout << X << ", " << Y << endl;
    }
    
    //////// 길찾기
    while(pathfound == false){

        here = new Node;

        auto distribution_X = getRandomPoint(width);
        auto distribution_Y = getRandomPoint(height);


        if(!Sampling(here, {distribution_X, distribution_Y})){
            delete here;    
            continue;
        }
        if(collision(here)){
            delete here;
            continue;
        } 
        nodeList.push_back(here);
        fsample << here->x << ", " << here->y << "\n";

        dist = getDistance(desNode, here);
        if(dist < 3) pathfound = true;
    }
    fsample.close();
    cout << "found!: " << nodeList.size() << endl;

    while(pathfound == true){

        if (here == nullptr) break;
        Node* tmpNode = here->parent;

        ftree << here->x << "," << here->y << "\n";
        dist = getDistance(here, rootNode);
        if (dist < 3) break;

        here = here->parent;
    }

    ftree.close();
}