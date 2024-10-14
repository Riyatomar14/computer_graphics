# Bresenham's_circle_midpoint_algorithm

#include<graphics.h>
#include<conio.h>
#include<iostream.h>

void main()
{
int h,k,x,y,r,d;
int gd= DETECT,gm;
initgraph(&gd,&gm," ");
cout<<"enter the value of centre coodinate"<<endl;
cin>>h>>k;
cout<<"enter the value of radius"<<endl;
cin>>r;
x=0;
y=r;
d=1-r;
do
{
   putpixel(h+x,k+y,4);
   putpixel(h+x,k-y,4);
   putpixel(h-x,k+y,4);
   putpixel(h-x,k-y,4);
   putpixel(h+y,k+x,4);
   putpixel(h+y,k-x,4);
   putpixel(h-y,k+x,4);
   putpixel(h-y,k-x,4);
   if(d<0)
   {
      x=x+1;
      y=y;
      d=d+(2*x)+3;
   }
   else
   {
      x=x+1;
      y=y-1;
      d=d+2*(x-y)+5;
   }
}while(x<y);
getch();
closegraph();
}
