package hash;

import java.util.HashMap;
import java.util.Map;

public class Server {
	private final String ipAddress;
	private final int port;
	private final Map<String, String> keyValueStore;

	public Server(String ipAddress, int port) {
		this.ipAddress = ipAddress;
		this.port = port;
		this.keyValueStore = new HashMap<>();
	}

	public void put(String key, String value) {
		keyValueStore.put(key, value);
		System.out.println("已成功将 " + key + " - " + value + "存储于" + ipAddress + ":" + port);
	}

	public String get(String key) {
		String value = keyValueStore.get(key);
		System.out.println("成功从 "+ipAddress + ":" + port + ": " + "读取键值对 " + key + " - " + value);
		return value;
	}

	public String getIpAddress() {
		return ipAddress;
	}

	public int getPort() {
		return port;
	}

}
