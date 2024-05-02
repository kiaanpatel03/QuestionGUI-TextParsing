/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *questionLabel;
    QLabel *questionTypeLabel;
    QStackedWidget *questionBox;
    QWidget *MCQPage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *option1RadioButton;
    QRadioButton *option2RadioButton;
    QRadioButton *option3RadioButton;
    QRadioButton *option4RadioButton;
    QWidget *page_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *TrueRadioButton;
    QRadioButton *FalseRadioButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QProgressBar *questionProgress;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(581, 449);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(false);
        questionLabel = new QLabel(centralwidget);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(40, 44, 491, 51));
        questionLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setWordWrap(true);
        questionTypeLabel = new QLabel(centralwidget);
        questionTypeLabel->setObjectName("questionTypeLabel");
        questionTypeLabel->setGeometry(QRect(40, 20, 311, 18));
        questionBox = new QStackedWidget(centralwidget);
        questionBox->setObjectName("questionBox");
        questionBox->setGeometry(QRect(60, 140, 431, 171));
        MCQPage = new QWidget();
        MCQPage->setObjectName("MCQPage");
        layoutWidget = new QWidget(MCQPage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 10, 331, 146));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        option1RadioButton = new QRadioButton(layoutWidget);
        option1RadioButton->setObjectName("option1RadioButton");
        option1RadioButton->setAutoFillBackground(false);
        option1RadioButton->setCheckable(true);
        option1RadioButton->setChecked(false);
        option1RadioButton->setAutoRepeat(false);

        verticalLayout->addWidget(option1RadioButton);

        option2RadioButton = new QRadioButton(layoutWidget);
        option2RadioButton->setObjectName("option2RadioButton");
        option2RadioButton->setAutoExclusive(true);

        verticalLayout->addWidget(option2RadioButton);

        option3RadioButton = new QRadioButton(layoutWidget);
        option3RadioButton->setObjectName("option3RadioButton");

        verticalLayout->addWidget(option3RadioButton);

        option4RadioButton = new QRadioButton(layoutWidget);
        option4RadioButton->setObjectName("option4RadioButton");

        verticalLayout->addWidget(option4RadioButton);

        questionBox->addWidget(MCQPage);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(80, 50, 281, 56));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TrueRadioButton = new QRadioButton(layoutWidget1);
        TrueRadioButton->setObjectName("TrueRadioButton");

        verticalLayout_2->addWidget(TrueRadioButton);

        FalseRadioButton = new QRadioButton(layoutWidget1);
        FalseRadioButton->setObjectName("FalseRadioButton");

        verticalLayout_2->addWidget(FalseRadioButton);

        questionBox->addWidget(page_2);
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(40, 330, 501, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        submitButton = new QPushButton(layoutWidget2);
        submitButton->setObjectName("submitButton");
        submitButton->setCheckable(false);

        horizontalLayout->addWidget(submitButton);

        previousButton = new QPushButton(layoutWidget2);
        previousButton->setObjectName("previousButton");

        horizontalLayout->addWidget(previousButton);

        nextButton = new QPushButton(layoutWidget2);
        nextButton->setObjectName("nextButton");

        horizontalLayout->addWidget(nextButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        questionProgress = new QProgressBar(centralwidget);
        questionProgress->setObjectName("questionProgress");
        questionProgress->setGeometry(QRect(40, 110, 501, 23));
        questionProgress->setValue(0);
        questionProgress->setTextVisible(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 581, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        questionBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mock Quiz", nullptr));
        questionLabel->setText(QCoreApplication::translate("MainWindow", "Question", nullptr));
        questionTypeLabel->setText(QCoreApplication::translate("MainWindow", "QuestionType", nullptr));
        option1RadioButton->setText(QCoreApplication::translate("MainWindow", "Option1", nullptr));
        option2RadioButton->setText(QCoreApplication::translate("MainWindow", "Option2", nullptr));
        option3RadioButton->setText(QCoreApplication::translate("MainWindow", "Option3", nullptr));
        option4RadioButton->setText(QCoreApplication::translate("MainWindow", "Option4", nullptr));
        TrueRadioButton->setText(QCoreApplication::translate("MainWindow", "True", nullptr));
        FalseRadioButton->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Cheat", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        previousButton->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
