/* etc
 * 11005 진법 변환 2
 * 10진법 수 N이 주어진다
 * 이 수를 B진법으로 바꿔 출력
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

	int n, b;
	cin >> n >> b;

	char k[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
		'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	string b_num;

	while (n) {
		b_num.insert(b_num.begin(), k[n % b]);
		n /= b;
	}
	cout << b_num;

	return 0;
}