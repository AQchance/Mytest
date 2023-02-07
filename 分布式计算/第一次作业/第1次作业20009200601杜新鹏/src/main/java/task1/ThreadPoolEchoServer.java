import java.io.*;
import java.net.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.TimeUnit;

public class ThreadPoolEchoServer {
	 public static void main(String[] args) throws Exception {
		ServerSocket listenSocket=new ServerSocket(8189);
        Socket socket=null;
        ThreadPoolExecutor threadpool= new ThreadPoolExecutor(4, 8, 200,
         TimeUnit.MILLISECONDS, new ArrayBlockingQueue<Runnable>(4));
            
        int count=0;
        System.out.println("Server listening at 8189");
            
        while(true){
            socket=listenSocket.accept();
			count++;
			System.out.println("The total number of clients is " + count + ".");
            ServerThread serverThread=new ServerThread(socket);
            threadpool.execute(serverThread);
        }
    }
}