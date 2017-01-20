#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct interval {
    int s;
    int e;
};

bool comp(interval a, interval b)   {
    return a.s>b.s;
}

void mergeIntervals(vector<interval> &a, int n) {
    sort(a.begin(),a.end(),comp);
    int index = 0;

    for(int i=0;i<n;i++)    {
        if(index != 0 && a[index-1].s <= a[i].e)    {
            while(index != 0 && a[index-1].s <= a[i].e) {
                a[index-1].s = min(a[index-1].s, a[i].s);
                a[index-1].e = max(a[index-1].e, a[i].e);
                index--;
            }
        }
        else    {
            a[index] = a[i];
        }
        index++;
    }
    for(int i=0;i<index;i++)
        cout<<a[i].s<<" "<<a[i].e<<"\n";
}

int main()  {
    int n;
    cin>>n;
    vector<interval> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i].s>>a[i].e;
    mergeIntervals(a,n);
    return 0;
}
