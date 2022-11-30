#include <windows.h>
#include<stdio.h>

void setColor(int ForgC){


    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int select_mode()
{
    setup();

    setColor(238);

    gotoxy(15, 14);
    printf(">  Log in(As a Shopper)");

    setColor(239);

    gotoxy(15, 17);
    printf("   Multi Player");

    gotoxy(15, 20);
    printf("   About Us");

    gotoxy(15, 23);
    printf("   Exit");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(15, 14);
            printf("   Single Player");

            setColor(238);

            gotoxy(15, 17);
            printf(">  Multi Player");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   Multi Player");

            setColor(238);

            gotoxy(15, 20);
            printf(">  About Us");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(239);

            gotoxy(15, 20);
            printf("   About Us");

            setColor(238);

            gotoxy(15, 23);
            printf(">  Exit");

            pos++;
        }

        else if(ch == 72 && pos == 3)
        {
            setColor(238);

            gotoxy(15, 20);
            printf(">  About Us");

            setColor(239);

            gotoxy(15, 23);
            printf("   Exit");

            pos--;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(15, 17);
            printf(">  Multi Player");

            setColor(239);

            gotoxy(15, 20);
            printf("   About Us");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  Single Player");

            setColor(239);

            gotoxy(15, 17);
            printf("   Multi Player");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}


int main(){



    setColor(238);

    gotoxy(10, 4);
    printf(">Log in(As a Shopper) :");

    gotoxy(10, 7);
    printf(">Log in(As a Customer):");
    setColor(269);


    gotoxy(10, 14);
    printf("> Sign Up(As a Shopper) :");

    gotoxy(10, 17);
    printf("> Sign Up(As a Customer) :");
    setColor(269);



    //gotoxy(15, 20);
    //printf("   Password  :");

    gotoxy(7, 20);
    printf("   Home Page");
    getch();
    return;
}
