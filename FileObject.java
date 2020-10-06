import java.io.*;
import java.util.StringTokenizer;

public class FileObject{
    //person class as per question
    static class Person{
        String name;    //like John
        float value;    //like 3.4
        Person(String n, float x){  //constructor to initialise
            name=n;
            value=x;
        }
        @Override
        public String toString() {  //toString method to display object in formatted manner
            return name + " " + value;
        }
    }
    //check whether string is float or not
    static boolean isFloat(String s){
        try {
            //if it throws exception, not float else float
            float f=Float.parseFloat(s);
            return true;
        } catch (Exception e) {
            return false;
        }
    }
    //this function create Person object from string and return it
    static Person convert(String line){
        //stringtokenizer will tokenize line in two strings separated by space
        StringTokenizer tokenizer=new StringTokenizer(line," ");    
        String a=tokenizer.nextToken();//reading first token
        String b=tokenizer.nextToken(); //reading second token
        if(isFloat(a)){     //if a is float, b will be name
            return new Person(b,Float.parseFloat(a));
        } //else a will be name and b will be value
        else return new Person(a,Float.parseFloat(b));
    }
    public static void main(String[] args) {
        //to read and write to files
        BufferedReader reader;
        FileWriter writer;
        try {
            //file.txt be the file given in question
            reader=new BufferedReader(new FileReader("file.txt"));
            //create a temp file to store correct formatting
            writer=new FileWriter(new File("temp.txt"));
            String line;
            //reading line by line till end of file
            while((line=reader.readLine())!=null){
                //converting line to object
                Person p=convert(line);
                //writing object to file
                writer.write(p.toString()+"\n");
            }
            writer.close(); //close temp.txt
            reader.close(); //close file.txt
            File oldfile=new File("file.txt");  //original file
            File newfile=new File("temp.txt");   //new file
            oldfile.delete();   //delete original
            newfile.renameTo(oldfile);  //rename temp to original file
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}