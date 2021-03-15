/* 브루트포스
 * 7453 합이 0인 네 정수
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4001
using namespace std;

int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];

vector<int> makeSum(int arr[], int arr2[], int size)
{
	vector<int> res;

	for (int i = 0; i < size; i++) {
		int sum = arr[i];
		for (int j = 0; j < size; j++) {
			res.push_back(sum + arr2[j]);
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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	// A와 B, C와 D 배열의 모든 합을 구한다
	vector<int> a = makeSum(A, B, n);
	vector<int> b = makeSum(C, D, n);

	long long ans = 0;

	// 이분탐색
	for (int i = 0; i < b.size(); i++) {
		int temp = -b[i];
		auto hi = upper_bound(a.begin(), a.end(), temp);
		auto lo = lower_bound(a.begin(), a.end(), temp);
		ans += hi - lo;
	}

	cout << ans;
	return 0;
}