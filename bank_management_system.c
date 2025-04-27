#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#include<string.h>
char name[20];
int dip_amt,amt=10000,acc_no,wit_amt,trans_amt,ac;

void menu();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_details();
void transaction_details();
//void last_details();
int main()
{
    int choice;
    printf("Enter your name : ");
    gets(name);
    printf("Enter your account no: ");
    scanf(" %d",&acc_no);
    while(1)
    {
       menu();
       printf("Enter your choice: ");
       scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        deposit_money();
        break;
    case 2:
        withdraw_money();
         break;
    case 3:
        transfer_money();
        break;
    case 4:
        account_details();
        break;
    case 5:
        transaction_details();
        break;
    //case 6:
     //   last_details();
     //   exit(0);

    default:
        printf("Invalid Choice");
        exit(0);
    }
}
    return 0;
}
void menu()
{
    printf("MAIN MENU\n");
    printf("1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money\n");
    printf("4. Account Details\n");
    printf("5. Transaction Details\n");
    printf("6. Exit\n");

}

void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt","a");
    printf("DEPOSIT MONEY\n");
    printf("Enter amount you want to deposit: ");
    scanf("%d",&dip_amt);
    //printf("Money is being deposited:\n ");

    amt+=dip_amt;
    printf("MONEY DEPOSITED\n");
    printf("Current balance is %d\n",amt);
   fprintf(ptr,"Rs %d had been deposited to your account\n",dip_amt);
   fprintf(ptr,"Date and Time of your transaction %s",ctime(&tm));

}
void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *fp = fopen("Account.txt","a");
    printf("WITHDRAW MONEY\n");
    printf("Enter amount you want to withdraw: \n");
    scanf("%d",&wit_amt);

    amt-=wit_amt;
    printf("************MONEY WITHDRAWN**************\n");
    printf("Current balance is %d\n",amt);
    fprintf(fp,"Rs %d had been withdrawn from your account\n",wit_amt);
    fprintf(fp,"Date and Time of your transaction %s",ctime(&tm));
}

void transfer_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt","a");
    printf("TRANSFER MONEY\n");
    printf("Enter the amount: ");
    scanf("%d",&trans_amt);
    printf("Enter the account number in which you want to transfer the money: ");
    scanf("%d",&ac);

    if(amt<trans_amt)
    {
    printf("You don't have sufficeint balance \n");
    }

    else
    {
        amt-=trans_amt;
        printf("**********MONEY TRANSFERED***********\n");
        printf("Current balance is %d\n",amt);
    }
    fprintf(ptr,"Rs %d had been transfered from your account\n",trans_amt);
    fprintf(ptr,"Date and Time of your transaction %s",ctime(&tm));

}
void account_details()
{
     printf("ACCOUNT DETAILS\n");
     for(int i=0;i<50;i++)
     {
          printf("-");
     }
     printf("Name : %s \n",name);
     printf("Account no %d\n",acc_no);
     printf("Total balance = %d\n ",amt);
     printf("Press ant key to continue....");
}

void transaction_details()
{
    FILE *ptr;
    ptr = fopen("Account.txt","r");   
    
    char c = fgetc(ptr);
    if(c==EOF)
    {
        printf("No recent transaction\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
        while(c!=EOF)
        {
            printf("%c",c);
            c = fgetc(ptr);
        }
    }
    getch();
}