//
//  0920_stack-queue_42587.cpp
//  alth
//
//  Created by 김경이 on 2019. 9. 20..
//  Copyright © 2019년 김경이. All rights reserved.
//

// https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while(priorities.size() != 0) {
        int flag = 0;
        for(int i=1; i<priorities.size(); i++) {
            if(priorities[i] > priorities[0]) {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1) {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            
            if(location == 0) {
                location = (priorities.size())-1;
            }
            else
                location--;
            
            continue;
        }
        
        priorities.erase(priorities.begin());
        answer++;
        
        if(location == 0)
            break;
        location--;
    }
    
    return answer;
}
