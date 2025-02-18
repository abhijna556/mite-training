#include<stdio.h>
#include<string.h>
int main() {
    int vehicleCount;
    char vehicleType[10];
    
    printf("enter number of vehicle:");
    scanf("%d", &vehicleCount);
    
    float collection = 0;
    for(int i=1;i<=vehicleCount;i++){
        printf("enter vehicle type:");
        scanf("%s",vehicleType);
        if(strcmp(vehicleType,"car")==0){
            collection += 50;
        }else if(strcmp(vehicleType,"Truck")==0){
            collection +=100;
        }else if(strcmp(vehicleType,"Bike")==0){
            collection += 20;
        }
    }
    printf("Total Toll collection:%.2f\n",collection);
    
    return 0;
}
    
    
