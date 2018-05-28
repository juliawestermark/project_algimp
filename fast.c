#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#define DEBUG   (0)

#if DEBUG
#define pr(...)         fprintf(stderr, __VA_ARGS__)
#else
#define pr(...)
#endif

typedef struct rational
{
	long long p;
	long long q;
} rat;

rat reduce(rat x)
{
	long long a = x.p;
	long long b = x.q;

	if (a == 0 || b == 0)
	{
		x.p = 0;
		x.q = 1;
		return x;
	}

	if (a < 0)
	{
		a = -a;
	}

	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	x.p /= a;
	x.q /= a;

	return x;
}

// rat addq(rat x, rat y)
// {
// 	rat z;

// 	z.p = x.p * y.q + y.p * x.q;
// 	z.q = x.q * y.q;

// 	z = reduce(z);

// 	return z;
// }

rat subq(rat x, rat y)
{
	rat z;

	z.p = x.p * y.q - y.p * x.q;
	z.q = x.q * y.q;

	z = reduce(z);

	return z;
}

// rat mulq(rat x, rat y)
// {
// 	rat z;

// 	z.p = x.p * y.p;
// 	z.q = x.q * y.q;

// 	z = reduce(z);

// 	return z;
// }

rat divq(rat x, rat y)
{
	rat z;

	z.p = x.p * y.q;
	z.q = x.q * y.p;

	if (z.q < 0)
	{
		z.p = -z.p;
		z.q = -z.q;
	}

	z = reduce(z);

	return z;
}

void swap(rat *a, rat *b) {
    rat temp = *a;
    *a = *b;
    *b = temp;
}

void swapRows(size_t ineq, size_t var, rat t[ineq][var], rat q[ineq], size_t rowOne, size_t rowTwo) {
	for (size_t j = 0; j < var; j++) {
		swap(&t[rowOne][j], &t[rowTwo][j]);
	}
	swap(&q[rowOne], &q[rowTwo]);
}

bool eliminate(size_t ineq, size_t var, rat t[ineq][var], rat q[ineq]) {

	pr("Start\n");

	size_t n1 = 0;
	size_t n2 = ineq;

	size_t i = 0;

	/** STEP 2 */
	while (i < n2 && i < ineq) {
		pr("Loop 1\n");
		if (t[i][var-1].p > 0) {
			swapRows(ineq, var, t, q, i, n1);
			n1++;
		} else if (t[i][var-1].p < 0) {
			/** Gör inget */
		} else {
			swapRows(ineq, var, t, q, i, n2-1);
			n2--;
            if (i < ineq - 1) {
				i--;
			}
		}
		i++;
	}

	#if DEBUG
	pr("n1=%zu, n2=%zu, ineq=%zu\n", n1, n2, ineq);
	for (i = 0; i < ineq; i++) {
        for (size_t j = 0; j < var; j++) {
            pr("%lld/%lld \t", t[i][j].p, t[i][j].q);
        }
        pr("<= \t %lld/%lld", q[i].p, q[i].q);
        pr("\n");
    }
    pr("\n");
	#endif

	/** STEP 3 */

	size_t ineqPrim = ineq - n2 + n1* (n2-n1);
	size_t varPrim = var -1;

	for(size_t i = 0; i < n2; i++) {
		pr("Loop 2\n");
		q[i] = divq(q[i],t[i][var-1]);
		pr("Är det här? i= %zu \n", i);
		for(size_t j = 0; j < var; j++) {
			pr("Eller här? j= %zu \n", j);
			t[i][j] = divq(t[i][j],t[i][var-1]);
			pr("Eller kanske här? var = %zu\n", var);
		}
	}

	pr("Loop2 är klar\n");

	#if DEBUG
	pr("Efter steg tre\n");
	for (i = 0; i < ineq; i++) {
        for (size_t j = 0; j < var; j++) {
            pr("%lld/%lld \t", t[i][j].p, t[i][j].q);
        }
        pr("<= \t %lld/%lld", q[i].p, q[i].q);
        pr("\n");
    }
    pr("\n");
	#endif

	/** STEP 4 */
	/** & STEP 5 */
	/** & STEP 6 */
	if (var > 1) {
		/** Do nothing */
	} else {
		pr("Else rad 477\n");
		rat B;
		rat b;
		B.q=1;
		b.q=1;
		// B.p = ;
		// b.p = INT_MIN;
		B.p = 2147483647/2;
		b.p = -2147483648/2;

		#if DEBUG
			pr("Efter steg någonting\n");
			for (i = 0; i < ineq; i++) {
				for (size_t j = 0; j < var; j++) {
					pr("%lld/%lld \t", t[i][j].p, t[i][j].q);
				}
				pr("<= \t %lld/%lld", q[i].p, q[i].q);
				pr("\n");
			}
			pr("\n");
		#endif

		pr("var, n1, n2, ineq = %zu, %zu, %zu, %zu", var, n1, n2, ineq);

		for (size_t i = 0; i < n1; i++) {
			pr("Loop 501a\n i=%zu\n", i);
			if (subq(q[i],B).p < 0){
				B = q[i];
				pr("Loop 501b\n B=%lld \n", B.p);
			}
		}

		pr("Mellan for typ rad 523\n \n");
		
		for(size_t i = n1; i < n2; i++) {
			pr("Loop 509a\n i=%zu\n", i);
			pr("Loop 509a\n b=%lld\n", b.p);
			if (subq(q[i],b).p > 0){
				b = q[i];
				pr("Loop 509b\n b=%lld \n", b.p);
			}
		}

		for(size_t i = n2; i < ineq; i++) {
			pr("Loop 515\n");
			if(q[i].p < 0)
				pr("Hejdå 1\n");
				return 0;
		}

		if (subq(B,b).p < 0) {
			pr("Hejdå 2\n");
			return 0;
		}

		pr("Hejdå 3\n");
		return 1;
	}

	if (ineqPrim > 0) {
		/** Do nothing */
	} else {
		return 1;
	}

	/** STEP 7 */
	rat newT[ineqPrim][varPrim];
	rat newQ[ineqPrim];
	int count = 0;

	for(size_t i = 0; i < n1; i++) {
		for(size_t k = n1; k < n2; k++){
			for(size_t j = 0; j< varPrim ; j++){
					newT[count][j] = subq(t[i][j],t[k][j]);
			}
			newQ[count] = subq(q[i],q[k]);
			count++;
		}
	}

	for(size_t i = n2; i < ineq; i++) {
		for(size_t j = 0; j< varPrim ; j++){
				newT[count][j] = t[i][j];
		}
		newQ[count] = q[i];
		count++;
	}

	return eliminate(ineqPrim, varPrim, newT, newQ);
}

bool fm(size_t rows, size_t cols, signed char a[rows][cols], signed char c[rows])
{
	printf("Hej\n");
	size_t var; /** variables, r */
	size_t ineq; /** inequalities, s */

	rat t[rows][cols];
	rat q[rows];

	var = cols;
	ineq = rows;

	/** STEP 1 */
	for (size_t i = 0; i < ineq; i++)
	{
		rat qtemp;
		
		for (size_t j = 0; j < var; j++)
		{
			rat ttemp;
			ttemp.p =(long long)a[i][j];
			ttemp.q = 1;
			t[i][j] = ttemp;
		}

		qtemp.p = (long long)c[i];
		qtemp.q = 1;
		q[i] = qtemp;
	}

	return eliminate(ineq, var, t, q);
}
