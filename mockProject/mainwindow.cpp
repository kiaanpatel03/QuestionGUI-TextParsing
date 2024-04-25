#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "question.h"
#include "questiongroup.h"

#include <vector>
#include <iostream>
#include <QRadioButton>


// TODO : add automatic assignment of user radiobutton selection when clicked.

// NOTE: the following questions are for testing the mcu functionality of the question class and it's gui
// Question q1("What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 0, true);
// Question q2("Which of the following is not a programming language?", {"Python", "Java", "C++", "Microsoft Word"}, 3, true);
// Question q3("In which year did World War II end?", {"1939", "1945", "1941", "1947"}, 1, true);
// Question q4("What is the largest planet in our solar system?", {"Earth", "Mars", "Jupiter", "Venus"}, 2, true);
// Question q5("The human body has how many bones at birth?", {"206", "270", "300", "350"}, 0, true);
// Question q6("Calculate: 5 + 7", {"10", "12", "15", "20"}, 1, true);
// Question q7("Which of the following is a type of bird?", {"Penguin", "Dolphin", "Kangaroo", "Lizard"}, 0, true);
// Question q8("What is the smallest planet in our solar system?", {"Mercury", "Earth", "Jupiter", "Saturn"}, 0, true);
// Question q9("Which of the following is a type of fruit?", {"Apple", "Carrot", "Broccoli", "Cucumber"}, 0, true);
// Question q10("In what year was the first iPhone released?", {"2005", "2007", "2010", "2012"}, 1, true);
Question q1("What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 0, true);
Question q2("Who wrote the novel 'Pride and Prejudice'?", {"William Shakespeare", "Jane Austen", "Charles Dickens", "Emily Brontë"}, 1, true);
Question q4("What is the square root of 144?", {"10", "12", "14", "16"}, 2, true);
Question q6("Who painted the famous artwork 'Mona Lisa'?", {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Michelangelo"}, 2, true);
Question q8("What is the name of the artificial intelligence system created by Anthropic?", {"GPT-3", "Claude", "Alexa", "Siri"}, 1, true);
Question q11("Who directed the movie 'Inception'?", {"Christopher Nolan", "Steven Spielberg", "Martin Scorsese", "Quentin Tarantino"}, 0, true);
Question q14("Who wrote the play 'Hamlet'?", {"William Shakespeare", "Oscar Wilde", "George Bernard Shaw", "Tennessee Williams"}, 0, true);
Question q3("The smallest planet in our solar system is Mercury.", {"True", "False"}, 0, false);
Question q5("The chemical symbol for gold is Au.", {"True", "False"}, 0, false);
Question q7("The largest ocean on Earth is the Pacific Ocean.", {"True", "False"}, 0, false);
Question q9("The square of 7 is 49.", {"True", "False"}, 0, false);
Question q10("The chemical symbol for sodium is Na.", {"True", "False"}, 0, false);
Question q12("The largest mammal on Earth is the Blue Whale.", {"True", "False"}, 0, false);
Question q13("The formula for the area of a circle is πr².", {"True", "False"}, 0, false);
Question q15("The fastest land animal is the Cheetah.", {"True", "False"}, 0, false);
const std::vector<Question> testQuestions = {q1, q2,q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15};

// 'load' testQuestions into QuestionGroup for 'additional' vector functionality
QuestionGroup testGroup(testQuestions);

void MainWindow::setRadioButton(int index,bool isMCQ){
    if(isMCQ){
        switch (index) {
        case 0:
            ui->option1RadioButton->setChecked(true);
            break;
        case 1:
            ui->option2RadioButton->setChecked(true);
            break;
        case 2:
            ui->option3RadioButton->setChecked(true);
            break;
        case 3:
            ui->option4RadioButton->setChecked(true);
            break;
        case -1:
            // std::cout << "None Selected" << std::endl;

            ui->option1RadioButton->setChecked(true);
            break;


        default:
            break;
        }
    }else{
        switch (index) {
        case -1:
        case 0:
            ui->TrueRadioButton->setChecked(true);
            break;
        case 1:
            ui->FalseRadioButton->setChecked(true);
            break;
        default:
            break;
        }
    }
}


void MainWindow::assignQuestionData(Question question){
    // Assigns question data to correct widget
    // TODO : add assignment of user selected radiobutton - first get assignement

    if(question.isMultipleChoiceQuestionType()){
        ui->questionBox->setCurrentIndex(0);
        ui->questionTypeLabel->setText(QString::fromStdString("Multiple Choice Question  : "));
        /* assign options */
        ui->option1RadioButton->setText(QString::fromStdString(question.getOptions()[0]));
        ui->option2RadioButton->setText(QString::fromStdString(question.getOptions()[1]));
        ui->option3RadioButton->setText(QString::fromStdString(question.getOptions()[2]));
        ui->option4RadioButton->setText(QString::fromStdString(question.getOptions()[3]));

        if(question.getUserAnswer() == -1){
            setRadioButton(-1, question.isMultipleChoiceQuestionType());
            // this is done to match the defualt radiobutton selected
            Question tempQuestion = testGroup.getQuestion();
            tempQuestion.setUserAnswer(0);
            testGroup.setQuestion(tempQuestion);
        }
    }else{
        ui->questionBox->setCurrentIndex(1);

        ui->questionTypeLabel->setText(QString::fromStdString("True/False Question  : "));
        // add assignment option
    }
    ui->questionLabel->setText(QString::fromStdString(question.getQuestionPrompt()));




    setRadioButton(question.getUserAnswer(), question.isMultipleChoiceQuestionType());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);


    // load first question of the 'quiz'
    assignQuestionData(testGroup.getQuestion());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitButton_clicked()
{
    if(testGroup.getQuestion().getUserAnswer() != -1){
        // TODO: add universal checker - separate function ?
        if(testGroup.getQuestion().isCorrect()){
             std::cout<< "Correct Answer" << std::endl;
        }else{
            std::cout<< "Incorrect Answer" << std::endl;

        }
    }else{
        std::cout<< "Invalid Answer" << std::endl;

    }

}

void MainWindow::on_nextButton_clicked()
{
    // Transitions to next question index and loads next content

    testGroup.next();
    std::cout<< "Current Question Index : " << testGroup.getIndex() << std::endl;
    assignQuestionData(testGroup.getQuestion());


}

void MainWindow::on_previousButton_clicked()
{

    // transitions to prior question index and loads content
    testGroup.previous();
    std::cout<< "Current Question Index : " << testGroup.getIndex() << std::endl;
    assignQuestionData(testGroup.getQuestion());

}

void MainWindow::on_pushButton_clicked()
{
    Question obj = testGroup.getQuestion();
    std::cout   << "Q : " << obj.getQuestionPrompt() << std::endl
                << "UA : " << obj.getUserAnswer() << std::endl
                << "CA : " << obj.getCorrectIndex()<<std::endl ;
}

void MainWindow::on_option1RadioButton_clicked()
{
    // TODO : make into helper function and check memory management
    //When  'selected' set user answer to the radiobutton number
    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(0);
    testGroup.setQuestion(tempQuestion);
}

void MainWindow::on_option2RadioButton_clicked()
{
    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(1);
    testGroup.setQuestion(tempQuestion);}

void MainWindow::on_option3RadioButton_clicked()
{
    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(2);
    testGroup.setQuestion(tempQuestion);
}

void MainWindow::on_option4RadioButton_clicked()
{
    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(3);
    testGroup.setQuestion(tempQuestion);
}


void MainWindow::on_TrueRadioButton_clicked()
{
    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(0);
    testGroup.setQuestion(tempQuestion);
}


void MainWindow::on_FalseRadioButton_clicked()
{
    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(1);
    testGroup.setQuestion(tempQuestion);
}

