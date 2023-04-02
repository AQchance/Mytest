
import java.io.Serializable;

public class Book implements Serializable {
	private int bookID;
	private String name;

	public Book(int bookID, String name) {
		this.bookID = bookID;
		this.name = name;
	}

	public String getName() {
		return name;
	}

	public int getID() {
		return bookID;
	}
}
