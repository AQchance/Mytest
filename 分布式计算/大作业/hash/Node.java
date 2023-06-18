package hash;

public class Node {
	private final String ipAddress;
	private final int port;
	
	public Node(String ipAddress, int port) {
		this.ipAddress = ipAddress;
		this.port = port;
	}
		
	public String getIpAddress() {
		return ipAddress;
	}
	
	public int getPort() {
		return port;
	}
}
