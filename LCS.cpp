//Longest Common Subsequence
//Time complexity O(mn)
//Space complexity O(mn)
#include <bits/stdc++.h>
using namespace std;

void printLCS(char s1[], char s2[]) {
    int i,j;
    int m = strlen(s1);
    int n = strlen(s2);
    int LCS[m+1][n+1];
    for(i=0; i<=m; i++) {
        for(j=0; j<=n; j++) {
            if(i==0 || j==0)
                LCS[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    int index = LCS[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    i = m; j = n;
    while(i > 0 && j > 0)   {
        if(s1[i-1] == s2[j-1])  {
            lcs[index-1] = s1[i-1];
            i--; j--; index--;
        }
        else if(LCS[i-1][j] > LCS[i][j-1])
            i--;
        else
            j--;
    }
    cout<<lcs<<endl;
}

int main()  {
    char s1[30],s2[30];
    cin>>s1;
    cin>>s2;
    printLCS(s1,s2);
    return 0;
}
