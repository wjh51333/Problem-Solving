/* 그래프
 * 7576 토마토
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1000
using namespace std;

int m, n;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 }; // 상하좌우

bool check(int x, int y)
{
	if (x >= n || x < 0 || y >= m || y < 0)
		return false;
	return true;
}

void bfs(vector<pair<int, int>> start)
{
	queue<pair<int, int>> q;

	// 익은 토마토가 없다면 종료
	if (start.empty())
		return;

	for (int i = 0; i < start.size(); i++) {
		// 익은 토마토의 위치를 큐에 미리 넣어둔다
		// bfs의 경우 큐에 원소를 넣기 전에 방문체크를 해야함
		visited[start[i].first][start[i].second] = true;
		q.push(start[i]);
	}

	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny) && !visited[nx][ny] && map[nx][ny] == 0) {
				map[nx][ny] = map[x][y] + 1;
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	vector<pair<int, int>> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			// 1 = 익은 토마토, 0 = 안 익은 토마토, -1 = 토마토가 들어있지 않은 칸
			if (map[i][j] == 1)
				start.push_back({ i, j });
		}
	}

	memset(visited, false, sizeof(visited));
	// 익은 토마토에서부터 탐색 시작
	bfs(start);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 안 익은 토마토가 있다면 -1
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}

			if (ans < map[i][j])
				ans = map[i][j];
		}
	}
	cout << ans - 1;

	return 0;
}