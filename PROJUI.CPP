#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;
union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}
void draw_card(int topx,int topy,char *sip)
{
  char f[1];
  f[0]=sip[0];
  setfillstyle(SOLID_FILL,WHITE);
  bar(topx,topy,topx+140,topy+165);

  for(int i=0;i<=140;++i)           //loop to make a line
  {
     putpixel(topx+i,topy+120,8);
  }
  setcolor(BLACK);

  settextstyle(6,0,2);
  outtextxy(topx+3,topy+122,sip);    //main content display
  settextstyle(6,0,8);
  outtextxy(topx+50,topy+2,f);       // first letter display
}
void open_sidebar()
{
  setbkcolor(7);
  setfillstyle(SOLID_FILL,8); //the big side bar
	bar(0,40,160,479);
  setfillstyle(SOLID_FILL,9); //tittle bar
	bar(40,0,160,40);

}
int MOUSE_STATUS_FLAG;
void homescreen()
{
 MOUSE_STATUS_FLAG=0;
 int x,y,button;
 setfillstyle(SOLID_FILL,9); //tittle bar
      bar(0,0,640,40);
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,7);// the small barszzz of hamburger menu
	 line(6,14,35,14);
	 line(6,20,35,20);
	 line(6,26,35,26);
 setbkcolor(3);     //background color
     draw_card(95,100,"gh");
     draw_card(95,280,"gtre");
     draw_card(250,100,"uygt");	//cards dimensions
     draw_card(405,100,"hfht");        //width =140
     draw_card(250,280,"jkhk");        //height = 165
     draw_card(405,280,"lpop");
		   //initmouse();
		   showmouseptr();
		   getmousepos(&button,&x,&y);
		    while(!kbhit())
		    {
		       delay(120);
		       getmousepos(&button,&x,&y);
			if( button == 1 )
			{
			  button = -1;
			  if(x>95&&x<235&&y>100&&y<265)
			  {
			    cleardevice();
			    cout<<"1";
			  }
			  else if(x>95&&x<235&&y>280&&y<445)
			  {
			    cleardevice();
			    cout<<"2";
			  }
			  else if(x>250&&x<390&&y>100&&y<265)
			  {
			    cleardevice();
			    cout<<"3";
			  }
			  else if(x>405&&x<545&&y>100&&y<265)
			  {
			    cleardevice();
			    cout<<"4";
			  }
			  else if(x>250&&x<390&&y>280&&y<445)
			  {
			    cleardevice();
			    cout<<"5";
			  }
			  else if(x>405&&x<545&&y>280&&y<445)
			  {
			    cleardevice();
			    cout<<"6";

			  }
			 if(x>=0&&x<=40&&y>=0&&y<=40&&MOUSE_STATUS_FLAG==0)
			 {
				open_sidebar();
				MOUSE_STATUS_FLAG=1;

			 }
			 else if(x>=0&&x<=40&&y>=0&&y<=40&&MOUSE_STATUS_FLAG==1)
			 {
				cleardevice();
				homescreen(); //show the homscreen
				MOUSE_STATUS_FLAG=0;

			 }

			}
		    }

}
/*------------------------------LOGIN PAGE---------------------------------*/
void login_page()
{
  int x_set=255;
  char *o;
  char u[10],c,t[1],pw[10];
  int pos=0,i;
  setbkcolor(WHITE);
  setfillstyle(SOLID_FILL,9); // upper bar
  bar(0,0,640,115);
  setcolor(15);
  settextstyle(6,0,5);
  outtextxy(137,20,"FOOTBALL SIMULATOR");
  setcolor(8);
  settextstyle(6,0,2);
  outtextxy(x_set,165,"Username");
  setcolor(CYAN);
  line(x_set-50,220,x_set+135,220);//username line
  line(x_set-50,293,x_set+135,293);//pw line
  setcolor(8);
  outtextxy(x_set,239,"Password");
  for(i=0;i<10;++i)
  {
    c=getch(); //input without ecoing
    u[i]=c;    //store the username
    t[0]=c;t[1]='\0';
    setcolor(8);
    settextstyle(6,0,2);
    outtextxy(x_set-17+pos,190,t);
    pos=pos+12;
  }
  up:
  if(getch()==13)
  {
   pos=0;
   for(i=0;i<10;++i)
    {
      c=getch(); //input without ecoing
      pw[i]=c;    //store the password
      t[0]=c;t[1]='\0';
      setcolor(8);
      settextstyle(6,0,2);
      outtextxy(x_set-17+pos,269,"*");
      pos=pos+12;
    }
    up_again:
    if(getch()==13)
    goto fwd;
    else
    goto up_again;
  }
  else
  {
    goto up;
  }
  fwd:
 for(i=0;i<300;++i)        //login animation
 {
   setcolor(15);
   setbkcolor(7);
   arc(320,240,0,i,70);
   arc(320,240,0,i,69);
   arc(320,240,0,i,68);
   arc(320,240,0,i,67);
   arc(320,240,0,i,66);
   outtextxy(240,330,"Logging in...");
   delay(1);
 }
 cleardevice();
 for(i=300;i<=360;++i)
 {
   arc(320,240,0,i,70);
   arc(320,240,0,i,69);
   arc(320,240,0,i,68);
   arc(320,240,0,i,67);
   arc(320,240,0,i,66);

   outtextxy(240,330,"Successfully loged in");
   delay(1);
 }


   cleardevice();
   homescreen();

}

/*--------------------------------MAIN-------------------------------------*/
int main()
{
   int gd = DETECT, gm, status, button, x, y;
   char array[50];

   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   settextstyle(DEFAULT_FONT,0,2);
      initmouse();
      login_page();
      //homescreen();


   getch();
   cleardevice();
   return 0;
}

