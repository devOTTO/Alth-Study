#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

int a[10][10]; //겨울마다 추가되는 양분
int yang[10][10]; //실제 양분
vector<int> tree[10][10]; //나무들의 나이를 저장하는 벡터
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int, int>>> q(k + 1); //k년에 있는 나무들 개수
											 //vector<pair<int, int>> v;
											 //memset(yang, 5, sizeof(int)); //초기 양분을 5로 초기화

											 //memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			yang[i][j] = 5;
			cin >> a[i][j]; //겨울마다 추가되는 양분
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
		tree[y - 1][x - 1].push_back(z); //인덱스이므로 -1 처리해준다. 나무들의 위치와 나이를 저장
		q[0].push_back(make_pair(y - 1, x - 1)); //0년에서의 나무있는 위치를 벡터에 넣어준다.
	}

	int year = 0;
	while (year < k) { //k년 까지 반복시켜준다.
					   //q[year].erase(unique(q[year].begin(), q[year].end()), q[year].end()); //위치 중복을 없애준다.
		vector<int> temp[10][10]; //해당년도에 생기는 나무를 저장하는 배열
		int temp_yang[10][10]; memset(temp_yang, 0, sizeof(temp_yang));
		int temp_del[10][10]; memset(temp_del, 0, sizeof(temp_del));
		while (!q[year].empty()) {  //해당 연도의 나무들을 전부 체크해준다.

			int y = q[year].back().first; int x = q[year].back().second; q[year].pop_back();
			//봄
			for (int i = 0; i < tree[y][x].size(); i++) { //정렬되어 있으므로 어린 것부터 빼준다.
				if (yang[y][x] - tree[y][x][i] >= 0) { //양분이 현재 나무나이보다 많거나 같으면
					yang[y][x] -= tree[y][x][i]; //빼주고
					tree[y][x][i]++; //나이 +1 해준다.
									 //q[year + 1].push_back(make_pair(y, x));
									 //cout << y<<","<<x<<":"<<tree[y][x][i] << endl;
					if (tree[y][x][i] % 5 == 0) {//가을: 더한것이 5의 배수이면 8칸에 나무가 생긴다.
						for (int j = 0; j < 8; j++) {
							int ny = y + dy[j]; int nx = x + dx[j];
							if (ny < 0 || ny >= n || nx < 0 || nx >= n) //범위 체크
								continue;
							temp[ny][nx].push_back(1);//가을에 번식을 위해 임시 배열에 저장
													  //q[year + 1].push_back(make_pair(ny, nx)); //다음 년에 탐색할 위치로 넣어준다.
						}
					}
				}
				else { //안되면 양분으로 돌아가게 하고 삭제한다. 현재나무가 죽으면 뒤에 나머지 나무도 죽게된다.
					   //봄이 끝나고 실행해야 하므로 양분으로 돌아갈 것을 임시저장해줘야된다.
					temp_yang[y][x] += tree[y][x][i] / 2; //여름
					tree[y][x][i] = -1; //i번째 원소 삭제를 위해 -1로 처리해준다.
				}
			}
		}



		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] == -1) { //여름: -1처리한 원소들을 제거한다.
						tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
						break;
					}
				}
				if (int(temp_yang[i][j] != 0)) { //여름: 임시저장된 양분을 양분벡터에 넣어준다.
					yang[i][j] += temp_yang[i][j];
				}
				if (int(temp[i][j].size()) != 0) {
					//가을: 새로 추가된 나무를 넣어준다. temp에 있는 것을 tree의 첫번째 인덱스에 넣어준다.
					for (int k = 0; k < temp[i][j].size(); k++) {
						tree[i][j].insert(tree[i][j].begin(), 1);
					}
				}
				yang[i][j] += a[i][j];//겨울: 양분을 더해준다.
									  //출력
				if (int(tree[i][j].size()) != 0) {
					q[year + 1].push_back(make_pair(i, j)); //나무들이 있는 위치를 q에 저장해준다.
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
			sum += int(tree[i][j].size()); //존재하는 모든 나무들을 세워준다.
		}
	}
	cout << sum << "\n";

	return 0;
}