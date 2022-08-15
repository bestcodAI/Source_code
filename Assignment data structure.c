#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "chamnan.bin"
// Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)

void Show();
void updateSuccess();
void About();
void login();
void Cools();
void Cools1();
void Loading();
void LogSuccess();
void addSuccess();
void deletSuccess();
void Awesome();



//Giving some delay
void delay( unsigned int value)
{
    unsigned int count1 =0;
    unsigned int count2 = 0;

    for(count1 = 0; count1 < value ; count1++ )
    {
        for(count2 = 0; count2 < count1 ; count2++ )
        {

        }
    }
}


// string to display Rocket
const char rocket[] =
    "           ^ \n\
          /^\\\n\
          |-|\n\
          |K|\n\
          |H|\n\
          |M|\n\
          |E|\n\
         /|R|\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
         ^   ^   \n\
";

int Hacker()
{

    int jumpControlAtBottom = 0;
    const int someDelay = 10009;
    int shifControl = 0;


    //jump to bottom of console

    for (jumpControlAtBottom = 0; jumpControlAtBottom < 30; ++jumpControlAtBottom)
    {
        printf("\n");
    }

    //Print rocket
    //fputs(rocket,stdout);
    printf("%s",rocket);

    for (shifControl = 0; shifControl < 30; ++shifControl)
    {
        // Rocket move on the basis of delay
        delay(someDelay);
        
        // move rocket a line upward
        printf("\n");
    }
}

void gotoxy(int x, int y)
{
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//structure to store date
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;
typedef struct// to call in program
{
    unsigned int books_id; // declare the integer data type
    char bookName[MAX_BOOK_NAME];// declare the character data type
    char authorName[MAX_AUTHOR_NAME];// declare the charecter data type
    char studentName[MAX_STUDENT_NAME];// declare the character data type
    char studentAddr[MAX_STUDENT_ADDRESS];// declare the character data type
    Date bookIssueDate;// declare the integer data type
} s_BooksInfo;
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############             Library management System 2022        ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t---------------------------------------------------------------------------");
}
void welcomeMessage()
{
    headMessage("www.personalweb.com.kh");
    sFileHeader fileHeaderInfo = {0};
    system("color 1");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    Show();
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
// Add books in list
void addBookInDataBase()
{
	system("color 37");
    int days;
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        //exit(1);
    }
    headMessage("ADD NEW BOOKS");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tBook ID NO  = ");
    fflush(stdin);
    scanf("%u",&addBookInfoInDataBase.books_id);
    do
    {
        printf("\n\t\t\tBook Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName,MAX_BOOK_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tAuthor Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName,MAX_AUTHOR_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tStudent Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.studentName,MAX_STUDENT_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.studentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addBookInfoInDataBase.bookIssueDate.dd,&addBookInfoInDataBase.bookIssueDate.mm,&addBookInfoInDataBase.bookIssueDate.yyyy);
        //check date validity
        status = isValidDate(&addBookInfoInDataBase.bookIssueDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
    Loading();
    addSuccess();
    system("color 57");
}
// search books
void searchBooks()
{
	system("color 20");
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
//        exit(1);
    }
    headMessage("SEARCH BOOKS");
    //put the control on books detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
//        exit(1);
    }
    printf("\n\n\t\t\tEnter Book Name to search: ");
    fflush(stdin);
    fgets(bookName,MAX_BOOK_NAME,stdin);
    Cools1();
    headMessage("SEARCH BOOKS");
    system("color 20");
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
    	
        printf("\n\t\t\tBook id = %u\n",addBookInfoInDataBase.books_id);
        printf("\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
    system("color 57");
}
// v books function
void viewBooks()
{
	system("color 40");
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    headMessage("VIEW BOOKS DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
//        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
//        exit(1);
    }
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d\n\n",countBook);
        printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
        printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        found = 1;
        ++countBook;
        printf("\n\t-------------------------------------------------------------------------------------------------");
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
    system("color 57");
}
// delete function
void deleteBooks()
{
    int found = 0;
    int bookDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    int status = 0;
    headMessage("Delete Books Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
//        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
//        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    scanf("%d",&bookDelete);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(addBookInfoInDataBase.books_id != bookDelete)
        {
            fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    
    Loading();
    (found)? deletSuccess() :printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
    system("color 57");
}

//Update book

void Updatebook()
{
    
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    int flag = 0;
    FILE *fp = NULL;
    headMessage("Update Books Details");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
        fclose(fp);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
//        exit(1);
    }
    
    printf("\n\t\t\tEnter Book Name. for Update:  ");
    fflush(stdin);
    fgets(bookName,MAX_BOOK_NAME,stdin);
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp) == 1)
    {
        if (strcmp(addBookInfoInDataBase.bookName,bookName)==0)
        {
//            printf("\n\t\t\tUpdate Book id: ");
			printf("\n\t\t\tUpdate Book Name: ");
			fflush(stdin);
			fgets(addBookInfoInDataBase.bookName,MAX_BOOK_NAME,stdin);
//			printf("\n\t\t\tUpdate Book Author: ");
			printf("\n\t\t\tUpdate Book Date Issue Books: ");
			scanf("%d/%d/%d",&addBookInfoInDataBase.bookIssueDate.dd,&addBookInfoInDataBase.bookIssueDate.mm,&addBookInfoInDataBase.bookIssueDate.yyyy);
            fseek(fp,-sizeof(addBookInfoInDataBase), 1);
            fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, fp);
            flag =1;
            break;
        }
    }
    
    if(flag == 1){
        	Loading();
            updateSuccess();	
	}
	else
	{
			printf("\nRecord not found!!");
			printf("\nPress Any Key to main menu...");
            getch();
	}
    fclose(fp);
    system("color 57");
}


void updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
//        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
//        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    Loading();
    system("cls");
    headMessage("UPDATE PASSWORD AREADY");
    system("color 3f");
//    printf("\n\t\t\tYour Password has been changed successfully");
//    printf("\n\t\t\tPress to Login Again...");
    MessageBox(0,"Your Password has been changed successfully\nPress Ok to Login again...","Message",1);
    fflush(stdin);
//    getchar();
    login();
//    exit(1);
    system("color 57");
}

void Show()
{
	sFileHeader fileHeaderInfo = {0};
	FILE *fp;
	fp = fopen(FILE_NAME,"rb");
	if(fp == NULL)
    {
        printf("File is not opened\n");
//        exit(1);
    }
    
    while(!fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp));
    {
    	printf("\n\t\t\t Username For Login is : %s",fileHeaderInfo.username);
        printf("\n\t\t\t Password For Login is : %s",fileHeaderInfo.password);
	}
    fclose(fp);
    
}
void menu()
{
    int choice = 0;
    system("color 57");
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Updat Books");
        printf("\n\t\t\t6.Update Password");
        printf("\n\t\t\t7.About Me");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice:-$ ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        	Awesome();
            addBookInDataBase();
            break;
        case 2:
        	Awesome();
            searchBooks();
            break;
        case 3:
        	Awesome();
            viewBooks();
            break;
        case 4:
        	Awesome();
            deleteBooks();
            break;
        case 5:
        	Awesome();
        	Updatebook();
        	break;
        case 6:
        	Awesome();
            updateCredential();
            break;
        case 7:
        	Awesome();
        	About();
        	break; 
        case 0:
        	Awesome();
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
           exit(1);
            break;
        default:
        	Awesome();
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            break;
        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}
//login password
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int L=0;
    system("color 80");
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("Login");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
//        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
        	system("cls");
        	Cools();
        	LogSuccess();
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("Login Failed");
        printf("\n\t\t\t\tSorry,Unknown User.We Are Exit Your System");
        getch();
        system("cls");
    }
}
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="root\n";
    const char defaultPassword[] ="root\n";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
void Cools(){
	int i;
	system("color 5");
	for(i=0; i<34; i++){
		Sleep(20);
		printf("\n\n\n\n\t\t\t\tWe Are Logining (Username & Password). Please wait 2s...\\");
		Sleep(20);
		system("cls");
		printf("\n\n\n\n\t\t\t\tWe Are Logining (Username & Password). Please wait 2s.../");
		Sleep(20);
		system("cls");
	}
	system("color 7");
}

void Cools1(){
	int i;
	system("color 4");
	for(i=0; i<34; i++){
		Sleep(20);
		printf("\n\n\n\n\t\t\t\tWe Are Searching (Data or File). Please wait 2s...\\");
		Sleep(20);
		system("cls");
		printf("\n\n\n\n\t\t\t\tWe Are Searching (Data or File). Please wait 2s.../");
		Sleep(20);
		system("cls");
	}
	system("color 7");
}

void Cools2(){
	int i;
	system("color 4");
	for(i=0; i<34; i++){
		Sleep(20);
		printf("\n\n\n\n\t\t\t\tWe Are Updating (Username & Password). Please wait 2s...\\");
		Sleep(20);
		system("cls");
		printf("\n\n\n\n\t\t\t\tWe Are Updating (Username & Password). Please wait 2s.../");
		Sleep(20);
		system("cls");
	}
	system("color 7");
}
void Loading()
{
	int i;
	system("cls");
	system("color 5");
	printf("\n\n\n\n\n\t\t\t\t");
	printf("LOADING:");
	printf("\n\t\t\t\t");
	for(i=0; i< 34; i++){
		Sleep(60);
		printf("\xB2");
	}
	system("color 7");
}
void LogSuccess()
{
	system("cls");
	system("color a");
	printf("\n\n\n\n");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\n\t\t\t\t|      LOGIN SUCCESSFULLY....!!!        |");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\nPress Any Key to Continue....");
	getch();
	system("color 7");
}
void addSuccess()
{
	system("cls");
	system("color a");
	printf("\n\n\n\n");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\n\t\t\t\t|      ADDING SUCCESSFULLY....!!!       |");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\nPress Any Key to Continue....");
	getch();
	system("color 7");
}
void updateSuccess()
{
	system("cls");
	system("color a");
	printf("\n\n\n\n");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\n\t\t\t\t|      UPDATING SUCCESSFULLY....!!!     |");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\nPress Any Key to Continue....");
	getch();
	system("color 7");
}
void deletSuccess()
{
	system("cls");
	system("color a");
	printf("\n\n\n\n");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\n\t\t\t\t|      DELETING SUCCESSFULLY....!!!     |");
	printf("\n\t\t\t\t-----------------------------------------");
	printf("\nPress Any Key to Continue....");
	getch();
	system("color 7");
}

void Awesome()
{
	int i;
	system("cls");
	system("color 6");
	for(i=0; i<5; i++){
		Sleep(30);
		printf("\n\n\n\n\t\t\t\tLoading...\\0");
		system("color 4");
		system("cls");
		Sleep(30);
		printf("\n\n\n\n\t\t\t\tLoading.../1.");
		system("color 2");
		system("cls");
		Sleep(30);
		printf("\n\n\n\n\t\t\t\tLoading...\\2..");
		system("color 3");
		system("cls");
		Sleep(30);
		printf("\n\n\n\n\t\t\t\tLoading.../3...");
		system("color 4");
		system("cls");
		Sleep(30);
		printf("\n\n\n\n\t\t\t\tLoading.../4....");
		system("color 2");
		system("cls");
		Sleep(30);
		printf("\n\n\n\n\t\t\t\tLoading.../5.....");
		system("color 3");
		system("cls");
		Sleep(30);
	}
	system("color 7");
}

void Into()
{
	int i;
	for(i=0; i< 5; i++)
	{
	Sleep(30);
	system("color 4");
	system("cls");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL       CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE    11\n");
	printf("\t11       WW W   W WW     EEEE       LL       CC       OO   OO   MM  M  M MM    EEEEE      11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL     CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE    11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	system("cls");
	Sleep(30);
	system("color 2");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL       CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE    11\n");
	printf("\t11       WW W   W WW     EEEE       LL       CC       OO   OO   MM  M  M MM    EEEEE      11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL     CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE    11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	system("cls");
	Sleep(30);
	system("color 3");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEEE       11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	Sleep(30);
	system("color 4");
	system("cls");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEEE       11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	system("cls");
	Sleep(30);
	system("color 2");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEEE       11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	system("cls");
	Sleep(30);
	system("color 3");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEEE       11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	Sleep(30);
	system("color 4");
	system("cls");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEEE       11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	system("cls");
	Sleep(30);
	system("color 2");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEE        11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	system("cls");
	Sleep(30);
	system("color 3");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	printf("\t11                                                                                        11\n");
	printf("\t11      WW    W    WW    EEEEEEE    LL      CCCCCC   OOOOOOO   MMM     MMM    EEEEEEE     11\n");
	printf("\t11       WW W   W WW     EEEE       LL      CC       OO   OO   MM  M  M MM    EEEEE       11\n");
	printf("\t11        WWW   WWW      EEEEEEE    LLLL    CCCCCC   OOOOOOO   MM   MM  MM    EEEEEEE     11\n");
	printf("\t11                                                                                        11\n");
	printf("\t11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	}
}

void About()
{
	system("color 60");
	headMessage("ABOUT ME");
	int i;
	printf("\n\t\t\tName: CHOU CHAMNAN");
	printf("\n\t\t\tStudent : 2 year of IT");
	printf("\n\t\t\tStudent at PSBU");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2 Contact Me \xB2\xB2\xB2\xB2\xB2");
	printf("\n\t\t\t1.Telegram Account");
	printf("\n\t\t\t2.Linkin Account");
	printf("\n\t\t\t3.My Assistant");
	printf("\n\t\t\t4.Go to Menu");
	printf("\n\t\t\t Go to my contact: ");
	scanf("%d",&i);
	if(i==1){
		MessageBox(0,"Welcome to My telegram...!!","Message",1);
		Hacker();
		system("start https://t.me/chamnanprogrammer");
	}else if(i == 2){
			MessageBox(0,"Welcome to My Linkin...!!","Message",1);
			Hacker();
		system("start https://www.linkedin.com/in/chamnan-chou-275148229");
	}else if(i == 3){
		   Hacker();
			MessageBox(0,"Welcome to My Assistant...!!","Message",1);
		system("start https://dinogamemakingbyprogrammerkh.on.drv.tw/Making%20AI%20Bot/");
	}else{
		printf("Press any key to main menu...");
		getch();
		Awesome();
	}
	system("color 57");
}
int main()
{
	Into();
	Hacker();
    init();
    welcomeMessage();
    login();
    getch();
    return 0;
    
}
