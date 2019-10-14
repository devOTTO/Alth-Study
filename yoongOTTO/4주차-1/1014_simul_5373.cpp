//
// Created by 융미 on 2019-10-14.
//

//5373 큐빙
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int tc;
vector<pair<char,char>> vec;
char fArr[3][3], bArr[3][3], uArr[3][3], lArr[3][3], rArr[3][3], dArr[3][3];

void init(){

    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j) {
            fArr[i][j] = 'r';
            bArr[i][j] = 'o';
            uArr[i][j] = 'w';
            lArr[i][j] = 'g';
            rArr[i][j] = 'b';
            dArr[i][j] = 'y';
        }
    }
}


void LMinus() {
    int j = 0;
    char temp[3];
    for(int i = 0; i<3; ++i){
        temp[i] = bArr[2-i][j];
        bArr[2-i][j] = uArr[i][j];
        uArr[i][j] = fArr[i][j];
        fArr[i][j] = dArr[i][j];
        dArr[i][j] = temp[i];
    }

}

void LPlus(){
    int j = 0;
    char temp[3];
    for(int i = 0; i<3; ++i){
        temp[i] = uArr[i][j];
        uArr[i][j] = bArr[2-i][j];
        bArr[2-i][j] = dArr[i][j];
        dArr[i][j] = fArr[i][j];
        fArr[i][j] = temp[i];
    }
}

void RMinus(){
    int j = 2;
    char temp[3];
    for(int i = 0; i<3; ++i){
        temp[i] = uArr[i][j];
        uArr[i][j] = bArr[2-i][j];
        bArr[2-i][j] = dArr[i][j];
        dArr[i][j] = fArr[i][j];
        fArr[i][j] = temp[i];
    }
}

void RPlus() {
    int j = 2;
    char temp[3];
    for(int i = 0; i<3; ++i){
        temp[i] = bArr[2-i][j];
        bArr[2-i][j] = uArr[i][j];
        uArr[i][j] = fArr[i][j];
        fArr[i][j] = dArr[i][j];
        dArr[i][j] = temp[i];
    }

}

void UPlus() {
    int i = 0;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = bArr[i][j];
        bArr[i][j] = lArr[i][j];
        lArr[i][j] = fArr[i][j];
        fArr[i][j] = rArr[i][2-j];
        rArr[i][2-j] = temp[j];
    }
}


void UMinus() {
    int i = 0;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = bArr[i][j];
        bArr[i][j] = rArr[i][2-j];
        rArr[i][2-j] = fArr[i][j];
        fArr[i][j] = lArr[i][j];
        lArr[i][j] = temp[j];
    }
}

void DPlus() {
    int i = 2;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = bArr[i][j];
        bArr[i][j] = rArr[i][2-j];
        rArr[i][2-j] = fArr[i][j];
        fArr[i][j] = lArr[i][j];
        lArr[i][j] = temp[j];
    }
}

void DMinus() {
    int i = 2;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = bArr[i][j];
        bArr[i][j] = lArr[i][j];
        lArr[i][j] = fArr[i][j];
        fArr[i][j] = rArr[i][2-j];
        rArr[i][2-j] = temp[j];
    }
}

void FPlus() {
    int i = 0;
    int k = 2;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = uArr[k][j];
        uArr[k][j] = lArr[k][j];
        lArr[k][j] = dArr[i][j];
        dArr[i][j] = rArr[2-j][i];
        rArr[2-j][i] = temp[j];
    }
}

void FMinus() {
    int i = 0;
    int k = 2;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = uArr[k][j];
        uArr[k][j] = rArr[2-j][i];
        rArr[2-j][i] = dArr[i][j];
        dArr[i][j] = lArr[k][j];
        lArr[k][j] = temp[j];
    }
}

void BPlus() {
    int i = 0;
    int k = 2;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[i] = uArr[i][j];
        uArr[i][j] = rArr[2-j][k];
        rArr[2-j][k] = dArr[k][j];
        dArr[k][j] = lArr[i][j];
        lArr[i][j] = temp[i];
    }
}

void BMinus() {
    int i = 0;
    int k = 2;
    char temp[3];
    for(int j = 0; j<3; ++j){
        temp[j] = uArr[i][j];
        uArr[i][j] = lArr[i][j];
        lArr[i][j] = dArr[k][j];
        dArr[k][j] = rArr[2-j][k];
        rArr[2-j][k] = temp[j];
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
                cout << uArr[i][j];
            cout << '\n';
        }

        cout << "l" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << lArr[i][j];
            cout << '\n';
        }

        cout << "R" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << rArr[i][j];
            cout << '\n';
        }

        cout << "f" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << fArr[i][j];
            cout << '\n';
        }

        cout << "b" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << bArr[i][j];
            cout << '\n';
        }

        cout << "d" << endl;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
                cout << dArr[i][j];
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
