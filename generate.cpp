#include "generate.hpp"

//parameters
#define p 9
#define width 20
#define height 30
#define thresh 3
#define min_sep 1
#define q 9 

vector<pair<int,int>> random_generate()
{
    vector<pair<int,int>> v;
    bool odd[width*2]={0};
    srand(time(0));
    int i,j;

    map< pair<int,int>, bool> mp; //avoid repeatation
    int t=p;
    while(t--)
    {
        int row=rand()%height+1;
        int x1,x2,y;
        y=row;

        x1=rand()%width+1;
        x2=x1+rand()%thresh+min_sep;

        if(!mp[{x1,y}] && !mp[{x2,y}])
        {
            mp[{x1,y}]=1;
            mp[{x2,y}]=1;
            v.push_back({x1,y});
            odd[x1]^=1;
            v.push_back({x2,y});
            odd[x2]^=1;
        }
        else t++;
    }
    vector<int> X;
    for(i=1;i<2*width;i++) if(odd[i]) X.push_back(i);
    assert(X.size()%2==0);

    i=0;
    // Ensure no vertical column has odd points
    while(i!=X.size())
    {
        int row=rand()%height+1;
        if(!mp[{X[i],row}] && !mp[{X[i+1],row}]) 
        {
            v.push_back({X[i],row});
            v.push_back({X[i+1],row});
            i+=2;
        }
    }
    assert(v.size()%2==0);
    X.clear();mp.clear();
    return v;
}