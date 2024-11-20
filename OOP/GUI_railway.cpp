#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>  
using namespace std;

vector<string> trains;
vector<string> tickets;
INT_PTR CALLBACK SearchTrainDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK SearchTicketDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void AddTrain(const string& trainInfo);
void BookTicket(const string& ticketInfo);
void CancelTicket(const string& ticketInfo);
void ViewAllTrains(HWND hwnd);
void ViewAllTickets(HWND hwnd);
void SearchTrain(HWND hwnd);
void SearchTicket(HWND hwnd);
void ClearAllTickets(HWND hwnd);
int main() {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char CLASS_NAME[]  = "TrainTicketBookingWindow";

    WNDCLASS wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Train Ticket Booking System", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 500, 350, nullptr, nullptr, hInstance, nullptr);

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: {
        CreateWindow("BUTTON", "Add Train", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     50, 50, 100, 30, hwnd, (HMENU)1, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "Book Ticket", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     50, 100, 100, 30, hwnd, (HMENU)2, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "Cancel Ticket", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     50, 150, 100, 30, hwnd, (HMENU)3, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "View All Trains", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     50, 200, 120, 30, hwnd, (HMENU)4, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "View All Tickets", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     50, 250, 120, 30, hwnd, (HMENU)5, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "Search Train", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     200, 50, 100, 30, hwnd, (HMENU)6, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "Search Ticket", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     200, 100, 100, 30, hwnd, (HMENU)7, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        CreateWindow("BUTTON", "Clear All Tickets", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                     200, 150, 120, 30, hwnd, (HMENU)8, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), nullptr);
        break;
    }
    case WM_COMMAND: {
        int wmId = LOWORD(wParam);
        switch (wmId) {
        case 1:  
            AddTrain("Train 101: Express, Origin: New York, Destination: LA");
            MessageBox(hwnd, "Train Added", "Info", MB_OK);
            break;
        case 2:  
            BookTicket("Ticket for Train 101: Alice, From: New York To: LA");
            MessageBox(hwnd, "Ticket Booked", "Info", MB_OK);
            break;
        case 3:  
            CancelTicket("Ticket for Train 101: Alice");
            MessageBox(hwnd, "Ticket Canceled", "Info", MB_OK);
            break;
        case 4:  
            ViewAllTrains(hwnd);
            break;
        case 5:  
            ViewAllTickets(hwnd);
            break;
        case 6:  
            SearchTrain(hwnd);
            break;
        case 7: 
            SearchTicket(hwnd);
            break;
        case 8:  
            ClearAllTickets(hwnd);
            MessageBox(hwnd, "All Tickets Cleared", "Info", MB_OK);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
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

void AddTrain(const string& trainInfo) {
    trains.push_back(trainInfo);
}

void BookTicket(const string& ticketInfo) {
    tickets.push_back(ticketInfo);
}

void CancelTicket(const string& ticketInfo) {
    auto it = find(tickets.begin(), tickets.end(), ticketInfo);
    if (it != tickets.end()) {
        tickets.erase(it);
    }
}

void ViewAllTrains(HWND hwnd) {
    string trainList = "Trains:\n";
    for (const string& train : trains) {
        trainList += train + "\n";
    }
    MessageBox(hwnd, trainList.c_str(), "All Trains", MB_OK);
}

void ViewAllTickets(HWND hwnd) {
    string ticketList = "Tickets:\n";
    for (const string& ticket : tickets) {
        ticketList += ticket + "\n";
    }
    MessageBox(hwnd, ticketList.c_str(), "All Tickets", MB_OK);
}

void SearchTrain(HWND hwnd) {
    char trainName[100] = {0};
    int result = DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(1), hwnd, (DLGPROC)SearchTrainDlgProc, (LPARAM)trainName);
    if (result == IDOK) {
        string message = "Train found: " + string(trainName);
        MessageBox(hwnd, message.c_str(), "Train Search Result", MB_OK);
    }
}

void SearchTicket(HWND hwnd) {
    char ticketInfo[100] = {0};
    int result = DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(1), hwnd, (DLGPROC)SearchTicketDlgProc, (LPARAM)ticketInfo);
    if (result == IDOK) {
        string message = "Ticket found: " + string(ticketInfo);
        MessageBox(hwnd, message.c_str(), "Ticket Search Result", MB_OK);
    }
}

void ClearAllTickets(HWND hwnd) {
    tickets.clear();
}

INT_PTR CALLBACK SearchTrainDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static char* trainName;
    switch (uMsg) {
    case WM_INITDIALOG:
        trainName = (char*)lParam;
        return TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK) {
            GetDlgItemText(hwndDlg, 1, trainName, 100);
            EndDialog(hwndDlg, IDOK);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

INT_PTR CALLBACK SearchTicketDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static char* ticketInfo;
    switch (uMsg) {
    case WM_INITDIALOG:
        ticketInfo = (char*)lParam;
        return TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK) {
            GetDlgItemText(hwndDlg, 1, ticketInfo, 100);
            EndDialog(hwndDlg, IDOK);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
