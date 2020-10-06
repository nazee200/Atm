#include<conio.h>
#include<stdio.h>
#include<dos.h>
long int atm_balance=10000;
struct atm_detail
{
int dd,mm,yy;
long int account_number;
char particular[20];
long int amount;
long int balance;
}atm_detail;
struct detail
{
char name[15];
char address[30];
char phone_number[10];
long int account_number;
long int balance;
char pass_word[10];
}detail;
void encrpt(char[],int);
void decrpt(char[],int);
void admin();
void create();
void add();
void update();
void delete_detail();
void balance();
void display_all();
void withdraw();
void deposit();
void display_one();
void user();
void transfer();
void atm();
void pin_change();
void mini();
void encrpt(char password[20],int key)
{
int i;
for(i=0;i<strlen(password);i++)
{
password[i]=password[i]-key;
}
}
void decrpt(char password[20],int key)
{
int i;
for(i=0;i<strlen(password);i++)
{
password[i]=password[i]+key;
}
}
void main()
{
char choice;
clrscr();
while(1)
{
clrscr();
printf("\n\n\t\t **********WELCOME TO SAEC BANK**********");
printf("\n\n\t\t\t     ****MAIN MENU****            ");
printf("\n\n\n\t 1.Admin");
printf("\n\n\t 2.User");
printf("\n\n\t 3.Exit");
choice=getch();
switch(choice)
{
case '1':
 admin();
 break;
case '2':
 user();
 break;
case '3':
 exit(0);
 break;
default:
 printf("\n\n\n\t\t Invalid Key pressed");
 getch();
 main();
 break;
}
}
}


void admin()
{
int i=0;
char d,choice,pass_word[10]="siva@123",get_pass[10]="";
char id[10]="welcome",get_id[10]="";
clrscr();
printf("\n\n\t Enter The Login Id   :");
scanf("%s",get_id);
printf("\n\n\t Enter The Pass Word  :");
while((d=getch())!='\r')
{
 get_pass[i]=d;
 printf("*");
 i++;
}
if((strcmp(pass_word,get_pass)==0)&&(strcmp(id,get_id)==0))
{
clrscr();
while(1)
{
clrscr();
printf("\n\n\t\t *****WELCOME TO ADMIN MANU*****");
printf("\n\n\n\t 1.Create");
printf("\n\n\t 2.Add new");
printf("\n\n\t 3.Update");
printf("\n\n\t 4.Display");
printf("\n\n\t 5.Delete");
printf("\n\n\t 6.Mini statement");
printf("\n\n\t 7.Go To Main Menu\n");
choice=getch();
switch(choice)
{
case '1':
 create();
 break;
case '2':
 add();
 break;
case '3':
 update();
 break;
case '4':
 display_all();
 break;
case '5':
 delete_detail();
 break;
case '6':
 mini();
 break;
case '7':
 main();
 break;
default:
 printf("\n\n\n\t\t Invalid key Pressed");
 getch();
 break;
}
}
}
else
{
printf("\n\n\t\t Invalid Password");
getch();
}
}

void user()
{
char choice;
while(1)
 {
  clrscr();
  printf("\n\n\t\t *****WELCOME TO USER MENU*****");
  printf("\n\n\n\t 1.Check balance");
  printf("\t\t 2.Withdraw");
  printf("\n\n\n\t 3.Deposit");
  printf("\t\t\t 4.Transfer");
  printf("\n\n\n\t 5.Display Account Detail");
  printf("\t 6.Mini Statement");
  printf("\n\n\n\t 7.Change Pin");
  printf("\t\t\t 8.Go To Main Menu\n");
  choice=getch();
  switch(choice)
  {
  case '1':
   balance();
   break;
  case '2':
   withdraw();
   break;
  case '3':
   deposit();
   break;
  case '4':
   transfer();
   break;
  case '5':
   display_one();
   break;
  case '6':
   atm();
   break;
  case '7':
   pin_change();
   break;
  case '8':
   main();
   break;
  default:
   printf("\n\n\n\t\t Invalid key Pressed");
   getch();
   break;
  }
 }
}

void create()
{
char choice;
FILE *fp;
clrscr();
fp=fopen("account_detail.txt","a");
do
{
clrscr();
printf("\n\n\t====================");
printf("\n\t CREATING A ACCOUNT");
printf("\n\t======================");
printf("\n\n Enter The Costomer's Name            :");
scanf("%s",detail.name);
encrpt(detail.name,0xFACA);
printf("\n Enter The Costomer's Address         :");
scanf("%s",detail.address);
encrpt(detail.address,0xFACA);
printf("\n Enter The customer's Phone Number    :");
scanf("%s",&detail.phone_number);
printf("\n Enter The  Account Number            :");
scanf("%lu",&detail.account_number);
printf("\n Enter The Balance Amount             :");
scanf("%lu",&detail.balance);
printf("\n Enter The User's Password            :");
scanf("%s",detail.pass_word);
encrpt(detail.pass_word,0xFACA);
fwrite(&detail,sizeof(detail),1,fp);
printf("\n\n\t Do You Want To Add One More Record (y/n):");
scanf(" %c",&choice);
}while(choice=='y');
fclose(fp);
}

void add()
{
FILE *fp;
fp=fopen("account_detail.txt","a");
clrscr();
printf("\n\n\t==============");
printf("\n\t ADD NEW RECORD");
printf("\n\t=================");
printf("\n\n Enter The Customer's Name            :");
scanf("%s",detail.name);
encrpt(detail.name,0xFACA);
printf("\n Enter The Customer's Address         :");
scanf("%s",detail.address);
encrpt(detail.address,0xFACA);
printf("\n Enter The customer's Phone Number    :");
scanf("%s",detail.phone_number);
printf("\n Enter The Account Number             :");
scanf("%ld",&detail.account_number);
printf("\n Enter the Balance Amount             :");
scanf("%ld",&detail.balance);
printf("\n Enter The User's Password            :");
scanf("%s",detail.pass_word);
encrpt(detail.pass_word,0xFACA);
fwrite(&detail,sizeof(detail),1,fp);
printf("\n\n\t New Account Is Created");
getch();
fclose(fp);
}

void update()
{
FILE *fp;
long int account_no;
int found=0,choice;
clrscr();
printf("\n\n\t================");
printf("\n\t UPDATE A RECORD");
printf("\n\t====================");
fp=fopen("account_detail.txt","r+");
rewind(fp);
printf("\n\n Enter The Account Number To Be Update:");
scanf("%lu",&account_no);
while((fread(&detail,sizeof(detail),1,fp)>0)&&(found==0))
{
if(account_no==detail.account_number)
{
clrscr();
printf("\n\n\t 1.Name");
printf("\n\n\t 2.Address");
printf("\n\n\t 3.Phone Number");
printf("\n\n\t 4.Account Number");
printf("\n\n\t 5.Balance");
printf("\n\n\t 6.User Password");
choice=getch();
clrscr();
switch(choice)
{
case '1':
  printf("\n Enter The Customer's Name           :");
  scanf("%s",&detail.name);
  encrpt(detail.name,0xFACA);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  break;
case '2':
  printf("\n Enter The Customer's Address        :");
  scanf("%s",detail.address);
  encrpt(detail.address,0xFACA);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  break;
case '3':
  printf("\n Enter The Customer's Phone Number   :");
  scanf("%s",detail.phone_number);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  break;
case '4':
  printf("\n Enter The Account Number            :");
  scanf("%ld",&detail.account_number);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  break;
case '5':
  printf("\n Enter The Balance Amount           :");
  scanf("%ld",&detail.balance);
   fseek(fp,-(long)sizeof(detail),1);
   fwrite(&detail,sizeof(detail),1,fp);
  break;
case '6':
  printf("\n Enter The User's Password          :");
  scanf("%s",detail.pass_word);
  encrpt(detail.pass_word,0xFACA);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  break;
default:
 printf("\n Invalid Key Pressed");
 getch();
 update();
 break;
}
found=1;
printf("\n\n\t\t A Account Is Updated");
}
}
fclose(fp);
if(found==0)
{
printf("\n\n\t\t Record Not Found");
}
getch();
}

void delete_detail()
{
long int account_number;
FILE *fpr,*fpw ;
clrscr();
printf("\n\n\t================");
printf("\n\t DELETE A RECORD");
printf("\n\t====================");
fpr=fopen("account_detail.txt","r");
fpw=fopen("temp.txt","w");
printf("\n Enter the deleting Account number:");
scanf("%lu",&account_number);
rewind(fpr);
while(fread(&detail,sizeof(detail),1,fpr))
{
 if(account_number!=detail.account_number)
 {
  fwrite(&detail,sizeof(detail),1,fpw);
 }
}
fclose(fpr);
fclose(fpw);
remove("account_detail.txt");
rename("temp.txt","account_detail.txt");
printf("\n\n\t A Account Is Deleted");
getch();
}

void display_all()
{
FILE *fp;
int i=0;
char a,password[10]="syed@123",get_pass[10]="";
clrscr();
fp=fopen("account_detail.txt","r");
printf("\n\t Enter the Password      :");
while((a=getch())!='\r')
{
 get_pass[i]=a;
 printf("*");
 i++;
}
rewind(fp);
if(strcmp(password,get_pass)==0)
{
while(fread(&detail,sizeof(detail),1,fp))
{
clrscr();
printf("\n\n\t\t=====================");
printf("\n\t\t DISPLAY ALL RECORD");
printf("\n\t\t======================");
decrpt(detail.name,0xFACA);
decrpt(detail.address,0xFACA);
decrpt(detail.pass_word,0xFACA);
printf("\n      ----------------------------------");
printf("\n\n\t Name            :%s",detail.name);
printf("\n\n\t Address         :%s",detail.address);
printf("\n\n\t Phone no        :%s",detail.phone_number);
printf("\n\n\t Account number  :%ld",detail.account_number);
printf("\n\n\t Balance amount  :%ld",detail.balance);
printf("\n\n\t user password   :%s\n",detail.pass_word);
printf("\n      ----------------------------------");
printf("\n\n\n\t\t Press Enter For Next Content");
getch();
}
}
else
{
printf("\n\n\n\n\t\t Invalid Pass Word");
printf("\n\n\t\t Your Are Not The Admin");
getch();
while(fread(&detail,sizeof(detail),1,fp))
{
clrscr();
printf("\n\n\t\t=====================");
printf("\n\t\t DISPLAY ALL RECORD");
printf("\n\t\t======================");
printf("\n      ----------------------------------");
printf("\n\n\t Name            :%s",detail.name);
printf("\n\n\t Address         :%s",detail.address);
printf("\n\n\t Phone no        :%s",detail.phone_number);
printf("\n\n\t Account number  :%ld",detail.account_number);
printf("\n\n\t Balance amount  :%ld",detail.balance);
printf("\n\n\t user password   :%s\n",detail.pass_word);
printf("\n      ----------------------------------");
printf("\n\n\n\t\t Press Enter For Next Content");
getch();
}
}
fclose(fp);
getch();
}

void display_one()
{
int found=0,i=0;
long account_number;
char pass_word[10]="",a;
FILE *fp;
clrscr();
fp=fopen("account_detail.txt","r");
printf("\n Enter The Your Account Number:");
scanf("%lu",&account_number);
printf("\n Enter The Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
  decrpt(detail.name,0xFACA);
  decrpt(detail.address,0xFACA);
  decrpt(detail.pass_word,0xFACA);
 if((account_number==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
  found=1;
  clrscr();
  printf("\n\n\t\t ******WELCOME %s******",detail.name);
  printf("\n      ----------------------------------");
  printf("\n\n\t Name           :%s",detail.name);
  printf("\n\n\t Address        :%s",detail.address);
  printf("\n\n\t Phone no       :%s",detail.phone_number);
  printf("\n\n\t Account number :%ld",detail.account_number);
  printf("\n\n\t Balance amount :%ld",detail.balance);
  printf("\n\n\t user password  :%s\n",detail.pass_word);
  printf("\n      ----------------------------------");
  printf("\n\n\n\t\t Thank You Using ATM Service");
 }
}
if(found==0)
 printf("\n\n\n\t Incorrect Password or Account Number");
getch();
fclose(fp);
}


void withdraw()
{
struct date d;
int found=0,i=0;
long int account_number,withdraw;
char pass_word[10]="",a;
FILE *fp,*fptr,*fpb;
clrscr();
getdate(&d);
fp=fopen("account_detail.txt","r+");
fptr=fopen("atm_detail.txt","a");
printf("\n\t Enter Your Account Number:");
scanf("%ld",&account_number);
printf("\n\t Enter Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
  decrpt(detail.name,0xFACA);
  decrpt(detail.address,0xFACA);
  decrpt(detail.pass_word,0xFACA);
 if((account_number==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
  found=1;
  clrscr();
  printf("\n\n\t\t ******WELCOME %s*****",detail.name);
  printf("\n\n        -------------------------------------------");
  printf("\n\n\t Enter The Withdraw Amount     :");
  scanf("%ld",&withdraw);
  if((detail.balance-500)<withdraw)
  {
   printf("\n\n\t\t Insufficient Balance");
   printf("\n\n        -------------------------------------------");
  }
  else if((withdraw%100)!=0)
  {
   printf("\n\n\t\t Please Enter Amount Multiples Of 100");
   printf("\n\n        -------------------------------------------");
  }
  else if((atm_balance-1000)<withdraw)
   {
   printf("\n\n\t\t Sorry!!! ATM Does Not Have Sufficient Amount");
   printf("\n\n\t\t Please Check Near By ATM Service");
   printf("\n\n        -------------------------------------------");
   }
  else
   {
    atm_detail.dd=d.da_day;
    atm_detail.mm=d.da_mon;
    atm_detail.yy=d.da_year;
    detail.balance=detail.balance-withdraw;
    atm_detail.account_number=detail.account_number;
    atm_detail.amount=withdraw;
    atm_detail.balance=detail.balance;
    strcpy(atm_detail.particular,"withdraw");
    atm_balance=atm_balance-withdraw;
    printf("\n\n\t\t Collect Your Money");
    printf("\n\n\t Your Current Balance Is %d", detail.balance);
    printf("\n\n\n\t\t Thank You Using ATM Service");
    printf("\n\n        -------------------------------------------");
    fwrite(&atm_detail,sizeof(atm_detail),1,fptr);
   }
  encrpt(detail.name,0xFACA);
  encrpt(detail.address,0xFACA);
  encrpt(detail.pass_word,0xFACA);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
 }
}
if(found==0)
{
 printf("\n\n\n\t\t Incorrect Password or Account Number\n");
}
getch();
fclose(fp);
fclose(fptr);
}

void deposit()
{
struct date d;
int found=0,i=0;
long int account_number,deposit;
char pass_word[10]="",a;
FILE *fp,*fptr;
clrscr();
getdate(&d);
fp=fopen("account_detail.txt","r+");
fptr=fopen("atm_detail.txt","a");
printf("\n\n\t Enter Your Account Number:");
scanf("%ld",&account_number);
printf("\n\n\t Enter Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);

while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
  decrpt(detail.name,0xFACA);
  decrpt(detail.pass_word,0xFACA);
 if((account_number==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
  found=1;
  clrscr();
  printf("\n\n\t\t ******WELCOME %s *****",detail.name);
  printf("\n\n        -------------------------------------------");
  printf("\n\n\t Enter Deposit Amount      :");
  scanf("%ld",&deposit);
  atm_detail.dd=d.da_day;
  atm_detail.mm=d.da_mon;
  atm_detail.yy=d.da_year;
  detail.balance=detail.balance+deposit;
  atm_detail.account_number=detail.account_number;
  atm_detail.amount=deposit;
  atm_detail.balance=detail.balance;
  strcpy(atm_detail.particular,"Deposit");
  atm_balance=atm_balance+deposit;
  printf("\n\n\t\t Amount Successfully Deposited");
  printf("\n\n\t Your Current Balance Is %d", detail.balance);
  printf("\n\n        -------------------------------------------");
  printf("\n\n\t\t Thank You Using ATM Service");
  encrpt(detail.name,0xFACA);
  encrpt(detail.pass_word,0xFACA);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  fwrite(&atm_detail,sizeof(atm_detail),1,fptr);
 }
}
if(found==0)
{
 printf("\n\n\n\t\t Incorrect Password or Account Number\n");
}
getch();
fclose(fp);
fclose(fptr);
}


void balance()
{
int found=0,i=0;
long int account_no,deposit;
char pass_word[10]="",a;
FILE *fp;
clrscr();
fp=fopen("account_detail.txt","r+");
printf("\n\n\t Enter Your Account Number:");
scanf("%ld",&account_no);
printf("\n\t Enter Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
  decrpt(detail.name,0xFACA);
  decrpt(detail.pass_word,0xFACA);
 if((account_no==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
  found=1;
  clrscr();
  printf("\n\n\n\t\t ******WELCOME %s *****",detail.name);
  printf("\n\n        -------------------------------------------");
  printf("\n\n\t\t Your Current Balance Is %d", detail.balance);
  printf("\n\n        -------------------------------------------");
  printf("\n\n\n\t\t Thank You Using ATM Service");
 }
}
if(found==0)
 printf("\n\n\n\t\t Incorrect Password or Account Number\n");
getch();
fclose(fp);
}

void atm()
{
int found=0,i=0;
long int account_number;
char pass_word[10]="",a;
FILE *fp,*fptr;
clrscr();
fp=fopen("account_detail.txt","r+");
fptr=fopen("atm_detail.txt","r");
printf("\n\n\t Enter Your Account Number:");
scanf("%ld",&account_number);
printf("\n\t Enter Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
 decrpt(detail.name,0xFACA);
 decrpt(detail.pass_word,0xFACA);
 if((account_number==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
   clrscr();
   found=1;
   printf("\n\n\n\t\t ******WELCOME %s *****",detail.name);
 }
}
if(found==1)
{
 rewind(fptr);
 printf("\n --------------------------------------------------------");
 printf("\n\n    Date       Particular         Amount       Balace");
 while(fread(&atm_detail,sizeof(atm_detail),1,fptr))
 {
 if(account_number==atm_detail.account_number)
  {
   printf("\n   %d/%d/%d      %s          %ld         %ld   ",atm_detail.dd,atm_detail.mm,atm_detail.yy,atm_detail.particular,atm_detail.amount,atm_detail.balance);
  }
 }
  printf("\n\n\t\t Thank You Using ATM Service");
  printf("\n -------------------------------------------------------");
}
if(found==0)
{
 printf("\n\n\t\t Incorrect Password or Account Number\n");
 printf("\n --------------------------------------------------");
}
getch();
fclose(fp);
fclose(fptr);
}

void pin_change()
{
int found=0,i=0;
long int account_number;
char pass_word[10]="",a;
FILE *fp;
clrscr();
fp=fopen("account_detail.txt","r+");
printf("\n\n\t Enter Your Account Number:");
scanf("%ld",&account_number);
printf("\n\t Enter Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
 decrpt(detail.pass_word,0xFACA);
 decrpt(detail.name,0xFACA);
 if((account_number==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
  clrscr();
  printf("\n\n\n\t\t ******WELCOME %s *****",detail.name);
  printf("\n --------------------------------------------------");
  printf("\n\n Enter The New Password          :");
  scanf("%s",detail.pass_word);
  encrpt(detail.name,0xFACA);
  encrpt(detail.pass_word,0xFACA);
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  found=1;
  printf("\n\n\t Password Sussesfully Chanced");
  printf("\n --------------------------------------------------");
  getch();
 }
}
if(found==0)
{
 printf("\n\n\t\t Incorrect Account Number Or Pass Word");
 getch();
}
fclose(fp);
}

void mini()
{
FILE *fptr;
fptr=fopen("atm_detail.txt","r");
rewind(fptr);
clrscr();
printf("\n -------------------------------------------------------------");
printf("\n\n     Date     AccountNumber    Particular    Amount    Balace");
while(fread(&atm_detail,sizeof(atm_detail),1,fptr))
{
 printf("\n\n %d/%d/%d      %ld        %s        %ld        %ld",atm_detail.dd,atm_detail.mm,atm_detail.yy,atm_detail.account_number,atm_detail.particular,atm_detail.amount,atm_detail.balance);
}
printf("\n\n -----------------------------------------------------------");
getch();
fclose(fptr);
}

void transfer()
{
struct date d;
long int account_number,transfer_amount,transfer_account;
int found=0,i=0,transfer=0,permit=0;
char pass_word[10]="",a,choice;
FILE *fp,*fptr;
clrscr();
getdate(&d);
fp=fopen("account_detail.txt","r+");
fptr=fopen("atm_detail.txt","a");
printf("\n\n\t Enter Your Account Number:");
scanf("%ld",&account_number);
printf("\n\t Enter Your Password      :");
while((a=getch())!='\r')
{
 pass_word[i]=a;
 printf("*");
 i++;
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(found==0))
{
 decrpt(detail.name,0xFACA);
 decrpt(detail.pass_word,0xFACA);
 if((account_number==detail.account_number)&&(strcmp(pass_word,detail.pass_word)==0))
 {
  clrscr();
  found=1;
  printf("\n\n\n\t\t ******WELCOME %s *****",detail.name);
  printf("\n\n        -------------------------------------------");
  printf("\n\n\t Enter The Transfer Account Number    :");
  scanf("%ld",&transfer_account);
  printf("\n\n\t Enter the transfer amount            :");
  scanf("%ld",&transfer_amount);
  if((detail.balance-500)<transfer_amount)
  {
   printf("\n\n\t Insufficient Balance");
   printf("\n\n        -------------------------------------------");
  }
  else
    permit=1;
 }
}
if(found==0)
{
 printf("\n\n\n\t Invalid Password Or Account number");
 printf("\n\n        -------------------------------------------");
}

rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(permit==1)&&(found==1))
{
  decrpt(detail.name,0xFACA);
 if(transfer_account==detail.account_number)
 {
  found=0;
  printf("\n\n\t Do You Want TO Transfer Money To %s (y/n):",detail.name);
  scanf(" %c",&choice);
  if(choice=='y')
  {
   transfer=1;
   detail.balance=detail.balance+transfer_amount;
   encrpt(detail.name,0xFACA);
   fseek(fp,-(long)sizeof(detail),1);
   fwrite(&detail,sizeof(detail),1,fp);
   atm_detail.dd=d.da_day;
   atm_detail.mm=d.da_mon;
   atm_detail.yy=d.da_year;
   atm_detail.account_number=detail.account_number;
   atm_detail.amount=transfer_amount;
   atm_detail.balance=detail.balance;
   strcpy(atm_detail.particular,"Credict");
   fwrite(&atm_detail,sizeof(atm_detail),1,fptr);
  }
  else
  {
   printf("\n\n\t Amount Is Not  Transfered Successfully");
   printf("\n\n\t Thank You For Using ATM Service");
   printf("\n\n        -------------------------------------------");
  }
 }
}
if(found==1)
{
 printf("\n\n\t Account Number Not found");
 printf("\n\n        -------------------------------------------");
}
rewind(fp);
while((fread(&detail,sizeof(detail),1,fp))&&(transfer==1))
{
 if(account_number==detail.account_number)
 {
  detail.balance=detail.balance-transfer_amount;
  printf("\n\n\t\t Your Current Balance Is %d", detail.balance);
  printf("\n\n\t Amount Transfered Successfully");
  printf("\n\n\t Thank You For Using ATM Service");
  printf("\n\n        -------------------------------------------");
  fseek(fp,-(long)sizeof(detail),1);
  fwrite(&detail,sizeof(detail),1,fp);
  strcpy(atm_detail.particular,"Transfer");
  atm_detail.dd=d.da_day;
  atm_detail.mm=d.da_mon;
  atm_detail.yy=d.da_year;
  atm_detail.account_number=detail.account_number;
  atm_detail.amount=transfer_amount;
  atm_detail.balance=detail.balance;
  fwrite(&atm_detail,sizeof(atm_detail),1,fptr);
 }
}
fclose(fp);
fclose(fptr);
getch();
}