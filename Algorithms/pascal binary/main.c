#include <stdio.h>
#include <stdlib.h>
#define N 10

void pascal1()
{
	int pas[N][N],i,j;
	
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			pas[i][j]=-1;
	
	
    pas[0][0]=1;
	pas[1][0]=pas[1][1]=1;
	
    for(i=2;i<N;i++){
		pas[i][0]=1;
        for(j=1;j<i;j++){
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
		}
		pas[i][i]=1;
    }
	
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++) 
            printf("%3d   ",pas[i][j]);
		printf("\n");
    }
}
void pascal2() {
	int *pas[N], i, j,total=0;
	
	for (i=0; i<N; i++){ 
		pas[i] = (int *) malloc(sizeof(int)*(i+1));
	
		total+=sizeof(int)*(i+1);
	}
	pas[0][0] = 1;
	pas[1][0] = pas[1][1] = 1;
	
	for (i = 2; i<N; i++) 
	{ 
		pas[i][0] = pas[i][i] = 1;
		for (j = 1; j<i; j++) 
		{
			pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
		}
	} 
	for (i=0; i<N; i++) 
	{
		for (j=0; j<i+1; j++) 
			printf("%3d ", pas[i][j]);
		printf("\n");
	}

	
	printf("total %d byte \n",total);
}

struct entry 
{ 
	int value; 
	struct entry *next;
};

struct entry *newEntry(int value, struct entry *next) 
{
	struct entry *e = (struct entry*) malloc(sizeof(struct entry)); 
	e->value = value; 
	e->next = next; 
	return e;
}
void pascal3() {
	struct entry *pas[N], *p, *q; 
	int i, j;
	pas[0] = newEntry(1, NULL); 
	pas[1] = newEntry(1, newEntry(1, NULL));
	for (i = 2; i<N; i++) 
	{ 
		p = pas[i-1]; 
		q = pas[i] = newEntry(1, NULL); 
		for (j = 1; j<i; j++) {
			q->next = newEntry( p->value + (p->next)->value , NULL);
			p = p->next;
			q = q->next;
		}
			q->next = newEntry(1, NULL);
	} 
	for (i=0; i<N; i++) {
		for(p = pas[i]; p->next != NULL; p = p->next)
			printf("%3d ", p->value);
		printf("%3d \n", p->value);
	}
}

void print_array (int a[], int n) 
{
	int i;
	for (i = 0; i < n-1; i++) 
		printf("%d,",a[i]); 
	printf("%d\n",a[n-1]);
}
void sort (int a[], int n) 
{ 
	int i,j,tmp; 
	for (i = 1; i < n; i++)
	for (j = i; j > 0 && a[j-1] > a[j]; j--) 
	{ 
		tmp = a[j]; a[j] = a[j-1]; 
		a[j-1] = tmp;
		print_array(a, n);
	}
}
int main (int argc, const char * argv[]) {
	int a[5]={5,4,3,2,1};
	sort(a,5);
    return 0;
}
