/*
 * Author: Paul Lin
 * Matilto: paul415236@gmail.com
 *
 *       ------------->                       
 *       | THETA < 0  |            #p1
 *       |     #p2    |             o
 *       |     o      |              \
 *       |    / \     |               \ <-------|
 *       <-- /   \<----                \        |
 *          /     \                     # p2    |  THETA > 0
 *         /       o                   o        |
 *        /         #p1               / -------->
 *       #p3                         /
 *                                  #p3 
 *
 * calculating the included angle from Vp3p2 to Vp2p1, angle is defined as -90deg to 90deg
 * 
*/
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define PI 3.1415926

typedef struct
{
	double x,y;
} point;

typedef struct
{
	double x,y;
} vector;

double norm(vector v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

double cross(vector v1, vector v2)
{
	return (v1.x*v2.y - v1.y*v2.x);
}

double dot(vector v1, vector v2)
{
	return (v1.x*v2.x + v1.y*v2.y);
}

double get_included_angle(vector v1, vector v2)
{
	double theta;

	double value = dot(v1, v2)/(norm(v1)*norm(v2));
	if (value < -1.0)
		value = -1.0;
	else if (value > 1.0)
		value = 1.0;

	theta = acos(value)*180/PI;

	return theta;
}

int main()
{
	point p1 = {100.0, -260.0};
	point p2 = {50.0, 10.0};
	point p3 = {30.0, -60.0};

	vector v23, v12;
	v23.x = p3.x - p2.x;
	v23.y = p3.y - p2.y;

	v12.x = p2.x - p1.x;
	v12.y = p2.y - p1.y;

	double theta;
	theta = get_included_angle(v23, v12);

	if (p1.x > p2.x) // goal is located in right side, we treat the included theta is negative <cos(-theta) = cos(theta)>
		theta *= -1.0;

	printf("theta = %.2f \n", theta);

	return 0;
}
