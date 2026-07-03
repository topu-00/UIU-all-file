import java.util.Comparator;

public class DobComparator implements Comparator<Person> {
    @Override
    public int compare(Person o1, Person o2) {
        // same logic
        return o1.dob - o2.dob;
    }
}
