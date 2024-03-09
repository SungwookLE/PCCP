#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> input;
    for (int i =0 ; i < n ; ++i){
        int num;
        cin >> num;
        input.push_back(num);
    }
    vector<int> sorted_input = input;

    sort(sorted_input.begin(), sorted_input.end(), [](int a, int b){
        if (a<b)
            return true;
        else
            return false;
    });

    sorted_input.erase(unique(sorted_input.begin(), sorted_input.end()), sorted_input.end());

    for(int i =0 ; i < input.size() ; ++i){
        int pos = lower_bound(sorted_input.begin(), sorted_input.end(), input[i]) - sorted_input.begin();
        cout << pos << " ";
    }

    return 0;
}