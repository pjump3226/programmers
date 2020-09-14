#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int score[3];
	for (int i = 0; i < 3; i++) {
		score[i] = 0;
	}
	int max = 0;
	vector<int> arr1, arr2, arr3;
	for (int i = 0; i <= 10000; i++) {
		arr1.push_back(i % 5 + 1);
	}
	for (int i = 0; i < 1250; i++) {
		arr2.push_back(2);
		arr2.push_back(1);
		arr2.push_back(2);
		arr2.push_back(3);
		arr2.push_back(2);
		arr2.push_back(4);
		arr2.push_back(2);
		arr2.push_back(5);
	}
	for (int i = 0; i < 1000; i++) {
		arr3.push_back(3);
		arr3.push_back(3);
		arr3.push_back(1);
		arr3.push_back(1);
		arr3.push_back(2);
		arr3.push_back(2);
		arr3.push_back(4);
		arr3.push_back(4);
		arr3.push_back(5);
		arr3.push_back(5);
	}

	for (int i = 0; i < answers.size(); i++) {
		if (arr1[i] == answers[i]) score[0]++;
		if (arr2[i] == answers[i]) score[1]++;
		if (arr3[i] == answers[i]) score[2]++;
	}
	if (score[0] >= score[1]) {
		max = score[0];
		if (score[0] < score[2]) {
			max = score[2];
		}
	}
	else {
		max = score[1];
		if (score[1] < score[2]) {
			max = score[2];
		}
	}
	cout << "max : " << max << '\n';
	for (int i = 0; i < 3; i++) {
		if (score[i] == max) {
			cout << i+1 << '\n';
			answer.push_back(i + 1);
		}
	}

	return answer;
}