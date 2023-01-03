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

} p[700];

int number_of_shoppers=0,number_of_customers=0,number_of_products=0,s_avatar,c_avatar;

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
    for(i=0; i<number_of_shoppers; i++)
    {
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

    for(i = 0; i < number_of_shoppers; i++)
    {
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
//    int i;
//    s_readdata();
//    for(i = 0; i < number_of_shoppers; i++)
//        if(!strcmp(name, s[i].user_name))
//        {
//            if(!strcmp(pass, s[i].pass))    return 1;
//            return 0;
//        }
//
//    return 0;

    int i;
    s_readdata();
    for(i = 0; i < number_of_shoppers; i++)
    {
        if(!strcmp(user_name, s[i].user_name))
        {
            if(!strcmp(pass, s[i].pass))    return i;
            return -1;
        }
    }
    return -1;

}



//LOGIN : ENTER IN THE PROFILE SCREEN of shopper

int s_profile(){
    setup();

    setColor(251);

    gotoxy(17, 13);
    printf("Welcome Back");

    gotoxy(17, 16);
    printf("%s!", s[s_avatar].shop_name);

    gotoxy(17, 19);
    printf("%s", s[s_avatar].name);    setColor(238);



    gotoxy(65, 14);
    printf(">  Add Product");


    setColor(239);

    gotoxy(65, 17);
    printf("   Update Pricing");

    gotoxy(65, 20);
    printf("   Delete  Product");

    gotoxy(65, 23);
    printf("   Log Out");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(65, 14);
            printf("   Add Product");

            setColor(238);

            gotoxy(65, 17);
            printf(">  Update Pricing");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(65, 17);
            printf("   Update Pricing");

            setColor(238);

            gotoxy(65, 20);
            printf(">  Delete  Product");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(239);

            gotoxy(65, 20);
            printf("   Delete  Product");

            setColor(238);

            gotoxy(65, 23);
            printf(">  Log Out");

            pos++;
        }

        else if(ch == 72 && pos == 3)
        {
            setColor(238);

            gotoxy(65, 20);
            printf(">  Delete  Product");

            setColor(239);

            gotoxy(65, 23);
            printf("   Log Out");

            pos--;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(65, 17);
            printf(">  Update Pricing");

            setColor(239);

            gotoxy(65, 20);
            printf("   Delete  Product");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(65, 14);
            printf(">  Add Product");

            setColor(239);

            gotoxy(65, 17);
            printf("   Update Pricing");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}



//Read products
void read_products()
{
    int  i;
    FILE *file =fopen("products.txt","r");
    if(file == NULL) file=fopen("products.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_products);
    for(i=1; i<=number_of_products; i++)
    {
        fscanf(file," %[^\n]",p[i].p_name);
        fscanf(file," %d",&p[i].price);
    }
    fclose(file);

}

//Write Data
void s_writeData()//product
{
	int i;
	FILE *fp;
	fp = fopen("products.txt", "w");
	fprintf(fp, "%d\n", number_of_products);
	for(i = 1; i <=number_of_products; i++) {
		fprintf(fp, "%s\n%d\n", p[i].p_name, p[i].price);
	}
	fclose(fp);
}


//Add Products from shopper ---------------------------------------------------------------------------------------------------------------->
int add_products()
{
    int i,m,j,pr,c;
    char na[100];

    system("cls");
    setColor(238);
    gotoxy(31,11);
    printf("how many product input: ");
    scanf("%d",&m);
    for(j=0,c=14;j<m;j++,c+=6){
        gotoxy(31,c);
        printf("input prouduct name: ");

        scanf(" %[^\n]",na);
        gotoxy(31,c+3);
        printf("input product price: ");
        scanf("%d",&pr);
        read_products();
        number_of_products++;
        strcpy(p[number_of_products].p_name,na);
        p[number_of_products].price=pr;
        s_writeData();
    }
}

//Find product name while updating pricing
int findbyname(char name[]){
    int pos = -1, i;
	read_products();
	for(i = 1; i <= number_of_products; i++) {
		if(strcmp(p[i].p_name, name) == 0) {
			pos = i;
		}
	}
	return pos;

}

//Update Product Price
int update_pricing()
{
    char name[100];
    int price,m,c;

    system("cls");
    setColor(238);
    gotoxy(31,11);
    printf("How many products you want to update: ");
    scanf("%d",&m);

    for(int j=1,c=14;j<=m;j++,c+=6){
        gotoxy(31,c);
        printf("Enter Your Product Name: ");
        scanf(" %[^\n]",name);
        gotoxy(31,c+3);
        printf("Enter Your Product Price: ");
        scanf("%d",&price);
        int pos = findbyname(name);

        if(pos!= -1){
           p[pos].price = price;
        }
        s_writeData();
    }

}


void ss_writeData()//shopper
{
   int i;
	FILE *fp;
	fp = fopen("shopper.txt", "w");
	fprintf(fp, "%d\n", number_of_shoppers);
	for(i = 0; i <number_of_shoppers; i++) {
		fprintf(fp, "%s\n%s\n%s\n%s\n", s[i].shop_name,s[i].name,s[i].user_name,s[i].pass);
	}
	fclose(fp);
}
// Delete Product from the price
int delete_product()
{
   	char name[100];
   	int price,i;
   	printf("Enter your product name: ");
   	scanf(" %[^\n]", name);
    int pos= findbyname(name);
    if(pos != -1)
    {
        number_of_products--;
        for(i = pos; i <=number_of_products; i++)
        {
            p[i]=p[i+1];
        }
    }
    else printf("ID not found\n");

    s_writeData();//Delete Product
}

//saving shopper after signup
void  s_saveInfo()
{
    int i;
    strcpy(s[number_of_shoppers].shop_name,shop_name);
    strcpy(s[number_of_shoppers].name,name);
    strcpy(s[number_of_shoppers].user_name,user_name);
    strcpy(s[number_of_shoppers].pass,pass);
    number_of_shoppers++;
    ss_writeData();
    setColor(219);
    gotoxy(65,8);
    printf("Successfully Created %s Account",user_name);
    sleep(2);
}



//######################################################################################################
//######################################################################################################
//######################################################################################################
//######################################################################################################
///Customerrrrrrrrrrrrrrrrrrrrrrrrrr
//######################################################################################################
//######################################################################################################
//######################################################################################################
//######################################################################################################


//Customer Read Data
void c_readdata()
{
    int  i;
    FILE *file =fopen("customer.txt","r");
    if(file == NULL) file=fopen("customer.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_customers);
    for(i=0; i<number_of_customers; i++)
    {
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
int customer_user_check()
{

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



//Customer writeData
void cc_writeData()
{
    int i;
	FILE *fp;
	fp = fopen("customer.txt", "w");
	fprintf(fp, "%d\n", number_of_customers);
	for(i = 0; i <number_of_customers; i++) {
		fprintf(fp, "%s\n%s\n%s\n", c[i].name,c[i].user_name,c[i].pass);
	}
	fclose(fp);
}

//saving customer after signup
void  cc_saveInfo()
{
    int i;
    strcpy(c[number_of_customers].name,name);
    strcpy(c[number_of_customers].user_name,user_name);
    strcpy(c[number_of_customers].pass,pass);
    number_of_customers++;
    cc_writeData();
    setColor(219);
    gotoxy(65,8);
    printf("Successfully Created %s Account",user_name);
    sleep(2);
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

            gotoxy(65,30);
            s_avatar=shopper_user_check();

            //shopper_user_check();
            //printf("%d 44444444444444444444444444444444444444",s_avatar);
            //sleep(10000);
            if(s_avatar<0)
            {

                return login(1);//shows invalid user
                //printf("3333333333333355555555555555555555555555333333333333333333");
            }
            return 1;
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
            scanf(" %[^\n]",name);

            gotoxy(76, 20);
            scanf("%s",user_name);

            gotoxy(76, 23);
            scanf("%s",pass);
            if(s_uniqueID()) return sign_up(1);

            return 1;
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
            scanf("%[^\n]",name);

            gotoxy(76, 17);
            scanf("%s",user_name);

            gotoxy(76, 20);
            scanf("%s",pass);
            if(c_uniqueID()) return sign_up(1);
            return 2;

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

                //f2=s_profile();
                while(1)
                {
                    f2=s_profile();
                    //printf("%d 233467246734343",f2);
                    //sleep(10000);
                    if(f2==0)
                    {
                        f3 = add_products();
                    }
                    else if(f2==1)
                    {
                        f5 = update_pricing();
                    }
                    else if(f2==2)
                    {
                        f4 = delete_product();
                    }
                }
            }

        }
        else if(f==1)
        {
            f6=sign_up(0);
            if(f6==1)
            {
                s_saveInfo();

            }
            if(f6==2)
            {
                cc_saveInfo();

            }


        }
        else
        {
            system("cls");
            return 0;
        }
    }
}

