#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "question.h"
#include "questiongroup.h"
#include "parsequestion.h"

#include <vector>
#include <iostream>
#include <QRadioButton>
#include <string>
#include <fstream>
#include <cstring>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// vector to store all of the lines
vector<string> lines;
vector<ParseQuestion> parsedQuestions;
QuestionGroup testGroup;



/* Parse Questions Methods */

ParseQuestion getQuestion(int index, vector<string> questions)
{
    ParseQuestion returnQuestion;

    if (index > questions.capacity() || index < 0)
    {
        cout << "Invalid index to fetch question from" << endl;
    }

    else
    {
        string line = questions[index];
        returnQuestion.parseDetails(line);
    }

    return returnQuestion;
}

vector<ParseQuestion> getQuestionsOfDifficulty(int numQuestions, string difficulty, vector<string> questions)
{
    vector<ParseQuestion> returnQuestions(0);
    vector<int> usedQuestions(0);    // store the question ids of questions already used

    returnQuestions.reserve(numQuestions);
    usedQuestions.reserve(numQuestions);

    while(returnQuestions.size() < returnQuestions.capacity())
    {
        // Generate a random number
        int randomNumber = rand() % 118;
        //cout << randomNumber << endl;

        if (find(usedQuestions.begin(), usedQuestions.end(), randomNumber) != usedQuestions.end())
        {
            // go to next loop iteration
            continue;
        }
        else
        {
            ParseQuestion fetchedQuestion = getQuestion(randomNumber, questions);

            if (fetchedQuestion.getQuestionDiff() == difficulty)
            {
                usedQuestions.push_back(randomNumber);
                returnQuestions.push_back(fetchedQuestion);
            }

            else
            {
                continue;
            }
        }

    }



    return returnQuestions;
}

int transform_answer_to_index(ParseQuestion question){
    string answer = question.getQuestionAnswer();
    char letter = answer[0];
    if(question.getQuestionType() == "TF"){
        if(letter == 'F'){
            return 1;
        }
        return 0;
    }else{

        // cout << letter << endl ;

        switch (letter)
        {
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        default:
            return -1;
            break;
        }


    }
}

bool isParseQuestionMCQ(ParseQuestion question){
    string answer = question.getQuestionAnswer();
    char letter = answer[0];
    if(question.getQuestionType() == "TF"){
        return false;
    }
    return true;
}

void getLines(string path){
    srand(time(NULL));

    // read in the text file
    //ifstream inputFile("C:/Users/Josh Goodwin/Desktop/School/UKZN/Third Year/COMP315/315 Projects/Project_315/WorldWar2Questions.txt");

    ifstream inputFile("/home/vyasa/Documents/TestingSuite/QuestionGUI-TextParsing-quiz-question-generator/Project_315/WorldWar2Questions.txt");
    // ifstream inputFile(path);

    // variable to store each line of the text file as it is read in
    string line;


    // print error message if the file cannot be read
    if (!inputFile.is_open())
    {
        cout << "Unable to open file." << endl;

    }

    // Read each line from the file and store it in the vector
    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    // Close the input file
    inputFile.close();
    std::cout << "Got the lines" << std::endl;

}

Question convertToQuestion(ParseQuestion parseQuestion){
    string questionPrompt = parseQuestion.getQuestion();

    // string answer = parseQuestion.getQuestionAnswer();

    int answerIndex = transform_answer_to_index(parseQuestion);
    vector<string> options = parseQuestion.parsePossibleAnswers();
    bool isMCQ = isParseQuestionMCQ(parseQuestion);
    Question transitionQuestion(questionPrompt, options , answerIndex ,isMCQ);
    return transitionQuestion;
}

vector<Question> createValidQuestionFormat(vector<ParseQuestion> parsedQuestions){
    vector<Question> transitionQuestions;

    for(int i = 0;i <parsedQuestions.size(); i++ ){
        transitionQuestions.push_back(convertToQuestion(parsedQuestions[i]));
    }

    return transitionQuestions;

}

/* Stop Parse Question Methods */

// Apply answer index color?
void MainWindow::applyStyleUpdateAnswer(int answerIndex){

    applyStyleSheetToRadioButtons();

    Question tempQuestion = testGroup.getQuestion();
    tempQuestion.setUserAnswer(answerIndex);
    testGroup.setQuestion(tempQuestion);

}

// sets a radiobutton specificied by the index to checked state
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

// assigns information about question to labels
void MainWindow::assignQuestionData(Question question){
    changeProgresssBar();
    // Assigns question data to correct widget

    if(question.isMultipleChoiceQuestionType()){
        ui->questionBox->setCurrentIndex(0);
        ui->questionTypeLabel->setText(QString::fromStdString("Multiple Choice Question"));

        /* assign options */
        ui->option1RadioButton->setText(QString::fromStdString(question.getOptions()[0]));
        ui->option2RadioButton->setText(QString::fromStdString(question.getOptions()[1]));
        ui->option3RadioButton->setText(QString::fromStdString(question.getOptions()[2]));
        ui->option4RadioButton->setText(QString::fromStdString(question.getOptions()[3]));


    }else{
        ui->questionBox->setCurrentIndex(1);

        ui->questionTypeLabel->setText(QString::fromStdString("True/False Question"));
        // add assignment option
    }
    if(question.getUserAnswer() == -1){

        // this is done to match the defualt radiobutton selected
        Question tempQuestion = testGroup.getQuestion();
        tempQuestion.setUserAnswer(0);
        testGroup.setQuestion(tempQuestion);
    }

    ui->questionLabel->setText(QString::fromStdString(question.getQuestionPrompt()));

    setRadioButton(question.getUserAnswer(), question.isMultipleChoiceQuestionType());
}

// applies appearance to all radiobuttons
void MainWindow::applyStyleSheetToRadioButtons()
{

    QString styleSheet = "QRadioButton{ border: 1px solid black; border-radius: 7px;padding:5px; }"
                         "QRadioButton::indicator { width: 0; height: 0; } "
                         "QRadioButton::checked {background-color: #51829B; }";

    QList<QRadioButton*> radioButtons = findChildren<QRadioButton*>();

    for (QRadioButton* radioButton : radioButtons) {
        radioButton->setStyleSheet(styleSheet);
    }
}

// applies appearance to all pushbuttons
void MainWindow::applyStyleSheetToPushButtons()
{

    QString styleSheet = "QPushButton{ border: 1px solid black; border-radius: 7px;padding:5px; }"
                         "QPushButton::indicator { width: 0; height: 0; } "
                         "QPushButton::checked {background-color: #51829B; }"
                         "QPushButton:hover {background-color: #D0D0D0;}";

    QList<QPushButton*> pushButtons = findChildren<QPushButton*>();

    for (QPushButton* pushButton : pushButtons) {
        pushButton->setStyleSheet(styleSheet);
    }
}

void MainWindow::changeProgresssBar(){
    double  groupSize = testGroup.size();
    double position = testGroup.getIndex() +1;

    double percentage  = (position/groupSize) *100;



    ui->questionProgress->setValue(percentage);
}

// applies a color based on user answer
void MainWindow::applyAnswerStyleSheet(bool isCorrect){
    Question currentQuestion = testGroup.getQuestion();
    QString correctStyleSheet = "QRadioButton{ border: 1px solid black; border-radius: 7px;padding:5px; }"
                                "QRadioButton::indicator { width: 0; height: 0; } "
                                "QRadioButton{background-color: #BACD92;}";

    QString incorrectStyleSheet = "QRadioButton{ border: 1px solid black; border-radius: 7px;padding:5px; }"
                                  "QRadioButton::indicator { width: 0; height: 0; } "
                                  "QRadioButton{background-color: #DD5746;}";
    QString currentStyleSheet = incorrectStyleSheet;
    if(isCorrect){
        currentStyleSheet = correctStyleSheet;
    }

    int userAnswer = currentQuestion.getUserAnswer();

    if(currentQuestion.isMultipleChoiceQuestionType()){
        switch (userAnswer) {
        case 0:
            ui->option1RadioButton->setStyleSheet(currentStyleSheet);
            break;
        case 1:
            ui->option2RadioButton->setStyleSheet(currentStyleSheet);

            break;
        case 2:
            ui->option3RadioButton->setStyleSheet(currentStyleSheet);

            break;
        case 3:
            ui->option4RadioButton->setStyleSheet(currentStyleSheet);

            break;
        default:
            break;
        }
    }else{
        switch (userAnswer) {
        case 0:
            ui->TrueRadioButton->setStyleSheet(currentStyleSheet);
            break;
        case 1:
            ui->FalseRadioButton->setStyleSheet(currentStyleSheet);

            break;
        default:
            break;
        }

    }


}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // load first question of the 'quiz'
    QString progressBarStyleSheet = "QProgressBar {"
                         "border: 1px solid black;"
                         "border-radius: 7px;"
                         "background-color: #ffffff;"
                         "}"
                         "QProgressBar::chunk {"
                         "background-color: #51829B;"
                         "border-radius: 5px;"
                         "}"
        ;
    getLines("");

    vector<ParseQuestion> easy = getQuestionsOfDifficulty(30, "E",lines);
    testGroup.setAllQuestions(createValidQuestionFormat(easy));



    ui->questionProgress->setStyleSheet(progressBarStyleSheet);
    applyStyleSheetToRadioButtons();
    applyStyleSheetToPushButtons();
    assignQuestionData(testGroup.getQuestion());
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Checks if answer provided is correct
void MainWindow::on_submitButton_clicked()
{
    if(testGroup.getQuestion().getUserAnswer() != -1){
        if(testGroup.getQuestion().isCorrect()){
             // std::cout<< "Correct Answer" << std::endl;
            applyAnswerStyleSheet(true);
        }else{
            // std::cout<< "Incorrect Answer" << std::endl;
            applyAnswerStyleSheet(false);
        }
    }else{
        std::cout<< "Invalid Answer" << std::endl;

    }

}

// Transitions to next question index and loads next content
void MainWindow::on_nextButton_clicked()
{
    applyStyleSheetToRadioButtons();
    testGroup.next();
    // std::cout<< "Current Question Index : " << testGroup.getIndex() << std::endl;
    assignQuestionData(testGroup.getQuestion());

}

// Transitions to prior question index and loads content
void MainWindow::on_previousButton_clicked()
{
    applyStyleSheetToRadioButtons();
    testGroup.previous();
    assignQuestionData(testGroup.getQuestion());
}

// TODO : remove the below method : used of testing
// Displays the correct answer and current user answer
void MainWindow::on_pushButton_clicked()
{
    Question obj = testGroup.getQuestion();
    std::cout   << "Q : " << obj.getQuestionPrompt() << std::endl
                << "UA : " << obj.getUserAnswer() << std::endl
                << "CA : " << obj.getCorrectIndex()<<std::endl ;
}


// The following methods is used to check if a radiobutton is checked and sets the user answer in the question object
void MainWindow::on_option1RadioButton_clicked()
{

    applyStyleUpdateAnswer(0);
}

void MainWindow::on_option2RadioButton_clicked()
{
    applyStyleUpdateAnswer(1);
}

void MainWindow::on_option3RadioButton_clicked()
{
    applyStyleUpdateAnswer(2);
}

void MainWindow::on_option4RadioButton_clicked()
{
    applyStyleUpdateAnswer(3);
}

// The following methods are for the true/false radiobuttons
void MainWindow::on_TrueRadioButton_clicked()
{
    applyStyleUpdateAnswer(0);
}

void MainWindow::on_FalseRadioButton_clicked()
{
    applyStyleUpdateAnswer(1);

}



