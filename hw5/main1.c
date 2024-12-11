#include <stdio.h>
int main(){
    int n=7;
    int i,j;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n+i-1;j++){
            if(j<=n-i){
                printf(" ");
            }else if((j - (n-i)) % 2 ==1){
                printf("%d",i);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
