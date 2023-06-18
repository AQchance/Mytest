package hash;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

public class Client {
	private final ConsistentHashing hashStore;
	private final List<Server> servers;
	
	public Client(List<Node> nodes, int virtualNodes) {
		this.servers = new ArrayList<>();
		for (Node node : nodes) {
			servers.add(new Server(node.getIpAddress(),
			node.getPort()));
		}	
		this.hashStore = new ConsistentHashing(nodes, virtualNodes);
		System.out.println("当前哈希环为 " + hashStore + "\n");
	}
	
	public void put(String key, String value) {
		Node node = hashStore.getNode(key); 
		Server server = findServer(node);
		server.put(key, value);
	}
	public String get(String key) {
		Node node = hashStore.getNode(key);
		Server server = findServer(node);
		return server.get(key);
	}
	private Server findServer(Node node) {
		for (Server server : servers) {
			if (server.getIpAddress().equals(node.getIpAddress()) && server.getPort() == node.getPort()) {
				return server;
			}
		}
		return null;
	}
	
	public void addNode(Node node) {
		servers.add(new Server(node.getIpAddress(), node.getPort()));
		hashStore.addNode(node);
		System.out.println("节点 " + node.getIpAddress() + ":" + node.getPort() + " 添加成功！ .\n");
		System.out.println("当前哈希环 " + hashStore.getRing() +"\n");
	}
	
	public void removeNode(Node node) {
		Server serverToRemove = null;
		for (Server server : servers) {
			if (server.getIpAddress().equals(node.getIpAddress()) &&
					server.getPort() == node.getPort()) {
				serverToRemove = server;
				break;
			}
		}
		if (serverToRemove != null) {
			servers.remove(serverToRemove);
		}
		hashStore.removeNode(node);
	}
	
	public TreeMap<Integer, Node> getRing() {
		return (TreeMap<Integer, Node>) hashStore.getRing();
	}
}
