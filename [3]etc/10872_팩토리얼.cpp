/* etc
 * 10872 팩토리얼
 * 0보다 크거나 같은 정수 N이 주어진다
 * 이때, N!을 출력
 */

#include <iostream>
using namespace std;

long long factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << factorial(n);

	return 0;
}