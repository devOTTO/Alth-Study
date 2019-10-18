//
// Created by 융미 on 2019-10-19.
//
//swea 2117 홈 방범 서비스
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 21

int tc, n, m;
int answer;
int arr[MAX][MAX] = {0,};
int dis[MAX][MAX] = {0,};
int costArr[2*MAX] = {0,};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q;

void make_cost(){
    for(int i = 1; i<2*MAX; ++i){
        costArr[i] = i*i + (i - 1)*(i - 1);
    }

}

void init(){
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            dis[i][j]=0;
}

void print(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
        {
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(int a, int b){
    int cnt = 0;
    int benefit = 0;

    q.push(make_pair(a,b));
    dis[a][b]=1;

    if(arr[a][b] == 1) cnt++;


    for(int k=1;;k++){
        if( q.empty() )
            break;

        int size = (int)q.size();


        benefit = (cnt * m) - costArr[k];

        if(benefit >= 0)
        {
            if(cnt > answer) answer = cnt;
        }

        for(int t=0; t<size; t++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];


                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(dis[nx][ny] != 0) continue;

                dis[nx][ny] = dis[x][y] + 1;
                q.push(make_pair(nx,ny));

                if(arr[nx][ny] == 1) ++cnt;
            }
        }
    }
    init();



}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    make_cost();

    cin >> tc;
    for(int t = 1; t<= tc; ++t){
        cin >> n >> m;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j) {
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i<n;++i){
            for(int j = 0; j<n; ++j){
                bfs(i,j);
            }
        }

        cout << "#" << t << ' ' << answer << '\n';
        answer = -1;
    }

    return 0;
}
