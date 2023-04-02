

import java.rmi.NotBoundException;
//客户端交互
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

import javax.swing.text.PlainDocument;

public class RMIClient {

	public static void main(String[] args) throws RemoteException, NotBoundException {
		// TODO Auto-generated method stub
		String name = "Books";
		String ServerIP = "127.0.0.1";
		int Serverport = 7777;
		Registry registry = LocateRegistry.getRegistry(ServerIP, Serverport);// 获取注册中心的引用
		myInterface proxy = (myInterface) registry.lookup(name);
		int option;
		int BookID;
		String Bookname = null;
		BookList bookList;
		Book book;
		Scanner scanner = new Scanner(System.in);
		System.out.println("1.添加书籍；2.删除指定ID书籍；3.按书名查询匹配书籍；4.按ID号查询指定书籍");
		while (true) {
			System.out.println("\n请输入操作指令：");
			option = scanner.nextInt();//输入缓冲区问题未解决
			
			switch (option) {
			case 1:
				System.out.println("请输入ID，书名：");
				BookID = scanner.nextInt();
				Bookname = scanner.next();
				if(proxy.add(new Book(BookID, Bookname))) {
					System.out.println("成功！");
				}else {
					System.out.println("ID重复！");
				}
				break;
			case 2:
				System.out.println("请输入ID：");
				BookID = scanner.nextInt();
				if (proxy.delete(BookID)) {
					System.out.println("删除成功");
				} else {
					System.out.println("查无此书！");
				}
				break;
			case 3:
				System.out.println("请输入书名：");
				Bookname = scanner.next();
				bookList = proxy.queryByName(Bookname);
				System.out.println(bookList.size());
				System.out.println("找到如下书籍：");
				bookList.dispaly();
				break;
			case 4:
				System.out.println("请输入ID：");
				BookID = scanner.nextInt();
				book = proxy.queryByID(BookID);
				System.out.println("找到如下书籍：");
				if(book == null) {
					System.out.println("没有相关书籍");
				}else {
					System.out.println(book.getID()+":"+book.getName());
				}
				break;
			default:
				System.out.println("输入无效！");
				break;
			}
		}
	}

}
