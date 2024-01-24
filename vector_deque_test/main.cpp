#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

using namespace std;

class Student
{
    friend ostream& operator<<(ostream& out, Student& s);
public:
    Student(string name, double score)
    {
        this->name = name;
        this->score = score;
    }

    double getScore()
    {
        return score;
    }

    void setScore(double score)
    {
        this->score = score;
    }


private:
    string name;
    double score;
};

ostream& operator<<(ostream& out, Student& s)
{
    out << "Name: " << s.name << " Score: " << s.score;
    return out;
}

void createStudent(vector<Student>& vStu)
{
    string setName = "ABCDE";
    for(int i = 0; i < 5; i++)
    {
        string name = "Student";
        name += setName[i];

        vStu.push_back(Student(name, 0.0));
    }
}

bool myCompare(double s1, double s2)
{
    return s1 > s2;
}

void getScore(vector<Student>& vStu)
{
    for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
    {
        deque<double> d;
        for(int i = 0; i < 10; i++)
        {
            double score = ((double)((rand() * 100) % 7001) / (double)100) + 30;
            d.push_back(score);
        }

        sort(d.begin(), d.end(), myCompare);
        d.pop_back();
        d.pop_front();

        double score = 0;
        for(deque<double>::iterator sit = d.begin(); sit != d.end(); sit++)
        {
            score += *sit;
        }

        score /= (double)d.size();

        it->setScore(score);
    }
}

bool myCompare_Stu(Student& s1, Student& s2)
{
    return s1.getScore() > s2.getScore();
}
void printScore(vector<Student>& vStu)
{
    sort(vStu.begin(), vStu.end(), myCompare_Stu);
    for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    vector<Student> vStu;

    createStudent(vStu);
    getScore(vStu);
    printScore(vStu);

    return 0;
}
