#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

HINSTANCE g_hInst;
HWND hUsername, hPassword, hLoginBtn, hQuestion, hOptions[4], hSubmitBtn, hScore;
string username, password;
int currentQuestion = 0, score = 0;
vector<string> questions;
vector<vector<string>> options;
vector<char> answers;
bool isLoggedIn = false;

void ShowMessage(const char* message, const char* title = "Message") {
    MessageBox(NULL, message, title, MB_OK | MB_ICONINFORMATION);
}

void InitializeQuestions() {
    questions = {
        "1. What is 5 + 3?",
        "2. What is the color of the sky?",
        "3. What is the capital of India?"
    };

    options = {
        {"A) 6", "B) 7", "C) 8", "D) 9"},
        {"A) Blue", "B) Green", "C) Yellow", "D) Red"},
        {"A) Mumbai", "B) Berlin", "C) Delhi", "D) Madrid"}
    };

    answers = {'C', 'A', 'C'};
}

void DisplayQuestion(HWND hwnd) {
    if (currentQuestion < questions.size()) {
        SetWindowText(hQuestion, questions[currentQuestion].c_str());
        for (int i = 0; i < 4; i++) {
            SetWindowText(hOptions[i], options[currentQuestion][i].c_str());
        }
    } else {
        stringstream ss;
        ss << "Quiz Completed! Your Score: " << score << "/" << questions.size();
        ShowMessage(ss.str().c_str(), "Quiz Result");
        PostQuitMessage(0);  
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND: {
        if ((HWND)lParam == hLoginBtn) {
            char user[30], pass[30];
            GetWindowText(hUsername, user, 30);
            GetWindowText(hPassword, pass, 30);

            username = user;
            password = pass;

            if (username == "user" && password == "pass") {
                ShowMessage("Login Successful!", "Login");
                isLoggedIn = true;

                ShowWindow(hUsername, SW_HIDE);
                ShowWindow(hPassword, SW_HIDE);
                ShowWindow(hLoginBtn, SW_HIDE);

                ShowWindow(hQuestion, SW_SHOW);
                for (auto& opt : hOptions) {
                    ShowWindow(opt, SW_SHOW);
                }
                ShowWindow(hSubmitBtn, SW_SHOW);

                DisplayQuestion(hwnd);
            } else {
                ShowMessage("Invalid Username or Password!", "Error");
            }
        }

        if ((HWND)lParam == hSubmitBtn) {
            for (int i = 0; i < 4; i++) {
                if (SendMessage(hOptions[i], BM_GETCHECK, 0, 0) == BST_CHECKED) {
                    if (answers[currentQuestion] == 'A' + i) {
                        score++;
                        ShowMessage("Correct Answer!", "Quiz");
                    } else {
                        stringstream ss;
                        ss << "Wrong! Correct Answer is " << answers[currentQuestion];
                        ShowMessage(ss.str().c_str(), "Quiz");
                    }
                    break;
                }
            }

            currentQuestion++;
            DisplayQuestion(hwnd);
        }
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    g_hInst = hInstance;
    InitializeQuestions();

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "QuizApp";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindow("QuizApp", "Quiz Application", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                              CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
                              NULL, NULL, hInstance, NULL);

    CreateWindow("STATIC", "Username:", WS_VISIBLE | WS_CHILD,
                 50, 50, 100, 20, hwnd, NULL, hInstance, NULL);
    hUsername = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                              150, 50, 200, 20, hwnd, NULL, hInstance, NULL);

    CreateWindow("STATIC", "Password:", WS_VISIBLE | WS_CHILD,
                 50, 100, 100, 20, hwnd, NULL, hInstance, NULL);
    hPassword = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD,
                              150, 100, 200, 20, hwnd, NULL, hInstance, NULL);

    hLoginBtn = CreateWindow("BUTTON", "Login", WS_VISIBLE | WS_CHILD,
                              150, 150, 100, 30, hwnd, NULL, hInstance, NULL);

    hQuestion = CreateWindow("STATIC", "", WS_CHILD,
                              50, 50, 400, 60, hwnd, NULL, hInstance, NULL);

    for (int i = 0; i < 4; i++) {
        hOptions[i] = CreateWindow("BUTTON", "", WS_CHILD | BS_RADIOBUTTON,
                                   50, 120 + i * 30, 400, 30, hwnd, NULL, hInstance, NULL);
    }

    hSubmitBtn = CreateWindow("BUTTON", "Submit", WS_CHILD,
                               150, 300, 100, 30, hwnd, NULL, hInstance, NULL);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
