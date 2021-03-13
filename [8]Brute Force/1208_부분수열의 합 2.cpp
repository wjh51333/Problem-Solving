/* 브루트포스
 * 1208 부분수열의 합 2
 * meet in the middle algorithm
 */

#include <iostream>
#include <map>
using namespace std;

int n, s, half;
int arr[40];
map<int, int> mp;
int answer = 0;

void dfsLeft(int idx, int sum)
{
	if (idx == half) {
		mp[sum]++;
		return;
	}

	dfsLeft(idx + 1, sum);
	dfsLeft(idx + 1, sum + arr[idx]);
}

void dfsRight(int idx, int sum)
{
	if (idx == n) {
		answer += mp[s - sum];
		return;
	}

	dfsRight(idx + 1, sum);
	dfsRight(idx + 1, sum + arr[idx]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	half = n / 2;
	dfsLeft(0, 0);
	dfsRight(half, 0);
	
	if (s == 0)
		answer--;

	cout << answer;
	return 0;
}