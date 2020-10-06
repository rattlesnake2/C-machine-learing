#include<stdio.h>
#include<math.h>
//calculate bn coefficients
float calcbn(float n){
    return (2.0/M_PI)*((-cos(n*M_PI)/n)-(-cos(n*0.0)/n))  ;
}
//clculate sum S(x)
float calcsx(int n,float bn[],float x){
    float sum=0;
    for(int i=1;i<=n;i++){
        sum+=(bn[i]*sin(i*x));
    }
    return sum;
}
int main(){
    //n=100 terms
    const int n=100;
    float bn[n+1];      //store b coefficients
    //calcuate coefficients
    for(int i=1;i<=n;i++){
        bn[i]=calcbn(i);
    }
    //simple input and output
    float x=0;
    printf("Enter the value of x (-1 to stop):  ");
    scanf("%f",&x);
    while(x!=-1){
        printf("S(x) (at x=%f) = %f\n",x,calcsx(n,bn,x));
        printf("Enter the value of x (-1 to stop):  ");
        scanf("%f",&x);
    }
}