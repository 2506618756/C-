#include <iostream>
using namespace std;
class CMyClassA {
    int val;
public:
    CMyClassA(int);
    void print(); 
};
CMyClassA::CMyClassA(int arg) {
    val = arg;
    printf("A:%d\n", val);
}
void CMyClassA::print() {
    printf("ssssssssssssssss\n");
    return;
}

class CMyClassB :public CMyClassA{
	public :
	CMyClassB(int t=0):CMyClassA(3*t)
	{
		val=t;
		
		printf("B:%d\n", val);	
	}
	void  print()
	{
	 printf("kkkkkkkkkkkkkkkkkkk\n");
	}
	private:
		int val;

}; 

int main(int argc, char** argv) {
    CMyClassA a(3), *ptr;
    CMyClassB b(5);
    ptr = &a;
    ptr->print();
    a = b;
    a.print();
    ptr = &b;
    ptr->print();
    return 0;
}
