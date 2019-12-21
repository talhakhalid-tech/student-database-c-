#include<iostream>
#include <iomanip>
#include<string>
#define size 70
#define col 6
using namespace std;
struct dates{
	int date,month,year;
};
class student{
	int usage;
	dates dob[size],doa[size];
	int reg[size],total[size];
	int sub[size][col];
	char grade[size];
	float perc[size];
	string name[size];
	string f_name[size];
public:
	int create_DB();
	char gradeof(float);
	void mysearch();
	void update();
	void display_all();
	void display_one();
	void delete_reg();
	void append();
	void sortdata();
	bool datecheck(int,int,int);
};
int main()
{
	system("color 3F");
	student stud;
	char display;
	int choice=0,usage=0;
	while(choice != 7)
	{
		cout<<"\n1. Create Database\n2. Search a student  result\n3. Update Student Record\n"
	    <<"4. Display Result:\n\tA. All students.\n\tB. particular student. \n5. Delete a result.\n6. Append new result.\n7. Exit\nSo what's your choice:  ";
	cin>>choice;
	switch (choice)
	{
		case 1:
	        {
				usage = stud.create_DB();
			    break;
	        }
		case 2:
			{
				if(usage !=0){
				stud.mysearch();
				break;
				}
				else{
					system("CLS");
					cout<<"\t\t\t\tyou must create database first!!!";
					break;
				}
			}
		case 3:
			{
				if(usage !=0){
				stud.update();
				break;
				}
				else{
					system("CLS");
					cout<<"\t\t\t\tyou must create database first!!!";
					break;
				}
			}
		case 4:
			{
				if(usage !=0){
				cout<<"A or B : ";
				cin>>display;
				switch (display)
				{
					case 'a':
					case 'A':
						{
							stud.display_all();
							break;
						}
					case 'b':
					case 'B':
						{
							stud.display_one();
							break;
						}
					default:
						{
							cout<<"invalid choice";
						}
				}
				break;
				}
				else{
					system("CLS");
					cout<<"\t\t\t\tyou must create database first!!!";
					break;
				}
			}
		case 5:
			{
				if(usage !=0){
				stud.delete_reg();
				break;
				}
				else{
					system("CLS");
					cout<<"\t\t\t\tyou must create database first!!!";
					break;
				}
			}
		case 6:
			{
				if(usage !=0){
				stud.append();
				break;
				}
				else{
					system("CLS");
					cout<<"\t\t\t\tyou must create database first!!!";
					break;
				}
			}
		case 7:
			{
				cout<<"GoodBye!"<<endl;
				break;
			}
		default:
			{
				cout<<"invalid choice:";
			}
	}
	}
 system("pause");
 return 0;
}
int student::create_DB()
{
	system("CLS");
	int sum;
	bool check=true;
	do{
	cout<<"Enter the size of database (max 70): ";
	cin>>usage;
	}while(usage<=0 || usage>70);
	for(int i=0;i<usage;i++)
	{
		sum=0;
		do{
		cout<<"Enter the reg# of student No."<<i+1<<"   ";
		cin>>reg[i];
		for(int x=0;x<i;x++){
			if(reg[i]==reg[x]){
				cout<<"reg# must be unique!!!"<<endl;
				reg[i]=0;
			}
		}
		}while(reg[i] <999 || reg[i] > 9999);
			do{
				cout<<"enter the name of reg No."<<reg[i]<<":    ";
				cin>>name[i];
				for(int j=0;j<name[i].length();j++){
					if(!isalpha(name[i][j])){
						name[i] = "null";
						cout<<"name should only contain alphabet"<<endl;
					}
				}	
			}while(name[i] ==  "null");
			do{
				cout<<"enter the father name of reg No."<<reg[i]<<":    ";
				cin>>f_name[i];
				for(int j=0;j<f_name[i].length();j++){
					if(!isalpha(f_name[i][j])){
						f_name[i] = "null";
						cout<<"father name should only contain alphabet"<<endl;
					}
				}	
			}while(f_name[i] ==  "null");
			do{
				cout<<"enter the date of birth of student (format: DD MM YY) enter space to split date month and year: ";
				cin>>dob[i].date>>dob[i].month>>dob[i].year;
				check = datecheck(dob[i].date,dob[i].month,dob[i].year);
			}while(check);
			do{
				cout<<"enter the date of Admission of student (format: DD MM YY) enter space to split date month and year: ";
				cin>>doa[i].date>>doa[i].month>>doa[i].year;
				check = datecheck(doa[i].date,doa[i].month,doa[i].year);
			}while(check);
			for(int j=0;j<col;j++){
			do{
			cout<<"Enter the marks of subject#"<<j+1<<" of reg No."<<reg[i]<<"(max 100):   ";
			cin>>sub[i][j];
			}while(sub[i][j] <0 || sub[i][j] >100);
		sum += sub[i][j];
		}
		total[i] = sum;
		perc[i]= (total[i] / 600.0)* 100;
		grade[i]= gradeof(perc[i]);
    }
	sortdata();
	return usage;
}
char student::gradeof(float x)
{
	char grade;
	if(x <= 100.0 && x >= 80.0)
	{
		grade = 'A';
		return grade;
	}
	else if(x < 80.0 && x >= 70.0)
	{
		grade = 'B';
		return grade;
	}
	else if(x < 70.0 && x >= 60.0)
	{
		grade = 'C';
		return grade;
	}
	else
	{
		grade = 'F';
		return grade;
	}
	
}
void student::mysearch()
{
	system("CLS");
	int reg_search,count=0;
	cout<<"enter the registration number you want to search: ";
	cin>>reg_search;
	for(int i=0;i<usage;i++)
	{
		if(reg[i] == reg_search)
		{
			cout<<"registration number found successfully";
		}
		else
			count++;
	}
	if(count == usage)
		cout<<"invalid registration number";
}
void student::update()
{
	system("CLS");
	int update_res,count=0,sum;
	bool check =true;
	cout<<"enter the registration number of which you want to update information: ";
	cin>>update_res;
	for(int i=0;i<usage;i++)
	{
				if(reg[i] == update_res)
		{
			sum=0;
			do{
				cout<<"Enter the updated reg#:   ";
				cin>>reg[i];
			}while(reg[i] <999 || reg[i] > 9999);
		do{
				cout<<"enter the name of reg No."<<reg[i]<<":    ";
				cin>>name[i];
				for(int j=0;j<name[i].length();j++){
					if(!isalpha(name[i][j])){
						name[i] = "null";
						cout<<"name should only contain alphabet"<<endl;
					}
				}	
			}while(name[i] ==  "null");
		do{
				cout<<"enter the father name of reg No."<<reg[i]<<":    ";
				cin>>f_name[i];
				for(int j=0;j<f_name[i].length();j++){
					if(!isalpha(f_name[i][j])){
						f_name[i] = "null";
						cout<<"father name should only contain alphabet"<<endl;
					}
				}	
			}while(f_name[i] ==  "null");
		do{
				cout<<"enter the updated date of birth of student (format: DD MM YY) enter space to split date month and year: ";
				cin>>dob[i].date>>dob[i].month>>dob[i].year;
				check = datecheck(dob[i].date,dob[i].month,dob[i].year);
			}while(check);
		do{
				cout<<"enter the updated date of Admission of student (format: DD MM YY) enter space to split date month and year: ";
				cin>>doa[i].date>>doa[i].month>>doa[i].year;
				check = datecheck(doa[i].date,doa[i].month,doa[i].year);
			}while(check);
		total[i]=0;
		for(int j=0;j<col;j++){
			do{
				cout<<"Enter the updated marks of subject#"<<j+1 << " of reg No."<<reg[i]<<"(max 100):   ";
				cin>>sub[i][j];
			}while(sub[i][j] <0 || sub[i][j] >100);
		sum += sub[i][j];
		}
		total[i]=sum;
		perc[i] = (total[i] / 600.0)* 100;
		grade[i]= gradeof(perc[i]);
		}
		else
			count++;
			
	}
	if(count == usage){
		cout<<"invalid registration number\n";
	}
	else
		cout<<"result successfully updated!";
	sortdata();
}
void student::display_all()
{
	system("CLS");
	cout<<"Student.no  Reg#	 Name    Father-Name    DateOfBirth    DateOfAdmission   Sub.1    Sub.2    Sub.3    Sub.4    Sub.5    Sub.6    Total   Percentage   Grade\n";
	for(int i=0;i<usage;i++){
			cout<<setw(10)<<i+1<<"  "<<setw(4)<<reg[i]<<"   "<<setw(10)<<name[i]<<"    "<<setw(11)<<f_name[i]<<"    ";
			cout<<setw(4)<<dob[i].date<<"/"<<dob[i].month<<"/"<<dob[i].year<<"    "<<setw(8)<<doa[i].date<<"/"<<doa[i].month<<"/"<<doa[i].year<<"   ";
		for(int j=0;j<col;j++){
				cout<<setw(5)<<sub[i][j]<<"    ";
			}
		cout<<setw(5)<<total[i]<<"   "
			<<setw(10)<<perc[i]<<"   "<<setw(5)<<grade[i]<<endl;
	}
}
void student::display_one()
{
	system("CLS");
	int reg_display,count=0;
	cout<<"enter the registration number of student: ";
	cin>>reg_display;
	for(int i=0;i<usage;i++)
	{

		if(reg[i] == reg_display){
			cout<<"Student.no  Reg#	 Name    Father-Name    DateOfBirth    DateOfAdmission   Sub.1    Sub.2    Sub.3    Sub.4    Sub.5    Sub.6    Total   Percentage   Grade\n";
				cout<<setw(10)<<i+1<<"  "<<setw(4)<<reg[i]<<"   "<<setw(10)<<name[i]<<"    "<<setw(11)<<f_name[i]<<"    ";
		cout<<setw(4)<<dob[i].date<<"/"<<dob[i].month<<"/"<<dob[i].year<<"    "<<setw(8)<<doa[i].date<<"/"<<doa[i].month<<"/"<<doa[i].year<<"   ";
		for(int j=0;j<col;j++){
				cout<<setw(5)<<sub[i][j]<<"    ";
			}
		cout<<setw(5)<<total[i]<<"   "
			<<setw(10)<<perc[i]<<"   "<<setw(5)<<grade[i]<<endl;
	}
		else
			count++;
	}
	if(count == usage)
		cout<<"invalid registration number";
}
void student::delete_reg()
{
	system("CLS");
	int del, count=0;
	cout<<"Enter Registration number you want to delete : ";
	cin>>del;
	for(int i=0; i<usage; i++)
	{
		if(reg[i] == del)
		{
			for(int j=i; j<(usage-1); j++)
			{
				reg[j]=reg[j+1];
				name[j]=name[j+1];
				f_name[j]=f_name[j+1];
				dob[j].date=dob[j+1].date;
				dob[j].month=dob[j+1].month;
				dob[j].year=dob[j+1].year;
				doa[j].date=doa[j+1].date;
				doa[j].month=doa[j+1].month;
				doa[j].year=doa[j+1].year;
				for(int x=0;x<col;x++)
					sub[j][x]=sub[j+1][x];
				total[j]=total[j+1];
				grade[j]=grade[j+1];
				perc[j]=perc[j+1];
			}
			count++;
			break;
		}
	}
	if(count==0){
		cout<<"Invalid registration number!";
	}
	else{
		cout<<"Result deleted successfully!";
		usage--;
	}
}
void student::append()
{
	system("CLS");
			int choice=0,sum;
			bool check=true;
			while(choice  != -999){
				do{
					cout<<"enter the  registration number you want to append ( enter -999 to end appending ): ";
					cin>>choice;
					for(int x=0;x<usage;x++){
						if(choice==reg[x]){
							cout<<"reg# must be unique!!!"<<endl;
							choice=0;
						}
					}
				}while((choice < 999 || choice > 9999) && choice != -999);
			if(choice != -999){
			reg[usage]=choice;
				sum=0;
				do{
				cout<<"enter the name of reg No."<<reg[usage]<<":    ";
				cin>>name[usage];
				for(int j=0;j<name[usage].length();j++){
					if(!isalpha(name[usage][j])){
						name[usage] = "null";
						cout<<"name should only contain alphabet"<<endl;
					}
				}	
			}while(name[usage] ==  "null");
				do{
				cout<<"enter the father name of reg No."<<reg[usage]<<":    ";
				cin>>f_name[usage];
				for(int j=0;j<f_name[usage].length();j++){
					if(!isalpha(f_name[usage][j])){
						f_name[usage] = "null";
						cout<<"father name should only contain alphabet"<<endl;
					}
				}	
			}while(f_name[usage] ==  "null");
				do{
				cout<<"enter the date of birth of student (format: DD MM YY) enter space to split date month and year: ";
				cin>>dob[usage].date>>dob[usage].month>>dob[usage].year;
				check = datecheck(dob[usage].date,dob[usage].month,dob[usage].year);
			}while(check);
				do{
				cout<<"enter the date of Admission of student (format: DD MM YY) enter space to split date month and year: ";
				cin>>doa[usage].date>>doa[usage].month>>doa[usage].year;
				check = datecheck(doa[usage].date,doa[usage].month,doa[usage].year);
			}while(check);
				for(int j=0;j<col;j++){
					do{
					cout<<"Enter the marks of subject#"<<j+1 << " of reg No."<<reg[usage]<<"(max 100):   ";
					cin>>sub[usage][j];
					}while(sub[usage][j] <0 || sub[usage][j] >100);
				sum += sub[usage][j];
				}
				total[usage] = sum;
				perc[usage] = (total[usage] / 600.0)* 100;
				grade[usage]= gradeof(perc[usage]);
			usage++;
			cout<<"result appended successfully!!!!"<<endl;
			}
			}
		sortdata();
}
void student::sortdata(){
	int min;
	for(int i=0;i<usage-1;i++){
		min = i;
		for(int j=i+1;j<usage;j++)
			if(reg[j]<reg[min])
		min = j;
		swap(reg[i],reg[min]);
		for(int x = 0 ; x < col ; x++){
			swap(sub[i][x],sub[min][x]);
		}
		swap(name[i],name[min]);
		swap(dob[i].date,dob[min].date);
		swap(dob[i].month,dob[min].month);
		swap(dob[i].year,dob[min].year);
		swap(doa[i].date,doa[min].date);
		swap(doa[i].month,doa[min].month);
		swap(doa[i].year,doa[min].year);
		swap(f_name[i],f_name[min]);
		swap(total[i],total[min]);
		swap(perc[i],perc[min]);
		swap(grade[i],grade[min]);

		}
}
bool student::datecheck(int date,int month,int year){
	bool check=false;
	switch (month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			{
				if(date > 31 || date < 1){
					cout<<"Invalid date"<<endl;
					check= true;
				}
				break;
			}

		case 4:
		case 6:
		case 9:
		case 11:
			{
				if(date > 30 || date < 1){
					cout<<"Invalid date"<<endl;
					check = true;
				}
				break;
			}
		case 2:
			{
				if(date > 29 || date < 1){
					cout<<"Invalid date"<<endl;
					check=true;
				}
				break;
			}
		default:
			{
				cout<<"Invalid month"<<endl;
				check = true;
			}
	}
	if(year > 9999 || year < 1000){
		cout<<"Invalid year"<<endl;
		check=true;
	}
	return check;
}