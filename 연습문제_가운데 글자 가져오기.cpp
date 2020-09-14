#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int sz = s.size();
	if (sz % 2) answer += s[sz / 2];
	else answer += s.substr(sz / 2 - 1, 2);

	return answer;
}