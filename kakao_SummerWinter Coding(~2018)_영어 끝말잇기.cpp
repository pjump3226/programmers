#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	unordered_map<string, bool> m;
	int order = 0;
	char last_alphabet;

	for (int i = 0; i < words.size(); i++) {
		if (i == 0) {
			last_alphabet = words[i].at(words[i].length() - 1);
			m[words[i]] = true;
		}
		else if (m.find(words[i]) != m.end() || words[i].at(0) != last_alphabet) {
			order = i;
			break;

		}
		else {
			m[words[i]] = true;
			last_alphabet = words[i].at(words[i].length() - 1);
		}
	}
	if (order == 0) {
		answer.push_back(0); answer.push_back(0);
	}
	else {
		answer.push_back(order%n + 1); answer.push_back(order / n + 1);
	}
	return answer;
}