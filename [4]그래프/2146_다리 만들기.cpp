/* 그래프
 * 2146 다리 만들기
 * 색이 있는 부분(1)이 육지이고, 색이 없는 부분(0)이 바다이다
 * 이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다
 * 가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다
 * 지도가 주어질 때, 가장 짧은 다리의 길이 출력
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 100
using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 }; // 상하좌우

bool check(int x, int y)
{
	if (x >= n || x < 0 || y >= n || y < 0)
		return false;
	return true;
}

void dfs(int x, int y, int cnt)
{
	visited[x][y] = true;
	// 몇번 섬인지 표시
	map[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny) && !visited[nx][ny] && map[nx][ny])
			dfs(nx, ny, cnt);
	}
}

int bfs(int cnt)
{
	queue<pair<int, int>> q;

	// 해당 섬의 좌표를 모두 큐에 넣는다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == cnt) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}

	int res = 0;
	while (!q.empty()) {
		// 현재 큐에 있는 칸으로부터 한칸씩 전진해본다
		int curSize = q.size();
		for (int i = 0; i < curSize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (check(nx, ny)) {
					// 다른 섬에 도착할 경우 종료
					if (map[nx][ny] && map[nx][ny] != cnt)
						return res;

					// 아직 방문하지 않은 바다칸이면 방문 표시
					if (!visited[nx][ny] && map[nx][ny] == 0) {
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		res++;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int cnt = 1;
	// dfs를 통해 섬을 표시해준다
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && map[i][j])
				dfs(i, j, cnt++);

	// 각 섬에서 제일 가까운 섬까지 가장 짧은 다리의 길이를 구한다
	int ans = 10000000;
	for (int i = 1; i < cnt; i++) {
		memset(visited, false, sizeof(visited));
		ans = min(ans, bfs(i));
	}
	cout << ans;

	return 0;
}