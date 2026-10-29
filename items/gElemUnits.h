#ifndef GELEMUNITS_H
#define GELEMUNITS_H

// Переименовать файл в canvasGraphicsItems

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QVector>

#include "../models/tfModel.h"

class connectionPort;
class connectionLine;

class transferFunction : public QGraphicsItem {
    private:
        int ID;
        tfModel* model;
        QVector<connectionPort*> inPort;
        QVector<connectionPort*> outPort;


    public:

        enum { Type = UserType + 3 };

        int type() const {
            return Type;
        }

        transferFunction(int ID, tfModel* model);

        tfModel* getModel();

        virtual QRectF boundingRect() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

    protected:
        virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};
//-----------------------------------------------------------------------------------------------------------------

// Порт может иметь несколько линий на выходе -> сделать вектор линий
class connectionPort : public QGraphicsItem {
    private:
        int ID;
        transferFunction* parentTF;
        connectionLine* line;

    public:

        enum { Type = UserType + 1 };

        int type() const {
            return Type;
        }

        connectionPort(int ID, transferFunction* parent = nullptr);
        void setLine(connectionLine* line);
        connectionLine* getLine();
        void deleteLine();

        virtual QRectF boundingRect() const;
        virtual QPainterPath shape() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

    protected:
        virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
        virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value);
};

//-----------------------------------------------------------------------------------------------------------------


class connectionLine : public QGraphicsPathItem {
private:
    int ID;
    connectionPort* startPort;
    connectionPort* endPort;

public:

    enum { Type = UserType + 2 };

    int type() const {
        return Type;
    }


    connectionLine(QGraphicsItem* parent = nullptr);

    int getID();

    void updateLine(QPointF start, QPointF end);

    void setStartPort(connectionPort* startPort);
    void setEndPort(connectionPort* endPort);

    connectionPort* getStartPort();
    connectionPort* getEndPort();

    // virtual QRectF boundingRect() const;
    // virtual QPainterPath shape() const;
    // virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};



#endif // GELEMUNITS_H
