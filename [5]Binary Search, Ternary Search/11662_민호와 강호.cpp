/* Binary Search, Ternary Seacrh
 * 11662 민호와 강호
 * 민호는 점 A(Ax, Ay)에서 점 B(Bx, By)를 향해 걸어가고 있고,
 * 강호는 점 C(Cx, Cy)에서 점 D(Dx, Dy)를 향해 걸어가고 있다
 * 민호와 강호는 동시에 출발하고, 민호가 점 B에 도착하는 순간 강호도 점 D에 도착한다
 * 또, 두 사람은 일정한 속도로 걸어간다
 * 두 사람의 거리가 가장 가까울 때 거리 출력
 */

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int coord[4][2]; // A, B, C, D

// 이동한 퍼센티지(percent)에서의 x, y좌표 반환
pair<double, double> now(int n, double percent)
{
	// n이 0이면 민호, 2면 강호
	double x = coord[n][0] + (coord[n + 1][0] - coord[n][0]) * (percent / 100);
	double y = coord[n][1] + (coord[n + 1][1] - coord[n][1]) * (percent / 100);
	return make_pair(x, y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;

	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		coord[i][0] = x;
		coord[i][1] = y;
	}

	// [0, 100] 시작점으로부터 어느 정도 왔는지 퍼센티지 범위
	double fp = 0, lp = 100;
	double ans = 2e9; // ans 최대값

	// Ternary Search
	while (lp - fp >= 1e-10) { // 오차 1e-10
		// 1:2 내분점, 2:1 내분점
		double p = (2 * fp + lp) / 3;
		double q = (fp + 2 * lp) / 3;

		// p, q점일 때 민호와 강호의 x, y좌표값
		pair<double, double> p_m = now(0, p), q_m = now(0, q);
		pair<double, double> p_k = now(2, p), q_k = now(2, q);

		// p, q일 때 민호와 강호의 거리
		double p_dist = pow(p_m.first - p_k.first, 2) + pow(p_m.second - p_k.second, 2);
		double q_dist = pow(q_m.first - q_k.first, 2) + pow(q_m.second - q_k.second, 2);

		// 제일 짧은 거리가 정답
		ans = min(ans, min(p_dist, q_dist));
		
		// p점일 때 거리가 더 길면 최소거리는 [p, lp]에 있고 아니면 [fp, q]에 있다
		if (p_dist >= q_dist)
			fp = p;
		else
			lp = q;
	}

	// 소수점 이하의 자릿수만 다룰 수 있게 된다
	// 소수점 이하의 n개의 수를 나타낼 것이다
	cout.setf(ios::fixed);
	// 소수부분을 10자리로 고정
	cout.precision(10);
	cout << sqrt(ans);

	return 0;
}