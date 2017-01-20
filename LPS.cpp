//Longest palindromic substring in O(n^2) time and O(1) space

#include <iostream>
#include <string.h>
using namespace std;

int longPalSubstr(char str[])   {
    int n = strlen(str);
    int i,low,high,len=1,start=0,maxlen=1;
    for(i=1;i<n;i++)    {
        //find even length substrings centred at i-1 and i
        low=i-1; high=i;
        while(low>=0 && high<n && str[low]==str[high])  {
            len = high-low+1;
            low--; high++;
        }
        if(len>maxlen)  {
            maxlen = len;
            start = i - len/2;
        }

        //find odd length substring centred at i
        low=i-1; high=i+1;
        while(low>=0 && high<n && str[low]==str[high])  {
            len = high-low+1;
            low--; high++;
        }
        if(len>maxlen)  {
            maxlen = len;
            start = i - len/2;
        }
    }
    cout<<"Longest palindromic substring : ";
    for(i=start;i<start+maxlen;i++)
        cout<<str[i];
    return maxlen;
}

int main()  {
    char str[20];
    cin>>str;
    cout<<"\nLength : "<<longPalSubstr(str)<<"\n";
    return 0;
}
