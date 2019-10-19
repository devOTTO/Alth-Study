//
//  main.cpp
//  swea_1953
//
//  Created by 김혜진 on 19/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


//터널 타입
#define UDLR 1
#define UD 2
#define LR 3
#define UR 4
#define DR 5
#define DL 6
#define UL 7

int T, N, M, R, C, L;
vector<int> answers;
int answer;
int map[50][50];
bool visited[50][50];



void bfs(queue<pair<int, int> > que, int time) {
    
    queue<pair<int, int> > next;
    
    while (!que.empty()) {
        
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        //이미 확인했던 공간이면
        if (visited[x][y])
            continue;
        
        int type = map[x][y];
        answer++;
        visited[x][y] = true;
        
        if (type == UDLR){
            //상
            if (x > 0 && !visited[x-1][y] && (map[x-1][y] == DR || map[x-1][y] == UD || map[x-1][y] == DL || map[x-1][y] == UDLR))
                next.push(make_pair(x-1, y));
            //하
            if (x < N-1 && !visited[x+1][y] && (map[x+1][y] == UR || map[x+1][y] == UD || map[x+1][y] == UL || map[x+1][y] == UDLR))
                next.push(make_pair(x+1, y));
            //좌
            if (y > 0 && !visited[x][y-1] && (map[x][y-1] == DR || map[x][y-1] == LR || map[x][y-1] == UR || map[x][y-1] == UDLR))
                next.push(make_pair(x, y-1));
            //우
            if (y < M-1 && !visited[x][y+1] && (map[x][y+1] == UL || map[x][y+1] == LR || map[x][y+1] == DL || map[x][y+1] == UDLR))
                next.push(make_pair(x, y+1));
        }
        else if (type == UD) {
            //상
            if (x > 0 && !visited[x-1][y] && (map[x-1][y] == DR || map[x-1][y] == UD || map[x-1][y] == DL|| map[x-1][y] == UDLR))
                next.push(make_pair(x-1, y));
            //하
            if (x < N-1 && !visited[x+1][y] && (map[x+1][y] == UR || map[x+1][y] == UD || map[x+1][y] == UL|| map[x+1][y] == UDLR))
                next.push(make_pair(x+1, y));
        }
        else if (type == LR){
            //좌
            if (y > 0 && !visited[x][y-1] && (map[x][y-1] == DR || map[x][y-1] == LR || map[x][y-1] == UR|| map[x][y-1] == UDLR))
                next.push(make_pair(x, y-1));
            //우
            if (y < M-1 && !visited[x][y+1] && (map[x][y+1] == UL || map[x][y+1] == LR || map[x][y+1] == DL|| map[x][y+1] == UDLR))
                next.push(make_pair(x, y+1));
        }
        else if (type == UR){
            //상
            if (x > 0 && !visited[x-1][y] && (map[x-1][y] == DR || map[x-1][y] == UD || map[x-1][y] == DL|| map[x-1][y] == UDLR))
                next.push(make_pair(x-1, y));
            //우
            if (y < M-1 && !visited[x][y+1] && (map[x][y+1] == UL || map[x][y+1] == LR || map[x][y+1] == DL|| map[x][y+1] == UDLR))
                next.push(make_pair(x, y+1));
        }
        else if (type == DR) {
            //하
            if (x < N-1 && !visited[x+1][y] && (map[x+1][y] == UR || map[x+1][y] == UD || map[x+1][y] == UL|| map[x+1][y] == UDLR))
                next.push(make_pair(x+1, y));
            //우
            if (y < M-1 && !visited[x][y+1] && (map[x][y+1] == UL || map[x][y+1] == LR || map[x][y+1] == DL|| map[x][y+1] == UDLR))
                next.push(make_pair(x, y+1));
        }
        else if (type == DL){
            //하
            if (x < N-1 && !visited[x+1][y] && (map[x+1][y] == UR || map[x+1][y] == UD || map[x+1][y] == UL|| map[x+1][y] == UDLR))
                next.push(make_pair(x+1, y));
            //좌
            if (y > 0 && !visited[x][y-1] && (map[x][y-1] == DR || map[x][y-1] == LR || map[x][y-1] == UR|| map[x][y-1] == UDLR))
                next.push(make_pair(x, y-1));
        }
        else if (type == UL){
            //상
            if (x > 0 && !visited[x-1][y] && (map[x-1][y] == DR || map[x-1][y] == UD || map[x-1][y] == DL|| map[x-1][y] == UDLR))
                next.push(make_pair(x-1, y));
            //좌
            if (y > 0 && !visited[x][y-1] && (map[x][y-1] == DR || map[x][y-1] == LR || map[x][y-1] == UR|| map[x][y-1] == UDLR))
                next.push(make_pair(x, y-1));
        }
    }
    
    
    if (time == L)
        return;
    else if (!next.empty())
        bfs(next, ++time);
}


int main() {
    
    cin >> T;
    
    for (int t = 0; t < T; t++){
        fill(map[0], map[0]+2500, 0);
        fill(visited[0], visited[0]+2500, false);
        answer = 0;
        
        cin >> N >> M >> R >> C >> L;
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++)
                cin >> map[i][j];
        }
        
        queue<pair<int, int> > que;
        que.push(make_pair(R, C));
        bfs(que, 1);
        
        answers.push_back(answer);
    }
    
    for (int t = 0; t < T; t++)
        cout << "#" << t+1 << " " << answers[t] << endl;
    
    return 0;
}
