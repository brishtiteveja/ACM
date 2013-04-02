////============================================================================
//
//// Name        : Geometry.cpp
//// Author      : Dhrubo Abdullah Khan
//// Version     :
//// Copyright   : Free to share
//// Description : Geometry Library
////============================================================================
//
///*********** The Geometry Library *****************/
//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//#define MAX_SIZE 1000
//
//const double PI = 2.0 * acos(0.0);
//const double EPS = 1e-9; 	//too small/big
//
//
//struct PT
//{
//	double x,y;
//
//	double length(){
//		return sqrt(x*x + y*y);
//	}
//
//	int normalize(){	//normalize the vector to unit length ;
//						// return -1 if the vector is 0
//		double l = length();
//		if(fabs(l) < EPS)
//			return -1;
//		x /= l;
//		y /= l;
//		return 0;
//	}
//
//	PT operator-(PT a){
//		PT r;
//		r.x = x - a.x;
//		r.y = y - a.y;
//		return r;
//	}
//
//	PT operator+(PT a){
//		PT r;
//		r.x = x + a.x;
//		r.y = y + a.y;
//		return r;
//	}
//
//	PT operator*(double sc){
//		PT r;
//		r.x = x*sc;
//		r.y = y*sc;
//		return r;
//	}
//
//	bool operator<(const PT& b){
//		if(fabs(x - b.x) < EPS)
//			return y < b.y;
//		return x < b.x;
//	}
//
//	double dist(PT& a,PT& b){
//		return sqrt((a.x - b.x) *(a.x - b.x) + (a.y - b.y)* (a.y - b.y));
//	}
//
//	double dot(PT& a, PT& b)
//	{
//		return (a.x*b.x + a.y * b.y);
//	}
//
//	//=============================================================
//	//The Convex Hull
//	//=============================================================
//
//	int sideSign(PT& p1,PT& p2,PT& p3)
//	//which side is p3 to the line p1->p2? returns:1 left, 0 on, -1 right
//	{
//		double sg = (p1.x - p3.x) * (p2.y-p3.y) - (p1.y-p3.y)*(p2.x-p3.x);
//		if(fabs(sg) < EPS)
//			return 0;
//		if(sg > 0)
//			return 1;
//		return -1;
//	}
//
//	bool better(PT& p1,PT& p2,PT& p3)
//	//used by convex hull: from p3, if p1 is better than p2
//	{
//		double sg = (p1.y - p3.y) *(p2.x - p3.x) - (p1.x - p3.x) *(p2.y - p3.y);
//		//watch range of the numbers
//		if(fabs(sg) < EPS)		//p3 is over the line connecting p1 and p2
//		{
//			if(dist(p3,p1) > dist(p3,p2)){
//				return true;
//			}else{
//				return false;
//			}
//		}
//		if(sg < 0)				// p3 is in the left side of theline
//			return true;
//		return false;			// p3 is in the right side of the line.
//	}
//
//	//convex hull in n*n
//	void vex(vector<PT>& vin, vector<PT>& vout){
//		vout.clear();
//		int n = vin.size();
//		int st = 0;
//		int i ;
//		for(i = 1;i < n;i++)
//			if(vin[i]< vin[st])
//				st = i;
//		vector<int> used;
//		//used[i]  is the index of the i-th point on the hull
//		used.push_back(st);
//
//		int idx = st;
//		int next;
//		do{
//			next = 0;
//			for(i = 1; i < n; i++){
//				if(better(vin[i],vin[next],vin[idx]))
//					next = i;
//			}
//			idx = next;
//			used.push_back(idx);
//		}while(idx != st);
//
//		for(i = 0; i <= used.size();i++)
//			vout.push_back(vin[used[i]]);
//	}
//
////convex hull in n*log(n)
//	void vex(vector<PT> vin,vector<PT>&vout){
//		//vin is not pass by reference,since we will rotate it
//		vout.clear();
//		int n = vin.size();
//		sort(vin.begin(),vin.end());
//		PT stk[MAX_SIZE];
//		int pstk,i;
//		//hopefully more than 2 points
//		stk[0] = vin[0];
//		stk[1] = vin[1];
//		pstk = 2;
//		for(i = 2; i < n;i++){
//			if(dist(vin[i],vin[i-1]) < EPS)
//				continue;
//			while(pstk > 1 && better(vin[i],stk[pstk-1],stk[pstk-2]))
//				pstk--;
//			stk[pstk] = vin[i];
//			pstk++;
//		}
//
//		//turn 180 degree
//		for(i = 0 ; i < n ; i++)
//		{
//			vin[i].y = -vin[i].y;
//			vin[i].x = -vin[i].x;
//		}
//
//		sort(vin.begin(),vin.end());
//		stk[0] = vin[0];
//		stk[1] = vin[1];
//		pstk = 2;
//		for(i = 2 ;i < n ; i++){
//			if(dist(vin[i],vin[i-1]) < EPS)
//				continue;
//			while(pstk > 1 && better(vin[i],stk[pstk - 1],stk[pstk-2]))
//				pstk--;
//			stk[pstk] = vin[i];
//			pstk++;
//		}
//
//		for(i = 1; i < pstk - 1 ; i++){
//			stk[i].x = -stk[i].x ; // don't forget rotate 180d back
//			stk[i].y = -stk[i].y;
//			vout.push_back(stk[i]);
//		}
//	}
//
//
//
//int isConvex(vector<PT>& v){
//	//test whether a simple polygon is convex
//	//return 0 if not convex, 1 if strictly convex
//	//2 if convex but htere are points unnecessary
//	//this function does not work if the polygon is self intersecting
//	//in that case, compute the convex hull of v,and see if both have the same area
//	int i,j,k;
//	int c1 = 0;
//	int c2 = 0;
//	int c0 = 0;
//	int n = v.size();
//
//	for(i = 0 ; i < n; i++){
//		j = (i+1) % n;
//		k = (j+1) % n;
//		int s = sideSign(v[i],v[j],v[k]);
//		if(s==0)
//			c0++;
//		if(s>0)
//			c1++;
//		if(s<0)
//			c2++;
//	}
//	if(c1 && c2)
//		return 0;
//	if(c0)
//		return 2;
//	return 1;
//}
//
//
////===============================================================
////Areas
////===============================================================
//
//double trap(PT a,PT b)
//{
//	return (0.5*(b.x - a.x) * (b.y - a.y));
//}
//
//double area(vector<PT>& vin)
////Area of a simple polygon,not necessary convex
//{
//	int n = vin.size();
//	double ret = 0.0;
//	for(int i = 0; i < n; i++)
//		ret += trap(vin[i],vin[(i+1)%n]);
//
//	return fabs(ret);
//}
//
//double peri(vector<PT>& vin)
////Perimeter of a simple polygon, not necessary convex
//{
//	int n = vin.size();
//	double ret = 0.0;
//	for(int i = 0 ; i < n; i++)
//		ret += dist(vin[i],vin[(i+1)%n]);
//}
//
//double triarea(PT a,PT b,PT c){
//	return fabs(trap(a,b) + trap(b,c)+trap(c,a));
//}
//
//double height(PT  a,PT b, PT c)
////height from a to the line bc
//{
//	double s3 = dist(c,b);
//	double ar = triarea(a,b,c);
//	return (2.0*ar/s3);
//}
//
//
////==================================
//// Points and Lines
////==================================
//
//int intersection(PT p1,PT p2,PT p3,PT p4,PT& r)
////two lines given by p1->p2,p3->p4 is the intersection point
////return -1 if two lines two lines are parallel
//{
//	double d = (p4.y - p3.y)*(p2.x - p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
//
//	if(fabs(d) < EPS)  //might need to do something special!!!!
//		return -1;
//	double ua,ub;
//	ua = (p4.x - p3.x)*(p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x);
//	ua /= d;
//	// ub = (p2.x - p1.x)*(p1.y - p3.y)  (p2.y - p1.y)*(p1.x-p3.x)
//	//ub /= d;
//	r = p1 + (p2-p1)*ua;
//	return 0;
//}
//
//void closestpt(PT p1,PT p2,PT p3, PT &r)
////the closest point on the line p1->p2 to p3
//{
//	if(fabs(triarea(p1,p2,p3)) < EPS){
//		r = p3;
//		return;
//	}
//	PT v = p2 - p1;
//	v.normalize();
//	double pr; // inner product
//	pr = (p3.y-p1.y)* v.y + (p3.x - p1.x)*v.x;
//	return 0;
//}
//
//int hcenter(PT p1,PT p2,PT p3,PT& r)
//{
//	//point generated by altitudes
//	if(triarea(p1,p2,p3)< EPS)
//		return -1;
//	PT a1,a2;
//	closestpt(p2,p3,p1,a1);
//	closestpt(p1,p3,p2,a2);
//	intersection(p1,a1,p2,a2,r);
//	return 0;
//}
//
//int center(PT p1,PT p2,PT p3,PT& r)
//{
//	//point generated by circumscribed circle
//	if(triarea(p1,p2,p3) < EPS)
//		return -1;
//	PT a1,a2,b1,b2;
//	a1 = (p2 + p3) * 0.5;
//	a2 = (p1 + p3) * 0.5;
//	b1.x = a1.x - (p3.y - p2.y);
//	b1.y = a1.y + (p3.x - p2.x);
//	b2.x = a2.x - (p3.y - p1.y);
//	b2.y = a2.y + (p3.x - p1.x);
//	intersection(a1,b1,a2,b2,r);
//
//	return 0;
//}
//
////=====================================
////Angles
////=====================================
//double angle(PT& p1,PT& p2,PT& p3)
////angle from p1->p2 to p1->p3 returns -PI to PI
//{
//	PT va = p2-p1;
//	va.normalize();
//	PT vb;
//	vb.x = -va.y;
//	vb.y = va.x;
//	PT v = p3 - p1;
//	double x,y;
//	x = dot(v,va);
//	y = dot(v,vb);
//
//	return (atan2(y,x));
//}
//
//double angle(double a, double b, double c)
////in a triangle with sides a,b,c, the angle between b and c
////we do not check if a,b,c is a triangle here
//{
//	double cs = (b*b + c*c - a*a)/ (2.0 * b*c);
//	return (acos(cs));
//}
//
//double rotate(PT p0,PT p1, double a, PT& r)
////rotate p1 around p0 clockwise, by angle a
////don't pass by reference for p1, so r and p1 can be the same
//{
//	p1 = p1 - p0;
//	r.x = cos(a)* p1.x - sin(a)* p1.y;
//	r.y = sin(a)* p1.x - cos(a)* p1.y;
//
//	r = r + p0;
//}
//
//void reflect(PT& p1, PT& p2,PT p3, PT& r){
////p1->p2 line, reflect p3 to get r.
//	if(dist(p1,p3)< EPS){
//		r = p3;
//		return;
//	}
//	double a = angle(p1,p2,p3);
//	r = p3;
//	rotate(p1,r,-2.0*a,r);
//}
//
//
//
//
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
int main(){
	return 0;
}
