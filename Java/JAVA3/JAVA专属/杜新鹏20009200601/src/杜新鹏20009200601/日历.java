package 杜新鹏20009200601;
import java.util.Scanner;
public class 日历 {
	public static void main(String args[]) {
		int i,j,decision,year,month,day,num=5,k;
		int Month[]= {0,31,0,31,30,31,30,31,31,30,31,30,31};
		Scanner in=new Scanner(System.in);
		String Weekday="周日\t周一\t周二\t周三\t周四\t周五\t周六";
		System.out.println("查询日历请按 1\n查询某一日期的星期请按 2");
		decision=in.nextInt();
		if(decision==1) {
			System.out.print("请输入所要查询的年份：");
			year=in.nextInt();
			if(year>=2021) {
				for(i=2021;i<year;i++) {			
					if((i%4==0&&i%100!=0)||i%400==0) {
						num+=2;
						num%=7;
					}
					else {
						num++;
						num%=7;
					}
				}
			}
			else {
				for(i=2021;year<i;i--) {
					if(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0) {
						num-=2;
						if(num<0) num+=7;
					}
					else{
						num--;
						if(num<0) num+=7;
					}
				}
			}
			if((year%4==0&&year%100!=0)||year%400==0) Month[2]=29;
			else Month[2]=28;
			for(i=1;i<=12;i++) {
				System.out.println(year+"年"+i+"月");
				System.out.println(Weekday);
				for(j=0;j<num;j++) {
					System.out.print("\t");
				}
				for(k=1;k<=Month[i];k++) {
					if(num<6) System.out.print(k+"\t");
					else System.out.println(k);
					num++;
					num%=7;
					if(k==Month[i]) System.out.print("\n");
				}
			}
		}
		else if(decision==2) {
			System.out.println("请输入日期（年月日用空格隔开）");
			year=in.nextInt();
			month=in.nextInt();
			day=in.nextInt();
			if(year>=2021) {
				for(i=2021;i<year;i++) {			
					if((i%4==0&&i%100!=0)||i%400==0) {
						num+=2;
						num%=7;
					}
					else {
						num++;
						num%=7;
					}
				}
			}
			else {
				for(i=2021;year<i;i--) {
					if(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0) {
						num-=2;
						if(num<0) num+=7;
					}
					else{
						num--;
						if(num<0) num+=7;
					}
				}
			}
			if((year%4==0&&year%100!=0)||year%400==0) Month[2]=29;
			else Month[2]=28;
			for(j=0,k=1;k<=month;k++) {
				if(k==month) j+=day;
				else j+=Month[k];
			}
			num+=(j-1)%7;
			num%=7;
			switch(num) {
			case 0: System.out.println("这一天是周天");break;
			case 1: System.out.println("这一天是周一");break;
			case 2: System.out.println("这一天是周二");break;
			case 3: System.out.println("这一天是周三");break;
			case 4: System.out.println("这一天是周四");break;
			case 5: System.out.println("这一天是周五");break;
			case 6: System.out.println("这一天是周六");break;
			default:System.out.println("无效数字");break;
			}
		}
	}
}
