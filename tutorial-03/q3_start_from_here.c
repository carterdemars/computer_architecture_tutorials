#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

double rect_real_part(struct complex_struct z) {
	return z.a;
}

double rect_img_part(struct complex_struct z) {
	return z.b;
}

double rect_magnitude(struct complex_struct z) {
	return sqrt(z.a * z.a + z.b * z.b);
}

double rect_angle(struct complex_struct z) {
	double PI = acos(-1.0);

	if (z.a > 0)
		return atan(z.b / z.a);
	else
		return atan(z.b / z.a) + PI;
}

double pol_real_part(struct complex_struct z) {
	return z.a * cos(z.b);
}

double pol_img_part(struct complex_struct z) {
	return z.a * sin(z.b);
}

double pol_magnitude(struct complex_struct z) {
	return z.a;
}

double pol_angle(struct complex_struct z) {
	return z.b;
}

double (*real_part_tbl[])(struct complex_struct) = { rect_real_part, pol_real_part };
double (*img_part_tbl[])(struct complex_struct) = { rect_img_part, pol_img_part };
double (*magnitude_tbl[])(struct complex_struct) = { rect_magnitude, pol_magnitude };
double (*angle_tbl[])(struct complex_struct) = { rect_angle, pol_angle };

#define real_part(z) (real_part_tbl[z.t](z))
#define img_part(z) (img_part_tbl[z.t](z))
#define magnitude(z) (magnitude_tbl[z.t](z))
#define angle(z) (angle_tbl[z.t](z))

// Add two complex numbers, and return the result in rectangular form
struct complex_struct complex_add_to_rect (
	struct complex_struct z, 
	struct complex_struct w);
// Add two complex numbers, and return the result in polar form
struct complex_struct complex_add_to_pol (
	struct complex_struct z, 
	struct complex_struct w);

struct complex_struct complex_add_to_rect (
		struct complex_struct z, 
		struct complex_struct w) {
	// You implementation here 
}

struct complex_struct complex_add_to_pol (
		struct complex_struct z, 
		struct complex_struct w) {
	// You implementation here 
}

struct complex_struct (*complex_add_tbl[])(struct complex_struct, struct complex_struct) = 
	{ complex_add_to_rect, complex_add_to_pol };    // Complete this definition.

// I give you the following macro definition to you. 
#define complex_add(z, w) ((*complex_add_tbl[z.t])(z, w))

int main (void) {
	struct complex_struct a = { RECTANGULAR, 1, 1 };
	struct complex_struct b = { RECTANGULAR, 1, 0 };

	struct complex_struct res1 = complex_add_to_rect(a, b);
	struct complex_struct res2 = complex_add_to_pol(a, b);
	struct complex_struct res3 = complex_add(a, b);
	assert(res1.a == res3.a);
	assert(res1.b == res3.b);
	printf("%d, %0.4f, %0.4f\n", res1.t, res1.a, res1.b);
	printf("%d, %0.4f, %0.4f\n", res2.t, res2.a, res2.b);

	return 0;
}

