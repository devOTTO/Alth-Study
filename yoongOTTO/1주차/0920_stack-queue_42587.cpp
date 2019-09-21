//
// Created by 융미 on 2019-09-21.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<int*> ptr_arr;
    deque<int> arr;

    for(int i = 0; i<priorities.size(); i++)
    {
        arr.push_back(priorities[i]);
        ptr_arr.push_back(&arr[i]);
    }

    int* ptr = &arr[location];

    int count = 0;
    while(arr.size()!=0)
    {
        deque<int*>::iterator iter_front = ptr_arr.begin();
        int front = arr.front();
        int* ptr_front = ptr_arr.front();
        arr.pop_front();
        ptr_arr.pop_front();

        int arrSize = arr.size();
        int max = *max_element(arr.begin(), arr.end());

        if(max > front) //만약 max가 존재하면 뒤로가고 break 상황 아님
        {
            arr.push_back(front);
            ptr_arr.push_back(ptr_front);
        }
        else //max 없으면 그냥 인쇄하는 경우
            count++;
        if(ptr == *iter_front && !(max>front))
            break;
    }
    answer = count;

    return answer;
}