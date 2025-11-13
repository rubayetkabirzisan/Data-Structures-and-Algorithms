#include<iostream>
using namespace std;
int main ()
{
    int i,j,n;
   cin>>n;
    for(i=1;i<=n;i++)
    {
        int value=i;
        for(j=1;j<=i;j++)
        {
            cout<<value;
            value++;
        }
        cout<<endl;
    }

}




