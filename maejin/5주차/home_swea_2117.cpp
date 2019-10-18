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
#include <math.h>
using namespace std;

int T, N, M;
vector<int> answers;
int houseNum;
int maxCost, maxK;
int answer;

int map[20][20];

int findHouseNum(int k, int x, int y){
    
    int num = 0;
    
    int startX = x - (k-1);
    int endX = x + (k-1);
    int startY = y - (k-1);
    int endY = y + (k-1);
    
    for (int i = startX; i <= endX; i++){
        for (int j = startY; j <= endY; j++){
            //범위 안에 집이 있을 경우
            if (i >= 0 && i < N && j >= 0 && j < N && map[i][j] == 1)
                num++;
        }
    }
        
    return num;
}


int main() {
    
    cin >> T;
    
    for (int t = 0; t < T; t++){
        
        fill(map[0], map[0]+400, 0);
        houseNum = 0;
        cin >> N >> M;
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++){
                cin >> map[i][j];
                if (map[i][j] == 1)
                    houseNum++;
            }
        
        maxCost = houseNum*M;
        maxK = (int) sqrt((double)maxCost);
   
    
        int maxHouse = 0;
        
        for (int k = 1; k <= maxK; k++){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    
                    int num = findHouseNum(k, i, j);
                    if (maxHouse < num)
                    {
                        maxHouse = num;
                        answer = k;
                    }
                    
                }
            }
        }
        
        answers.push_back(answer);
        
    }
    
    for (int t = 0; t < T; t++)
        cout << "#" << t+1 << " " << answers[t] << endl;
    
    
    return 0;
}
