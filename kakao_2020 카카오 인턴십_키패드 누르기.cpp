#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	unordered_map<int, pair<int, int>> m;
	for (int i = 1; i < 10; i++) {
		m[i] = make_pair((i - 1) / 3, (i - 1) % 3);
	}
	m[0] = make_pair(3, 1);

	pair<int, int> left_s = make_pair(3, 0);
	pair<int, int> right_s = make_pair(3, 2);

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			left_s = m[numbers[i]];
			answer.push_back('L');
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			right_s = m[numbers[i]];
			answer.push_back('R');
		}
		else {
			if (abs(m[numbers[i]].first - left_s.first) + abs(m[numbers[i]].second - left_s.second)
				< abs(m[numbers[i]].first - right_s.first) + abs(m[numbers[i]].second - right_s.second)) {
				left_s = m[numbers[i]];
				answer.push_back('L');
			}
			else if (abs(m[numbers[i]].first - left_s.first) + abs(m[numbers[i]].second - left_s.second)
				> abs(m[numbers[i]].first - right_s.first) + abs(m[numbers[i]].second - right_s.second)) {
				right_s = m[numbers[i]];
				answer.push_back('R');
			}
			else {
				if (hand == "right") {
					right_s = m[numbers[i]];
					answer.push_back('R');
				}
				else {
					left_s = m[numbers[i]];
					answer.push_back('L');
				}
			}
		}
	}
	return answer;
}