#ifndef CANVASSCENE_H
#define CANVASSCENE_H

#include <QGraphicsScene>

#include "../items/gElemUnits.h"

class canvasScene : public QGraphicsScene {
    private:
        connectionPort* start;

        QPointF center(QGraphicsItem* item);
    public:
        canvasScene(QObject *parent = nullptr);

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent* event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        // void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // CANVASSCENE_H
