//
// Created by 융미 on 2019-10-15.
//

//16235 나무 재테크
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 101
using namespace std;


int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,-1,0,1,-1,0,1};
int n, m, k;
int A[MAX][MAX] = {0,}; //로봇이 뿌리는 양분
int arr[MAX][MAX] = {0,}; //남은 양분

vector<int> tree[MAX][MAX]; //tree age vector
queue<pair<int,int>> q; //bfs
int answer = 0;

//나무 양분 추가 나이 증가
void springSummer(){

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j)
        {
            if(!tree[i][j].empty())
            {
                sort(tree[i][j].begin(), tree[i][j].end());
                int tempSize = tree[i][j].size();

                //양분 먹기
                for(int k = 0; k<tempSize; ++k)
                {
                    int age = tree[i][j][k];

                    if(arr[i][j] >= age){
                        arr[i][j] -= age;
                        ++tree[i][j][k];
                    }
                    else //나무의 죽음(여름)
                    {

                        for(int l = k; l<tempSize; ++l)
                        {
                            arr[i][j] += tree[i][j][l] / 2;
                            --answer;
                        }

                        tree[i][j].erase(tree[i][j].begin()+k, tree[i][j].end());
                        break;
                    }
                    //가을용 조
                    if(tree[i][j][k] %5 == 0){
                        q.push(make_pair(i, j));
                    }
                }
            }
        }
    }

}

//나무의 번식
void fall(){

    while(!q.empty()){
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        for(int i = 0; i<8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            tree[nx][ny].push_back(1);
            ++answer;
        }
    }
}

//겨울엔 로봇이 양분을 추가
void winter(){
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            arr[i][j] += A[i][j];
}

void solution(){

    //나무의 양분 5로 초기화
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            arr[i][j] = 5;

    //k년 만큼 사계절 반복
    for(int i = 0; i<k; ++i)
    {
        springSummer();
        fall();
        winter();
    }
    cout << answer;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            cin >>A[i][j];

    int r, c, age;
    for(int i = 0; i<m; ++i)
    {
        cin >> r >> c >> age;
        r--;
        c--;

        tree[r][c].push_back(age);
        ++answer;
    }

    solution();
    return 0;
}
