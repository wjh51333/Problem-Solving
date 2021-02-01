/* 그래프
 * 4963 섬의 개수
 * 정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다
 * 섬의 개수 출력
 * 한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다
 * 두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다
 * 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다
 * 1은 땅, 0은 바다
 */

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int w, h;
int map[50][50];
bool visited[50][50] = { false, };
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 상하좌우 + 대각선
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

bool check(int nx, int ny)
{
	if ((nx >= 0 && nx < h) && (ny >= 0 && ny < w))
		return true;
	return false;
}

// bfs
void go(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check(nx, ny))
				continue;

			if (!visited[nx][ny] && map[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			break;

		int ans = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) {
					go(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}