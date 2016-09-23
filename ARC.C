#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
int gd=DETECT,gm,xc,yc,a,b;
float x,y,x1,y1,theta,dtheta,ftheta=0,asp,r,PI=3.14;
initgraph(&gd,&gm,"c:\\tc\\bgi");
getaspectratio(&a,&b);
asp=(float)b/a;
printf("\n enter the centre of curvature(xc,yc:");
scanf("%d%d",&xc,&yc);
printf("\n enter the starting points:(x,y)");
scanf("%f%f",&x,&y);
printf("\n enter the arc  angle(o):");
scanf("%f",&theta);
theta*=PI/180;

putpixel(xc,yc,11);
r=sqrt((xc-x)*(xc-x)+(yc-y)*(yc-y));
dtheta=1.0/r;
x1=x;
y1=y;

while(ftheta<=theta)
{
putpixel((x1-xc)*asp+xc,y1,1);
x1+=(yc-y1)*dtheta;
y1+=(x1-xc)*dtheta;
ftheta+=dtheta;
}
line(xc,yc,(x-xc)*asp+xc,y);
line(xc,yc,(x1-xc)*asp+xc,y1);
getch();
closegraph();
}