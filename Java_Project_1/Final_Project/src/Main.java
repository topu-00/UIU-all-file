// Sadika Binti Noor(0112330453)
//A.S.M Absaruzzaman(0112330445)
// Mahmudul Hasan Topu(0112330164)


import java.io.File;
import java.io.FileWriter;
import java.util.Formatter;

public class Main {
    public static void main(String[] args) {
      MainFrame m=  new MainFrame();
        File Output =new File("output.txt");
        try{
            Output.createNewFile();
        }
        catch (Exception e){
            System.out.println("Error Creating File");
        }
    }
}
