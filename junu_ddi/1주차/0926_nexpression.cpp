#include <string>
#include <vector>
#include<list>
#include<iostream>
#include<cmath>
using namespace std;

int solution(int N, int number) {
	int answer = 0;
	vector<list<int>> dp(9, list<int>());
	dp[1].push_back(N);
	//cout << "1 " << N << endl;
	for (int i = 2; i <= 9; i++) {
		if (i == 9) return -1;
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += (N * pow(10, j));
		}
		dp[i].push_back(sum);
		//cout <<i<<" "<< sum << endl;
		for (int j = 1; j < i; j++) {
			//cout << "i: " << i << ", j: " << j << endl;
			for (int it : dp[j]) {
				for (int it2 : dp[i - j]) {
					int mul = it * it2; int sub = it - it2; int add = it + it2;
					if (it2 != 0) {
						int div = it / it2;
						if (div == number) return i;
						dp[i].push_back(div);
					}
					if (mul == number || sub == number || add == number)
						return i;
					dp[i].push_back(mul);
					dp[i].push_back(sub);
					dp[i].push_back(add);
				}
			}
		}
	}

	return answer;
}

int main() {
	int n = 2; int number = 11;
	cout << solution(2, 11) << "\n";

	return 0;
}
