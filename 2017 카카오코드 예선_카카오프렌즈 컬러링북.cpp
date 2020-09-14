#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int num = 0;

	vector<int> answer(2);
	queue<pair<int, int>> q;
	int visited[101][101] = { 0, };
	int r, c;
	int size = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && picture[i][j]) {
				number_of_area++;
				visited[i][j] = 1;
				num = picture[i][j];
				q.push(pair<int, int>(i, j));
				size++;
				int q_size = q.size();
				while (!q.empty()) {
					r = q.front().first;
					c = q.front().second;
					q.pop();
					for (int k = 0; k < q_size; k++) {
						if (r - 1 >= 0) {
							if (picture[r - 1][c] == num && !visited[r - 1][c]) {
								visited[r - 1][c] = 1;
								q.push(pair<int, int>(r - 1, c));
								size++;
							}
						}
						if (r + 1 < m) {
							if (picture[r + 1][c] == num && !visited[r + 1][c]) {
								visited[r + 1][c] = 1;
								q.push(pair<int, int>(r + 1, c));
								size++;
							}
						}
						if (c - 1 >= 0) {
							if (picture[r][c - 1] == num && !visited[r][c - 1]) {
								visited[r][c - 1] = 1;
								q.push(pair<int, int>(r, c-1));
								size++;
							}
						}
						if (c + 1 < n) {
							if (picture[r][c + 1] == num && !visited[r][c + 1]) {
								visited[r][c + 1] = 1;
								q.push(pair<int, int>(r, c+1));
								size++;
							}
						}
					}
				}
				if (max_size_of_one_area < size) max_size_of_one_area = size;
				size = 0;
			}
			else continue;
		}

		answer[0] = number_of_area;
		answer[1] = max_size_of_one_area;
	}
	return answer;
}0