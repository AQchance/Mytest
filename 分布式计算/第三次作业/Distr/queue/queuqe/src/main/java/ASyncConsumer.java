import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.MessageConsumer;
import javax.jms.Session;
import javax.jms.Message;
import javax.jms.TextMessage;

import org.apache.activemq.ActiveMQConnectionFactory;

public class ASyncConsumer {

    public static void main(String[] args) throws JMSException {
		String brokerURL = "tcp://localhost:61616";
		ConnectionFactory factory = null;
		Connection connection = null;
		Session session = null;
		Destination destination = null;
		MessageConsumer messageConsumer = null;
		MyListener listener = null;
		
        
		try {
			factory = new ActiveMQConnectionFactory(brokerURL);
			connection = factory.createConnection();
			connection.start();
			
			session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
			destination = session.createQueue("TEST");								//消费者创建一个目的地为TEST的消息队列
			messageConsumer = session.createConsumer(destination);					//根据目的地创建一个消费者
			
			listener = new MyListener();											//实例化一个监听对象
			
			messageConsumer.setMessageListener(listener);							//将消费者的监听对象设置为我们实例化的监听对象
			
			System.in.read();   // Pause
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			connection.close();
		}
	}
	
}
