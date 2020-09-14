#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<double> rate;

bool compare(int a, int b) {
	if (rate[a] != rate[b])
		return rate[a] > rate[b];
	else return a < b;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<vector<int>> arr;
	for (int i = 0; i <= N + 1; i++) {
		vector<int> v;
		for (int j = 0; j < 2; j++) {
			v.push_back(0);
		}
		arr.push_back(v);
	}

	for (int i = 0; i < stages.size(); i++) {
		arr[stages[i]][0]++;
		for (int j = 1; j <= stages[i]; j++) {
			arr[j][1]++;
		}
	}
	rate.push_back(0);
	for (int i = 1; i <= N; i++) {
		answer.push_back(i);
		if (arr[i][1] == 0) rate.push_back(0);
		else rate.push_back((double)arr[i][0] / (double)arr[i][1]);
	}
	sort(answer.begin(), answer.end(), compare);
	return answer;
}