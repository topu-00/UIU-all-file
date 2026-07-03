import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.Iterator;
import java.util.Scanner;

public class FileDemo {
    public static void main(String[] args) {
        ArrayList<String> student=new ArrayList<>();
        File file1=new File("data.txt");
        File file2=new File("data2.txt");
        try{
            file1.createNewFile();
            file2.createNewFile();
            System.out.println("File are create");
        }
        catch (Exception e){
            System.out.println("File not create");
        }

        try {
            int id;
            String Name;
            Scanner input=new Scanner(System.in);
            FileWriter writer=new FileWriter("data.txt",true);
            Formatter form=new Formatter(writer);
//            for (int i=0;i<3;i++){
//                id=input.nextInt();
//                Name=input.next();
//                form.format("%d %s\r\n",id,Name);
//            }
//            form.format("%d %s\r\n",1355,"MaxM");
//            form.format("%d %s\r\n",1111,"MaxM");


            form.close();
        }
        catch (Exception e){
            System.out.println("File not exist");
        }
        try
        {
            Scanner in=new Scanner(file1);
            while (in.hasNext()){
               // int n=in.nextInt();
                String s=in.nextLine();
                student.add(s);
                //System.out.println(s);
            }
            in.close();
        }
        catch (Exception e){
            System.out.println("Error");
        }
        Name[] name = new Name[0];
        for (String list : student ){
            String[] detail=list.split(" ");
            name[0]=new Name(Integer.parseInt(detail[0]),detail[1]);
            System.out.println(list);
        }
        System.out.println();
        Iterator it=student.iterator();
    }
    public static class Name{
        int id;
        String name;

        public Name(int id, String name) {
            this.id = id;
            this.name = name;
        }
    }
}
