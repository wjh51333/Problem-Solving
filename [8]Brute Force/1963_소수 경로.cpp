/* 브루트포스
 * 1963 소수 경로
 */

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 10000
using namespace std;

bool prime[MAX];

void eratosthenes()
{
	fill_n(prime, MAX, 1);
	prime[0] = prime[1] = false;

	// 에라토스테네스의 체 활용
	// 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다
	// 지울 때 자기자신은 지우지 않고 이미 지워진 수는 건너뛴다
	for (int i = 2; i < 100; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < MAX; j += i)
				prime[j] = false;
		}
	}
}

int change(int org, int idx, int n)
{
	string s = to_string(org);
	s[idx] = '0' + n;
	return stoi(s);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, A, B;
	cin >> T;

	eratosthenes();

	for (int t = 0; t < T; t++) {
		cin >> A >> B;

		queue<int> q;
		q.push(A);

		bool check = false;
		int dist[MAX];
		fill(dist, dist + MAX, -1);
		dist[A] = 0;

		while (!q.empty() && !check) {
			int cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) continue;
					int next = change(cur, i, j);
					
					if (next < 1000 || next >= 10000) continue;
					if (dist[next] != -1) continue;

					if (prime[next]) {
						dist[next] = dist[cur] + 1;
						q.push(next);
					}
				}
			}
		}
		cout << dist[B] << "\n";
	}
	

	return 0;
}