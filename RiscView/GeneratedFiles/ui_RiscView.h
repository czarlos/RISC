/********************************************************************************
** Form generated from reading UI file 'RiscView.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RISCVIEW_H
#define UI_RISCVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RiscViewClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RiscViewClass)
    {
        if (RiscViewClass->objectName().isEmpty())
            RiscViewClass->setObjectName(QStringLiteral("RiscViewClass"));
        RiscViewClass->resize(600, 400);
        menuBar = new QMenuBar(RiscViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RiscViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RiscViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RiscViewClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RiscViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RiscViewClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RiscViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RiscViewClass->setStatusBar(statusBar);

        retranslateUi(RiscViewClass);

        QMetaObject::connectSlotsByName(RiscViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *RiscViewClass)
    {
        RiscViewClass->setWindowTitle(QApplication::translate("RiscViewClass", "RiscView", 0));
    } // retranslateUi

};

namespace Ui {
    class RiscViewClass: public Ui_RiscViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RISCVIEW_H
