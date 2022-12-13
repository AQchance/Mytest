package Animals;
class Animal{
	void out() {
		System.out.println("1");
	}
}
class Dog extends Animal{
	void out() {
		System.out.println("2");
	}
	void sh() {
		System.out.println("3");
	}
}
public class Test {
	public static void main(String args[]) {
		Animal a=new Dog();
		a.out();
		((Dog)a).sh();
		Animal b=new Animal();
		b.out();
	}
}
