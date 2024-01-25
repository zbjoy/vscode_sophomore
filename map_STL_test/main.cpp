#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Maker;
struct makerFunc;
void printSet(set<Maker, makerFunc>& s);

class Maker
{
    friend ostream& operator<<(ostream& out, Maker& m);
    friend void printSet(set<Maker, makerFunc>& s);
public:
    Maker(){};
    Maker(string tName, int tAge) : name(tName), age(tAge){};
    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }
private:
    string name;
    int age;
};

ostream& operator<<(ostream& out, Maker& m)
{
    out << "Name: " << m.name << " Age: " << m.age;
    return out;
}

struct makerFunc
{
    // bool operator()(Maker& m1, Maker& m2)
    bool operator()(const Maker& m1, const Maker& m2)
    {
        return m1.getAge() > m2.getAge();
        // m1.getName();
    }
};

//template <typename T>
void printSet(set<Maker, makerFunc>& s)
{
    for(set<Maker, makerFunc>::iterator it = s.begin(); it != s.end(); it++)
    {
        
        // cout << (*it) << endl;
        cout << "Name: " << it->name << " Age: " << it->age << endl;
    }
}



void test()
{
    set<Maker, makerFunc> s;
    makerFunc make;
    //make(Maker("aaa", 10), Maker("bbb", 20));
    // const Maker m1("aaa", 10);
    Maker m2("bbb", 20);
    // make(m1, m2);
    //makerFunc(Maker("aaa", 10), Maker("bbb", 20));
    // s.insert(m1);//Maker("aaa", 10)); // error !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! insert失败
    // s.insert(Maker("bbb", 20));
    // s.insert(Maker("ccc", 30));
    // s.insert(Maker("ddd", 40));
    // s.insert(Maker("eee", 50));

    //printSet(s);
}

void test02()
{
    map<int, Maker> mymap;
    mymap.insert(make_pair(2, Maker("aaa", 10)));
    Maker m2("bbb", 20);
    // mymap[6] = Maker("ccc", 30); // error
    mymap[6] = m2;
    for(map<int, Maker>::iterator it = mymap.begin(); it != mymap.end(); it++)
    {
        cout << it->second.getName() << "   " << it->second.getAge() << endl;
    }
}

int main()
{
    test();//err ?????????
    // test02();
    return 0;
}