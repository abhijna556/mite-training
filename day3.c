#include <stdio.h>
void displayAges(short int* ages,int length,int index){
   if(index >= length){
       return;
   }
  printf("%d",ages[index]);
  displayAges(ages,5,index +1);
}
  void travelbackwardAges(short int* ages,int length,int index){
    if(index >= length){
    return;
    }   
    travelbackwardAges(ages,5,index+1);
    printf("%d",ages[index]);
}
int main()
{
    short int ages[]={45,42,14,20,70};
    displayAges(ages, 5,0);
    printf("\n");
    travelbackwardAges(ages,5,0);
    return 0;
}
    
