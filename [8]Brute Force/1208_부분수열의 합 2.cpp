/* 브루트포스
 * 1208 부분수열의 합 2
 * meet in the middle algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
int A[20];
int B[20];

vector<int> makeSum(int arr[], int size)
{
	vector<int> res;

	for (int i = 0; i < (1 << size); i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			if (i & (1 << j))
				sum += arr[j];
			
		}
		res.push_back(sum);
	}
	sort(res.begin(), res.end());

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n / 2; i++) cin >> A[i];
	for (int i = 0; i < (n - n / 2); i++) cin >> B[i];

	vector<int> a = makeSum(A, n / 2);
	vector<int> b = makeSum(B, (n - n / 2));

	long long answer = 0;
	for (int i = 0; i < b.size(); i++) {
		int temp = s - b[i];
		auto hi = upper_bound(a.begin(), a.end(), temp);
		auto lo = lower_bound(a.begin(), a.end(), temp);
		answer += hi - lo;
	}
	
	if (s == 0)
		answer--;

	cout << answer;
	return 0;
}