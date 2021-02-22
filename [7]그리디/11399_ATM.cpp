/* 그리디
 * 11399 ATM
 * 줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때,
 * 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(), p.end());

	int ans =  0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j <= i; j++)
			tmp += p[j];
		ans += tmp;
	}
	cout << ans;

	return 0;
}