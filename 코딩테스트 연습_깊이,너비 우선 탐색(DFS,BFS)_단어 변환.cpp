#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int val = 0;
	queue<int> q;
	for (int i = 0; i < words.size(); i++) {
		if (target == words[i]) {
			val = 1;
			break;
		}
	}
	if (!val) return answer;

	string word = begin;
	vector<bool> visited(words.size());
	for (int i = 0; i < words.size(); i++) {
		int dif = 0;
		for (int j = 0; j < begin.size(); j++) {
			if (begin[j] != words[i][j]) {
				dif++;
			}
		}
		if (dif == 1 && !visited[i]) {
			q.push(i);
			visited[i] = 1;
		}
	}

	while (!q.empty()) {
		if (!val) break;
		int q_size = q.size();
		answer++;
		for (int i = 0; i < q_size; i++) {
			word = words[q.front()];
			if (word == target) {
				val = 0;
				break;
			}
			q.pop();
			for (int k = 0; k < words.size(); k++) {
				int dif = 0;
				for (int j = 0; j < word.size(); j++) {
					if (word[j] != words[k][j]) {
						dif++;
					}
				}
				if (dif == 1 && !visited[k]) {
					q.push(k);
					visited[k] = 1;
				}
			}
		}
	}


	return answer;
}