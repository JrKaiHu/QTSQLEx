/********************************************************************************
** Form generated from reading UI file 'qtsqlex01.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSQLEX01_H
#define UI_QTSQLEX01_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTSQLEx01Class
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTableView *scoreTV;
    QLabel *label_2;
    QTableWidget *scoreTW;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTSQLEx01Class)
    {
        if (QTSQLEx01Class->objectName().isEmpty())
            QTSQLEx01Class->setObjectName(QStringLiteral("QTSQLEx01Class"));
        QTSQLEx01Class->resize(749, 822);
        centralWidget = new QWidget(QTSQLEx01Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 701, 721));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scoreTV = new QTableView(widget);
        scoreTV->setObjectName(QStringLiteral("scoreTV"));

        gridLayout->addWidget(scoreTV, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        scoreTW = new QTableWidget(widget);
        scoreTW->setObjectName(QStringLiteral("scoreTW"));

        gridLayout->addWidget(scoreTW, 1, 1, 1, 1);

        QTSQLEx01Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTSQLEx01Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 749, 21));
        QTSQLEx01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTSQLEx01Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTSQLEx01Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTSQLEx01Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTSQLEx01Class->setStatusBar(statusBar);

        retranslateUi(QTSQLEx01Class);

        QMetaObject::connectSlotsByName(QTSQLEx01Class);
    } // setupUi

    void retranslateUi(QMainWindow *QTSQLEx01Class)
    {
        QTSQLEx01Class->setWindowTitle(QApplication::translate("QTSQLEx01Class", "QTSQLEx01", Q_NULLPTR));
        label->setText(QApplication::translate("QTSQLEx01Class", "Score List TableView::", Q_NULLPTR));
        label_2->setText(QApplication::translate("QTSQLEx01Class", "Score List TableWidget:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QTSQLEx01Class: public Ui_QTSQLEx01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSQLEX01_H
