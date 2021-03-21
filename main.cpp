#include "GUI.h"
#include <QtWidgets/QApplication>

#include "Service.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository<Student> repo{"Students.txt"};
    Service s{repo};
    GUI w{s};
    w.show();
    
    return a.exec();
}
