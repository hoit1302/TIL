package hw;

public class GraduateStudent extends Student {
	public GraduateStudent(String name) {
		super(name);
	}

	@Override
	public void computeGrade() {
		grade = "����";
		if (score >= 80)
			grade = "���";
	}
}
