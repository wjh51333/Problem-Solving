/* 브루트포스
 * 1261 알고스팟
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#define MAX 101
#define INF 100000
using namespace std;

int n, m;
int maze[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	deque<pair<int, int>> q;
	q.push_front(make_pair(1, 1));
	visited[1][1] = true;
	dp[n][m] = INF;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

			if (!visited[nx][ny]) {
				visited[nx][ny] = true;

				if (nx == n && ny == m) {
					dp[nx][ny] = min(dp[nx][ny], dp[x][y]);
					continue;
				}

				if (maze[nx][ny]) {
					dp[nx][ny] = dp[x][y] + 1;
					q.push_back(make_pair(nx, ny));
				}
				else {
					dp[nx][ny] = dp[x][y];
					q.push_front(make_pair(nx, ny));
				}
			}
		}
	}

	if (dp[n][m] == INF)
		dp[n][m] = 0;

	cout << dp[n][m];

	return 0;
}