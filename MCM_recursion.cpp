#include<bits/stdc++.h>
using namespace std;
/*MCM Steps
1.find i,j
2.find base case
3.find k loop scheme
4.calculate answer from temprery ans
*/
int solve(int a[],int i,int j)
{ 
    int mn=INT_MAX;
    if(i>=j)
    return 0;
    for(int k=i;k<=j-1;k++)
    {
       int temp_ans=solve(a,i,k)
                      +solve(a,k+1,j)
                      +(a[i-1]*a[k]*a[j]);
       if(temp_ans<mn)
       {
           mn=temp_ans;
       }
    }
    return mn;
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
    int i=1;
    int j=n-1;
    cout<<solve(a,i,j);        
    
    return 0;
}
