#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
bool flag = true;
int main() {
	double x, y, c;
	scanf("%lf %lf %lf", &x, &y, &c); //double형으로 자료 입력
	double left = 0;
	double right = x;
	while (abs(right - left) > 0.000001) { //10^(-5)이상이라고 하면 틀림 10^(-7)이상이라고 하면 시간초과
		double mid = (left + right) / 2.0;
		double d = mid; //현재 두 빌딩 사이의 거리
		double h1 = sqrt(x*x - d*d);
		double h2 = sqrt(y*y - d*d);
		double h = (h1*h2) / (h1 + h2); // 현재 교점의 y좌표
		if (h > c) {//구한 높이가 c높이보다 크면
			left = mid; //거리를 더 늘려줘야함 = left를 mid로 바꿔줌
			//두 빌딩 사이의 거리가 증가함
		}
		else {//아니면
			right = mid; //거리를 줄임
		}
	}
	printf("%.3lf\n", left);
	
	return 0;
}
