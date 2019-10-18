#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<list>
#include<set>
using namespace std;

typedef struct {
	int y; int x; int s; int d; int z; //�ӵ�, ����, ũ��
}shark;

int main() {
	int r, c, m; cin >> r >> c >> m;
	vector<vector<shark>> v(r, vector<shark>(c));
	vector<vector<int>> loc(r, vector<int>(c, 0));
	set<pair<int, int>> svector;
	for (int i = 0; i < m; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		y -= 1; x -= 1; d -= 1;
		v[y][x].s = s; v[y][x].d = d; v[y][x].z = z;//��� ����
		loc[y][x] = 1; //����ִ����� ����
		svector.insert(make_pair(y, x));
	}
	int time = 0;
	int sum = 0;
	while (time < c) {

		//���ÿ��� ����� �� ����
		for (int i = 0; i < r; i++) {//���� ����� �� ã�´�.
			if (loc[i][time] != 0) { //�ش� ��ġ�� �� ������
				sum += v[i][time].z; //�ش� ��� ũ�⸦ �����ְ�
									 //�ش� ����� ������ �����Ѵ�.
				svector.erase(svector.find(make_pair(i, time)));

				loc[i][time] = 0; //��ġ�� �����ش�.
				break; //����� ���ã�� ����
			}
		}
		//cout << "svector size: " << int(svector.size()) << endl;
		//����̵�
		set<pair<int, int>> svector_temp; //�̵��� ������ ��ġ�� ��� �ӽú���
		vector<vector<int>> loc_temp(r, vector<int>(c, 0)); //loc�� �ӽ�
		vector<vector<shark>> v_temp(r, vector<shark>(c)); //v�� �ӽ�
		set<pair<int, int>>::iterator it;
		for (it = svector.begin(); it != svector.end(); it++) {
			int y = (*it).first;  int x = (*it).second; //���� ������ ��ġ�� �ҷ��´�.
			int s = v[y][x].s; int d = v[y][x].d; int z = v[y][x].z; //�� ������ �ҷ��´�.
																	 //��, �Ʒ�, ��, �� 0,1,2,3
																	 //���⿡ ���� �ӵ���ŭ �̵�
																	 //���� �ش� ��ġ�� �� ������ ������ ���� �ؾ��Ѵ�.
			int ny = y; int nx = x; int nd = d;
			int speed = s;
			if (d == 0 || d == 1) { //y
				speed = s % (2 * (r - 1));
				while (speed--) {//�ѹ��� ��� �Ű��ش�.
					if (ny == 0) { //0�̵Ǹ� ������ �ٲ��ش�.
						nd = 1;
					}
					if (ny == r - 1) {
						nd = 0;
					}
					if (nd == 0) {//����
						ny--;
					}
					else {//�Ʒ���
						ny++;
					}
				}
			}
			else if (d == 2 || d == 3) {//x
				speed = s % (2 * (c - 1));
				while (speed--) {
					if (nx == 0) { //0�̵Ǹ� ������ 2(������)����
						nd = 2;
					}
					if (nx == c - 1) {//���� ������ �÷��������� ������ 3(����)����
						nd = 3;
					}
					if (nd == 2) {
						nx++;
					}
					else {
						nx--;
					}
				}
			}

			//�������־�� �� �ڷᱸ��: ����, ��ġ����, ��ġ��� �迭
			if (loc_temp[ny][nx] != 0) {//�̹� ������ ũ�� ��
				if (v_temp[ny][nx].z < z) {//���� �� �̹� �ִ� ���� ũ��
										   //������ ������Ʈ ���ش�.

					shark temp_shark; //����
					temp_shark.y = ny; temp_shark.x = nx; temp_shark.d = nd;
					temp_shark.s = s; temp_shark.z = z;

					v_temp[ny][nx] = temp_shark; //��ġ��� ����
				}
			}
			else {//ó���̸� �׳� ���� �ִ´�.
				shark temp_shark;
				temp_shark.y = ny; temp_shark.x = nx; temp_shark.d = nd;
				temp_shark.s = s; temp_shark.z = z;

				svector_temp.insert(make_pair(ny, nx)); //��� ���Ϳ� �ְ�
				loc_temp[ny][nx] = 1; //�ε����� ��ġ���Ϳ� �ְ�
				v_temp[ny][nx] = temp_shark; //��ġ��� �迭
			}
		}
		//������ ����
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				loc[i][j] = loc_temp[i][j];
				v[i][j] = v_temp[i][j];
				//cout << loc[i][j] << " ";
			}
			//cout << "\n";
		}
		//cout << "\n";
		svector.clear();
		for (it = svector_temp.begin(); it != svector_temp.end(); it++) {
			svector.insert(*it);
		}
		time++;
	}
	cout << sum << "\n";
	return 0;
}