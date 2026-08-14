#include "canvasPage.h"
#include "../mainWindow.h"

canvasPage::canvasPage(mainWindow* mWin, QWidget* parent) : QWidget{parent} {
    setObjectName("canvasPage");

    spt = new QSplitter();
    gLay = new QGridLayout();
    tree = new QTreeWidget();
    // Сделать собственный класс сцены в котором будут определены дополнительные методы связанные с привязкой объектов к сетке
    scene = new QGraphicsScene();
    scene->setSceneRect(-40000, -40000, 80000, 80000);
    view = new canvasView(scene);

    spt->addWidget(tree);
    spt->addWidget(view);

    spt->setObjectName("elementsSplitter");
    spt->setHandleWidth(3);
    spt->setSizes({200, 700});

    tree->setObjectName("elementsTree");
    tree->setWordWrap(true);
    tree->setTextElideMode(Qt::ElideNone);
    tree->setUniformRowHeights(false);

    gLay->setSpacing(0);
    gLay->setContentsMargins(0, 0, 0, 1);

    QStringList elemNames = mWin->getElemUnits_names();
    QStringList helpNames = mWin->getHelpUnits_names(); // Сделать файл

    tree->setHeaderLabel(tr("Звенья"));
    tree->setDragDropMode(QAbstractItemView::DragOnly);

    QTreeWidgetItem* elemItems = new QTreeWidgetItem;
    elemItems->setFlags(elemItems->flags() & ~Qt::ItemIsDragEnabled);
    elemItems->setText(0, tr("Элементарные звенья"));
    for(int i = 0; i < elemNames.length(); i++) {
        QTreeWidgetItem* item = new QTreeWidgetItem;
        item->setText(0, elemNames.value(i));
        // Сделать данные для распознавания что вставлять на холст после перетаскивания
        // item->setData(0, );
        elemItems->addChild(item);
    }
    tree->addTopLevelItem(elemItems);

    // Сумматор и др элементы если есть
    QTreeWidgetItem* helpItems = new QTreeWidgetItem;
    helpItems->setFlags(elemItems->flags() & ~Qt::ItemIsDragEnabled);
    helpItems->setText(0, tr("Элементы построения\nструктурной схемы"));
    for(int i = 0; i < helpNames.length(); i++) {
        QTreeWidgetItem* item = new QTreeWidgetItem;
        item->setText(0, helpNames.value(i));
        // Сделать данные для распознавания что вставлять на холст после перетаскивания
        // item->setData(0, );
        helpItems->addChild(item);
    }
    tree->addTopLevelItem(helpItems);

    // Сделать собственный класс сцены в котором будут определены дополнительные методы связанные с привязкой объектов к сетке
    view->gridOn();

    QPen pen(Qt::black);
    QBrush brush(Qt::white);
    // scene->addEllipse(QRectF(0, 0, 40, 40), pen, brush);

    transferFunction* tf = new transferFunction;
    scene->addItem(tf);


    setStyleSheet(R"(
        QWidget#canvasPage {
                background-color: rgb(70, 70, 70);
                border: 1px solid black;
        }
        )"
    );

    spt->setStyleSheet(R"(
        QSplitter#elementsSplitter::handle:horizontal {
            background-color: rgb(160, 160, 160);
        }

        QSplitter#elementsSplitter::handle:horizontal:hover {
            background-color: rgb(120, 120, 120);
        }

        QSplitter#elementsSplitter::handle:horizontal:pressed {
            background-color: rgb(40, 40, 40);
        }
        )"
    );

    tree->setStyleSheet(R"(
        QTreeWidget#elementsTree {
            background-color: rgb(100, 100, 100);
            color: white;
            outline: none;

            border: 1px solid black;
            border-bottom: none;
            padding: 0px;
        }


        QTreeWidget#elementsTree QHeaderView {
            background-color: rgb(100, 100, 100);
            border: none;
            border-bottom: 1px solid black
        }

        QTreeWidget#elementsTree QHeaderView::section {
            background-color: rgb(100, 100, 100);
            color: white;

            border: none;
            padding: 4px;
        }

        QTreeWidget#elementsTree::item {
            background-color: transparent;
            border: none;
        }

        QTreeWidget#elementsTree::item:hover {
            background-color: rgb(110, 110, 110);
        }

        QTreeWidget#elementsTree::item:selected {
            background-color: rgb(90, 90, 90);
            color: white;
        }

    )");


    // gLay->addWidget(tree, 0, 0, Qt::AlignLeft);
    gLay->addWidget(spt, 0, 0);
    setLayout(gLay);
}


void canvasPage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QWidget::paintEvent(event);

    QStyleOption option;
    option.initFrom(this);

    QPainter painter(this);

    style()->drawPrimitive(
        QStyle::PE_Widget,
        &option,
        &painter,
        this
        );
}