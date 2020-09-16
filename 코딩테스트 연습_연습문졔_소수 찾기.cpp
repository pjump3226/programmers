#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;
	vector<bool> arr(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			arr[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i]) answer++;
	}
	return answer;
}