#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string fileName = "grades.txt";
    ifstream fin;
    fin.open(fileName);
    if (!fin)
    {
        cout << fileName << " is not found. " << endl;
        system("pause");
        exit(0);
    }

    int studentID;
    double exam1;
    double exam2;
    double exam3;
    int numOfStudent[3]={0,0,0};        //store number of student for each exam
    double examSum[3]={0,0,0};      //store sum of grade for each exam
    double examMin[3]={1000,1000,1000}; //min grade for each exam
    double examMax[3]={0,0,0};      //max grade for each exam

    //read file and store stats in the array
    while (fin >> studentID >> exam1 >> exam2 >> exam3)
    {
        if (exam1 != 0)     //exam1
        {
            examSum[0] += exam1;
            numOfStudent[0]++;
            examMax[0] = std::max(examMax[0], exam1);
            examMin[0] = std::min(examMin[0], exam1);
        }
        if (exam2 != 0)     //exam2
        {
            examSum[1] += exam2;
            numOfStudent[1]++;
            examMax[1] = std::max(examMax[1], exam2);
            examMin[1] = std::min(examMin[1], exam2);
        }
        if (exam3 != 0)     //exam3
        {
            examSum[2] += exam3;
            numOfStudent[2]++;
            examMax[2] = std::max(examMax[2], exam3);
            examMin[2] = std::min(examMin[2], exam3);
        }
        //cout<<studentID<<" "<<exam1<<" "<<exam2<<" "<<exam3<<endl;
    }
    int examnum;
    //infinite loop
    while (1)
    {
        cout << "Which exam would you like to view statistics of?: ";
        cin >> examnum;

        //invalid choice
        while (examnum < 1 || examnum > 3)
        {
            cout << "Please enter a valid exam to view: ";
            cin >> examnum;
        }
        //printing stats
        cout<<"Number Of student who took the exam: "<<numOfStudent[examnum-1]<<endl;
        cout<<"Exam Average: "<<examSum[examnum-1]/numOfStudent[examnum-1]<<endl;
        cout<<"Minimum grade: "<<examMin[examnum-1]<<endl;
        cout<<"Maximum grade: "<<examMax[examnum-1]<<endl<<endl;
        
    }
}