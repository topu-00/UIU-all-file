public class Main {
    public static void main(String[] args) {
        Teacher t1; //Declare object;[Teacher is a Class && t1 is object];
        t1 = new Teacher(); //Create Object;
        // Initialize Object Variable ⬇️;
        t1.name = "Michael";
        t1.age = 20;
        t1.id = 164;
        System.out.println(t1.name);
        System.out.println(t1.age);
        System.out.println(t1.id);

        Teacher t2 = new Teacher();//Declare and Create Object;
        t2.name = "Michael";
        t2.age = 20;
        t2.id = 164;
        System.out.println(t2.name);
        System.out.println(t2.age);
        System.out.println(t2.id);
    }
}
