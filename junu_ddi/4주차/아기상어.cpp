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
					//0번 물고기가 없는 경우
					if (arr[ny][nx] == 0) {
						visit[ny][nx] = true; //방문처리해주고
						q.push(make_pair(make_pair(ny, nx), dist + 1));
					}
					//상어 사이즈가 물고기보다 큰 경우-> 먹는다
					else if (arr[ny][nx] < s.Size) {
						Food Temp; Temp.y = ny; Temp.x = nx;
						Temp.Dist = dist + 1; //상어와의 거리를 측정해줘야 된다.
						v.push_back(Temp); //먹을 수 있는 물고기벡터에 넣어준다.
						visit[ny][nx] = true;
						q.push(make_pair(make_pair(ny, nx), dist + 1));
					}//상어와 물고기사이즈가 같은 경우
					else if (arr[ny][nx] == s.Size) {
						visit[ny][nx] = true;
						q.push(make_pair(make_pair(ny, nx), dist + 1));
					}
				}
			}
		}
		if (v.size() == 0) {//더이상 먹을 수 있는 물고기가 없으면 출력
			cout << s.Time << endl;
			break;
		}
		else if (v.size() == 1) { //먹을 수 있는 물고기가 하나이면
			arr[v[0].y][v[0].x] = 9; //해당 물고기를 먹고 상어위치를 변경해준다.
			arr[s.y][s.x] = 0; //현재 상어 위치를 0으로 바꿔준다.
			s.y = v[0].y; s.x = v[0].x;
			s.Eat_Num++; s.Time = s.Time + v[0].Dist;
			if (s.Eat_Num == s.Size) { //먹은 개수가 사이즈만큼이면 사이즈+1 해준다.
				s.Eat_Num = 0; s.Size++;
			}

		}
		else { //먹을 수 있는 물고기 개수가 여러개이면 기준대로 정렬시켜서 젤 첫번째것을 먹는다.
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