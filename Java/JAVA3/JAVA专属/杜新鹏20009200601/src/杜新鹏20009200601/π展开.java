package ������20009200601;

public class ��չ�� {
	public static void main(String args[]) {
		int i;
		double Result=0.0;
		for(i=1;i<10000;i++) {
			Result+=4.0*1/(2*i-1)*Math.pow(-1,i+1);
		}
		System.out.print(Result);
	}

}
