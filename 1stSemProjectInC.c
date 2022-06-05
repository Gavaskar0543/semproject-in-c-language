//Project
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct user{
    char phone[40];
    char ac[50];
    char password[50];
    float balance;
};
int main()
{ 
    struct user usr,usr1;
    int opt;
    FILE *fp;
    char filename[50],phonenumber[20],pword[40];
    char count = 'y';
    int choice;
    float amount;

    printf("\nwhat do you want to do?");
    printf("\n\n1.Register an account");
    printf("\n2.login to an account");

    printf("\n\nyour choice:");
    scanf("%d",&opt);

    if(opt==1)
       {
           system("cls");
           printf("enter account no:");
           scanf("%s",usr.ac);
           printf("enter your phone no:");
           scanf("%s",usr.phone);
           printf("enter your new password:");
           scanf("%s",usr.password);
           usr.balance=0;
           //storeing detials using user phone number to retrive user detials
           strcpy(filename,usr.phone);
           fp=fopen(strcat(filename,".dat"),"w");
           fwrite(&usr,sizeof(struct user),1,fp);
           if(fwrite !=0){
               printf("\n\nAccount succesfully registered");
           }else
           {
               printf("\n\nsomething went wrong please try again");
           }    
           fclose(fp);
          
       }
       if(opt == 2){
           system("cls");
           printf("phone number:");
           scanf("%s",phonenumber);
           printf("password:\t");
           scanf("%s",pword);
           strcpy(filename,phonenumber);
           fp=fopen(strcat(filename,".dat"),"r");
           if(fp== NULL){
               printf("\n Account number not registered");
           }
           else
           {

           fread(&usr,sizeof(struct user),1,fp);
           fclose(fp);
           if(!strcmp(pword,usr.password))
           {
             while(count== 'y')
             {
                 system("cls");
                 printf("\npress 1 to check balance");
                 printf("\npress 2 to deposit");
                 printf("\npress 3 to whithdraw");
                 printf("\npress 4 to tranfer");
                 printf("\npress 5 to change the password");
                 printf("\nyour choice:\t");
                 scanf("%d",&choice);
                 switch(choice)
                 {
                     case 1:
                     printf("\n your currnt balance is Rs.%.2f",usr.balance);
                     break;
                     case 2:
                     printf("\nenter the amount:\t");
                     scanf("%f",&amount);
                     usr.balance +=amount;
                     fp=fopen(filename,"w");
                     fwrite(&usr,sizeof(struct user),1,fp);
                     if(fwrite!= NULL) printf("\nsuccesfully deposited");
                     fclose(fp);
                     break;
                     case 3:
                       printf("\nenter the amount:\t");
                     scanf("%f",&amount);
                     usr.balance -=amount;
                     fp=fopen(filename,"w");
                     fwrite(&usr,sizeof(struct user),1,fp);
                     if(fwrite!= NULL) printf("\nyou have withdrawn Rs.%.2f",amount);
                     fclose(fp);
                     break;
                     case 4:
                     printf("\nplease enter the phone number to transfer :");
                     scanf("%s",phonenumber);
                     printf("\n please enter the amount to transfer:");
                     scanf("%f",&amount);
                     if(amount>usr.balance)printf("\nInsufficient balance");
                     else{
                         strcpy(filename,phonenumber);
                         fp=fopen(strcat(filename,".dat"),"r") ;
                         fread(&usr1,sizeof (struct user),1,fp);
                         fclose(fp);
                         fp=fopen(filename,"w");
                         usr1.balance+= amount;
                         fwrite(&usr1,sizeof(struct user),1,fp);

                         fclose(fp);
                         if(fwrite!= NULL)
                         {
                             printf("\nyou have sucessfully transfered Rs.%.2.f",usr.balance);
                             strcpy(filename,usr.phone);
                             fp=fopen(strcat (filename,".dat"),"w");
                             usr.balance -=amount;
                              fwrite(&usr1,sizeof(struct user),1,fp);
                              fclose(fp);         
                         
                         
                         }
                     }
                         break;
                     case 5:
                    printf("\nplease enter your new password");
                    scanf("%s",&pword);
                    fp=fopen(filename,"w");
                    strcpy(usr.password,pword);
                    fwrite(&usr,sizeof(struct user),1,fp);
                    if(fwrite != NULL)
                    {
                        printf("\npassword sucessfully changed");
                    }
                    break;
                    default:
                    printf("\ninvalid option");
                     

                 }

                 printf("\nDo you want to continue the transaction[y/n]\t");
                 scanf("%s",&count);
             }
           }
           else
           {
               printf("\ninvalid password");
           }
           }
       }

   return 0;
}