#include <string>
#include <vector>

using namespace std;
int count = 0;

void dfs(vector<int> numbers, int target, int n, int sum) {
	if (n == numbers.size()) {
		if (sum == target) count++;
		return;
	}
	dfs(numbers, target, n + 1, sum + numbers[n]);
	dfs(numbers, target, n + 1, sum - numbers[n]);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, target, 0, 0);
	answer = count;
	return answer;
}