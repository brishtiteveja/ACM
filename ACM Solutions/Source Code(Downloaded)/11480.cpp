#include <stdio.h>
#include <stdlib.h>
int n, ex;
long long int c;
int main()
{
  while(1)
  {
    scanf("%d",&n);
    if(n == 0) break;
    printf("Case %d: ",++ex);
    c = 0;
    for(int i = 2; i <= n - 3; i++)
    {
      if( (n - i) % 3 == 0 )
      {
        if(i % 2 == 0) c += i/2 - 1;
        else c += i / 2;
      }
    }
    printf("%llu\n",c);
  }
  return 0;
}
