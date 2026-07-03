public class test {
    public static void main(String[] args) {
        int i;
        int c=5;
        int b=2;
        int a[]=new int[5];
        for (i=10;i>0;b--)
        try{
            a[i--]=c/b;
            System.out.println("a");
        }catch (ArithmeticException e){
            i--;
            System.out.println("b");
        }
        catch (ArrayIndexOutOfBoundsException ie){
            i--;
            System.out.println("c");
        }
    }
}
