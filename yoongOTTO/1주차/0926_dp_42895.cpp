//
// Created by 융미 on 2019-09-26.
//
#include <iostream>
using namespace std;

int answer = -1;
int arr[8] = {0,};

void dfs(int count, int sum, int number){
    if(count > 8) return;

    if(answer != -1 && answer < count) return;

    if(sum == number) {
        if(answer == -1 || count < answer)
            answer = count;
        return;
    }

    for(int i = 0; i<8; ++i)
    {
        dfs(count+i+1,sum+arr[i],number);
        dfs(count+i+1,sum-arr[i],number);
        dfs(count+i+1,sum*arr[i],number);
        dfs(count+i+1,sum/arr[i],number);
    }
}

int solution(int N, int number) {

    arr[0] = N;

    for(int i = 1; i<8; ++i)
    {
        arr[i] = 10*arr[i-1] + N;
    }

    dfs(0,0,number);

    return answer;
}


