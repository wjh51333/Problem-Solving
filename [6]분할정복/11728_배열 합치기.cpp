/* 분할정복
 * 11728 배열 합치기
 * Merge Sort
 * 시간 복잡도 O(nlogn)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	vector<int> a, b, result;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> k;
		a.push_back(k);
	}

	for (int i = 0; i < m; i++) {
		cin >> k;
		b.push_back(k);
	}

	// Merge Sort
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			result.push_back(a[i]);
			i++;
		}
		else {
			result.push_back(b[j]);
			j++;
		}
	}

	if (i >= n) {
		for (int l = j; l < m; l++)
			result.push_back(b[l]);
	}
	else {
		for (int l = i; l < n; l++)
			result.push_back(a[l]);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}