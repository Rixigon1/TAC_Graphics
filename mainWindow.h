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

#include "welcomePage.h"
#include "canvasPage.h"
#include "solverPage.h"
#include "preferencesPage.h"

class mainWindow : public QWidget {
    Q_OBJECT
    private:
        bool fileOpened = false;
        bool canvasActiveFocus = false;
        QStringList openedFiles;

        QSignalMapper* sMapper = new QSignalMapper(this);
        QGridLayout* gLay = new QGridLayout;
        QMenuBar* mainMenu = new QMenuBar;
        QStackedWidget* pages = new QStackedWidget;
        QToolBar* mainBar = new QToolBar;
        QStatusBar* stBar = new QStatusBar;

    public:
        mainWindow(QWidget *parent = nullptr);

    signals:

    public slots:
        void setActivePage(int id);
        void notYetImplimend();
};

#endif // MAINWINDOW_H
