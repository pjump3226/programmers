#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) return cities.size() * 5;
	int answer = 0;
	vector<string> v;
	for (int i = 0; i < cities.size(); i++) {
		int sw = 0;
		for (int j = 0; j < cities[i].size(); j++) {
			cities[i].at(j) = tolower(cities[i].at(j));
		}
		for (int j = 0; j < v.size(); j++) {
			if (cities[i] == v[j]) {
				v.erase(v.begin() + j);
				v.push_back(cities[i]);
				answer += 1;
				sw = 1;
				break;
			}
		}
		if (!sw) {
			if (v.size() == cacheSize) v.erase(v.begin());
			v.push_back(cities[i]);
			answer += 5;
		}

	}
	return answer;
}