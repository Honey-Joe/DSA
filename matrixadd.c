#include<stdio.h>

void main(){
    int m , n ,i , j ;
    printf("Enter the row and coloumn of matrix");
    scanf("%d" , &m);
    n = m;
    int a[m][n];
    int b[m][n];
    int c[m][n];
    printf("Enter the elements of the first array");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    // printf("Enter the elements of the second array");
    // for(i=0;i<m;i++){
    //     for(j=0;j<n;j++){
    //         scanf("%d",&b[i][j]);
    //     }
    // }

    for(i = 0 ; i < m ; i++ ){
        for(j =0 ; j< n ; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // for(i = 0 ; i < m ; i++ ){
    //     for(j =0 ; j< n ; j++){
    //         printf("%d ",b[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("Sum of two array:");
    // for(i = 0 ; i < m ; i++ ){
    //     for(j = 0 ; j< n ; j++){
    //         c[i][j] = a[i][j] + b[i][j];
    //     }
    //     printf("\n");
    // }
    int temp = 0;
    for(i = 0 ; i < m ; i++){
        for(j = i+1; j< n ; j++){
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    // for(i = 0 ; i < m ; i++ ){
    //     for(j =0 ; j< n ; j++){
    //         printf("%d ", c[i][j]);
    //     }    
    //     printf("\n");
    // }
     for(i = 0 ; i < m ; i++ ){
        for(j =0 ; j< n ; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    


    
}