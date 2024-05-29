#include<iostream>
#include<math.h>
using namespace std;
class CPoint {
public:
	int x, y;
	CPoint(int x,int y):x(x),y(y){}
	CPoint(){}
};
class CLine :public CPoint {
public:
	int x1, y1, x2, y2;
	CLine(int x1,int y1,int x2,int y2):x1(x1),y1(y1), x2(x2), y2(y2) {}
	double length() {
		return sqrt((x1  - x2 )* (x1 - x2) + (y1  - y2)* (y1 - y2));
	}
	double k() {
		return (y2 - y1) * 1.0 / (x2 - x1);
	}
};
class CCirecle :public CPoint {
public:
	int r;
	CCirecle(int x1, int y1, int r) :CPoint(x1,y1),r(r) {}
	double sqare() {
		return 3.1415926 * r * r;
	}
};
int main() {
	CLine l1 = CLine(1, 4, 6, 7);
	printf("%.2f\n", l1.k());
	printf("%.2f\n", l1.length());
	
	CCirecle c1 = CCirecle(1, 4, 6);
	printf("%.2f\n", c1.sqare());
}