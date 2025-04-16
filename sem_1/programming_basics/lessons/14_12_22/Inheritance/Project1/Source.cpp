#include <iostream>


class Point2D {
public:
    Point2D(double _x = 0, double _y = 0);
    ~Point2D();
    void print(std::ostream&);
private:
    double x, y;
};

Point2D::Point2D(double _x, double _y) : x{ _x }, y{ _y } {
    std::cout << "Constructor 2D\n";
}
Point2D::~Point2D() {
    std::cout << "Destructor 2D\n";
}
void Point2D::print(std::ostream& out) {
    out << x << " " << y << " ";
}

class Point3D :public Point2D {//private, если наследуем не всё
public:
    Point3D(double _x = 0, double _y = 0, double _z = 0);
    ~Point3D();
    void print(std::ostream&);
private:
    double z;
};

Point3D::Point3D(double _x, double _y, double _z) : Point2D(_x, _y), z{ _z } {
    std::cout << "Constructor 3D\n";
}
Point3D::~Point3D() {
    std::cout << "Destructor 3D\n";
}
void Point3D::print(std::ostream& out) {
    Point2D::print(out);
    out << z << " ";
}

int main()
{
    //Point2D p;
    //Point2D *arr[3];

    //arr[0] = new Point2D(1, 2);       //в Point2D необходимо пометить методы print() и ~Point2D() как virtual
    //arr[1] = new Point3D(11, 12, 17);
    //arr[2] = new Point2D(5, 8);

    std::shared_ptr<Point2D> arr[3];        //в этом случае методы Point2D не надо помечать как virtual
    arr[0] = std::make_shared<Point2D>(1, 2);
    arr[1] = std::make_shared<Point3D>(11, 12, 7);
    arr[2] = std::make_shared<Point3D>(1, 2, 0);

    for (size_t i = 0; i < 3; i++)
    {
        arr[i]->print(std::cout);
        std::cout << '\n';
    }

    return 0;
}