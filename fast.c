#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#define DEBUG   (1)

#if DEBUG
#define pr(...)         fprintf(stderr, __VA_ARGS__)
#else
#define pr(...)
#endif

/** typedef struct rational rat; */

typedef struct rational
{
	long long p;
	long long q;
} rat;



// typedef struct list_t list_t;
// struct list_t
// {
// 	list_t *next;
// 	rat *data;
// };

// static list_t *freeList;

// list_t *new_list(rat *data)
// {
// 	list_t *list;

// 	if (freeList != NULL)
// 	{
// 		list = freeList;
// 		freeList = freeList->next;
// 	}
// 	else
// 	{
// 		list = malloc(sizeof(list_t));
// 	}
// 	assert(list != NULL);

// 	list->next = NULL;
// 	list->data = data;

// 	return list;
// }

// /** Single linked list */
// void add(list_t *list, rat *data)
// {
// 	list_t *link;
// 	list_t *temp;

// 	link = new_list(data);

// 	link->next = list;
// 	list = link;
// }

// typedef struct list_t list_t;
// struct list_t
// {
// 	list_t *next;
// list_t *prev;
// 	rat *data;
// };

// list_t *new_list(rat *data)
// {
// 	list_t *list;

// 	if (freeList != NULL)
// 	{
// 		list = freeList;
// 		freeList = freeList->next;
// 	}
// 	else
// 	{
// 		list = malloc(sizeof(list_t));
// 	}
// 	assert(list != NULL);

// 	list->next = list->prev = list;
// 	list->data = data;

// 	return list;
// }

// /** Circular list */
// void add(list_t *list, rat *data)
// {
// 	list_t *link;
// 	list_t *temp;

// 	link = new_list(data);

// 	list->prev->next = link;
// 	link->next = list;
// 	temp = list->prev;
// 	list->prev = link;
// 	link->prev = temp;
// }

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

	// pr("HEJ \n %")
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

// void step3(list_t* list, size_t var)
// {
// 	if (list->data==NULL) {
// 		return;
// 	}
// 	else {
// 		for(size_t j=0; j < var; j++){
// 			list->data[j] = divq((list->data)[j],list->data[var-1]);
// 		}
// 		list->data[var] = divq(list->data[var],list->data[var-1]);
// 	}
// 	step3(list->next, var);
// }

// rat step44(rat B, list_t* list, size_t var)
// {
// 	if (list->data == NULL){
// 		return B;
// 	}
// 	else{
// 		if (subq(list->data[var],B).p<0) {
// 			B = list->data[var];
// 		}
// 		return step44(B, list->next, var);
// 	}
// }

// rat step45(rat b, list_t* list, size_t var)
// {
// 	if (list->data == NULL){
// 		return b;
// 	}
// 	else{
// 		if (subq(list->data[var],b).p>0) {
// 			b = list->data[var];
// 		}
// 		return step45(b, list->next, var);
// 	}
// }

// bool step46(list_t* list, size_t var)
// {
// 	if (list->data == NULL){
// 		return 1;
// 	}
// 	if (list->data[var].p < 0){
// 		return 0;
// 	}
// 	else{
// 		return step46(list->next, var);
// 	}
// }

// void step71(size_t ineq, size_t var, rat newT[ineq][var], rat newQ[ineq], list_t* pos, list_t* neg, int count){
// 	for(size_t j = 0; j < var; j++){
// 		newT[count][j] = subq(pos->data[j], neg->data[j]);
// 	}
// 	// newQ[count] = subq(pos->data[var], neg->data[var]);
// 	newT[count][var] = subq(pos->data[var], neg->data[var]);
// 	count++;
// 	if (neg->next != NULL){
// 		step71(ineq, var, newT, newQ, pos, neg->next, count);
// 	}
// }

// void step72(size_t ineq, size_t var, rat newT[ineq][var], rat newQ[ineq], list_t* zero, int count)
// {
// 	for (size_t j = 0; j < var; j++){
// 		newT[count][j] = zero->data[j];
// 	}
// 	// newQ[count] = zero->data[var];
// 	newT[count][var] = zero->data[var];
// 	count++;
// 	if(zero->next != NULL) {
// 		step72(ineq, var, newT, newQ, zero->next, count);
// 	}
// 	count = 0;
// }


// void step73(size_t ineq, size_t var, rat newT[ineq][var], rat newQ[ineq], list_t* pos, list_t* neg, int count){
// 	step71(ineq, var, newT, newQ, pos, neg, count);
// 	if(pos->next != NULL) {
// 		step73(ineq, var, newT, newQ, pos->next, neg, count);
// 	}
// }

void swap(rat *a, rat *b) {
    rat temp = *a;
    *a = *b;
    *b = temp;
}

// void swapRows(size_t ineq, size_t var, rat t[ineq][var], rat q[ineq][var], size_t rowOne, size_t rowTwo) {
void swapRows(size_t ineq, size_t var, rat t[ineq][var], rat q[ineq], size_t rowOne, size_t rowTwo) {
	size_t j;
	for (j = 0; j < var; j++) {
		swap(&t[rowOne][j], &t[rowTwo][j]);
	}
	swap(&q[rowOne], &q[rowTwo]);
}
void db() {

}

bool eliminate(size_t ineq, size_t var, rat t[ineq][var], rat q[ineq]) {

	// list_t *pos = new_list(NULL);
	// list_t *neg = new_list(NULL);
	// list_t *zero = new_list(NULL);

	pr("Start\n");

	size_t n1;
	size_t n2;
	n1 = 0;
	n2 = 0;

	// int a;
    // int b;

	// swapRows(ineq, var, t, q, rowOne, rowTwo);

	n1 = 0;
	n2 = ineq;

	size_t i = 0;

	while (i < n2 && i < ineq) {
		db();
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

	// /** STEG 2 */
	// for (i = 0; i < ineq; i++)
	// {
	// 	// rat rowTemp[var+1];
	// 	// for(size_t j = 0 ; j < var ; j++) {
	// 	// 	rowTemp[j] = t[i][j];
	// 	// }
	// 	// rowTemp[var] = q[i];

	// 	if (t[i][var-1].p > 0)
	// 	{
	// 		/** Pusha till början av lista */
	// 		// add(pos,rowTemp);
	// 		add(pos,&t[i][0]);
	// 		n1++;
	// 		n2++;
	// 	}
	// 	else if (t[i][var-1].p < 0)
	// 	{
	// 		// add(neg, rowTemp);
	// 		add(neg,&t[i][0]);
	// 		/** Pusha till slutet av lista */
	// 		n2++;
	// 	}
	// 	else
	// 	{
	// 		// add(zero, rowTemp);
	// 		add(zero,&t[i][0]);
	// 		/** Lägg till sistsist */
	// 	}
	// }
	// db();
	/** STEG 3 */

	size_t ineqPrim = ineq - n2 + n1* (n2-n1);
	size_t varPrim = var -1;

	// // rat tNew[ineqPrim][varPrim];
	// // rat qNew[ineqPrim];
	// //
	// if (n1>0) {
	// step3(pos, varPrim);
	// }
	// if (n2-n1>0) {
	// step3(neg, varPrim);
	// }
	//

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

	// if (var > 1) /** ELLER varPrim? */
	// {
	// 	/** Gå till steg 6 */
	// }
	// else
	// { /** var==1 eller varprim ==1?*/
	//
	// 	if (n2 > n1) {
	//
	// 		rat B; /* = qNew[0]; 	 Om B inte finns? */
	// 		rat b; /* = qNew[n1+1]; Om b inte finns? */
	//
	// 		B.q=1;
	// 		b.q=1;
	// 		B.p = 2147483647;
	// 		b.p = -2147483648;
	//
	// 		if (subq(step44(B, pos, var), step45(b, neg, var)).p < 0) {
	// 			return 0;
	// 		}
	// 		if (ineqPrim > n2) {
	// 			return step46(zero, var);
	// 		}
	//
	// 		return 1;
	// 	}
	//


		if (var > 1) {

		}
		else{
			pr("Else rad 477\n");

			// if(n2>n1) {
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
			// }
		}

		//
		// 	// b[r] = max;
		// 	for (size_t i = 1; i < n1; i++) { /** */
		// 		if (subq(qNew[i],B).p < 0 || i == 0) /* Eller om B == NULL ?, dvs i= 0*/
		// 			B = q[i];
		// 	}
		//
		// }
		// else
		// {
		// 	b[r] = -inf
		// }
		//
		// if (n1 > 0)
		// {
		// 	// B[r] = min;
		// 	for (size_t i = n1+1; i < n2; i++) {
		// 		if (subq(qNew[i],b).p > 0 || i == n1+1)
		// 			b = q[i];
		// 	}
		// }
		// else
		// {
		// 	B[r] = inf
		// }
		//
		// if (ineq > n2) {
		// 	for (size_t i = n2 + 1; i < ineq; i++) {
		// 		if (qNew[i].p < 0)
		// 			return 0;
		// 	}
		// }
		//
		// if (subq(B,b) < 0) {
		// 	return 0;
		// } else {
		// 	return 1;
		// }


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

	/** STEG 6 */


	// b[r] <= B[r]
	// Add eq from step 2
	// sprim = s - n2 + n1 * (n2 - n1);
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

	if (ineqPrim > 0) {

	} else {
		return 1;
	}

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

	//
	// if (n1 > 0 && n2 > n1) {
	// 	step73(ineqPrim, varPrim, newT, newQ, pos, neg, count);
	// }
	// if (ineqPrim-n2> 0) {
	// 	step72(ineqPrim, varPrim, newT, newQ, zero, count);
	// }
	//
	// return eliminate(ineqPrim, varPrim, newT);
	//
	//
	//
	//
	// //
	// list_t negstart = neg;
	// for (size_t i = 0 ; i < n1 ; i++) {
	// 	list_t *postemp = pos;
	// 	list_t *negcount = negstart;
	// 	for (size_t k = n1; k < n2 ; k++){
	// 		// negtemp = neg;
	//
	// 		for (size_t j = 0; j < varPrim; j++) {
	// 			postemp = pos;
	// 			list_t *negtemp = neg;
	// 			ttemp[i*n2+k-n1][j] = subq(t[i][j],t[k][j]);
	// 			ttemp[i*n2+k-n1][j] = subq(postemp.data,negcount.data);
	// 			pos = pos->next;
	// 			negcount= negcount->next;
	// 			if (i == n1-1)
	// 				neg = NULL;
	//
	// 		}
	// 		qtemp[i*n2+k-n1]= subq(q[i],q[k]);
	// 		qtemp[i*n2+k-n1]= subq(postemp.data,negcount.data);
	// 	}
	//
	// }
	//
	// int count = 0 ;
	// while (zeros != NULL) {
	// 	for (size_t j = 0 ; j < n-n2; j++){
	// 		ttemp[n1*(n2-n1)+count][j] = zeros.data[j];
	// 	}
	// 	qtemp[n1*(n2-n1)+count] = zeros.data[var];
	// 	zeros = zeros->next;
	// 	count++;
	// }
	//
	// if (varPrim > 0)
	// {
	// 	/** Gå till steg 7 */
	// }
	// else
	// {
	// 	return 1; /** Vad betyder detta? */
	// }

	/** STEG 7 */
	// var = varPrim;
	// ineq = ineqPrim;
	// Define new rxs matrix and new s vector
		/** Gå till steg 2 */

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

	/** STEG 1 */
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
		// qtemp.p = (long long)c[i];
		// qtemp.q = 1;
		// t[i][var] = qtemp;

		qtemp.p = (long long)c[i];
		qtemp.q = 1;
		q[i] = qtemp;
	}

	return eliminate(ineq, var, t, q);
}
