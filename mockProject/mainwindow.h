#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void assignQuestionData(Question question);
    void setRadioButton(int index,bool isMCQ);
    void applyStyleSheetToRadioButtons();
    void applyStyleSheetToPushButtons();
    void applyAnswerStyleSheet(bool isCorrect);
private slots:
    void on_submitButton_clicked();

    void on_nextButton_clicked();

    void on_previousButton_clicked();

    void on_option1RadioButton_clicked();

    void on_pushButton_clicked();

    void on_option2RadioButton_clicked();

    void on_option3RadioButton_clicked();

    void on_option4RadioButton_clicked();

    void on_TrueRadioButton_clicked();

    void on_FalseRadioButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
