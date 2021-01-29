/* etc
 * 9613 GCD 합
 * 양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합 출력
 */

#include <iostream>
#include <vector>

using namespace std;

int gcd(int n, int m)
{
	if (m == 0)
		return n;

	return gcd(m, n % m);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		vector<int> arr(n);
		for (int j = 0; j < n; j++)
			cin >> arr[j];

		long long sum = 0;
		for (int j = 0; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				sum += gcd(arr[j], arr[k]);
		cout << sum << "\n";
	}

	return 0;
}