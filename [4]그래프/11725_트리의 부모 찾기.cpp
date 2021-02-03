/* 그래프
 * 11725 트리의 부모 찾기
 */

#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int n;
vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX];

void dfs(int v)
{
	visited[v] = true;

	for (int i = 0; i < tree[v].size(); i++) {
		int next = tree[v][i];

		if (!visited[next]) {
			parent[next] = v;
			dfs(next);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v;
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

	return 0;
}