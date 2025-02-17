#include<stdio.h>
#include<string.h>
int main(){
    int id;
    char name[255];
    float salary;
    int attendance;
    printf("enter id:");
    scanf("%d",&id);
    printf("enter name:");
    scanf("%s",name);
    printf("enter salary:");
    scanf("%f",&salary);
    printf("enter number of days worked:");
    scanf("%d",&attendance);
    
    float bonus=0.0f;
    float gross_salary=0.0f;
    char category[50]="good";

    
    if (attendance >25){
        bonus=(salary/100.0f)*5.0f;
    }else if(attendance<10){
        bonus=(-1.0f*((salary/100.0f)*50.0f));
    }
        gross_salary=(salary+bonus);
        
        
    if(attendance>25){
            strcpy(category,"excellent");
     }else if(attendance<15){
            strcpy(category,"Need improvement");
    }
     printf("payroll details:\n");
     printf("Id:%d\n",id);
     printf("Name:%s\n",name);
     printf("Basic salary:%2.f\n",salary);
    if (bonus>0){
     printf("\tbonus:%.2f\n",bonus);
    }
     printf("final salary:%.2f",gross_salary);
     printf("employee performance category:%s\n",category);
     return 0;
    }   
