//palindromic partitions 
#include <bits/stdc++.h>

using namespace std;
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
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp_ans=1+(solve(x,i,k)+solve(x,k+1,j));
        if(temp_ans<ans)
        ans=temp_ans;
        
    }
    return ans;
}
int main()
{
    string x;
    cin>>x;
    int n=x.size();
    int i=0;
    int j=n-1;
    cout<<solve(x,i,j);

    return 0;
}
