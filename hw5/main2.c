#include <stdio.h>
#include <math.h>

int main(){
    double pi=4.0f;
    double term;
    int x;
    
    for(x=1; ;x++){
        term=4.0*pow(-1,x)/(2*x+1);
        pi += term;
        
        if(fabs(pi-3.14159)<0.000005){
        break;
        }
    }
    
    printf("計算出pi= %.5f\n",pi);
    printf("最小的x＝%d\n",x);
    
    return 0;
}
