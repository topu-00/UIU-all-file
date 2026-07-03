

//Mahmudul hasan Topu
//Id ; 0112330164
//set -B

import java.util.ArrayList;
import java.util.Collection;

import java.util.Collections;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        ArrayList<Book>BookList=new ArrayList<Book>();
        BookList.add(new Book(1,"Narnia","Lewis",2000));
        BookList.add(new Book(2,"Tempest","Shakespeare",3500));
        BookList.add(new Book(3,"Caesar","Shakespeare",4500));
        BookList.add(new Book(4,"Harry potter","Rowling",3000));
        BookList.add(new Book(5,"Leagues under the sea","Verne",3200));

        System.out.println("Print all Book list:");
        System.out.println(BookList);

        System.out.println("Searching A book By Title: ");
        for (int i=0; i<BookList.size();i++){
          if (BookList.get(i).title.equals("Tempest")){
              System.out.println(BookList.get(i));
          }
        }

        System.out.println("Remove book by id: ");

        for (int i=0;i<BookList.size();i++){
            if (BookList.get(i).id==2){
                BookList.remove(i);
                //System.out.println(BookList.get(i));
            }

        }
        System.out.println("After remove Book\nBook List: ");
        System.out.println(BookList);
        Collections.sort(BookList);
        System.out.println("after sort");
        System.out.println(BookList);
        Collections.sort(BookList,new PriceSort());
        System.out.println("After Shor by price");
        System.out.println(BookList);
    }

}
