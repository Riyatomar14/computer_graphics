Bresenham's line drawing algorithm 

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

int main()
{
    int gd= DETECT,gm;
    initgraph(&gd,&gm," ");
    int x1,y1,x2,y2,dx,dy,p;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cout<<"the value of x1 and y1"<<x1<<y1<<endl;
    cout<<"the value of x2 and y2"<<x2<<y2<<endl;
    dx = x2 - x1;
    dy = y2 - y1;
    p = (2*dy) - dx;
    putpixel(x1,y2,10);
    while(x1<=x2)
    {
	      if(p < 0)
	      {
	         x1++;
	         p = p + (2*dy);
      	}
	      else
	      {
	         x1++;
	         y1++;
	         p =p + (2*dy) - (2*dx);
	      }
	      putpixel(x1,y1,10);
	      delay(10);
    }
    getch();
    closegraph();
    return 0;
}
