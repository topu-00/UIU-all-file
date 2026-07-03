import java.util.PrimitiveIterator;

public class Library {
    private Location location;
    private Book[] NumberOfBooks = new Book[100];

    public Library(Location location) {
        this.location = location;
    }

    public Location getLocation() {
        return location;
    }

    public void setLocation(Location location) {
        this.location = location;
    }

    int BookIndex = 0;

    void AddBook(Book book) {
        this.NumberOfBooks[BookIndex] = book;
        BookIndex++;
    }

    void SeeAllBook() {
        for (int i = 0; i < BookIndex; i++) {
            System.out.println("==========================================");
            NumberOfBooks[i].PrintDetail();
        }
        System.out.println("==========================================");
    }
}
