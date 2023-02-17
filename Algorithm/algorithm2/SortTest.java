import java.util.Scanner;
public class SortTest {
    public static void main(String[] args) {
        double[][] time = new double[5][11];
        double[][] space = new double[5][11];
        Sort s = new Sort();
        int set = new Scanner(System.in).nextInt();
        //重复十次
        for (int i = 0; i < 10; i++) {
            int[] A = new int[set];
            for (int j = 0; j < set; j++) {

                A[j] = (int) (Math.random() * (set));

            int[] a = new int[set];
            long startTime = 0;
            long startMem = 0;
            long endMem = 0;
            Runtime r;
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.IS(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[0][i] = (endMem - startMem) / 1024;
            time[0][i] = System.currentTimeMillis() - startTime;
            s.print(a);
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.TDM(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[1][i] = (endMem - startMem) / 1024;
            time[1][i] = System.currentTimeMillis() - startTime;
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.BUM(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[2][i] = (endMem - startMem) / 1024;
            time[2][i] = System.currentTimeMillis() - startTime;
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.RQ(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[3][i] = (endMem - startMem) / 1024;
            time[3][i] = System.currentTimeMillis() - startTime;
            s.copy(A, a);

            r = Runtime.getRuntime();
            r.gc();
            startTime = System.currentTimeMillis();
            s.QD3P(a);
            space[4][i] = (endMem - startMem) / 1024;
            time[4][i] = System.currentTimeMillis() - startTime;

        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                time[i][10] += time[i][j];
                space[i][10] += space[i][j];
            }
            time[i][10] = time[i][10] / 10.0;
            space[i][10] = space[i][10] / 10.0;
        }
        System.out.println("\n时间性能对比");
        System.out.println("Run1\tRun2\tRun3\tRun4\tRun5\tRun6\tRun7\tRun8\tRun9\tRun10\tAvg\t");
        s.print(time);

        System.out.println("\n空间性能对比(KB)");
        System.out.println("Run1\tRun2\tRun3\tRun4\tRun5\tRun6\tRun7\tRun8\tRun9\tRun10\tAvg\t");
        s.print(space);
    };
}
}