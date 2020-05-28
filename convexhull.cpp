#include<iostream>
using namespace std;
class Point
{
	public:
		Point(int xx,int yy)
		{
			x=xx;
			y=yy;	
		};
		Point()
		{
			x=0;
			y=0;
		} 
		int x,y;
} ;
int TLT(Point s[],int n)
{
	int ltl=0;
	for(int i=1;i<n;i++)
	{
		if(s[i].x<s[ltl].x||(s[i].x==s[ltl].x&&s[i].y<s[ltl].y))
		ltl=i;
	}
	return ltl;
}
bool ToLeft(Point a,Point b,Point c)//if Point c locate on the left of line ab
{
	int area=a.x*b.y+c.x*a.y+b.x*c.y-c.x*b.y-a.x*c.y-b.x*a.y;
	if area>0// ignore degeneracy 
	return true;
	else 
	return false;
}
bool compare(Point a, Point b) 
{
	if(ToLeft())
}
int main()
{
return 0;
}
