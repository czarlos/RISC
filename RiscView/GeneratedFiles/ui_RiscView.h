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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RiscViewClass
{
public:
    QWidget *centralWidget;
    QPushButton *CommitButton;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *ChatLabel;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RiscViewClass)
    {
        if (RiscViewClass->objectName().isEmpty())
            RiscViewClass->setObjectName(QStringLiteral("RiscViewClass"));
        RiscViewClass->resize(1128, 721);
        centralWidget = new QWidget(RiscViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CommitButton = new QPushButton(centralWidget);
        CommitButton->setObjectName(QStringLiteral("CommitButton"));
        CommitButton->setGeometry(QRect(880, 580, 251, 81));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 881, 471));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 470, 881, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ChatLabel = new QLabel(widget);
        ChatLabel->setObjectName(QStringLiteral("ChatLabel"));

        horizontalLayout->addWidget(ChatLabel);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        RiscViewClass->setCentralWidget(centralWidget);
        CommitButton->raise();
        ChatLabel->raise();
        lineEdit->raise();
        textEdit->raise();
        textEdit->raise();
        graphicsView->raise();
        menuBar = new QMenuBar(RiscViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1128, 21));
        RiscViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RiscViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RiscViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RiscViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RiscViewClass->setStatusBar(statusBar);

        retranslateUi(RiscViewClass);

        QMetaObject::connectSlotsByName(RiscViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *RiscViewClass)
    {
        RiscViewClass->setWindowTitle(QApplication::translate("RiscViewClass", "RiscView", 0));
        CommitButton->setText(QApplication::translate("RiscViewClass", "Commit", 0));
        ChatLabel->setText(QApplication::translate("RiscViewClass", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Chat:</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class RiscViewClass: public Ui_RiscViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RISCVIEW_H
