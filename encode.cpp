#include<iostream>
using namespace std;

//encode message
string encode(string s,int key){
    int len=s.length(); //length
    for(int i=0;i<len;i++){
        s[i]+=(key*3);  //add key*3 to ascii value
    }
    return s;
}
//decode messgae
string decode(string s,int key){
    int len=s.length();
    for(int i=0;i<len;i++){
        s[i]-=(key*3);  //subtrat key*3 from ascii value
    }
    return s;
}
int main(){
    //menu
    cout<<"1. Encrypt Message\n";
    cout<<"2. Decrypt Message\n";
    cout<<"3. Exit\n";
    cout<<"Enter choice.. ";
    int choice;
    cin>>choice;
    while(choice==1||choice==2)
    {    if(choice==1){ //encoding
            cout<<"Enter message to encrypt and key\n";
            //input message and key
            string message;
            int key;
            cin.ignore();
            getline(cin,message);
            cin>>key;
            cout<<encode(message,key)<<endl;
        }
        else{   //decoding
            cout<<"Enter message to decrypt and key\n";
            //input message and key
            string message;
            int key;
            cin.ignore();
            getline(cin,message);
            cin>>key;
            cout<<decode(message,key)<<endl;
        }
        cout<<"Enter choice.. ";
        cin>>choice;
    }
}