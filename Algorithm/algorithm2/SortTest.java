import java.util.Scanner;
public class SortTest {
    public static void main(String[] args) {
        double[][] time = new double[5][11];
        double[][] space = new double[5][11];
        Sort s = new Sort();
        System.out.println("请输入初始问题规模（数组元素个数）：");
        int set = new Scanner(System.in).nextInt();
        // test
        // 两行选一行
        // for(int i=0;i<10;i++,set*=2){//问题规模连续翻倍的十次实验
        for (int i = 0; i < 10; i++) {// 问题规模相同的十次实验
            System.out.println("\n问题规模（数组元素个数）：" + set);

            // System.out.println("随机数组生成为：");
            int[] A = new int[set];
            for (int j = 0; j < set; j++) {

                // 五行选一行
                A[j] = (int) (Math.random() * (set));// 随机数据
                // A[j]=(int)(Math.random()*(set/16));//大量重复数据
                // A[j]=(int)(Math.random()*(set/set));//常量数据
                // A[j]=(-1)*j;//有序数据
                // A[j]=j;//有序数据

                // System.out.print(A[j]+" ");
            }
            // System.out.println();

            int[] a = new int[set];
            long startTime = 0;
            long startMem = 0;
            long endMem = 0;
            Runtime r;

            // System.out.println("Inesrtion Sort result：");
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

            // System.out.println("Top-down Mergeort result：");
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.TDM(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[1][i] = (endMem - startMem) / 1024;
            time[1][i] = System.currentTimeMillis() - startTime;
            // s.print(a);

            // System.out.println("Bottom-up Mergesort result：");
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.BUM(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[2][i] = (endMem - startMem) / 1024;
            time[2][i] = System.currentTimeMillis() - startTime;
            // s.print(a);

            // System.out.println("Random Quicksort result：");
            s.copy(A, a);
            startTime = System.currentTimeMillis();

            r = Runtime.getRuntime();
            r.gc();
            startMem = r.totalMemory() - r.freeMemory();
            s.RQ(a);
            endMem = r.totalMemory() - r.freeMemory();
            space[3][i] = (endMem - startMem) / 1024;
            time[3][i] = System.currentTimeMillis() - startTime;
            // s.print(a);

            // System.out.println("Quicksort with Dijkstra 3-way Partition result：");
            s.copy(A, a);

            r = Runtime.getRuntime();
            r.gc();
            startTime = System.currentTimeMillis();
            // startMem =r.totalMemory() - r.freeMemory();
            s.QD3P(a);
            // endMem=r.totalMemory() - r.freeMemory();
            space[4][i] = (endMem - startMem) / 1024;
            time[4][i] = System.currentTimeMillis() - startTime;
            // s.print(a);

        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                time[i][10] += time[i][j];
                space[i][10] += space[i][j];
            }
            time[i][10] = time[i][10] / 10.0;
            space[i][10] = space[i][10] / 10.0;
        }
        System.out.println("\nRunning time cost(ms)");
        System.out.println("     run1   run2   run3   run4   run5   run6   run7   run8   run9   run10   avg");
        s.print(time);

        System.out.println("\nRunning memory cost(KB)");
        System.out.println("     run1   run2   run3   run4   run5   run6   run7   run8   run9   run10   avg");
        s.print(space);

    };
}