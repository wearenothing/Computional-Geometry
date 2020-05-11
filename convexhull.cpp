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
	}
	
	//Sorting
	sort(P.begin(),P.end(),cmp_point);
	
	//upper hull
	vector<Point> upper_hull(2);
	upper_hull[0]=P[0];
	upper_hull[1]=P[1];
	for(int i=2;i<n;i++)
	{
		upper_hull.push_back(P[i]);
		while(upper_hull.size()>=3&&!isRightTurn(upper_hull[i-2],upper_hull[i-1],upper_hull[i]))
		{
			vector<Point>::iterator iter=upper_hull.end();
			iter--;
		 	upper_hull.erase(iter);
		}
		
	}
	
	//lower hull
	
	return 0;
}
