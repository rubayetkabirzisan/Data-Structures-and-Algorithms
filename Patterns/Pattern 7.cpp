#include <iostream>
using namespace std;
int main()
{
    int num = 1,n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout<<" ";
        }
        for (int k = i; k <= n; k++)
        {
            cout<<num;
        }
        cout<<endl;;
        num++;
    }
    return 0;
}

