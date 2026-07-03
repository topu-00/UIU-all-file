public class Book implements Comparable<Book>{
    int id;
    String title;
    String author;
    double price;

    public Book(int id,  String title ,String author,double price ) {
        this.author = author;
        this.id = id;
        this.price = price;
        this.title = title;
    }
   public String toString(){
        return "Id: " +id+" Title: "+ title+ " Author: " + author+ " Price: "+price + "\n";
    }

    public String getAuthor() {
        return author;
    }

    public int getId() {
        return id;
    }

    public double getPrice() {
        return price;
    }

    public String getTitle() {
        return title;
    }

    @Override
    public int compareTo(Book o) {
        int max= this.author.compareTo(o.author);
        if (max==0){
            return this.title.compareTo(o.title);
        }
        return max;
    }
}
