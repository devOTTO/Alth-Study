//
// Created by 융미 on 2019-09-21.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size = answers.size();
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int counts[3] = {0,};

    for(int i=0; i<size; i++) {
        if(answers[i] == a[i%5])
            counts[0]++;
        if(answers[i] == b[i%8])
            counts[1]++;
        if(answers[i] == c[i%10])
            counts[2]++;
    }

    int max = *max_element(counts, counts+3);
    for(int i = 0; i<3; i++)
    {
        if(counts[i] == max)
            answer.push_back(i+1);
    }

    return answer;
}