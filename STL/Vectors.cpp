#include<bits/stdc++.h>
using namespace std;
//void printVec(vector<int>&v)
//{
//    cout<<"Size : "<<v.size()<<endl;
//    for(int i=0; i<v.size(); i++)
//    {
//        cout<<v[i]<<" ";
//
//    }
//    //v.push_back(2);
//    cout<<endl;
//}
void printVec(vector<string>&v)
{
    cout<<"Size : "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";

    }
    //v.push_back(2);
    cout<<endl;
}
int main ()
{
    //int a[10];
//    vector<int>v(10,3);
//    v.push_back(7);
//    v.push_back(17);
//     vector<int>v;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//          printVec(v);
//         v.push_back(x);
//     }
    //printVec(v);
    //v.pop_back();
    //printVec(v);

//    vector<int>&v2=v;//O(n) Time Complexity
//    v2.push_back(5);
//    printVec(v);
//     printVec(v);
//    printVec(v2);
    vector<string>v;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    printVec(v);

}
