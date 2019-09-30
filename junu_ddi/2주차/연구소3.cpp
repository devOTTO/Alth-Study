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
int road; //빈칸

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
				//벽을 -2로 해준다.
				v[i][j] = -2;
			}
			else {
				v[i][j] = a;
				if (a == 0) //빈칸이면
					road++; //빈칸의 개수를 측정해준다.
			}
			if (a == 2) virus.push_back(make_pair(i, j));	//바이러스 위치 저장
		}
	}

	//조합을 사용해 활성화할 바이러스의 경우의 수를 따진다.
	vector<int> order;
	for (int i = 0; i < virus.size(); i++) {
		if (i < int(virus.size()) - m) {
			order.push_back(0);
		}
		else order.push_back(1);
		//바이러스 개수만큼 1을 넣어서 활성화 할 바이러스 경우를 다 다르게 해본다.
	}

	//우선 빈칸없이 전부 바이러스인지 체크
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


	int ans = 99999; //최솟값을 구할 ans
	do {
		memset(visited, 0, sizeof(visited));
		int temp_road = road; //빈칸 수를 복사한다.
		vector<vector<int>> copy = v; //여러번 돌리기 위해서 지도를 복사
		queue<pair<int, int>> q; //바이러스를 퍼뜨리는 과정을 담을 큐
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 1) {
				//활성화 시킬 m개의 바이러스를 선택해서 큐에 담아준다.
				q.push(virus[i]);
				copy[virus[i].first][virus[i].second] = 0; //활성화시킬 바이러스 시작 초를 0으로 바꿔준다.
				visited[virus[i].first][virus[i].second] = 1; //빈칸으로 인식해 다시 큐에 들어가면 안되므로 방문처리
			}
			else {
				copy[virus[i].first][virus[i].second] = -1;
				//비활성화 상태의 바이러스를 -1로 바꿔준다.
			}

		}

		int t = 0; //시간 측정을 위한 t
		while (!q.empty()) {
			if (temp_road == 0) {
				//빈칸 수가 0이 되면 다 퍼진 것이므로 이전 것과 비교해서 최소인지 확인한다.
				ans = min(ans, t);
				break;
			}
			int y = q.front().first; int x = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				//범위 벗어나면 취소 
				if (0 > ny || ny >= n || 0 > nx || nx >= n) {
					continue;
				}
				else if (copy[ny][nx] == 0 && visited[ny][nx] == 0) { //빈칸이고 방문한 적 없으면
																	  //cout << ny << ", " << nx << endl;
					copy[ny][nx] = copy[y][x] + 1;
					if (t < copy[ny][nx]) t = copy[ny][nx]; //날짜 값의 최대값을 찾는다.
					visited[ny][nx] = 1; //방문처리 해준다.
					q.push(make_pair(ny, nx));
					//바이러스가 옮겨졌으므로 큐에 넣어준다.
					temp_road--; //빈칸이 하나 줄었다.
				}
				else if (copy[ny][nx] == -1) {
					//비활성화 바이러스인 경우는 최댓값을 최신화 시키지 않는다.
					//빈칸을 줄이지 않고 날짜 갱신하고 큐에 넣어준다.
					copy[ny][nx] = copy[y][x] + 1;
					visited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	} while (next_permutation(order.begin(), order.end()));

	if (ans == 99999) cout << -1 << "\n"; //어떻게 해도 모든 빈칸에 바이러스 퍼뜨리지 못하는 경우
	else
		cout << ans << "\n";

	return 0;
}

