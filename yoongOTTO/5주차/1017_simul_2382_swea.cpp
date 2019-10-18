//
// Created by 융미 on 2019-10-18.
//
//SWEA 2382 미생물 격리
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 101
int t, n, m, k;
int answer;
//1 상 2 하 3 좌 4 우
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int changeDir[5] = {0, 2, 1, 4, 3};
vector<int> arr[MAX][MAX];
struct data{
    int x;
    int y;
    int num;
    int dir;
};


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tempX, tempY, tempNum, tempDir;
    cin >> t;
    for(int tc = 1; tc<t+1; ++tc)
    {
        vector<data> vec;

        cin >> n >> m >> k;

        for(int j = 0 ;j<k; ++j){
            cin >> tempX >> tempY >> tempNum >> tempDir;
            vec.push_back(data{tempX, tempY, tempNum,tempDir});
            arr[tempX][tempY].push_back(j);
        }

        while(m--){

            for(int j = 0; j<k; ++j){
                if(vec[j].num == 0) continue;
                arr[vec[j].x][vec[j].y].clear();
            }
            for(int j = 0; j<k; ++j) {
                if(vec[j].num == 0) continue;

                //arr[vec[j].x][vec[j].y].clear();

                vec[j].x += dx[vec[j].dir];
                vec[j].y += dy[vec[j].dir];

                arr[vec[j].x][vec[j].y].push_back(j);
            }

            for(int i = 0; i<k; ++i){
                if(vec[i].num == 0)continue;

                int x = vec[i].x;
                int y = vec[i].y;

                if(x == 0 || y == 0 || x == n-1 || y == n-1){
                    vec[i].num /= 2;
                    vec[i].dir = changeDir[vec[i].dir];
                }
                else if (arr[vec[i].x][vec[i].y].size() > 1) {
                    int x = vec[i].x;
                    int y = vec[i].y;
                    int max_num = 0;
                    int max_cnt = 0;
                    int max_dir = 0;
                    int sum = 0;
                    for (int j = 0; j < arr[x][y].size(); j++) {
                        sum += vec[arr[x][y][j]].num; // 미생물 수 합
                        // 최대 미생물을 가진 군집 찾기
                        if (max_num < vec[arr[x][y][j]].num) {
                            max_num = vec[arr[x][y][j]].num;
                            max_dir = vec[arr[x][y][j]].dir;
                            max_cnt = arr[x][y][j];
                        }
                        vec[arr[x][y][j]].num = 0;
                    }
                    vec[max_cnt].num = sum;
                    vec[max_cnt].dir = max_dir;
                }
            }
        }

        answer = 0;
        for(int j = 0; j<k; ++j)
        {
            answer += vec[j].num;
        }

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                arr[i][j].clear();
            }
        }
        cout << "#" << tc << ' ' << answer << '\n';
    }


    return 0;
}