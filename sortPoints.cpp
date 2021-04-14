#include <bits/stdc++.h>
using namespace std;
struct point {
	double x, y, z;
};
static void orderByX(struct point *p, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (p[i].x > p[j].x) swap(p[i], p[j]);
			else if (p[i].x == p[j].x) {
				if (p[i].y > p[j].y) swap(p[i], p[j]);
				else if (p[i].y == p[j].y) {
					if (p[i].z > p[j].z) swap(p[i], p[j]);
				}
			}
		}
	}
}
static void orderByY(struct point *p, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (p[i].y > p[j].y) swap(p[i], p[j]);
			else if (p[i].y == p[j].y) {
				if (p[i].x > p[j].x) swap(p[i], p[j]);
				else if (p[i].x == p[j].x) {
					if (p[i].z > p[j].z) swap(p[i], p[j]);
				}
			}
		}
	}
}
static void orderByZ(struct point *p, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (p[i].z > p[j].z) swap(p[i], p[j]);
			else if (p[i].z == p[j].z) {
				if (p[i].x > p[j].x) swap(p[i], p[j]);
				else if (p[i].x == p[j].x) {
					if (p[i].y > p[j].y) swap(p[i], p[j]);
				}
			}
		}
	}
}
void orderPoints(double *a0, int npoints, int axis, double *sortedres) {
	struct point p[npoints];
	for (int i = 0; i < npoints * 3; i += 3) {
		p[i / 3].x = a0[i];
		p[i / 3].y = a0[i + 1];
		p[i / 3].z = a0[i + 2];
	}
	switch (axis) {
	case 0: orderByX(p, npoints);
		break;
	case 1: orderByY(p, npoints);
		break;
	case 2: orderByZ(p, npoints);
		break;
	default: break;
	}
	int idx = 0;
	for (auto dot : p) {
		sortedres[idx] = dot.x;
		sortedres[idx + 1] = dot.y;
		sortedres[idx + 2] = dot.z;
		idx += 3;
	}
}
int main() {
	double a[] = { 1.1,1.2,1.8,1.2,1.5,1.3,1.0,0.8,0.4,9.0,8.0,6.1 };
	int n = 4;
	double ans[3 * n];

	orderPoints(a, n, 0, ans);
	for (int i = 0; i<12; i += 3) {
		printf("%.2f %.2f %.2f \n", ans[i], ans[i + 1], ans[i + 2]);
	}
	return 0;
}