#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream file("data_prog_contest_problem_1.txt");
	if (!file.is_open()) {
		return 1;
	}

	int n;
	file >> n;

	vector<pair<int, int>> nums;
	for (int i = 0; i < n; i++) {
		int a;
		int b;

		file >> a >> b;

		if (a > b) swap(a, b);
		nums.push_back({ b, a });
	}

	sort(nums.begin(), nums.end());

	int points = 0;
	int last_point = INT_MIN;

	for (auto& n : nums) {
		int left = n.second;
		int right = n.first;

		if (last_point < left) {
			last_point = right;
			points++;
		}
	}

	cout << points;
	return 0;
}