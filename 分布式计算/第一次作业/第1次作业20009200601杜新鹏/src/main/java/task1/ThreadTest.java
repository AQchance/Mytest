class MyThread extends Thread {
    private int ticket;

    MyThread(int t) {
        ticket = t;
    }

    public void run() {
        int n = ticket;
        for (int i = 0; i < n; i++) {
            if (ticket > 0) {
                System.out.println(this.getName() + " sold ticket " + ticket + ".");
                this.ticket--;
            }
        }
    }
};

public class ThreadTest {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(10);
        MyThread t2 = new MyThread(15);
        MyThread t3 = new MyThread(30);
        t1.start();
        t2.start();
        t3.start();
        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (Exception e) {
            System.out.println("Exception from main!");
        }
        System.out.println(t1.getName() + " end!");
        System.out.println(t2.getName() + " end!");
        System.out.println(t3.getName() + " end!");
    }
}