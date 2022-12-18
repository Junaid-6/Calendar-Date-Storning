#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
string month_name[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
class Date{
	short day, month; int year;  char format;
	public:
		Date(){this->day=1; this->month=1; this->year=2000; this->format = 'D';}		
		Date(short month, short day,  int year){
			if(year%4 == 0) month_days[1] = 29; //Leap Year
			
			if(year>0 && day <= month_days[month-1] && day >= 1 && month <= 12 && month >= 1)
				{	this->day = day;
					this->month = month;
					this->year = year;
					this->format = 'D';
				}
			else
				{ this->day=1; this->month=1; this->year=2000; this->format = 'D';	}				
		}
		
		void input(){
			bool date = false;
			while(!date){
				cout<<"Enter Date (month/day/year): ";
				char slice;
				cin>>month>> slice&&slice=='/' && cin>>day>>slice&&slice=='/' && cin>>year;
				
				if(year%4 == 0 || year%400==0) { month_days[1] = 29;} // leap year				      
				if(year<0){
				cout<<"The year can't be Negtive : "<<year <<endl;
				}			
				if(month > 12 || month < 1){
				cout<<"The month you enter "<<month<<" is out of range please  (1 to 12) "<<endl;
				}				
				if(day > month_days[month-1] || day <= 0){
					if(!(month>12 || month < 0))
						cout<<"The day  "<<day<<" is out of range for month "<<month_name[month-1]<<"(1 to "<<month_days[month-1]<<")"<<endl;
					else
						cout<<"The day you enter "<<day<<" is out of range for month "<<month;}
				if(!(year<0||month > 12 || month < 1||day > month_days[month-1] || day <= 0)){
					date = true;
					break;}
				cout<<"\n\aPlease enter date again."<<endl;
				}
		    }
		    
		void show(){
			display_format();				
		}
		
		void display_format(){
			string year, month, day;
			switch(this->format){
				case 'D':
					cout<<"Date: "<<this->month<<"/"<<this->day<<"/"<<this->year;
					break;
				case 'T':
					year = to_string(this->year);
					day = to_string(this->day);
					month = to_string(this->month);
					cout<<"Date: ";					
					if(this->month < 10)
						month = "0"+to_string(this->month);													
					if(this->day < 10) 
						day = "0"+to_string(this->day);	
																
					cout<<month<<"/"<<day<<"/";
					for(int i = year.size()-2; i <year.size(); i++)
						cout<<year[i]; 								
					break;
				case 'L':
					cout<<"Date: "<<month_name[this->month-1]<<" "<<this->day<<","<<this->year;
					break;
				case 'J':
					cout<<"Date: "<<setw(2)<<setfill('0')<<this->year%100<<"/";
					int jday = this->day;
					for(int i=0; i<this->month-1; i++){
						jday += month_days[i];
					}cout<<jday;				
			}
			cout<<endl;
		}
		
		bool Set(short month , short day, int year){
			bool set = false;
			if(year%4 == 0) month_days[1] = 29; //leap year
			if(year > 0){
				if(month <= 12 && month > 0){
					if(day <= month_days[month-1] && day > 0){
						this->day = day;
						this->month = month;
						this->year = year;
						set = true;					
					}
				}
			}
			return set;
		}
		int GetMonth()	{ return this->month; }
		int GetDay()	{ return this->day;	  }
		int GetYear()	{ return this->year;  }
		
		bool SetFormat(char choice){			
			cout<<"\n";
			if(choice =='D'||choice =='T'||choice=='L'||choice=='J') 
				{ this->format = choice; return true; }
			else	
				return false;
		}
		
		void Increment(int numDays = 1){
			for(int i=0; i < numDays; i++){
				this->day++;
				if(this->year%4==0||this->year%400==0) month_days[1] = 29;  // Leap year
				if(this->day > month_days[this->month-1]){
					month_days[this->month-1]++;
					this->day = 1;
					this->month += 1;
						if(this->month > 12 ){
							this->year++;
							this->month = 1;
						}
				}
			} 
		}
				
		int Compare(const Date& d){
			
			if(this->year > d.year) return 1;
			else if(d.year > this->year) return -1;	
			
			else if(this->month > d.month) return 1;
			else if(d.month > this->month) return -1;
			
			else if(this->day > d.day) return 1;
			else if(d.day > this->day) return -1;
			else
				return 0;			
			}
};
