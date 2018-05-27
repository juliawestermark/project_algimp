#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

/** typedef struct rational rat; */

typedef struct rational
{
	long long p;
	long long q;
} rat;

typedef struct list_t list_t;
struct list_t
{
	list_t *next;
	list_t *prev;
	void *data;
};

static list_t *freeList;

list_t *new_list(void *data)
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

void step3(list_t* list, size_t var) {
	if (list->data==NULL) {
		return;
	}
	size_t length = var;
	else {
		for(size_t j=0; j < var; j++){
			// void *data = list->data;
			list->data[j] = divq((list->data[j]),(list->data[var-1]));
		}
		list->data[var] = divq(list->data[var],list->data[var-1]);
	}
	step3(list->next, var);
}

rat step44(rat B, list){
	if (list->data == NULL){
	return B;
}
	else{
		if(subq(list->data[var],B).p<0){
			B = list->data;
		}
		return step45(B, list->next);
	}
}

rat step45(rat b, list){
	if (list->data == NULL){
	return b;
}
	else{
		if(subq(list->data[var],b).p>0){
			b = list->data;
		}
		return step45(b, list->next);
	}
}
boolean step46(list){
	if (list->data== NULL){
		return 1;
	}
	if (list->data < 0){
		return 0;
	}
	else{
		return step46(list->next);
	}
}

bool eliminate(size_t ineq, size_t var, rat t[ineq][var], rat q[ineq]) {

	list_t *pos = new_list(NULL);
	list_t *neg = new_list(NULL);
	list_t *zero = new_list(NULL);

	size_t n1;
	size_t n2;

	n1 = 0;
	n2 = 0;

	/** STEG 2 */
	for (size_t i = 0; i < ineq; i++)
	{
		rat rowTemp[var+1];
		for(size_t j = 0 ; j < var ; j++) {
			rowTemp[j] = t[i][j];
		}
		rowTemp[var] = q[i];

		if (t[i][var-1].p > 0)
		{
			/** Pusha till början av lista */
			// add(pos,rowTemp);
			add(pos,&t[i][0]);
			n1++;
			n2++;
		}
		else if (t[i][var-1].p < 0)
		{
			// add(neg, rowTemp);
			add(pos,&t[i][0]);
			/** Pusha till slutet av lista */
			n2++;
		}
		else
		{
			// add(zero, rowTemp);
			add(pos,&t[i][0]);
			/** Lägg till sistsist */
		}
	}
	/** STEG 3 */

	size_t ineqPrim = ineq - n2 + n1* (n2-n1);
	size_t varPrim = var -1;

	// rat tNew[ineqPrim][varPrim];
	// rat qNew[ineqPrim];
	//

	step3(pos, var);
	step3(neg, var);

	//
	// for (size_t i = 0 ; i < n2 ; i++)
	// {
	// 	for(size_t j = 0 ; j < var ; j++)
	// 	{
	// 		tNew[i][j] = divq(t[i][j],t[i][var-1]);
	// 	}
	// 	qNew[i] = divq(q[i],t[i][var-1]);
	// }

	// #if 0
	// hur gör vi med negativa tal????
	// #endif

	// for (size_t i = 1; i < r - 1)
	// {
	// 	for (size_t j = 1; j < n2)
	// 	{
	// 		t[i][j] = t[i][j] / t[r][j];
	// 		q[j] = q[j] / t[r][j];
	// 		/** Hur gör vi med negativa tal? */
	// 	}
	// }

	/** STEG 4 */
	/** & STEG 5 */

	if (var > 1) /** ELLER varPrim? */
	{
		/** Gå till steg 6 */
	}
	else
	{ /** var==1 eller varprim ==1?*/
		rat B; /* = qNew[0]; 	/** Om B inte finns? */
		rat b; /* = qNew[n1+1]; /** Om b inte finns? */

		if (n2 > n1)
		{

			rat B;
			rat b;
			B.q=1;
			b.q=1;
			B.p = 2147483647
			b.p = -2147483648
			if(step44(B, pos) < step45(b, neg)){
				return 0;
				}
				else{
					return step46(zero);
				}
			}


			// b[r] = max;
			for (size_t i = 1; i < n1; i++) { /** */
				if (subq(qNew[i],B).p < 0 || i == 0) /* Eller om B == NULL ?, dvs i= 0*/
					B = q[i];
			}

		}
		else
		{
			b[r] = -inf
		}

		if (n1 > 0)
		{
			// B[r] = min;
			for (size_t i = n1+1; i < n2; i++) {
				if (subq(qNew[i],b).p > 0 || i == n1+1)
					b = q[i];
			}
		}
		else
		{
			B[r] = inf
		}

		if (ineq > n2) {
			for (size_t i = n2 + 1; i < ineq; i++) {
				if (qNew[i].p < 0)
					return 0;
			}
		}

		if (subq(B,b) < 0) {
			return 0;
		} else {
			return 1;
		}


		// for (size_t i = n2 + 1; i <= ineq; i++)
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

	// 	for(size_t j=0; j < var; j++){
	// 		ttemp[count][j] = pos.data[j];
	// 	}
	// 	pos = pos->next;
	// 	count++;
	// 	}
	// while (neg != NULL) {

	// 	for(size_t j=0; j < var; j++){
	// 	ttemp[count][j] = neg.data[j];
	// 	}
	// 	neg = neg->next;
	// 	count++;
	// }

	list_t negstart = neg;
	for (size_t i = 0 ; i < n1 ; i++) {
		list_t *postemp = pos;
		list_t *negcount = negstart;
		for (size_t k = n1; k < n2 ; k++){
			// negtemp = neg;

			for (size_t j = 0; j < varPrim; j++) {
				postemp = pos;
				list_t *negtemp = neg;
				ttemp[i*n2+k-n1][j] = subq(t[i][j],t[k][j]);
				ttemp[i*n2+k-n1][j] = subq(postemp.data,negcount.data);
				pos = pos->next;
				negcount= negcount->next;
				if (i == n1-1)
					neg = NULL;

			}
			qtemp[i*n2+k-n1]= subq(q[i],q[k]);
			qtemp[i*n2+k-n1]= subq(postemp.data,negcount.data);
		}

	}

	int count = 0 ;
	while (zeros != NULL) {
		for (size_t j = 0 ; j < n-n2; j++){
			ttemp[n1*(n2-n1)+count][j] = zeros.data[j];
		}
		qtemp[n1*(n2-n1)+count] = zeros.data[var];
		zeros = zeros->next;
		count++;
	}

	if (varPrim > 0)
	{
		/** Gå till steg 7 */
	}
	else
	{
		return 1; /** Vad betyder detta? */
	}

	/** STEG 7 */
	var = varPrim;
	ineq = ineqPrim;
	// Define new rxs matrix and new s vector
		/** Gå till steg 2 */
	return eliminate(ineq, var, t, q);
}

bool fm(size_t rows, size_t cols, signed char a[rows][cols], signed char c[rows])
{
	size_t var; /** variables, r */
	size_t ineq; /** inequalities, s */

	rat t[rows][cols];
	rat q[rows];

	var = cols;
	ineq = rows;

	/** STEG 1 */
	for (size_t i = 0; i < ineq; i++)
	{
		for (size_t j = 0; j < var; j++)
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

	return eliminate(ineq, var, t, q);
}
