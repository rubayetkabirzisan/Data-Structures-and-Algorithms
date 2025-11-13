#include<bits/stdc++.h>
using namespace std;
//void printVec(vector<pair<int,int>>&v)
//{
//    cout<<"Size : "<<v.size()<<endl;
//    for(int i=0; i<v.size(); i++)
//    {
//        cout<<v[i].first<<" "<<v[i].second<<endl;
//
//    }
//
//    cout<<endl;
//}
void printVec(vector<int>&v)
{
    cout<<"Size : "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" "<<endl;

    }

    cout<<endl;
}
int main ()
{
    //vector<pair<int,int>>v={{1,2},{2,3},{3,5}};
//    vector<pair<int,int>>v;
//    printVec(v);
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        int x,y;
//        cin>>x>>y;
//        v.push_back({x,y});
//    }
//    printVec(v);
//    int n;
//    cin>>n;
//    vector<int>v[n];
//    for(int i=0; i<n; i++)
//    {
//        int n1;
//        cin>>n1;
//        for(int j=0; j<n1; j++)
//        {
//            int x;
//            cin>>x;
//            v[i].push_back(x);
//        }
//    }
//    for(int i=0;i<n;i++)
//    {
//        printVec(v[i]);
//    }
    int n;
    cin>>n;
    vector<vector<int>>v;
    for (int i=0; i<n; i++)
    {
        int n1;
        cin>>n1;
        //vector<int>temp;
        v.push_back(vector<int>());
        for(int j=0; j<n1; j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);

        }
        //v.push_back(temp);
    }
    //v[0].push_back(10);
//    v.push_back(vector<int>());
    for(int i=0; i<v.size(); i++)
    {
        printVec(v[i]);
    }
    cout<<v[0][1];
}
