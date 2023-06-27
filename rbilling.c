#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct items{
  char item[20];
  float price;
  int qty;
  };

  struct orders{
   char customer[50];
   char date[50];
   int numofitem;
   struct items itm[50];
   };
  void generatebillheader(char name[50],char date[30]){
  printf("\n\n");
    printf("\t ADV.RESTURANT");
    printf("\n\t----------------");
    printf("\n Date:%s",date);
    printf("\nInvoice to : %s",name);
    printf("\n");
    printf("------------------------------------");
    printf("item\t\t");
    printf("Qty\t\t");
    printf("total\t\t");
    printf("\n-----------------------------");
    printf("\n\n");
    }

void generatebillbody(char item[30],int qty, float price){
printf("%s\t\t",item);
   printf("%d\t\t",qty);
   printf("%.2f\t\t",qty*price);
   printf("\n");
   }

void generatebillfooter(float total){
printf("\n");
float dis = 0.1*total;
float nettotal=total-dis;
float cgst = 0.09*nettotal,grandtotal=nettotal + 2*cgst;
printf("---------------------------------------------------\n");
printf("Sub Total\t\t\t%.2f",total);
printf("\nDiscount @10%.2f","%",dis);
printf("\n\t\t\t\t---------");
printf("\nNet Total\t\t\t%.2f",nettotal);
printf("\nCGST@9%s\t\t\t%.2f",cgst);
printf("\nsgst@9%s\t\t\t%.2f",cgst);
printf("\n-----------------------------------------");
printf("\n Grand total\t\t%.2f",grandtotal);
printf("\n-----------------------------\n");
}
int main(){
int opt,n;
struct orders ord;
struct orders order;
char savebill='y',conFlag ='y';
char name[50];
File *fp;
while(contFlag == 'y'){
system("clear");
float total =0;
printf("\t==============ADV. Resturanr==================");
printf("\n\nPlease select your preffered operation");
printf("\n\n1.Generate Invoice");
printf("\n2.Show all Invoice");
printf("\n3.Search Invoice");
printf("\n4.Exit");
printf("\n\n Your choice:\t");
scanf("%d",&opt);
fgetc(stdin);
switch(opt){
case 1:
       system("clearf");
       printf(\n Pleae enter the name of the coustmoer :\t);
       fgetc(ord.customer ,50,stdin);
       ord.customer[strlen(ord.customer)-1 = 0;
       strcpy(ord.date,__Date__);
       printf("\nPleae enter the number of the items:\t");
       scanf("%d",&n);
       ord.numofitem=n;
       for(int i=0;i<n;i++){
       fgetc(stdin);
       printf(\n\n");
       printf("please enter the item %d:\t",i+1);
       fgetc(ord.itm[i].itm,20,stdin);
       ord.itm[i].itm[strlen(ord.itm[i].itm)-1]=0;
       printf("please enter the quantity:\t");
       scanf("%d",&ord.itm[i].qty);
       printf("please enter the unit price :\t");
       scanf("%f",&ord.itm[i].price);
       total+= ord.itm[i]*ord.itm[i].price;
       }

       generatebillheader(ord.customer,ord.date);
       for(int i=0;i<ord.numofitem;i++){
       generatebillbody(ord.itm[i].itm,ord.itm[i].qty,ord.itm[i].price);
       }
       generatebillfooter(total);
       printf("\n Do you want to save the invoice[y/n]:\t");
       scanf("%s",&savebill);

       if(savebill =='y'){
       fp = fopen("Resturantbill.dat","a=");
       fwrite(&ord,sizeof(struct orders),1,fp);
       if(fwrite !=0){
       printf("\n successfully saved");
       }
       else{
       printf("\n Error saving");
       }
       fclose(fp);
       }
       break;
case 2:
       system("clear");
       fp = fopen("Resturantbill.dat,"r");
       printf("\n*******your previous invoice********8\n"):
       while(fread(&order,sizeof(struct orders),1,fp)){
       float tot = 0;
       generatebillheader(order.cudtomer,order.date);
       for(int i=0;i<order.numofitem;i++){
       generatebillbody(order.itm[i].itm,order.itm[i].qty,order.itm[i].price);
       tot+=order.itm[i].qty*order.itm[i].price;
       }
	generatebilfotter(tot);
	}
	fclose(fp);
	break;

case 3:
      printf("enter the name of the customer :\t");
      fget(name,50,stdin);
      name[strlen(name)-1] = 0;
      system("clear");
      fp = fopen("Restaurantbill.dat","r");
      printf("\t*******invoice of %s*******",name);
      while(fread(&order,sizeof(struct orders),1,fp)){
      float tot = 0;
      if(!strcmp(order.customer.name)){
      generatebillheader(order.customer,order.date);
      for(int i=0;i<order.numofitem;i++){
      generatebillbody(order.itm[i].itm,order.itm[i].qty,order.itm[i].price);
      tot+=order.itm[i].qty * order.itm[i].price;
      }
      generatebillfooter(tot);
      invoicefound = 1;
      }
      }
      if(!invoicefound){
      printf("Sorry the invoice for %s doesnot exists",name);
      }
      fclose(fp);
      break;

case 4:
       printf("\n\t\t Bye:)\n\n");
       exit(0);
       break;

default:
       printf("sorry invalid optoin");
       break;
       }
       printf("\ndo you want to perform another operation?[y/n]:\t");
       scanf("%s",&conFlag);
       }
       printf("\n\n\t\t bye bye :)\n\n");
       printf("\n\n");


       return 0;
       }