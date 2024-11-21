#include <windows.h>
#include <string>
#include <sstream>

HWND hUser, hPin, hAmount, hOutput;
std::string username = "priyanka";
std::string pin = "1234";
double balance = 1000;

void UpdateOutput(HWND hOutput, const std::string& message) {
    SetWindowText(hOutput, message.c_str());
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    char userInput[100], pinInput[100], amountInput[100];
    switch (msg) {
        case WM_COMMAND:
            switch (wp) {
                case 1: 
                    GetWindowText(hUser, userInput, 100);
                    GetWindowText(hPin, pinInput, 100);
                    if (username == userInput && pin == pinInput) {
                        UpdateOutput(hOutput, "Login successful!");
                    } else {
                        UpdateOutput(hOutput, "Invalid username or PIN.");
                    }
                    break;
                case 2: 
                    GetWindowText(hAmount, amountInput, 100);
                    if (strlen(amountInput) > 0) {
                        double amount = atof(amountInput);
                        if (amount > 0) {
                            balance += amount;
                            std::ostringstream oss;
                            oss << "Deposit successful! New balance: $" << balance;
                            UpdateOutput(hOutput, oss.str());
                        } else {
                            UpdateOutput(hOutput, "Enter a valid amount.");
                        }
                    }
                    break;
                case 3: 
                    GetWindowText(hAmount, amountInput, 100);
                    if (strlen(amountInput) > 0) {
                        double amount = atof(amountInput);
                        if (amount > 0 && amount <= balance) {
                            balance -= amount;
                            std::ostringstream oss;
                            oss << "Withdrawal successful! New balance: $" << balance;
                            UpdateOutput(hOutput, oss.str());
                        } else if (amount > balance) {
                            UpdateOutput(hOutput, "Insufficient balance.");
                        } else {
                            UpdateOutput(hOutput, "Enter a valid amount.");
                        }
                    }
                    break;
                case 4: 
                    {
                        std::ostringstream oss;
                        oss << "Current balance: $" << balance;
                        UpdateOutput(hOutput, oss.str());
                    }
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "ATMWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClass(&wc)) return -1;

    HWND hwnd = CreateWindow("ATMWindowClass", "ATM Management System", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
                              100, 100, 400, 500, NULL, NULL, NULL, NULL);

    CreateWindow("static", "Username:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 20, hwnd, NULL, NULL, NULL);
    hUser = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow("static", "PIN:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 20, hwnd, NULL, NULL, NULL);
    hPin = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 100, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow("static", "Amount:", WS_VISIBLE | WS_CHILD, 50, 150, 100, 20, hwnd, NULL, NULL, NULL);
    hAmount = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 150, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow("button", "Login", WS_VISIBLE | WS_CHILD, 50, 200, 100, 30, hwnd, (HMENU)1, NULL, NULL);
    CreateWindow("button", "Deposit", WS_VISIBLE | WS_CHILD, 150, 200, 100, 30, hwnd, (HMENU)2, NULL, NULL);
    CreateWindow("button", "Withdraw", WS_VISIBLE | WS_CHILD, 250, 200, 100, 30, hwnd, (HMENU)3, NULL, NULL);
    CreateWindow("button", "Check Balance", WS_VISIBLE | WS_CHILD, 150, 250, 100, 30, hwnd, (HMENU)4, NULL, NULL);

    hOutput = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY, 
                           50, 300, 300, 100, hwnd, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
