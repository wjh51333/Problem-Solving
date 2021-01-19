#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		scanf("%d,%d", &a, &b);
		cout << a + b << endl;
	}

	return 0;
}