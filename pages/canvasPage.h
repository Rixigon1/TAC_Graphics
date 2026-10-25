#ifndef CANVASPAGE_H
#define CANVASPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeWidget>
#include <QPainter>
#include <QHeaderView>
#include <QSplitter>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "../canvas/canvasView.h"
#include "../canvas/canvasScene.h"
#include "../items/gElemUnits.h"


class mainWindow;


class canvasPage : public QWidget {
    Q_OBJECT
    private:
        QGridLayout* gLay;
        QTreeWidget* tree;
        QSplitter* spt;
        canvasScene* scene;
        canvasView* view;
        QList<QPoint>* gridPoints;



    public:
        canvasPage(mainWindow* mWin, QWidget* parent = nullptr);

        void paintEvent(QPaintEvent* event);

    signals:

};

#endif // CANVASPAGE_H
