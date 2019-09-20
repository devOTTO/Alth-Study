#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> who(4);
	vector<int> stu1(10001);
	vector<int> stu2(10001);
	vector<int> stu3(10001);
	int stuex1[10] = { 1,2,3,4,5,1,2,3,4,5 };
	int stuex2[8] = { 2,1,2,3,2,4,2,5 };
	int stuex3[10] = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i<10001; i++) {
		stu1[i] = stuex1[i % 10];
		stu2[i] = stuex2[i % 8];
		stu3[i] = stuex3[i % 10];
	}//각 학생들의 답안을 넣어준다(만개)
	for (int i = 0; i<answers.size(); i++) {
		//각 학생들의 답안과 실제 답안과 비교해서 맞으면 who에 플러스해준다.
		if (answers[i] == stu1[i])
			who[1]++;
		if (answers[i] == stu2[i])
			who[2]++;
		if (answers[i] == stu3[i])
			who[3]++;
	}
	int maxindex = 0;
	for (int i = 1; i<who.size(); i++) {
		if (maxindex<who[i]) {
			//만약 최댓값이 새로 생기면 배열 비우고 다시 첨부터 채운다
			answer.clear();
			answer.push_back(i);
			maxindex = who[i];
		}
		else if (maxindex == who[i]) {
			//최댓값과 같으면 배열에 추가해준다.
			answer.push_back(i);
		}
	}

	return answer;
}