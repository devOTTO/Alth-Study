//
//  main.cpp
//  swea_2117
//
//  Created by 김혜진 on 17/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, N, M;
vector<int> answers;

int answer;
int map[20][20];

int startX, startY;
vector<pair<int, int> > houseList;

bool visited[20][20];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void bfs(queue<pair<int, int> > que, int k, int house) {
    
    queue<pair<int, int> > next;
    
    while(!que.empty()){
        
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        if (map[x][y] == 1)
            house++;
        
        
        for (int i = 0; i < 4; i++) {
            
            int nextX = x+dx[i];
            int nextY = y+dy[i];
            
            if (nextX > -1 && nextX < N && nextY > -1 &&  nextY < N){
                
                if (!visited[nextX][nextY]){
                    next.push(make_pair(nextX, nextY));
                    visited[nextX][nextY] = true;
                }
            }
        }
    }
    
    int cost = k*k + (k-1)*(k-1);
    int pay = house*M;
    
    if (answer < house && pay >= cost)
        answer = house;
    
    if (!next.empty())
        bfs(next, ++k, house);
}



int main() {
    
    cin >> T;
    
    for (int t = 0; t < T; t++){
        
        fill(map[0], map[0]+400, 0);
        answer = 0;
        
        cin >> N >> M;
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];
  
        
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                fill(visited[0], visited[0]+400, false);
                queue<pair<int, int> > que;
                que.push(make_pair(i, j));
                visited[i][j] = true;
                
                startX = i;
                startY = j;
                
                bfs(que, 1, 0);
            }
        }
        answers.push_back(answer);
        
    }
    
    for (int t = 0; t < T; t++)
        cout << "#" << t+1 << " " << answers[t] << endl;
    
    
    return 0;
}
