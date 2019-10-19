//
//  main.cpp
//  swea_5650
//
//  Created by 김혜진 on 19/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


#define U 0
#define D 1
#define L 2
#define R 3

struct pinBall{
    int x;
    int y;
    int dir;
    int score;
};

int T, N;
vector<int> answers;

int map[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int block[][4] = {{0,0,0,0}, {1, 3, 0, 2}, {3, 0, 1, 2}, {2, 0, 3, 1}, {1, 2, 3, 0}, {1, 0, 3, 2}};
int answer;
pinBall ball;

vector<pair<int, int> > emptyList;                  //빈칸 리스트
pair<pair<int, int>, pair<int, int>> wormhole[11];  //5~10 웜홀 리스트
bool wormholeCheck[11];                             //입력할 때 확인용



void game(int startX, int startY) {
    
    ball.x += dx[ball.dir];
    ball.y += dy[ball.dir];
    
    //벽에 닿았을 경우
    if (ball.x < 0 || ball.y < 0 || ball.x == N || ball.y == N){
       //방향 전환과 스코어 증가
        ball.dir = block[5][ball.dir];
        ball.score++;
    }
    else {
        
        int nextArea = map[ball.x][ball.y];
    
        //블록의 경우
        if (nextArea > 0 && nextArea <= 5){
            ball.dir = block[nextArea][ball.dir];
            ball.score++;
        }
        
        //웜홀일 경우 좌표 이동
        else if (nextArea > 5 && nextArea < 11){
            if (wormhole[nextArea].first.first == ball.x && wormhole[nextArea].first.second == ball.y){
                ball.x = wormhole[nextArea].second.first;
                ball.y = wormhole[nextArea].second.second;
            }
            else {
                ball.x = wormhole[nextArea].first.first;
                ball.y = wormhole[nextArea].first.second;
            }
        }
        
        //블랙홀 게임 종료
        else if (nextArea == -1)
            return;
        
    }
    
    //출발 위치라면 게임 종료
    if (ball.x == startX && ball.y == startY)
        return;
    
    game(startX, startY);
}

int main() {
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        
        fill(map[0], map[0]+10000, 0);
        fill(wormholeCheck, wormholeCheck+11, 0);
        emptyList.clear();
        answer = 0;
        
        
        cin >> N;
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                
                if (map[i][j] == 0)
                    emptyList.push_back(make_pair(i, j));
                
                else if (map[i][j] > 5 && map[i][j] < 11){
                    if (!wormholeCheck[map[i][j]]) {
                        wormhole[map[i][j]].first = make_pair(i, j);
                        wormholeCheck[map[i][j]] = true;
                    }
                    else
                        wormhole[map[i][j]].second = make_pair(i, j);
                }
            }
        }
        
        //빈곳마다 게임 시작
        int size = int(emptyList.size());
        for (int i = 0; i < size; i++) {
            
            //상하좌우 다넣어보기
            for (int j = 0; j < 4; j++) {
                ball.x = emptyList[i].first;
                ball.y = emptyList[i].second;
                ball.score = 0;
                ball.dir = j;
                
                game(ball.x, ball.y);
                
                if (answer < ball.score)
                    answer = ball.score;
            }
        }
        
        answers.push_back(answer);
    }
    
    for (int t = 0; t < T; t++)
        cout << "#" << t+1 << " " << answers[t] << endl;
    
    return 0;
}
