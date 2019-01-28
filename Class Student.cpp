#include <iostream>;
#include <string>;
#include <fstream>
using namespace std;

class Person{
protected:
	string name;
	string id;
public:

	Person(){
		name="unknown";
		id="unknown";
	}

	Person(const string name,const string id){
		this->name=name;
		this->id=id;
	}

	Person(const Person &pp){
		name=pp.name;
		id=pp.id;
	}

	void set_Person(string name,string id){
		this->name=name;
		this->id=id;
	}


	string Get_name(){
		return name;
	}

	string Get_id(){
		return id;
	}

	bool operator <(const Person&obj){
		return id<obj.id;
	}

	bool operator == (const Person& obj){
		return id==obj.id;
	}

	friend ostream& operator<<(ostream& toStream, const Person& obj){
		toStream<<"Name: "<<obj.name<<endl;
		toStream<<"Id: "<<obj.id<<endl;
		return toStream;
	}

	friend istream& operator >>(istream& fromStream, Person& obj){
		fromStream>>obj.name;
		fromStream>>obj.id;
		return fromStream;
	}

	int ValidateID()
	{
		bool flag=false;
		int len=id.size();
		if(len==10)
		{
			flag=true;
		}
		else flag=false;
		string year = id.substr (0,2);
		string month = id.substr (2,2);
		string day = id.substr (4,2);
		int intyear = stoi(year);
		int intmonth = stoi(month);
		int intday = stoi(day);
		if(intmonth>12&&intmonth<40||intmonth>52)
		{
			flag=false;
		}
		if(intday>31&&intmonth==1||intday>31&&intmonth==3||intday>31&&intmonth==5||
			intday>31&&intmonth==7||intday>31&&intmonth==8||intday>31&&intmonth==10||
			intday>31&&intmonth==12||intday>31&&intmonth==41||intday>31&&intmonth==43||
			intday>31&&intmonth==45||intday>31&&intmonth==47||intday>31&&intmonth==48||
			intday>31&&intmonth==50||intday>31&&intmonth==52)
		{
			flag=false;
		}
		if(intday>30&&intmonth==4||intday>31&&intmonth==6||intday>31&&intmonth==9||
			intday>31&&intmonth==11||intday>30&&intmonth==44||intday>31&&intmonth==46||
			intday>31&&intmonth==49||intday>31&&intmonth==51)
		{
			flag=false;
		}
		if(intday>28&&intmonth==2&&intyear%4!=0||intday>29&&intmonth==2&&intyear%4==0)
		{
			flag=false;
		}
		return flag;	
	}

	void age()
	{
		string year = id.substr (0,2);
		string month = id.substr (2,2);	
		int intyear = stoi(year);
		int intmonth = stoi(month);
		if(intmonth>40)
		{
			intyear=intyear+2000;
		}
		else {
			intyear=intyear+1900;
		}
		cout<<"Person is "<<2018-intyear<<" old"<<endl;
	}

};

class Student:public Person{
private:
	string spec;
	string fn;
public:
	Student(string spec, string fn,string name, string id):Person(name,id){
		this->spec=spec;
		this->fn=fn;
	}

	ostream& output(ostream& toStream){
		toStream<<"Name: "<<name<<endl;
		toStream<<"Id: "<<id<<endl;
		toStream<<"Spec: "<<spec<<endl;
		toStream<<"Fn: "<<fn<<endl;

		return toStream;
	}

};

void main(){
	string strName,strId,strSpec,strFN;

	cout<<"Name ";
	getline(cin,strName);
	cout<<"ID ";
	getline(cin,strId);

	Person p(strName,strId);
	if(p.ValidateID())
	{
		cout<<p;
		p.age();
		cout<<"Spec ";
		getline(cin,strSpec);
		cout<<"FN ";
		getline(cin,strFN);
		Student s(strSpec,strFN,strName,strId);
		s.output(cout);
	}
	else cout<<"Wrong ID"<<endl;

	system("pause");
}
