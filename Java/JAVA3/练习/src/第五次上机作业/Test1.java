package ������ϻ���ҵ;
import java.util.Scanner;

public class Test1 {
	public static void main(String args[]) {
		double C=12.010;
		double H=1.008;
		double N=14.010;
		double O=16.000;
		Scanner in=new Scanner(System.in);
		System.out.println("���������ʽ������");
		int num=in.nextInt();
		for(int j=0;j<num;j++) {
			String name=in.next();
			int sum=0;
			float molecularweight=0f;
			char element='0';
			for(int i=0;i<name.length();i++) {
				char ch=name.charAt(i);
				if(ch>='0'&&ch<='9') {
					sum*=10;
					sum+=ch-'0';
					if(i+1>=name.length()||name.charAt(i+1)>'9'||name.charAt(i+1)<'0') {
						switch(element) {
						case 'C':molecularweight+=C*sum;break;
						case 'H':molecularweight+=H*sum;break;
						case 'O':molecularweight+=O*sum;break;
						case 'N':molecularweight+=N*sum;break;
						default:break;
						}
						sum=0;
					}
				}
				else {
					element=ch;
					if(i+1>=name.length()||name.charAt(i+1)>'9'||name.charAt(i+1)<'0') {
						switch(element) {
						case 'C':molecularweight+=C;break;
						case 'H':molecularweight+=H;break;
						case 'O':molecularweight+=O;break;
						case 'N':molecularweight+=N;break;
						default:break;
						}
					}
				}
			}
			System.out.println("�÷���ʽ�ķ�����Ϊ"+molecularweight);
		}
	}
}
