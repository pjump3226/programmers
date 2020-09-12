#include <string>
#include <vector>
#include <queue>

using namespace std;
int cnt = 0;
queue<int> q;

void bfs(int n, vector<vector<int>> computers, vector<int> visited) {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cnt++;
			visited[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				for (int i = 0; i < n; i++) {
					if (!visited[i] && computers[node][i]) {
						q.push(i);
						visited[i] = 1;
					}
				}
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	vector<int> visited(n);
	bfs(n, computers, visited);
	return cnt;
}