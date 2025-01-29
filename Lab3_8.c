# include <stdio.h>
int main () {
    int n=5;
    int a[5]={5,4,3,2,1};
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    } 
}
