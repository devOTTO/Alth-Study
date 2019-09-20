#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    for(int i=0;i<priorities.size();i++){
        q.push(priorities[i]);
    }
    while (!q.empty()) {
        int nowPrior=q.front(); q.pop();
        if(nowPrior!=*max_element(priorities.begin(),priorities.end())){
            //현재우선순위가 최고 우선순위보다 작으면 뒤로 다시 넣어주고
            q.push(nowPrior);
            //찾고자 하는 location의 인덱스도 수정해준다.
            if(location==0){
                location=priorities.size()-1;
            }else{
                location--;
            }
        }
        else{
            //현재 우선순위와 일치하면 우선순위에서 지워주고
            //지운 순서를 플러스해준다.
            answer++;
            if(location!=0){
                location--; //location도 갱신해준다.
                priorities.erase(max_element(priorities.begin(),priorities.end()));
            }
            else{ //location이 0이면 요청한 인쇄이므로 종료하고 answer반환
                break;
            }
        }
    }
    return answer;
}