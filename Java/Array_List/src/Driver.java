
import java.util.*;

public class Driver {

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        /**
         * Declaring an arraylist
         */
        ArrayList<Person> arrayList = new ArrayList<>();

        /**
         * Declare some persons
         */
        Person person = new Person("James", 40, 2001);
        Person person1 = new Person("James", 10, 2000);
        Person person2 = new Person("Jack", 90, 23);


        /**
         * Adding items to an arraylist
         */
        arrayList.add(person);
        arrayList.add(person1);
        arrayList.add(person2);
        arrayList.add(new Person("Jish", 2, 91));

        /**
         * Get from an arraylist by index position
         */
        Person dummy = arrayList.get(0);
        System.out.println(dummy);

        /**
         * Removing items from an arraylist
         */
        // NOT PREFERRED - will throw an error
//        for(Person p : arrayList) {
//            if(p.getName().equals("James")) {
//                arrayList.remove(p);
//            }
//        }

        // * PREFERRED WAY TO REMOVE FROM ARRAYLIST
//        Iterator<Person> it = arrayList.iterator();
//        while(it.hasNext()) {
//            Person p = it.next();
//            if (p.getName().equals("James")) {
//                it.remove();
//            }
//        }

        /**
         * When to use Comparable vs Comparator:
         * - judi onek simple sorting logic thake (1 tar upor basis e soring), use Comparable
         * - judi onek complex sorting logic thake (2 or more tar upor basis e soring), use Comparable
         *
         * Definitely judi Comparable ke bhalo moto structure korte paren you can sort on multiple basis (as we've seen in this current example)
         * Question is: eto pera niben ken -.- ?
         */
        // Will throw an error if the class to be sorted (Person class) has not implemented the Comparable interface
        // Default sorting, Ascending order of name, tie-breaker: descending order of age
        Collections.sort(arrayList);

        System.out.println("Default sorting:");
        for(Person p : arrayList) {
            System.out.println(p);
        }

        // Sort using DobComparator.
        // aage default sorting hobe, ui sorted list er upor Dob sorting hobe using the DobComparator class
        Collections.sort(arrayList, new DobComparator());
        System.out.println("Default sorting + DOB sorting:");
        System.out.println(arrayList);
//        for(Person p : arrayList) {
//            System.out.println(p);
//        }
    }
}
