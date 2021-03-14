/* 브루트포스
 * 2143 두 배열의 합
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int A[MAX];
int B[MAX];

vector<long long> makeSum(int arr[], int size)
{
	vector<long long> res;

	for (int i = 0; i < size; i++) {
		long long sum = 0;
		for (int j = i; j < size; j++) {
			sum += arr[j];
			res.push_back(sum);
		}
	}
	sort(res.begin(), res.end());

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m;
	cin >> T >> n;

	for (int i = 0; i < n; i++) cin >> A[i];

	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];

	vector<long long> a = makeSum(A, n);
	vector<long long> b = makeSum(B, m);

	long long ans = 0;

	// 이분탐색
	for (int i = 0; i < b.size(); i++) {
		int temp = T - b[i];
		auto hi = upper_bound(a.begin(), a.end(), temp);
		auto lo = lower_bound(a.begin(), a.end(), temp);
		ans += hi - lo;
	}

	cout << ans;
	return 0;
}