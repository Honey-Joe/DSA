#include <stdio.h>
void  main(){
  void reverse(){
    int n,i;
    printf("Enter a number of  elements in an array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
      printf("Enter a number ");
      scanf("%d",&a[i]);
    }
    printf("The elements in an array");
    for(i=0;i<n;i++){
      printf("%d \n",a[i]);
    }
    printf("The Reverse of the array:");
    for(i=n-1 ; i>=0 ; i--){
      printf("%d \n",a[i]);
    }
  }
  //reverse();
  
  void second(){
    int n,i;
    printf("Enter a number of  elements in an array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
      printf("Enter a number ");
      scanf("%d",&a[i]);
    }
    printf("The elements in an array");
    for(i=0;i<n;i++){
      printf("%d \n",a[i]);
    }
    int first = a[0];
    int second = a[0];
    for(i=1 ; i<n ; i++){
      if(a[i] > first){
        second = first;
        first = a[i];
      }
      else if(a[i] > second){
        second = a[i];
      }
    }
    printf("The second largest number in the array : %d \n", second);
  }
  //second();
  
  void frequency(){
    int n,i;
    printf("Enter a number of  elements in an array: ");
    scanf("%d",&n);
    int a[n];
    int freq[100];
    for(i=0;i<100;i++){
      freq[i]=0;
    }
    for(i=0;i<n;i++){
      printf("Enter a number ");
      scanf("%d",&a[i]);
    }
    printf("The elements in an array");
    for(i=0;i<n;i++){
      printf("%d \n",a[i]);
    }
    
    for( i = 0 ; i < n ; i++){
      freq[a[i]]++;
    }
    printf("Frequency");
    for(i = 0; i<100 ; i++){
    if(freq[i]!=0)
      printf("%d  : %d \n", i , freq[i]); 
    }
  }
  //frequency();
  
  void linear(){
    int n,i;
    printf("Enter a number of  elements in an array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
      printf("Enter a number ");
      scanf("%d",&a[i]);
    }
    printf("The elements in an array");
    for(i=0;i<n;i++){
      printf("%d \n",a[i]);
    }
    int s;
    printf("Enter a value to search in the array: ");
    scanf("%d", &s);
    int flag = 0;
    for(i=0; i < n ; i++){
      if(s== a[i]){
        printf("The Search element is %d in the %d position", a[i],i);
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      printf("The element is not found ");
    }
  }
  linear();
}
  
