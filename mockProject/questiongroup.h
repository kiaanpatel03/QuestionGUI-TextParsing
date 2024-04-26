#ifndef QUESTIONGROUP_H
#define QUESTIONGROUP_H
#include "question.h"
#include <vector>


class QuestionGroup
{
public:
    QuestionGroup();
    QuestionGroup(std::vector<Question> allQuestions): allQuestions(allQuestions){}

    void next();
    void previous();
    Question getQuestion();
    void setQuestion( Question question);
    int getIndex();
    ~QuestionGroup();
private:
    std::vector<Question> allQuestions;
    int index = 0;

};

#endif // QUESTIONGROUP_H
