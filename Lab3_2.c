# include <stdio.h>
int main () {
    int n,avg,multi;
    printf("Enter n for the square matrix:");
    scanf("%d",&n);
    int a[n][n],b[n][n];
    int crr[3][3]={1,2,2,
                 3,3,2,
                 3,4,1};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            scanf("%d",&a[i][j]);
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            printf("%d",a[i][j]);
            b[i][j]=a[i][j];
        }
     printf("\n");
    }
    printf("\n");

    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            int sum=0;

            for(int r=0;r<3;r++){
                for(int c=0;c<3;c++){
                    sum+=a[i+r][j+c]*crr[r][c];  
                }
            }
            avg= sum/9;
            b[i+1][j+1]=avg;

        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            printf("%d",b[i][j]);

        }
         printf("\n");
    }
return 0;
}
