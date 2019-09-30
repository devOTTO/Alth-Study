#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<deque>
#include<map>
#include<cstring>
using namespace std;

int v[100][100];
//초기화할때 중간에 0 나오면 초기화를 멈추게 해서 뒤에 숫자가 남아있는 경우가 있어서 틀렸음.

int main() {
	int r, c, k; cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}
	int time = 0; //시간 체크
	int flag = 0; //0일때 행연산(행의 개수(세로)>=열의 개수(가로)), 1일때 열연산(세로<가로)
	int row_max = 3; //행 최대 길이 저장
	int col_max = 3; //열 최대 길이 저장
	while (time <= 100) {
		if (v[r - 1][c - 1] == k) { // 찾으면 출력 후 끝
			cout << time << "\n";
			return 0;
		}
		//행연산: 처음은 행연산
		if (flag == 0) {
			int col_end = col_max; col_max = 0; //열의 개수가 변경이 될 수 있으므로 복사해둔다.
			for (int i = 0; i<row_max; i++) {
				map<int, int> m;
				for (int j = 0; j<col_end; j++) {
					if (v[i][j] != 0 && m.find(v[i][j]) == m.end()) {//없으면 map에 추가
						m.insert(make_pair(v[i][j], 1));
					}
					else if (v[i][j] != 0) {//있으면 개수를 추가하여 나오는 숫자와 그 개수를 map에 저장
						m[v[i][j]]++;
					}
				}
				vector<std::pair<int, int>> temp; //map을 빈도수에 따라 정렬해줄 temp벡터
				map<int, int>::iterator it;
				for (it = m.begin(); it != m.end(); it++) { //temp에다 복사하고
					temp.push_back(make_pair(it->first, it->second));
				}
				//pair의 두번째 값을 기준으로 정렬해준다.
				std::sort(temp.begin(), temp.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
					if (l.second != r.second)
						return l.second < r.second;
					else if (l.second == r.second)
						return l.first < r.first;
				});

				vector<int> ele;
				vector<pair<int, int>>::iterator it2; //ele 벡터에 하나씩 다 넣어준다.
				for (it2 = temp.begin(); it2 != temp.end(); it2++) {
					ele.push_back(it2->first); ele.push_back(it2->second);
				}

				if (col_max<int(ele.size())) {//만약 열의 개수가 크다면 
					if (int(ele.size()) <= 100) {
						col_max = int(ele.size()); //열 최대 개수 갱신
					}
					else
						col_max = 100;
				}

				for (int j = 0; j < 100; j++) {
					if (j < ele.size()) { //i번째 행을 갱신시켜준다.
						v[i][j] = ele[j];
					}
					else
						v[i][j] = 0; //나머지는 0으로 리셋
				}
			}
			/*cout << time << endl;
			for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
			printf("%2d", v[i][j]);
			}
			cout << endl;
			}*/
		}
		//열연산
		else {
			int row_end = row_max; row_max = 0; //행의 최대 개수가 갱신이 되므로 복사해둔다.
			for (int i = 0; i<col_max; i++) { //i가 이번엔 열로 들어가서 나중에 처리
				map<int, int> m; //개수를 세기 위한 map 
								 //한 열씩 연산 시작
				for (int j = 0; j < row_end; j++) {
					if (v[j][i] != 0 && m.find(v[j][i]) == m.end()) {//없으면 map에 추가
						m.insert(make_pair(v[j][i], 1));
					}
					else if (v[j][i] != 0) {//있으면 개수를 추가.
						m[v[j][i]]++;
					}
				}

				vector<std::pair<int, int>> temp; //map을 정렬해줄 temp벡터
				map<int, int>::iterator it;
				for (it = m.begin(); it != m.end(); it++) {
					temp.push_back(make_pair(it->first, it->second));
				}
				std::sort(temp.begin(), temp.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
					if (l.second != r.second)
						return l.second < r.second;
					else if (l.second == r.second)
						return l.first < r.first;
				}); //pair의 두번째 값을 기준으로 정렬해준다.

					//새로 숫자 만드는 과정: 여기서 해당 행의 배열을 리셋해주어야 한다.
				vector<int> ele;
				vector<pair<int, int>>::iterator it2; //하나씩 다 넣어준다.
				for (it2 = temp.begin(); it2 != temp.end(); it2++) {
					ele.push_back(it2->first); ele.push_back(it2->second);
				}
				if (row_max<int(ele.size())) {
					if (int(ele.size()) <= 100) {
						row_max = int(ele.size()); //열 최대 개수 갱신
					}
					else
						row_max = 100;
				}
				for (int j = 0; j < 100; j++) {
					if (j < ele.size()) {
						v[j][i] = ele[j];
					}
					else
						v[j][i] = 0; //나머지는 0으로 넣어준다.
				}
			}
			/*cout << time << endl;
			for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
			printf("%2d", v[i][j]);
			}
			cout << endl;
			}*/
		}
		time++;

		if (row_max >= col_max) flag = 0;
		else flag = 1;
	}
	if (time == 101)
		cout << -1 << "\n";
	return 0;
}