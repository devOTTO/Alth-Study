
//5373 큐빙
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int tc;
vector<pair<char,char>> vec;

class side {
public:
    char arr[3][3];
public:
    void right(){
        char temp[3][3];
        for(int i = 0; i<3; ++i)
            for(int j = 0; j<3; ++j)
                temp[i][j] = arr[i][j];

        arr[0][0] = temp[2][0];
        arr[0][1] = temp[1][0];
        arr[0][2] = temp[0][0];
        arr[1][0] = temp[2][1];
        arr[1][2] = temp[0][1];
        arr[2][0] = temp[2][2];
        arr[2][1] = temp[1][2];
        arr[2][2] = temp[0][2];
    }
    void left(){
        char temp[3][3];
        for(int i = 0; i<3; ++i)
            for(int j = 0; j<3; ++j)
                temp[i][j] = arr[i][j];

        arr[0][0] = temp[0][2];
        arr[0][1] = temp[1][2];
        arr[0][2] = temp[2][2];
        arr[1][0] = temp[0][1];
        arr[1][2] = temp[2][1];
        arr[2][0] = temp[0][0];
        arr[2][1] = temp[1][0];
        arr[2][2] = temp[2][0];
    }
    void init(char c){
        for(int i = 0; i<3; ++i)
            for(int j = 0; j<3; ++j)
                arr[i][j] = c;
    }

};

side fArr, bArr, uArr, lArr, rArr, dArr;

void init(){
    fArr.init('r');
    bArr.init('o');
    uArr.init('w');
    lArr.init('g');
    rArr.init('b');
    dArr.init('y');
}

void LMinus() {
    int j = 0;
    char temp[3];
    lArr.left();
    for(int i = 0; i<3; ++i){
        temp[i] = bArr.arr[2-i][j];
        bArr.arr[2-i][j] = uArr.arr[i][j];
        uArr.arr[i][j] = fArr.arr[i][j];
        fArr.arr[i][j] = dArr.arr[i][j];
        dArr.arr[i][j] = temp[i];
    }

}

void LPlus(){
    int j = 0;
    char temp[3];
    lArr.right();
    for(int i = 0; i<3; ++i){
        temp[i] = uArr.arr[i][j];
        uArr.arr[i][j] = bArr.arr[2-i][j];
        bArr.arr[2-i][j] = dArr.arr[i][j];
        dArr.arr[i][j] = fArr.arr[i][j];
        fArr.arr[i][j] = temp[i];
    }
}

void RMinus(){
    int j = 2;
    char temp[3];
    rArr.left();
    for(int i = 0; i<3; ++i){
        temp[i] = uArr.arr[i][j];
        uArr.arr[i][j] = bArr.arr[2-i][j];
        bArr.arr[2-i][j] = dArr.arr[i][j];
        dArr.arr[i][j] = fArr.arr[2-i][j];
        fArr.arr[2-i][j] = temp[i];
    }
}

void RPlus() {
    int j = 2;
    char temp[3];
    rArr.right();
    for(int i = 0; i<3; ++i){
        temp[i] = bArr.arr[2-i][j];
        bArr.arr[2-i][j] = uArr.arr[i][j];
        uArr.arr[i][j] = fArr.arr[i][j];
        fArr.arr[i][j] = dArr.arr[i][j];
        dArr.arr[i][j] = temp[i];
    }

}

void UPlus() {
    int i = 0;
    char temp[3];
    uArr.right();
    for(int j = 0; j<3; ++j){
        temp[j] = bArr.arr[i][j];
        bArr.arr[i][j] = lArr.arr[i][j];
        lArr.arr[i][j] = fArr.arr[i][j];
        fArr.arr[i][j] = rArr.arr[i][j];
        rArr.arr[i][j] = temp[j];
    }
}


void UMinus() {
    int i = 0;
    char temp[3];
    uArr.left();
    for(int j = 0; j<3; ++j){
        temp[j] = bArr.arr[2-i][j];
        bArr.arr[i][2-j] = rArr.arr[i][j];
        rArr.arr[i][j] = fArr.arr[i][j];
        fArr.arr[i][j] = lArr.arr[i][j];
        lArr.arr[i][j] = temp[j];
    }
}

void DPlus() {
    int i = 2;
    char temp[3];
    dArr.right();
    for(int j = 0; j<3; ++j){
        temp[j] = bArr.arr[2-i][j];
        bArr.arr[i][2-j] = rArr.arr[i][j];
        rArr.arr[i][j] = fArr.arr[i][2-j];
        fArr.arr[i][2-j] = lArr.arr[i][j];
        lArr.arr[i][j] = temp[j];
    }
}

void DMinus() {
    int i = 2;
    char temp[3];
    dArr.left();
    for(int j = 0; j<3; ++j){
        temp[j] = bArr.arr[i][j];
        bArr.arr[i][j] = lArr.arr[i][2-j];
        lArr.arr[i][2-j] = fArr.arr[i][j];
        fArr.arr[i][j] = rArr.arr[i][2-j];
        rArr.arr[i][2-j] = temp[j];
    }
}

void FPlus() {
    int i = 0;
    int k = 2;
    char temp[3];
    fArr.right();
    for(int j = 0; j<3; ++j){
        temp[j] = uArr.arr[k][2-j];
        uArr.arr[k][2-j] = lArr.arr[k][j];
        lArr.arr[k][j] = dArr.arr[i][2-j];
        dArr.arr[i][2-j] = rArr.arr[j][i];
        rArr.arr[j][i] = temp[j];
    }
}

void FMinus() {
    int i = 0;
    int k = 2;
    char temp[3];
    fArr.left();
    for(int j = 0; j<3; ++j){
        temp[j] = uArr.arr[k][2-j];
        uArr.arr[k][2-j] = rArr.arr[j][i];
        rArr.arr[j][i] = dArr.arr[i][j];
        dArr.arr[i][j] = lArr.arr[k][j];
        lArr.arr[k][j] = temp[j];
    }
}

void BPlus() {
    int i = 0;
    int k = 2;
    char temp[3];
    bArr.right();
    for(int j = 0; j<3; ++j){
        temp[i] = uArr.arr[i][2-j];
        uArr.arr[i][2-j] = rArr.arr[2-j][k];
        rArr.arr[2-j][k] = dArr.arr[k][j];
        dArr.arr[k][j] = lArr.arr[i][j];
        lArr.arr[i][j] = temp[i];
    }
}

void BMinus() {
    int i = 0;
    int k = 2;
    char temp[3];
    bArr.left();
    for(int j = 0; j<3; ++j){
        temp[j] = uArr.arr[i][j];
        uArr.arr[i][j] = lArr.arr[i][2-j];
        lArr.arr[i][2-j] = dArr.arr[k][2-j];
        dArr.arr[k][2-j] = rArr.arr[j][k];
        rArr.arr[j][k] = temp[j];
    }
}

void solution(){

    for(int i = 0; i<vec.size(); ++i)
    {
        switch(vec[i].first) {
            case 'L':
                if (vec[i].second == '+')
                    LPlus();
                else
                    LMinus();
                break;
            case 'F':
                if (vec[i].second == '+')
                    FPlus();
                else
                    FMinus();
                break;
            case 'B':
                if (vec[i].second == '+')
                    BPlus();
                else
                    BMinus();
                break;
            case 'U':
                if (vec[i].second == '+')
                    UPlus();
                else
                    UMinus();
                break;
            case 'D':
                if (vec[i].second == '+')
                    DPlus();
                else
                    DMinus();
                break;
            case 'R':
                if (vec[i].second == '+')
                    RPlus();
                else
                    RMinus();
                break;
        }
        cout << "U" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << uArr.arr[i][j];
            cout << '\n';
        }

        cout << "l" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << lArr.arr[i][j];
            cout << '\n';
        }

        cout << "R" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << rArr.arr[i][j];
            cout << '\n';
        }

        cout << "f" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << fArr.arr[i][j];
            cout << '\n';
        }

        cout << "b" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << bArr.arr[i][j];
            cout << '\n';
        }

        cout << "d" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << dArr.arr[i][j];
            cout << '\n';
        }
        cout << endl;

    }

    while(!vec.empty())
        vec.pop_back();

//    cout << "U" << endl;
//    for(int i = 0; i<3; ++i)
//    {
//        for(int j = 0; j<3; ++j)
//            cout << uArr[i][j];
//        cout << '\n';
//    }
//
//    cout << "l" << endl;
//    for(int i = 0; i<3; ++i)
//    {
//        for(int j = 0; j<3; ++j)
//            cout << lArr[i][j];
//        cout << '\n';
//    }
//
//    cout << "R" << endl;
//    for(int i = 0; i<3; ++i)
//    {
//        for(int j = 0; j<3; ++j)
//            cout << rArr[i][j];
//        cout << '\n';
//    }
//
//    cout << "f" << endl;
//    for(int i = 0; i<3; ++i)
//    {
//        for(int j = 0; j<3; ++j)
//            cout << fArr[i][j];
//        cout << '\n';
//    }
//
//    cout << "b" << endl;
//    for(int i = 0; i<3; ++i)
//    {
//        for(int j = 0; j<3; ++j)
//            cout << bArr[i][j];
//        cout << '\n';
//    }
//
//    cout << "d" << endl;
//    for(int i = 0; i<3; ++i)
//    {
//        for(int j = 0; j<3; ++j)
//            cout << dArr[i][j];
//        cout << '\n';
//    }
//    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string temp;
    int num;
    cin >> tc;
    for(int k = 0; k<tc; ++k){
        cin >> num;
        for(int i = 0; i<num; ++i)
        {
            cin >> temp;
            vec.push_back({temp[0], temp[1]});
        }
        init();
        solution();
    }

    return 0;
}