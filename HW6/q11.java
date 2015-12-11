class Person {
	public Person() {
		System.out.println("Person is
		                   created");
	}
	public void work() {
		System.out.println("person is working");
	}
}
class Student extends Person {
	public Student() {
		System.out.println("Student is created");
	}
	public void work() {
		System.out.println("Student is studying");
	}
}
public class Question10 {
	public static void main(String[] args) {
		Person b = new Student();
		b.work();
	}
}