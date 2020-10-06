import java.util.Scanner;

public class BubbleSort{

    //ascending order
    static void asc(int []list){
        //for i=1 to len(list)
        for(int i=0;i<list.length;i++){
            //for j=i+1 to len(list)
            for(int j=i+1;j<list.length;j++){
                //swap list[i],list[j] using temp
                if(list[i]>list[j]){
                    int temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
            }
        }
    }

    //descending order
    static void desc(int []list){
        //for i=1 to len(list)
        for(int i=0;i<list.length;i++){
            //for j=i+1 to len(list)
            for(int j=i+1;j<list.length;j++){
                //swap list[i],list[j] using temp
                if(list[i]<list[j]){
                    int temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
            }
        }
    }


    public static void main(String[] args) {
        //list in random order
        int []list={64, 25, -12, -22, 11, 1,2,44,3,122, 23, 34};
        System.out.println("Enter the order: 1 for Ascending and 2 for Descending");
        //input choice using scanner
        Scanner sc=new Scanner(System.in);
        int choice=sc.nextInt();
        //switch
        switch(choice){
            case 1:
                //call asc and sort list ascending and print
                asc(list);
                System.out.println("List in Ascending order:");
                for(int i:list)
                    System.out.print(i+" ");
                break;
            case 2:
            //call asc and sort list descending and print
                desc(list);
                System.out.println("List in Descending order:");
                for(int i:list)
                    System.out.print(i+" ");
                break;
        }
        sc.close();
    }
}