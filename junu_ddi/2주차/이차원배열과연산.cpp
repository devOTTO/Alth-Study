#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<deque>
#include<map>
#include<cstring>
using namespace std;

int v[100][100];
//�ʱ�ȭ�Ҷ� �߰��� 0 ������ �ʱ�ȭ�� ���߰� �ؼ� �ڿ� ���ڰ� �����ִ� ��찡 �־ Ʋ����.

int main() {
	int r, c, k; cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}
	int time = 0; //�ð� üũ
	int flag = 0; //0�϶� �࿬��(���� ����(����)>=���� ����(����)), 1�϶� ������(����<����)
	int row_max = 3; //�� �ִ� ���� ����
	int col_max = 3; //�� �ִ� ���� ����
	while (time <= 100) {
		if (v[r - 1][c - 1] == k) { // ã���� ��� �� ��
			cout << time << "\n";
			return 0;
		}
		//�࿬��: ó���� �࿬��
		if (flag == 0) {
			int col_end = col_max; col_max = 0; //���� ������ ������ �� �� �����Ƿ� �����صд�.
			for (int i = 0; i<row_max; i++) {
				map<int, int> m;
				for (int j = 0; j<col_end; j++) {
					if (v[i][j] != 0 && m.find(v[i][j]) == m.end()) {//������ map�� �߰�
						m.insert(make_pair(v[i][j], 1));
					}
					else if (v[i][j] != 0) {//������ ������ �߰��Ͽ� ������ ���ڿ� �� ������ map�� ����
						m[v[i][j]]++;
					}
				}
				vector<std::pair<int, int>> temp; //map�� �󵵼��� ���� �������� temp����
				map<int, int>::iterator it;
				for (it = m.begin(); it != m.end(); it++) { //temp���� �����ϰ�
					temp.push_back(make_pair(it->first, it->second));
				}
				//pair�� �ι�° ���� �������� �������ش�.
				std::sort(temp.begin(), temp.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
					if (l.second != r.second)
						return l.second < r.second;
					else if (l.second == r.second)
						return l.first < r.first;
				});

				vector<int> ele;
				vector<pair<int, int>>::iterator it2; //ele ���Ϳ� �ϳ��� �� �־��ش�.
				for (it2 = temp.begin(); it2 != temp.end(); it2++) {
					ele.push_back(it2->first); ele.push_back(it2->second);
				}

				if (col_max<int(ele.size())) {//���� ���� ������ ũ�ٸ� 
					if (int(ele.size()) <= 100) {
						col_max = int(ele.size()); //�� �ִ� ���� ����
					}
					else
						col_max = 100;
				}

				for (int j = 0; j < 100; j++) {
					if (j < ele.size()) { //i��° ���� ���Ž����ش�.
						v[i][j] = ele[j];
					}
					else
						v[i][j] = 0; //�������� 0���� ����
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
		//������
		else {
			int row_end = row_max; row_max = 0; //���� �ִ� ������ ������ �ǹǷ� �����صд�.
			for (int i = 0; i<col_max; i++) { //i�� �̹��� ���� ���� ���߿� ó��
				map<int, int> m; //������ ���� ���� map 
								 //�� ���� ���� ����
				for (int j = 0; j < row_end; j++) {
					if (v[j][i] != 0 && m.find(v[j][i]) == m.end()) {//������ map�� �߰�
						m.insert(make_pair(v[j][i], 1));
					}
					else if (v[j][i] != 0) {//������ ������ �߰�.
						m[v[j][i]]++;
					}
				}

				vector<std::pair<int, int>> temp; //map�� �������� temp����
				map<int, int>::iterator it;
				for (it = m.begin(); it != m.end(); it++) {
					temp.push_back(make_pair(it->first, it->second));
				}
				std::sort(temp.begin(), temp.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
					if (l.second != r.second)
						return l.second < r.second;
					else if (l.second == r.second)
						return l.first < r.first;
				}); //pair�� �ι�° ���� �������� �������ش�.

					//���� ���� ����� ����: ���⼭ �ش� ���� �迭�� �������־�� �Ѵ�.
				vector<int> ele;
				vector<pair<int, int>>::iterator it2; //�ϳ��� �� �־��ش�.
				for (it2 = temp.begin(); it2 != temp.end(); it2++) {
					ele.push_back(it2->first); ele.push_back(it2->second);
				}
				if (row_max<int(ele.size())) {
					if (int(ele.size()) <= 100) {
						row_max = int(ele.size()); //�� �ִ� ���� ����
					}
					else
						row_max = 100;
				}
				for (int j = 0; j < 100; j++) {
					if (j < ele.size()) {
						v[j][i] = ele[j];
					}
					else
						v[j][i] = 0; //�������� 0���� �־��ش�.
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