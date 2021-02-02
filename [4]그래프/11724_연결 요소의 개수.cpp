/* 그래프
 * 11724 연결 요소의 개수
 * 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수출력
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(1001, vector<int>());
bool visited[1001] = { false, };

void dfs(int v)
{
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next])
			dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;

	return 0;
}