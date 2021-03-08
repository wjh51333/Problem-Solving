/* 브루트포스
 * 6603 로또
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

void dfs(vector<int> &arr, int idx)
{
	if (res.size() == 6) {
		for (int n : res) {
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	if (idx == arr.size()) return;

	// idx번째 숫자 선택
	res.push_back(arr[idx]);
	dfs(arr, idx + 1);
	// idx번째 숫자 선택 X
	res.pop_back();
	dfs(arr, idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	while (cin >> K) {
		if (K == 0)
			break;

		vector<int> arr(K);
		for (int i = 0; i < K; i++) {
			cin >> arr[i];
		}

		dfs(arr, 0);
		cout << "\n";
	}

	return 0;
}