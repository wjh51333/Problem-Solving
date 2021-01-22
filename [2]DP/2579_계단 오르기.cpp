/* Dynamic Programming
 * 2579 계단 오르기
 * 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임
 * 계단을 밟으면 각각의 계단에 쓰여있는 일정한 점수를 얻게 됨
 * 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다
 *    즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다
 * 2. 연속된 세 개의 계단을 모두 밟아서는 안된다
 *    단, 시작점은 계단에 포함되지 않는다
 * 3. 마지막 도착 계단은 반드시 밟아야 한다
 * 이 게임에서 얻을 수 있는 총 점수의 최댓값 출력
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int step[301];
	int dp[301];

	for (int i = 1; i <= n; i++)
		cin >> step[i];

	dp[0] = 0;
	dp[1] = step[1];
	dp[2] = step[1] + step[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + step[i - 1] + step[i], dp[i-2] + step[i]);
	}
	cout << dp[n];

	return 0;
}