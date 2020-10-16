package hw;


public class Calculator {
	int num1,num2;
	
	//생성자
	Calculator(int num1,int num2){
		this.num1=num1;
		this.num2=num2;
	}

	public int getNum1() {
		return num1;
	}

	public void setNum1(int num1) {
		this.num1 = num1;
	}

	public int getNum2() {
		return num2;
	}

	public void setNum2(int num2) {
		this.num2 = num2;
	}
	
	int add(int num1, int num2) {
		return num1+num2;
	}

	int sub(int num1, int num2) {
		return num1-num2;
	}
	int mul(int num1, int num2) {
		return num1*num2;
	}
	//*** 중요 형변환:묵시적형변환/명시적형변환
	double div(int num1, int num2) {
		return (double)num1/num2;
	}

	void showinfo(String op) {
		double result=0.0;
		if(op.equals("+"))
			result=add(num1, num2);
		else if(op.equals("-"))
			result=sub(num1, num2);
		else if(op.equals("*"))
			result=mul(num1, num2);
		else if(op.equals("/")) {
			if(num2==0) {
				System.out.println("Indivisible by zero");
				return;
			}
			result=div(num1, num2);
		}
		System.out.println("result: "+result);
	}
	

	
}