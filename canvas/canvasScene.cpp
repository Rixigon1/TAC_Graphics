#include "canvasScene.h"

canvasScene::canvasScene(QObject *parent) : QGraphicsScene(parent) {
    start = nullptr;
}

QPointF canvasScene::center(QGraphicsItem* item) {
    return item->mapToScene(item->boundingRect().center());
}

void canvasScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if(event->button() == Qt::RightButton && start && start->getLine()) {
        start->deleteLine();
        start = nullptr;
        event->accept();
        return;
    }

    if(event->button() != Qt::LeftButton) {
        QGraphicsScene::mousePressEvent(event);
        return;
    }


    // Добавить обработку нажатия на саму TF
    auto* portItem = qgraphicsitem_cast<connectionPort*>(itemAt(event->scenePos(), QTransform()));
    // auto* TFItem = qgraphicsitem_cast<transferFunction*>(itemAt(event->scenePos(), QTransform()));

    // Если линия уже создается
    if(start && start->getLine()) {
        connectionLine* line = start->getLine();
        if(portItem && start != portItem && !portItem->getLine()) {
            line->updateLine(center(start), center(portItem));
            line->setEndPort(portItem);
            portItem->setLine(line);
            line->setPen(QPen(Qt::black, 2));

            start = nullptr;
        }
        event->accept();
        return;
    }


    // Если только начинаем рисовать линию
    if(portItem && !portItem->getLine()) {
        start = portItem;

        QPointF sPoint = center(start);
        connectionLine* line = new connectionLine();
        addItem(line);
        start->setLine(line);
        line->setStartPort(start);
        line->setPath(QPainterPath(sPoint));
        line->setPen(QPen(Qt::black, 2));
        line->setBrush(Qt::NoBrush);
        line->setZValue(1);
        line->setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton);

        event->accept();
        return;
    }

    QGraphicsScene::mousePressEvent(event);
}

void canvasScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if(start && start->getLine()) {
        connectionLine* line = start->getLine();
        line->updateLine(center(start), event->scenePos());

        event->accept();
        return;
    }


    QGraphicsScene::mouseMoveEvent(event);
}











