#include"date.h"
int main(){
	Date date;
	cout<<"Default date: "; date.show();
	cout<<"\nSetting Date: "; date.input();
	Date newdate;
	cout<<"\nCreating New Date: "; newdate.input();
	cout<<"\nIncreament in new date defualt :"; newdate.Increment(); newdate.show();
	cout<<"\nSetting style: \n"; 
	cout<<"Style Two Digit : \b"; newdate.SetFormat('T');  newdate.show();
	cout<<"Style Long : \b"; newdate.SetFormat('L');  newdate.show();
	cout<<"Julian : \b"; newdate.SetFormat('J');  newdate.show();
	cout<<"Style Defualt : \b"; newdate.SetFormat('D');  newdate.show();
	cout<<"New date month = "<<newdate.GetMonth();
	cout<<"\nNew date day = "<<newdate.GetDay();
	cout<<"\nNew date year = "<<newdate.GetYear();
	cout<< "\nFirst date: "; date.show();
	cout<<"\nNew date: "; newdate.show();
	cout<<"\nDate Comparison\n";
	cout<<"Defualt Date.Compare(newDate)  : \b "; cout<<date.Compare(newdate);
	cout<<"\nnewDate.Compare(defualtdate) : \b "; cout<<newdate.Compare(date);
	cout<<"\nIncreamenting : \b";
	cout<< "\nFirst date: "; date.show();
	int day; cout<<"\nEnter number of days"; cin>>day; date.Increment(day);
	cout<<"\nNow first date: "; date.show();  

	


}