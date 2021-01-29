/* etc
 * 2745 진법 변환
 * B진법 수 N이 주어진다
 * 이 수를 10진법으로 바꿔 출력
 * 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다
 * 이런 경우에는 알파벳 대문자 사용
 * A : 10, B : 11, ..., F : 15, ..., Y : 34, Z : 35
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;
	int b;
	cin >> n >> b;

	int decimal = 0;
	int mult = 1;
	for (int i = n.size() - 1; i >= 0; i--) {
		if (n[i] >= '0' && n[i] <= '9')
			decimal += (n[i] - '0') * mult;

		if (n[i] >= 'A' && n[i] <= 'Z')
			decimal += (n[i] - 'A' + 10) * mult;

		mult *= b;
	}
	cout << decimal;

	return 0;
}