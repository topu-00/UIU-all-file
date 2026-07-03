import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter How Many Book You Want To Add: ");
        int n = in.nextInt();
        in.nextLine();
        Location location = new Location("Dhaka");
        Library library = new Library(location);
        for (int i = 0; i < n; i++) {
            System.out.println();
            System.out.println("Book Number: " + "(" + (i + 1) + ")");
            System.out.println();
            System.out.print("Enter Author Name: ");
            String AuthorName = in.nextLine();
            System.out.print("Enter Phone Number: ");
            String phone = in.nextLine();
            System.out.print("Enter Email: ");
            String email = in.nextLine();
            System.out.print("Enter Title: ");
            String title = in.nextLine();
            System.out.print("Enter ISBN: ");
            long isbn = in.nextLong();
            in.nextLine();
            Author author = new Author(AuthorName, phone, email);
            Book book = new Book(title, isbn, author);
            library.AddBook(book);
        }
        System.out.println();
        library.SeeAllBook();
    }
}
