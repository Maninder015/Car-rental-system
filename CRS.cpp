#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<conio.h>

using namespace std;

class User{
    public:
        string Username;
        string Password;
        string dir;
        char ch;
        void getdata(int x){
            Sleep(1000);
            system("CLS");
            cout<<"Enter your Username(It should be Unique) : ";
            cin>>Username;
            while(1){
                if(x){
                    if(Unique()!=true){
                        cout<<"User already exists! Enter a unique username\n";
                        getdata(1);
                        return;
                    }
                    cout<<"Enter Password: ";
                    ch = _getch();
                    while (ch != 13)
                    {
                    Password.push_back(ch);
                    cout<<"*";
                    ch = _getch();
                    }
                    break;
                }
            }
            writedata();
            ofstream outa;
            dir = Username+".txt";
            outa.open(dir.c_str());
            outa<<"Car Company"<<"\t\t\t\t"<<"Car Model"<<"\t\t\t  "<<"Year"<<"\t\t\t\t\t "<<"Car Number"<<"\t\t\t\t "<<"Number of days"<<"\t\t\t   "<<"Rental fee";
            outa<<endl;
        }
    
    bool Unique(){
        ifstream inf;
        inf.open("UsernameData.txt", ios::in);
        string user;
        string pass;
        string line;
        if(!inf){
            cout<<"Unable to open file!";
            exit(0);
        }
        else{
            while(getline(inf, line)){
                if(line.compare(Username) == 0){
                    inf.close();
                    return false;
                }
                getline(inf, line);
            }
        }
        inf.close();
        return true;
    }

    void writedata(){
        ofstream outf;
        outf.open("UsernameData.txt", ios::app);
        outf<<Username<<"\n"<<Password<<"\n";
        cout<<"\nPlease Wait...........";
        Sleep(2000);
        system ("CLS");
        cout<<"\nYou are now a registered user.\n";
        cout<<"\n\nTaking you to Car Section.";
        cout<<"\n\nPlease wait.....";
        outf.close();
    }

    int login(){
        Sleep(1000);
        system("CLS");
        string userN;
        string passW;
        cout<<"Enter Your Username : ";
        cin>>userN;
        Username = userN;
        ifstream newfile;
        string line;
        char  c;
        newfile.open("UsernameData.txt");
        while(getline(newfile, line)){
                if(line.compare(userN) == 0){
                    getline(newfile, line);
                    cout<<"Enter Password : ";
                    c =_getch();
                    while(c != 13){
                    	passW.push_back(c);
                    	cout<<"*";
                    	c =_getch();
					}
                    if(line.compare(passW) == 0){
                        cout<<"\nAccess Granted!\n";
                        cout<<"\n\nTaking you to the Car section.\n\nPlease wait....";
                        dir = userN+".txt";
                        return 1;
                    }
                    else{
                        cout<<"\nIncorrect Password! Try Again\n";
                        newfile.close();
                        login();
                    }
                    }
                    getline(newfile, line);
                }
                cout<<"User Not Found!";
                exit(0);
        }
};

class rent : public User{
    public:
        int days = 0, rentalfee = 0;
        string carCompany;
        string carModel;
        string carNumber;
        int year=0;
        int dis=0;
        int rentalfee1;
        void chooseCar(){
            do
            {
                Sleep(2000);
                system("CLS");
                cout<<"\t\t\t\t\tPlease Select a Car Company"<<endl;
                cout<<"\t\t\t\t\tEnter 'A' for Tesla car"<<endl;
                cout<<"\t\t\t\t\tEnter 'B' for Hyundai car"<<endl;
                cout<<"\t\t\t\t\tEnter 'C' Mahindra car"<<endl;
                cout<<"\t\t\t\t\tEnter 'D' Suzuki car"<<endl;
                cout<<"\n\t\t\t\t\tEnter your choice here : ";
                cin>>carCompany;
                system("CLS");
                cout<<"Opening Car Model Catalogue......";
                cout<<endl;
                if(carCompany == "A"){
                    Sleep(2000);
                    system("CLS");
                    cout<<"\t\t\tPlease Select Tesla Car Model"<<endl;
                    cout<<"\t\t\tEnter 'A' for Model S"<<endl;
                    cout<<"\t\t\tEnter 'B' for Model X"<<endl;
                    cout<<"\t\t\tEnter 'C' for Model Y"<<endl;
                    cout<<"\n\t\t\tEnter your choice here : ";
                    cin>>carModel;
                    cout<<endl;
                    cout<<"\t--------------------------------------------------------------------------"<<endl;
                    if(carModel == "A"){
                        system("CLS");
                        cout<<"You have chose Tesla Model S car"<<endl;
                        ifstream inAA("AA.txt");
                        char str[200];
                        while(inAA){
                            inAA.getline(str,200);
                            if(inAA){
                                cout<<str<<endl;
                            }
                        }
                        inAA.close();
                    }
                    if(carModel == "B"){
                        system("CLS");
                        cout<<"You have chose Tesla Model X car"<<endl;
                        ifstream inAB("AB.txt");
                        char str[200];
                        while(inAB){
                            inAB.getline(str,200);
                            if(inAB){
                                cout<<str<<endl;
                            }
                        }
                        inAB.close();
                    }
                    if(carModel == "C"){
                        system("CLS");
                        cout<<"You have chose Tesla Model Y car"<<endl;
                        ifstream inAC("AC.txt");
                        char str[200];
                        while(inAC){
                            inAC.getline(str,200);
                            if(inAC){
                                cout<<str<<endl;
                            }
                        }
                    }
                    if(carModel != "A" && carModel != "B" && carModel != "C"){
                        cout<<"Invalid Input! Please try again"<<endl;
                    }
                }
                if(carCompany == "B"){
                    Sleep(2000);
                    system("CLS");
                    cout<<"\t\t\t\t\tPlease Select Hyundai Car Model"<<endl;
                    cout<<"\t\t\t\t\tEnter 'A' for Creta"<<endl;
                    cout<<"\t\t\t\t\tEnter 'B' for Verna"<<endl;
                    cout<<"\t\t\t\t\tEnter 'C' for i20 sports"<<endl;
                    cout<<"\n\t\t\tEnter your choice here : ";
                    cin>>carModel;
                    cout<<endl;
                    cout<<"\t--------------------------------------------------------------------------"<<endl;
                    if(carModel == "A"){
                        system("CLS");
                        cout<<"You have chose Hyundai Creata car"<<endl;
                        ifstream inBA("BA.txt");
                        char str[200];
                        while(inBA){
                            inBA.getline(str,200);
                            if(inBA){
                                cout<<str<<endl;
                            }
                        }
                        inBA.close();
                    }
                    if(carModel == "B"){
                        system("CLS");
                        cout<<"You have chose Hyundai Verna"<<endl;
                        ifstream inBB("BB.txt");
                        char str[200];
                        while(inBB){
                            inBB.getline(str,200);
                            if(inBB){
                                cout<<str<<endl;
                            }
                        }
                        inBB.close();
                    }
                    if(carModel == "C"){
                        system("CLS");
                        cout<<"You have chose Hyundai i20 sports"<<endl;
                        ifstream inBC("BC.txt");
                        char str[200];
                        while(inBC){
                            inBC.getline(str,200);
                            if(inBC){
                                cout<<str<<endl;
                            }
                        }
                        inBC.close();
                    }
                    if(carModel != "A" && carModel != "B" && carModel != "C"){
                        cout<<"Invalid Input! Please try again"<<endl;
                    }
                }
                if(carCompany == "C"){
                    Sleep(2000);
                    system("CLS");
                    cout<<"\t\t\tPlease Select Mahindra Model"<<endl;
                    cout<<"\t\t\tEnter 'A' for Thar"<<endl;
                    cout<<"\t\t\tEnter 'B' for Bolero"<<endl;
                    cout<<"\t\t\tEnter 'C' for XUV"<<endl;
                    cout<<"\n\t\t\tEnter your choice here : ";
                    cin>>carModel;
                    cout<<endl;
                    cout<<"\t--------------------------------------------------------------------------"<<endl;
                    if(carModel == "A"){
                        system("CLS");
                        cout<<"You have chose Mahindra Thar"<<endl;
                        ifstream inCA("CA.txt");
                        char str[200];
                        while(inCA){
                            inCA.getline(str,200);
                            if(inCA){
                                cout<<str<<endl;
                            }
                        }
                        inCA.close();
                    }
                    if(carModel == "B"){
                        system("CLS");
                        cout<<"You have chose Mahindra Bolero"<<endl;
                        ifstream inCB("CB.txt");
                        char str[200];
                        while(inCB){
                            inCB.getline(str,200);
                            if(inCB){
                                cout<<str<<endl;
                            }
                        }
                        inCB.close();
                    }
                    if(carModel == "C"){
                        system("CLS");
                        cout<<"You have chose Mahindra XUV"<<endl;
                        ifstream inCC("CC.txt");
                        char str[200];
                        while(inCC){
                            inCC.getline(str,200);
                            if(inCC){
                                cout<<str<<endl;
                            }
                        }
                        inCC.close();
                    }
                    if(carModel != "A" && carModel != "B" && carModel != "C"){
                        cout<<"Invalid Input! Please try again"<<endl;
                    }
                }
                if(carCompany == "D"){
                    Sleep(2000);
                    system("CLS");
                    cout<<"\t\t\t\t\tPlease Select Suzuki Model"<<endl;
                    cout<<"\t\t\t\t\tEnter 'A' for Swift"<<endl;
                    cout<<"\t\t\t\t\tEnter 'B' for Baleno"<<endl;
                    cout<<"\t\t\t\t\tEnter 'C' for Alto K10"<<endl;
                    cout<<"\n\t\t\tEnter your choice here : ";
                    cin>>carModel;
                    cout<<endl;
                    cout<<"\t--------------------------------------------------------------------------"<<endl;
                    if(carModel == "A"){
                        system("CLS");
                        cout<<"You have chose Suzuki Swift"<<endl;
                        ifstream inDA("DA.txt");
                        char str[200];
                        while(inDA){
                            inDA.getline(str,200);
                            if(inDA){
                                cout<<str<<endl;
                            }
                        }
                        inDA.close();
                    }
                    if(carModel == "B"){
                        system("CLS");
                        cout<<"You have chose Suzuki Baleno"<<endl;
                        ifstream inDB("DB.txt");
                        char str[200];
                        while(inDB){
                            inDB.getline(str,200);
                            if(inDB){
                                cout<<str<<endl;
                            }
                        }
                        inDB.close();
                    }
                    if(carModel == "C"){
                        system("CLS");
                        cout<<"You have chose Alto K10"<<endl;
                        ifstream inDC("DC.txt");
                        char str[200];
                        while(inDC){
                            inDC.getline(str,200);
                            if(inDC){
                                cout<<str<<endl;
                            }
                        }
                        inDC.close();
                    }
                    if(carModel != "A" && carModel != "B" && carModel != "C"){
                        cout<<"Invalid Input! Please try again"<<endl;
                    }
                }
                if(carCompany != "A" && carCompany != "B" && carCompany != "C" && carCompany != "D"){
                    cout<<"Invalid Input! Please Try Again"<<endl;
                }
            } while (carCompany != "A" && carCompany != "B" && carCompany != "C" && carCompany != "D" && carModel != "A" && carModel != "B" && carModel != "C");
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"Please provide following information.\n";
            while(1){
                cout<<"Please Select Car number(4 digit) : ";
                cin>>carNumber;
                if(strlen(carNumber.c_str())!=4){
                    cout<<"\nEnter a valid Number\n";
                }
                else{
                    break;
                }
            }
            system("CLS");
            cout<<"\n10% DISCOUNT on cars rented for more than 50 days \n";
			cout<<"\n25% DISCOUNT on cars rented for more than 150 days\n\n";
            cout<<"Enter the number of days you wish to rent a car : ";
            cin>>days;
            cout<<endl;
        }
        void calculate(){
            system("CLS");
            if(carCompany == "A" && carModel == "A"){
                rentalfee = days*3000;
            }
            else if(carCompany == "A" && carModel == "B"){
                rentalfee = days*4000;
            }
            else if(carCompany == "A" && carModel == "C"){
                rentalfee = days*2000;
            }
            else if(carCompany == "B" && carModel == "A"){
                rentalfee = days*1000;
            }
            else if(carCompany == "B" && carModel == "B"){
                rentalfee = days*800;
            }
            else if(carCompany == "B" && carModel == "C"){
                rentalfee = days*700;
            }
            else if(carCompany == "C" && carModel == "A"){
                rentalfee = days*1200;
            }
            else if(carCompany == "C" && carModel == "B"){
                rentalfee = days*1400;
            }
            else if(carCompany == "C" && carModel == "C"){
                rentalfee = days*1500;
            }
            else if(carCompany == "D" && carModel == "A"){
                rentalfee = days*500;
            }
            else if(carCompany == "D" && carModel == "B"){
                rentalfee = days*600;
            }
            else if(carCompany == "D" && carModel == "C"){
                rentalfee = days*300;
            }
            while(1)
            {
			cout<<"\n10% DISCOUNT on cars manufactured in 2011-2017 \n";
			cout<<"\n25% DISCOUNT on cars manufactured from 2005-2010\n";
			cout<<"\nEnter the manufacturer year(2005-2022) : ";
            cin>>year;
            system("CLS");
            if((year>2022)||(year<2005))
                  cout<<"\nenter valid year\n";     
            else if((year<=2016)&&(year>=2011))
			      {
				  dis=rentalfee*0.1;
				  cout<<"\n10% DISCOUNT applied for year 2011-2017\n";
			      break;
			      }
			else if((year<=2010)&&(year>=2005))
			      {
				  dis=rentalfee*0.25;
				  cout<<"\n25% DISCOUNT applied for year 2005-2010\n";
			      break;
			      }
			else
			      {
			       dis=0;
				   break; 	
			     	
			     }
			}
			
		    if((days>=51)&&(days<=150))
				{
				  dis=dis+rentalfee*0.1;
				  cout<<"\nAdditional 10% DISCOUNT applied for renting car for more than 50 days \n";  
			    }
			else if(days>150)
			  {
			      dis=dis+rentalfee*0.25;
			      cout<<"\nAdditional 25% DISCOUNT applied for renting car for more than 150 days \n\n";
		      }
		      rentalfee1=rentalfee-dis;
              Sleep(2000);
              cout<<"\nCalculating rent. Please wait......"<<endl;
              Sleep(2000);
        }

        void showRent(){
            cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
            cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
            cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
            cout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<Username<<" |"<<endl;
            cout << "\t\t	| Car Company :"<<"------------------|"<<setw(10)<<carCompany<<" |"<<endl;
            cout << "\t\t	| Car Model :"<<"--------------------|"<<setw(10)<<carModel<<" |"<<endl;
            cout << "\t\t	| Car No. :"<<"----------------------|"<<setw(10)<<carNumber<<" |"<<endl;
            cout << "\t\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
            cout << "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rentalfee<<" |"<<endl;
            cout << "\t\t	| Your DISCOUNT  is :"<<"------------|"<<setw(10)<<dis<<" |"<<endl;
            cout << "\t\t	| Your Actual Rental Amount is :"<<"-|"<<setw(10)<<rentalfee1<<" |"<<endl;
            cout << "\t\t	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
            cout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
            cout << "\t\t	 ________________________________________________________"<<endl;
            cout <<"\n";
            cout << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rentalfee1<<" |"<<endl;
            cout << "\t\t	 ________________________________________________________"<<endl;
            cout << "\t\t	 # This is a computer generated invoice and it does not"<<endl;
            cout << "\t\t	 require an authorised signture #"<<endl;
            cout <<" "<<endl;
            cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
            cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
            cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
            cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;

            ofstream outs;
            outs.open(dir.c_str(),ios::app);
            outs<<carCompany<<"\t\t\t\t"<<setw(10)<<carModel<<"\t\t\t\t"<<setw(10)<<year<<"\t\t\t\t"<<setw(10)<<carNumber<<"\t\t\t\t"<<setw(10)<<days<<" days\t\t\t"<<setw(10)<<"Rs."<<rentalfee1<<endl;
            outs.close();

            ofstream outad;
            outad.open("AllRecords.txt",ios::app);
            outad<<Username<<"\t\t"<<setw(10)<<carCompany<<"\t\t\t\t"<<setw(10)<<carModel<<"\t\t\t\t"<<setw(10)<<year<<"\t\t\t\t"<<setw(10)<<carNumber<<"\t\t\t\t"<<setw(10)<<days<<" days\t\t\t"<<setw(10)<<"Rs."<<rentalfee1<<endl;
            outad.close();
        }
        int knowmyrecords(){
            system("CLS");
            string Un;
            char lineC[1000];
            cout<<"Enter your Username : ";
            cin>>Un;
            Un = Un+".txt";
            ifstream infile;
            infile.open(Un.c_str());
            system("CLS");
            cout<<"Looking for Records.....\n"<<endl;
            Sleep(2000);
            if(!infile){
                int k = 0;
                cout<<"User don't exist.\n\nEnter '0' to try again with different username\nEnter '1' to exit\n";
                cout<<"\nEnter your choice here : ";
                cin>>k;
                if(k == 1){
                    return 1;
                }
                knowmyrecords();
                return 1;
            }
            while(infile){
                infile.getline(lineC,1000);
                if(infile){
                    cout<<lineC<<endl;
                }
            }
            infile.close();
        }
        void Thankyou(){
            system("PAUSE");
    
            system ("CLS");
                
            ifstream inf("thanks.txt");

            
            char str[300];

            while(inf) {
                inf.getline(str, 300);
                if(inf) 
                cout << str << endl;
            }
            inf.close();
	}
};

class welcome{
    public:
        int welcum(){
            ifstream infw("welcome.txt");
            
            if(!infw){
                cout<<"Cannot open file";
                return 1;
            }
            char str[1000];
            while(infw){
                infw.getline(str,1000);
                if(infw){
                    cout<<str<<endl;
                }
            }
            infw.close();
            Sleep(1000);
            cout<<"\nStarting the program. Please wait....\n";
            Sleep(1000);
            cout<<"\nLoading files....."<<endl;
            Sleep(1000);
            system("CLS");
            return 1;
        }
};

int main(){
    welcome Obj;
    Obj.welcum();
    rent U1;
    char ca;
    string passWd;
    char lineR[1000];
    int i;
    int j;
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
    cout<<"\t\t\t\t\t------------------------------";
    cout<<"\n\t\t\t\t\t     Press 1 for Admin \n";
    cout<<"\n\t\t\t\t\t     Press 2 for User \n";
    cout<<"\t\t\t\t\t------------------------------\n\n";	
    cout<<"\t\t\t\t\t\t     Enter here : ";
    cin>>j;
    system("CLS");
    switch(j){
        case 1:
        {
            cout<<"\t\t\t\t\tEnter Password to get admin access : ";
            ca = getch();
            while(ca != 13){
                passWd.push_back(ca);
                cout<<"*";
                ca = getch();
            }
            if(passWd.compare("Password123") == 0){
                system("CLS");
                cout<<"\n\n\t\t\t\t\tAccess Granted\n\n";
                cout<<"Showing all the records of rentals till today.....\n\n";
                Sleep(2000);
                ifstream filerec;
                filerec.open("AllRecords.txt");
                while(filerec){
                    filerec.getline(lineR,1000);
                    if(filerec){
                        cout<<lineR<<endl;
                    }
                }
                break;
            }
            cout<<"\n\n\t\t\t\tAccess Denied! Wrong Password\n";
            break;
        }
        case 2:
            {
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       USER INTERFACE \n\n";
            cout<<"\t\t\t\t\t------------------------------";
            cout<<"\n\t\t\t\t\t     Press 1 to LOGIN \n";
            cout<<"\n\t\t\t\t\t     Press 2 to REGISTER \n";
            cout<<"\n\t\t\t\t\t     Press 3 to Know your";
            cout<<"\n\t\t\t\t\t     all previous rentals \n";
            cout<<"\t\t\t\t\t------------------------------\n\n";	
            cout<<"\t\t\t\t\t\tEnter here : ";
            cin>>i;
            switch(i){
                case 1:
                    U1.login();
                    break;
                case 2:
                    U1.getdata(1);
                    break;
                case 3:
                    U1.knowmyrecords();
                    exit(1);
                default:
                    cout<<"Invalid Input!";
                    exit(0);
            }
            U1.chooseCar();
            U1.calculate();
            U1.showRent();
            U1.Thankyou();
            }
            break;
        default:
            cout<<"\n\nInvalid Input\n";
    }
    return 0;
}