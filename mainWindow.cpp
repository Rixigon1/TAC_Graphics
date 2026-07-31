#include "mainWindow.h"

#include <QDebug>


mainWindow::mainWindow(QWidget *parent) : QWidget{parent} {

    setObjectName("mainWindow");
    setMinimumSize(1000, 600);

    gLay->setSpacing(0);
    gLay->setContentsMargins(0, 0, 0, 1);

    QMenu* fileMenu = mainMenu->addMenu(tr("&Файл"));
    QAction* newFile = fileMenu->addAction(tr("&Новый файл..."));
    QAction* openFile = fileMenu->addAction(tr("&Открыть файл..."));
    QAction* closeFile = fileMenu->addAction(tr("&Закрыть файл..."));
    fileMenu->addSeparator();
    QAction* saveFile = fileMenu->addAction(tr("&Сохранить файл"));
    QAction* saveAsFile = fileMenu->addAction(tr("Сохранить файл &как..."));

    saveFile->setEnabled(false);
    saveAsFile->setEnabled(false);

    connect(newFile, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(openFile, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(closeFile, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(saveFile, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(saveAsFile, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));


    QMenu* editMenu = mainMenu->addMenu(tr("&Изменить"));
    QAction* undo = editMenu->addAction(tr("О&тменить"));
    QAction* redo = editMenu->addAction(tr("&Вернуть"));
    editMenu->addSeparator();
    QAction* cut = editMenu->addAction(tr("Вы&резать"));
    QAction* copy = editMenu->addAction(tr("Ко&пировать"));
    QAction* paste = editMenu->addAction(tr("Вст&авить"));

    for(QAction* action : editMenu->actions()) {
        action->setEnabled(false);
    }

    connect(undo, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(redo, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(cut, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(copy, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));
    connect(paste, SIGNAL(triggered(bool)), this, SLOT(notYetImplimend()));




    mainMenu->setContentsMargins(0, 0, 0, 0);
    QFont font = mainMenu->font();
    font.setPointSize(6);
    mainMenu->setFont(font);
    gLay->setMenuBar(mainMenu);


    mainBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    mainBar->setIconSize(QSize(24, 24));

    QActionGroup* barGroup = new QActionGroup(this);
    QAction* welcomeActionBar = barGroup->addAction(tr("Добро\nпожаловать"));
    QAction* editBar = barGroup->addAction(tr("Редактировать\nструктурную схему"));
    QAction* preferencesBar = barGroup->addAction(tr("Настройки"));
    QAction* solverBar = barGroup->addAction(tr("Решить\nсистему ДУ"));

    welcomeActionBar->setIcon(QIcon(":/Icons//Windows.jpg"));
    editBar->setIcon(QIcon(":/Icons//Windows.jpg"));
    solverBar->setIcon(QIcon(":/Icons//Windows.jpg"));
    preferencesBar->setIcon(QIcon(":/Icons//Windows.jpg"));

    barGroup->addAction(welcomeActionBar);
    barGroup->addAction(editBar);
    barGroup->addAction(solverBar);
    barGroup->addAction(preferencesBar);

    welcomeActionBar->setCheckable(true);
    editBar->setCheckable(true);
    solverBar->setCheckable(true);
    preferencesBar->setCheckable(true);

    barGroup->setExclusive(true);

    mainBar->setOrientation(Qt::Vertical);
    mainBar->addAction(welcomeActionBar);
    mainBar->addAction(editBar);
    mainBar->addAction(solverBar);
    mainBar->addAction(preferencesBar);

    // Переписать под лямбду и вызов connect-а один раз для QActionGroup
    int i = 0;
    for(QAction* action : mainBar->actions()) {
        connect(action, SIGNAL(triggered(bool)), sMapper, SLOT(map()));
        sMapper->setMapping(action, i);
        if(QToolButton* button = qobject_cast<QToolButton*>(mainBar->widgetForAction(action))) {
            if(i == 0) {
                button->setChecked(true);
            }
            button->setAutoRaise(true);
            button->setFixedSize(120, 70);
        }
        i++;
    }



    mainBar->setSizePolicy(
        QSizePolicy::Fixed,
        QSizePolicy::Expanding
    );
    gLay->addWidget(mainBar, 1, 0);


    connect(sMapper, SIGNAL(mappedInt(int)), this, SLOT(setActivePage(int)));

    welcomePage* wPage = new welcomePage;
    canvasPage* cPage = new canvasPage;
    solverPage* sPage = new solverPage;
    preferencesPage* pPage = new preferencesPage;

    // Мера для тестирования
    i = 40;
    for(QWidget* wgt : {(QWidget*)wPage, (QWidget*)cPage, (QWidget*)sPage, (QWidget*)pPage}) {
        QPalette pal = wgt->palette();
        pal.setColor(QPalette::Window, QColor(i, i, i));
        wgt->setPalette(pal);
        wgt->setAutoFillBackground(true);
        i += 40;
    }

    pages->insertWidget(0, wPage);
    pages->insertWidget(1, cPage);
    pages->insertWidget(2, sPage);
    pages->insertWidget(3, pPage);
    pages->setCurrentIndex(0);

    connect(pages, &QStackedWidget::currentChanged, this, [editMenu](int j){
        if(j == 0 || j == 3) {
            for(QAction* action : editMenu->actions()) {
                action->setEnabled(false);
            }
        }
        else {
            for(QAction* action : editMenu->actions()) {
                action->setEnabled(true);
            }
        }
    });

    gLay->addWidget(pages, 1, 1);


    stBar->setFixedHeight(20);
    gLay->addWidget(stBar, 2, 0, 1, 2);

    setLayout(gLay);






    setStyleSheet(R"(
        QWidget#mainWindow {
            background-color: rgb(100, 100, 100);
            border: none;
        }
        )"
    );

    mainMenu->setStyleSheet(R"(
        QMenuBar {
            color: white;
            font-size: 10pt;
            font-weight: normal;
            padding: 0px 0px;
        }

        QMenuBar::item {
            padding: 3px 5px;
        }

        QMenuBar::item:selected {
            padding: 3px 5px;
            margin: 0px;
            background-color: #9A737F;

        }

    )");

    fileMenu->setStyleSheet(R"(
        QMenu {
            background-color: rgb(100, 100, 100);
            border: none;
            border-radius: 0px;
            spacing: 0px;
            margin: 0px;
            padding: 0px;
        }
        QMenu::item {
            background-color: transparent;
            color: white
        }
        QMenu::item:selected {
            background-color: rgb(85, 85, 85);
        }
        QMenu::item:disabled {
            background-color: transparent;
            color: rgb(200, 200, 200);
        }
    )");

    editMenu->setStyleSheet(R"(
        QMenu {
            background-color: rgb(100, 100, 100);
            border: none;
            border-radius: 0px;
            spacing: 0px;
            margin: 0px;
            padding: 0px;
        }
        QMenu::item {
            background-color: transparent;
            color: white
        }
        QMenu::item:selected {
            background-color: rgb(85, 85, 85);
        }
        QMenu::item:disabled {
            background-color: transparent;
            color: rgb(200, 200, 200);
        }
    )");

    mainBar->setStyleSheet(R"(
        QToolBar {
            background-color: rgb(100, 100, 100);
            border: none;
            spacing: 0px;
        }

        QToolButton {
            color: white;
            background-color: transparent;

            border: none;
            border-left: 3px solid transparent;
        }

        QToolButton:hover {
            background-color: rgb(85, 85, 85);
        }

        QToolButton:checked {
            color: white;
            background-color: transparent;

            border: none;
            border-left: 3px solid #9A737F;
        }

        QToolButton:checked:hover {
            background-color: rgb(85, 85, 85);

            border: none;
            border-left: 3px solid #9A737F;
        }
    )");




}


void mainWindow::notYetImplimend() {
    QMessageBox mes(this);
    mes.setText(QObject::tr("Данный функционал ещё не реализован"));
    mes.setIcon(QMessageBox::Icon::Warning);
    mes.exec();
}

void mainWindow::setActivePage(int id) {
    pages->setCurrentIndex(id);
}