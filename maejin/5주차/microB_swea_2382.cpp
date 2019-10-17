//
//  main.cpp
//  swea_2382
//
//  Created by 김혜진 on 17/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define U 1
#define D 2
#define L 3
#define R 4
#define EMPTY -1

struct microB{
    int x;
    int y;
    int num;
    int direction;
};

bool compare(microB a, microB b)
{
    return a.num > b.num;
}

int T, N, M, K; //테스트케이스, 배열크기, M시간후, K군집수
vector<int> answers;
int map[100][100];
vector<microB> list;
int answer;


void move() {
    
    int size = list.size();
    
    //int nextMap[100][100];      //미생물 군집이 이동한 맵
    //fill(nextMap[0], nextMap[0]+10000, -1);
    
    //초기화
    fill(map[0], map[0]+10000, EMPTY);
    sort(list.begin(), list.end(), compare);
    
    answer = 0;
    vector<microB> nextList;    //살아남은 미생물군집
    
    for (int i = 0; i < size; i++) {
        
        microB cur = list[i];
        if (cur.direction == U)
            cur.x -= 1;
        else if (cur.direction == D)
            cur.x += 1;
        else if (cur.direction == L)
            cur.y -= 1;
        else if (cur.direction == R)
            cur.y += 1;
        
        //만약 이동한 구간이 약품 처리 구간이라면
        if (cur.x == 0 || cur.x == N-1 || cur.y == 0 || cur.y == N-1){
            
            //미생물 수 줄어든다
            cur.num /= 2;
            
            if (cur.num == 0) //0이라면 다음 맵에 추가하지 않고 삭제
                continue;
            
            //방향 반대로
            if (cur.direction == U)
                cur.direction = D;
            else if (cur.direction == D)
                cur.direction = U;
            else if (cur.direction == L)
                cur.direction = R;
            else if (cur.direction == R)
                cur.direction = L;
        }
        
        answer += cur.num;
        
        //만약 이동하는 구간에 미생물 군집이 있다면
        if (map[cur.x][cur.y] != -1){
            if (nextList[map[cur.x][cur.y]].num > cur.num)  //원래 있던 것이 군집이 크다면
                nextList[map[cur.x][cur.y]].num += cur.num;
            else {  //지금 군집이 크다면
                nextList[map[cur.x][cur.y]].num += cur.num;
                nextList[map[cur.x][cur.y]].direction = cur.direction;  //방향 바꿈
            }
        }
        else {
            nextList.push_back(cur);
            map[cur.x][cur.y] = nextList.size()-1;
        }
    }
    
    //copy(map[0], map[0]+10000, nextMap[0]);
    list = nextList;
}



int main() {
    
    cin >> T;
    
    for (int t = 0; t < T; t++){
        
        //초기화
        //fill(map[0], map[0]+10000, EMPTY);
        list.clear();
        
        cin >> N >> M >> K;
        for(int k = 0; k < K; k++){
            microB temp;
            cin >> temp.x >> temp.y >> temp.num >> temp.direction;
            //map[temp.x][temp.y] = k;
            list.push_back(temp);
            answer += temp.num;
        }
        
        while(M--)
            move();
        
        answers.push_back(answer);
    }
    
    cout << endl;
    
    for (int t = 0; t < T; t++)
        cout << "#" << t+1 << " " << answers[t] << endl;
    
    return 0;
}
