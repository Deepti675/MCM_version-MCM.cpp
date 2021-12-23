#include <bits/stdc++.h>

using namespace std;
int t[1002][1002];
int memoize_MCM(int a[],int i,int j)
{
    if(i>=j)
    {
    return 0;
    }
    if(t[i][j]!=-1)
    {
    return t[i][j];
    }
    t[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        t[i][j]=min(t[i][j],memoize_MCM(a,i,k)
        +memoize_MCM(a,k+1,j)
        +a[i-1]*a[k]*a[j]);
        
    }
    return t[i][j];
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   memset(t,-1,sizeof(t));
   int i=1;
   int j=n-1;
   cout<<memoize_MCM(a,i,j);
    return 0;
}
