/* 그래프
 * 2178 미로 탐색
 * nxm 크기의 배열로 표현되는 미로가 있다
 * 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다
 * 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (n, m)의 위치로 이동할 때 지나야 하는 최소의 칸 수 출력
 * 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다
 * 칸을 셀 때는 시작 위치와 도착 위치도 포함한다
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
bool visited[101][101] = { false, };
int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 };
int ans = 10000;

bool check(int nx, int ny)
{
	if ((nx > 0 && nx <= n) && (ny > 0 && ny <= m))
		return true;
	return false;
}

// 시간초과
void dfs(int x, int y, int res)
{
	visited[x][y] = true;

	if (x == n && y == m) {
		ans = min(ans, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny) && !visited[nx][ny] && map[nx][ny]) {
			dfs(nx, ny, res + 1);
			visited[nx][ny] = false;
		}
	}
}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	// int res = 1;
	// dfs(1, 1, res);

	// bfs
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny) && !visited[nx][ny] && map[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				map[nx][ny] += map[x][y];
			}
		}
	}
	cout << map[n][m];

	return 0;
}