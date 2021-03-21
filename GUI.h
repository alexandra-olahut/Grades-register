#pragma once

#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qformlayout.h>
#include <qlayout.h>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qlabel.h>


#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "Service.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(Service& service, QWidget* parent = Q_NULLPTR);

private:
    Ui::GUIClass ui;
    Service& service;


//    void listItemClicked();

//    int getSelectedIndex();
    void populate(std::vector<Student> items);
    void connections();
    void filterByGroup(int group);
    void byGroup1();
    void byGroup2();
    void byGroup3();
    void byGroup4();
    void byGroup5();
    void byGroup6();
    void byGroup7();

    void sorted();

//    void update();
};
