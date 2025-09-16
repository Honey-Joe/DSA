#include <stdio.h>

void main(){
    int i , j , k ,m , n ;
    printf("Enter the row and column of the array");
    scanf("%d %d" ,&m, &n);
    int a[m][n] , b[n][m] , c[m][m];
    printf("Enter the element of first array :");
    for(i=0 ; i< m ; i++){
        for(j = 0; j < n ; j++){
            printf("Enter the element: ");
            scanf("%d" , &a[i][j]);
        }
    }
    printf("Enter the element of second array :");
    for(i=0; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("Enter the element: ");
            scanf("%d" , &b[i][j]);
        }
    }

    printf("Multiplication of array A and Array b");

    for(i=0 ; i < m ; i++){
        for(j=0; j < m ; j++){
            c[i][j] = 0;
            for(k = 0 ; k<n ; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    for(i=0;i<m ; i++){
        for(j = 0 ; j < n ; j ++  ){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
 

}