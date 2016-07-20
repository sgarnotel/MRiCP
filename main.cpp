#include "mainwindow.h"

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 *
 * The main function
 */
int main(int argc, char *argv[])
{
    cout << "DEBUG " << DEBUG << endl;

    if (DEBUG){
#ifdef LINUX_OS
        bool res = system("pwd");
#endif
#ifdef MAC_OS
        bool res = system("pwd");
#endif
#ifdef WIN_OS
        bool res = system("cd");
#endif

        if (res){
            cout << "Location fail!" << endl;
        }
    }

    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}


