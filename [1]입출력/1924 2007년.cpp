#include <iostream>
#include <string>
using namespace std;

int main()
{
	int endOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string dayOfWeek[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int month, day;
	cin >> month >> day;

	int cnt = day;
	for (int i = 0; i < month - 1; i++)
		cnt += endOfMonth[i];

	cout << dayOfWeek[cnt % 7] << endl;
	return 0;
}