#include "GUI.h"
#include <sstream>

using namespace std;

GUI::GUI(Service& service, QWidget* parent)
    : QMainWindow(parent), service(service)
{
    ui.setupUi(this);
    this->setWindowTitle("Catalogue");

    std::vector<Student> students = this->service.getStudents();
    this->populate(students);
    this->connections();
}

//void GUI::listItemClicked()
//{
 //   QMessageBox::critical(this, "Error", "Please provide all attributes for a turret");
//}

/*
int GUI::getSelectedIndex()
{
    QModelIndexList selected_indexes = this->ui.listWidget->selectionModel()->selectedIndexes();
    if (selected_indexes.size() == 0)
    {
        return -1;
    }
    int selected_index = selected_indexes.at(0).row();
    return selected_index;
}*/

void GUI::populate(std::vector<Student> items)
{
    this->ui.tableWidget->clear();
    this->ui.tableWidget->setColumnCount(7);
    this->ui.tableWidget->setRowCount(items.size());

    QStringList header;
    header << "Student ID" << "Username" << "Name" << "Group" << "Grade" << "Year 1" << "Year 2";
    this->ui.tableWidget->setHorizontalHeaderLabels(header);

    for (int i = 0; i < items.size(); i++)
    {
        this->ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(std::to_string(items[i].getId()))));
        this->ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(items[i].getUser())));
        this->ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(items[i].getName().toString())));
        this->ui.tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(std::to_string(items[i].getGroup()))));
        
        string g = std::to_string(items[i].getGrades().get1()).substr(0,4);
        this->ui.tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(g)));
 //       this->ui.tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString()));
    
        this->ui.tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(items[i].getStatus().get1())));
        this->ui.tableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(items[i].getStatus().get2())));
    }

}

void GUI::connections()
{
//    QObject::connect(this->ui.listWidget, &QListWidget::itemClicked, this, &GUI::listItemClicked);
    QObject::connect(this->ui.sorted_checkBox, &QCheckBox::stateChanged, this, &GUI::sorted);
    QObject::connect(this->ui.b911, &QPushButton::clicked, this, &GUI::byGroup1);
    QObject::connect(this->ui.b912, &QPushButton::clicked, this, &GUI::byGroup2);
    QObject::connect(this->ui.b913, &QPushButton::clicked, this, &GUI::byGroup3);
    QObject::connect(this->ui.b914, &QPushButton::clicked, this, &GUI::byGroup4);
    QObject::connect(this->ui.b915, &QPushButton::clicked, this, &GUI::byGroup5);
    QObject::connect(this->ui.b916, &QPushButton::clicked, this, &GUI::byGroup6);
    QObject::connect(this->ui.b917, &QPushButton::clicked, this, &GUI::byGroup7);
}


void GUI::filterByGroup(int group)
{
    std::vector<Student> list;
    list = this->service.filterByGroup(group);
    if (this->ui.sorted_checkBox->isChecked())
    {
        std::vector<Student> list2;
        list2 = this->service.sortForGroup(list);
        this->populate(list2);
    }
    else {
        this->populate(list);
    }
}

void GUI::byGroup1()
{
    filterByGroup(911);
}

void GUI::byGroup2()
{
    filterByGroup(912);
}
void GUI::byGroup3()
{
    filterByGroup(913);
}
void GUI::byGroup4()
{
    filterByGroup(914);
}
void GUI::byGroup5()
{
    filterByGroup(915);
}
void GUI::byGroup6()
{
    filterByGroup(916);
}
void GUI::byGroup7()
{
    filterByGroup(917);
}


void GUI::sorted()
{
    std::vector<Student> list;
    if (this->ui.sorted_checkBox->isChecked())
    {
        list = this->service.sortByGrade(1);
    }
    else
    {
        list = this->service.getStudents();
    }
    this->populate(list);
}



//void GUI::update()
//{
//   this->populate();
//}
