#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string str = to_string(n);
	sort(str.begin(), str.end(), greater<int>());
	answer = atol(str.c_str());
	return answer;
}