#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QToolBar>
#include <QPushButton>
#include <QActionGroup>
#include <QStackedWidget>
#include <QActionGroup>
#include <QToolButton>
#include <QSignalMapper>
#include <QPalette>
#include <QStatusBar>
#include <QFile>

#include "pages/welcomePage.h"
#include "pages/canvasPage.h"
#include "pages/solverPage.h"
#include "pages/preferencesPage.h"

class mainWindow : public QWidget {
    Q_OBJECT
    private:
        bool fileOpened = false;
        bool canvasActiveFocus = false;
        QStringList openedFiles;
        QString lang = "_ru";
        QStringList elemUnits_names;
        QStringList helpUnits_names;
        QString elemUnits_path = "iniFiles/";
        QString elemUnits_fileName = "elemUnitsNames";
        QString helpUnits_fileName = "helpUnitsNames";

        // Сделать считывание из файла


        // Путь к сохраненным файлам переместить в настройки QSettings


        QSignalMapper* sMapper = new QSignalMapper(this);
        QGridLayout* gLay = new QGridLayout;
        QMenuBar* mainMenu = new QMenuBar;
        QStackedWidget* pages = new QStackedWidget;
        QToolBar* mainBar = new QToolBar;
        QStatusBar* stBar = new QStatusBar;

    public:
        mainWindow(QWidget *parent = nullptr);

        const QStringList getElemUnits_names();
        const QStringList getHelpUnits_names();

    signals:

    public slots:
        void setActivePage(int id);
        void notYetImplimend();
};

#endif // MAINWINDOW_H
