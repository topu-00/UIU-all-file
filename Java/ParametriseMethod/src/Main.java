public class Main {
    public static void main(String[] args) {
        Teacher t1;//Declare Object ;
        t1 = new Teacher();//Create Object;
        t1.setInfo("Michael", 20, 164);//Call Parametrise Method;
        t1.display();//Call Method;
        Teacher t2 = new Teacher();//Declare and Create Object;
        t2.setInfo("Max", 22, 165);//Call Parametrise Method;
        t2.display();//Call Method; 
    }
}
