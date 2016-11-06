#include<graphics.h>
using namespace std;
main()
{
    int x,y;
    initwindow(640,480);
    setbkcolor(9);
    while(ismouseclick(WM_LBUTTONDOWN))
    getmouseclick(WM_LBUTTONDOWN, x, y);

    return 0;
}
