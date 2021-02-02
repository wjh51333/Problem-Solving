/* 그래프
 * 1707 이분 그래프
 * 그래프의 정점의 집합을 둘로 분할하여, 
 * 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때,
 * 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph)라 부른다
 * 그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
bool* visited;
int* bipartite;

bool dfs(int v, int b)
{
	visited[v] = true;
	bipartite[v] = b;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next] && !dfs(next, !b))
			return false;

		if (bipartite[v] == bipartite[next])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m, u, v;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n >> m;

		graph = vector<vector<int>>(n + 1, vector<int>());
		visited = new bool[n + 1];
		bipartite = new int[n + 1];
		memset(visited, false, n + 1);
		memset(bipartite, -1, n + 1);

		for (int i = 1; i <= m; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool ans = true;
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && !dfs(i, true))
				ans = false;
		}

		if (ans)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}