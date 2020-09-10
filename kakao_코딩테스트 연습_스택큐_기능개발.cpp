#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	int num;
	int pub = 0;

	for (int i = 0; i < progresses.size(); i++) {
		q.push((99 - progresses[i]) / speeds[i] + 1);
	}
	while (!q.empty()) {
		num = q.front();
		q.pop();
		pub = 1;
		while (q.front() <= num) {
			q.pop();
			pub++;
			if (q.empty()) break;
		}
		answer.push_back(pub);
		num = q.front();
	}
	return answer;
}