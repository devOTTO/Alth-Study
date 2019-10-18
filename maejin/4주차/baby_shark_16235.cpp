//
//  main.cpp
//  baby_shark_16236
//
//  Created by 김혜진 on 14/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//0 빈칸 9 아기상어 1~9 물고기, 아기상어 처음 크기 2

struct BABY {
    int size = 2;
    pair<int, int> location;
    int eat = 0;
};

int N, T;
int map[20][20];
int visited[20][20];
bool check = false;
BABY shark;


int fishNum[7];

void findFish(queue<pair<int,int>> que, int time) {
    
    
    int findX = 20;
    int findY = 20;
    
    queue<pair<int,int>> next;
    
    while(!que.empty()) {
        
        pair<int, int> cur = que.front();
        que.pop();
        
        if (!visited[cur.first][cur.second]){
         
            visited[cur.first][cur.second] = true;
            
            //비어있거나 같은 사이즈의 물고기
            if (map[cur.first][cur.second] == 0 || map[cur.first][cur.second] == shark.size){
                
                //상
                if (cur.first > 0 && !visited[cur.first-1][cur.second])
                    next.push(make_pair(cur.first-1, cur.second));
                
                //좌
                if (cur.second > 0 && !visited[cur.first][cur.second-1])
                    next.push(make_pair(cur.first, cur.second-1));
                
                //우
                if (cur.second < N-1 && !visited[cur.first][cur.second+1])
                    next.push(make_pair(cur.first, cur.second+1));
                
                //하
                if (cur.first < N-1 && !visited[cur.first+1][cur.second])
                    next.push(make_pair(cur.first+1, cur.second));
                
            }
            //작은 사이즈의 물고기
            else if (map[cur.first][cur.second] < shark.size) {
                
                if (cur.first < findX) {
                    findX = cur.first;
                    findY = cur.second;
                }
                else if (cur.first == findX && cur.second < findY){
                    findX = cur.first;
                    findY = cur.second;
                }
                check = true;
            }
        }
    }
    
    if(check){
        map[findX][findY] = 0;
        map[shark.location.first][shark.location.second] = 0;
        shark.location.first = findX;
        shark.location.second = findY;
        shark.eat++;
        T += time;
        
        //사이즈 업!
        if (shark.eat == shark.size) {
            shark.eat = 0;
            shark.size++;
        }
    }
    
    if (!check && !next.empty())
        findFish(next, ++time);
}

int main() {
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        
            if (map[i][j] == 9){
                shark.location.first = i;
                shark.location.second = j;
            }
            else if (map[i][j] != 0)
                fishNum[map[i][j]]++;
        }
    }
    
    
    do{
        queue<pair<int,int>> next;
        
        int x = shark.location.first;
        int y = shark.location.second;
        fill(visited[0], visited[0]+400, false);
        visited[x][y] = true;
        check = false;
        
        
        //상
        if (x > 0 && !visited[x-1][y])
            next.push(make_pair(x-1, y));
        
        //좌
        if (y > 0 && !visited[x][y-1])
            next.push(make_pair(x, y-1));
              
        //우
        if (y < N-1 && !visited[x][y+1])
            next.push(make_pair(x, y+1));
        
        //하
        if (x < N-1 && !visited[x+1][y])
            next.push(make_pair(x+1, y));
        
        findFish(next, 1);
        
    }while(check);
    
    cout << T;
    
    return 0;
}
