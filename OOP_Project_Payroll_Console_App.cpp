/*______________________________________________________________________________________*/
/*___________________________________ HEADER FILES _____________________________________*/
/*______________________________________________________________________________________*/


#include <iostream>  //for input output
#include <fstream>   //for file handling
#include <sstream>   // for accessing string stream
#include <stdlib.h>  // for random number function
#include <string>    //for strings
#include <conio.h>   //for getch function
#include <iomanip>   //for setw function
#include <time.h>    //for accessing current time
#include <windows.h> //for getting and setting Console_Cursor position

using namespace std;
/*_________________________________GLOBAL FUNCTIONS________________________________*/
// function prototypes
void gotoxy(int, int);
void clrscr();

// function definitions
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clrscr()
{
  system("cls");
}
/*_________________________________GLOBAL FUNCTIONS ENDED________________________________*/

/*_________________________________LINES CLASS________________________________*/
class LINES
{
public:
  /************************************************************************/
  void LINE_HOR(int column1, int column2, int row, char c)
  {
    for (column1; column1 <= column2; column1++)
    {
      gotoxy(column1, row);
      cout << c;
    }
  }
  /************************************************************************/

  void LINE_VER(int row1, int row2, int column, char c)
  {
    for (row1; row1 <= row2; row1++)
    {
      gotoxy(column, row1);
      cout << c;
    }
  }

  /************************************************************************/

  void BOX(int column1, int row1, int column2, int row2, char c)
  {
    char ch = 218;
    char c1, c2, c3, c4;
    char l1 = 196, l2 = 179;
    if (c == ch)
    {
      c1 = 218;
      c2 = 191;
      c3 = 192;
      c4 = 217;
      l1 = 196;
      l2 = 179;
    }
    else
    {
      c1 = c;
      c2 = c;
      c3 = c;
      c4 = c;
      l1 = c;
      l2 = c;
    }
    gotoxy(column1, row1);
    cout << c1;
    gotoxy(column2, row1);
    cout << c2;
    gotoxy(column1, row2);
    cout << c3;
    gotoxy(column2, row2);
    cout << c4;
    column1++;
    column2--;
    LINE_HOR(column1, column2, row1, l1);
    LINE_HOR(column1, column2, row2, l1);
    column1--;
    column2++;
    row1++;
    row2--;
    LINE_VER(row1, row2, column1, l2);
    LINE_VER(row1, row2, column2, l2);
  }
};
/*_________________________________LINES CLASS ENDED________________________________*/
class AbstractClass
{
public:
  virtual void bigbox() = 0;
  virtual void smallBox() = 0;
};

/*_______________________________________ANIMATION CLASS_____________________________________*/
class ANIMATION : public AbstractClass
{
  LINES L;

public:
  /************************************************************************/
  void smallBox()
  {
    L.BOX(5, 5, 160, 40, 219);
    L.BOX(6, 6, 159, 39, 219);
    L.BOX(7, 7, 158, 38, 219);
  }
  void bigbox()
  {
    L.BOX(45, 5, 125, 40, 219);
    L.BOX(47, 6, 123, 8, 218);
    L.BOX(47, 9, 123, 11, 218);
    L.BOX(47, 12, 83, 34, 218);
    L.BOX(86, 12, 123, 34, 218);
    L.BOX(47, 35, 123, 39, 218);
  }
  /************************************************************************/

  void Cdelay(int msec, int x, int y)
  {
    gotoxy(x, y);
    cout << ".....Redirecting...." << endl
         << endl;
    gotoxy(x, y + 2);
    for (int i = 0; i < 20; i++)
    {
      long goal = msec + (clock());
      while (goal > (clock()))
        ;
      cout << char(254);
    }
    system("CLS");
  }
  /************************************************************************/

  void exiting(int msec)
  {
    L.BOX(67, 27, 100, 35, 219);
    gotoxy(70, 30);
    cout << "..........Exiting.........." << endl;
    gotoxy(70, 32);
    for (int i = 0; i < 27; i++)
    {
      long goal = msec + (clock());
      while (goal > (clock()))
        ;
      cout << char(262);
    }
    system("CLS");
  }
  /************************************************************************/

  void redirecting(int msec)
  {
    L.BOX(67, 27, 100, 35, 219);
    gotoxy(70, 30);
    cout << "....Redirecting to Menu...." << endl;
    gotoxy(70, 32);
    for (int i = 0; i < 28; i++)
    {
      long goal = msec + (clock());
      while (goal > (clock()))
        ;
      cout << char(254);
    }
    system("CLS");
  }
  /************************************************************************/

  void printing(int msec)
  {
    L.BOX(67, 27, 103, 35, 219);
    gotoxy(72, 30);
    cout << "......Generating Slip......" << endl;
    gotoxy(70, 32);
    for (int i = 0; i < 31; i++)
    {
      long goal = msec + (clock());
      while (goal > (clock()))
        ;
      cout << char(254);
    }
    system("CLS");
  }
  /************************************************************************/

  void loading()
  {
    int msec = 140;
    gotoxy(67, 27);
    cout << "..................LOADING................." << endl
         << endl;
    gotoxy(67, 28);
    for (int i = 0; i < 42; i++)
    {
      long goal = msec + (clock());
      while (goal > (clock()))
        ;
      cout << char(254);
    }
    system("CLS");
  }
};
/*____________________________________ANIMATION CLASS ENDED___________________________________*/

/*___________________________________HELPER CLASS___________________________________*/
class HelperClass
{
  LINES L;

public:
  /************************************************************************/

  void drawline(int n, char ch)
  {
    cout << "\n";
    for (int i = 0; i < n; i++)
      cout << ch;
    cout << endl;
  }
  /************************************************************************/

  void pauseHandler()
  {
    char key;
    cout << "\n\n\n";
    gotoxy(1, 1);
    _getch();
  }
  /************************************************************************/

  void draw_PMS()
  {
    string sp = "     ";
    string b = "\xB2\xB2\xB2\xB2\xB2\xB2";                                                             // 6
    string c = "\xB2\xB2\xB2\xB2\xB2\xB2\xB2";                                                         // 7
    string d = "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"; //
    string _7 = "\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    string _6 = "\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    string _25 = "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    drawline(110, ' ');
    drawline(110, ' ');
    cout << "              " << sp << _25 << _25 << _25 << _25 << _25 << "\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << _25 << _25 << _25 << _25 << _25 << "\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << d << "          " << c << b << "               " << b << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << d << "          " << c << c << "             " << c << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << d << "          " << c << " " << c << "           " << c << " " << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "              " << c << "          " << c << "  " << c << "         " << c << "  " << c << "          " << _7 << "                    \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "              " << c << "          " << c << "   " << c << "       " << c << "   " << c << "          " << _7 << "                    \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "              " << c << "          " << c << "    " << c << "     " << c << "    " << c << "          " << _7 << "                    \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << d << "          " << c << "     " << c << "  " << c << "      " << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << d << "          " << c << "      " << c << c << "       " << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << d << "          " << c << "          " << c << "          " << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "                               " << c << "                           " << c << "                        " << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "                               " << c << "                           " << c << "                        " << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "                               " << c << "                           " << c << "                        " << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "                               " << c << "                           " << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "                               " << c << "                           " << c << "          " << _7 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2       " << c << "                               " << c << "                           " << c << "          " << _6 << _7 << _7 << "      \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << "\xB2\xB2\xB2\xB2                                                                                                                           \xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << _25 << _25 << _25 << _25 << _25 << "\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "              " << sp << _25 << _25 << _25 << _25 << _25 << "\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    drawline(110, ' ');
    drawline(110, ' ');
  }
};
/*______________________________________HELPER CLASS ENDED______________________________________*/

/*_________________________________________PERSON CLASS ________________________________________*/
class Person
{
protected:
  string name;
  int age;

public:
  Person() {}
};
/*_________________________________________PERSON CLASS ENDED________________________________________*/

/*_________________________________________EMPLOYEE CLASS_________________________________________*/
class Employee : public Person
{
private:
  AbstractClass *ptr;
  int code;
  int yearsOfExperience;
  string designation;
  int workingHours;
  int loanBalance;

  /*PRIVATE MEMBER FUNCTIONS*/

  int stoi(string input)
  {
    int integer;
    stringstream(input) >> integer;
    return integer;
  }
  /************************************************************************/

  void dataExtractor(string data, string temp)
  {
    temp = data.substr(0, data.find('|')); // code|name|designation|age|yearsOfExperience|workingHours|loanBalance
    code = stoi(temp);
    data = data.substr(data.find('|') + 1);
    name = data.substr(0, data.find('|'));
    data = data.substr(data.find('|') + 1); // designation|age|yearsOfExperience|workingHours|loanBalance
    designation = data.substr(0, data.find('|'));
    data = data.substr(data.find('|') + 1); // age|yearsOfExperience|workingHours|loanBalance
    temp = data.substr(0, data.find('|'));
    age = stoi(temp);
    data = data.substr(data.find('|') + 1); // yearsOfExperience|workingHours|loanBalance
    temp = data.substr(0, data.find('|'));
    yearsOfExperience = stoi(temp);
    data = data.substr(data.find('|') + 1); // workingHours|loanBalance
    temp = data.substr(0, data.find('|'));
    workingHours = stoi(temp);
    data = data.substr(data.find('|') + 1); // loanBalance
    loanBalance = stoi(data);
    isLoanTaken = ((loanBalance != 0) ? true : false);
    loanTaken = isLoanTaken ? 'Y' : 'N';
  }
  /************************************************************************/

  // void displayEmployeeListData()
  // {
  //   salary = workingHours * 350;
  //   cout
  //       << left << setw(5) << code << setw(18) << name << " " << setw(23) << designation
  //       << " " << setw(4) << age << " " << setw(10) << yearsOfExperience << " " << setw(10) << salary
  //       << " " << left << setw(4) << loanTaken << endl;
  //   cout << endl;
  // }
  void displayEmployeeListData(int y)
  {
    int x = 40;
    salary = workingHours * 350;
    gotoxy(x, y);
    cout << code << endl; // code
    gotoxy(x + 6, y);
    cout << name << endl; // name
    gotoxy(x + 31, y);
    cout << designation << endl; // des
    gotoxy(x + 55, y);
    cout << age << endl; // age
    gotoxy(x + 62, y);
    cout << yearsOfExperience << endl; // exp
    gotoxy(x + 76, y);
    cout << salary << endl; // salary
    gotoxy(x + 85, y);
    cout << loanTaken << endl; // loanStatus
  }
  /************************************************************************/

  void employeeListHeadings()
  {
    int x = 40;
    int y = 5;
    gotoxy(x, y);
    cout << "Code" << endl;
    gotoxy(x + 6, y);
    cout << "Name" << endl;
    gotoxy(x + 31, y);
    cout << "Designation  " << endl;
    gotoxy(x + 55, y);
    cout << "Age " << endl;
    gotoxy(x + 62, y);
    cout << "Experience " << endl;
    gotoxy(x + 76, y);
    cout << "Salary " << endl;
    gotoxy(x + 85, y);
    cout << "Loan " << endl;
  }
  /************************************************************************/

  void formatDataToDisplay(int x, int y)
  {
    salary = workingHours * 350;
    gotoxy(x, y);
    cout
        << left << setw(5) << code << setw(18) << name << " " << setw(23) << designation
        << " " << setw(4) << age << " " << setw(10) << yearsOfExperience << " " << setw(10) << salary
        << " " << left << setw(4) << loanTaken << endl;
    cout << endl;
  }

  /************************************************************************/

  void displayEmployeeHeadings(int x, int y)
  {
    gotoxy(x, y);
    cout << "Code Name               Designation             Age Experience Salary Loan-Status " << endl;
  }
  /************************************************************************/

  void calculatingGrossPay()
  {
    salary = workingHours * 350; // 3500
    HRA = salary * 0.27;
    PF = 0.12 * salary;
    tax = 0.04 * salary;
    mealAllowance = 300;
    transportAllowance = 300;
    medicalAllowance = 500;
    loanDebit = salary * 0.09; // 315
    isLoanTaken = (loanBalance != 0 ? true : false);
    loanTaken = isLoanTaken ? 'Y' : 'N';
    if (loanDebit > loanBalance)
    {
      loanBalance = 0;
      loanDebit = loanBalance;
    }
    loanBalance = loanBalance - loanDebit;
    grosspay =
        (salary + mealAllowance + medicalAllowance + transportAllowance + HRA) - (PF + tax + loanDebit);
  }
  /************************************************************************/

  void formatingEmployeeSlip()
  {
    ptr->bigbox();
    int x = 50, y = 12;
    gotoxy(74, y - 5);
    cout << "EMPLOYEE SALARY SLIP" << endl;
    gotoxy(55, y - 2);
    cout << "Name : " << name << "                          Working Hours : " << workingHours << " hrs" << endl;
    gotoxy(x + 10, y + 2);
    cout << "EARNINGS" << endl;
    gotoxy(100, y + 2);
    cout << "DEDUCTIONS" << endl;
    gotoxy(x, y + 6);
    cout << "Basic Pay           : " << salary << endl;
    gotoxy(x + 40, y + 6);
    cout << "PF                    : " << PF << endl;
    gotoxy(x, y + 9);
    cout << "HRA(27% of Basic)   : " << HRA << endl;
    gotoxy(x + 40, y + 9);
    cout << "Tax                   : " << tax << endl;
    gotoxy(x, y + 12);
    cout << "Meal Allowance      : " << mealAllowance << endl;
    gotoxy(x + 40, y + 12);
    cout << "Loan Status           : " << loanTaken << endl;
    gotoxy(x, y + 15);
    cout << "Medical Alowance    : " << medicalAllowance << endl;
    gotoxy(x + 40, y + 15);
    cout << "Loan Debit This Month : " << loanDebit << endl;
    gotoxy(x, y + 18);
    cout << "Transport Allowance : " << transportAllowance << endl;
    gotoxy(x + 40, y + 18);
    cout << "Loan Balance          : " << loanBalance << endl;
    gotoxy(x + 20, y + 25);
    cout << "Total Gross Pay     : " << grosspay;
  }
  /************************************************************************/

  int getCode()
  {
    string line;
    int temp;
    ifstream read("Employee.txt", ios::in);
    if (!read)
    {
      cout << "Error 404! File not found" << endl;
      return -1;
    }
    else
    {
      while (read.peek() != EOF)
      {
        getline(read, line, '\n');
      }
    }
    if (line != "")
    {
      line = line.substr(0, line.find('|'));
      temp = stoi(line);
    }
    else
    {
      temp = 0;
    }
    return temp + 1;
  }
  /************************************************************************/

  void inputEmployeeDetails()
  {
    bool warning = false;
    string temp;
    gotoxy(74, 8);
    cout << "Enter Employee's Details" << endl;
    gotoxy(50, 12);
    cout << "Name                                    :    ";
    cin.ignore();
    getline(cin, name);
    gotoxy(50, 14);
    cout << "Designation                             :    ";
    getline(cin, designation);
    gotoxy(50, 16);
    cout << "Age                                     :    ";
    do
    {
      cin >> age;
      if (age > 100 || age < 20)
      {
        gotoxy(130, 14);
        cout << "Warning!" << endl;
        gotoxy(120, 17);
        cout << "Minimum (20) Maximum (100)      ";
        gotoxy(155, 17);
      }
    } while (age > 100 || age < 20);
    gotoxy(50, 18);
    cout << "Working Hours                           :    ";
    do
    {
      cin >> workingHours;
      if (workingHours > 15 || workingHours < 1)
      {
        gotoxy(130, 14);
        cout << "Warning!" << endl;
        gotoxy(120, 19);
        cout << "Maximum time limit is 15!     " << endl;
        gotoxy(155, 19);
      }
    } while (workingHours > 15 || workingHours < 1);
    gotoxy(50, 20);
    cout << "Years of Experience                      :   ";
    do
    {
      cin >> yearsOfExperience;
      if (yearsOfExperience > (age - 18) || yearsOfExperience < 1)
      {
        gotoxy(130, 14);
        cout << "Warning!" << endl;
        gotoxy(120, 21);
        cout << "Enter less than " << (age - 18) << "     " << endl;
        gotoxy(145, 21);
      }
    } while (yearsOfExperience > (age - 18) || yearsOfExperience < 1);
    gotoxy(50, 22);
    cout << "Any loan if taken  (Y/N)                  :  ";
    cin >> loanTaken;
    setLoanStatus(loanTaken);
    if (isLoanTaken)
    {
      gotoxy(50, 24);
      cout << "Enter Loan Balance                      :   ";
      cin >> loanBalance;
    }
    else
    {
      loanBalance = 0;
    }
    code = getCode();
    L.BOX(58, 26, 110, 30, 218);
    gotoxy(60, 28);
    cout << "\t\tYour Employee Code is " << code << endl;
  }
  /************************************************************************/

  void listBox(int y2)
  {
    L.BOX(35, 1, 135, y2, 219);
    L.BOX(37, 2, 133, 6, 218);
  }

public:
  /************************************************************************/

  LINES L;
  ANIMATION animate;
  HelperClass helper;
  /************************************************************************/

  int HRA; // house rent allowance
  int PF;  // provident fund (provided after retirements)
  int tax;
  int mealAllowance;
  int transportAllowance;
  int medicalAllowance;
  int loanDebit;
  int grosspay;
  double salary;
  bool isLoanTaken;
  char loanTaken;

  /************************************************************************/
  Employee()
  {
    ptr = &animate;
  }
  /************************************************************************/

  void setAge(int a) { age = a; }
  void setName(string n) { name = n; }
  void setDesignation(string des) { designation = des; }
  void setWorkingHours(double s) { workingHours = s; }
  void setLoanBalance(int bal) { loanBalance = bal; }
  void setExperience(int years) { yearsOfExperience = years; }
  void setLoanStatus(char input)
  {
    isLoanTaken = (input == 'Y' ? true : false);
    loanTaken = input;
  }

  /************************************************************************/
  int getAge() { return age; }
  string getName() { return name; }
  string getDesignation() { return designation; }
  double getWorkingHours() { return workingHours; }
  int getExperience() { return yearsOfExperience; }
  int getLoanBalance() { return loanBalance; }
  /*************************************************************/
  void addEmployee()
  {
    L.BOX(15, 5, 155, 10, 219);
    inputEmployeeDetails();
    ofstream write("Employee.txt", ios::app);
    if (!write)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "File failed to open!";
      return;
    }
    else
    {
      write << code << "|" << name << "|" << designation
            << "|" << age << "|" << yearsOfExperience << "|"
            << workingHours << "|" << loanBalance << endl;
      gotoxy(62, 32);
      cout << "\t\t\tFile Updated!" << endl;
    }
    write.close();
  }
  /*****************************************************************/
  void printSlip()
  {
    ifstream read("Employee.txt");
    if (!read)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "File not found !";
    }
    string line, input, query, data, temp;
    bool found = false;
    L.BOX(60, 5, 110, 7, 218);
    gotoxy(67, 6);
    cout << "Enter employee code : ";
    cin >> input;
    while (read.peek() != EOF)
    {
      getline(read, line, '\n');
      query = line.substr(0, line.find('|'));
      if (query == input)
      {
        data = line;
        found = true;
        break;
      }
    }
    if (found)
    {
      animate.printing(100);
      dataExtractor(data, temp);
      calculatingGrossPay();
      formatingEmployeeSlip();
    }
    else
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "Invalid Employee Code!" << endl;
    }
  }
  /****************************************************************/
  void searchEmployee()
  {
    string input, line, query, data, temp;
    bool isfound = false;
    ifstream read("Employee.txt", ios::in);
    if (!read)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "File not found !";
      return;
    }
    else
    {
      L.BOX(30, 10, 145, 25, 219); //( x , y , x , y , char )
      gotoxy(50, 12);
      cout << "Enter code of employee you want to search :  ";
      cin >> input;
      while (read.peek() != EOF)
      {
        getline(read, line, '\n');
        query = line.substr(0, line.find('|'));
        if (query == input)
        {
          data = line;
          isfound = true;
          break;
        }
      }
      if (!isfound)
      {
        gotoxy(50, 14);
        cout << "Employee Not found!" << endl;
      }
      if (isfound)
      {
        dataExtractor(data, temp);
        displayEmployeeHeadings(50, 16); // y+4 (next cursor)
        formatDataToDisplay(50, 19);
      }
    }
    read.close();
  }
  /******************************************************/
  void deleteEmployee()
  {
    string input, line, query;
    bool isFound = false;
    ifstream read("Employee.txt", ios::in);
    ofstream tempHandler("temp.txt", ios::out);
    if (!read || !tempHandler)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "Cannot reach  required file!";
      return;
    }
    L.BOX(30, 10, 145, 25, 219);
    gotoxy(50, 12);
    cout << "Enter code of employee you want to delete : ";
    cin >> input;
    while (read.peek() != EOF)
    {
      getline(read, line, '\n');
      query = line.substr(0, line.find('|'));
      if (query != input)
      {
        tempHandler << line << endl;
      }
      else
      {
        isFound = true;
      }
    }
    read.close();
    tempHandler.close();
    /********************************/
    ofstream write("Employee.txt", ios::out);
    ifstream inputHandler("temp.txt", ios::in);
    if (!write || !tempHandler)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "Cannot reach  required file!";
      return;
    }
    while (inputHandler.peek() != EOF)
    {
      getline(inputHandler, line, '\n');
      write << line << endl;
    }
    write.close();
    inputHandler.close();
    gotoxy(50, 15);
    /*ternary operator*/
    cout << ((isFound) ? "Employee deleted successfully!" : "Employee already donot exist!") << endl;
  }
  /*****************************************************************/

  void updateEmployee()
  {
    string line, input, query;
    bool isFound = false;
    ifstream read("Employee.txt", ios::in);
    fstream tempHandler("temp.txt", ios::out);
    if (!read || !tempHandler)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "Cannot reach  required file!";
      return;
    }
    // L.BOX(15, 5, 155, 10, 219);
    L.BOX(35, 2, 135, 6, 219);
    gotoxy(60, 4);
    cout << "Enter code of employee you want to update : ";
    cin >> input;
    while (read.peek() != EOF)
    {
      getline(read, line, '\n');
      query = line.substr(0, line.find('|'));
      if (query != input)
      {
        tempHandler << line << endl;
      }
      else
      {
        isFound = true;
      }
    }
    read.close();
    tempHandler.close();
    ofstream write("Employee.txt", ios::out);
    tempHandler.open("temp.txt", ios::in);
    if (!write || !tempHandler)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "Cannot reach  required file!";
      return;
    }
    while (tempHandler.peek() != EOF)
    {
      getline(tempHandler, line, '\n');
      write << line << endl;
    }
    if (isFound)
    {
      inputEmployeeDetails();
      write << code << "|" << name << "|" << designation
            << "|" << age << "|" << yearsOfExperience << "|"
            << workingHours << "|" << loanBalance << endl;
      gotoxy(73, 32);
      cout << "Employee updated!" << endl;
    }
    else
    {
      L.BOX(60, 11, 110, 15, 219);
      gotoxy(75, 13);
      cout << "Invalid Employee Code!" << endl;
      return;
    }
    write.close();
    tempHandler.close();
  }
  /*****************************************************************/

  void displayEmployeeList()
  {
    string line, temp;
    char ch;
    int y = 10;
    int count = 10;
    ifstream read("Employee.txt", ios::in);
    if (!read)
    {
      L.BOX(60, 13, 110, 17, 219);
      gotoxy(75, 15);
      cout << "Cannot reach  required file!";
      return;
    }
    gotoxy(75, 3);
    cout << "ALL EMPLOYEES DATA" << endl;
    employeeListHeadings();
    while (read.peek() != EOF)
    {
      getline(read, line, '\n');
      dataExtractor(line, temp);
      displayEmployeeListData(y);
      y = y + 2;
    }
    listBox(y + 2);
    cout << endl;
    read.close();
  }
};
/*_________________________________________EMPLOYEE CLASS ENDED___________________________________________*/

/*_______________________________________________ADMIN CLASS_______________________________________________*/
class Admin : public Person
{
private:
  void accessDenied()
  {
    clrscr();

    L.BOX(60, 16, 108, 30, 219);
    gotoxy(74, 22);
    cout << "  Access Denied!" << endl;
    animate.Cdelay(130, 74, 25);
  }
  /*****************************************************************/

  void accessGranted()
  {
    clrscr();
    L.BOX(60, 16, 108, 30, 219);
    gotoxy(74, 22);
    cout << "  Access Granted!" << endl;
    animate.Cdelay(80, 74, 25);
  }
  /*****************************************************************/

  string username;
  string password;
  HelperClass helper;
  ANIMATION animate;
  LINES L;

public:
  Admin() : username("admin"), password("123") {}

  /*********************************************/
  void setPassword(string ps) { password = ps; }
  void setUsername(string un) { username = un; }
  string getUsername() { return username; }
  string getPassword() { return password; }
  /*********************************************/

  /*****************************************************************/
  void loginAccess()
  {
    char ch = ' ';
    bool access = true;
    string us = "", ps;
    int size = password.size();
    do
    {
      system("Color 3E");
      gotoxy(74, 18);
      cout << "    Enter Credentials";
      L.BOX(70, 17, 102, 19, 218);
      L.BOX(55, 15, 116, 31, 218);
      L.BOX(56, 16, 115, 30, 219);
      gotoxy(74, 21);
      cout << "Enter UserName: ";
      gotoxy(90, 21);
      cin >> us;
      gotoxy(74, 24);
      cout << "Enter Password: ";
      gotoxy(90, 24);
      for (int i = 0; i < size; i++)
      {
        ch = _getch();
        ps += ch;
        cout << char(260);
      }
      access = true;
      if (us != username || ps != password)
      {
        accessDenied();
        ps = "";
        access = false;
      }
    } while (!access);
    if (access)
    {
      accessGranted();
    }
  }
  /*****************************************************************/
};
/*_______________________________________________ADMIN CLASS ENDED_______________________________________________*/

/*_______________________________________________PAYROLL CLASS_______________________________________________*/
class Payroll
{
  Employee *emp;      // aggregation
  Admin adm;          // composition
  HelperClass helper; // composition
  LINES L;            // composition
  ANIMATION animate;  // composition

public:
  Payroll()
  {
    emp = new Employee;
  }
  void introduction()
  {
    helper.draw_PMS();
    animate.loading();
    adm.loginAccess();
  }
  void displayMenu()
  {
    int _x = 77;
    int _y = 20;
    L.BOX(60, 9, 111, 13, 219);
    gotoxy(69, 11);
    cout << "PAYROLL MANAGEMENT SYSTEM BY F-I-A";
    L.BOX(70, 17, 102, 19, 218);
    L.BOX(55, 15, 116, 31, 218);
    L.BOX(56, 16, 115, 30, 219);
    gotoxy(_x - 3, _y - 2);
    cout << "PAYROLL MANAGEMENT SYSTEM";
    gotoxy(_x, _y);
    cout << "1: NEW EMPLOYEE";
    gotoxy(_x, _y + 1);
    cout << "2: SEARCH EMPLOYEE";
    gotoxy(_x, _y + 2);
    cout << "3: LIST OF EMPLOYEES";
    gotoxy(_x, _y + 3);
    cout << "4: SALARY SLIP";
    gotoxy(_x, _y + 4);
    cout << "5: UPDATE EMPLOYEE";
    gotoxy(_x, _y + 5);
    cout << "6: DELETE EMPLOYEE";
    gotoxy(_x, _y + 6);
    cout << "0: QUIT ";
    gotoxy(_x, _y + 7.5);
    cout << "ENTER YOUR CHOICE :";
    gotoxy(_x + 20, _y + 7.5);
  }
  void mainMenu()
  {
    system("Color 3E");
    system("CLS");
    string input;
    char ch;
    introduction();
    while (ch != '0')
    {
      clrscr();
      displayMenu();
      cin >> input;
      ch = input[0];
      system("CLS");
      if (ch == '1')
      {
        emp->addEmployee();
        helper.pauseHandler();
      }
      else if (ch == '2')
      {
        emp->searchEmployee();
        helper.pauseHandler();
      }
      else if (ch == '3')
      {

        emp->displayEmployeeList();
        helper.pauseHandler();
      }
      else if (ch == '4')
      {
        emp->printSlip();
        helper.pauseHandler();
      }
      else if (ch == '5')
      {
        emp->updateEmployee();
        helper.pauseHandler();
      }
      else if (ch == '6')
      {
        emp->deleteEmployee();
        helper.pauseHandler();
      }
      else if (ch == '0')
      {
        animate.exiting(150);
      }
      else
      {
        gotoxy(73, 25);
        cout << "!!!Invalid Input!!!" << endl;
        animate.redirecting(100);
      }
    }
  }
};
/*____________________________________________PAYROLL CLASS ENDED____________________________________________*/

/*_______________________________________________MAIN BODY_______________________________________________*/
int main()
{
  system("Color 3E"); // setting screen and font color
  Payroll PR;
  PR.mainMenu();
}
/*_________________________________________________END OF MAIN_________________________________________________*/
