/* 그래프
 * 2667 단지번호붙이기
 * 정사각형 모양의 지도가 있다
 * 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다
 * 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고,
 * 단지에 번호를 붙이려 한다
 * 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다
 * 대각선상에 집이 있는 경우는 연결된 것이 아니다
 * 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, cnt = 0;
int map[25][25];
bool visited[25][25] = { false, };
int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 };
vector<int> complex;

bool check(int nx, int ny)
{
	if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n))
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
		complex[cnt]++;

		for (int i = 0; i < 4; i++) {
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
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				complex.push_back(0);
				go(i, j);
				cnt++;
			}
		}
	}

	sort(complex.begin(), complex.end());
	cout << cnt << "\n";
	for (int i = 0; i < complex.size(); i++)
		cout << complex[i] << "\n";

	return 0;
}