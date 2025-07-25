//Showing the bank accounts in read binary way..
#include<stdio.h>
#define SPACE(k) for(j=1;j<=k;j++) fprintf(stdout," ");
#define LINE for(j=1;j<=80;j++)  fprintf(stdout,"-");
struct customer
{
   int accno;
   char name[20];
   float balance;

};
int main()
{
  struct customer oi;
  int i=1,j,k;
  char fname[30];
  FILE *fp;
  printf("\nEnter your file name : ");
  gets(fname);
  fp=fopen(fname,"rb");
  if(fp==NULL)
  {
    printf("\nFile not found ...");
    getch();
    return 0;
  }
  clrscr();
  SPACE(22);
  fprintf(stdout,"\nOI Bank Customer Report\n");
  LINE;
  fprintf(stdout,"\n%10s","S.no");
  fprintf(stdout,"%25s","Account no");
  fprintf(stdout,"%25s","Name");
  fprintf(stdout,"%12s","Balance");
  fprintf(stdout,"\n");
  LINE;
  fread(&oi,sizeof(oi),1,fp);
  while(!feof(fp))
  {
    fprintf(stdout,"\n%10d",i);
    fprintf(stdout,"%25d",oi.accno);
    fprintf(stdout,"%25s",oi.name);
    fprintf(stdout,"%12.2f",oi.balance);

    fread(&oi,sizeof(oi),1,fp);
  }
  fprintf(stdout,"\n");
  LINE;
  fclose(fp);
  getch();
  return 0;
}
