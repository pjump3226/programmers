#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
bool sel[101];

void dfs(vector<int>numbers, int idx, int cnt) {
	if (cnt == 2) {
		int sum = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (sel[i]) {
				sum += numbers[i];
			}
		}
		answer.push_back(sum);
	}
	else {
		for (int i = idx; i < numbers.size(); i++) {
			if (sel[i]) continue;
			sel[i] = 1;
			dfs(numbers, i, cnt + 1);
			sel[i] = 0;
		}
	}
}

vector<int> solution(vector<int> numbers) {
	dfs(numbers, 0, 0);
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}