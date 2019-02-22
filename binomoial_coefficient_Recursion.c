#include <stdio.h>
int bin_coeff(int n,int k)
{
    if(k==0 || k==n)
        return 1;
    else
        return(bin_coeff(n-1,k-1)+bin_coeff(n-1,k));
}
int main()
{
    int n,k,cof;
    scanf("%d %d",&n,&k);
    cof=bin_coeff(n,k);
    printf("%d",cof);
}
