#include <stdio.h>
void readDetails(float* p_salary,int* p_score,int* p_experience){
  printf("enter salary:");
  scanf("%f",p_salary);
  
  printf("enter credit score:");
  scanf("%d",p_score);
  
  printf("enter experience:");
  scanf("%df",p_experience);
} 
  int isEligible(float salary,int score,int experience){
    return((salary>=30000) && (score>=750) && (experience>=2));
}
int main()
{
   float salary;
   int score;
   int experience;
   readDetails(&salary,&score,&experience);
   if(isEligible(salary,score,experience)){
   printf("loan approved");
   }
   else{
       printf("loan rejected");
   }
    return 0;
}
