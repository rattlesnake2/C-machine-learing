#include<iostream>
using namespace std;

//this function will shift array to delete element
bool moveArrayElements(string dino[],int n,string dinosaur){
    //find position of dinosaur to be removed
    int i=0;
    while(i<n && dino[i]!=dinosaur)
        i++;
    //if position not found
    if(i==n)
        return false;
    //position found
    //shift all elements from postion (i+1 to n-1) to (i to n-2)
    for(int j=i;j<n-1;j++)
        dino[j]=dino[j+1];
    return true;
}

int deleteDinosaur(string dino[],int n){
    //print list
    cout<<"The following is a list of all the dinosaurs you take care of:\n";
    for(int i=0;i<n;i++)
        cout<<dino[i]<<endl;
    //take input
    cout<<"What Dinosaur do you wish to remove?\nDINOSAUR NAME:";
    string dinosaur;
    cin>>dinosaur;
    //call function
    bool result=moveArrayElements(dino,n,dinosaur);
    //print result
    if(result){
        cout<<"You have removed "<<dinosaur<<endl;
        return n-1;
    }
    cout<<"Dinosaur failed to remove\n";
    return n;
}

int main(){
    //sample array
    string dino[]={"T-rex","Triceratops","Dinosouras","BananaSouras","Mangosouras"};
    int n=5;
    //printing choice
    cout<<"What would you like to do?\n";
    cout<<"1.   Enter some Dinosaurs.\n";
    cout<<"2.   Delete a Dinosaur.\n";
    cout<<"3.   List/Print Dinosaurs.\n";
    cout<<"4.   Print Statistics on Dinosaur Cost.\n";
    cout<<"5.   End Program.\n";
    cout<<"Enter 1, 2, 3, 4, or 5.\n";
    int choice;
    cin>>choice;
    //loop for choices
    while(choice){
        switch (choice)
        {
            case 1: //function to insert dinosaur
                break;
            case 2:
                n=deleteDinosaur(dino,n);
                break;
            case 3: //function to print dinosaur
                break;
            case 4: //print stats
                break;
            case 5: 
                return 0;
                break;
            
            default:
            break;
        }
        //asking for choice
        cout<<"Enter choice: ";
        cin>>choice;
    }
}