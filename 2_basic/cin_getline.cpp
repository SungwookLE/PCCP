#include <iostream>
#include <string>

using namespace std;

int T;
string s;
int main(){

    // 1.  가장 기본적인 입력 받는 법
    string a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    // 2. cin은 개행문자를 기준으로 tokenizing 된다. 따라서 문장 전체를 가져오려면
    string b;
    getline(cin, b);

    // 3. getline은 문장 전체를 가져오게 하려고 개행문자도 문자로 인식해서 가져오는데, 이런 경우 아래 예제와 같이 T(예를 들어 3개)의 문장을 가져오려고 할때 T 입력받을 때 뒤에 남아있는 개행문자를
    //      하나의 라인으로 인식해서 받아오게 되는 문제가 있다. 이걸 해소시켜주려면 `getline(cin, bufferflust)` 처럼 개행문자를 날려주고 받아야한다.
    cin >> T;
    string bufferflush;
    getline(cin , bufferflush); // T를 받아올 때 남아있는 개행문자를 날려주는 것

    for(int i = 0 ; i < T; ++i){
        getline(cin, s); 
        cout << s << "\n";
    }
    return 0;
}