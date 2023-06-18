package hash;

import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) {

		List<Node> nodes = new ArrayList<>();
		Node node1 = new Node("Node1", 8080);
		Node node2 = new Node("Node2", 8081);
		Node node3 = new Node("Node3", 8082);
		nodes.add(node1);
		nodes.add(node2);
		nodes.add(node3);

		// 虚拟节点为3
		String key1 = "Teacher1";
		String key2 = "Teacher2";
		String key3 = "Student1";
		String key4 = "Student2";
		String key5 = "Student3";
		Client client = new Client(nodes, 3);
		client.put(key1, "19711110");
		client.put(key2, "19710205");
		client.put(key3, "20020627");
		String value1 = client.get(key1);
		String value2 = client.get(key2);
		String value3 = client.get(key3);
		System.out.println("value1: " + value1);
		System.out.println("value2: " + value2);
		System.out.println("value3: " + value3);

		Node node4 = new Node("Node4", 8083);
		client.addNode(node4);

		client.put(key4, "20020815");
		client.put(key5, "20020329");
		String value4 = client.get(key4);
		String value5 = client.get(key5);
		System.out.println("value4: " + value4);
		System.out.println("value5: " + value5);

		client.removeNode(node2);
		client.removeNode(node3);
		client.removeNode(node4);
		System.out.println("当前哈希环： " + client.getRing() + "\n");

		String deletedV2 = client.get(key4);
		System.out.println("删除节点：" + deletedV2);
	}
}