/* etc
 * 11576 Base Conversion
 * A진법을 B진법으로 변환
 * N진법이란, 한 자리에서 숫자를 표현할 때 쓸 수 있는 숫자의 가짓수가 N이라는 뜻
 * 예를 들어 N은 17일 때 한 자릿수에서 사용할 수 있는 수는 0, 1, ..., 16으로 총 17가지
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n;
	cin >> a >> b >> n;

	vector<int> anum(n);
	for (int i = 0; i < n; i++)
		cin >> anum[i];

	int sum = 0, mult = 1;
	for (int i = anum.size() - 1; i >= 0; i--) {
		sum += anum[i] * mult;
		mult *= a;
	}

	vector<int> bnum;
	while (sum) {
		bnum.push_back(sum % b);
		sum /= b;
	}

	for (int i = bnum.size() - 1; i >= 0; i--)
		cout << bnum[i] << " ";

	return 0;
}