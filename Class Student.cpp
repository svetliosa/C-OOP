#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum Gender { male, female, unknown };

class Person{
protected:
	string m_strName;
	string m_strId;
	Gender m_eGender;

public:
	Person(string strName,string strId,Gender from){
		m_strName=strName;
		m_strId=strId;
		m_eGender=from;
	}

	string GetName(){
		return m_strName;
	}

	string GetId(){
		return m_strId;
	}

	ostream& output(ostream& toStream){
		toStream<<"Person Name: "<<m_strName<<endl;
		toStream<<"Person ID: "<<m_strId<<endl;
		switch(m_eGender){
		case male:
			toStream<<"Gender: "<<"Male"<<endl;
			break;
		case female:
			toStream<<"Gender: "<<"Female"<<endl;
			break;
		default:
			toStream<<"Gender: "<<"Unknown"<<endl;
		}
		return toStream;
	}

	int ValidatePIN()
	{
		bool flag=false;
		int len=m_strId.size();
		if(len==10)
		{
			flag=true;
		}
		else flag=false;
		string year = m_strId.substr (0,2);
		string month = m_strId.substr (2,2);
		string day = m_strId.substr (4,2);
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
		string year = m_strId.substr (0,2);
		string month = m_strId.substr (2,2);	
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
	string m_strFn;
	string m_strSpec;

public:
	Student (string strName, string strId, Gender from, string strFn, string strSpec):Person(strName,strId,from)
	{
		m_strFn=strFn;
		m_strSpec=strSpec;
	}

	string GetFn(){
		return m_strFn;
	}

	string GetSpec(){
		return m_strSpec;
	}

	ostream& output(ostream& toStream){
		toStream<<"Person Name: "<<m_strName<<endl;
		toStream<<"Person ID: "<<m_strId<<endl;
		switch(m_eGender){
		case male:
			toStream<<"Gender: "<<"Male"<<endl;
			break;
		case female:
			toStream<<"Gender: "<<"Female"<<endl;
			break;
		default:
			toStream<<"Gender: "<<"Unknown"<<endl;
		}
		toStream<<"Student FN: "<<m_strFn<<endl;
		toStream<<"Student Specialty: "<<m_strSpec<<endl;
		return toStream;

	}

	int searchfn(string m_strarr[3]){
		string fnsec;
		bool flag=false;
		cout<<"Search for a student"<<endl;
		cout<<"FN: "<<endl;
		getline(cin,fnsec);
		for(int i=0;i<3;i++){
			if(fnsec==m_strarr[i]){
				flag=true;
				break;
			}
			else{
				flag=false;
			}
		}
		return flag;
	}

	void file_print (string strName, string strId, Gender from, string strFn, string strSpec)
	{
		fstream file;
		file.open("example.txt", ios::out);
		file<<strName<<" "<<strId<<" "<<from<<" "<<strFn<<" "<<strSpec<<endl;
		file.close();

	}
};



void main(){
	string m_strIme, m_strEgn;
	Gender m_ePol=unknown;
	int a;
	string m_strFakN;
	string m_strSpecialnost;

	Student s(m_strIme,m_strEgn,m_ePol,m_strFakN,m_strSpecialnost);
	string m_strarr[3];

	for(int i=0;i<3;i++){
		cout<<"Name: ";
		getline(cin,m_strIme);
		cout<<"EGN: ";
		getline(cin,m_strEgn);
		cout<<"Gender: "<<endl<<"1. Male"<<endl<<"2. Female"<<endl;
		cin>>a;
		switch (a){
		case 1: m_ePol=male; break;
		case 2: m_ePol=female; break;
		}

		Person p(m_strIme,m_strEgn,m_ePol);
		p.GetName();
		p.GetId();
		p.ValidatePIN();
		if(p.ValidatePIN())
		{
			p.output(cout);
			p.age();
		}
		else cout<<"Wrong PIN"<<endl;
		cin.ignore();
		cout<<"FN: ";
		getline(cin,m_strFakN);
		m_strarr[i]=m_strFakN;
		cout<<"Specialty: ";
		getline(cin,m_strSpecialnost);
		
		s.GetFn();
		s.GetSpec();
		s.output(cout);
		s.file_print(m_strIme,m_strEgn,m_ePol,m_strFakN,m_strSpecialnost);
	}
	
	if(s.searchfn(m_strarr))
	{ 
		cout<<"The student exists"<<endl;
	}
	else
	{
		cout<<"The student doesn`t exists"<<endl;
	}

	system("pause");
}
