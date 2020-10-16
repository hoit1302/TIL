package hw;

public class Polygon {
	String shape;
	int width,height;
	double area;
	
	Polygon(String shape, int width){
		this.shape=shape;
		this.width=width;		
	}
	
	Polygon(String shape, int width, int height){
		this(shape, width);	
		this.height=height;
	}
//	정사각형
	void calcArea(int width) {
		area=width*width;		
	}
//  삼각형, 직사각형
	void calcArea(int width,int height,int s) {
		if(s==1)
			area=(width*height)/2;
		else if(s==2)
			area=width*height;
	}
//	출력
	void printArea() {
		System.out.println(shape);
		System.out.println("area"+area);
	}

}
