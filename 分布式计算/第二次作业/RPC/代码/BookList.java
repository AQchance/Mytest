
import java.io.Serializable;
import java.util.Vector;

public class BookList implements Serializable {
	Vector<Book> books;

	public BookList() {
		books = new Vector<Book>();
	}

	public BookList(Vector<Book> bs) {
		books = new Vector<Book>(bs);
	}

	public boolean add(Book book) {// 往存书处存书
		for (int i = 0; i < books.size(); i++) {
			if (book.getID() == books.get(i).getID()) {
				return false;
			}
		}
		return books.add(book);
	}

	public boolean delete(int BookID) {
		int flag = -1;
		for (int i = 0; i < books.size(); i++) {
			if (BookID == books.get(i).getID()) {
				flag = i;
				break;
			}
		}
		if (flag == -1) {
			return false;
		} else {
			books.remove(flag);
			return true;
		}

	}

	public Book queryByID(int BookID) {
		int flag = -1;
		for (int i = 0; i < books.size(); i++) {
			if (BookID == books.get(i).getID()) {
				flag = i;
				break;
			}
		}
		if (flag == -1) {
			return null;
		} else {
			return books.get(flag);
		}
	}

	public Vector<Book> queryByName(String name) {
		Vector<Book> result = new Vector<Book>();
		for (int i = 0; i < books.size(); i++) {
			if (books.get(i).getName().matches("(.*)" + name + "(.*)")) {
				result.add(books.get(i));
			}
		}
		return result;
	}

	public int size() {
		return books.size();
	}

	public void dispaly() {
		if (books.size() == 0) {
			System.out.println("书库为空！");
		} else {
			for (int i = 0; i < books.size(); i++) {
				System.out.println(books.get(i).getID() + ":" + books.get(i).getName());
			}
		}
	}

}
