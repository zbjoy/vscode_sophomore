#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void writeFile()
{
    ofstream out;
    // out.open("test.txt", ios::out | ios::trunc); // | ios::binary)
    out.open("test1.txt", ios::out | ios::trunc | ios::binary);
    if(!out.is_open())
    {
        cout << "writeFile open() error" << endl;
    }

    // out << "姓名: 老张" << endl;
    // out << "年龄: 19" << endl;

    // out << "name: laozhang" << endl;
    // out << "age: 19" << endl;
    char buf[1024] = "name: laozhang\n";
    char buf1[1024] = "age: 19";
    out.write(buf, strlen(buf));
    out.write(buf1, strlen(buf1));

    out.close();
}

void readFile()
{
    ifstream in;
    // in.open("test.txt", ios::in);
    in.open("test1.txt", ios::in | ios::binary);
    if(!in.is_open())
    {
        cout << "readFile open() error" << endl;
    }

    char buf[1024] = { 0 };
    char c = 0;
   //while(!in.eof())
    while((c = in.get()) != EOF)
    {
        in.putback(c);
        //in >> buf;
        //in.getline(buf, sizeof(buf));
        in.read(buf, sizeof(buf));
        cout << buf << endl;
    }

    in.close();
}

void test()
{
    writeFile();
    readFile();
}

int main()
{
    test();
    return 0;
}