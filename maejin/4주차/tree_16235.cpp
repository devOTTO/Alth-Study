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

struct tree {
    int x;
    int y;
    int age = 1;
};

bool compare(tree a, tree b){
    
    if (a.age == b.age)
        return true;
    
    return a.age < b.age;
}

int N, M, K;
int map[11][11];
int A[11][11];
vector<tree> trees[11][11];
vector<tree> dead;


void spring() {
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            
            if (!trees[i][j].empty()){
                sort(trees[i][j].begin(), trees[i][j].end(), compare);
                int size = trees[i][j].size();
                int index = -1;
                for (int k = 0; k < size; k++) {
                    
                    if (map[i][j] < trees[i][j][k].age){
                        index = k;
                        break;
                    }
                    
                    map[i][j] -= trees[i][j][k].age;
                    trees[i][j][k].age++;
                }
                
                if (index != -1){
                    for (int k = 0; k < size-index; k++) {
                        dead.push_back(trees[i][j][index]);
                        trees[i][j].erase(trees[i][j].begin()+index);
                        M--;
                    }
                }
            }
        }
    }
}


void summer() {
    
    while (!dead.empty()) {
        
        tree temp = dead[0];
        dead.erase(dead.begin());
        map[temp.x][temp.y] += temp.age/2;
    }
}


void creatNewTree(tree curr)
{
    tree temp;
    for (int i = curr.x-1; i <= curr.x+1; i++) {
        for (int j = curr.y-1; j <= curr.y+1; j++) {
            if (i > 0 && i < N+1 && j > 0 && j < N+1) {
                
                if (i != curr.x || j != curr.y){
                    temp.x = i;
                    temp.y = j;
                    trees[i][j].push_back(temp);
                    M++;
                }
            }
        }
    }
}

void fall() {
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int size = trees[i][j].size();
            for (int k = 0; k < size; k++) {
                tree curr = trees[i][j][k];
                //5의 배수라면
                if (curr.age%5 == 0)
                    creatNewTree(curr);
            }
        }
    }
}

void winter() {
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            map[i][j]+=A[i][j];
    }
}

int main() {
    
    fill(map[0], map[0]+121, 5);
    
    cin >> N >> M >> K;
    
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    }
    
    for (int i = 1; i <= M; i++){
        tree temp;
        cin >> temp.x >> temp.y >> temp.age;
        trees[temp.x][temp.y].push_back(temp);
    }
    
    while(K--){
        spring();
        summer();
        fall();
        winter();
    }
    
    cout << M;
    
    return 0;
}
