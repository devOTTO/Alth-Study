//
//  main.cpp
//  tree_16235
//
//  Created by 김혜진 on 14/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int map[10][10];
int A[10][10];
vector<int> trees[10][10];

void springAndSummer() {
   
     for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++){
               
               if (!trees[i][j].empty()){
    
                   int size = trees[i][j].size();
                   int dead = size;
                   sort(trees[i][j].begin(), trees[i][j].end());
                   
                   for (int k = 0; k < size; k++){
                       
                       if (map[i][j] < trees[i][j][k]){
                           dead = k;
                           break;
                       }
                       
                       map[i][j] -= trees[i][j][k];
                       trees[i][j][k]++;
                   }
                   
                   for (int k = size-1; k > dead-1; k--){
                       map[i][j] += trees[i][j][k]/2;
                       trees[i][j].pop_back();
                       M--;
                   }
               }
           }
       }
}


void creatNewTree(int x, int y)
{
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            
            if (i > -1 && i < N && j > -1 && j < N) {
                
                if (i != x || j != y){
                    trees[i][j].push_back(1);
                    M++;
                }
            }
        }
    }
}


void fall() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int size = trees[i][j].size();
            for (int k = 0; k < size; k++) {
                //5의 배수라면
                if (trees[i][j][k]%5 == 0)
                    creatNewTree(i, j);
            }
        }
    }
}

void winter() {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            map[i][j]+=A[i][j];
    }
}

int main() {

    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
            map[i][j] = 5;
        }
    }
    
    int x,y,age;
    for (int i = 0; i < M; i++){
        cin >> x >> y >> age;
        trees[x-1][y-1].push_back(age);
    }
    
    while(K--){
        springAndSummer();
        fall();
        winter();
    }
    
    cout << M;
    
    return 0;
}
