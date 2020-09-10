#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, int> m;
	for (int i = 0; i < clothes.size(); i++) {
		if (m.find(clothes[i][1]) == m.end()) {
			m.insert(make_pair(clothes[i][1], 1));
		}
		else {
			m[clothes[i][1]]++;
		}
	}
	for (auto it : m) answer *= (it.second + 1);
	answer--;
	return answer;
}

int main() {
	vector<vector<string>> clothes = 
	{ {"hat","headgear"}, {"sunglasses","eyewear"},
	{"turban", "headgear"} };

	for (int i = 0; i < clothes.size(); i++) {
		cout << clothes[i][1] << '\n';
		
	}

	return 0;
}