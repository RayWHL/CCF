#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
struct edge {
    int to;
    edge *next;
};
struct node
{
    int i;
    int f;
    int color;
    edge *next;

    bool operator <(const node temp) const
    {
        return f>temp.f;
    }
};
node g[10000];
node g1[10000];
vector<node> s;
int time=0;
void addedge(int a,int b)
{
    edge *temp= new edge;
    temp->to=b;
    temp->next=g[a].next;
    g[a].next=temp;

    edge *temp2=new edge;
    temp2->to=a;
    temp2->next=g1[b].next;
    g1[b].next=temp2;
}

void dfs(int i)
{
    ++time;
    g[i].color=1;
    for(edge *p=g[i].next;p;p=p->next)
    {
        if(g[p->to].color==0)
            dfs(p->to);
    }
    g[i].color=2;
    ++time;
    g[i].f=time;
    s.push_back(g[i]);
}

void dfsvisit()
{
    for(int i=0;i<n;++i)
    {
        if(g[i].color==0)
            dfs(i);
    }
}

void dfs1(int i)
{
    g1[i].color=1;
    for(edge *p=g1[i].next;p;p=p->next)
    {
        if(g1[p->to].color==0)
            dfs1(p->to);
    }
    g1[i].color=2;
}

void dfsvisit1()
{
    int output=0;
    int pri=0;
    int now=0;
    for(int i=0;i<n;++i)
    {
        if(g1[s[i].i].color==0)
        {
            dfs1(s[i].i);
            now=0;
            for(int k=0;k<n;++k)
            {
                if(g1[k].color==2) ++now;
            }
            output+=(now-pri)*(now-pri-1)/2;
            pri=now;
        }
    }
    cout<<output<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<n;++i)
    {
        g[i].i=i;
        g[i].color=0;
        g1[i].i=i;
        g1[i].color=0;
    }
    for(int i=0;i<m;++i)
    {
        cin>>a>>b;
        addedge(a-1,b-1);
    }
    dfsvisit();
    sort(s.begin(),s.end());
    dfsvisit1();
    return 0;
}
