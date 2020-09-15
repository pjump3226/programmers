#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++) {
		int j = 0;
		for (j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j]) {
				j++;
				break;
			}
		}
		answer.push_back(j - i - 1);
	}
	return answer;
}