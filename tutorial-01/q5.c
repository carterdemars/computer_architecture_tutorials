#include <stdio.h>

int f1(int x, int y) {
	return x*x + y*y;
}

void f2(int val) {
here: ;
	  printf("%d\n", val);
}
void f3(int a) {
	int b = f1(a, a+1);
	f2(b);
}
int main(int argc, char *argv[]) {
	int w = 1;
	f3(w);
}
