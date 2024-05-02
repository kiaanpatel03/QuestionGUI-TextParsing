#include <iostream>
#include <vector>
#ifndef QUESTION_H
#define QUESTION_H

class Question
{
public:
    Question();
    Question(std::string questionPrompt, std::vector<std::string> options, int correctIndex, bool isMultipleChoice);
    std::vector<std::string> getOptions();
    int getCorrectIndex();
    int getUserAnswer();
    void setUserAnswer(int answer);
    bool isMultipleChoiceQuestionType();
    std::string getQuestionPrompt();

    bool isCorrect();



private:
    std::string questionPrompt;
    bool isMultipleChoice;
    std::vector<std::string> options;
    int correctIndex;
    int userAnswer = -1;
};

#endif // QUESTION_H
