public class Test4 {
	static int x=1;
	int y;
	Test4(){
		y++;
	}
	static {
		x++;
	}
	public static void main(String args[]) {
		Test4 st=new Test4();
		System.out.println(x);
		System.out.println(st.y);
		st=new Test4();
		System.out.println(x);
		System.out.println(st.y);
	}
}
