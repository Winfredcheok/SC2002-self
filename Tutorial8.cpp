// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <string>

enum KindofPolygon { POLY_PLAIN, POLY_RECT, POLY_TRIANG };
string StringKindofPoly[] = { "POLY_PLAIN", "POLY_RECT","POLY_TRIANG"};


    class Polygon{

    protected :
        string name;
        float width;
        float height;
        KindofPolygon polytype;	
        
    public :
        Polygon(string theName, float theWidth, float theHeight):name(theName)	{
			//name = theName;
			width = theWidth;
			height = theHeight;
			polytype = POLY_PLAIN;
		}
		
		 KindofPolygon getPolytype() {
			return polytype;
		}
		
		void setPolytype(KindofPolygon value) {
			polytype = value;
		}
		
		string getName() { return name; }
		
		virtual  float calArea() = 0; //to make it pure virtual
		
		void printWidthHeight( ) {
		cout<< "Width = " << width << " Height = " << 
		height<<endl;
		}
    
};


class Rectangle : public Polygon{
    
    public :
        Rectangle(string theName, float theWidth, float theHeight): Polygon(theName, theWidth,theHeight){
            polytype=POLY_RECT;
        }
        
        float calArea(){
            return width*height;
        }
};

class Triangle : public Polygon{
    
    public :
        Triangle( string theName, float theWidth, float theHeight): Polygon(theName, theWidth, theHeight){
            polytype=POLY_TRIANG;
        }
        float calArea(){
            return 0.5f*width*height;
        }
};

class TestPolygon{
    public : 
        static void printArea(Polygon &p){
            float area=p.calArea();
            cout<< "the area is " << area <<endl;
        }
};


int main() {
    // Write C++ code here
    
    Rectangle rect("Rect", 3.0f, 4.0f);
    rect.printWidthHeight();
    TestPolygon::printArea(rect);
    
    Triangle tri("Tri", 3.0f, 4.0f);
    tri.printWidthHeight();
    TestPolygon::printArea(tri);

    return 0;
}
