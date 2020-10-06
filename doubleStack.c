#include<stdio.h>

//push into red or green or c=central node
//using pointers because we want to update values in main
void push(int *c,int red[],int green[],int *redsize,int *greensize){
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    //c not initialized
    if((*c==-1))
        *c=num;
    //even
    else if(num%2==0){
        red[*redsize]=num;
        (*redsize)++;
    }
    //odd
    else{
        green[*greensize]=num;
        (*greensize)++;
    }
}
//popping from red
void pop_red(int *redsize){
    if(*redsize>0)
        (*redsize)--;
}
//popping from green
void pop_green(int *greensize){
    if(*greensize>0)
        (*greensize)--;
}
//printing whole list
void print(int *c,int red[],int green[],int *redsize,int *greensize){
    //first print green
    if(*greensize>0){
        for(int i=*greensize-1;i>=0;i--)
            printf("%d<-",green[i]);
    }
    //central node
    if(*c!=-1){
        printf("%d",*c);
    }
    //red
    if(*redsize>0){
        for(int i=0;i<*redsize;i++)
            printf("->%d",red[i]);
    }
    printf("\n");
}
int main(){
    //initialize variable and print menu
    int c=-1;
    int red[100];
    int green[100];
    int redsize=0;
    int greensize=0;
    printf("1.Push\n2.Pop Red\n3.Pop Green\n4.Print\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    while(choice>=0 && choice<=4){
        if(choice==1){  //push
            push(&c,red,green,&redsize,&greensize);
        }
        else if(choice==2){     //pop from red
            pop_red(&redsize);
        }
        else if(choice==3){     //pop from green
            pop_red(&greensize);
        }
        else if(choice==4)      //print
            print(&c,red,green,&redsize,&greensize);
        printf("Enter your choice: ");
        scanf("%d",&choice);

    }
}