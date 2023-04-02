
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface myInterface extends Remote {
	boolean add(Book book) throws RemoteException;// 添加一个书籍对象

	Book queryByID(int bookID) throws RemoteException;// 查询指定ID号的书籍对象

	BookList queryByName(String name) throws RemoteException;// 按书名查询书籍对象列表。

	boolean delete(int bookID) throws RemoteException;// 删除指定ID号的书籍对象。
}
