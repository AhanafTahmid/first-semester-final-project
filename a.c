int select_mode()
{
    setup();

    setColor(238);

    gotoxy(15, 14);
    printf(">  Single Player");

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
