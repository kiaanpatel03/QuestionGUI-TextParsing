#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <random>
#include <algorithm>
#include <Question.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// returns Question at specified index in the question bank
Question getQuestion(int index, vector<string> questions)
{
    Question returnQuestion;

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

vector<Question> getQuestionsOfDifficulty(int numQuestions, string difficulty, vector<string> questions)
{
    vector<Question> returnQuestions(0);
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
            Question fetchedQuestion = getQuestion(randomNumber, questions);

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



int main()
{
    srand(time(NULL));

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

    // Vectors to store 10 Questions of each difficulty
    vector<Question> easyQs;
    vector<Question> mediumQs;
    vector<Question> hardQs;

    cout << "\n" << easyQs.size() << "\n" << mediumQs.size()<< "\n" << hardQs.size() << endl;

    easyQs = getQuestionsOfDifficulty(5, "E", lines);

    cout << "\nQuestion1:\n" << endl;
    easyQs[0].printDetails();
    cout << "\nQuestion2:\n" << endl;
    easyQs[1].printDetails();
    cout << "\nQuestion3:\n" << endl;
    easyQs[2].printDetails();
    cout << "\nQuestion4:\n" << endl;
    easyQs[3].printDetails();
    cout << "\nQuestion5:\n" << endl;
    easyQs[4].printDetails();

    mediumQs = getQuestionsOfDifficulty(5, "M", lines);

    cout << "Question1:\n" << endl;
    mediumQs[0].printDetails();
    cout << "\nQuestion2:\n" << endl;
    mediumQs[1].printDetails();
    cout << "\nQuestion3:\n" << endl;
    mediumQs[2].printDetails();
    cout << "\nQuestion4:\n" << endl;
    mediumQs[3].printDetails();
    cout << "\nQuestion5:\n" << endl;
    mediumQs[4].printDetails();

    hardQs = getQuestionsOfDifficulty(5, "H", lines);

    cout << "Question1:\n" << endl;
    hardQs[0].printDetails();
    cout << "\nQuestion2:\n" << endl;
    hardQs[1].printDetails();
    cout << "\nQuestion3:\n" << endl;
    hardQs[2].printDetails();
    cout << "\nQuestion4:\n" << endl;
    hardQs[3].printDetails();
    cout << "\nQuestion5:\n" << endl;
    hardQs[4].printDetails();

    cout << "\n" << easyQs.size() << "\n" << mediumQs.size()<< "\n" << hardQs.size() << endl;

    return 0;
}
