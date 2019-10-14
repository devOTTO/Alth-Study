//
// Created by 융미 on 2019-10-14.
//
//17140 이차원 배열과 연산
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 101

int r,c,k;
int m = 3;
int n = 3; // m : 행 n : 열
int arr[MAX][MAX] = { 0, };
int answer = -1;

void RCal(){

    vector<pair<int,int>> tempVec[MAX];

    for(int i = 0; i<m; ++i){
        int countArr[MAX] = {0,};
        for(int j = 0; j<n; ++j)
            countArr[arr[i][j]]++;

        for(int k = 1; k<MAX; ++k)
            if(countArr[k])
                tempVec[i].push_back({countArr[k], k});
    }

    for(int i = 0; i<m; ++i)
        for(int j = 0; j<n; ++j)
            arr[i][j] = 0;

    for(int i = 0; i<m; ++i){
        sort(tempVec[i].begin(), tempVec[i].end());
    }

    for(int i = 0; i<m; ++i){
        int size = tempVec[i].size();
        int idx = 0;
        for(int j = 0; j<size && idx < MAX; ++j){
            arr[i][idx++] = tempVec[i][j].second;
            arr[i][idx++] = tempVec[i][j].first;
        }
        n = max(n,idx);
    }
}

void CCal(){
    vector<pair<int,int>> tempVec[MAX];

    for(int i = 0; i<n; ++i){
        int countArr[MAX] = {0,};

        for(int j = 0; j<m; ++j)
            countArr[arr[j][i]]++;

        for(int k = 1; k<MAX; ++k)
            if(countArr[k])
                tempVec[i].push_back({countArr[k], k});
    }

    for(int i = 0; i<m; ++i)
        for(int j = 0; j<n; ++j)
            arr[i][j] = 0;

    for(int i = 0; i<n; ++i){
        sort(tempVec[i].begin(), tempVec[i].end());
    }

    for(int i = 0; i<n; ++i){
        int size = tempVec[i].size();
        int idx = 0;
        for(int j = 0; j<size && idx < MAX; ++j){
            arr[idx++][i] = tempVec[i][j].second;
            arr[idx++][i] = tempVec[i][j].first;
        }
        m = max(m,idx);
    }
}


void solution() {
    int time = 0;

    while(time<101){
        if(arr[r][c] == k) {
            answer = time;
            return;
        }

        if(m >= n)
            RCal();
        else
            CCal();

        time++;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    --r;
    --c;
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            cin >> arr[i][j];
        }
    }

    solution();

    cout << answer;

    return 0;
}
