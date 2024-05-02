#include "parsequestion.h"

ParseQuestion::ParseQuestion()
{
    //ctor
}

ParseQuestion::~ParseQuestion()
{
    //dtor
}

string ParseQuestion::getQuestionID()
{
    return questionID;
}

void ParseQuestion::setQuestionID(string val)
{
    questionID = val;
}

string ParseQuestion::getQuestionType()
{
    return questionType;
}

void ParseQuestion::setQuestionType(string val)
{
    questionType = val;
}

string ParseQuestion::getQuestionDiff()
{
    return questionDiff;
}

void ParseQuestion::setQuestionDiff(string val)
{
    questionDiff = val;
}

string ParseQuestion::getQuestion()
{
    return question;
}

void ParseQuestion::setQuestion(string val)
{
    question = val;
}

string ParseQuestion::getPossibleAnswersString()
{
    return possibleAnswersString;
}

void ParseQuestion::setPossibleAnswersString(string val)
{
    possibleAnswersString = val;
}

vector<string> ParseQuestion::getPossibleAnswersVector()
{
    return possibleAnswersVector;
}

void ParseQuestion::setPossibleAnswersVector(vector<string> val)
{
    possibleAnswersVector = val;
}

string ParseQuestion::getQuestionAnswer()
{
    return questionAnswer;
}

void ParseQuestion::setQuestionAnswer(string val)
{
    questionAnswer = val;
}

void ParseQuestion::parseDetails(const string& line)
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

void ParseQuestion::printDetails()
{
    cout << "ParseQuestion ID: " << questionID << endl;
    cout << "ParseQuestion Type: " << questionType << endl;
    cout << "ParseQuestion Difficulty: " << questionDiff << endl;
    cout << "ParseQuestion: " << question << endl;
    cout << "Possible Answers: " << endl;

    vector<string> answers = parsePossibleAnswers();

    for(const auto& answer : answers)
    {
        cout << "\t" << answer << endl;
    }

    cout << "Answer: " << questionAnswer << endl;
}

vector<string> ParseQuestion::parsePossibleAnswers()
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
