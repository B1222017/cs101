#include <stdio.h>
#include <stdlib.h>
void print_sp(int i,int n){
	for(int sp=0;sp<=0-i;sp++){
		printf(" ");
	}
}

void print_num(int n){
	for(int i=0;i<=n;i++){
		printf("%d",n);
	}
	printf("\n");
}

int main(){
	int rows=6;
	for(int i=0;i<=rows;i++){
		print_sp(i,rows);
		print_num(i);
	}
	return 0;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}
