import java.util.Comparator;

public class Compare implements Comparator<Record> {

    @Override
    public int compare(Record o1, Record o2) {
        return (int)(o2.GPA-o1.GPA);
    }
}
