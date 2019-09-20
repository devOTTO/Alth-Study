#include <string>
#include <vector>
#include<iostream>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	vector<long long> vec(N);
	vec[0] = 1; vec[1] = 1;
	for (int i = 2; i<vec.size(); i++) {
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	if (N == 1) {
		answer = 4;
	}
	else if (N == 2) {
		answer = 6;
	}
	else if (N == 3) {
		answer = 10;
	}
	else answer = 3 * vec[N - 1] + 2 * vec[N - 2] + 2 * vec[N - 3] + vec[N - 4];

	return answer;
}