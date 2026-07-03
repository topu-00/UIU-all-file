import java.io.FileWriter;
import java.util.Formatter;

public class Add_Student_onFile {
    public void add(Record r){
        try{
            FileWriter student=new FileWriter("Student.txt",true);
            Formatter student_add=new Formatter(student);
            student_add.format("%d %s %.3f\r\n",r.id,r.name,r.GPA);
            student_add.close();
        }
        catch (Exception e){
            System.out.println("Error Writing file");
        }
    }
}
