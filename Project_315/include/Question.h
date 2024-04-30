#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <random>
#include <algorithm>
#include <Question.h>

using namespace std;


class Question
{
public:
    Question();
    virtual ~Question();
    string getQuestionID();
    void setQuestionID(string val);
    string getQuestionType();
    void setQuestionType(string val);
    string getQuestionDiff();
    void setQuestionDiff(string val);
    string getQuestion();
    void setQuestion(string val);
    string getPossibleAnswersString();
    void setPossibleAnswersString(string val);
    vector<string> getPossibleAnswersVector();
    void setPossibleAnswersVector(vector<string> val);
    string getQuestionAnswer();
    void setQuestionAnswer(string val);
    void parseDetails(const string& line);
    void printDetails();
    vector<string> parsePossibleAnswers();

protected:

private:
    string questionID;
    string questionType;
    string questionDiff;
    string question;
    string possibleAnswersString;
    vector<string> possibleAnswersVector;
    string questionAnswer;
};

#endif // QUESTION_H
