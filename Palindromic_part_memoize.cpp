//memoize palindromic partitions 
#include <bits/stdc++.h>

using namespace std;
int t[1002][1002];
bool ispalindrom(string x,int i,int j)
{
    while(i<j)
    {
        if(x[i]!=x[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int solve(string x,int i,int j)
{
    if(i>=j)
    return 0;
    if(ispalindrom(x,i,j)==true)
    return 0;
    if(t[i][j]!=-1)
    return t[i][j];
    t[i][j]=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        t[i][j]=min(t[i][j],1+(solve(x,i,k)+solve(x,k+1,j)));
        
    }
    return t[i][j];
}
int main()
{
    string x;
    cin>>x;
    int n=x.size();
    int i=0;
    int j=n-1;
    memset(t,-1,sizeof(t));
    cout<<solve(x,i,j);

    return 0;
}
