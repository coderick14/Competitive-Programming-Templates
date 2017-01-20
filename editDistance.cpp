#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int editDistance(char s1[],char s2[])  {
    int m=strlen(s1);
    int n=strlen(s2);
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)   {
        for(int j=0;j<=n;j++)   {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}

int main()  {
    char s1[30],s2[30];
    cout<<"Hi";
    cin>>s1;
    cin>>s2;
    cout<<"\nEdit distance : "<<editDistance(s1,s2)<<"\n";
    return 0;
}
