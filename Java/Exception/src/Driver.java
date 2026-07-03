import java.io.BufferedReader;
import java.io.FileReader;
import java.security.spec.RSAOtherPrimeInfo;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Driver {
//    public static void main(String[] args) {
//        Scanner s=new Scanner(System.in);
//        jump:
//        try{
//            int a=s.nextInt();
//            int b=s.nextInt();
//            if (b==1){
//                throw new CustomException();
//            }
//            int d=a/b;
//            System.out.println(d);
//
//        }
//        catch (Exception  e){
//            System.out.println(e.getMessage());
//        }
//
//        System.out.println("Hello");
//    }
public static void main(String[] args) {
    String filePath="/Users/mahmudulhasantopu/Desktop/GitHub/Exception/src/a.txt";
    try{
        BufferedReader reder=new BufferedReader(new FileReader(filePath));
    }catch (Exception e){
        System.out.println(e.getMessage());

    }
}
}
