import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageProducer;
import javax.jms.ObjectMessage;
import javax.jms.Session;
import javax.jms.Topic;

import org.apache.activemq.ActiveMQConnectionFactory;

public class Publisher {

    private static String brokerURL = "tcp://localhost:61616";
    private static ConnectionFactory factory;
    private Connection connection;
    private Session session;
    private MessageProducer producer;
	private Topic topic;
    
    public Publisher(String topicName) throws JMSException {
		
    	factory = new ActiveMQConnectionFactory(brokerURL);
    	connection = factory.createConnection();
        
        session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
		topic = session.createTopic(topicName);
        producer = session.createProducer(topic);
		
		connection.start();
    }    
    
    public void close() throws JMSException {
        if (connection != null) {
            connection.close();
        }
    }    
    
	public static void main(String[] args) throws JMSException {
    	Publisher publisher = new Publisher("MYTOPIC");
        publisher.sendMessage();
        publisher.close();

	}
	
    public void sendMessage() throws JMSException {
        
        Message message = session.createTextMessage("Hello world!");
		//for(int i=0;i<15;i++){
		producer.send(message);
		System.out.println("Sent a message!");
		//}
    }	

}
