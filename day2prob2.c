#include<stdio.h>

int main(){
    int productCount;
    int weight;
    
    printf("enter number of products");
    scanf("%d",&productCount);
    int acceptedCount=0;
    int rejectedCount=0;
    for(int i=1;i<=productCount;i++){
    printf("enter weights(in grams):");
    scanf("%d",&weight);
    if(weight>=950 && weight <=1058){
        acceptedCount++;
    }else{
        rejectedCount++;
    }
    }
    printf("acceptd products:%d\n",acceptedCount);
    printf("rejected products:%d\n",rejectedCount);
    
    return 0;
}
    
