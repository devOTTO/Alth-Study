//
//  0927_simul_17140.cpp
//  alth
//
//  Created by 김경이 on 2019. 9. 27..
//  Copyright © 2019년 김경이. All rights reserved.
//

// 이차원 배열과 연산 https://www.acmicpc.net/problem/17140

#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

int r, c, k;
int map[102][102] = {0, };
int rN, cN;
int t;

int main() {
    rN = cN = 3;
    scanf("%d %d %d", &r, &c, &k);
    r--; c--;
    
    for(int i=0; i<3; i++)
        scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
    
    if(map[r][c] == k){
        printf("0");
        return 0;
    }
    
    while (1)
    {
        t++;
        if (t > MAX) {
            printf("-1");
            return 0;
        }
        
        vector<pair<int, int>> tmp[MAX];
        
        //R
        if (rN >= cN)
        {
            for (int i = 0; i < rN; i++) {
                int cnt[MAX + 1] = { 0, };
                
                for (int j = 0; j < cN; j++)
                    cnt[map[i][j]]++;
                
                for(int j=1; j<=MAX; j++)
                    if(cnt[j])
                        tmp[i].push_back({ cnt[j], j });
            }
            
            for (int i = 0; i < rN; i++)
                for (int j = 0; j < cN; j++)
                    map[i][j] = 0;
            
            for (int i = 0; i < rN; i++)
                sort(tmp[i].begin(), tmp[i].end());
            
            for (int i = 0; i < rN; i++) {
                int idx = 0;
                for (int j = 0; j < tmp[i].size(); j++) {
                    map[i][idx++] = tmp[i][j].second;
                    if (idx == MAX)
                        break;
                    map[i][idx++] = tmp[i][j].first;
                    if (idx == MAX)
                        break;
                }
                cN = max(cN, idx);
            }
        }
        
        //C
        else
        {
            for (int i = 0; i < cN; i++)
            {
                int cnt[MAX + 1] = { 0, };
                
                for (int j = 0; j < rN; j++)
                    cnt[map[j][i]]++;
                
                for (int j = 1; j <= MAX; j++)
                    if (cnt[j])
                        tmp[i].push_back({ cnt[j], j });
            }
            
            for (int i = 0; i < rN; i++)
                for (int j = 0; j < cN; j++)
                    map[i][j] = 0;
            
            for (int i = 0; i < cN; i++)
                sort(tmp[i].begin(), tmp[i].end());
            
            for (int i = 0; i < cN; i++)
            {
                int idx = 0;
                for (int j = 0; j < tmp[i].size(); j++)
                {
                    map[idx++][i] = tmp[i][j].second;
                    if (idx == MAX)
                        break;
                    map[idx++][i] = tmp[i][j].first;
                    if (idx == MAX)
                        break;
                }
                rN = max(rN, idx);
            }
        }
        
        if (map[r][c] == k)
        {
            printf("%d", t);
            return 0;
        }
    }
    
    return 0;
}
