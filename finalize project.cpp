#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class VaccinationCenter{
protected:
string name,location,timings;
double  center_no, telephone_no;
string status;                              //status=1 open else closed
public:
	VaccinationCenter()
	{
		
	}
	
	VaccinationCenter(string name,string location,string timings, double center_no,double telephone_no,string status)
	{
		this->name=name;
		this->location=location;
		this->timings=timings;
		this->center_no=center_no;
		this->telephone_no=telephone_no;
		this->status=status;
	}
	void setdata()
	{
//		VaccinationCenter V;
//		void addRecord()
//{
//fstream f;
//student s;
//f.open("myfile.txt",ios::out );
//s.getdata();
//f.write((char*)&s, sizeof(s));
//f.close();
//
//}

//		ifstream obj;
//		obj.open("vaccinationcenter.txt", ios:app);
//		if(!obj){
//			cout<<"FILE NOT OPEN"<<endl;
//		}
//		else{
//			
//		}
		
		cout<<"Enter Center name: "<<endl;
		cin>>name;
		cout<<"Enter location: "<<endl;
		cin>>location;
		cout<<"Enter Center timings: "<<endl;
		cin>>timings;
		cout<<"Enter Center Number: "<<endl;
		cin>>center_no;
		cout<<"Enter Telephone number: "<<endl;
		cin>>telephone_no;
		cout<<"Enter status: "<<endl;
		cin>>status;
		

		
	}
	
	void adddatafiling( ){
		VaccinationCenter V;
		ofstream f;
		
		f.open("vaccinationcenter.txt", ios::out| ios::app);
		if(!f){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
			V.setdata( );
			f.write((char*)this, sizeof(*this));
			f.close();
		}
		
	}
	  
	void displayVaccinationdatafiling(){
		
		
		
		ifstream f1;
		VaccinationCenter V;
		f1.open("vaccinationcenter.txt", ios::in|ios:: );
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		f1.read((char*)this,sizeof(*this));
		cout<<endl<<endl;
		while(!f1.eof()){
			V.display();
			f1.read((char*)this,sizeof(*this));
		}
		
		
		
		
		
		
//		void Readdata()
//{
//fstream f;
//student s;
//f.open(&quot;studen.dat&quot;,ios::in | ios::binary);
//
//if(f.read((char*)&amp;s,sizeof(s))){
//cout&lt;&lt;endl&lt;&lt;endl;
//s.displayStudent();
//
//}
	}}
	void display()
	{
		cout<<"Center name: "<<name<<endl<<"Location: "<<location<<endl<<"Center timings: "<<timings<<endl<<"Center Number: "<<center_no<<endl<<"Telephone number: "<<telephone_no<<endl<<"Status: "<<status;
	}
};
class Patient:public VaccinationCenter{
	protected:
   string pname,Cnic,address,previoustest;
   int age;
  // static covidresult it will tells total covid positive and ratio.
public:
	Patient()
	{
		
	}
	
	Patient(string name,string location,string timings, double center_no,double telephone_no,string status, string n,string cnic,string add, string pt, int a):VaccinationCenter(name,location, timings, center_no,telephone_no,status)
	{
		pname=n;
		Cnic=cnic;
		address=add;
		previoustest=pt;
		age=a;
	}
	void setpatientdetails( ){
		cout<<"ENTER YOUR NAME: "<<endl;
		cin>>pname;
		
		cout<<"ENTER YOUR CNIC: "<<endl;
		cin>>Cnic;
		
		cout<<"ENTER YOUR ADDRESS: "<<endl;
		cin>>address;
		
		cout<<"ENTER YOUR PREVIOUS TEST RESULT: "<<endl;
		cin>>previoustest;
		
		cout<<"ENTER YOUR  AGE: "<<endl;
		cin>>age;
		
	}
	string getname( ){
		return name;
	}
	
	string getcnic( ){
		return Cnic;
	}
	string getaddress( ){
		return address;
	}
	string getprevioustest( ){
		return previoustest;
	}
	int getage( ){
		return age;
	}
	
	void displaypatientdetails(  ){
		cout<<"---------PATIENT DETAILS------------------"<<endl;
		cout<<"PATIENT NAME:"<<pname<<endl;
		cout<<"CNIC NO: "<<Cnic<<endl;
		cout<<"ADDRESS: "<<address<<endl;
		cout<<"PREVIOUS TEST REPORT: "<<previoustest<<endl;
		cout<<"AGE: "<<age<<endl;
		
	}
};
class Vaccine: public Patient{
	string xx;
	protected:
string vcheck,bookv,firstdose,seconddose,date;
public:
	Vaccine()
	{
		
	}
	
	Vaccine(string name,string location,string timings, double center_no,double telephone_no,string status,string n,string cnic,string add, string pt, int a, string vc, string bv, string fd, string sd, string d):Patient(name,location,timings, center_no,telephone_no,status, n,cnic,add, pt,a)
	{
		vcheck=vc;
		bookv=bv;
		firstdose=fd;
		seconddose=sd;
		date=d;
	}
	void setadmin()
	{
		cout<<"Are vaccines availabe in stock?"<<endl;
		cin>>vcheck;
		if(vcheck=="yes"||vcheck=="Yes"||vcheck=="YES")
		{
			cout<<"Enter vaccine available for first dose: "<<endl;
			cin>>firstdose;
			cout<<"Enter vaccine available for second dose: "<<endl;
			cin>>seconddose;
		}
	}
	void setpatient()
	{
		if(vcheck=="yes"||vcheck=="Yes"||vcheck=="YES")
		{
			cout<<"---Booking Vaccination----"<<endl<<"These are the vaccines available: "<<firstdose<<" for firstdose and "<<seconddose<<" for second dose."<<endl<<"Which dose do you want to book?"<<endl;
			cin>>xx;
			cout<<"Enter date you want to book for."<<endl;
			cin>>date;
			if(xx=="first")
			{
				cout<<"Your first dose for "<<firstdose<<" has been booked on "<<date<<endl;
			}
			else if(xx=="second")
			{
				cout<<"Your second dose for "<<seconddose<<" has been booked on"<<date<<endl;
			}
		}
	}
//	void set_vaccine_details(string vc, string bv, string fd, string sd, string d ){
//		cout<<"ENTER VACCINE CHECK: "<<vcheck<<endl;
//		cin>>vcheck;
//		cout<<"PLEASE BOOKED VACCINE  : "<<endl;
//		cin>>bookv;
//		cout<<"ENTER FIRST DOSE: "<<firstdose<<endl;
//		cin>>firstdose;
//		cout<<"ENTER SECOND DOSE : "<<seconddose<<endl;
//		cin>>seconddose;
//		cout<<"ENTER  DATE: "<<date<<endl;
//		cin>>date;
//		
//	}
	string getvc()
	{
		return vcheck;
	}
	string getbv()
	{
		return bookv;
	}
	string getfd()
	{
		return firstdose;
	}
	string getsd()
	{
		return seconddose;
	}
	string getd()
	{
		return date;
	}
	
	void display_vaccine_details( ){

		cout<<"YOUR VACCINE DETIALS ARE:"<<endl<<endl;
		cout<<"VACCINE CHECK: "<<vcheck<<endl;
		cout<<"FIRST DOSE: "<<firstdose<<endl;
		cout<<"SECOND DOSE : "<<seconddose<<endl;
		cout<<"DATE: "<<date<<endl;
	}
};
//class Patient:public VaccinationCenter{
//string pname,Cnic,address,previoustest;
//int age;
//public:
//	Patient(string name,string location,string timings, double center_no,double telephone_no,string status, string vc, string bv, string fd, string sd, string d, string n,string cnic,string add, string pt, int a):
//};
class VaccineCard:public Vaccine{
public:
	VaccineCard()
	{
		
	}
	
	VaccineCard(string name,string location,string timings, double center_no,double telephone_no,string status,string n,string cnic,string add, string pt, int a, string vc, string bv, string fd, string sd, string d):Vaccine(name, location,timings, center_no, telephone_no,status, n,cnic,add, pt,  a,  vc,  bv,  fd, sd,  d){}
	
	void displayVcard(  ){
		cout<<"---------VACCINATION CARD------------------"<<endl;
		cout<<"PATIENT NAME:"<<pname<<endl;
		cout<<"CNIC NO: "<<Cnic<<endl;
		cout<<"ADDRESS: "<<address<<endl;
		cout<<"PREVIOUS TEST REPORT: "<<previoustest<<endl;
		cout<<"AGE: "<<age<<endl;
	
		cout<<"VACCINE CHECK: "<<vcheck<<endl;
		cout<<"FIRST DOSE: "<<firstdose<<endl;
		cout<<"SECOND DOSE : "<<seconddose<<endl;
		cout<<"DATE: "<<date<<endl;
		
	}
	
	
};
class CovidTest: public Patient {
string booktest;
protected:
double oxygenlevel; //test result ka bh bnao aik variable
public:
	CovidTest()
	{
		
	}
	CovidTest(string name,string location,string timings, double center_no,double telephone_no,string status, string n,string cnic,string add, string pt, int a,string booktest,double oxygenlevel):Patient(name,location,timings, center_no,telephone_no,status, n,cnic,add, pt,a)
	{
		this->booktest=booktest;
		this->oxygenlevel=oxygenlevel;
	}
	void set_Covidtest__detials(){
		cout<<"BOOKED YOUR TEST"<<endl;
		cin>>booktest;
	    
	    cout<<"ENTER YOUR OXYGEN LEVEL"<<endl;
		cin>>oxygenlevel;
	}
	string getbookt()
	{
		return booktest;
	}
	double getoxylevel()
	{
		return oxygenlevel;
	}
	  
	void displayCovidtest( ){
		cout<<"YOUR DETAILS ARE:"<<endl;
		cout<<"TEST BOOKING: "<<booktest<<endl;
		cout<<"OXYGEN LEVEL: "<<oxygenlevel<<endl;
		
	}
	
};
class Emergency: public CovidTest{
public:
	Emergency()
	{
		
	}
	
	Emergency(string name,string location,string timings, double center_no,double telephone_no,string status, string n,string cnic,string add, string pt, int a,string booktest,double oxygenlevel):CovidTest(name,location,timings, center_no,telephone_no,status, n,cnic,add, pt,a,booktest,oxygenlevel){}
	void help()
	{
		if(oxygenlevel<50)
		{
			cout<<"You require emergency services. Please visit your nearest hospital as soon as possible!!!!"<<endl;
		}
	}
};
	


int main()
{
	int n1,n2,c3;
	do
	{
		cout<<"-----WELCOME-----"<<endl<<"-----Choose from the options below-----"<<endl<<"1. Press 1 for Admin"<<endl<<"2. Press 2 for patient"<<endl<<"3. Press 3 to exit"<<endl;
		cin>>n1;
		if(n1==1)
		{
			do
			{
				cout<<"1. Press 1 to add vaccination center."<<endl<<"2. Press 2 to add vaccine details."<<endl<<"3. Press 3 to print center details."<<endl<<"4. Press 4 to exit."<<endl;
				cin>>n2;
				switch(n2)
					{
						case 1:
							{
								VaccinationCenter obj;
							//	obj.setdata();
//								obj.setdata();
                                obj.adddatafiling();
                               
								
								break;
							}
						case 2:
							{
								Vaccine obj;
								obj.setdata();
								break;
							}
						case 3:
							{
								VaccinationCenter obj1;
								obj1.displayVaccinationdatafiling();
							//	obj.display();
								break;
							}
						case 4:
							{
								break;
							}
						default:
							{
								cout<<"Wrong input!!!!!"<<endl;
								break;
							}
					}
			}while(n2!=4);
		}
		else if(n1==2)
		{
			do
			{
				
				cout<<"1. Press 1 to enter patient data."<<endl<<"2. Press 2 to book vaccine."<<endl<<"3. Press 3 to set Covid details."<<endl<<"4. Press 4 to display patient details."<<endl<<"5. Press 5 to print vaccination card."<<endl<<"6. Press 6 to print vaccination details."<<endl<<"7. Press 7 to print Covid test booking details."<<endl<<"8. Press 8 to print center details."<<endl<<"9. Press 9 to exit."<<endl;
				cin>>c3;
				switch(c3){
					
					case 1:{
						Patient obj2;
						obj2.setpatientdetails();
						break;
					}
					
					case 2:
						{
							Vaccine obj3;
							obj3.setpatient();
							break;
						}
					case 3:{
						CovidTest obj4;
						obj4.set_Covidtest__detials();
						break;
					}
					
					case 4:{
						Patient obj5;
						obj5.displaypatientdetails(  );
						break;
					}
					
					case 5:{
						VaccineCard obj6;
						obj6.displayVcard(  );
						break;
					}
					case 6:{
						Patient obj9;
						obj9.displaypatientdetails(  );
						Vaccine obj7;
						obj7.display_vaccine_details( );
						break;
					}
					
					case 7:{
						Patient obj9;
						obj9.displaypatientdetails(  );
						CovidTest obj8;
						obj8.displayCovidtest( );
						break;
					}
					
					case 8:{
						
						VaccinationCenter obj10;
						obj10.display();
						break;
					}
					
					case 9:{
						cout<<"EXIT"<<endl;
						break;
					}
				}
			}while(c3!=9);
		}
	}while(n1!=3);
	
}
