#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<list>
#include<string>
using namespace std;

/* ������ü ������
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
//enum�� ���� FACE��� �ڷ����� ����� U=0, D=1 �̷������� ���� ���� �Ҵ�ȴ�.
char init[7] = "wyrogb"; //�ʱ�ȭ�� ���� �迭
char arr[55]; //���� ���� ����
int cube[SIZE][3][3]; //�麰�� ��ü ��ȣ�� ����
char temp[3][3];  //�鳻�� �������� ���� �ӽ� �迭

void rotate(FACE f, int cnt) {
	char que[12];
	while (cnt--) {
		//ť�� �����͸� �ִ´�.
		for (int i = 0; i < 12; i++) {
			que[i] = arr[rot[f][i]];
		}
		//ť�� 3ĭ �о �ִ´�.
		for (int i = 0; i < 12; i++) {
			arr[rot[f][i]] = que[(i + 3) % 12];
		}
		//���� ������.
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
	//�̷��� �ƽ�Ű�ڵ忡 enum FACE���� ������ �Ͱ� 
	//�ش��ϴ� ���� �迭�� ���� ���Ҵ�.
	conv['-'] = 3;
	conv['+'] = 1;
	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;

	//ť�갢 ĭ�� ���ο��ϱ� 
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				cube[i][j][k] = i * 9 + j * 3 + k;

	int n, m;
	int t; cin >> t;
	while (t--) {
		//ť�� �ʱ�ȭ
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