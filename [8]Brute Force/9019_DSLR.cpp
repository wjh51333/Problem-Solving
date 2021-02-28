/* 브루트포스
 * 9019 DSLR
 */

#include <iostream>
#include <queue>
#include <string>
#define MAX 10000
using namespace std;

int calc(int n, char flag)
{
	int res = 0;
	
	switch (flag) {
	case 'D': // 2 * n
		res = (2 * n) % 10000;
		break;
	case 'S': // n - 1
		res = (n == 0) ? 9999 : n - 1;
		break;
	case 'L': // d2 d3 d4 d1
		res = (n / 1000) + (n % 1000) * 10;
		break;
	case 'R': // d4 d1 d2 d3
		res = (n % 10) * 1000 + (n / 10);
		break;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a, b;
	char ch[] = { 'D', 'S', 'L', 'R' };
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> a >> b;

		queue<int> q;
		string cmd[MAX];
		bool visited[MAX] = { false, };
		bool check = false;
		q.push(a);
		visited[a] = true;

		while (!q.empty() && !check) {
			int cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int next = calc(cur, ch[i]);

				if (visited[next]) continue;

				q.push(next);
				cmd[next] = cmd[cur] + ch[i];
				visited[next] = true;

				if (next == b) {
					cout << cmd[next] << "\n";
					check = true;
					break;
				}
			}
		}
	}

	return 0;
}