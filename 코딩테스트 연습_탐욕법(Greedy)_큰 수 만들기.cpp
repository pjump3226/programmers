#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	string num = "";
	int idx = 0;

	for (int i = k; i < number.size(); i++) {
		int index = 0;
		int max = -1;
		for (int j = idx; j <= i; j++) {
			if (number[j] - '0' > max) {
				max = number[j] - '0';
				index = j + 1;
			}
		}
		answer += to_string(max);
		idx = index;
	}
	return answer;
}