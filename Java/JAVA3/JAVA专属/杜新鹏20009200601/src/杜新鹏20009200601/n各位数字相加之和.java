package ������20009200601;
import java.util.Scanner;
public class n��λ�������֮�� {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int n,sum=0;
		n=sc.nextInt();
		for(;n>0;n/=10) {
			sum+=n%10;
		}
		System.out.println(sum);
	}
}
