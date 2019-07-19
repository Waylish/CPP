#include<bits/stdc++.h>
using namespace std;
struct ss{
	int v;
	long long wei;
	int next;
};
ss s1[10100001];
bool visited[10100011];
int head[10101000],cnt;
long long s3[10001010];
priority_queue< pair<long long ,long long > >q;
int m,n,a,b,c;
void abb(int x,int y,int z)
{
	cnt++;
	s1[cnt].v=y;
	s1[cnt].wei=z;
	s1[cnt].next=head[x];
	head[x]=cnt;
}
int main()
{
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		abb(a,b,c);
		abb(b,a,c);
	}
	for(int i=1;i<=n;i++)
	{
		s3[i]=0x3f3f3f3f3f3f3f3f;
	}
	s3[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		long long x=q.top().second;
		q.pop();
		if(visited[x])
		{
			continue;
		}
		visited[x]=true;
		for(int j=head[x];j!=-1;j=s1[j].next)
		{
			if(s3[s1[j].v]>s3[x]+s1[j].wei)
			{
				s3[s1[j].v]=min(s3[s1[j].v],s3[x]+s1[j].wei);
				q.push(make_pair(-s3[s1[j].v],s1[j].v));
			}
		}
			
	}
	cout<<s3[n];
	return 0;
}
