#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string s;

	for (int j = 0; j < n; j++) {
		s = "";
		for (int i = 0; i < n; i++) s += " ";

		int num1 = arr1[j];
		int num2 = arr2[j];
		for (int i = n - 1; i >= 0; i--) {
			if (num1 % 2 || num2 % 2) {
				s.at(i) = '#';
			}
			num1 /= 2; num2 /= 2;
		}
		answer.push_back(s);
	}
	return answer;
}