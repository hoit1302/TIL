package hw;

public class Manager extends Employee {
	protected int bonus;

	public Manager(String name, int salary, int bonus) {
		super(name, salary);
		this.bonus = bonus;
	}

	@Override
	public int raiseSalary() {
		int increased_salary;
		increased_salary = (int) (salary * 1.2);
		return increased_salary;
	}

	@Override
	public String showInfo() {
		String result = super.showInfo();
		result += "\n보너스:" + bonus;
		return result;
	}
}
