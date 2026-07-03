public class Teacher {
    String name;
    int age;
    int id;

    void setInfo(String Name, int Age, int ID) {
        name = Name;
        age = Age;
        id = ID;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("ID: " + id);
    }
}
