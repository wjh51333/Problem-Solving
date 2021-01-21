/* Dynamic Programming
 * 9465 스티커
 * 스티커 한 장을 떼면 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없음
 * 상냥이가 뗄 수 있는 스티커의 점수의 최댓값
 * 2n개의 스티커 중 점수의 합이 최대가 되면서 서로 변을 공유하지 않는 스티커 집합
 */

#include <iostream>
#include <algorithm>

using namespace std;

int map[2][100001];
int dp[2][100001];

int calc(int n)
{
	// 시작점은 무조건 [0][0]이나 [1][0] 중 하나
	dp[0][0] = map[0][0];
	dp[1][0] = map[1][0];
	dp[0][1] = map[0][1] + map[1][0];
	dp[1][1] = map[1][1] + map[0][0];

	for (int i = 2; i < n; i++) {
		// 대각선으로 갈 때와 대각선으로 가지만 가운데 한 칸 띄고 대각선으로 가는 경우 중 큰 값 선택
		dp[0][i] = map[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = map[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	return max(dp[0][n - 1], dp[1][n - 1]);	
}

int main()
{
	int T, n;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		cout << calc(n) << endl;
	}
	return 0;
}