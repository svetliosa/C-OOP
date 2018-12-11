#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class student{
private:
	string name;
	vector<int>oc;
public:
	student(){
		name="Ime";
	}
	student(string nm){
		name=nm;
	}
	student(string nm, vector<int>&v){
		name=nm;
		oc=v;
	}
	void setoc(vector<int> &v){
		oc=v;
	}
	vector<int>&getoc() {
		return oc;
	}
	void setname(string nm){
		name=nm;
	}
	string getname(){
		return name;
	}

	void print() {
		cout<<name<<" ";
		for (int i=0;i<oc.size(); i++) {
			cout<<oc[i]<<" ";}
		cout<<endl;

	}

	double sruspeh(){
		double sum=0;
		double sr;
		for(int i=0;i<oc.size();i++){
			sum=sum+oc[i];
		}
		sr=sum/oc.size();
		return sr;
	}

	int broioc(int k){
		int br=0;
		for(int i=0;i<oc.size();i++){
			if (oc[i]==k){
				br++;
			}
		}
		return br;
	}

	bool deloc(int n) {
		vector<int>::iterator it;
		it=oc.begin();
		bool flag = false;
		while(it!=oc.end()){
			if(*it==n)
			{
				it=oc.erase(it); 
				flag=true;
			}
			else it++;
		}
		return flag;
	}

	bool IsGood(){
		return (sruspeh()>4.5&&broioc(2)==0);
	}

	friend ostream &operator<<(ostream &str, const student&st){
	str<<st.name<<" "<<st.oc.size()<<endl;
	for(int i=0;i<st.oc.size();i++)
		str<<st.oc[i]<<" ";
	str<<endl;
	return str;
	
	}

};

int main() {
	setlocale(LC_ALL, "Bulgarian");
	student s1("Pesho");
	student s2("Ivan");
	int mas[]={5,3,4,6,2,4,6,6,6,4};
	vector<int> v1(mas,mas+5), v2(mas+5,mas+10);
	s1.setoc(v1);
	s2.setoc(v2);
	s1.print();
	s2.print();
	s1.getoc();
	s2.getoc();
	cout<<"Среден успех на "<<s1.getname()<<": "<<s1.sruspeh()<<endl;
	cout<<"Среден успех на "<<s2.getname()<<": "<<s2.sruspeh()<<endl;
	cout<<"Брой четворки на "<<s1.getname()<<": "<<s1.broioc(4)<<endl;
	cout<<"Брой четворки на "<<s2.getname()<<": "<<s2.broioc(4)<<endl;
	if (s1.deloc(4))  cout << "Има изтрити оценки"<<endl;
	else cout << "Няма изтрити оценки"<<endl;
	s1.print();
	if (s2.deloc(4))  cout << "Има изтрити оценки"<<endl;
	else cout << "Няма изтрити оценки"<<endl;
	s2.print();
	if(s1.IsGood()) cout<<"Студентът "<<s1.getname()<<": е добър студент"<<endl;
	else cout<<"Студентът "<<s1.getname()<<": е лош студент"<<endl;
	if(s2.IsGood()) cout<<"Студентът "<<s2.getname()<<": е добър студент"<<endl;
	else cout<<"Студентът "<<s2.getname()<<": е лош студент"<<endl;
	

	list<student> gr;
	student s3("Nina");
	student s4("Petq");
	student s5("Ivelina");
	int arr[]={2,4,5,4,5,6,5,6,4,5,3,2,2,4,6};
	vector<int> v3(arr,arr+5), v4(arr+5,arr+10), v5(arr+10,arr+15);
	s3.setoc(v3);
	s4.setoc(v4);
	s5.setoc(v5);
	gr.push_back(s1);
	gr.push_back(s2);
	gr.push_back(s3);
	gr.push_back(s4);
	gr.push_back(s5);
	double sum=0;
	double srr;


	list<student>::iterator it;
	it=gr.begin();
	while(it!=gr.end()){
		(*it).print();
		sum=sum+(*it).sruspeh();
		it++;
	}
	srr=sum/gr.size();
	cout<<"Средния успех на групата е: "<<srr<<endl;



	double max=0;
	it=gr.begin();
	while(it!=gr.end()){
		if (max<(*it).sruspeh()){
			max=(*it).sruspeh();
		}
		it++;
	}
	it=gr.begin();
	while(it!=gr.end()){
        if(max==(*it).sruspeh()){
            cout<<"Студентът с най-висок успех е:"<<(*it).getname()<<endl;
		}
        it++;
    }



	list<student> gr2;
	int br=0;
	it=gr.begin();
	while(it!=gr.end()){
		if((*it).broioc(2)!=0){
			gr2.push_back(*it);
			br++;
		}
		it++;
	}
	cout<<"Броят на студентите, които имат поправителен е: "<<br<<endl;
	it=gr2.begin();
	while(it!=gr2.end()){
		(*it).print();
		it++;
	}



	cout<<"Броят на студентите, които имат поправителен е: "<<br<<endl;
	it=gr2.begin();
	while(it!=gr2.end()){
		(*it).operator<<(cout);
		it++;
	}
	

	system("pause");
	return 0;
}