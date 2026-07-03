import java.io.FileWriter;
import java.util.Formatter;

public class Des_list {
    public void add2(Record r){
        try{
            //FileWriter student2=new FileWriter("deans_list.txt",true);
            Formatter student_add2=new Formatter("deans_list.txt");
            student_add2.format("%d %s %.3f\r\n",r.id,r.name,r.GPA);
            student_add2.close();
        }
        catch (Exception e){
            System.out.println("Error Writing file");
        }
    }
}
