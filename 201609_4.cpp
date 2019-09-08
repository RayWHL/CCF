#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <queue>
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

	int pri;	//��¼���·����ǰһ����
	int pri_len;	//��¼ǰһ����

	edge *next;

	bool operator > (const node temp) const
	{
		return val > temp.val;
	}
};

node NODE[10000];
int visit[10000];
int n, m;

int max_int = 0x3f3f3f3f;

priority_queue <node, vector<node>, greater<node>> q;  //��С���ȶ��� �����ظ��Ķ���

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
	q.push(NODE[0]);
	while (!q.empty())
	{
		node num = q.top();
		q.pop();
		//�����ظ��Ķ���
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
					NODE[p->to].pri = num.i;
					NODE[p->to].pri_len = p->d;

					q.push(NODE[p->to]);
				}
				//��ͬ��·�����ȣ�������̵�
				else if (num.val + p->d == NODE[p->to].val)
				{
					if(NODE[p->to].pri_len>p->d)
                    {
                        NODE[p->to].pri = num.i;
					    NODE[p->to].pri_len = p->d;
                    }
				}
			}
		}
	}
}


int main()
{
	cin >> n >> m ;
	int a, b, c;
	//��ʼ��
	for (int i = 0; i < n; ++i) 
	{
		NODE[i].i = i;
		NODE[i].val = max_int;
		NODE[i].next = NULL;
	}
	NODE[0].val = 0; //��ʼ��
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		addedge(a-1, b-1, c);
		addedge(b-1, a-1, c);
	}

	dijistra();

	int out = 0;
	for (int i = 1; i < n; ++i)
	{
		out += NODE[i].pri_len;
	}

	cout << out << endl;
	return 0;
}
