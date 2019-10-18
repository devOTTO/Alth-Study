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
	int y; int x; int s; int d; int z; //속도, 방향, 크기
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
		v[y][x].s = s; v[y][x].d = d; v[y][x].z = z;//상어 저장
		loc[y][x] = 1; //상어있는지를 저장
		svector.insert(make_pair(y, x));
	}
	int time = 0;
	int sum = 0;
	while (time < c) {

		//낚시왕이 가까운 상어를 잡음
		for (int i = 0; i < r; i++) {//가장 가까운 상어를 찾는다.
			if (loc[i][time] != 0) { //해당 위치에 상어가 있으면
				sum += v[i][time].z; //해당 상어 크기를 더해주고
									 //해당 상어의 정보를 삭제한다.
				svector.erase(svector.find(make_pair(i, time)));

				loc[i][time] = 0; //위치도 지워준다.
				break; //가까운 상어찾기 종료
			}
		}
		//cout << "svector size: " << int(svector.size()) << endl;
		//상어이동
		set<pair<int, int>> svector_temp; //이동한 상어들의 위치를 담는 임시벡터
		vector<vector<int>> loc_temp(r, vector<int>(c, 0)); //loc의 임시
		vector<vector<shark>> v_temp(r, vector<shark>(c)); //v의 임시
		set<pair<int, int>>::iterator it;
		for (it = svector.begin(); it != svector.end(); it++) {
			int y = (*it).first;  int x = (*it).second; //남은 상어들의 위치를 불러온다.
			int s = v[y][x].s; int d = v[y][x].d; int z = v[y][x].z; //그 정보를 불러온다.
																	 //위, 아래, 왼, 오 0,1,2,3
																	 //방향에 맞춰 속도만큼 이동
																	 //만약 해당 위치에 상어가 있으면 작은걸 삭제 해야한다.
			int ny = y; int nx = x; int nd = d;
			int speed = s;
			if (d == 0 || d == 1) { //y
				speed = s % (2 * (r - 1));
				while (speed--) {//한번씩 계속 옮겨준다.
					if (ny == 0) { //0이되면 방향을 바꿔준다.
						nd = 1;
					}
					if (ny == r - 1) {
						nd = 0;
					}
					if (nd == 0) {//위로
						ny--;
					}
					else {//아래로
						ny++;
					}
				}
			}
			else if (d == 2 || d == 3) {//x
				speed = s % (2 * (c - 1));
				while (speed--) {
					if (nx == 0) { //0이되면 방향이 2(오른쪽)으로
						nd = 2;
					}
					if (nx == c - 1) {//제일 마지막 컬럼까지가면 방향이 3(왼쪽)으로
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

			//변경해주어야 할 자료구조: 상어벡터, 위치벡터, 위치상어 배열
			if (loc_temp[ny][nx] != 0) {//이미 있으면 크기 비교
				if (v_temp[ny][nx].z < z) {//현재 상어가 이미 있는 상어보다 크면
										   //정보만 업데이트 해준다.

					shark temp_shark; //갱신
					temp_shark.y = ny; temp_shark.x = nx; temp_shark.d = nd;
					temp_shark.s = s; temp_shark.z = z;

					v_temp[ny][nx] = temp_shark; //위치상어 갱신
				}
			}
			else {//처음이면 그냥 새로 넣는다.
				shark temp_shark;
				temp_shark.y = ny; temp_shark.x = nx; temp_shark.d = nd;
				temp_shark.s = s; temp_shark.z = z;

				svector_temp.insert(make_pair(ny, nx)); //상어 벡터에 넣고
				loc_temp[ny][nx] = 1; //인덱스를 위치벡터에 넣고
				v_temp[ny][nx] = temp_shark; //위치상어 배열
			}
		}
		//데이터 갱신
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