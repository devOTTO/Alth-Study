//
//  main.cpp
//  17140
//
//  Created by minhye Lee on 03/10/2019.
//  Copyright © 2019 minhye Lee. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;
int main() {
    int arr[100][100] = {0,};
    int r,c,k;
    int row = 3;
    int col = 3;
    int answer = 0;
    cin >> r >> c >> k;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    while(arr[r-1][c-1] != k && answer <= 100){
        if(row >= col){
            //r연산
            for(int i = 0; i < 100; i++){
                int count[101] = {0,};

                priority_queue< P, vector<P>, greater<P> > pq;

                for(int j = 0; j < 100; j++){
                    if(arr[i][j] !=0)
                        count[arr[i][j]]++;
                }

                for(int z = 0; z < 101; z++){
                    if(count[z] != 0)
                        pq.push(make_pair(count[z],z));
                }
                for(int q = 0; q < 100; q++){
                    arr[i][q] = 0;
                }
                int temp = 0;
                while(pq.size() != 0){
                    arr[i][temp] = pq.top().second;
                    temp++;
                    if(temp == 100)
                        break;
                    arr[i][temp] = pq.top().first;
                    temp++;
                    if(temp == 100)
                        break;
                    pq.pop();
                }
                col = max(temp, col);
            }

            
            
        } else{
            for(int i = 0; i < 100; i++){
                int count[101] = {0,};
                priority_queue< P, vector<P>, greater<P> > pq;

                for(int j = 0; j < 100; j++){
                    if(arr[j][i] !=0)
                        count[arr[j][i]]++;
                }
                for(int z = 0; z < 101; z++){
                    if(count[z] != 0)
                        pq.push(make_pair(count[z],z));
                }
                for(int q = 0; q < 100; q++){
                    arr[q][i] = 0;
                }
                int temp = 0;
                while(pq.size() != 0 ){
                    arr[temp][i] = pq.top().second;
                    temp++;
                    if(temp == 100)
                        break;
                    arr[temp][i] = pq.top().first;
                    temp++;
                    if(temp == 100)
                        break;
                    pq.pop();
                }
                row = max(temp, row);
            }
        }
        answer++;
    }
    
    if(answer > 100)
        cout << -1 << endl;
    else
        cout << answer << endl;

}
