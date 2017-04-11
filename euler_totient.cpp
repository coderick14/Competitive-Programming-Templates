#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAX 1000005
long long phi[MAX];
void generatePhi()
{

    phi[1]=1;
    for(int i=2; i<MAX; i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for(int j=(i<<1);j<MAX;j=j+i)
            {
                if(!phi[j]) 
                    phi[j]=j;

                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}

long long solutions[MAX];
int main()
{
    generatePhi();


    for(int i=1; i<MAX; i++)
    {
        for(int j=2; i*j<MAX; j++)
            solutions[i*j] += i*phi[j];
    }

    for(int i=2; i<MAX; i++)
    {
        solutions[i] += solutions[i-1];
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<solutions[n]<<endl;
    }
    return 0;
}
