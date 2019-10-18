//
//  main.cpp
//  lab3_17142
//
//  Created by 김혜진 on 15/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define TMAX 100000

int N, M;
int T = TMAX;                          //최소시간
int map[50][50];                //바이러스 2 벽 1 빈칸 0

vector<pair<int, int>> virus;   //바이러스
bool v_visited[10];
int zeroNum;                    //빈칸 갯수


queue<pair<int, int>> active;   //활성 바이러스
bool visited[50][50];


void bfs(int time, int emptyArea) {
    
    queue<pair<int, int>> next;
    time++;
    
    if (time >= T)
        return;
    
    while(!active.empty()){
        int x = active.front().first;
        int y = active.front().second;
        active.pop();
        visited[x][y] = true;
        
        
        //상
        if (x > 0 && !visited[x-1][y]){
            if (map[x-1][y] != 1){
                next.push(make_pair(x-1, y));
                visited[x-1][y] = true;
                
                
                if (map[x-1][y] == 0) emptyArea--;
            }
        }
        
        //하
        if (x < N-1 && !visited[x+1][y]){
            if (map[x+1][y] != 1){
                next.push(make_pair(x+1, y));
                visited[x+1][y] = true;
                
                if (map[x+1][y] == 0) emptyArea--;
            }
        }
        
        //좌
        if (y > 0 && !visited[x][y-1]){
            if (map[x][y-1] != 1){
                next.push(make_pair(x, y-1));
                visited[x][y-1] = true;
                
                if (map[x][y-1] == 0) emptyArea--;
            }
        }
        
        //우
        if (y < N-1 && !visited[x][y+1]){
            if (map[x][y+1] != 1){
                next.push(make_pair(x, y+1));
                visited[x][y+1] = true;
                
                if (map[x][y+1] == 0) emptyArea--;
            }
        }
        
    }
    
    if (!next.empty() && emptyArea != 0){
        active = next;
        bfs(time, emptyArea);
    }
    else if (emptyArea == 0 && T > time)
        T = time;
}

void setVirus(int index, queue<pair<int, int>> temp){
    
    temp.push(virus[index]);
    
    if (temp.size() == M)
    {
        active = temp;
        fill(visited[0], visited[0]+2500, 0);
        bfs(0, zeroNum);
        return;
    }
    
    for (int i = index+1; i < virus.size(); i++){
        setVirus(i, temp);
    }
}


void putVirus() {
 
    queue<pair<int, int>> temp;
    for (int i = 0; i < virus.size(); i++)
        setVirus(i, temp);
}

int main() {
   
    cin >> N >> M;
    

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
            
            if (map[i][j] == 0)
                zeroNum++;
            
            if (map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    
    if (zeroNum == 0){
        cout << 0;
        return 0;
    }
    
    putVirus();

    if (T == TMAX)
        cout << -1;
    else
        cout << T;
    
    return 0;
}
