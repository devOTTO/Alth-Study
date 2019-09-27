//
//  tile.cpp
//  test
//
//  Created by 김혜진 on 27/09/2019.
//  Copyright © 2019 None. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    
    long long cur = 1, post = 1;
    for (int i = 1; i < N+1; i++)
    {
        if (i > 2)
        {
            int num = cur;
            cur += post;
            post = num;
        }
    }
    
    if (N == 1){
        answer = 4;
    }else{
        answer = cur * 2 ㅁㅁㅁ+ (cur + post) * 2 ;
    }
    
    //cout << result << endl;
    return answer;
}
