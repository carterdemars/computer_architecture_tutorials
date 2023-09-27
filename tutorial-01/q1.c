#include <stdio.h>
#include <stdlib.h>

/*
TRANSLATING C++ INTO C

#include <iostream>
using namespace std;
class A {

    private:
        int x,y;
    public:
        A(int x, int y) : x(x), y(y) {}
    int sum() { return x+y; }
};

int main() {
    A *a = new A(1,2);
    cout << a->sum() << endl;
    delete a;
}

*/

typedef struct {
    int x, y;
} A;

int sum(int a, int b) {
    return a+b;
}

int main(void) {
    A* a = malloc(sizeof(A));
    (*a).x = 1;
    (*a).y = 2;
    printf("%d", sum((*a).x, (*a).y));
    free(a);
}