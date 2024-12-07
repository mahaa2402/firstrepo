//code to generate prime no using sieve of eratosthenes
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    vector<int> prime(n+1,1);
    prime[0]=prime[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(prime[i]==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}