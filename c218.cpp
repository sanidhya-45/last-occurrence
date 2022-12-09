#include <iostream>
using namespace std; 
////////////  indes of first occurence of a given number ////
// naive solution
int var=INT16_MAX;
int OLOGN(int a[], int k,int low, int high)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==k)
            {
                var=min(var,mid);
                // if(a[mid]!=0 || a[mid-1]!=a[mid])
                // return mid; 
                if(var==0) return mid;
                return OLOGN(a,k,low,mid-1);
            }
        else if(a[mid]<k)
            return OLOGN(a,k,mid+1,high);
        else return OLOGN(a,k,low,mid-1);
        

    }
    if(var==INT16_MAX)
        return -1;
    return var;
}
int main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;

    n=OLOGN(a,k,0,n);
    cout<<n;

    // int u=-1;
    // for(int i=0;i<n;i++)
    // {
    //     if(k==a[i])
    //         {
    //             u=i;
    //             break;
    //         }
    // }
    // cout<<u;
    // above takesO(n) time
return 0;
}