//
//  0920_brute-force_42840.cpp
//  alth
//
//  Created by 김경이 on 2019. 9. 20..
//  Copyright © 2019년 김경이. All rights reserved.
//

// https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int result[3] = {0, };
    
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == a[i%5])
            result[0]++;
        if(answers[i] == b[i%8])
            result[1]++;
        if(answers[i] == c[i%10])
            result[2]++;
    }
    
    int max = 0;
    for(int i=0; i<3; i++) {
        if(max<result[i])
            max = result[i];
    }
    
    for(int i=0; i<3; i++) {
        if(max == result[i])
            answer.push_back(i+1);
    }
    
    return answer;
}
