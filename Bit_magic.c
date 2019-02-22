#include <stdio.h>
int main()
{
    int no_ones,twos_compliment1,twos_compliment2,res=0,p;
    int n;
    scanf("%d",&n);
    p=n;
    while(n){
        res=res+1;
        n=n&(n-1);
    }
    printf("no of ones %d\n",res);

    twos_compliment1=-p;
    twos_compliment2=~p+1;
    printf("twos_compliment1:%d twos_compliment2:%d \n",twos_compliment1,twos_compliment2);
}
