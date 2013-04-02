#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char n[10];
int p, maradek, max, i, j, t, hossz;
char tabla[5010][1200];
char * add(char * a, char * b)
{
	char eredmeny[1200] = {'0'}, a2[1200] = {'0'}, b2[1200] = {'0'};
	j = 0;
	memcpy(b2,b,strlen(b)+1);
	memcpy(a2,a,strlen(a)+1);
	
    if(strlen(a) < strlen(b))
	{ 
		max = strlen(b) - 1;
		for(i = 0; i < abs(strlen(a) - strlen(b)); i++)
			a2[i] = '0';
		t = i;
		for(i, j = 0; i < t + strlen(a); i++, j++)
			a2[i] = a[j];
	}
	else
	{ 
		max = strlen(a) - 1;
		for(i = 0; i < abs(strlen(a) - strlen(b)); i++)
			b2[i] = '0';
		t = i;
		for(i, j = 0; i < t + strlen(b); i++, j++)
			b2[i] = b[j];
	}
    
	for(i = max, j = max + 1; i >= 0; i--)
	{
		t = maradek;
		t += (a2[i] - '0' + b2[i] - '0');
		eredmeny[j--] = (t % 10) + '0';
		maradek = t / 10;
	}
	
    if(maradek) eredmeny[j] = '1';
	
    for(i = 0; eredmeny[i] == '0'; i++) ;

	eredmeny[hossz = strlen(eredmeny+i-1)+1] = '\0';
	
    return (eredmeny+i-1);
}

void fibonacci()
{
	int i;
	hossz = 1;
	for(i = 2; i <= 5000; i++)
	{
		memcpy(tabla[i],add(tabla[i-1],tabla[i-2]),hossz+1);
	}
}
int main()
{
	tabla[0][0] = '0';
	tabla[0][1] = '0';
	tabla[0][2] = '\0';
    tabla[1][0] = '0';
	tabla[1][1] = '1';
	tabla[1][2] = '\0';
	
	fibonacci();
	while(scanf("%s",n) != EOF)
	{
		p = atoi(n);
		printf("%s\n",tabla[p]+1);
	}
	return 0;
}
