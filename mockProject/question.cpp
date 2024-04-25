#include "question.h"

Question::Question() {}

Question::Question(std::string questionPrompt, std::vector<std::string> options, int correctIndex, bool isMultipleChoice){
    this->questionPrompt= questionPrompt;
    this->options = options;
    this->correctIndex = correctIndex;
    this->isMultipleChoice = isMultipleChoice;
}

std::vector<std::string> Question::getOptions(){
    return this->options;
}
int Question::getCorrectIndex(){
    return this->correctIndex;
}

std::string Question::getQuestionPrompt(){
    return this->questionPrompt;
}


int Question::getUserAnswer(){
    return this->userAnswer;

}
bool Question::isMultipleChoiceQuestionType(){
    return this->isMultipleChoice;
}
void Question::setUserAnswer(int answer){
    this->userAnswer = answer;


}

bool Question::isCorrect(){
    return (userAnswer == correctIndex);
}








