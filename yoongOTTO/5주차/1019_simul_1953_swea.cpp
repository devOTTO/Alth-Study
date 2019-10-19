//
// Created by 융미 on 2019-10-19.
//

//1953 탈주범 검거 swea
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX 51

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[MAX][MAX] = {0,};
int dis[MAX][MAX] = {0,};
int t, n, m, r,c, l;
int answer;

void initArr(){
    for(int i = 0; i<MAX; ++i)
    {
        for(int j = 0; j<MAX; ++j)
        {
            arr[i][j] = 0;
            dis[i][j] = 0;
        }
    }
}
void print(){
    cout << endl;
    for(int i = 0; i<n; ++i)
    {
        for(int j = 0; j<m; ++j){
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }

}
bool checkGo(int x, int y, int nx, int ny, int num){
    bool check = false;
    switch (num){
        case 1:
            check = true;
            break;
        case 2: //상 하
            if((x + 1 == nx && y == ny) || (x-1 == nx && y == ny) ) check = true;
            break;
        case 3: //좌 우
            if((x == nx && y + 1 == ny) || (x == nx && y -1 == ny)) check = true;
            break;
        case 4: //하 좌
            if((x + 1 == nx && y == ny) || (x == nx && y - 1 == ny)) check = true;
            break;
        case 5: //상 좌
            if((x - 1 == nx && y == ny) || (x == nx && y - 1 == ny)) check = true;
            break;
        case 6: //상 우
            if((x - 1 == nx && y == ny) || (x == nx && y + 1 == ny)) check = true;
            break;
        case 7: //하 우
            if((x + 1 == nx && y == ny) || (x == nx && y + 1 == ny)) check = true;
            break;
    }
    return check;
}

bool checkSelf(int x, int y, int num, int nx, int ny, int nnum){

    bool check= false;

    if(x - 1 == nx && y == ny) //상
    {
        if(num == 1 || num == 2 || num == 4 || num == 7)
            check = checkGo(x,y,nx,ny,nnum);

    }else if(x + 1 == nx && y == ny){ //하
        if(num == 1 || num == 2 || num == 5 || num == 6)
            check = checkGo(x,y,nx,ny,nnum);

    }else if(x == nx && y -1 == ny) { //좌
        if(num == 1 || num == 3 || num == 6 || num == 7)
            check = checkGo(x,y,nx,ny,nnum);

    }else { //우
        if(num == 1 || num == 3 || num == 4 || num == 5)
            check = checkGo(x,y,nx,ny,nnum);
    }
    return check;
}

void bfs(){
    answer = 0;
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));
    dis[r][c] = 1;
    int time= 1;
    while(!q.empty()){

        pair<int,int> cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 0 || dis[nx][ny] != 0) continue;
            if (!checkSelf(x, y, arr[x][y], nx, ny, arr[nx][ny])) continue;

            dis[nx][ny] = dis[x][y] + 1;
            q.push(make_pair(nx, ny));

        }

    }

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j)
            if(dis[i][j] >=1 && dis[i][j] <= l) ++answer;
    }
    //print();

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    for(int tc = 1; tc<= t; ++tc){

        initArr();

        cin >> n >> m >> r >> c >> l;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                cin >> arr[i][j];
            }
        }
        bfs();
        cout << '#' << tc << ' ' << answer << '\n';
    }

    return 0;
}
