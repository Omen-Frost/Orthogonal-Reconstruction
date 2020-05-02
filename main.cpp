#include <bits/stdc++.h>
using namespace std;

#include "generate.hpp"
#include "visualization.hpp"
#include "edge_struct.hpp"


bool compare_by_second(pair<int,int>& a, pair<int,int>& b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    bool self_intersecting; 
    int turns=0;
    // Repeat until a successful no self-intersecting polygon is formed
    while(1)
    {
        if(turns>2e5)
        {
            cout<<"Unable to terminate\n";
            return 0;
        }
        turns++;
        self_intersecting=0;
        
        vector<pair<int,int>> points= random_generate();

        int i=0;
        vector<edge> edges;
        edge nw;

        //Add horizontal edges
        sort(points.begin(),points.end(),compare_by_second);
        vector<pair<int,int>> seg;
        while(i<points.size())
        {
            assert(points[i].second==points[i+1].second);

            nw={points[i],points[i+1]};
            edges.push_back(nw);
            seg.push_back(points[i]);
            seg.push_back({points[i+1].first+1,-points[i+1].second});
            i+=2;
        }
        sort(seg.begin(),seg.end());
        int h=0;
        set<int> Y;
        //Add vertical edges
        sort(points.begin(),points.end());
        i=0;
        while(i<points.size())
        {
            assert(points[i].first==points[i+1].first);

            while(h<seg.size() && seg[h].first<=points[i].first)
            {
                if(seg[h].second<0) Y.erase(-seg[h].second);
                else Y.insert(seg[h].second);
                h++;
            }
            nw={points[i],points[i+1]};
            edges.push_back(nw);

            int l=points[i].second,r=points[i+1].second;
            auto lt=Y.upper_bound(l);
            auto rt=Y.lower_bound(r);
            // check if edges intersect
            if(lt!=rt)
            {
                self_intersecting=1;break;
            }
            i+=2;
        }
        if(!self_intersecting)
        {
            draw(edges,points);
            break;
        }
        edges.clear();seg.clear();points.clear();Y.clear();
    }
    
    cout<<"Finished successfully\n"<<"#Turns ="<<turns<<'\n';
    return 0;
}

