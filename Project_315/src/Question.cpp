#include "Question.h"

Question::Question()
{
    //ctor
}

Question::~Question()
{
    //dtor
}

string Question::getQuestionID()
{
    return questionID;
}

void Question::setQuestionID(string val)
{
    questionID = val;
}

string Question::getQuestionType()
{
    return questionType;
}

void Question::setQuestionType(string val)
{
    questionType = val;
}

string Question::getQuestionDiff()
{
    return questionDiff;
}

void Question::setQuestionDiff(string val)
{
    questionDiff = val;
}

string Question::getQuestion()
{
    return question;
}

void Question::setQuestion(string val)
{
    question = val;
}

string Question::getPossibleAnswersString()
{
    return possibleAnswersString;
}

void Question::setPossibleAnswersString(string val)
{
    possibleAnswersString = val;
}

vector<string> Question::getPossibleAnswersVector()
{
    return possibleAnswersVector;
}

void Question::setPossibleAnswersVector(vector<string> val)
{
    possibleAnswersVector = val;
}

string Question::getQuestionAnswer()
{
    return questionAnswer;
}

void Question::setQuestionAnswer(string val)
{
    questionAnswer = val;
}

void Question::parseDetails(const string& line)
{
    vector<string> questionDetails;

    // Copy the string to a non-const char array
    char charLine[line.size() + 1];
    strcpy(charLine, line.c_str());

    char* ptr;
    ptr = strtok(charLine, "#"); // Delimiters are #

    // use while loop to check ptr is not null
    while (ptr != NULL)
    {
        questionDetails.push_back(ptr); // push the string token
        ptr = strtok (NULL, "#");
    }

    questionID = questionDetails[0];
    questionType = questionDetails[1];
    questionDiff = questionDetails[2];
    question = questionDetails[3];
    possibleAnswersString = questionDetails[4];
    questionAnswer = questionDetails[5];
}

void Question::printDetails()
{
    cout << "Question ID: " << questionID << endl;
    cout << "Question Type: " << questionType << endl;
    cout << "Question Difficulty: " << questionDiff << endl;
    cout << "Question: " << question << endl;
    cout << "Possible Answers: " << endl;

    vector<string> answers = parsePossibleAnswers();

    for(const auto& answer : answers)
    {
        cout << "\t" << answer << endl;
    }

    cout << "Answer: " << questionAnswer << endl;
}

vector<string> Question::parsePossibleAnswers()
{
    vector<string> answers;

    // Copy the string to a non-const char array
    char questionLine[possibleAnswersString.size() + 1];
    strcpy(questionLine, possibleAnswersString.c_str());

    char* Qptr;
    Qptr = strtok(questionLine, "$"); // Delimiters are $

    // use while loop to check ptr is not null
    while (Qptr != NULL)
    {
        answers.push_back(Qptr); // push the string token
        Qptr = strtok (NULL, "$");
    }

    return answers;
}
