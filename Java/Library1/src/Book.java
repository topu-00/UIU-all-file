public class Book {
    private String title;
    private long isbn;
    private Author author;

    public Book(String title, long isbn, Author author) {
        this.title = title;
        this.isbn = isbn;
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public long getIsbn() {
        return isbn;
    }

    public void setIsbn(long isbn) {
        this.isbn = isbn;
    }

    public Author getAuthor() {
        return author;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }
    void PrintDetail()
    {
        System.out.println("Title: "+this.title);
        System.out.println("ISBN: "+this.isbn);
        author.PrintAuthorDetails();
    }
}
