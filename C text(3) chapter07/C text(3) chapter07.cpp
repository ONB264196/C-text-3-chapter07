#include<stdio.h>

#define _0721



#ifdef _0701
int main(void) {
	struct xy {
		int x;
		double y;
	};

	struct xy s = { 1 };
	struct xy t = s;

	printf("s.x = %d\n", s.x);
	printf("s.y = %lf\n", s.y);
	printf("t.x = %d\n", t.x);
	printf("t.y = %lf\n", t.y);

	return 0;
}
#endif

//実行不可
#ifdef _0702
#define complex struct { double re, im; }

int main(void) {
	complex a{}, b{};
	complex x{}, y{};

	a = b;
	x = b;

	return 0;
}
#endif

#ifdef _0703
struct __comp { double re, im; };
#define complex	 struct __comp

int main(void) {
	complex a{}, b{};
	complex x{}, y{};

	a = b;
	x = b;

	return 0;
}
#endif

//実行不可
#ifdef _0704
struct __comp { double re, im; };
#define complex struct __comp
#define compptr struct __comp *

int main(void) {
	complex a{}, b{};
	compptr pa = nullptr, pb{};

	pa = &a;
	pb = &b;

	return 0;
}
#endif

#ifdef _0705
typedef struct { double re, im; } complex;

int main(void) {
	complex a{}, b = { 0.0 };
	complex x{}, y = { 0.0 };
	complex* pa = nullptr, * pb = nullptr;

	return 0;
}
#endif

#ifdef _0706
typedef struct { double re, im; } complex;
typedef complex* compptr;

int main(void) {
	complex a{}, b = { 0.0 };
	complex x{}, y = { 0.0 };
	compptr pa = nullptr, pb = nullptr;

	a = b;
	x = b;
	pa = &a;
	pb = &b;

	return 0;
}
#endif

#ifdef _07C1
#include <iostream>

using namespace std;

struct Complex {
private:
	double re = 0, im = 0;
public:
	Complex(double r, double i) : re(r), im(i) { }

	double Real(void) { return re; }
	double Image(void) { return im; }
};

int main(void) {
	Complex a(0, 0);
	Complex* pa = &a;

	cout << "  a = (" << a.Real() << ", " << a.Image() << ")\n";
	cout << "*pa = (" << pa->Real() << ", " << pa->Image() << ")\n";

	return 0;
}
#endif

//実行不可
#ifdef _0709a
#include "defSX.h"
#include "defSY.h"

int main(void) {
	SX s{};
	SY t{};

	return 0;
}
#endif

//実行不可
#ifdef _0710
#include"defSY.h"
#include"defSX.h"

int main(void) {
	SX s{};
	SY t{};

	return 0;
}
#endif

#ifdef _0711
typedef struct __sy SY;

typedef struct {
	int a;
	SY* b;
}SX;

typedef struct __sy {
	int c;
	SX d;
}SY;

int main(void) {

	return 0;
}
#endif

#ifdef _0709b
#include "SX.h"
#include "SY.h"

int main(void) {
	SX s{};
	SY t{};

	return 0;
}
#endif

#ifdef _0714
typedef struct {
	char formA[16];
	char nameA[65];
	char formB[16];
	char nameB[65];
} Rec;

int main(void) {
	Rec _01_{};
	int AtoZ = 65;

	printf("成分%c : ", AtoZ);
	scanf_s("%s", _01_.formA, 16);
	printf("物質名%c : ", AtoZ);
	scanf_s("%s", _01_.nameA, 65);
	AtoZ++;
	printf("成分%c : ", AtoZ);
	scanf_s("%s", _01_.formB, 16);
	printf("物質名%c : ", AtoZ);
	scanf_s("%s", _01_.nameB, 65);

	return 0;
}
#endif

#ifdef _0715
typedef char Form[16];
typedef char Name[65];

typedef struct {
	Form form;
	Name name;
} FormName;

typedef struct {
	FormName compA;
	FormName compB;
} Rec;

int main(void) {
	Rec _01_{};
	int AtoZ = 65;

	printf("成分%c : ", AtoZ);
	scanf_s("%s", _01_.compA.form, 16);
	printf("物質名%c : ", AtoZ);
	scanf_s("%s", _01_.compA.name, 65);
	AtoZ++;
	printf("成分%c : ", AtoZ);
	scanf_s("%s", _01_.compB.form, 16);
	printf("物質名%c : ", AtoZ);
	scanf_s("%s", _01_.compB.name, 65);

	return 0;
}
#endif

#ifdef _0716
int main(void) {
	struct test {
		char c1;
		int nx;
		char c2;
	};

	printf("構造体test全体の大きさ = %u\n", (unsigned)sizeof(struct test));
	printf("構造体testのメンバの大きさの合計 = %u\n", (unsigned)(sizeof(char) + sizeof(int) + sizeof(char)));

	return 0;
}
//全体のサイズ = char 1/(4) + int 4/(4) + char 1/(4) = 12
//メンバのサイズの合計 = char(1) + int(4) + char(1) = 6
#endif

#ifdef _0717
#include<stddef.h>

struct test {
	char c1;
	int nx;
	char c2;
};

int main(void) {
	printf("c1のオフセット = %u\n", (unsigned)offsetof(struct test, c1));
	printf("nxのオフセット = %u\n", (unsigned)offsetof(struct test, nx));
	printf("c2のオフセット = %u\n", (unsigned)offsetof(struct test, c2));

	return 0;
}
#endif

#ifdef _07C2
struct test {
	char c1;
	int nx;
	char c2;
};

int test_eq(const struct test* a, const struct test* b) {
	if (a->c1 != b->c1) return 0;
	if (a->nx != b->nx) return 0;
	if (a->c2 != b->c2) return 0;
	return 1;
}

int main(void) {
	test a{}, b{};

	if (!test_eq(&a, &b)) putchar('\a');

	return 0;
}
#endif

#ifdef _0719
int main(void) {
	union uxy {
		int x;
		double y;
	} u{};

	u.x = 1;
	printf("s.x = %d\n", u.x);
	printf("s.y = %lf\n", u.y);

	return 0;
}
#endif

#ifdef _0720
int main(void) {
	union uxy {
		int x;
		double y;
	};

	union uxy s = { 5 };
	union uxy t = s;

	printf("s.x = %d\n", s.x);
	printf("s.y = %lf\n", s.y);
	printf("t.x = %d\n", t.x);
	printf("t.y = %lf\n", t.y);

	return 0;
}
#endif

#ifdef _0721
typedef union {
	struct {
		int type;
	} code;

	struct {
		int type;
		char* name;
	} dog;

	struct {
		int type;
		double weight;
	} cat;
} Animal;

void print_animal(const Animal* x) {
	switch (x->code.type) {
	case 1: printf("犬。名前は%sです。\n", x->dog.name); break;
	case 2: printf("猫。体重は%.1lf㎏です。\n", x->cat.weight); break;
	}
}

int main(void) {
	Animal a{}, b{};

	a.dog.type = 1;
	a.dog.name = (char*)"Taro";

	b.cat.type = 2;
	b.cat.weight = 3.5;

	print_animal(&a);
	print_animal(&b);

	return 0;
}
#endif