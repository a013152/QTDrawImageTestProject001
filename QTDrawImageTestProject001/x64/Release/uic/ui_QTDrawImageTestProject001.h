/********************************************************************************
** Form generated from reading UI file 'QTDrawImageTestProject001.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDRAWIMAGETESTPROJECT001_H
#define UI_QTDRAWIMAGETESTPROJECT001_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTDrawImageTestProject001Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTDrawImageTestProject001Class)
    {
        if (QTDrawImageTestProject001Class->objectName().isEmpty())
            QTDrawImageTestProject001Class->setObjectName(QString::fromUtf8("QTDrawImageTestProject001Class"));
        QTDrawImageTestProject001Class->resize(600, 400);
        menuBar = new QMenuBar(QTDrawImageTestProject001Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QTDrawImageTestProject001Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTDrawImageTestProject001Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QTDrawImageTestProject001Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTDrawImageTestProject001Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QTDrawImageTestProject001Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTDrawImageTestProject001Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QTDrawImageTestProject001Class->setStatusBar(statusBar);

        retranslateUi(QTDrawImageTestProject001Class);

        QMetaObject::connectSlotsByName(QTDrawImageTestProject001Class);
    } // setupUi

    void retranslateUi(QMainWindow *QTDrawImageTestProject001Class)
    {
        QTDrawImageTestProject001Class->setWindowTitle(QCoreApplication::translate("QTDrawImageTestProject001Class", "QTDrawImageTestProject001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTDrawImageTestProject001Class: public Ui_QTDrawImageTestProject001Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDRAWIMAGETESTPROJECT001_H
