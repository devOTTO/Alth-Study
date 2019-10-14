#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

int a[10][10]; //�ܿ︶�� �߰��Ǵ� ���
int yang[10][10]; //���� ���
vector<int> tree[10][10]; //�������� ���̸� �����ϴ� ����
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int, int>>> q(k + 1); //k�⿡ �ִ� ������ ����
											 //vector<pair<int, int>> v;
											 //memset(yang, 5, sizeof(int)); //�ʱ� ����� 5�� �ʱ�ȭ

											 //memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			yang[i][j] = 5;
			cin >> a[i][j]; //�ܿ︶�� �߰��Ǵ� ���
		}
	}
	/*for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	cout << yang[i][j] << " ";
	}
	cout << endl;
	}*/

	for (int i = 0; i < m; i++) {
		int y, x, z; cin >> y >> x >> z;
		tree[y - 1][x - 1].push_back(z); //�ε����̹Ƿ� -1 ó�����ش�. �������� ��ġ�� ���̸� ����
		q[0].push_back(make_pair(y - 1, x - 1)); //0�⿡���� �����ִ� ��ġ�� ���Ϳ� �־��ش�.
	}

	int year = 0;
	while (year < k) { //k�� ���� �ݺ������ش�.
					   //q[year].erase(unique(q[year].begin(), q[year].end()), q[year].end()); //��ġ �ߺ��� �����ش�.
		vector<int> temp[10][10]; //�ش�⵵�� ����� ������ �����ϴ� �迭
		int temp_yang[10][10]; memset(temp_yang, 0, sizeof(temp_yang));
		int temp_del[10][10]; memset(temp_del, 0, sizeof(temp_del));
		while (!q[year].empty()) {  //�ش� ������ �������� ���� üũ���ش�.

			int y = q[year].back().first; int x = q[year].back().second; q[year].pop_back();
			//��
			for (int i = 0; i < tree[y][x].size(); i++) { //���ĵǾ� �����Ƿ� � �ͺ��� ���ش�.
				if (yang[y][x] - tree[y][x][i] >= 0) { //����� ���� �������̺��� ���ų� ������
					yang[y][x] -= tree[y][x][i]; //���ְ�
					tree[y][x][i]++; //���� +1 ���ش�.
									 //q[year + 1].push_back(make_pair(y, x));
									 //cout << y<<","<<x<<":"<<tree[y][x][i] << endl;
					if (tree[y][x][i] % 5 == 0) {//����: ���Ѱ��� 5�� ����̸� 8ĭ�� ������ �����.
						for (int j = 0; j < 8; j++) {
							int ny = y + dy[j]; int nx = x + dx[j];
							if (ny < 0 || ny >= n || nx < 0 || nx >= n) //���� üũ
								continue;
							temp[ny][nx].push_back(1);//������ ������ ���� �ӽ� �迭�� ����
													  //q[year + 1].push_back(make_pair(ny, nx)); //���� �⿡ Ž���� ��ġ�� �־��ش�.
						}
					}
				}
				else { //�ȵǸ� ������� ���ư��� �ϰ� �����Ѵ�. ���糪���� ������ �ڿ� ������ ������ �װԵȴ�.
					   //���� ������ �����ؾ� �ϹǷ� ������� ���ư� ���� �ӽ���������ߵȴ�.
					temp_yang[y][x] += tree[y][x][i] / 2; //����
					tree[y][x][i] = -1; //i��° ���� ������ ���� -1�� ó�����ش�.
				}
			}
		}



		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] == -1) { //����: -1ó���� ���ҵ��� �����Ѵ�.
						tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
						break;
					}
				}
				if (int(temp_yang[i][j] != 0)) { //����: �ӽ������ ����� ��к��Ϳ� �־��ش�.
					yang[i][j] += temp_yang[i][j];
				}
				if (int(temp[i][j].size()) != 0) {
					//����: ���� �߰��� ������ �־��ش�. temp�� �ִ� ���� tree�� ù��° �ε����� �־��ش�.
					for (int k = 0; k < temp[i][j].size(); k++) {
						tree[i][j].insert(tree[i][j].begin(), 1);
					}
				}
				yang[i][j] += a[i][j];//�ܿ�: ����� �����ش�.
									  //���
				if (int(tree[i][j].size()) != 0) {
					q[year + 1].push_back(make_pair(i, j)); //�������� �ִ� ��ġ�� q�� �������ش�.
															/*for (int k = 0; k < tree[i][j].size(); k++) {
															cout << i << "," << j << ": " << tree[i][j][k] << " yang: " << yang[i][j] << "\n";
															}*/
					sort(tree[i][j].begin(), tree[i][j].end());
				}
			}
		}
		//cout << "\n";
		year++;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += int(tree[i][j].size()); //�����ϴ� ��� �������� �����ش�.
		}
	}
	cout << sum << "\n";

	return 0;
}