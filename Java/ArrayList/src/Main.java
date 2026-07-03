import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        //System.out.println("Enter N: ");
        int n=in.nextInt();
        ArrayList<Integer>[]list =new ArrayList[n];
        for (int i=0;i<n;i++){
            list[i]=new ArrayList<>();
            //System.out.println("Enter K: ");
            int k=in.nextInt();
            for (int j=0;j<=k;j++){
                if (j==0){
                    list[i].add(k);
                }
                else {
                    list[i].add(in.nextInt());
                }

            }
        }
        for (int i=0;i<n;i++){
            int l=in.nextInt();
            int I=in.nextInt();
            try{
                System.out.println(list[l-1].get(I-1));
            }
            catch (Exception e){
                System.out.println("ERROR!");
            }

        }
    }
}
