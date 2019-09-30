#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<deque>
#include<map>
#include<queue>
#include<cstring>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int visited[50][50];
int road; //��ĭ

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n));
	//vector<vector<int>> virus(n, vector<int>(n));
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				//���� -2�� ���ش�.
				v[i][j] = -2;
			}
			else {
				v[i][j] = a;
				if (a == 0) //��ĭ�̸�
					road++; //��ĭ�� ������ �������ش�.
			}
			if (a == 2) virus.push_back(make_pair(i, j));	//���̷��� ��ġ ����
		}
	}

	//������ ����� Ȱ��ȭ�� ���̷����� ����� ���� ������.
	vector<int> order;
	for (int i = 0; i < virus.size(); i++) {
		if (i < int(virus.size()) - m) {
			order.push_back(0);
		}
		else order.push_back(1);
		//���̷��� ������ŭ 1�� �־ Ȱ��ȭ �� ���̷��� ��츦 �� �ٸ��� �غ���.
	}

	//�켱 ��ĭ���� ���� ���̷������� üũ
	int flag2 = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 0)
				flag2 = false;
		}
	}
	if (flag2 == true) {
		cout << 0 << "\n";
		return 0;
	}


	int ans = 99999; //�ּڰ��� ���� ans
	do {
		memset(visited, 0, sizeof(visited));
		int temp_road = road; //��ĭ ���� �����Ѵ�.
		vector<vector<int>> copy = v; //������ ������ ���ؼ� ������ ����
		queue<pair<int, int>> q; //���̷����� �۶߸��� ������ ���� ť
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 1) {
				//Ȱ��ȭ ��ų m���� ���̷����� �����ؼ� ť�� ����ش�.
				q.push(virus[i]);
				copy[virus[i].first][virus[i].second] = 0; //Ȱ��ȭ��ų ���̷��� ���� �ʸ� 0���� �ٲ��ش�.
				visited[virus[i].first][virus[i].second] = 1; //��ĭ���� �ν��� �ٽ� ť�� ���� �ȵǹǷ� �湮ó��
			}
			else {
				copy[virus[i].first][virus[i].second] = -1;
				//��Ȱ��ȭ ������ ���̷����� -1�� �ٲ��ش�.
			}

		}

		int t = 0; //�ð� ������ ���� t
		while (!q.empty()) {
			if (temp_road == 0) {
				//��ĭ ���� 0�� �Ǹ� �� ���� ���̹Ƿ� ���� �Ͱ� ���ؼ� �ּ����� Ȯ���Ѵ�.
				ans = min(ans, t);
				break;
			}
			int y = q.front().first; int x = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				//���� ����� ��� 
				if (0 > ny || ny >= n || 0 > nx || nx >= n) {
					continue;
				}
				else if (copy[ny][nx] == 0 && visited[ny][nx] == 0) { //��ĭ�̰� �湮�� �� ������
																	  //cout << ny << ", " << nx << endl;
					copy[ny][nx] = copy[y][x] + 1;
					if (t < copy[ny][nx]) t = copy[ny][nx]; //��¥ ���� �ִ밪�� ã�´�.
					visited[ny][nx] = 1; //�湮ó�� ���ش�.
					q.push(make_pair(ny, nx));
					//���̷����� �Ű������Ƿ� ť�� �־��ش�.
					temp_road--; //��ĭ�� �ϳ� �پ���.
				}
				else if (copy[ny][nx] == -1) {
					//��Ȱ��ȭ ���̷����� ���� �ִ��� �ֽ�ȭ ��Ű�� �ʴ´�.
					//��ĭ�� ������ �ʰ� ��¥ �����ϰ� ť�� �־��ش�.
					copy[ny][nx] = copy[y][x] + 1;
					visited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	} while (next_permutation(order.begin(), order.end()));

	if (ans == 99999) cout << -1 << "\n"; //��� �ص� ��� ��ĭ�� ���̷��� �۶߸��� ���ϴ� ���
	else
		cout << ans << "\n";

	return 0;
}

