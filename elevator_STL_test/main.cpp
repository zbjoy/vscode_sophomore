#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

class People
{
public:
    People(){};
    People(string tName) : name(tName){}
    string getName(){return name;}
private:
    string name;
};

class Elevator
{
public:
    static Elevator* getElevator(){return elevator;}

    void CreatePeople();
    void PopSomePeople();
    void PushSomePeople();
    void printPeopleStatus();
    void printPushPeople();
    void printPopPeople();
    void printNowPeople();


    // ~Elevator()
    // {
    //     if(elevator != NULL)
    //     {
    //         delete elevator;
    //         elevator = NULL;
    //     }
    // }
public:
    int layer;
    static const int layerMax = 17;
    static const int peopleMax = 15;
private:
    Elevator(){layer = 1;}
    Elevator(const Elevator&){};
private:
    static Elevator* elevator;
    list<People> elevatorPeople;
    queue<People> wantPushPeople;
    vector<People> pushPeople;
    vector<People> popPeople;
};

Elevator* Elevator::elevator = new Elevator;

void test()
{
    Elevator* elevator = Elevator::getElevator();

    for(; elevator->layer <= Elevator::layerMax; ++elevator->layer)
    {
        elevator->CreatePeople();
        if(Elevator::layerMax == elevator->layer)
        {
            elevator->PopSomePeople();
        }
        else
        {
            elevator->PopSomePeople();
            elevator->PushSomePeople();
        }
        elevator->printPeopleStatus();
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    test();
    return 0;
}

void Elevator::CreatePeople()
{
    while(!wantPushPeople.empty())
    {
        wantPushPeople.pop();
    }
    int num = rand() % 11;
    string setName = "A";
    char frontTemp[10] = { 0 };
    sprintf(frontTemp, "%d", layer);
    string F = "The ";
    string T = " layer People";
    for(int i = 0; i < num; i++)
    {
        char temp[10] = { 0 };
        sprintf(temp, "%c", ((setName.c_str())[0] + i));
        string name = F + string(frontTemp) + T + string(temp);
        wantPushPeople.push(People(name));
    }
}
void Elevator::PopSomePeople()
{
    if(layer == layerMax)
    {
        while(!elevatorPeople.empty())
        {
            popPeople.push_back(elevatorPeople.front());
            elevatorPeople.pop_front();
        }
        return;
    }

    int popNum = rand() % 7;
    while(popNum--)
    {
        // int popPeople = rand() % elevatorPeople.size() + 1;
        if(elevatorPeople.empty())
        {
            break;
        }
        int popPeoplePos = rand() % elevatorPeople.size();
        list<People>::iterator it = elevatorPeople.begin();
        while(popPeoplePos--)
        {
            it++;
        }
        popPeople.push_back(*it);
        elevatorPeople.erase(it);
    }
}
void Elevator::PushSomePeople()
{
    while(!wantPushPeople.empty())
    {
        if(elevatorPeople.size() >= peopleMax)
        {
            return;
        }
        pushPeople.push_back(wantPushPeople.front());
        elevatorPeople.push_back(wantPushPeople.front());
        wantPushPeople.pop();
    }

}
void Elevator::printPeopleStatus()
{
    cout << "Now people numbers: " << elevatorPeople.size() << endl;
    printNowPeople();
    cout << "PushPeople Status:" << endl;
    printPushPeople();
    cout << "PopPeople Status:" << endl;
    printPopPeople();
    cout << "--------------------------------------------------------" << endl;

}

void Elevator::printPushPeople()
{
    int i = 0;
    for(vector<People>::iterator it = pushPeople.begin(); it != pushPeople.end(); ++it)
    {
        if(!(i % 3) && i != 0)   cout << endl;

        cout << "Name: " << it->getName() << "     ";
        ++i;
    }
    cout << endl;
}

void Elevator::printPopPeople()
{
    int i = 0;
    for(vector<People>::iterator it = popPeople.begin(); it != popPeople.end(); ++it)
    {
        if(!(i % 3) && i != 0)  cout << endl;

        cout << "Name: " << it->getName() << "     ";
        ++i;
    }
    cout << endl;
}

void Elevator::printNowPeople()
{
    int i = 0;
    for(list<People>::iterator it = elevatorPeople.begin(); it != elevatorPeople.end(); ++it)
    {
        if(!(i % 3) && i != 0)  cout << endl;

        cout << "Name: " << it->getName() << "     ";
        ++i;
    }
    cout << endl;
}