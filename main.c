#include <windows.h>
#include<stdio.h>
#include<string.h>
void setColor(int ForgC)
{


    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

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



//////////////////////////////////////////
//////////////////////////////////////////
//
char name[100], user_name[100], pass[100],shop_name[100];
struct user
{
    char name[100], user_name[100], pass[100],shop_name[100];

} s[700],c[700];

struct product
{
    char p_name[100];
    int id,price;

}p[700];
int number_of_shoppers=0,number_of_customers=0,number_of_products=0;

void setup()
{
    system("cls");
    gotoxy(67, 31);

    setColor(156);
    printf("By Spartans");
}




int home_page()
{
    setup();

    setColor(238);

    gotoxy(15, 14);
    printf(">  Login");

    setColor(239);

    gotoxy(15, 17);
    printf("   Sign Up");

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
            printf("   Login");

            setColor(238);

            gotoxy(15, 17);
            printf(">  Sign Up");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   Sign Up");

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
            printf(">  Sign Up");

            setColor(239);

            gotoxy(15, 20);
            printf("   About Us");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  Login");

            setColor(239);

            gotoxy(15, 17);
            printf("   Sign Up");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}

///Shopperrrrrrrrrrrrrrrrrrrrrrrrrrr

//Shopper Read Data
void s_readdata()
{
    int  i;
    FILE *file =fopen("shopper.txt","r");
    if(file == NULL) file=fopen("shopper.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_shoppers);
    for(i=0;i<number_of_shoppers;i++){
        fscanf(file," %[^\n]",s[i].shop_name);
        fscanf(file," %[^\n]",s[i].name);
        fscanf(file,"%s",s[i].user_name);
        fscanf(file," %s",s[i].pass);
    }
    fclose(file);

}

//Shop show
void show()
{
	int i;
	s_readdata();

	for(i = 0; i < number_of_shoppers; i++) {
		//printf("%s\n%s\n%s\n%s\n ", s[i].shop_name, s[i].name, s[i].user_name,s[i].pass);

            setColor(219);

            gotoxy(76, 27);
            printf("%s",s[i].shop_name);

            gotoxy(76, 29);
            printf("%s",s[i].name);

            gotoxy(76, 33);
            printf("%s",s[i].user_name);

            gotoxy(76, 35);
            printf("%s",s[i].pass);
    }

}

//SIGNUP:   Shopper unique ID check
int s_uniqueID()
{

    int i;
    s_readdata();
    ///show();
    for(i = 0; i < number_of_shoppers; i++)
        if(!strcmp(user_name, s[i].user_name))
            return 1;
    return 0;
}




//LOGIN :      Shopper UserName check while login
int shopper_user_check()
{
    int i;
    s_readdata();
    for(i = 0; i < number_of_shoppers; i++)
        if(strcmp(name, s[i].user_name))
        {
            if(strcmp(pass, s[i].pass))    return 0;
            return 1;
        }

    return 1;
}



//LOGIN : ENTER IN THE PROFILE SCREEN of shopper
int s_profile(){

    setup();

    setColor(251);

    gotoxy(17, 8);
    printf("Welcome 77777777777777777777777777777777");
}


//Read products
int read_products()
{
    int  i;
    FILE *file =fopen("products.txt","r");
    if(file == NULL) file=fopen("products.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_products);
    for(i=0;i<number_of_products;i++){
        fscanf(file," %[^\n]",p[i].p_name);
        fscanf(file," %d",&p[i].price);
    }
    fclose(file);

}

// Add pricing
int add_pricing(){


}

int add_products()
{
    printf("n");
}









//######################################################################################################//######################################################################################################
//######################################################################################################
//######################################################################################################
//######################################################################################################
///Customerrrrrrrrrrrrrrrrrrrrrrrrrr
//######################################################################################################

//Customer Read Data
void c_readdata()
{
    int  i;
    FILE *file =fopen("customer.txt","r");
    if(file == NULL) file=fopen("customer.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_customers);
    for(i=0;i<number_of_customers;i++){
        fscanf(file," %[^\n]",c[i].name);
        fscanf(file,"%s",c[i].user_name);
        fscanf(file," %s",c[i].pass);
    }
    fclose(file);

}


//SIGNUP:  Customer unique ID check
int c_uniqueID()
{
    int i;
    c_readdata();
    ///show();
    for(i = 0; i < number_of_customers; i++)
        if(!strcmp(user_name, c[i].user_name))
            return 1;
    return 0;
}


//LOGIN :      Customer UserName check while login
int customer_user_check(){

    int i;
    c_readdata();
    for(i = 0; i < number_of_customers; i++)
        if(strcmp(name, c[i].user_name))
        {
            if(strcmp(pass, c[i].pass))    return 1;
            //return -1;
        }

    return 0;


}













int login(int a)
{
    int m=0;
    setup();
    if(a)
    {
        setColor(236);

        gotoxy(65, 8);
        printf("Invalid User Name");

        gotoxy(65, 10);
        printf("  or Password");
    }
    setColor(238);

    gotoxy(15, 14);
    printf(">  Login As a Shopper");

    setColor(239);

    gotoxy(15, 17);
    printf("   Login As a Customer");

    gotoxy(15, 20);
    printf("   Home Page");

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
            printf("   Login As a Shopper");

            setColor(238);

            gotoxy(15, 17);
            printf(">  Login As a Customer");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   Login As a Customer");

            setColor(238);

            gotoxy(15, 20);
            printf(">  Home Page");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(15, 17);
            printf(">  Login As a Customer");

            setColor(239);

            gotoxy(15, 20);
            printf("   Home Page");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  Login As a Shopper");

            setColor(239);

            gotoxy(15, 17);
            printf("   Login As a Customer");

            pos--;
        }
        else if(ch == 32 && !pos)
        {
            setColor(238);

            gotoxy(65, 14);
            printf("Shop Name:");

            gotoxy(65, 17);
            printf("Username:");

            gotoxy(65, 20);
            printf("Password:");

            setColor(219);

            gotoxy(76, 14);
            scanf("%[^\n]",shop_name);

            gotoxy(76, 17);
            scanf("%s",user_name);

            gotoxy(76, 20);
            scanf("%s",pass);
            if(shopper_user_check()) return login(1);
             else return m=1;
        }
        else if(ch == 32 && pos==1)
        {
            setColor(238);

            gotoxy(65, 14);
            printf("Username:");

            gotoxy(65, 17);
            printf("Password:");

            setColor(219);

            gotoxy(76, 14);
            scanf("%s",user_name);

            gotoxy(76, 17);
            scanf("%s",pass);
            if(customer_user_check()) return login(1);
            else return m=1;
        }
        else if(ch == 32)   return pos;

    }
}

int sign_up(int a)
{
    setup();

    if(a)
    {
        setColor(236);

        gotoxy(65, 8);
        printf("This User Name");

        gotoxy(65, 10);
        printf("isn't available");
    }


    setColor(238);

    gotoxy(15, 14);
    printf(">  SignUp As a Shopper");

    setColor(239);

    gotoxy(15, 17);
    printf("   SignUp As a Customer");

    gotoxy(15, 20);
    printf("   Home Page");

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
            printf("   SignUp As a Shopper");

            setColor(238);

            gotoxy(15, 17);
            printf(">  SignUp As a Customer");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   SignUp As a Customer");

            setColor(238);

            gotoxy(15, 20);
            printf(">  Home Page");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(15, 17);
            printf(">  SignUp As a Customer");

            setColor(239);

            gotoxy(15, 20);
            printf("   Home Page");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  SignUp As a Shopper");

            setColor(239);

            gotoxy(15, 17);
            printf("   SignUp As a Customer");

            pos--;
        }
        else if(ch == 32 && !pos)
        {
            setColor(238);

            gotoxy(65, 14);
            printf("Shop Name:");

            gotoxy(65, 17);
            printf("Name     :");

            gotoxy(65, 20);
            printf("Username :");

            gotoxy(65, 23);
            printf("Password :");

            setColor(219);

            gotoxy(76, 14);
            scanf("%[^\n]",shop_name);

            gotoxy(76, 17);
            scanf("%s",name);

            gotoxy(76, 20);
            scanf("%s",user_name);

            gotoxy(76, 23);
            scanf("%s",pass);
            if(s_uniqueID()) return sign_up(1);
        }
        else if(ch == 32 && pos==1)
        {
            setColor(238);


            gotoxy(65, 14);
            printf("Name     :");

            gotoxy(65, 17);
            printf("Username :");

            gotoxy(65, 20);
            printf("Password :");

            setColor(219);

            gotoxy(76, 14);
            scanf("%s",name);

            gotoxy(76, 17);
            scanf("%s",user_name);

            gotoxy(76, 20);
            scanf("%s",pass);
            if(c_uniqueID()) return sign_up(1);

        }
        else if(ch == 32)   return pos;
      /// if(s_uniqueID()) return sign_up(1);

        //s_readdata();
        //show();


    }


    ///return sign_up(1);

    return 1;
}





int main()
{
    int f, f1, f2, f3, f4, f5, f6, f7, i, j;

    while(1)
    {
        f = home_page();

        if(!f)
        {
            f1 = login(0);
            if(f1==1)
            {
                while(1)
                {
                    f2=s_profile();
                }
            }

        }
        else if(f==1)
        {
            f2=sign_up(0);
            if(f2==1)
            {

            }
        }
        else
        {
            system("cls");
            return 0;
        }
    }
}

