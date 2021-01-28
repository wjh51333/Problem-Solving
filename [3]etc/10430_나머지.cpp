/* etc
 * 10430 나머지
 * (A+B)%C는 ((A%C) + (B%C))%C와 같을까?
 * (AxB)%C는 ((A%C) x (B%C))%C와 같을까?
 * 세 수 A, B, C가 주어졌을 때, 위의 네 가지 값 출력
 */

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << "\n";
	cout << ((a % c) + (b % c)) % c << "\n";
	cout << (a * b) % c << "\n";
	cout << ((a % c) * (b % c)) % c << "\n";

	return 0;
}