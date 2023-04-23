import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.ObjectMessage;
import javax.jms.Message;
import javax.jms.TextMessage;

public class DrawerListener implements MessageListener {

    public void onMessage(Message message) {
        // int N = 100;
        // double[] number = new double[N];
        try {
            System.out.println("We received a signal:"+((TextMessage)message).getText());

            // for (int i = 0; i < 104; i++) {
            //     if (i < 100) {
            //         String str = ((TextMessage) message).getText();
            //         number[i] = Double.valueOf(str);
            //     }
            //     if (i == 100) {
            //         System.out.println("The average of the past one hundred signals is "
            //                 + ((TextMessage) message).getText() + " .");
            //     }
            //     if (i == 101) {
            //         System.out.println("The variance of the past one hundred signals is "
            //                 + ((TextMessage) message).getText() + " .");
            //     }
            //     if (i == 102) {
            //         System.out.println("The maxinum of the past one hundred signals is "
            //                 + ((TextMessage) message).getText() + " .");
            //     }
            //     if (i == 103) {
            //         System.out.println("The mininum of the past one hundred signals is "
            //                 + ((TextMessage) message).getText() + " .");
            //     }
            // }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
