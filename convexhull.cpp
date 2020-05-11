#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
//Point 类 
class Point
{
	public:
		Point(int x,int y)
		{
			this->x=x;
			this->y=y;	
		};
		Point()
		{
			this->x=0;
			this->y=0;
		} 
		int getX() const{
		return x;
		}
		int getY() const{
		return y;
		}
		int id;
	private: 
	
	int x,y;
} ;
//比较Point 的大小 
bool cmp_point(Point a,Point b)
{
	if(a.getX()!=b.getX())
	return a.getX()<b.getX();
	else
	return a.getY()<b.getY();
};
//判断r点在线pq右边的函数,在pq上也算 
bool isRightTurn(Point p,Point q,Point r)
{
	int area2= p.getX()*q.getY()+r.getX()*p.getY()+q.getX()*r.getY()-q.getY()*r.getX()-p.getX()*r.getY()-q.getX()*p.getY();
	if(area2<=0)
	return true;
	else
	return false;
}
int main()
{
	//Input
	int n;
	cin>>n;
	vector<Point> P(n);
	for(int i=0;i<n;i++) 
	{
		int x,y;
		cin>>x>>y;
		P[i]=Point(x,y);
		P[i].id=i+1;
	}
	
	//Sorting
	sort(P.begin(),P.end(),cmp_point);
	
	//upper hull
	vector<int> up_hull(2);
	up_hull[0]=0;
	up_hull[1]=1;

	for(int i=2;i<n;i++)
	{
		up_hull.push_back(i);
		//取uphull最后面三个点 
		while(up_hull.size()>=3&&!isRightTurn(P[up_hull[up_hull.size()-3]],P[up_hull[up_hull.size()-2]],P[up_hull[up_hull.size()-1]]))
		{
			vector<int>::iterator iter=up_hull.end();
			up_hull.erase(iter-2); //输出倒数第二个元素 	
		}
	}
	/*for(int i=0;i<up_hull.size();i++)
		cout<<P[up_hull[i]].id<<" ";
	cout<<endl;*/
	//lower hull
	
	vector<int> low_hull(2);
	low_hull[0]=n-1;
	low_hull[1]=n-2;

	for(int i=n-3;i>=0;i--)
	{
		low_hull.push_back(i);
		//取uphull最后面三个点 
		while(low_hull.size()>=3&&!isRightTurn(P[low_hull[low_hull.size()-3]],P[low_hull[low_hull.size()-2]],P[low_hull[low_hull.size()-1]]))
		{
			vector<int>::iterator iter=low_hull.end();
			low_hull.erase(iter-2); //输出倒数第二个元素 	
		}
	}
	/*for(int i=0;i<low_hull.size();i++)
			cout<<P[low_hull[i]].id<<" ";
			cout<<endl;*/
	int h=low_hull.size()+up_hull.size()-2;
	long mult1=1;
	long mult2=1;
	for(int i=0;i<up_hull.size();i++)
		mult1*=P[up_hull[i]].id;
	for(int i=1;i<low_hull.size()-1;i++)
			mult2*=P[low_hull[i]].id;
	cout<<(mult1*mult2*h)%(n+1);
	return 0;
}
