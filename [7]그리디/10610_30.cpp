/* 그리디
 * 10610 30
 * N에 포함된 숫자들을 섞어 만들 수 있는 30의 배수가 되는 가장 큰 수
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

	string n;
	cin >> n;

	vector<int> arr;
	for (char ch : n)
		arr.push_back(ch - '0');
	sort(arr.begin(), arr.end());

	int sum = 0;
	// 모든 자리수를 섞어 30의 배수가 되는지 확인해야하므로 자리수의 합을 구한다
	for (int i = 0; i < arr.size(); i++)
		sum += arr[i];

	// 30의 배수가 되려면 0이 하나 있어야 하고 자리수의 합이 3으로 나누어 떨어져야 한다
	if (arr[0] == 0 && sum % 3 == 0) {
		for (int i = arr.size() - 1; i >= 0; i--)
			cout << arr[i];
	}
	else
		cout << -1;

	return 0;
}