//
//  0927_bfs_17142.cpp
//  alth
//
//  Created by 김경이 on 2019. 9. 27..
//  Copyright © 2019년 김경이. All rights reserved.
//

// 연구소 3 https://www.acmicpc.net/problem/17142

#include <algorithm>
#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 987654321

struct Point {
    int r, c, d;
};

int n, m;
int map[52][52] = {0, };
Point Virus[10];
int VirusCnt;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

int countBits(int n) {
    int cnt = 0;
    while(n) {
        if(n & 1) ++ cnt;
        n = n >> 1;
    }
    return cnt;
}

int solve() {
    int ret = INF;
    for(int subset=0; subset < 1 << VirusCnt; subset++) {
        if(countBits(subset) == m) {
            bool visited[50][50] = {false};
            int dist = 0;
            queue<Point> queue;
            for(int i=0; i<VirusCnt; i++){
                if(subset & (1 << i)) {
                    visited[Virus[i].r][Virus[i].c] = true;
                    queue.push(Virus[i]);
                }
            }
            
            while(!queue.empty()) {
                Point curr = queue.front();
                queue.pop();
                if(map[curr.r][curr.c] != 2)
                    dist = max(dist, curr.d);
                
                for(int i=0; i<4; i++) {
                    int nr = curr.r + dr[i];
                    int nc = curr.c + dc[i];
                    
                    if(nr<0 || nr>n-1 || nc<0 || nc>n-1) continue;
                    if(visited[nr][nc] || map[nr][nc] == 1) continue;
                    visited[nr][nc] = true;
                    queue.push({nr, nc, curr.d+1});
                }
            }
            
            bool flag = true;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(map[i][j] == 0 && visited[i][j] == false)
                        flag = false;
                }
            }
            if(flag)
                ret = min(ret, dist);
        }
    }
    if(ret == INF) return -1;
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    
    VirusCnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2) {
                Virus[VirusCnt++] = {i, j};
            }
        }
    }
    
    printf("%d", solve());
    return 0;
}
