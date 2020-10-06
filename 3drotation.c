#include<stdio.h>

void multiply(float mat1[][4],float mat2[][4],float out[][4],int m,int n,int o){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        printf("%f ",mat2[i][j]);
        printf("\n");
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            out[i][j]=0;
            for(int k=0;k<n;k++){
                out[i][j]+=(mat1[i][k]*mat2[k][j]);
            }
        }
    }
}
void rotate(float x[],float y[],float z[], float tx,float ty,float tz, int n){
    float rx[4][4]={{1,0,0,0},
                {0,cos(tx),-sin(tx),0},
                {0,sin(tx),cos(tx),0},
                {0,0,0,1}};
    float ry[4][4]={{cos(ty),0,-sin(ty),0},
                {0,1,0,0},
                {sin(ty),0,cos(ty),0},
                {0,0,0,1}};
    float rz[4][4]={{cos(tz),-sin(tz),0,0},
                {sin(tz),cos(tz),0,0},
                {0,0,1,0},
                {0,0,0,1}};
    float temp[4][4],rot[4][4],final[4][1];
    multiply(ry,rx,temp,4,4,4);
    multiply(rz,temp,rot,4,4,4);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        printf("%f ",rot[i][j]);
        printf("\n");
    }
    for(int i=0;i<n;i++){
        float cord[4][1]={{x[i]},{y[i]},{z[i]},{1}};
        multiply(rot,cord,final,4,4,1);
        printf("Initial position:(%f,%f,%f);  Final position:(%f,%f,%f)\n",x[i],y[i],z[i],final[0][0],final[1][0],final[2][0]);
    }

}
int main(){
    float tx,ty,tz;
    printf("Enter the angle of rotation along X,Y,Z(in degrees)\n");
    scanf("%f%f%f",&tx,&ty,&tz);
    tx=3.14/180*tx;
    ty=3.14/180*ty;
    tz=3.14/180*tz;
    
    int n;
    printf("Enter the number of points: ");
    scanf("%d",&n);
    float x[100],y[100],z[100];
    for(int i=0;i<n;i++){
        printf("Enter the cordinates(x,y,z): ");
        scanf("%f%f%f",&x[i],&y[i],&z[i]);
    }
    rotate(x,y,z,tx,ty,tz,n);
}