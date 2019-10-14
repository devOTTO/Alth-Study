#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

typedef struct {
	int x; int y; int Size; int Eat_Num; int Time;
}Shark;
typedef struct {
	int x; int y; int Dist;
}Food;

int arr[20][20];
bool visit[20][20];
Shark s;
vector<Food> v;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

bool sort_dist(Food &a, Food &b)
{
	if (a.Dist <= b.Dist) {
		if (a.Dist == b.Dist) {
			if (a.y <= b.y) {
				if (a.y == b.y) {
					if (a.x < b.x) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			arr[i][j] = a;
			if (a == 9) {
				s.y = i; s.x = j;
				s.Size = 2; s.Eat_Num = 0;
				s.Time = 0;
			}

		}
	}

	while (1) {
		v.clear();
		memset(visit, false, sizeof(visit));

		queue<pair<pair<int, int>, int>> q;
		q.push(make_pair(make_pair(s.y, s.x), 0));
		visit[s.y][s.x] = true;

		while (q.empty() == 0) {
			int y = q.front().first.first; int x = q.front().first.second;
			int dist = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)
					continue;
				if (!visit[ny][nx]) {
					//0�� ����Ⱑ ���� ���
					if (arr[ny][nx] == 0) {
						visit[ny][nx] = true; //�湮ó�����ְ�
						q.push(make_pair(make_pair(ny, nx), dist + 1));
					}
					//��� ����� ����⺸�� ū ���-> �Դ´�
					else if (arr[ny][nx] < s.Size) {
						Food Temp; Temp.y = ny; Temp.x = nx;
						Temp.Dist = dist + 1; //������ �Ÿ��� ��������� �ȴ�.
						v.push_back(Temp); //���� �� �ִ� ����⺤�Ϳ� �־��ش�.
						visit[ny][nx] = true;
						q.push(make_pair(make_pair(ny, nx), dist + 1));
					}//���� ��������� ���� ���
					else if (arr[ny][nx] == s.Size) {
						visit[ny][nx] = true;
						q.push(make_pair(make_pair(ny, nx), dist + 1));
					}
				}
			}
		}
		if (v.size() == 0) {//���̻� ���� �� �ִ� ����Ⱑ ������ ���
			cout << s.Time << endl;
			break;
		}
		else if (v.size() == 1) { //���� �� �ִ� ����Ⱑ �ϳ��̸�
			arr[v[0].y][v[0].x] = 9; //�ش� ����⸦ �԰� �����ġ�� �������ش�.
			arr[s.y][s.x] = 0; //���� ��� ��ġ�� 0���� �ٲ��ش�.
			s.y = v[0].y; s.x = v[0].x;
			s.Eat_Num++; s.Time = s.Time + v[0].Dist;
			if (s.Eat_Num == s.Size) { //���� ������ �����ŭ�̸� ������+1 ���ش�.
				s.Eat_Num = 0; s.Size++;
			}

		}
		else { //���� �� �ִ� ����� ������ �������̸� ���ش�� ���Ľ��Ѽ� �� ù��°���� �Դ´�.
			sort(v.begin(), v.end(), sort_dist);
			arr[v[0].y][v[0].x] = 9;
			arr[s.y][s.x] = 0;
			s.y = v[0].y; s.x = v[0].x;
			s.Eat_Num++; s.Time = s.Time + v[0].Dist;
			if (s.Eat_Num == s.Size) {
				s.Eat_Num = 0; s.Size++;
			}
		}
	}

	return 0;
}