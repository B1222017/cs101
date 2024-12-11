#include <stdio.h>

int main(){
    
    for(int i=1;i<=81;i++){
        int row = (i-1)/9+1;
        int col = (i-1)%9+1;
        
        printf("%d*%d=%2d ",row, col, row*col);
        if(col == 9)printf("\n");
    }
    return 0;
}
