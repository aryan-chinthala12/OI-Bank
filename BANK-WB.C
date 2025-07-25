// A binary bank project to enter accounts and balence amount..
#include<stdio.h>
#include<conio.h>
struct customer
{
  int accno;
  char name[20];
  float balance;

};
void main()
{
  struct customer oi;
  FILE *fp;
  char fname[50];
  clrscr();
  printf("\nEnter any file to store these with ending with .dat : ");
  gets(fname);
  fp=fopen(fname,"wb");
  printf("\n...Welcome to OI Bank...");
  printf("\nPress 0 at account no. to stop.\n");

  for(; ;)
  {
     printf("\nEnter your Account No.: ");
     scanf("%d",&oi.accno);
     if(oi.accno==NULL)
	break;
     fflush(stdin);
     printf("\n\tEnter your name : ");
     gets(oi.name);
     printf("\nEnter your balance amount : ");
     scanf("%f",&oi.balance);
     fwrite(&oi,sizeof(oi),1,fp);

  }
  printf("\nOI Bank.dat file is succesfully created...!");
  fclose(fp);
  getch();
}