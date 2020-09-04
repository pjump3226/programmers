#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		int prior = 0;
		int sw = 0;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			if (skill_trees[i][j] == skill.at(prior)) {
				if (prior < skill.length() - 1) prior++;
			}
			else {
				for (int k = prior; k < skill.length(); k++) {
					if (skill_trees[i][j] == skill[k]) {
						sw = 1;
						break;
					}
				}
				if (sw == 1) break;
			}
		}
		if (sw == 1) continue;
		answer++;
	}
	return answer;
}