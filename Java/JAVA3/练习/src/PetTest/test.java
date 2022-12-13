package PetTest;
import java.util.Scanner;
abstract class Pet {
	public static int ID=1;
	public String name;
	Pet(String name)
	{
		this.name=name;
	}
	public String getName()
	{
		return this.name;
	}
	public static String judgePet(Pet pet)
	{
		if(pet instanceof Dog) {
			return "Dog";
		}
		if(pet instanceof Cat) {
			return "Cat";
		}
		else
			return "Bird";
	}
	public abstract int getID();
}
class Dog extends Pet{
	public Dog(String name)
	{
		super(name);
	}
	public int PetID=ID++;
	public int getID()
	{
		return PetID;
	}
}
class Cat extends Pet {
	public Cat(String name)
	{
		super(name);
	}
	int PetID=ID++;
	public int getID()
	{
		return PetID;
	}
}

class Bird extends Pet {
	public Bird(String name)
	{
		super(name);
	}
	int PetID=ID++;
	public int getID()
	{
		return PetID;
	}
}
public class test {
	public static void main(String args[]) {
		Pet[] pets=new Pet[100];
		int choice;
		Scanner input=new Scanner(System.in);
		Scanner charinput=new Scanner(System.in);
		while(true) {
			System.out.println("��ѡ�����²���\n1:��������\n2:��ѯ������Ϣ\n3:���߳���\n4:ι������\n5:�˳�����");
			choice=input.nextInt();
			if(choice==1) {
				System.out.println("��ѡ��Ҫ�������������\n1:��\n2:è\n3:��\n4:������һ��");
				int flag=input.nextInt();
				if(flag==1) {
					System.out.println("��������������:");
					String Petname=charinput.nextLine();
					Dog dog=new Dog(Petname);
					pets[dog.getID()]=dog;
					System.out.println("�����ɹ�!");
				}
				else if(flag==2) {
					System.out.println("��������������:");
					String Petname=charinput.nextLine();
					Cat cat=new Cat(Petname);
					pets[cat.getID()]=cat;
					System.out.println("�����ɹ�!");
				}
				else if(flag==3) {
					System.out.println("��������������:");
					String Petname=charinput.nextLine();
					Bird bird=new Bird(Petname);
					pets[bird.getID()]=bird;
					System.out.println("�����ɹ�!");
				}
				else {
					System.out.println("�ѷ�����һ��");
					continue;
				}
			}
			else if(choice==2) {
			System.out.println("1:���������Ʋ�ѯ\n2:�����������ѯ\n3:��������Ų�ѯ\n4:������г�����Ϣ\n5:������һ��");
			int tmp=input.nextInt();
			String Petname;
			String breed;
			int use=0;
			int petID;
			if(tmp==1) {
				System.out.println("�������������:");
				Petname=charinput.nextLine();
				for(int i=1;i<100;i++) {
					if(pets[i]!=null) {
						if(pets[i].getName().equals(Petname)) {
							use=1;
							System.out.println(" ���:"+pets[i].getID()+" ����:"+Pet.judgePet(pets[i])+" ����:"+pets[i].getName());
						}
					}
				}
				if(use==0) {
					System.out.println("���ﲻ����!");
				}
			}
			else if(tmp==2) {
				use=0;
				System.out.println("�������������");
				breed=charinput.next();
				for(int i=1;i<=99;i++) {
					if(pets[i]!=null) {
						if(Pet.judgePet(pets[i]).equals(breed)) {
							use=1;
							System.out.println(" ���:"+pets[i].getID()+" ����:"+Pet.judgePet(pets[i])+" ����:"+pets[i].getName());
						}
					}
				}
				if(use==0) {
					System.out.println("���ﲻ����!");
				}
			}
			else if(tmp==3) {
				System.out.println("������������");
				petID=input.nextInt();
				if(pets[petID]!=null) System.out.println(" ���:"+pets[petID].getID()+" ����:"+Pet.judgePet(pets[petID])+" ����:"+pets[petID].getName());
				else System.out.println("���ﲻ����");
			}
			else if(tmp==4) {
				for(int i=1;i<=99;i++)
				{
						if(pets[i]!=null) System.out.println(" ���:"+pets[i].getID()+" ����:"+Pet.judgePet(pets[i])+" ����:"+pets[i].getName());
				}
			}
			else {
				System.out.println("�ѷ�����һ��");
				continue;
			}
		}
		else if(choice==3) {
			System.out.println("1:����������:\n2:������һ��");
			int flag=input.nextInt();
			if(flag==1) {
				int petID=input.nextInt();
				System.out.println("���:"+petID+" ����:"+Pet.judgePet(pets[petID])+" ����:"+pets[petID].getName()+" �ó��ﱻ�ɹ�����");
				pets[petID]=null;
			}
			else {
				continue;
			}
		}
		else if(choice==4) {
			System.out.println("������Ҫι���ĳ�������:");
			int feedNumber=input.nextInt();
			System.out.println("���:"+feedNumber+" ����:"+Pet.judgePet(pets[feedNumber])+" ����:"+pets[feedNumber].getName()+" �ó����ѱ�ι��");
		}
		else if(choice==5) break;
		}
		System.out.println("��ӭ�´ι���");
		}
}
