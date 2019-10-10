//
//  main.cpp
//  Alth_day03
//
//  Created by 김혜진 on 04/10/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <iostream>
using namespace std;

int R, C, T;
int Answer;
int maps[50][50];
pair<int,int> AC[2];

void spread()
{

    int nextMaps[50][50] = {0, };

    for (int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if (maps[i][j] > 0)
            {

                int spreadNum = 0;

                //상
                if (i > 0 && maps[i-1][j] != -1)
                {
                    nextMaps[i-1][j] += maps[i][j]/5;
                    spreadNum++;
                }
                //하
                if (i+1 < R && maps[i+1][j] != -1)
                {
                    nextMaps[i+1][j] += maps[i][j]/5;
                    spreadNum++;
                }
                //좌
                if (j > 0 && maps[i][j-1] != -1)
                {
                    nextMaps[i][j-1] += maps[i][j]/5;
                    spreadNum++;
                }
                //우

                if (j+1 < C && maps[i][j+1] != -1)
                {
                    nextMaps[i][j+1] += maps[i][j]/5;
                    spreadNum++;
                }

                nextMaps[i][j] += maps[i][j] - (maps[i][j] / 5) * spreadNum;
            }
            else if (maps[i][j] == -1)
                nextMaps[i][j] = -1;

        }
    }

    for (int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            maps[i][j] = nextMaps[i][j];

    }

}



void airClean()
{

    //위쪽 반시계방향
    for (int i = AC[0].first-1; i > 0; i--)
        maps[i][0] = maps[i-1][0];

    for (int i = 0; i + 1 < C ; i++)
        maps[0][i] = maps[0][i+1];

    for (int i = 0; i < AC[0].first ; i++)
        maps[i][C-1] = maps[i+1][C-1];

    for (int i = C-1; i - 1 > 0; i--)
        maps[AC[0].first][i] = maps[AC[0].first][i-1];

    maps[AC[0].first][1] = 0;

    //아래쪽 시계 방향 바람
    for (int i = AC[1].first+1; i + 1< R; i++)
        maps[i][0] = maps[i + 1][0];

    for (int i = 0; i + 1< C ; i++)
        maps[R-1][i] = maps[R-1][i+1];

    for (int i = R - 1; i > AC[1].first ; i--)
           maps[i][C-1] = maps[i-1][C-1];

    for (int i = C-1; i > 1; i--)
        maps[AC[1].first][i] = maps[AC[1].first][i-1];

    maps[AC[1].first][1] = 0;


}

void sum()
{
    Answer = 0;
    for (int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            if (maps[i][j] > 0)
                Answer += maps[i][j];
    }
}


int main() {

    cin >> R >> C >> T;

    bool check_air = false;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> maps[i][j];

                if (maps[i][j] == -1) //공기청정기
                {
                    if (!check_air)
                    {
                        AC[0].first = i;
                        AC[0].second = j;
                        check_air = true;
                    }
                    else
                    {
                        AC[1].first = i;
                        AC[1].second = j;
                    }
                }
        }
    }

    while(T != 0)
    {
        spread();
        airClean();
        T--;
    }

    sum();
    cout << Answer;
    return 0;
}

