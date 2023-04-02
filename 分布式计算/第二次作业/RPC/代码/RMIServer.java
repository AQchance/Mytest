
//服务端逻辑
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class RMIServer {

	public static void main(String[] args) throws RemoteException {

		try {
			String name = "Books";
			BookList Library = new BookList();// 存书的地方
			myInterface myInterface = new InterfaceImpl(Library);// 接口
			myInterface skeleton = (myInterface) UnicastRemoteObject.exportObject(myInterface, 0);// 注入接口，生成skeleton对象
			Registry registry = LocateRegistry.createRegistry(7777);
			registry = LocateRegistry.getRegistry("127.0.0.1", 7777);// 获取注册中心的引用
			System.out.println("regitry Books object");
			registry.rebind(name, skeleton);
		} catch (Exception e) {
			System.err.println("Exception:" + e);
			e.printStackTrace();
		}

	}

}
