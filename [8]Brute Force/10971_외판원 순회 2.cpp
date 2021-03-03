/* 브루트포스
 * 10971 외판원 순회 2
 * DFS
 */

#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

int n;
int dist[10][10];
bool visited[10];
vector<int> path(1, 0);
int ans = INF;

void dfs(int curDist)
{
	int here = path.back();

	if (path.size() == n) {
		if (dist[here][0] > 0)
			ans = min(ans, curDist + dist[here][0]);
		return;
	}

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;

		if (dist[here][next] > 0) {
			path.push_back(next);
			visited[next] = true;
			dfs(curDist + dist[here][next]);

			visited[next] = false;
			path.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	visited[0] = true;
	dfs(0);
	cout << ans;

	return 0;
}