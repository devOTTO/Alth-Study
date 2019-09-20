//
//  0920_dp_42895.cpp
//  alth
//
//  Created by 김경이 on 2019. 9. 20..
//  Copyright © 2019년 김경이. All rights reserved.
//

// https://programmers.co.kr/learn/courses/30/lessons/43104

#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    
    long long fibo[1000] = {0, };
    
    fibo[1] = 1;
    fibo[2] = 1;
    
    for(int i=3; i<=N; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    answer += (fibo[N]+fibo[N-1])*2;
    answer += (fibo[N-1]+fibo[N-2])*2;
    
    return answer;
}
