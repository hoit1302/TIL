package hw;

class Calculator {
	
	private int num1;
	private int num2;
	
	Calculator(int num1, int num2) {
		this.num1 = num1;
		this.num2 = num2;
	}
	
	int add() {
		return num1 + num2;
	}
	int minus() {
		return num1-num2;
	}
	int multiply() {
		return num1*num2;
	}
	double divide() {
		return (double)num1 / num2;
	}
}
