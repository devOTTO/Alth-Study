//
//  42840.cpp
//  test
//
//  Created by 김혜진 on 27/09/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> answer;

    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int correct[3] = {0, };
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == a[i%5])
            correct[0]++;
        if(answers[i] == b[i%8])
            correct[1]++;
        if(answers[i] == c[i%10])
            correct[2]++;
    }
    
    int max = 0;
    for(int i = 0; i < 3; i++)
    {
        if( max < correct[i] )
        {
            max = correct[i];
            answer.clear();
            answer.push_back(i+1);
        }
        else if (max == correct[i])
            answer.push_back(i+1);
        
    }
    
    return answer;
}
