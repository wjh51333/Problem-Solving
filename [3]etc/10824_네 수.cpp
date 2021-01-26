/* etc
 * 10824 네 수
 * 네 자연수 A, B, C, D가 주어진다
 * 이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합 출력
 * 두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다
 * 즉, 20과 30을 붙이면 2030이 된다
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num[4];
	long long sum = 0;

	for (int i = 0; i < 4; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i += 2) {
		num[i].append(num[i + 1]);
		sum += stoll(num[i]);
	}
	cout << sum;

	return 0;
}