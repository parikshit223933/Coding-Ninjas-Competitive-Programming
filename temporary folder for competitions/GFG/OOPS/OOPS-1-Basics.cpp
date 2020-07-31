/* class Student
{
public:
    int rollNo;
    char name[20];
}; */
#include<iostream>
using namespace std;

class A
{
    int x, y;
    int sqr()
    {
        return x * x;
    }

public:
    int z;
    int twice()
    {
        return 2 * y;
    }
    int test(int i)
    {
        int q = sqr();
        return q + i;
    }
};
class Student {
    private:
    string name="parikshit";
    public:
    string getName()
    {
        return name;
    }    
};
int main()
{

    /* Student s1;
    Student s2;
    Student *s3 = new Student; */

    /* A obj;
    obj.z = 10; // valid. z is a public member
    obj.x = 4;  // Invalid. x is a private member and hence can
    // be accessed only by member functions
    // not directly by using object
    int j = obj.twice(); // valid. twice( ) is a public member function
    int k = obj.sqr();   // Invalid. sqr() is a private member function
    int l = obj.test();  // valid. test is a public member function */


}