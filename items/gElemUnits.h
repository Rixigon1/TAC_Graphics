#ifndef GELEMUNITS_H
#define GELEMUNITS_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>

class connectionPort;
class connectionLine;

class transferFunction : public QGraphicsItem {
    private:
        connectionPort* inPort;
        connectionPort* outPort;

    public:
        transferFunction();

        virtual QRectF boundingRect() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

    protected:
        virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};
//-----------------------------------------------------------------------------------------------------------------

class connectionPort : public QGraphicsItem {
    private:
        transferFunction* parentTF;

    public:
        connectionPort(QGraphicsItem* parent);

        virtual QRectF boundingRect() const;
        virtual QPainterPath shape() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

    protected:
        virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

//-----------------------------------------------------------------------------------------------------------------


class connectionLine : public QGraphicsItem {
private:
    connectionPort* startPort;
    connectionPort* endPort;

public:
    connectionLine(QGraphicsItem* parent);

    virtual QRectF boundingRect() const;
    virtual QPainterPath shape() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};



#endif // GELEMUNITS_H
