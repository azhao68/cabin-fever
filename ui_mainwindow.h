/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "view.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    View *view;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QWidget *snowSize;
    QGridLayout *gridLayout_6;
    QLineEdit *snowSizeTextbox;
    QSlider *snowSizeSlider;
    QLabel *snowSizeLabel;
    QWidget *snowRate;
    QGridLayout *gridLayout_7;
    QLineEdit *snowRateTextbox;
    QSlider *snowRateSlider;
    QLabel *snowRateLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        view = new View(centralWidget);
        view->setObjectName(QString::fromUtf8("view"));

        horizontalLayout->addWidget(view);

        MainWindow->setCentralWidget(centralWidget);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        snowSize = new QWidget(dockWidgetContents);
        snowSize->setObjectName(QString::fromUtf8("snowSize"));
        snowSize->setGeometry(QRect(10, 40, 230, 22));
        gridLayout_6 = new QGridLayout(snowSize);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        snowSizeTextbox = new QLineEdit(snowSize);
        snowSizeTextbox->setObjectName(QString::fromUtf8("snowSizeTextbox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(snowSizeTextbox->sizePolicy().hasHeightForWidth());
        snowSizeTextbox->setSizePolicy(sizePolicy);
        snowSizeTextbox->setMinimumSize(QSize(40, 0));
        snowSizeTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_6->addWidget(snowSizeTextbox, 0, 3, 1, 1);

        snowSizeSlider = new QSlider(snowSize);
        snowSizeSlider->setObjectName(QString::fromUtf8("snowSizeSlider"));
        snowSizeSlider->setMinimumSize(QSize(100, 0));
        snowSizeSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(snowSizeSlider, 0, 2, 1, 1);

        snowSizeLabel = new QLabel(snowSize);
        snowSizeLabel->setObjectName(QString::fromUtf8("snowSizeLabel"));

        gridLayout_6->addWidget(snowSizeLabel, 0, 0, 1, 1);

        snowRate = new QWidget(dockWidgetContents);
        snowRate->setObjectName(QString::fromUtf8("snowRate"));
        snowRate->setGeometry(QRect(10, 10, 230, 22));
        gridLayout_7 = new QGridLayout(snowRate);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        snowRateTextbox = new QLineEdit(snowRate);
        snowRateTextbox->setObjectName(QString::fromUtf8("snowRateTextbox"));
        sizePolicy.setHeightForWidth(snowRateTextbox->sizePolicy().hasHeightForWidth());
        snowRateTextbox->setSizePolicy(sizePolicy);
        snowRateTextbox->setMinimumSize(QSize(40, 0));
        snowRateTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_7->addWidget(snowRateTextbox, 0, 3, 1, 1);

        snowRateSlider = new QSlider(snowRate);
        snowRateSlider->setObjectName(QString::fromUtf8("snowRateSlider"));
        snowRateSlider->setMinimumSize(QSize(100, 0));
        snowRateSlider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(snowRateSlider, 0, 2, 1, 1);

        snowRateLabel = new QLabel(snowRate);
        snowRateLabel->setObjectName(QString::fromUtf8("snowRateLabel"));

        gridLayout_7->addWidget(snowRateLabel, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "A CS123 Final", nullptr));
        snowSizeTextbox->setText(QString());
        snowSizeLabel->setText(QCoreApplication::translate("MainWindow", "Snow Size", nullptr));
        snowRateTextbox->setText(QString());
        snowRateLabel->setText(QCoreApplication::translate("MainWindow", "Snow Rate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
