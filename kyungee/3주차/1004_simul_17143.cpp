//
//  1004_simul_17143.cpp
//  alth
//
//  Created by 김경이 on 2019. 10. 4..
//  Copyright © 2019년 김경이. All rights reserved.
//

// 아기 상어 https://www.acmicpc.net/problem/17143

#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

int R, C, M;
int ans;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
struct shark{
    int s; // 속력
    int d; // 이동 방향 (1:상, 2:하, 3:우, 4:좌)
    int z; // 크기 (0이면 없음)
};
shark map[102][102];

int main() {
    scanf("%d %d %d", &R, &C, &M);
    
    int r, c, s, d, z;
    for(int i=1; i<=M; i++) {
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        map[r][c] = {s, d, z};
    }
    
    // 1. 낚시왕이 오른쪽으로 한 칸 이동
    for(int t=1; t<=C; t++) {
        shark tmp[102][102] = {0, };
        // 2. 낚시왕의 열에 있는 가장 가까운 상어 하나 잡고 없애기
        for(int j=1; j<=R; j++) {
            if(map[j][t].z) {
                ans += map[j][t].z;
                map[j][t] = {0, 0, 0};
                break;
            }
        }
        
        // 3. 상어 이동
        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                if(map[i][j].z) {
                    // 상, 하 이동일 경우
                    if (map[i][j].d == 1 || map[i][j].d == 2) {
                        int s = map[i][j].s % (2*(R-1));
                        int d = map[i][j].d;
                        int x = i;
                        while(s--) {
                            if(x==1 && d==1) d = 2;
                            if(x==R && d==2) d = 1;
                            x += dx[d];
                        }
                        if(tmp[x][j].z < map[i][j].z)
                            tmp[x][j] = {map[i][j].s, d, map[i][j].z};
                    }
                    // 우, 좌 이동일 경우
                    else {
                        int s = map[i][j].s % (2*(C-1));
                        int d = map[i][j].d;
                        int y = j;
                        while(s--) {
                            if(y==1 && d==4) d = 3;
                            if(y==C && d==3) d = 4;
                            y += dy[d];
                        }
                        if(tmp[i][y].z < map[i][j].z)
                            tmp[i][y] = {map[i][j].s, d, map[i][j].z};
                    }
                    map[i][j] = {0, 0, 0};
                }
            }
        }
        memcpy(map, tmp, sizeof(tmp));
    }
    return 0;
}

