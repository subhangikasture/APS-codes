
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long fact(int n){
    long long res=1;
    int i;
    for(i=1;i<=n;i++){

            res*=i;
    }
    return res;
}
int permutation(char *s,char c)
{
    int i,hash[26]={0},total;
    for(i=0;i<strlen(s);i++)
    {
        hash[s[i]-'A']++;
    }
    int element=hash[c-'A'];
    if(element==0)
        return 0;
    hash[c-'A']=0;
    total=strlen(s);
    total=total-element+1;
    long long res=fact(total);

    for(i=0;i<26;i++)
    {
       if(hash[i]>1){
        res=res/fact(hash[i]);
       }
    }
    return res;
}

int main()
{
    char s[10]={"KLECSEKLE"};
    char c='E';
    int res;
    res=permutation(s,c);
    printf("%d",res);
    return 0;
}
