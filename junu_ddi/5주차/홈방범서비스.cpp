#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stdio.h>
using namespace std;

vector<int> answers;

int main() {
	int t; cin >> t;
	while (t--) {
		int answer = 0;
		int n, m; cin >> n >> m;
		vector<vector<int> > v(n, vector<int>(n));
		vector<pair<int, int>> gip;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a; cin >> a;
				v[i][j] = a;
				if (a == 1) {
					gip.push_back(make_pair(i, j));
					//집정보를 넣어둔다.
				}
			}
		}
		int gipsize = int(gip.size());
		for (int k = 1; k <= 2*n-1; k++) { //k가 n이 될때가지 해본다.
			//i는 시작점과 거리판단.
			int num; int price = k * k + (k - 1)*(k - 1);
			int price_limit = m * gipsize-price;
			if (price_limit < 0) break;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					//해당 시작점과 집과의 거리가 k보다 안에 있으면
					//방범구역
					price = (k * k) + ((k - 1)*(k - 1));
					num = 0;
					for (int l = 0; l < gip.size(); l++) {
						int dist_y = (gip[l].first - i);
						if (dist_y < 0) dist_y = -1 * dist_y;
						int dist_x = (gip[l].second - j);
						if (dist_x < 0) dist_x = -1 * dist_x;
						int dist = dist_y + dist_x;
						if (dist < k ) { //범위 안에 있으면
							num++;
						}
					}
					//전 집을 다 조사해서 비용이 0or양수이고 
					//집개수가 최대이면
					int result = m * num-price;
					if (result >= 0&&num>answer) {
						//cout << "k: " << k << " (i,j): " <<i << " " << j << endl;
						//cout << "m*num: " << m * num <<" price: " << price << endl;
				
						answer = num;
					}
				}
			}
		}
		//cout << answer << endl;
		answers.push_back(answer);
	}
	for (int i = 0; i < answers.size(); i++) {
		cout <<"#"<<i+1<<" "<< answers[i] << "\n";
	}

	return 0;
}
