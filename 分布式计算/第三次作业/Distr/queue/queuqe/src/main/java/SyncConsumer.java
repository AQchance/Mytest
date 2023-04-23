import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.MessageConsumer;
import javax.jms.Session;
import javax.jms.Message;
import javax.jms.TextMessage;

import org.apache.activemq.ActiveMQConnectionFactory;

public class SyncConsumer {

    public static void main(String[] args) throws JMSException {
		String brokerURL = "tcp://localhost:61616";
        
		ConnectionFactory factory = new ActiveMQConnectionFactory(brokerURL);
    	Connection connection = factory.createConnection();
        connection.start();
        Session session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
		Destination destination = session.createQueue("TEST");
		MessageConsumer messageConsumer = session.createConsumer(destination);
		
    	TextMessage message = (TextMessage)messageConsumer.receive(100000);
        System.out.println("Received a message: " + message.getText());
		
		connection.close();
    }
	
}
