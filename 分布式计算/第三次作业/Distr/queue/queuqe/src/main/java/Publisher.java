import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageProducer;
import javax.jms.ObjectMessage;
import javax.jms.Session;
import java.lang.*;
import java.lang.constant.Constable;

//使用JFreeChart画图
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;
import org.jfree.data.category.DefaultCategoryDataset;

import org.apache.activemq.ActiveMQConnectionFactory;
import java.util.Random;

public class Publisher {

    private static String brokerURL = "tcp://localhost:61616";
    private static ConnectionFactory factory;
    private Connection connection;
    private Session session;
    private MessageProducer producer;

    public Publisher() throws JMSException {
        factory = new ActiveMQConnectionFactory(brokerURL);
        connection = factory.createConnection();
        connection.start();
        session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
        producer = session.createProducer(null);
    }

    public void close() throws JMSException {
        if (connection != null) {
            connection.close();
        }
    }

    public static void main(String[] args) throws JMSException {
        Publisher publisher = new Publisher();
        publisher.sendMessage();
        publisher.close();

    }

    public void sendMessage() throws JMSException {
        Destination mydest = session.createQueue("Draw");
        int Maxtimes = 10000;
        double MaxSignal = -1, MinSignal = 100000;
        int N = 100;
        double[] random_signal = new double[N]; // 动态分配一个N大小的double数组
        System.out.println("\n_____________________Now begin outputing new random signal!______________________");
        while (--Maxtimes > 0) {
            double sum = 0;
            double average = 0;
            double variance = 0;
            for (int i = 0; i < N; i++) {
                Random r = new Random();
                double number = Math.sqrt(25) * r.nextGaussian() + 100; // 均值为100，方差为25的正态分布随机数
                random_signal[i] = number;
                sum += number;
                if (MaxSignal < random_signal[i])
                    MaxSignal = random_signal[i];
                if (MinSignal > random_signal[i])
                    MinSignal = random_signal[i];
            }
            average = sum / N; // 计算均值
            for (int i = 0; i < N; i++) {
                variance += (random_signal[i] - average) * (random_signal[i] - average);
            }
            variance = variance / N; // 计算方差
            try {

                DefaultCategoryDataset dataset = new DefaultCategoryDataset();  //定义数据集

                Destination dest = session.createQueue("TEST"); // 创建了一个名为TEST的消息队列
                String str = "\n_____________________Now begin outputing random signal!______________________";
                Message mes = session.createTextMessage(str); // 定义要发送的消息
                producer.send(dest, mes);

                for (int i = 0; i < N; i++) {

                    dataset.addValue(((int)random_signal[i]), "Signal",""+(i+1));    //将信号加入数据集

                    Destination destination = session.createQueue("TEST"); // 创建了一个名为TEST的消息队列
                    String strnumber = "" + random_signal[i];
                    Message message = session.createTextMessage(strnumber); // 定义要发送的消息
                    producer.send(destination, message);
                    producer.send(mydest, message);                         //发给draw消息队列
                    System.out.println("A message has been sent!");
                    Thread.sleep(100);
                }

                Destination destination = session.createQueue("TEST"); // 创建了一个名为TEST的消息队列
                String strnumber = "The average of the past one hundred signals is " + average + " .";
                Message message = session.createTextMessage(strnumber); // 定义要发送的消息
                producer.send(destination, message);
                //producer.send(mydest, message); 
                System.out.println("A message has been sent!");
                strnumber = "The variance of the past one hundred signals is " + variance + " .";
                message = session.createTextMessage(strnumber); // 定义要发送的消息
                producer.send(destination, message);
                //producer.send(mydest, message); 
                System.out.println("A message has been sent!");
                strnumber = "The maximum value of all signals is " + MaxSignal + " .";
                message = session.createTextMessage(strnumber); // 定义要发送的消息
                producer.send(destination, message);
                //producer.send(mydest, message); 
                System.out.println("A message has been sent!");
                strnumber = "The minimum value of all signals is " + MinSignal + " .";
                message = session.createTextMessage(strnumber); // 定义要发送的消息
                producer.send(destination, message);
                //producer.send(mydest, message); 
                System.out.println("A message has been sent!");

                JFreeChart chart = ChartFactory.createLineChart(
                    "Signal record",                    // 图表标题
                    "random signal number",             // X 轴标签
                    "random signal",                    // Y 轴标签
                    dataset                             // 数据集
                );
                ChartFrame frame = new ChartFrame("Signal record", chart);
                frame.pack();
                frame.setVisible(true);
                Thread.sleep(10000);
                frame.dispose();

                // for (int i = 0; i < 15; i++) {
                // producer.send(destination, message); // 向目的地消息队列发送message
                // System.out.println("Sent a message!"); // 发送完消息输出
                // }
            } catch (Exception e) {
                System.out.println("ERROR!");
            }
        }
    }
}
