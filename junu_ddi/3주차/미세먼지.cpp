#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

int r, c, t;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
int upairy, upairx, downairy, downairx;
int v[50][50];

int main() {

	cin >> r >> c >> t;
	vector<pair<int, int>> start;
	vector<queue<pair<int, int>>> qs(1001); //초마다의 먼지들이 담긴 좌표큐 배열
	int flag = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int a; cin >> a;
			v[i][j] = a;
			if (a != -1 && a != 0) { //공기청정기(-1)이 아니고 빈칸이 아니면 먼지값 저장
				qs[1].push(make_pair(i, j));
			}
			if (flag == 0 && a == -1) { //공기청정기 윗칸이면 해당 위치를 저장한다.
				upairy = i; upairx = j;
				flag = 1;
			}
			else if (flag == 1 && a == -1) { //아래칸이면 해당 위치를 저장한다.
				downairy = i; downairx = j;
			}
		}
	}
	//cout << downairy << downairx << endl;
	for (int i = 1; i <= t; i++) {
		int plus[50][50];//매초마다 변화하는 먼지현황을 담는 배열
		memset(plus, 0, sizeof(plus));
		plus[upairy][upairx] = -1; plus[downairy][downairx] = -1; //공기청정기 저장
		while (!qs[i].empty()) {
			int y = qs[i].front().first; int x = qs[i].front().second; qs[i].pop(); //먼지를 꺼내온다.
			int cnt = 0;
			plus[y][x] += v[y][x]; //먼지 지수를 복사
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j]; int nx = x + dx[j];
				if (0 > ny || ny >= r || 0 > nx || nx >= c || (ny == upairy && nx == upairx) || (ny == downairy && nx == downairx))
					//범위 밖이거나 청정기일때 취소
					continue;
				plus[ny][nx] += v[y][x] / 5;
				cnt++;

			}
			plus[y][x] -= (v[y][x] / 5)*cnt;

			//한번 퍼지고 그다음 공기청정기 가동
		}
		/*cout << "\n";
		for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
		//cout << v[i][j] << " ";
		printf("%2d ", plus[i][j]);
		}
		cout << "\n";
		}*/
		//공기청정기 작동
		for (int j = upairy - 1; j - 1 >= 0; j--)
			plus[j][0] = plus[j - 1][0];
		for (int j = 0; j + 1<c; j++)
			plus[0][j] = plus[0][j + 1];
		for (int j = 0; j + 1 <= upairy; j++)
			plus[j][c - 1] = plus[j + 1][c - 1];
		for (int j = c - 1; j - 1>0; j--)
			plus[upairy][j] = plus[upairy][j - 1];
		plus[upairy][1] = 0;

		for (int j = downairy + 1; j + 1<r; j++)
			plus[j][0] = plus[j + 1][0];
		for (int j = 0; j + 1<c; j++)
			plus[r - 1][j] = plus[r - 1][j + 1];
		for (int j = r - 1; j - 1 >= downairy; j--)
			plus[j][c - 1] = plus[j - 1][c - 1];
		for (int j = c - 1; j - 1>0; j--)
			plus[downairy][j] = plus[downairy][j - 1];
		plus[downairy][1] = 0;
		//cout << "\n";
		/*for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
		//cout << v[i][j] << " ";
		printf("%2d ", temp[i][j]);
		}
		cout << "\n";
		}*/
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) { //갱신된 것을 v에 저장
				v[j][k] = plus[j][k];
				if (plus[j][k] != 0 && plus[j][k] != -1)
					qs[i + 1].push(make_pair(j, k));
			}
		}

	}
	//cout << "\n";
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//cout << v[i][j] << " ";
			sum += v[i][j];
		}
		//cout << "\n";
	}
	cout << sum + 2 << "\n";
	return 0;
}
