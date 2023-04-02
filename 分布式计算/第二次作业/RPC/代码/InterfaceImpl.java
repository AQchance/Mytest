
//GRUD接口的实现
import java.rmi.RemoteException;

public class InterfaceImpl implements myInterface{
	private BookList library;
	public InterfaceImpl(BookList Library) {
		library = Library;
	}

	@Override
	public boolean add(Book book) throws RemoteException {
		return library.add(book);
	}

	@Override
	public Book queryByID(int bookID) throws RemoteException {
		return library.queryByID(bookID);
	}

	@Override
	public BookList queryByName(String name) throws RemoteException {
		BookList bookList = new BookList(library.queryByName(name));
		return bookList;
	}

	@Override
	public boolean delete(int bookID) throws RemoteException {
		return library.delete(bookID);
	}
}
