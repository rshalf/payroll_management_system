#include <iostream>
#include <cstdlib>  // for system("cls")
#include <string>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <errno.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class Admin;
class Employee;
void login();
void menuAdmin();
void loginScreenAdmin();
void menuEmployee(string);
//void addBonus();
class Exit_1
{
    public:
    virtual void exit_finale()=0; 
};
class Main
{
    public:
        //virtual void exit_finale()=0; 
        virtual void view_details(){};  
        void logout(Employee &e1)
        {
            cout<<"You will be logged out......"<<endl;
        } 
        void logout(Admin &e1)
        {
            cout<<"You will be logged out......"<<endl;
        } 

};
class Exitting:public Exit_1
{
    public:
    void exit_finale()
    {
        cout<<"Thank you for using our portal!"<<endl;
    }
};

class Employee: public Main
{
    private:
        string name;
        string id;
        string dob;
        string nationality;
        long long int phno;
        string address;
        long long int emer_phno;
        string position;
        float curr_sal;
        int years_of_service;
        int year_of_entry;
        string email_id;
    public:
        Employee(string id_us)
        {
            ifstream fin;
            fin.open("emp.csv");
            vector<string> row;
            string rec, deets, temp;
            getline(fin, rec);
            while(getline(fin, rec))
            {
                row.clear();
                //getline(fin, rec);
                stringstream s(rec);

                while(std::getline(s, deets, ','))
                {
                    row.push_back(string(deets));
                }
                if(row[0]==id_us)
                {
                    name=row[1];
                    id=row[0];
                    dob=row[2];
                    nationality=row[3];
                    email_id=row[4];
                    phno=stoull(row[5]);
                    address=row[6];
                    emer_phno=stoull(row[7]);
                    position=row[8];
                    curr_sal=stof(row[9]);
                    years_of_service=stoi(row[10]);
                    year_of_entry=stoi(row[11]);
                    break;
                }
            }
            fin.close();
        }
        ~Employee()
        {
            
        }
        void view_details()
        {
            system("cls");
            cout<<"\n-----------------------------------< TECHgenix >------------------------------"<<endl;
            cout<<endl;
            cout<<"        --------------------------General Information--------------------------"<<endl;
            cout<<"Name: "<<name<<"                                    ";
            cout<<"Employee ID: "<<id<<endl;
            cout<<"Date of birth: "<<dob<<endl;
            cout<<"Nationality: "<<nationality<<endl;
            cout<<"Current Job Position: "<<position<<endl;
            cout<<"Current Salary: "<<curr_sal<<endl;
            cout<<"Years of Service: "<<years_of_service<<"                               ";
            cout<<"Joining Year: "<<year_of_entry<<endl;
            cout<<"        --------------------------Contact Information--------------------------"<<endl;
            cout<<"Email-ID: "<<email_id<<endl;
            cout<<"Contact number: "<<phno<<"                        ";
            cout<<"Emergency number: "<<emer_phno<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
        int edit_details(string id_us)
        {
            
            int ch;
            system("cls");
            cout<<"What would you like to edit?"<<endl;
            cout<<"1.) Email-ID"<<endl;
            cout<<"2.) Contact Number"<<endl;
            cout<<"3.) Emergency Contact Number"<<endl;
            cout<<"4.) Address"<<endl;
            cout<<"Enter your choice:- ";
            cin>>ch;
            cout<<endl;
            string new_deet;
            int index;
            if (ch==1)
            {
                index=4;
                cout<<"Enter the new Email-ID: ";
                cin>>new_deet;
                email_id=new_deet;
                cout<<endl;
            }
            else if (ch==2)
            {
                index=5;
                cout<<"Enter the new Contact Number: ";
                cin>>new_deet;
                phno=stoull(new_deet);
                new_deet=phno;
                cout<<new_deet;
                cout<<endl;
            }
            else if(ch==3)
            {
                index=7;
                cout<<"Enter the new Emergency Contact: ";
                cin>>new_deet;
                emer_phno=stoull(new_deet);
                new_deet=stoull(new_deet);
                cout<<endl;
            }
            else if(ch==4)
            {
                cout<<"Enter the new Address: ";
                cin>>new_deet;
                address=new_deet;
                cout<<endl;
                index=6;
            }
            else
            {
                return -1;
            }
            int flag=1;
            std::ifstream fin("emp.csv",ios::in);
            std::ofstream fout("Emp2.csv");
            //fout<<"id,name,dob,nationality,email-id,contact-no,address,emergency-contact,position,current-salary,years-of-service,year-joint,";
            string line, word;
            int count=0;
            vector<string> row;
            getline(fin, line);
            while(getline(fin, line))
            {
                row.clear();
                //getline(fin, rec);
                stringstream s(line);

                while(std::getline(s, word, ','))
                {
                    row.push_back(string(word));
                    //cout<<"NEW WORD:"<<string(word);
                }
                if(row[0]==id_us)
                {
                    row[index]=new_deet;
                }
                for(int i=0; i<11; i++)
                {
                    fout<<row[i]<<",";
                }
                fout<<row[11]<<"\n";
            }
            fout.close();
            fin.close();
            //fout.close();
            int res=remove("emp.csv");
            //if(res==0)
                //cout<<"success";
           // else
               // cout<<stderr<<"System error"<<errno<<strerror(errno);
            //tried using the .c_str() thing and that shows error saying const char some bs
            rename("Emp2.csv", "emp.csv");

            /*while (fin.getline(line, word, ','))
            {
                row.clear();
                fin.getline(s, word, ',');
                stringstream s(line);
                while(getline(s, word, ','))
                {
                    row.push_back(word);
                }
                if(row[0]==id_us)
                {
                    flag=1;
                    stringstream convert;
                    convert<<new_deet;
                    //convert.str()in the next line;
                    row[index]=convert.str();
                    if(!fin.eof())
                    {
                        for(int i=0; i<11; i++)
                        {
                            fout<<row[i]<<",";
                        }
                        fout<<row[11]<<"\n";
                    }
                }
                else
                {
                    if(!fin.eof())
                    {
                        for(int i=0; i<11; i++)
                        {
                            fout<<row[i]<<",";
                        }
                        fout<<row[11]<<"\n";
                    }
                }
                if(fin.eof())
                {
                    break;
                }
                if(flag==0)
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
                fin.close();
                fout.close();
                remove("Employee_Details.csv");
                rename("Empdeets.csv", "Employee_Details.csv");
            }*/
        }
        int salary(string id)
        {
            //2dimensional vector(row and columns)
            vector<vector<string>> data;
            //data->has all file data
            vector<string> row;
            string line,word;

            //fstream file("foo.csv",ios::in);
            std::ifstream file("emp.csv",ios::in);
            if(file.is_open()){
                while(getline(file,line)){
                    row.clear();
                    stringstream str(line);
                    //stringstream object to split words
                    while(getline(str,word,',')){
                        //splits line based on commas
                        row.push_back(word);//pushes into row
                    }
                    data.push_back(row);//row is added into data
                }
            }
            else{
                cout<<"failed to access file"<<endl;
            }
            int i,j;
            //data.size=>no of rows
            //data[].size=>cols size
            for(i=0;i<data.size();i++){
                if (data[i][0]==id){
                    cout<<"SALARY : "<<data[i][9]<<endl;
                    //return atoi(data[i][9]);
                }

            }
        }

        void loan(string id){
                vector<vector<string>> data;
                vector<string> row;
                string line, word;

                std::ifstream file("emp.csv", ios::in);
                std::ofstream file1("empnew.csv");
                //file1<<"id,name,dob,nationality,email-id,contact-no,address,emergency-contact,position,current-salary,years-of-service,year-joint,";

                if (file.is_open()){
                    while (getline(file, line)){
                        row.clear();
                        stringstream str(line);
                        while (getline(str, word, ',')){
                            row.push_back(word); 
                        }
                        data.push_back(row); 
                    }
                }
                else{
                    cout << "failed to access file" << endl;
                }
                int i, j,r;
                cout << "Enter desired loan amount" << endl;
                int loan_amt;
                cin >> loan_amt;
                int new_salary;
                for (i = 0; i < data.size(); i++){
                    if (data[i][0] == id){
                        r=i;
                        int salary = std::stoi(data[i][9]);
                        new_salary = salary - loan_amt;
                        curr_sal=new_salary;
                        cout<<curr_sal;
                        data[i][9] = std::to_string(curr_sal);
                        cout << "current salary : " << data[i][9] << endl;
                    }
                }
                for (i = 1; i < data.size(); i++){
                    for (j = 0; j < data[i].size(); j++){
                            file1 << data[i][j] << ",";
                    }
                    file1<<"\n";
                }
                file.close();
                file1.close();
                remove("emp.csv");
                rename("empnew.csv", "emp.csv");
    }

};

class Admin:public Main
{ 
    public:
        string pwd="idk";
        int finduser(string id)
        {
            ifstream fin;
            fin.open("emp.csv");
            vector<string> row;
            string rec, deets, temp;
            getline(fin, rec);
            while(getline(fin, rec))
            {
                row.clear();
                //getline(fin, rec);
                stringstream s(rec);

                while(std::getline(s, deets, ','))
                {
                    row.push_back(string(deets));
                }
                if (row[0]==id)
                {
                    return 1;
                }
            }
            return -1;
        }
        void listOutAll()
        {
            ifstream fin;
            fin.open("emp.csv");
            vector<string> row;
            string rec, deets, temp;
            getline(fin, rec);
            //cout<<"ID             "<<"NAME                       "<<"DOB      "<<"CURRENT POSITION"
            while(getline(fin, rec))
            {
                row.clear();
                stringstream s(rec);
                while(std::getline(s, deets, ','))
                {
                    row.push_back(string(deets));
                }

                cout<<"-------------------------------------------------------------------------------------"<<endl;
                cout<<"        --------------------------General Information--------------------------      "<<endl;
                cout<<"Name: "<<row[1]<<"                                    ";
                cout<<"Employee ID: "<<row[0]<<endl;
                cout<<"Date of birth: "<<row[2]<<endl;
                cout<<"Nationality: "<<row[3]<<endl;
                cout<<"Current Job Position: "<<row[8]<<endl;
                cout<<"Current Salary: "<<row[9]<<endl;
                cout<<"Years of Service: "<<row[10]<<"            ";
                cout<<"Joining Year: "<<row[11]<<endl;
                cout<<"        --------------------------Contact Information--------------------------      "<<endl;
                cout<<"Email-ID: "<<row[4]<<endl;
                cout<<"Contact number: "<<row[5]<<"                          ";
                
                cout<<"Emergency number: "<<row[7]<<endl;
                cout<<"Address: "<<row[6]<<endl;
                
                cout<<endl;
                cout<<"-------------------------------------------------------------------------------------"<<endl;
                cout<<endl;
                cout<<endl;

            }
            fin.close();
        }


        void newEmployee()
        {                
        //fstream file;//file pointer(file stream object that will be used to interact with the file)    
        
        std::ofstream file("emp.csv",ios::out|ios::app);
        

        int i,contact_num,emergency_contact,current_salary,years_of_service,year_of_joining;
        string id,name,dob,nationality,email_id,position,address;
        try{
            //getline(cin, str); =>cin can't take a sentence/phrase(stops at any empty space)
            //cin.ignore =>ignore new line character from input buffer
            cout<<"Enter Employee Details"<<endl;
            cout<<"Employee id  : ";
            cin>>id;

            cout<<"Employee Name : ";
            cin.ignore();
            getline(cin, name); 
            
            cout<<"Employee DOB  : ";
            getline(cin, dob); 
            
            cout<<"Nationality : ";
            getline(cin, nationality); 
            
            cout<<"Employee Email id  : ";
            getline(cin, email_id); 
            
            cout<<"contact details  : ";
            cin>>contact_num;
            
            cout<<"Address  : ";
            cin.ignore();
            getline(cin, address); 

            cout<<"Position  : ";
            //cin.ignore();   
            getline(cin, position);         
            
            cout<<"Emergency contact : ";
            cin>>emergency_contact;        
            
            cout<<"current salary : ";
            cin>>current_salary;
            
            cout<<"years of service : ";
            cin>>years_of_service;
            
            cout<<"Year of joining : ";
            cin>>year_of_joining;        
                
            //put in file
                file<<"\n";
                file<<id<<","
                    <<name<< ","
                    <<dob<< ","
                    <<nationality<< ","
                    <<email_id<< ","
                    <<contact_num<< ","
                    <<address<< ","
                    <<emergency_contact<< ","
                    <<position<< ","
                    <<current_salary<< ","
                    <<years_of_service<< ","
                    <<year_of_joining<< ","     
                    <<'\n';        
            
        }catch(exception &e){
            cout<<"error:" << e.what()<<endl;
        }
        
        file.close();

        }
        

        void removeEmployee()
        {
            string ID;
            cout<<"Enter ID of employee to be deleted: ";
            cin>> ID;
            cout<<"\n";

            vector<vector<string>> data;
            vector<string> row;
            string line,word;

            std::ifstream file("emp.csv",ios::in);
            std::ofstream filenew("empnew.csv");

            if(file.is_open())
            {
                while(getline(file,line))
                {
                    row.clear();
                    stringstream str(line);  //stringstream object to split words
                    while(getline(str,word,','))
                    {
                        row.push_back(word);
                    }
                    data.push_back(row);
                }
            }


            int r;

            for(int i=1;i<data.size();i++)
            {        
                    if(data[i][0]==ID)
                    {
                        r=i;
                    }
            }
            
            
            // new file updation

            for(int i=0;i<data.size();i++){
                for(int j=0;j<data[i].size();j++)
                {
                    if(i!=r)
                        filenew<<data[i][j]<<",";
                }
                if(i!= data.size()-1 && i!=r)
                    filenew<<"\n";
                
            }
            filenew.close();
            file.close();
            remove("emp.csv");
            rename("empnew.csv", "emp.csv");


        }
        
        void addBonus()
        {
            string ID;
            float bonus;

            cout<<"Enter employee's ID: ";
            cin>> ID;
            cout<<"\n";
            

            cout<<"Enter bonus: ";
            cin>> bonus;
            
            vector<vector<string>> data;
            vector<string> row;
            string line,word;

            std::ifstream file("emp.csv",ios::in);
            std::ofstream filenew("empnew.csv");

            if(file.is_open()){
                while(getline(file,line))
                {
                    row.clear();
                    stringstream str(line);  //stringstream object to split words
                    while(getline(str,word,','))
                    {
                        row.push_back(word);
                    }
                    data.push_back(row);
                }
                    }
            int r;
            float esal;
            
            //to compute new salary

            for(int i=1;i<data.size();i++){
                for(int j=0;j<data[i].size();j++)
                {
                    
                    if(data[i][j]==ID)
                    {
                        r=i;
                        esal=stoi(data[i][9])+ bonus; 
                        //cout<<"new salary:"<<esal;
                    }
                }
            }
            
            // new file updation

            for(int i=0;i<data.size();i++){
                for(int j=0;j<data[i].size();j++)
                {
                    if(data[i][j]=="")
                        break;
                    if(i==r && j==9)
                        filenew<<esal<<",";
                    else
                    {
                        filenew<<data[i][j]<<",";
                    }
                }
                if(i!=data.size()-1 && i!=r)
                    filenew<<"\n";
            }
            filenew.close();
            file.close();
            remove("emp.csv");
            rename("empnew.csv", "emp.csv");

    }






};


void loginScreenEmployee()
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    //Employee e(empid);
    string passwd;
    string empid;
    cout<<"\n------------------------------E M P L O Y E E--------------------------------\n\n";
    cout<<"Enter the Employee ID: ";
    cin>>empid;
    cout<<"Enter password: ";
    cin>>passwd;
    ifstream fin;
    fin.open("emp.csv");
    vector<string> row;
    string rec, deets, temp;
    int flag=0;
    //getline(fin, rec);
    while(getline(fin, rec))
    {
        row.clear();
        //cout<<rec<<endl;
        stringstream s(rec);
        //cout<<"This happened";
        while(std::getline(s, deets, ','))
        {
            //cout<<deets;
            row.push_back(string(deets));
        }
        //cout<<row[0];
        if(row[0]==empid)
        {
            if(row[2]==passwd)
            {
                flag=1;
                fin.close();
                menuEmployee(empid);
                break;
            }
            else
            {
                flag=2;
                
            }
        }
        else
        {
            flag=3;
              
        }
        
    }
    if (flag==2)
    {
        SetConsoleTextAttribute(hConsole, 4); 
        cout<<"Wrong Password! Try Again!"<<endl;
        SetConsoleTextAttribute(hConsole, 15); 
        loginScreenEmployee();
    }
    if (flag==3)
    {
        SetConsoleTextAttribute(hConsole, 4); 
        cout<<"Wrong Employee ID! Try Again!"<<endl;
        SetConsoleTextAttribute(hConsole, 15); 
        loginScreenEmployee(); 
    }
}
//void loginScreenEmployee();
void menuEmployee(string id)
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    //system("cls");
    cout << "\n-----------------------------E M P L O Y E E-----------------------------\n\n";
    Employee e1(id);
    int choice;
    cout << "1. View Details \n";
    cout << "2. View Salary\n";
    cout << "3. Loan application\n";
    cout << "4. Edit Details\n";
    cout << "5. Logout\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        e1.view_details();
        menuEmployee(id);
    }
    // cout << "DAMN\n";
    else if (choice == 2)
    {
        e1.salary(id);
        menuEmployee(id);
    }
    // cout << "DAMN\n";
    else if (choice == 3)
    {
        e1.loan(id);
        menuEmployee(id);
    }
    else if(choice == 4)
    {
        int ch=e1.edit_details(id);
        menuEmployee(id);
    }
    else if(choice==5)
    {
        Main m;
        m.logout(e1);
        login();
    }
    // cout << "DAMN\n";
    else
    {
        while (choice < 1 || choice > 5)
        {
            //system("cls");
            cout << "\n---------------------------E M P L O Y E E-----------------------------------\n\n";
            SetConsoleTextAttribute(hConsole, 4); // 4 stands for red coloured text
            cout << "\nINVALID INPUT ENTERED!\n\n";
            SetConsoleTextAttribute(hConsole, 15); // 15 stands for white coloured text
            cout << "1. View Details \n";
            cout << "2. View Salary\n";
            cout << "3. Loan application\n";
            cout << "4. Edit Details\n";
            cout << "5. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                e1.view_details();
                menuEmployee(id);
            }
            // cout << "DAMN\n";
            else if (choice == 2)
            {
                e1.salary(id);
                menuEmployee(id);
            }
            // cout << "DAMN\n";
            else if (choice == 3)
            {
                e1.loan(id);
                menuEmployee(id);
            }
            else if(choice == 4)
            {
                int ch=e1.edit_details(id);
                menuEmployee(id);
            }
            else if(choice==5)
            {
                Main m;
                m.logout(e1);
                login();
            }
        }
    }
}
void login()
{
    int choice;
    //system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"----------------------------------< TECHgenix >----------------------------------------------"<<endl;
    cout<<"********************************************************************************************"<<endl;
    cout<< "\n-----------------------L O G I N--------------------------\n\n\n";
    cout<<"1. As Administrator\n";
    cout<<"2. As Employee\n";
    cout<<"3. Exit\n";
    cout<<"Enter you choice: ";
    cin >> choice;
    cout<<"\n";
    if(choice == 1)
        loginScreenAdmin();
    else if(choice == 2)
        loginScreenEmployee();
    else if(choice==3)
    {
        Exitting exo;
        exo.exit_finale();
    }
    
    else 
    {
        while(choice>3 || choice<1)
        {
            //system("cls");
            cout<<"---------------------------------------TECHgenix----------------------------------------------"<<endl;
            cout<<"********************************************************************************************"<<endl;
            cout<< "\n-----------------------L O G I N--------------------------\n\n\n";
            
            SetConsoleTextAttribute(hConsole, 4);  //4 stands for red coloured text
            cout<< "\nINVALID INPUT ENTERED!\n\n";
            SetConsoleTextAttribute(hConsole, 15); //15 stands for white coloured text
            cout<<"1. As Administrator\n";
            cout<<"2. As Employee\n";
            cout<<"3. Exit\n";
            cout<<"Enter your choice again: ";
            cin>>choice;
        }
        if(choice == 1)
            loginScreenAdmin();
        else if(choice == 2)
            loginScreenEmployee();
        else if(choice==3)
    {
        Exitting exo;
        exo.exit_finale();
    }
        
        

    }
        
}           

void loginScreenAdmin()
{ 
    Admin a1;
    string pwd;
    //system("cls");
    cout<<"\n--------------------A D M I N I S T R A T O R--------------------\n\n";
    cout<<"Enter password:";
    cin>> pwd;
    if(pwd==a1.pwd)
        menuAdmin();
    else
    {
        while(pwd!=a1.pwd)
        {
            system("cls");
            cout<<"\n--------------------A D M I N I S T R A T O R--------------------\n\n";
            SetConsoleTextAttribute(hConsole,4);
            cout<<"INCORRECT PASSWORD!\n";
            SetConsoleTextAttribute(hConsole,15);
            cout<<"Re-enter password:";
            cin>> pwd;
        }
        menuAdmin();
    }
}

void menuAdmin()
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int choice; 
    Admin A;
    //system("cls");
            cout<<"\n--------------------A D M I N I S T R A T O R--------------------\n\n";
            cout<<"1. Add a new employee\n";
            cout<<"2. Remove an employee\n";
            cout<<"3. View list of employees\n";
            cout<<"4. Grant a bonus\n";
            cout<<"5. Search for an employee\n";
            cout<<"6. Logout\n";
            cout<<"Enter your choice again: ";
            cin>>choice;
            cout<<"\n";
        
        if(choice==1)
        {
            A.newEmployee();
            menuAdmin();
        }
        else if(choice==2)
        {
            A.removeEmployee();
            menuAdmin();
        }
        else if(choice==3)
        {
            Admin a;
            a.listOutAll();
            menuAdmin();
        }
        else if(choice==4)
        {
            A.addBonus();
            menuAdmin();
        }
        else if(choice==5)
        {
                string empid;
                Admin a;
                cout<<"Enter the Employee ID: ";
                cin>>empid;
                int res=a.finduser(empid);
                if (res==-1)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout<<"User does not exist. Enter a valid user ID"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {
                    Employee e(empid);
                    e.view_details();
                }
                menuAdmin();
        }
        else if(choice==6)
        {
            Main m;
            m.logout(A);
            login();
        }

    else
    {
        while(choice<1 || choice>6)
        {
            //system("cls");
            cout<<"\n--------------------A D M I N I S T R A T O R--------------------\n\n";
            SetConsoleTextAttribute(hConsole, 4);  //4 stands for red coloured text
            cout<< "\nINVALID INPUT ENTERED!\n\n";
            SetConsoleTextAttribute(hConsole, 15); //15 stands for white coloured text
            cout<<"1. Add a new employee\n";
            cout<<"2. Remove an employee\n";
            cout<<"3. View list of employees\n";
            cout<<"4. Grant a bonus\n";
            cout<<"5. Search for an employee\n";
            cout<<"6. Logout\n";
            cout<<"Enter your choice again: ";
            cin>>choice;
            cout<<"\n";
        
        if(choice==1)
        {
            A.newEmployee();
            menuAdmin();
        }
        else if(choice==2)
        {
            A.removeEmployee();
            menuAdmin();
        }
        else if(choice==3)
        {
             Admin a;
            a.listOutAll();
            menuAdmin();
        }
        else if(choice==4)
        {
            A.addBonus();
            menuAdmin();
        }
        else if(choice==5)
        {
                string empid;
            Admin a;
            cout<<"Enter the Employee ID: ";
            cin>>empid;
            int res=a.finduser(empid);
            if (res==-1)
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout<<"User does not exist. Enter a valid user ID"<<endl;
                SetConsoleTextAttribute(hConsole, 15);
            }
            else
            {
                Employee e(empid);
                e.view_details();
            }
                menuAdmin();
        }
        else if(choice==6)
        {
            Main m;
            m.logout(A);
            login();
        }
    
    }
}

}

int main()
{
    login();
    return 0;
}