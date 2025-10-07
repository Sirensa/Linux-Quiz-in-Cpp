#include <iostream>
#include <string>
using namespace std;

struct Question {
    string question;
    string options[4];
    int correctIndex;
};

void askQuestion(const Question& q, int& score) {
    cout << "\n" << q.question << "\n";
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << q.options[i] << "\n";
    }

    int answer;
    cout << "Your answer (1-4): ";
    cin >> answer;

    if (answer == q.correctIndex + 1) {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer was: " << q.options[q.correctIndex] << "\n";
    }
}

int main() {
    Question quiz[] = {
        {
            "Which command is used to list files in Linux?",
            {"ls", "list", "dir", "show"},
            0
        },
        {
            "What does 'chmod' do?",
            {"Change file owner", "Change file permissions", "Move file", "Delete file"},
            1
        },
        {
            "Which directory contains system configuration files?",
            {"/bin", "/etc", "/usr", "/home"},
            1
        },
        {
            "What is the root user ID in Linux?",
            {"0", "1", "1000", "999"},
            0
        },
        {
            "Which command is used to display the current directory?",
            {"pwd", "dir", "where", "loc"},
            0
        }
    };

    int score = 0;
    int total = sizeof(quiz) / sizeof(quiz[0]);

    cout << "Welcome to the Linux Quiz!\n";
    for (int i = 0; i < total; ++i) {
        askQuestion(quiz[i], score);
    }

    cout << "\n You scored " << score << " out of " << total << "!\n";
    if (score == total) {
        cout << "Excellent! You're a Linux wizard! \n";
    } else if (score >= total / 2) {
        cout << "Good job! Keep learning Linux! \n";
    } else {
        cout << "Keep practicing! Linux mastery takes time. \n";
    }

    return 0;
}
