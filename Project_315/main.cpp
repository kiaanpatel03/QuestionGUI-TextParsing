#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <random>
#include <algorithm>

using namespace std;

struct Question
{
    string questionID;
    string questionType;
    string questionDiff;
    string question;
    string questionPossibleAnswersString;
    string questionAnswer;

    void parseDetails(const string& line)
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
        questionPossibleAnswersString = questionDetails[4];
        questionAnswer = questionDetails[5];
    }

    void printDetails()
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

    vector<string> parsePossibleAnswers()
    {
        vector<string> answers;

        // Copy the string to a non-const char array
        char questionLine[questionPossibleAnswersString.size() + 1];
        strcpy(questionLine, questionPossibleAnswersString.c_str());

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
};

int main()
{
    // read in the text file
    ifstream inputFile("C:/Users/Josh Goodwin/Desktop/School/UKZN/Third Year/COMP315/315 Projects/Project_315/WorldWar2Questions.txt");
    // variable to store each line of the text file as it is read in
    string line;
    // vector to store all of the lines
    vector<string> lines;

    // print error message if the file cannot be read
    if (!inputFile.is_open())
    {
        cout << "Unable to open file." << endl;
        return 1;
    }

    // Read each line from the file and store it in the vector
    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    // Close the input file
    inputFile.close();

    for (auto& line : lines)
    {
        cout << "\n" << line << "\n" << endl;

        Question question;
        question.parseDetails(line);
        question.printDetails();
    }

    return 0;
}
