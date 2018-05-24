#include <stdbool.h>
#include <stdio.h>

struct rational {
	int p;
	int q;
};

typedef struct rational rat;

rat reduce(rat x)
{
	int a=x.p;
	int b=x.q;

	if (a == 0 || b == 0)
	{
		x.q = 0;
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

rat addq(rat x, rat y)
{
	rat z;

	z.p = x.p*y.q + y.p*x.q;
	z.q = x.q * y.q;

	z = reduce(z);

	return z;
}

rat subq(rat x, rat y)
{
	rat z;

	z.p = x.p*y.q - y.p*x.q;
	z.q = x.q * y.q;

	z = reduce(z);

	return z;
}

rat mulq(rat x, rat y)
{
	rat z;

	z.p = x.p * y.p;
	z.q = x.q * y.q;

	z = reduce(z);

	return z;
}

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

bool fm(size_t rows, size_t cols, signed char a[rows][cols], signed char c[rows])
{

	return 0;
}
