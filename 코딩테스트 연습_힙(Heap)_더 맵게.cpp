#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	if (pq.top() >= K) {
		return cnt;
	}

	while (pq.size() > 1) {
		if (pq.size() >= 2) {
			int num = pq.top();
			pq.pop();
			num += (pq.top() * 2);
			pq.pop();
			pq.push(num);
		}
		cnt++;
		if (pq.top() >= K) {
			return cnt;
		}
	}
	return -1;
}