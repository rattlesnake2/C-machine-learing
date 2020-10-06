import java.util.ArrayList;

public class ArrayListJava{
   public static void main(String[] args) {
       ArrayList<Character>list=new ArrayList<>();   //1) creating new list
       list.add('|');       //2)   add character to list
       list.add('<');
       list.add('\\');      // '\' is invalid symbol
       list.add('/');
       list.add('>');
       System.out.print("List: [ ");        //3)   print list
       for (int i=0;i<list.size();i++) {
            System.out.print(list.get(i));
            if(i!=list.size()-1)
               System.out.print(",");   //dont print comma after last element
       }
       System.out.println(" ]");
       list.remove(list.size()-1);      //4)remove last element
       System.out.println("number of elements in list: "+list.size());      //5) size of list
       list.add('+');   //6) add character
       list.add(1, '-');    //7) add character at position 1
       System.out.print("List: [ ");    //8) print list
       for (int i=0;i<list.size();i++) {
            System.out.print(list.get(i));
            if(i!=list.size()-1)
               System.out.print(",");
       }
       System.out.println(" ]");
       
   } 
}