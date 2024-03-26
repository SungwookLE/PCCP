#include <bits/stdc++.h>

using namespace std;

#define threshold 3
#define distance_object_to_line 20

const int width = 300;
const int height = 300;
const double jump = 5;
const int start_x = 0;
const int start_y = 0;
const double start_hdAng = 0;

const int des_x = 250;
const int des_y = 250;
const double des_hdAng = 0;


struct Node {
    double x = 0;
    double y = 0;
    double hdAng =0;
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

double getRandomAng(){

    random_device random_device;
    mt19937 engine(random_device());
    normal_distribution<double> distribution(0, M_PI_2);

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

bool Sampling(Node* sample, tuple<double, double, double> randomPoint){

    double dist = 0.0;
    double towardAngle= M_PI_2, diffAngle = 0.0;
    double min_dist = 10*(width + height);

    int i = -1;
    int index = 0;
    sample->x = get<0>(randomPoint);
    sample->y = get<1>(randomPoint);

    sample->hdAng = get<2>(randomPoint);
    if(sample->hdAng > M_PI)  sample->hdAng = sample->hdAng - M_PI*2;
    else if (sample->hdAng < - M_PI)  sample->hdAng =  sample->hdAng + M_PI*2;

    for(auto node: nodeList){
        diffAngle = abs(node->hdAng - sample->hdAng);
        if (diffAngle > M_PI) diffAngle -= M_PI*2;
        else if (diffAngle < -M_PI) diffAngle += M_PI*2;
        diffAngle = abs(diffAngle);
        i++;
        
        if (diffAngle > M_PI/10) continue;

        dist = getDistance(node, sample);
        towardAngle = getAngle(node, sample);
        
        if (dist < min_dist){
            min_dist = dist;
            index = i;
            if (dist == 0 && diffAngle < M_PI/100) return false;
        }
    }
    sample->x = nodeList[index]->x + jump * cos(towardAngle);
    sample->y = nodeList[index]->y + jump * sin(towardAngle);
    // sample->hdAng ;
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
    ifstream fobject("object.txt"); // 정적 장애물
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
    }
    
    //////// 길찾기
    while(pathfound == false){
        here = new Node;

        auto distribution_X = getRandomPoint(width);
        auto distribution_Y = getRandomPoint(height);
        auto distribution_hdAng = getRandomAng();

        if(!Sampling(here, {distribution_X, distribution_Y, distribution_hdAng})){
            delete here;    
            continue;
        }
        if(collision(here)){
            delete here;
            continue;
        } 
        nodeList.push_back(here);
        fsample << here->x << ", " << here->y << ", " << here->hdAng*180.0/M_PI << "\n";
        cout << here->x << ", " << here->y << ", " << here->hdAng*180.0/M_PI << "\n";

        dist = getDistance(desNode, here);

        double diffAngle = abs(here->hdAng - desNode->hdAng);
        if (diffAngle > M_PI) diffAngle = diffAngle - M_PI*2;
        else if (diffAngle < -M_PI) diffAngle = diffAngle + M_PI*2;

        if(dist < 3 && abs(diffAngle) <= M_PI/10) pathfound = true;

    }
    fsample.close();
    cout << "Found!: " << nodeList.size() << endl;

    while(pathfound == true){

        if (here == nullptr) break;
        Node* tmpNode = here->parent;

        ftree << here->x << "," << here->y << ", " << here->hdAng*180.0/M_PI << "\n";
        here = here->parent;
    }

    ftree.close();
}