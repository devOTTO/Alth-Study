//
// Created by 융미 on 2019-10-14.
//
//16234 인구 이동 - bfs
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define MAX 100
int n, l, r;
int arr[MAX][MAX] = {0,};
int dis[MAX][MAX] = {0,};

int dx[4] = { 0,0,1,-1};
int dy[4] = {-1,1,0,0};

int answer;
queue<pair<int,int> > q;
int idx = 1;
bool flag = false;


void bfs(){

    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;

        q.pop();
        for(int i = 0; i<4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dis[nx][ny] != 0) continue;

            int cha = abs(arr[nx][ny] - arr[x][y]);
            if(cha < l || cha > r) continue;

            dis[nx][ny] = idx;
            q.push({nx,ny});
            flag = true;
        }
    }
}

void solution(){

    while(true) {
        idx = 1;
        flag = false;
        int sum[2501] = {0,};
        int nums[2501] = {0,};

        for(int i = 0; i<n; ++i)
            for(int j = 0; j<n; ++j)
                dis[i][j] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = idx;
                    bfs();
                    idx++;
                }
            }
        }
        if(!flag) return;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum[dis[i][j]] += arr[i][j];
                nums[dis[i][j]]++;
            }
        }

        for (int i = 1; i < idx; ++i) {
            sum[i] /= nums[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = sum[dis[i][j]];
            }
        }

        answer++;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> l >> r;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            cin >> arr[i][j];

    solution();

    cout << answer;
    return 0;
}
