//
// Created by 융미 on 2019-10-13.
//
//17142 연구소 3
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX_RANGE 50
int arr[MAX_RANGE][MAX_RANGE] = {0,};
int vis[MAX_RANGE][MAX_RANGE] = {0,};

int m, n;
int answer = 1e9;
int undo = 0;
int virus = 0;
int combIndex=0;

vector<pair<int,int>> vec;
queue<pair<int,int>> q;
int temp[10] = {0,};
int comb[3628800][10] = {0,};

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

void save(int length){
    for(int i = 0; i<length; ++i) {
        comb[combIndex][i] = temp[i];
    }
    combIndex++;
}

void combination(int index, int n, int r, int target){
    if(r == 0) save(index);
    else if(target == n) return;
    else{
        temp[index] = target;
        combination(index+1, n, r-1, target+1);
        combination(index,n,r,target+1);
    }
}

void init_vis() {
    for(int i =0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            vis[i][j] = -1;
        }
    }
}

void bfs(){
// 0 빈칸 1 벽 2 바이러스

    int infect = 0, times = 0;
    while(!q.empty()){
        auto cur = q.front();

        int x = cur.first;
        int y = cur.second;
        q.pop();

        for(int k = 0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] != 1 && vis[nx][ny] == -1) {
                vis[nx][ny] = vis[x][y] + 1;

                if(arr[nx][ny] == 0){
                    infect+=1;
                    times = vis[nx][ny];
                }

                q.push({nx,ny});
            }


        }
    }

    if(infect == undo && answer > times) answer = times;

}


void solution(){

    vector<int> minVec;
    combination(0, virus, m, 0);


    for(int i = 0; i<combIndex; ++i){
        init_vis();
        for(int j = 0; j<m; ++j){
            q.push(vec[comb[i][j]]);
            vis[vec[comb[i][j]].first][vec[comb[i][j]].second] = 0;
        }
        bfs();
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                vec.push_back({i,j});
                ++virus;
            }
            else if(arr[i][j] == 0) ++undo;
        }
    }


    solution();

    cout << (answer == 1e9 ? -1 : answer);


    return 0;
}