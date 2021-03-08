/* 브루트포스
 * 1182 부분수열의 합
 */

#include <iostream>
using namespace std;

int n, S;
int answer = 0;
int arr[20];

void dfs(int sum, int idx)
{
	if (idx == n) {
		if (sum == S)
			answer++;
		return;
	}

	// idx번째 원소 선택
	dfs(sum + arr[idx], idx + 1);
	// idx번째 원소 선택 X
	dfs(sum, idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> S;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	
	// 공집합일 경우 원소의 합은 0이 된다
	// 크기가 양수인 부분수열이어야 하므로 공집합은 제외
	if (S == 0) answer--;

	cout << answer;
	return 0;
}