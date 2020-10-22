package hw;

public class GraduateStudent extends Student {
	public GraduateStudent(String name) {
		super(name);
	}

	@Override
	public void computeGrade() {
		grade = "과락";
		if (score >= 80)
			grade = "통과";
	}
}
