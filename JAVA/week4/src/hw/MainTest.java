package hw;

public class MainTest {
	public static void main(String[] args) {
		Employee e1 = new Employee("박주은", 100000);
		Manager e2 = new Manager("김주은", 200000, 50000);
		Executive e3 = new Executive("고주은", 400000, 100000, 100000);

		e1.raiseSalary();
		e2.raiseSalary();
		e3.raiseSalary();
		
		System.out.println("===Employee(직원)===");
		System.out.println(e1.showInfo());
		System.out.println();
		System.out.println("===Manager(매니저)===");
		System.out.println(e2.showInfo());
		System.out.println();
		System.out.println("===Executive(임원)===");
		System.out.println(e3.showInfo());
		System.out.println();
	}
}
