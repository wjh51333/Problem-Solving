/* 분할정복
 * 2261 가장 가까운 두 점
 * 분할정복이 아니라 Sweep line 알고리즘
 * set은 삽입, 삭제, 탐색이 모두 O(logN) 걸린다
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	int x, y;
	Point() { }
	Point(int x, int y) : x(x), y(y) { }
	bool operator < (const Point& v) const {
		if (y == v.y)
			return x < v.x;
		else
			return y < v.y;
	}
};

bool cmp(const Point &a, const Point &b)
{
	return a.x < b.x;
}

int dist(Point a, Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, y;
	vector<Point> p;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p.push_back(Point(x, y));
	}
	
	// x좌표가 증가하는 순으로 정렬
	sort(p.begin(), p.end(), cmp);

	// candidate에는 현재 점과 x좌표의 차이가 ans 이하인 점들만 들어있다
	set<Point> candidate = { p[0], p[1] };
	
	// 1번 점부터 (m - 1)번점이 있을 때, 가장 가까운 점의 거리
	int ans = dist(p[0], p[1]);
	int start = 0;
	for (int i = 2; i < n; i++) {
		Point now = p[i];
		while (start < i) {
			auto a = p[start];
			x = now.x - a.x;

			// ans에는 거리의 제곱이 저장되어 있어서 x*x와 비교
			if (x * x > ans) {
				candidate.erase(a);
				start += 1;
			}
			else
				break;
		}

		// candidate 배열을 y좌표 기준으로 정렬
		// 이분 탐색을 이용해 m번점과의 거리 차이가 d인 점을 구간을 찾고
		// 그 구간에 들어있는 점만 검사
		int d = (int)sqrt((double)ans) + 1;

		// x좌표에 -100000을 넣는 이유는 같은 y좌표를 가지는 점이 여러 개일 때, 가능한 x좌표의 값 중 가장 작은 값(-10000)보다 작기 때문
		// upper_point도 마찬가지
		auto lower_point = Point(-100000, now.y - d);
		auto upper_point = Point(100000, now.y + d);
		
		// candidate 배열에서 y좌표가 m의 y좌표 - d보다 큰 점 중에서 가장 인덱스가 작은 점
		auto lower = candidate.lower_bound(lower_point);
		
		// candidate 배열에서 y좌표가 m의 y좌표 + d보다 작은 점 중에서 가장 인덱스가 큰 점
		auto upper = candidate.upper_bound(upper_point);

		for (auto it = lower; it != upper; it++) {
			int d = dist(now, *it);
			if (d < ans) {
				ans = d;
			}
		}
		candidate.insert(now);
	}
	cout << ans;
	return 0;
}