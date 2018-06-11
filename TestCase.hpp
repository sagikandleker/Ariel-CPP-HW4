#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <type_traits>
using namespace std;

class TestCase{
private:
	ostream& os;
	string test_name;
	int trueTest;
	int falseTest;

public:
	TestCase(const string str, ostream& in) : os(in)
{
		this->test_name = str;
		trueTest = 0;
		falseTest = 0;
}

	template <typename T>
	TestCase check_equal(T a, T b)
	{
		if(a==b)
		{
			trueTest++;

		}
		else{
			falseTest++;
			os << test_name<< ": Failure in test #"<<to_string(falseTest+trueTest)<< ": " << a << " should equal " << b << "!" << endl;

		}
		return *this;

	}



	template <typename T>
	TestCase check_different(T a, T b)
	{
		if(a!=b)
		{
			trueTest++;

		}
		else{
			falseTest++;
			os << test_name << ": Failure in test #"<<to_string(falseTest+trueTest)<<": " << a << " equal to " << b << "!" << endl;

		}
		return *this;

	}

	template <typename T>
	TestCase check_output(T a, string b)
	{
		stringstream s;
		s << a;
		string test = s.str();
		if(test != b)
		{
			falseTest++;
			os << test_name<< ": Failure in test #"<<to_string(falseTest+trueTest)<<": string value should be " << a << " but is " << b << endl;

		}
		else{
			trueTest++;
		}
		return *this;

	}

	template <typename Function,typename T,typename t2>
	TestCase check_function(Function f,T a, t2 b)
	{
		int temp=f(a);
		if(temp!=b){
			falseTest++;
			os << test_name<< ": Failure in test #"<< to_string(falseTest+trueTest)<<": Function should return "
					<<b<<" but returned "<<temp<<"!" << endl;
		}
		else{
			trueTest++;
		}
		return *this;
	}



	void print()
	{

		os<< test_name<<": "<<falseTest<<" failed, "<<trueTest<<" passed, "
				<<to_string(trueTest+falseTest)<<" total"<<endl;
	}

};