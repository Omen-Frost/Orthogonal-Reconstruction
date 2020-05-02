#include "visualization.hpp"

#define margin 30
#define width 700
#define height 700
#define scale 12
void draw(vector<edge>& v,vector<pair<int,int>>& points)
{
    ofstream file,pt;
    file.open("output.svg");
    pt.open("input.svg");
    file<<"<svg xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file<<"<rect width=\""<<width+2*margin<<"\" height=\""<<height+2*margin<<"\" style=\"fill:rgb(255,255,255); stroke-width:"<<1<<"; stroke:rgb(0,0,0)\" />"<<endl;
    pt<<"<svg xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    pt<<"<rect width=\""<<width+2*margin<<"\" height=\""<<height+2*margin<<"\" style=\"fill:rgb(255,255,255); stroke-width:"<<1<<"; stroke:rgb(0,0,0)\" />"<<endl;
    for(auto &z:v)
    {
        file<<"<line x1=\""<<margin+z.u.first*scale<<"\" y1=\""<<margin+z.u.second*scale<<"\" x2=\""<<margin+z.v.first*scale<<"\" y2=\""<<margin+z.v.second*scale<<"\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl;
        file<<"<circle cx=\""<<margin+z.u.first*scale<<"\" cy=\""<<margin+z.u.second*scale<<"\" r=\""<<2<<"\" fill=\"black\" fill-opacity=\"1\" />"<<endl;
        file<<"<circle cx=\""<<margin+z.v.first*scale<<"\" cy=\""<<margin+z.v.second*scale<<"\" r=\""<<2<<"\" fill=\"black\" fill-opacity=\"1\" />"<<endl;
    }
    for(auto &z:points)
    {
        pt<<"<circle cx=\""<<margin+z.first*scale<<"\" cy=\""<<margin+z.second*scale<<"\" r=\""<<2<<"\" fill=\"black\" fill-opacity=\"1\" />"<<endl;
    }
    file<<"</svg>"<<endl;
    pt<<"</svg>"<<endl;
    file.close();
    pt.close();
}