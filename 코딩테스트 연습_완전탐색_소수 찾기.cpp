#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool sel[8];
vector<char> v;
vector<int> arr;

void dfs(string numbers, int cnt, int target) {
	if (cnt == target) {
		string s = "";
		int num;
		for (int i = 0; i < v.size(); i++) {
			s += v[i];
		}
		num = stoi(s);
		if (num == 1) return;
		int i;
		for (i = 2; i < sqrt(num); i++) {
			if (num%i == 0) break;
		}
		if (i == (int)sqrt(num) + 1) arr.push_back(num);
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			if (sel[i])continue;
			sel[i] = 1;
			v.push_back(numbers[i]);
			dfs(numbers, cnt + 1, target);
			sel[i] = 0;
			v.pop_back();
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	for (int i = 1; i <= numbers.size(); i++) {
		dfs(numbers, 0, i);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		answer++;
	}
	return answer;
}