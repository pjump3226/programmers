#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> values = priorities;
	queue<int> q;
	sort(values.begin(), values.end(), greater<int>());

	for (int i = 0; i < priorities.size(); i++) {
		q.push(i);
	}
	int idx = 0;
	while (!q.empty()) {
		int order = q.front();
		q.pop();
		if (priorities[order] == values[idx]) {
			idx++;
			if (order == location) break;
		}
		else {
			q.push(order);
		}
	}
	answer = idx;
	return answer;
}