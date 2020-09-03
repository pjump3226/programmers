#include <string>
#include <vector>
#include <iostream>
int gym_clothes[32];

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	for (int i = 0; i < lost.size(); i++) {
		gym_clothes[lost[i]]--;
	}

	for (int i = 0; i < reserve.size(); i++) {
		gym_clothes[reserve[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (gym_clothes[i] >= 0) {
			answer++;
		}
		else {
			if (gym_clothes[i - 1] == 1) {
				gym_clothes[i - 1]--;
				answer++;
			}
			else if (gym_clothes[i + 1] == 1) {
				gym_clothes[i + 1]--;
				answer++;
			}
		}
	}
	return answer;
}