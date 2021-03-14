/* 브루트포스
 * 2632 피자판매
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int A[MAX];
int B[MAX];

vector<int> makeSum(int arr[], int size)
{
	vector<int> res;

	res.push_back(0);
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size - 1; j++) {
			sum += arr[(i + j) % size];
			res.push_back(sum);

			// i == 0일 때만 전체 합 추가
			if (i == 0 && j == size - 2)
				res.push_back(sum + arr[size - 1]);
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

	int s, n, m;
	cin >> s >> m >> n;

	for (int i = 0; i < m; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];

	vector<int> a = makeSum(A, m);
	vector<int> b = makeSum(B, n);

	int ans = 0;

	// 이분탐색
	for (int i = 0; i < b.size(); i++) {
		int temp = s - b[i];
		auto hi = upper_bound(a.begin(), a.end(), temp);
		auto lo = lower_bound(a.begin(), a.end(), temp);
		ans += hi - lo;
	}

	cout << ans;
	return 0;
}