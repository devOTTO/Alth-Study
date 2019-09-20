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
            //����켱������ �ְ� �켱�������� ������ �ڷ� �ٽ� �־��ְ�
            q.push(nowPrior);
            //ã���� �ϴ� location�� �ε����� �������ش�.
            if(location==0){
                location=priorities.size()-1;
            }else{
                location--;
            }
        }
        else{
            //���� �켱������ ��ġ�ϸ� �켱�������� �����ְ�
            //���� ������ �÷������ش�.
            answer++;
            if(location!=0){
                location--; //location�� �������ش�.
                priorities.erase(max_element(priorities.begin(),priorities.end()));
            }
            else{ //location�� 0�̸� ��û�� �μ��̹Ƿ� �����ϰ� answer��ȯ
                break;
            }
        }
    }
    return answer;
}