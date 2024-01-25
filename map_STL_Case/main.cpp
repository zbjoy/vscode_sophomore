#include <iostream>
#include <string>
#include <map>
#include <ctime>

using namespace std;

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门

class Worker
{
public:
    Worker(){}

    Worker(string tName, int tAge, double tSalary) : name(tName), age(tAge), salary(tSalary){}

    string& getName()
    {
        return name;
    }

    int& getAge()
    {
        return age;
    }

    double showSalary()
    {
        return salary;
    }

private:
    string name;
    int age;
    double salary;
    int deparment;
};

void createWorker(multimap<int, Worker>& company, int num)
{
    srand((unsigned int)time(NULL));
    string setName = "A";
    int baseSalary[3] = {3000, 5000, 4000};
    int developSalary[3] = {10000, 8000, 5000};
    for(int i = 0; i < num; ++i)
    {
        string name = "Worker";
        char temp[10] = { 0 };
        // sprintf(temp, "%s", (setName.c_str())[0] + i);
        sprintf(temp, "%c", (setName.c_str())[0] + i);
        name += string(temp);
        int age = rand() % 21 + 20;
        int deparment = rand() % 3 + 1;
        double salary = (double)(rand() * 10000 % (developSalary[deparment - 1] * 100)) / (double)100.0 + (double)baseSalary[deparment - 1];
        company.insert(make_pair(deparment, Worker(name, age, salary)));
    }
}
void showWorker(multimap<int, Worker>& company)
{
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Sale_deparment:" << endl;
    multimap<int, Worker>::iterator it = company.find(SALE_DEPATMENT);
    int count = company.count(SALE_DEPATMENT);
    int i = 0;
    for(; it != company.end() && i < count; ++it, ++i)
    {
        cout << "Name: " << it->second.getName() << " Age: " << it->second.getAge() << " Salary: " << it->second.showSalary() << endl; 
    }
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Develop_deparment:" << endl;
    it = company.find(DEVELOP_DEPATMENT);
    count = company.count(DEVELOP_DEPATMENT);
    i = 0;
    for(; it != company.end() && i < count; ++it, ++i)
    {
        cout << "Name: " << it->second.getName() << " Age: " << it->second.getAge() << " Salary: " << it->second.showSalary() << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Finance_deparment:" << endl;
    it = company.find(FINACIAL_DEPATMENT);
    count = company.count(FINACIAL_DEPATMENT);
    i = 0;
    for(; it != company.end() && i < count; ++it, ++i)
    {
        cout << "Name: " << it->second.getName() << " Age: " << it->second.getAge() << " Salary: " << it->second.showSalary() << endl;
    }
}

void test()
{
    multimap<int, Worker> company;
    createWorker(company, 10);
    showWorker(company);
}

int main()
{
    test();
    return 0;
}