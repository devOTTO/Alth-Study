//
// Created by 융미 on 2019-09-21.
//

#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long arr[81] = {0,};
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i<81; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    answer = 2*(2*arr[N]+arr[N-1]);

    return answer;
}