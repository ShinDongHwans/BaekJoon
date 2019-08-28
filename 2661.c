#include <cstdio>
#include <iostream>
using namespace std;

int n, a[82];

int check(int len) {
	int c;

	for (int i = 2; i <= len / 2; i++) {
		for (int j = 1; j <= len - i; j++) {
			c = 0;
			for (int k = j; k < j + i; k++){
                if (k + i > len) break;
				if (a[k] == a[k + i]) c++;
            }

			if (c == i) return 0;
		}
	}
	return 1;
}

void go(int cnt) {
	if (cnt == n + 1) {
		for (int i = 1; i < n + 1; i++) printf("%d", a[i]);
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		if (i == a[cnt - 1]) continue;
		a[cnt] = i;
		if (check(cnt) == 1) go(cnt + 1);
	}
}

int main() {
	scanf("%d", &n);
	go(1);
	return 0;
}