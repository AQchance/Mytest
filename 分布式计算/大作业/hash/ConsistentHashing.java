package hash;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.List;
import java.util.SortedMap;
import java.util.TreeMap;
public class ConsistentHashing {
	private final SortedMap<Integer, Node> ring; 
	private final int virtualNodes;
	
	public ConsistentHashing(List<Node> nodes, int virtualNodes) {
		this.virtualNodes = virtualNodes;
		this.ring = new TreeMap<>();
		for (Node node : nodes) {
			addNode(node);
			System.out.println("节点 " + node.getIpAddress() + ":" + node.getPort() + " 添加成功！\n");
			System.out.println("当前哈希环状态为： " + ring + "\n");
		}
	}
	
	public void addNode(Node node) {
		for (int i = 0; i < virtualNodes; i++) {
			String virtualNodeId = node.getIpAddress() + ":" + node.getPort() + "-" + i; 
			int hash = getHash(virtualNodeId); 
			System.out.println("虚拟节点： " + virtualNodeId + " 为 " + hash);
			ring.put(hash, node);
		}
	}
	
	public void removeNode(Node node) {
		for (int i = 0; i < virtualNodes; i++) {
			String virtualNodeId = node.getIpAddress() + ":" + node.getPort() + "-" + i;
			int hash = getHash(virtualNodeId);
			ring.remove(hash);
			System.out.println("虚拟节点 " + virtualNodeId + "移除成功！");
		}
	}

	private int getHash(String key) {
		try {
			MessageDigest messageDigest =
					MessageDigest.getInstance("MD5");
			messageDigest.update(key.getBytes());
			byte[] digest = messageDigest.digest();
			int hash = 0;
			for (int i = 0; i < 4; i++) {
				hash <<= 8;
				hash |= ((int) digest[i]) & 0xFF;
			}
			return hash & 0x7FFFFFFF;
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		return 0;
	}
	
	public Node getNode(String key) {
		if (ring.isEmpty()) {
			return null;
		}
		int hash = getHash(key); 
		SortedMap<Integer, Node> tailMap = ring.tailMap(hash);
		if (tailMap.isEmpty()) {
			System.out.println(hash + " 被映射于：" + ring.get(ring.firstKey()));
			return ring.get(ring.firstKey());
		} else {
			System.out.println(hash + "被映射于：" + tailMap.get(tailMap.firstKey()));
			return tailMap.get(tailMap.firstKey());
		}
	}
	
	
	
	public SortedMap<Integer, Node> getRing() {
		return ring;
	}
	
	public int getVirtualNodes() {
		return virtualNodes;
	}
	
}
	
