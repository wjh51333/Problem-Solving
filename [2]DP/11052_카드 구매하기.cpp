/* Dynamic Programming
 * 11052 카드 구매하기
 * 카드는 카드팩의 형태로만 구매할 수 있고
 * 카드팩의 종류는 카드 1개가 포함된 카드팩, ... 카드 N개가 포함된 카드팩과 같이 총 N가지
 * 돈을 최대한 많이 지불해서 카드 N개 구매
 * 카드 i개가 포함된 카드팩의 가격은 Pi원
 * 카드 팩의 가격이 주어졌을 때 N개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최댓값
 * 구매한 카드팩에 포함되어 있는 카드 개수의 합은 N과 같아야 함
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, p[10001];
	int dp[1001];
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	dp[1] = p[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = p[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i - j] + p[j], dp[i]);
		}
	}
	cout << dp[n];

	return 0;
}