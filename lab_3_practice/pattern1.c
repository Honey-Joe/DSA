#include <stdio.h>

void main(){
    printf("Enter the no of rows");
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for (int  k =0 ; k < n-i-1 ; k++){
            printf(" ");
        }
        char ch = 'A';
        for(int j=0;j<=i;j++){
            printf("%c " , ch++);
        }
        printf("\n");
    }

    for (int i = n; i > 0; i--) {
        for (int s = 0; s < n - i; s++) printf(" ");
        char ch = 'A';
        for (int j = 0; j < i; j++) {
            printf("%c ", ch++);
        }
        printf("\n");
    }

    for(int i=n ; i>=1 ; i--){
        for(int j=0 ; j <= i-1; j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i = 0 ; i < n ; i++){

    }
}