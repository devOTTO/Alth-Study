//
//  17143.cpp
//  Alth_day03
//
//  Created by 김혜진 on 10/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
using namespace std;

#define U 1
#define D 2
#define R 3
#define L 4

int map[101][101];
int r, c, M, result;
int sharkD[10001];
int sharkS[10001];
int sharkZ[10001];


//상어 낚시
void catchShark(int index)
{
    for (int i = 1; i <= r; i++) {
        if (map[i][index] != 0) {
            result += sharkZ[map[i][index]];
            map[i][index] = 0;
            break;
        }
    }
}

//상어 이동
void moveShark()
{
    int temp[101][101] = {0,};
    int shark;
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            
            shark = map[i][j];
            
            //상어 발견
            if (map[i][j]) {
                //세로 이동
                if (sharkD[shark] == U || sharkD[shark] == D){
                    int s = sharkS[shark] % ((r-1)*2);
                    int x = i;
                    int d = sharkD[shark];
                    
                    while(s--){
                        if (x == r && d == D) d = U;
                        if (x == 1 && d == U) d = D;
                        
                        if (d == D) x++;
                        else x--;
                            
                    }
                    
                    sharkD[shark] = d;
                    if (temp[x][j] != 0) {
                        if (sharkZ[temp[x][j]] < sharkZ[shark])
                            temp[x][j] = shark;
                    }
                    else
                        temp[x][j] = shark;
                    
                }
                //가로 이동
                else{
                    int s = sharkS[shark] % ((c-1)*2);
                    int y = j;
                    int d = sharkD[shark];
                    
                    while(s--){
                        if (y == c && d == R) d = L;
                        if (y == 1 && d == L) d = R;
                        
                        if (d == R) y++;
                        else y--;
                    }
                    
                    sharkD[shark] = d;
                    if (temp[i][y] != 0) {
                        if (sharkZ[temp[i][y]] < sharkZ[shark])
                            temp[i][y] = shark;
                    }
                    else
                        temp[i][y] = shark;
                }
            }
        }
    }
    
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++)
            map[i][j] = temp[i][j];
    }
}



int main()
{
    
    cin >> r >> c >> M;
    
    if (M == 0)
    {
        cout << 0;
        return 0;
    }
    
    int x, y;
    for (int i = 1; i <= M; i++)
    {
        cin >> x >> y;
        map[x][y] = i;
        cin >> sharkS[i] >> sharkD[i] >> sharkZ[i];
    }
    
    //낚시왕 이동
    for (int i = 1; i <= c; i++)
    {
        catchShark(i);
        moveShark();
    }
    
    cout << result;
    
    return 0;
    
}


