/**
 * Implement Person with Comparable for sorting
 */
public class Person implements Comparable<Person>{
    String name;
    int age;
    int dob;

    public Person(String name, int age, int dob) {
        this.name = name;
        this.age = age;
        this.dob = dob;
    }

    /**
     * Override the compareTo method
     * the (Person o) parameter stands for the "other" object to which the current object "this" is being compared
     * returns > 0 or == 0 or < 0
     * Judi returns > 0: then current object (this) other object (o) er theke boro
     * Judi returns < 0: then current object (this) other object (o) er theke choto
     * Judi returns 0: duijon shoman
     *
     * Ascending trick: current object (this) ke aage rakhben and other object (o) ke pore rakhben
     * Descending trick: other object (o) ke aage rakhben and current object (this) ke pore rakhben
     *
     *
     * Dhoren name wise ascending order e shajabo. then judi name same hoi, age wise descending order e shajabo
     */
    @Override
    public int compareTo(Person o) {
        // this ta aage, o ta pore. So ascending order of name
        int nameComparison = this.name.compareTo(o.name);

        // judi name same hoi
        if (nameComparison == 0) {
            // o ta aage, and this ta pore. So descending order of age
            return o.age - this.age;
        }

        // else if name not same, tahole return whatever name er comparision return korto
        return nameComparison;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", dob=" + dob +
                '}';
    }
}

