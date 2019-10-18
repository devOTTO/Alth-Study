#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<list>
using namespace std;

int na[50][50];
int visit[50][50];
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int main() {
	int n, l, r; cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			na[i][j] = a;
		}
	}
	int year = 0;
	while (1) {
		year++;
		vector<vector<int>> temp(n, vector<int>(n));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) { //�湮 �������� �־��ش�.
					cnt++;
					visit[i][j] = 1;
					queue<pair<int, int>> q; //�湮ó���� ť
					vector<pair<int, int>> uniGroup;//����ó���� ���� ť
					q.push(make_pair(i, j));
					uniGroup.push_back(make_pair(i, j));
					int sum = 0;
					while (!q.empty()) {
						int y = q.front().first; int x = q.front().second; q.pop();
						sum += na[y][x];
						for (int k = 0; k < 4; k++) {
							int ny = y + dy[k]; int nx = x + dx[k];
							if (ny < 0 || ny >= n || nx < 0 || nx >= n)
								continue;
							int sub = na[ny][nx] - na[y][x];
							if (sub < 0) sub = -1 * sub;
							if (!visit[ny][nx] && sub >= l && sub <= r) {//���� ���̸� ť�� �־��༭ �� Ž��
								visit[ny][nx] = 1; //�湮���ְ�
								q.push(make_pair(ny, nx)); //���� Ž���� ���� ť�� �־��ְ�
								uniGroup.push_back(make_pair(ny, nx)); //���� ���տ� �־��ش�.
							}
						}
					}
					for (int k = 0; k < uniGroup.size(); k++) {
						int y = uniGroup[k].first; int x = uniGroup[k].second;
						int unisize = int(uniGroup.size());
						temp[y][x] = sum / unisize; //���ŵ� �ӽ� ����
					}
				}
			}
		}
		//�ѹ� ����Ŭ ������ �ٽ� visit�ʱ�ȭ
		memset(visit, 0, sizeof(visit));

		//�̵��� ������ ���� �������ش�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				na[i][j] = temp[i][j];
				temp[i][j] = 0;
			}
		}
		if (cnt == n * n) {//���� �̵��� ���̻� �Ͼ�� ������ �� ������ ������ ���� ���
			cout << year - 1 << "\n";
			break;
		}
		cnt = 0;
	}



	return 0;
}