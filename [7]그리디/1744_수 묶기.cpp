/* 그리디
 * 1744 수 묶기
 * 길이가 N인 수열이 주어졌을때, 그 수열의 합을 구하려고 한다
 * 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다
 * 어떤 수를 묶게 되면, 수여르이 합을 구할 때 묶은 수는 서로 곱한 후에 더한다
 * 수열이 주어졌을 때, 합이 최대가 나오게 수를 묶었을 때의 합 출력
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

	int n, tmp;
	cin >> n;

	int zero = 0;
	int ans = 0;
	vector<int> positive;
	vector<int> negative;

	for (int i = 0; i < n; i++) {
		cin >> tmp;

		if (tmp > 1)
			positive.push_back(tmp);
		else if (tmp < 0)
			negative.push_back(tmp);
		else if (tmp == 0)
			zero++;
		else // 1은 곱하는 것보다 더하는 것이 합이 최대가 된다
			ans++;
	}

	// 양수가 홀수개라면 1(자기 자신) 추가
	if (positive.size() % 2)
		positive.push_back(1);

	// 음수가 홀수개일 때 0이 있으면 0 추가, 아니면 1(자기 자신) 추가
	if (negative.size() % 2)
		negative.push_back(zero > 0 ? 0 : 1);

	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());

	for (int i = 0; i < positive.size(); i += 2)
		ans += positive[i] * positive[i + 1];

	for (int i = 0; i < negative.size(); i += 2)
		ans += negative[i] * negative[i + 1];

	cout << ans;

	return 0;
}