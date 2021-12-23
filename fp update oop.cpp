#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

#include<conio.h>//console input output
#include<string.h>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info
using namespace std;
class Covac{   //ABSTRACT CLASS
	
	      public:
	    	Covac(){
			}
		virtual void setdata()=0;
	    virtual void adddatafiling( )=0;
	    virtual void displayVaccinationdatafiling()=0;
	    virtual void display()=0;
};
class VaccinationCenter:public Covac{
protected:
	char* name;
   string location,timings;
double  center_no, telephone_no;
string status;                              //status=1 open else closed
public:
	VaccinationCenter()
	{
		name=new char[100]; //DMA
	}
	
	VaccinationCenter(char *n,string location,string timings, double center_no,double telephone_no,string status)
	{
		name=n;
		this->location=location;
		this->timings=timings;
		this->center_no=center_no;
		this->telephone_no=telephone_no;
		this->status=status;
	}
	void setdata()
	{

		
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
		cout<<"------Center data added successfully!!!-----"<<endl;
		

		
	}
	
	void adddatafiling( ){
		VaccinationCenter V;
		fstream f;
		f.open("vaccinationcenter.txt", ios::app);
		if(!f){
			cout<<"FILE NOT OPEN"<<endl;
			
		}
		else{
			V.setdata( );
			f<<"\n";
			f<<V.name;f<<"\n";
			f<<V.location;f<<"\n";
			f<<V.timings;f<<"\n";	
			f<<V.center_no;f<<"\n";
			f<<V.telephone_no;f<<"\n";
			f<<V.status;
			
			f.close();
		}
		
	}
	  
	void displayVaccinationdatafiling(){
		
		VaccinationCenter V;
		fstream f1;
		f1.open("vaccinationcenter.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof()){
			//f1.read((char*) &V,sizeof(VaccinationCenter));
			f1>>V.name;
			f1>>V.location;
			f1>>V.timings;
			f1>>V.center_no;
			f1>>V.telephone_no;
			f1>>V.status;
			//cout<<V.name;
			V.display();
		//	V.display();
			cout<<"\n\n";
		}

	}}
	void display()
	{
		cout<<"Center name: "<<name<<endl<<"Location: "<<location<<endl<<"Center timings: "<<timings<<endl<<"Center Number: "<<center_no<<endl<<"Telephone number: "<<telephone_no<<endl<<"Status: "<<status;
	}
	
	~VaccinationCenter( ){ //DESTRUCTOR
		delete name;
	}
	
	template <class X> void Centerstatus( X a)// a is oxygen level{
	{
		
		
			cout<<"CENTER STATUS IS"<<a<<endl;
		}
};
class Patient:public VaccinationCenter{
	
	static int totalcases;
	protected:
   string pname,address,previoustest;
   string  Cnic;
   int age;
  // static covidresult it will tells total covid positive and ratio.
public:
	Patient()
	{
		
	}
	
	Patient(char *name,string location,string timings, double center_no,double telephone_no,string status, string n,string cnic,string add, string pt, int a):VaccinationCenter(name,location, timings, center_no,telephone_no,status)
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
		// new added
		cin.ignore();
		
		cout<<"ENTER YOUR PREVIOUS TEST RESULT: "<<endl;
		cin>>previoustest;
		
		try {
         cout<<"ENTER AGE"<<endl;
          cin>>age;
         if (age <=0) {
        //cout << "Access granted - youd enough.";
          throw ;
       }     
	   else {

  }
}
     catch (...) {
    cout << "Access denied - AGE CANT BE NEGATIVE.\n";
   }		
	
	}

	void adddatafiling()
	{
		Patient p;
		fstream f;
		f.open("patientdetails.txt", ios::app);
		if(!f){
			cout<<"FILE NOT OPEN"<<endl;
			
		}
		else{
			p.setpatientdetails( );
			f<<"\n";
			f<<p.pname;f<<"\n";
			f<<p.Cnic;f<<"\n";
			f<<p.address;f<<"\n";	
			f<<p.previoustest;f<<"\n";
			f<<p.age;f<<"\n";
			
			f.close();
		}
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
	void displaypatientfiling()
	{
		Patient p;
		fstream f1;
		f1.open("patientdetails.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof()){
			f1>>p.pname;
			f1>>p.Cnic;
			f1>>p.address;	
			f1>>p.previoustest;
			f1>>p.age;
			
			p.displaypatientdetails();
			cout<<"\n\n";
		}
			f1.close();
			}
}
      friend void totalcasescount( const Patient p );
};
   int Patient::totalcases=50000; //static of patient class
   void totalcasescount( const Patient pt ){
   	fstream f1;
   	Patient p;
   	f1.open("patientdetails.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof()){
			f1>>p.pname;
			f1>>p.Cnic;
			f1>>p.address;	
			f1>>p.previoustest;
			f1>>p.age;
			
			
	   }
	   if(p.previoustest=="positive"){
   		    p.totalcases++;
   		    cout<<"TOTAL CASES ARE: "<<p.totalcases<<endl;
			
		}
			f1.close();
			}

   }
   
class Vaccine: public Patient{
	string xx;
	protected:
    string vcheck,bookv,firstdose,seconddose,date;
public:
	Vaccine()
	{
		
	}
	
	Vaccine(char* name,string location,string timings, double center_no,double telephone_no,string status,string n,string cnic,string add, string pt, int a, string vc, string bv, string fd, string sd, string d):Patient(name,location,timings, center_no,telephone_no,status, n,cnic,add, pt,a)
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
	void adminfiling()
	{
		Vaccine v;
		fstream f;
		f.open("adminvaccine.txt", ios::app);
		if(!f){
			cout<<"FILE NOT OPEN"<<endl;
			
		}
		else{
			v.setadmin();
			f<<v.vcheck;f<<endl;
			f<<v.firstdose;f<<endl;
			f<<v.seconddose;f<<endl;
			f.close();
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
				cout<<"Your second dose for "<<seconddose<<" has been booked on "<<date<<endl;
			}
		}
	}
	void patientfiling()
	{
		
		
		Vaccine v;
		fstream f1;
		fstream f2;
		f1.open("adminvaccine.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof()){
			f1>>v.vcheck;
			f1>>v.firstdose;
			f1>>v.seconddose;
			v.setpatient();
			f2.open("vaccinedate.txt",ios::app);
			if(!f2){
			cout<<"FILE NOT OPEN"<<endl;
			
		}
		else{
			f2<<v.date;f2<<endl;
			f2.close();
			
		}
			
			cout<<"\n\n";
		}
			f1.close();
			}
}
	
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

		cout<<"--------------YOUR VACCINE DETIALS ARE----------------"<<endl<<endl;
		cout<<"Vaccine availability: "<<vcheck<<endl;
		cout<<"FIRST DOSE: "<<firstdose<<" on "<<date<<endl;
		cout<<"SECOND DOSE : "<<seconddose<<" on "<<date<<endl;
	}
	void displayfiling()
	{
		Vaccine v;
		fstream f1,f2;
		f1.open("adminvaccine.txt", ios::in);
		f2.open("vaccinedate.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		if(!f2){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof()){
			f1>>v.vcheck;
			f1>>v.firstdose;
			f1>>v.seconddose;
			while(!f2.eof())
			{
				f2>>v.date;
				
				v.display_vaccine_details();
				
			}


			cout<<"\n\n";
		}
			f1.close();
			f2.close();
			}
	}

           friend istream &operator>>( istream  &input, Vaccine &v) { 
//          string vcheck,bookv,firstdose,seconddose,date;
            cout<<"Enter vaccine available for first dose: "<<endl;
			input>>v.firstdose;
			cout<<"Enter vaccine available for second dose: "<<endl;
			input>>v.seconddose;
             
             return input;            
      }
	
			friend ostream &operator<<( ostream &output, const  Vaccine &V ) { 
            cout<<"FIRST DOSE"<<endl;
			output<<V.firstdose;
			cout<<"SECOND DOSE: "<<endl;
			output<<V.seconddose;
            return output;            
      }
	
};

class VaccineCard:public Vaccine{
public:
	VaccineCard()
	{
		
	}
	
	VaccineCard(char* name,string location,string timings, double center_no,double telephone_no,string status,string n,string cnic,string add, string pt, int a, string vc, string bv, string fd, string sd, string d):Vaccine(name, location,timings, center_no, telephone_no,status, n,cnic,add, pt,  a,  vc,  bv,  fd, sd,  d){}
	
	void displayVcard(  ){
		cout<<"---------VACCINATION CARD------------------"<<endl;
		cout<<"PATIENT NAME:"<<pname<<endl;
		cout<<"CNIC NO: "<<Cnic<<endl;
		cout<<"ADDRESS: "<<address<<endl;
		cout<<"PREVIOUS TEST REPORT: "<<previoustest<<endl;
		cout<<"AGE: "<<age<<endl;
	
		cout<<"FIRST DOSE: "<<firstdose<<" on "<<date<<endl;
		cout<<"SECOND DOSE : "<<seconddose<<" on "<<date<<endl;
		
	} 
	   friend ostream &operator<<( ostream &output, const  VaccineCard &V ) { 
         output << "YOUR DETAILS"<<endl;
         return output;            
      }


	
	void vaccinecardfiling( ){
	fstream f1;
	fstream f2,f3;
	VaccineCard p;
	f1.open("patientdetails.txt", ios::in);
	f2.open("adminvaccine.txt", ios::in);
	f3.open("vaccinedate.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		if(!f2){
			cout<<"FILE NOT OPEN"<<endl;
		}
		if(!f3){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof()){
			f1>>p.pname;
			f1>>p.Cnic;
			f1>>p.address;	
			f1>>p.previoustest;
			f1>>p.age;
			while(!f2.eof())
			{
				f2>>p.vcheck;
				f2>>p.firstdose;
				f2>>p.seconddose;
				while(!f3.eof())
				{
					f3>>p.date;
					p.displayVcard();
				}

			}
	
			cout<<"\n\n";
		}
			f1.close();
			f2.close();
			f3.close();
			}
			
			
	
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
	CovidTest(char* name,string location,string timings, double center_no,double telephone_no,string status, string n,string cnic,string add, string pt, int a,string booktest,double oxygenlevel):Patient(name,location,timings, center_no,telephone_no,status, n,cnic,add, pt,a)
	{
		this->booktest=booktest;
		this->oxygenlevel=oxygenlevel;
	}

	void bookcovidtest()
	{
		cout<<"BOOKED YOUR TEST"<<endl;
	}
	void oxylevel()
	{
		cout<<"ENTER YOUR OXYGEN LEVEL: "<<endl;
		cin>>oxygenlevel;
	}
	void adddatafiling()
	{
		CovidTest ct;
		fstream f;
		f.open("CovidTest.txt", ios::app);
		if(!f){
			cout<<"FILE NOT OPEN"<<endl;
			
		}
		else{
			ct.oxylevel();
			f<<"\n";
//			f<<ct.booktest;f<<"\n";
			f<<ct.oxygenlevel;f<<"\n";
			
			f.close();
		}
	}
	void displayCovidTest()
	{
		CovidTest ct;
		fstream f1;
		f1.open("CovidTest.txt", ios::in);
		if(!f1){
			cout<<"FILE NOT OPEN"<<endl;
		}
		else{
		
		while(!f1.eof())
		{
			
//			f1<<ct.booktest;
			f1>>ct.oxygenlevel;
			
			ct.displayoxylevel();	
			
			cout<<"\n\n";
		}
			f1.close();
			}
}
	
	
	
	string getbookt()
	{
		return booktest;
	}
	double getoxylevel()
	{
		return oxygenlevel;
	}
	  
	void displayoxylevel( ){

		cout<<"OXYGEN LEVEL: "<<oxygenlevel<<endl;
		
	}
	
};
class Emergency: public CovidTest{
public:
	Emergency()
	{
		
	}
	
	Emergency(char* name,string location,string timings, double center_no,double telephone_no,string status, string n,string cnic,string add, string pt, int a,string booktest,double oxygenlevel):CovidTest(name,location,timings, center_no,telephone_no,status, n,cnic,add, pt,a,booktest,oxygenlevel){}
	void help()
	{
		if(oxygenlevel<50)
		{
			cout<<"You require emergency services. Please visit your nearest hospital as soon as possible!!!!"<<endl;
		}
	}
	
	template <class X> void message( X a)// a is oxygen level{
	{
		
		
			cout<<"YOU GIVE MESSAGE"<<a<<endl;
		}
	
};
	

//-----------------------------------------------------------------;
int password()//b
{
    char cname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\n\t\t\t\t\tCAPTURE:-> "<<cap<<endl;
    cout<<" Please enter the valid capture :-   ";
    cin>>capt;
    if( (strcmp(cname,"taha")==0) && (strcmp(pass,"Fast123")==0) && cap==capt)
        return 1;
    else
        return 0;
}




int main()
{
	
	
	int n1,n2,c3;
	int k=3;
	cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
	cout<<" \n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVAC APPLICATION \xB3\xB2=\xB2=\xB2-\xB3\n\n "<<endl;
    cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
    B:
    system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t*******";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t*******\n";
    while(k>=1)
    {
    int c = password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--) //stop for 60 seconds
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
              goto B;
        }
    }
	
	int ch;
	do{
		do
	{
		cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 WELCOME TO THE VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl<<"\t\t\t-----Choose from the options below-----"<<endl<<endl<<"\t\t1. Press 1 for Admin"<<endl<<"\t\t2. Press 2 for patient"<<endl<<"\t\t3. Press 3 to exit"<<endl;
		cin>>n1;
		if(n1==1)
		{
			do
			{
				cout<<endl<<"\t\t1. Press 1 to add vaccination center."<<endl<<"\t\t2. Press 2 to add vaccine details."<<endl<<"\t\t3. Press 3 to print center details."<<endl<<"\t\t4. Press 4 to check total number of covid cases"<<endl<<"\t\t5. Press 5 to exit"<<endl;
				cin>>n2;
				switch(n2)
					{
						case 1:
							{
								
								Covac* obj;
								VaccinationCenter obj1;
								obj=&obj1;
							   //obj.setdata();
							    
                                obj->adddatafiling();
								
								break;
							}
						case 2:
							{
								
								Vaccine obj;
								obj.adminfiling();
								break;
							}
						case 3:
							{
								Covac* obj;
								
								VaccinationCenter obj1;
							//	if(obj1.)
								obj=&obj1;
								obj->displayVaccinationdatafiling();
							//	obj.display();
								break;
							}
						case 4:{
							 Patient P;
							 totalcasescount( P );
							break;
						}	
							
						case 5:
							{
								break;
							}
						default:
							{
								cout<<"Wrong input!!!!!"<<endl;
								break;
							}
					}
			}while(n2!=5);
		}
		else if(n1==2)
		{
			do
			{
				
				cout<<endl<<"\t\t1. Press 1 to enter patient data."<<endl<<"\t\t2. Press 2 to book vaccine."<<endl<<"\t\t3. Press 3 to enter oxygen level."<<endl<<"\t\t4. Press 4 to display patient details."<<endl<<"\t\t5. Press 5 to print vaccination card."<<endl<<"\t\t6. Press 6 to print vaccination details."<<endl<<"\t\t7. Press 7 to check oxygen level."<<endl<<"\t\t8. Press 8 to print center details."<<endl<<"\t\t9. Press 9 to book covid test."<<endl<<"\t\t10. Press 10 to see total number of covid cases for precautionary Measures"<<endl<<"\t\t11. Press 11 to exit"<<endl;
				cin>>c3;
				switch(c3){
					
					case 1:{
						Patient obj2;
						obj2.adddatafiling();
						break;
					}
					
					case 2:
						{
							Vaccine obj3;
							obj3.patientfiling();
							break;
						}
					case 3:{
						CovidTest obj4;
//						obj4.set_Covidtest__detials();
						obj4.adddatafiling();
						
						break;
					}
					
					case 4:{
						Patient obj5;
						obj5.displaypatientfiling();
						break;
					}
					
					case 5:{
						VaccineCard obj6;
						obj6.vaccinecardfiling(  );
						break;
					}
					case 6:{
						
						Vaccine obj7;
						obj7.displayfiling();
						break;
					}
					
					case 7:{
//						Patient obj9;
//						obj9.displaypatientdetails(  );
//						CovidTest obj8;
						Emergency obj;
						obj.displayoxylevel( );
						obj.help();
						break;
					}
					
					case 8:{
						Covac *obj;
						VaccinationCenter obj10;
						obj= &obj10;
						obj->displayVaccinationdatafiling();
						break;
					}
					
					case 9:{
						CovidTest obj;
						obj.bookcovidtest();
						break;
					}
					case 10:{
						Patient P;
						totalcasescount( P);
						break;
					}
					case 11:{
						
						break;
					}
					default:{
						
						break;
					}
					
				}
			}while(c3!=11);
		}
	}while(n1!=3);
	
}
		
		
	while(ch!=0);
	return 0;
}
