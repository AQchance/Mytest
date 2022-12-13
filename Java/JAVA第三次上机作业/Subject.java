package 第三次上机作业;

public interface Subject {
	public void registerObserver(Student stu);
	public void removeObserver(Student stu);
	public void notifyObservers(Student stu);
	public void getKnowledge(String text);
}
