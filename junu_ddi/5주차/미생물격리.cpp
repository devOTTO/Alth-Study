#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stdio.h>
using namespace std;

int dy[] = { -1,0,1,0 }; //상, 우, 하, 좌
int dx[] = { 0,1,0,-1 };
typedef struct {
	int y; int x; int dir; int num;
	unsigned operator==(const pair<int,int> a) {
		return(a.first==y&&a.second==x);
	}
}mis;

vector<int> answers;
int n, m, k; //n 크기, m 격리시간, k 미생물군집개수
int sum = 0;

bool cmp(const mis &a, const mis &b) {
	if (a.num > b.num) {
		return true;
	}
	else 
		return false;
}

int main() {
	//freopen("C:\input.txt", "r", stdin);
	int t; cin >> t;
	while (t--) {
		sum = 0;
		cin >> n >> m >> k;
		//vector<vector<int> > v(n + 1, vector<int>(n + 1));
		vector<vector<mis> > q(1003);
		//vector<map<pair<int, int>, mis > > q(1003);
		for (int i = 0; i < k; i++) {
			int y, x, num, dir;
			mis temp;
			cin >> y >> x >> num >> dir;
			if (dir == 1) {//상
				dir = 0;
				temp.y = y; temp.x = x; temp.num = num;
				temp.dir = dir;
			}
			else if (dir == 2) {//하
				dir = 2;
				temp.y = y; temp.x = x; temp.num = num;
				temp.dir = dir;
			}
			else if (dir == 3) {//좌
				dir = 3;
				temp.y = y; temp.x = x; temp.num = num;
				temp.dir = dir;
			}
			else {//우
				dir = 1;
				temp.y = y; temp.x = x; temp.num = num;
				temp.dir = dir;
			}
			q[1].push_back(temp); //m이 1일때
		}
		sort(q[1].begin(), q[1].end(), cmp);
		/*for (int i = 0; i < q[1].size(); i++) {
			cout << q[1][i].num << " ";
		}*/
		
		int time = 1;
		while (time <= m) {
			vector<vector<mis> > Vtemp(n, vector<mis>(n)); //미생물 담을 벡터
			/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
			cout << Vtemp[i][j].num << " ";
			}
			cout << endl;
			}*/
			
			for (int i=0 ; i< q[time].size(); i++) {
				//한개씩 미생물 군집을 가져와서 새로운 거(Vtemp)에 넣는다.
				mis temp;
				int y = q[time][i].y; int x = q[time][i].x;
				int num = q[time][i].num; int dir = q[time][i].dir;
				int ny = y + dy[dir]; int nx = x + dx[dir];

				//약품구역으로 가면
				if (ny == 0 || ny == n - 1 || nx == 0 || nx == n - 1) {
					num = num / 2; dir = (dir + 2) % 4;//절반이 되고 방향은 반대가 됨.
					//cout << ny << "," << nx << ": " << num << dir << endl;
					//0이면 군집은 사라짐 다음에 넣어줄 필요 없음
					if (num == 0)
						continue;
					//0이 아니면 다음 시간에 군집벡터에 넣어준다.
					temp.y = ny; temp.x = nx; temp.num = num; temp.dir = dir;
					q[time+1].push_back(temp);
					//그리고 새로운 Vtemp에도 넣어준다.
					Vtemp[ny][nx] = temp;
				}
				else if (Vtemp[ny][nx].num == 0) {//빈칸일때는 그냥 넣어준다.
					temp.y = ny; temp.x = nx; temp.num = num; temp.dir = dir;
					q[time + 1].push_back(temp);
					Vtemp[ny][nx] = temp;
				}
				else if (Vtemp[ny][nx].num != 0) {
					//이미 다른 군집이 있으면 이미 있는게 큰 것이므로 값만 더해준다.
					temp.y = ny; temp.x = nx; temp.num = num; temp.dir = dir;

					temp.num = Vtemp[ny][nx].num + num;
					Vtemp[ny][nx].num = temp.num; //맵의 값 갱신
					//벡터의 값 갱신
					vector<mis>::iterator it;
					it = find(q[time + 1].begin(), q[time + 1].end(), make_pair(ny, nx));
					(*it).num = temp.num;
				}
			}
			sort(q[time + 1].begin(), q[time + 1].end(), cmp);
			if (time == m) {//m시간이 되면 개수를 파악한다.
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						sum += Vtemp[i][j].num;
					}
				}
			}
			time++;
		}
		answers.push_back(sum);
	}
	for (int i = 0; i < answers.size(); i++) {
		cout << "#"<<i+1<<" "<<answers[i] << "\n";
	}
	return 0;
}
