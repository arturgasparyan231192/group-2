#include <iostream>
#include <cmath>


class Shape {
    public:
        virtual std::string getM() = 0;
        virtual std::string getN() = 0;
};

class Point : public Shape {
    protected:
        float x;
        float y;
    public:
        void setX(float x){
            this->x = x; 
        }
        void setY(float y){
            this->y = y;
        }
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
        Point(float x = 0, float y = 0){
            this->x = x;
            this->y = y;
            std::cout << " Point\n";
        }
        ~Point(){
            std::cout << "~Point\n";
        }
        Point(const Point& p){
            std::cout << "I am in copy constructor Point\n";
            x = p.x;
            y = p.y;
        }
        long distance(Point b,Point d){
            return sqrt(pow(((double)b.getX()-d.getX()),2)+pow(((double)b.getY()-d.getY()),2));
        }
	virtual void foo(){std::cout << "Point foo!\n";}
	void boo(){std::cout << "Point boo!\n";}
	virtual std::string getM(){return "I am in Point\n";}
	virtual std::string getN(){return "I am in Point\n";}
};

class Circle : public Point {
    private:
        float r;
    public:
        void setR(float r){
            this->r = r;
        }
        float getR(){
            return r;
        }
        float getL(){
            return 2*M_PI*r;
        }
	void setA(Point p){
	    this->x = p.getX();
	    this->y = p.getY();
	}
        Circle(Point p, float r = 0) :Point(p) {
            this->r = r;
            std::cout << " Circle\n";
        }
        ~Circle(){
            std::cout << "~Circle\n";
        }
        Circle(const Circle& c) :Point(c) {
            std::cout << "I am in copy constructor Circle\n";
            r = c.r;
        }
	virtual std::string getM(){return "I am in Circle\n";}
	virtual std::string getN(){return "I am in Circle\n";}     
};

class Line : public Point {
    private:
        Point a;
    public:   
        long getL(){
            Point b(x,y);
            return distance(b,a);
        }
        void setA(Point p){this->a = p;}
        void setB(Point p){
	    this->x = p.getX();
	    this->y = p.getY();
	}
        Point getA(){
            return a;
        }
        Point getB(){
	    Point b(x,y);
            return b;
        }
        Line(Point p, Point d) {
            this->x = p.getX();
            this->y = p.getY();
            this->a = d;
            std::cout << " Line\n";    
        }
        ~Line(){
            std::cout << "~Line\n";
        }
        Line(const Line& l) :Point(l) {
            a = l.a;
            std::cout << "I am in copy constructor Line\n";    
        }
        void PrintCoord(Point p, Point d){
            float k = (d.getY()-p.getY())/(d.getX()-p.getX());
	    float b = p.getY() - k*p.getX();
            for (int i=p.getX()+1; i < d.getX(); i++){
                std::cout << "(" << i << "," << k*i+b << ")\n";
            }
        }

};

class Rectangle : public Point  {
    private:
        Point c; 
    public:
        Rectangle(Point p, Point d){
            this->x = p.getX();
            this->y = p.getY();
            this->c = d;
            std::cout << " Rectangle\n";
        }
        ~Rectangle(){
            std::cout << "~Rectangle\n";
        }
        Rectangle(const Rectangle& a) :Point(a){
            c = a.c;
            std::cout << " I am in copy constructor of Rectangle\n";
        } 
        void setA(Point p){
            this->x = p.getX();
	    this->y = p.getY();
        }
        void setB(Point p){
            this->c = p;
        }
        Point getA(){
	    Point a(x,y);
            return a;
        }
        Point getB(){
            return c;
        }
        float getS(){
            return ((getB()).getY()-y)*((getB()).getX()-x);
        }
        float getL(){
            return 2*((getB()).getY()-y+(getB()).getX()-x);
        }
	virtual void foo(){std::cout << "Rectangle foo!\n";}
	void boo(){std::cout << "Rectanglee boo!\n";}
};

class Triangle : public Point {
    private:
        Point b,c;
    public:
       Triangle(Point p, Point d, Point m){
            this->x = p.getX();
            this->y = p.getY();
            this->b = d;
	    this->c = m;
            std::cout << " Triangle\n";
        }
        ~Triangle(){
            std::cout << "~Triangle\n";
        }
        Triangle(const Triangle& a) :Point(a){
            b = a.b;
            c = a.c;
            std::cout << " I am in copy constructor of Triangle\n";
        }
        void setA(Point p){
            this->x = p.getX();
	    this->y = p.getY();
        }
        void setB(Point p){
            this->b = p;
        }
        void setC(Point p){
            this->c = p;
        }
        Point getA(){
	    Point a(x,y);
            return a;
        }
        Point getB(){
            return b;
        }
        Point getC(){
            return c;
        }
        float getS(){
            return 0,5*fabs((x-getC().getX())*(getB().getY()-getC().getY())-(getB().getX()-getC().getX())*(y-getC().getY()));
        }
        float getL(){
            Point k(x,y);
            return distance(k,b)+distance(c,b)+distance(k,c);
        }
	virtual void foo(){std::cout << "Triangle foo!\n";}
	void boo(){std::cout << "Triangle boo!\n";}
};


void printS(Shape* obj){
    std::cout << obj->getM();
}

void printP(Shape* obj){
    std::cout << obj->getN();
}

int main() {

    Point a,b,m(10,10);
    float aX,aY,bX,bY;
    std::cout << "Mtcreq x0:";
    std::cin >> aX; 
    a.setX(aX);
    std::cout << "Mtcreq y0:";
    std::cin >> aY;
    a.setY(aY);
    std::cout << "Mtcreq x1:"; 
    std::cin >> bX;
    b.setX(bX);
    std::cout << "Mtcreq y1:";   
    std::cin >> bY;
    b.setY(bY);
    Line l(a,b);
    l.PrintCoord(a,b);

    Circle c(m);
    c.setR(10);
    std::cout << "Shrjanagci yerkarutyun:" << c.getL() << "\n";
    std::cout << "Hatvaci yerkarutyun:" << l.getL() << "\n";

    Rectangle r(a,b);
    Rectangle i = r;
    std::cout << "Uxxankyan makers:" << r.getS() << "\n";
    std::cout << "Uxxankyan paragic:" << r.getL() << "\n";

    Triangle t(a,b,c);
    Triangle o = t;
    std::cout << "Yerankyan makeres:" << t.getS() << "\n";
    std::cout << "Yerankyan paragic:" << t.getL() << "\n";
      
    Point *p = &r;
    p->foo(); 
    p->boo();
    p = &t;
    p->foo();
    p->boo();

    printS(&b);
    printP(&a);
    printP(&c);  

    return 0;   
}

