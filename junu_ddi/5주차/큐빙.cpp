#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<list>
#include<string>
using namespace std;

/* 정육면체 전개도
U
0  1  2
3  4  5
6  7  8
L        _________  R         B
36 37 38|F18 19 20| 45 46 47| 27 28 29
39 40 41| 21 22 23| 48 49 50| 30 31 32
42 43 44| 24 25 26| 51 52 53| 33 34 35
---------
9  10 11
12 13 14
15 16 17
D
*/
int rot[6][12] = {
	{ 36,37,38,18,19,20,45,46,47,27,28,29 },//U
{ 51,52,53,24,25,26,42,43,44,33,34,35 },//D
{ 6,7,8,44,41,38,11,10,9,45,48,51 },//F
{ 2,1,0,53,50,47,15,16,17,36,39,42 },//B
{ 35,32,29,9,12,15,18,21,24,0,3,6 },//L
{ 8,5,2,26,23,20,17,14,11,27,30,33 } //R
};
enum FACE { U, D, F, B, L, R, SIZE };
//enum을 통해 FACE라는 자료형을 만들고 U=0, D=1 이런식으로 정수 값이 할당된다.
char init[7] = "wyrogb"; //초기화를 위한 배열
char arr[55]; //실제 문자 저장
int cube[SIZE][3][3]; //면별로 전체 번호를 저장
char temp[3][3];  //면내의 값변경을 위한 임시 배열

void rotate(FACE f, int cnt) {
	char que[12];
	while (cnt--) {
		//큐에 데이터를 넣는다.
		for (int i = 0; i < 12; i++) {
			que[i] = arr[rot[f][i]];
		}
		//큐를 3칸 밀어서 넣는다.
		for (int i = 0; i < 12; i++) {
			arr[rot[f][i]] = que[(i + 3) % 12];
		}
		//면을 돌린다.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[j][2 - i] = arr[cube[f][i][j]];
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[cube[f][i][j]] = temp[i][j];
			}
		}
	}
}
int conv[256];

int main() {
	//이렇게 아스키코드에 enum FACE에서 정의한 것과 
	//해당하는 값의 배열을 만들어서 값할당.
	conv['-'] = 3;
	conv['+'] = 1;
	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;

	//큐브각 칸에 값부여하기 
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				cube[i][j][k] = i * 9 + j * 3 + k;

	int n, m;
	int t; cin >> t;
	while (t--) {
		//큐브 초기화
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j++) {
				arr[i * 9 + j] = init[i];
			}
		}
		int n; cin >> n;
		while (n--) {
			string a;
			cin >> a;
			int f = conv[a[0]]; int cnt = conv[a[1]];
			rotate((FACE)f, cnt);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << arr[cube[U][i][j]];
			}
			cout << "\n";
		}
	}

	return 0;
}