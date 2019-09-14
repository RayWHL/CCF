#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct  edge
{
	int d;
	int to;

	edge *next;
};

struct node
{
	int i;
	int val;
    int type;

	edge *next;

	bool operator > (const node temp) const
	{
		return val > temp.val;
	}
};

node NODE[10000];
int visit[10000];
int n, m,k;
vector<int> out;

int d[10000][10000];
int max_int = 0x3f3f3f3f;

priority_queue <node, vector<node>, greater<node> > q;  //最小优先队列 存在重复的顶点

void addedge(int a, int b, int c)
{
	edge *temp = new edge;
	temp->to = b;
	temp->d = c;
	temp->next = NODE[a].next;
	NODE[a].next = temp;
}


void dijistra()
{
	while (!q.empty())
	{
		node num = q.top();
		q.pop();
		//消除重复的顶点
		if (visit[num.i] == 1)
			continue;
		visit[num.i] = 1;
		for (edge *p = num.next; p; p = p->next)
		{
			if (visit[p->to] == 0)
			{
				if (num.val + p->d < NODE[p->to].val)
				{
					NODE[p->to].val = num.val + p->d;

					q.push(NODE[p->to]);
				}

			}
		}
	}
}


void deal()
{

    for(int i=0;i<n;++i)
    {//初始化
        if(NODE[i].type==0) continue;
        for (int j = 0; j < n; ++j)
        {
            NODE[j].val = max_int;
            visit[j]=0;
        }
        NODE[i].val=0;
        q.push(NODE[i]);
        dijistra();
        for(int j=0;j<n;++j)
        {
            if(NODE[j].val<max_int)
            {
                d[i][j]=NODE[j].val;
                d[j][i]=NODE[j].val;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin >> n >> m >>k;
	int a, b, c;
	//初始化
	for (int i = 0; i < n; ++i)
	{
	    cin>>NODE[i].type;
		NODE[i].i = i;
		NODE[i].val = max_int;
		NODE[i].next = NULL;
	}
	for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            d[i][j]=max_int;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		addedge(a-1, b-1, c);
		addedge(b-1, a-1, c);
	}

	deal();
    for(int i=0;i<n;++i)
    {
        long long int output=0;
        out.clear();
        for(int j=0;j<n;++j)
        {
            if(NODE[j].type==1 && d[i][j]<max_int)
                out.push_back(d[i][j]);
        }
        sort(out.begin(),out.end());
        for(int j=0;j<out.size() && j<k;++j)
            output+=out[j];
        cout<<output<<endl;
    }

	return 0;
}
