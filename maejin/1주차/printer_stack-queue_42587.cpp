//
//  printer.cpp
//  test
//
//  Created by 김혜진 on 27/09/2019.
//  Copyright © 2019 None. All rights reserved.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cur = 0;
    int max = *max_element(priorities.begin(), priorities.end());
    
    
    while(!priorities.empty())
    {
        
        if (*priorities.begin() == max)
        {
            answer++;
            
            if (cur == location)
            {
                break;
            }
            
            priorities.erase(priorities.begin());
            max = *max_element(priorities.begin(), priorities.end());
        }
        else
        {
            priorities.push_back(*priorities.begin());
            priorities.erase(priorities.begin());
            
            if (cur == location)
            {
                location = location+priorities.size();
            }
        }
        
        cur++;
    }
    
    return answer;
}
