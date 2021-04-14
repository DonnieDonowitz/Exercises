#include <stdlib.h>
#include <stdio.h>

int findInterf(double a0[3], double a1[3], double b0[3], double b1[3], double *intp, double *u, double *v) {
	double ia[3], ib[3];
	for (int i = 0; i < 3;++i) {
		ia[i] = a0[i] + *u * (a1[i] - a0[i]);
		ib[i] = b0[i] + *v * (b1[i] - b0[i]);
	}
	bool ok = true;
	for (int i = 0; i < 3 && ok; ++i) {
		if (ia[i] == ib[i]) continue;
		else ok = false;
	}
	intp = ia;
	return ok ? 1 : 0;
}
int main() {
	double a0[] = { 1.1,2.1,2.0 };
	double a1[] = { 1.2,2.2,3.0 };
	double b0[] = { 1.7,2.1,3.0 };
	double b1[] = { 1.8,2.2,4.0 };
	double* intp;
	double u = 1.0;
	double v = 1.0;
	int ans = findInterf(a0, a1, b0, b1, intp, &u, &v);
	printf("%d", ans);
	return 0;
}