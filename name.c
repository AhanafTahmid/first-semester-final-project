#include<stdio.h>
#include<windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void main()
{
    int i,j;

    //A STARTS//
    for(i=25,j=2; i>=21,j<=6; i--,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("#");
    }
    for(i=25,j=2; i<=30,j<=6; i++,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("#");
    }
    for(i=23; i<28; i++)
    {
        Sleep(50);
        gotoxy(i,4);
        printf("#");
    }


    //H STARTS//
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(32,j);
        printf("#");
    }
    for(i=32; i<=36; i++)
    {
        Sleep(50);
        gotoxy(i,4);
        printf("#");
    }
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(37,j);
        printf("#");
    }

    //A STARTS//
    for(i=43,j=2; i>=39,j<=6; i--,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("#");
    }
    for(i=43,j=2; i<=49,j<=6; i++,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("#");
    }
    for(i=42; i<45; i++)
    {
        Sleep(50);
        gotoxy(i,4);
        printf("#");
    }


    //N STARTS//
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(51,j);
        printf("#");
    }
    for(i=52,j=2; i<=56,j<=6; i++,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("#");
    }
    for(j=6; j>=2; j--)
    {
        Sleep(50);
        gotoxy(57,j);
        printf("#");
    }


    //F STARTS//
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(60,j);
        printf("#");
    }
    for(i=60; i<=64; i++)
    {
        Sleep(50);
        gotoxy(i,0);
        printf("#");
    }
    for(i=60; i<=64; i++)
    {
        Sleep(50);
        gotoxy(i,4);
        printf("#");
    }




/*

    //M STSRTS
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(32,j);
        printf("M");
    }
    for(i=33,j=2; i<=35,j<=4; i++,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("M");
    }
    for(i=35,j=4; i>=37,j>=2; i++,j--)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("M");
    }
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(38,j);
        printf("M");
    }

    //A2 STARTS
    for(i=44,j=2; i>=40,j<=6; i--,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("A");
    }
    for(i=44,j=2; i<=49,j<=6; i++,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("A");
    }
    for(i=42; i<46; i++)
    {
        Sleep(50);
        gotoxy(i,4);
        printf("A");
    }


    //N STARTS//
    for(j=2; j<=6; j++)
    {
        Sleep(50);
        gotoxy(51,j);
        printf("|");
    }
    for(i=52,j=2; i<=56,j<=6; i++,j++)
    {
        Sleep(50);
        gotoxy(i,j);
        printf("|");
    }
    for(j=6; j>=2; j--)
    {
        Sleep(50);
        gotoxy(57,j);
        printf("|");
    }

    */

    getch();

}
