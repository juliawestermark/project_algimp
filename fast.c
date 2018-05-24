#include <stdbool.h>
#include <stdio.h>

static list_t *freeList;

/** typedef struct rational rat; */

typedef struct rational
{
	long long p;
	long long q;
} rat;

/** typedef struct list_t list_t; */

typedef struct list_t
{
	list_t *next;
	list_t *prev;
	void *data;
} list_t;

list_t *newList(void *data)
{
	list_t *list;

	if (freeList != NULL)
	{
		list = freeList;
		freeList = freeList->next;
	}
	else
	{
		list = malloc(sizeof(list_t));
	}
	assert(list != NULL);

	list->next = list->prev = list;
	list->data = data;

	return list;
}

void add(list_t *list, void *data)
{
	list_t *link;
	list_t *temp;

	link = new_list(data);

	list->prev->next = link;
	link->next = list;
	temp = list->prev;
	list->prev = link;
	link->prev = temp;
}

rat reduce(rat x)
{
	int a = x.p;
	int b = x.q;

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

	z.p = x.p * y.q + y.p * x.q;
	z.q = x.q * y.q;

	z = reduce(z);

	return z;
}

rat subq(rat x, rat y)
{
	rat z;

	z.p = x.p * y.q - y.p * x.q;
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
	int var; /** variables, r */
	int ineq; /** inequalities, s */

	int n1;
	int n2;

	list_t pos;
	list_t neg;
	list_t zero;

	rat t[rows][cols];
	rat q[cols];

	var = cols;
	ineq = rows;

	/** STEG 1 */
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			t[i][j] = a[i][j];
			q[j] = c[j];
		}
	}

	n1 = 0;
	n2 = 0;

	for (int j = 0; j < s; j++)
	{
		
		/** STEG 2 */
		if (t[r][j] > 0)
		{
			/** Pusha till början av lista */
			pos = add(pos,t[][j])
			n1++;
			n2++;
		}
		else if (t[r][j] < 0)
		{
			/** Pusha till slutet av lista */
			n2++;
		}
		else
		{
			/** Lägg till sistsist */
		}
	}
	/** STEG 3 */
	for (int i = 1; i < r - 1)
	{
		for (int j = 1; j < n2)
		{
			t[i][j] = t[i][j] / t[r][j];
			q[j] = q[j] / t[r][j];
			/** Hur gör vi med negativa tal? */
		}
	}

	/** STEG 4 */
	if (n2 > n1)
	{
		b[r] = max;
	}
	else
	{
		b[r] = -inf
	}

	if (n1 > 0)
	{
		B[r] = min;
	}
	else
	{
		B[r] = inf
	}

	/** STEG 5 */

	if (r > 1)
	{
		/** Gå till steg 6 */
	}
	else
	{ /** r=1 */
		for (int j = n2 + 1; j <= s; j++)
		{
			if (b[1] > B[1] || q[j] < 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}

	/** STEG 6 */

	b[r] <= B[r] Add eq from step 2 sprim = s - n2 + n1 * (n2 - n1);
	if (sprim > 0)
	{
		/** Gå till steg 7 */
	}
	else
	{
		return 1;
	}

	/** STEG 7 */
	r = r - 1;
	s = sprim;
	Define new rxs matrix and new s vector
		/** Gå till steg 2 */

		return 0;
}
