#include <iostream>
using namespace std;

class myException {
private:
	string msg;
public:
	myException(string t):msg(t){}
	string getErr() {
		return msg;
	}
};

class mathError : public myException {
public:
	mathError(string t):myException(t){}
};

class invalidOperation : public myException {
public:
	invalidOperation(string t):myException(t){}
};

class divByZero : public mathError{
public:
	divByZero(string t):mathError(t){}
};

class tooLarge : public mathError{
public:
	tooLarge(string t):mathError(t){}
};

class precisionLoss : public mathError{
public:
	precisionLoss(string t):mathError(t){}
};

int main () {
	try {
	   int a,b;
	   cin >>a >>b;
	   if ( a==100) throw( invalidOperation("Invalid Op")); // Create a different exception type 
	   if ( a==1000) throw(tooLarge("Number Too large")); // Create a different exception type
	   if ( b==0) throw( divByZero("Divide by Zero"));
	} catch (divByZero &err){ // Derived classes (if there're any) comes first.
		cout << "Exception:" << err.getErr() << endl;		
	} catch (mathError &err){ // Catch all math Exceptions except above: tooLarge and precisionLoss
		cout << "General Math Exception:" << err.getErr() << endl;	
	} catch (myException &err){ // Base Class: Catch all exceptions except listed above. Should be last.
		cout << "General Exception:" << err.getErr() << endl;	
	}
}