#include <iostream>
using namespace std;
#include <string>
#include <limits>
#include <vector>
#include <fstream>

// -->
// -->  Промени файла с който работиш
// -->

/*
--Да се дефинира базов клас фирма зададена с име, булстат, брой служители и регистрация по ддс.
--Да се дефинира производен клас служители зададен с динамичен масив от служителите на всички отдели (минимум 5) 
създадени до момента във фирмата (дължината на масива зависи от служителите във фирмата.
--Информацията за тях е 3 имена, ЕГН, позиция, години, трудов стаж). 
--Класовете да включват конструктори без параметри за попълване на член-променливите в диалог.
--Да се определят и извеждат средният брой служители за всеки отдели и определи този,който има най-дълъг стаж в съответния отдел. 
--В зависимост от трудовия стаж в съответна фирма да се определи и размера на отпуската на всеки служител.
--Да се извежда пълната информация за всеки служител на фирмата.
--Да се предефинира операцията <<, която да се използва за извеждане на данните.

--Данните да се четат и съхраняват във файл.
Класовете да се опишат с UML клас диаграма.
--Задължително данните да се въвеждат динамично, чрез меню.*/

class firm{ // клас фирма
    public:
        string name;
        int bulstat;
        int number_employees;
        string registration_dds;

        firm(){
            cout << "Default constructor for firm class created!" << '\n';
        }

        firm(string n, int b, int n_e, string r_d){
            name = n;
            bulstat = b;
            number_employees = n_e;
            registration_dds = r_d;
        }
};

class person{ // клас пърсон
    public:
        int department_number;

        person(){
            cout << "Default constructor for person class created!" << '\n';
        }

        person(int d_n){
            department_number = d_n;
        }

        int getDepartment_Number(){
            return department_number;
        }
};

class employee : public person{ // клас имплоий
    public:
        string full_names;
        string EGN;
        string position;
        int age;
        int worked_years;
        //int department_number;

        employee(){
            cout << "Default constructor for employee class created!" << '\n';
        }

        employee(string f_n, string E, string p, int a, int w_y, int d_n) : person(d_n){
            full_names = f_n;
            EGN = E;
            position = p;
            age = a;
            worked_years = w_y;
            //department_number = d_n;
        }

        void show(){
            cout << "Full names: " << full_names << '\n';
            cout << "EGN: " << EGN << '\n';
            cout << "Position: " << position << '\n';
            cout << "Age: " << age << '\n';
            cout << "Worked years: " << worked_years << '\n';
            cout << "Department number: " << department_number << '\n';
        }

        string getName(){
            return full_names;
        }

        int getWorkedYears(){
            return worked_years;
        }

        int get_department_number(){
            return department_number;
        }
};

    //Departmets numbers:
    //  First department: 1
    //  Second department: 2
    //  Third department: 3
    //  Fourth department: 4
    //  Fifth department: 5    

ostream& operator<<(ostream& os, const employee& emp) { // предефиниране на операцията "<<"
    os << "Full Name: " << emp.full_names << "\n"
       << "EGN: " << emp.EGN << "\n"
       << "Position: " << emp.position << "\n"
       << "Age: " << emp.age << "\n"
       << "Worked Years: " << emp.worked_years << "\n"
       << "Department Number: " << emp.department_number;
    return os;
}

void write_in_file(vector<employee> employees){ // функция за писане във файл
    fstream myFile;
    myFile.open("projeckt1.txt", ios::app);
    if(myFile.is_open()){
        for(employee cur_employee : employees){
            myFile << "Full Name: " << cur_employee.full_names << "\n";
            myFile << "EGN: " << cur_employee.EGN << "\n";
            myFile << "Position: " << cur_employee.position << "\n";
            myFile << "Age: " << cur_employee.age << "\n";
            myFile << "Worked years: " << cur_employee.worked_years << "\n";
            myFile << "Department Number: " << cur_employee.department_number << "\n\n";
        }
        myFile.close();
    }
}

void read_from_file(){ // функция за четен от файл
    fstream myFile;
    myFile.open("projeckt1.txt", ios::in);
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            cout << line << endl;
        }
        myFile.close();
    }
    //system("pause>0");
}

int main(){
    vector<employee> new_employees; // декларираме динамично зеделен масив с работници от тип "employee"

    // брой работници във всеки департамент
    int dep_one_empl = 0;
    int dep_two_empl = 0;
    int dep_three_empl = 0;
    int dep_four_empl = 0;
    int dep_five_empl = 0;

    // променливи за брой години на най-дълго работелите във фирмата за всеки департамент
    int dep_one_longest_worked_years = INT_MIN;
    int dep_two_longest_worked_years = INT_MIN;
    int dep_three_longest_worked_years = INT_MIN;
    int dep_four_longest_worked_years = INT_MIN;
    int dep_five_longest_worked_years = INT_MIN;

    // обект от тип "employee" в който ще се инициализира най-дълго ръботелият във фирмата за всеки департамент
    employee dep_one_longest_worked;
    employee dep_two_longest_worked; 
    employee dep_three_longest_worked; 
    employee dep_four_longest_worked; 
    employee dep_five_longest_worked; 

    // променливите за стойностите на класа "employee"
    string cur_names;
    string cur_EGN;
    string cur_position;
    int cur_age;
    int cur_worked_years;
    int cur_department_number;

    
    cout << "Please enter 5 employees of the company: " << '\n';
    for(int i = 0; i < 5; i++){
        cout << "Three names: ";
        getline (cin, cur_names);
        cout << "EGN: ";
        cin >> cur_EGN;
        cout << "Position: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline (cin, cur_position);
        //cin >> cur_position;
        cout << "Age: ";
        cin >> cur_age; 
        cout << "Worked years: ";
        cin >> cur_worked_years;
        cout << "Department number: ";
        cin >> cur_department_number;
        //cin.ignore(0, '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        employee new_employee (cur_names, cur_EGN, cur_position, cur_age, cur_worked_years, cur_department_number);
        //employees[i] = new_employee;

        switch(new_employee.get_department_number()){
            case 1:
                dep_one_empl += 1;
                if(dep_one_longest_worked_years < new_employee.worked_years){
                    dep_one_longest_worked_years = new_employee.worked_years;
                    dep_one_longest_worked = new_employee;
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }else{
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }
                break;
            case 2:
                dep_two_empl += 1;
                if(dep_two_longest_worked_years < new_employee.worked_years){
                    dep_two_longest_worked_years = new_employee.worked_years;
                    dep_two_longest_worked = new_employee;
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }else{
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }
                break;
            case 3:
                dep_three_empl += 1;
                if(dep_three_longest_worked_years < new_employee.worked_years){
                    dep_three_longest_worked_years = new_employee.worked_years;
                    dep_three_longest_worked = new_employee;
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }else{
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }
                break;
            case 4:
                dep_four_empl += 1;
                if(dep_four_longest_worked_years < new_employee.worked_years){
                    dep_four_longest_worked_years = new_employee.worked_years;
                    dep_four_longest_worked = new_employee;
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }else{
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }
                break;
            case 5:
                dep_five_empl += 1;
                if(dep_five_longest_worked_years < new_employee.worked_years){
                    dep_five_longest_worked_years = new_employee.worked_years;
                    dep_five_longest_worked = new_employee;
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }else{
                    cout << new_employee.getName() << " will have " << 10 + new_employee.worked_years << endl;
                }
                break;
        }

        new_employees.push_back(new_employee); 
    }

    // извеждаме работниците с най-дълъг стаж за всеки отдел
    /*
    cout << "Longest worked in department 1 is: " << dep_one_longest_worked.getName() << " with " << 10 + dep_one_longest_worked.worked_years << " days off a year." << endl;
    cout << "Longest worked in department 2 is: " << dep_two_longest_worked.getName() << " with " << 10 + dep_two_longest_worked.worked_years << " days off a year." << endl;
    cout << "Longest worked in department 3 is: " << dep_three_longest_worked.getName() << " with " << 10 + dep_three_longest_worked.worked_years << " days off a year." << endl;
    cout << "Longest worked in department 4 is: " << dep_four_longest_worked.getName() << " with " << 10 + dep_four_longest_worked.worked_years << " days off a year." << endl;
    cout << "Longest worked in department 5 is: " << dep_five_longest_worked.getName() << " with " << 10 + dep_five_longest_worked.worked_years << " days off a year." << endl;
    */

    // заделяме динамечно обекти от тип "employee" 
    /*
    new_employees.push_back(employee("Ivan Ivanov Petrov", "05874598", "HR", 28, 6, 1));
    new_employees.push_back(employee("Maria Georgieva Popova", "98765432", "Finance", 34, 10, 2));
    new_employees.push_back(employee("Georgi Stoyanov Dimitrov", "12345678", "IT", 26, 3, 3));
    new_employees.push_back(employee("Petya Ivanova Marinova", "87654321", "Marketing", 30, 7, 1));
    new_employees.push_back(employee("Stoyan Petkov Ganchev", "65432109", "Sales", 40, 15, 3));
    new_employees.push_back(employee("Viktoria Nikolova Pavlova", "11223344", "Operations", 29, 5, 5));
    new_employees.push_back(employee("Nikolay Todorov Kirov", "99887766", "Support", 24, 2, 2));
    new_employees.push_back(employee("Kalina Dimitrova Ivanova", "55443322", "Logistics", 35, 12, 5));
    new_employees.push_back(employee("Dimitar Georgiev Stanev", "44556677", "Procurement", 31, 9, 3));
    new_employees.push_back(employee("Borislav Krumov Angelov", "88776655", "Legal", 37, 13, 4));
    new_employees.push_back(employee("Svetlana Mihaylova Vasileva", "77889900", "HR", 32, 8, 1));*/
    
    /*for (employee cur_employee : new_employees){ // извеждаме информацията за всеки работник със функцията show()
        cur_employee.show(); 
    }*/

    for (const auto& emp : new_employees) {
        cout << emp << "\n\n"; // Използване на предефинирания оператор <<
    }

    write_in_file(new_employees); // пишем във файла
    read_from_file(); // четем от файла

    return 0;
}