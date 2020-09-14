#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	int max = citations.back();
	for (int i = max; i >= 0; i--) {
		int up = 0;
		int down = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) up++;
			else down++;
		}
		if (up >= i && down <= i) {
			answer = i;
			break;
		}
	}
	return answer;
}