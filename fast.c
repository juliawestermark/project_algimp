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

/** Circular list */
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

bool eliminate(size_t ineq, size_t var, rat t[rows][cols], rat q[rows]) {

	int n1;
	int n2;

	n1 = 0;
	n2 = 0;

	/** STEG 2 */
	for (int i = 0; i < ineq; i++)
	{
		rat rowTemp[var+1];
		for(int j = 0 ; j < var ; j++) {
			rowTemp[j] = t[i][j];
		}
		rowTemp[var] = q[i];
		
		if (t[i][var-1].p > 0)
		{
			/** Pusha till början av lista */
			add(pos,rowTemp)
			n1++;
			n2++;
		}
		else if (t[i][var-1] < 0)
		{
			add(neg, rowTemp)
			/** Pusha till slutet av lista */
			n2++;
		}
		else
			add(zeros, rowTemp)
			/** Lägg till sistsist */
		}
	}
	/** STEG 3 */

	int ineqPrim = ineq - n2 + n1* (n2-n1);
	int varPrim = var -1;
	
	rat tNew[ineqPrim][varPrim];
	rat qNew[ineqPrim];

	for (int i = 0 ; i < n2 ; i++)
	{
		for(int j = 0 ; j < var ; j++)
		{
			tNew[i][j] = divq(t[i][j],t[i][var-1]);
		}
		qNew[i] = divq(q[i]/t[i][var-1]);
	}

	// #if 0
	// hur gör vi med negativa tal????
	// #endif

	// for (int i = 1; i < r - 1)
	// {
	// 	for (int j = 1; j < n2)
	// 	{
	// 		t[i][j] = t[i][j] / t[r][j];
	// 		q[j] = q[j] / t[r][j];
	// 		/** Hur gör vi med negativa tal? */
	// 	}
	// }

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

		rat B = q[0]; 	/** Om B inte finns? */
		rat b = q[n1+1]; /** Om b inte finns? */

		for (int i = 1; i < n1; i++) {
			if (q[i] < B)
				B = q[i];
		}
		for (int i = n1+2; i < n2; i++) {
			if (q[i] > b)
				b = q[i];
		}
		for (int i = n2 + 1; i < ineq; i++) {
			if (q[i] < 0)
				return 0;
		}

		if (B < b) {
			return 0;
		} else {
			return 1;
		}


		// for (int i = n2 + 1; i <= ineq; i++)
		// {
		// 	if (b[1] > B[1])
		// 	{
		// 		return 0;
		// 	}
		// 	else if (q[i] < 0 && i > n2)
		// 	{
		// 		return 0;
		// 	}
		// 	else
		// 	{
		// 		return 1;
		// 	}
		// }
	}

	/** STEG 6 */

	#if 0
	b[r] <= B[r]
	Add eq from step 2
	sprim = s - n2 + n1 * (n2 - n1);
	#endif




	// 	ttemp[n1*(n2-n1)][var]
	// 	int count = 0 ;
	// 	while (pos != NULL){}

	// 	for(int j=0; j < var; j++){
	// 		ttemp[count][j] = pos.data[j];
	// 	}
	// 	pos = pos->next;
	// 	count++;
	// 	}
	// while (neg != NULL) {

	// 	for(int j=0; j < var; j++){
	// 	ttemp[count][j] = neg.data[j];
	// 	}
	// 	neg = neg->next;
	// 	count++;
	// }




	negstart = neg;
	for (int i = 0 ; i < n1 ; i++) {
		postemp = pos;
		negcount = negstart;
		for (int k = n1; k < n2 ; k++){
			negtemp = neg;

			for (int j = 0; j < varprim; j++) {
				postemp = pos;
				negtemp = neg;
				ttemp[i*n2+k-n1][j] = subq(t[i][j],t[k][j]);
				ttemp[i*n2+k-n1][j] = subq(postemp.data,negcount.data);
				pos = pos->next;
				negcount= negcount->next;
				if (i == n1-1) måsvinge
					neg = NULL;

			}
			qtemp[i*n2+k-n1]= subq(q[i],q[k]);
			qtemp[i*n2+k-n1]= subq(postemp.data,negcount.data);
		}

	}
	int count = 0 ;
	while (zeros != NULL) {
		for (int j = 0 ; j < n-n2; j++){
			ttemp[n1*(n2-n1)+count][j] = zeros.data[j];
		}
		qtemp[n1*(n2-n1)+count] = zeros.data[var];
		zeros = zeros->next;
		count++;
	}
		if (varprim > 0)
		{
			/** Gå till steg 7 */
		}
		else
		{
			return 1;
		}

		/** STEG 7 */
		var = var - 1;
		ineq = ineqprim;
		// Define new rxs matrix and new s vector
			/** Gå till steg 2 */
		return eliminate(size_t ineq, size_t var, rat t[rows][cols], rat q[rows]);
	}

bool fm(size_t rows, size_t cols, signed char a[rows][cols], signed char c[rows])
{
	int var; /** variables, r */
	int ineq; /** inequalities, s */

	list_t pos;
	list_t neg;
	list_t zero;

	rat t[rows][cols];
	rat q[rows];

	var = cols;
	ineq = rows;

	/** STEG 1 */
	for (int i = 0; i < ineq; i++)
	{
		for (int j = 0; j < var; j++)
		{
			rat ttemp;
			rat qtemp;
			ttemp.p =(long long)a[i][j];
			ttemp.q = 1;
			t[i][j] = ttemp;
		}
		qtemp.p = (long long)c[i];
		qtemp.q = 1;
		q[i] = qtemp;
	}



	return eliminate(size_t ineq, size_t var, rat t[rows][cols], rat q[rows])
}
