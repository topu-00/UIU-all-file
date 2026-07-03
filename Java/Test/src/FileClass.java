import java.io.File;
import java.io.FileWriter;
import java.util.Formatter;
import java.util.Scanner;

public class FileClass {
    public static void main(String[] args) {
        //Create File
        File file=new File("data.txt");
        try{
            file.createNewFile();
        }
        catch(Exception e){
            System.out.println("Error");
        }


        // Write a file

        Scanner in=new Scanner(System.in);
        try{
            String  s=in.nextLine();
            FileWriter file_writer=new FileWriter("data.txt",true);
            Formatter fileWrite=new Formatter(file_writer);
            fileWrite.format("%s\n\r",s);
            fileWrite.close();
        }
        catch (Exception e){
            System.out.println("Error");
        }

    }
}
