#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a%b) : b;
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	answer = { gcd(n,m), n*m / gcd(n,m) };
	return answer;
}