#include <iostream>
using namespace std;

class Point3D
{
    int x, y, z;
    static int count;

public:

    Point3D() : x(0), y(0), z(0)
    {
        count++;
    }

    Point3D(int x, int y, int z) :x(x), y(y), z(z)
    {
        count++;
    }

    void Init(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void Show() const
    {
        cout << x << "\t" << y << "\t" << z << endl;
    }

    Point3D Sum(const Point3D& b)
    {
        return Point3D(x + b.x, y + b.y, z + b.z);
    }

    Point3D Mult(const Point3D& b)
    {
        return Point3D(x * b.x, y * b.y, z * b.z);
    }

    static int GetCount()
    {
        return count;
    }

    ~Point3D()
    {
        count--;
    }
};

int Point3D::count = 0;

int main()
{
    Point3D obj1(1, 2, 3);
    Point3D obj2(4, 5, 6);

    obj1.Show();
    obj2.Show();

    Point3D sumResult = obj1.Sum(obj2);
    cout << "Sum of obj1 and obj2: ";
    sumResult.Show();

    Point3D multResult = obj1.Mult(obj2);
    cout << "Multiplication of obj1 and obj2: ";
    multResult.Show();

    cout << "Number of Point3D objects: " << Point3D::GetCount() << endl;

    return 0;
}