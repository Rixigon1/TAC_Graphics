#ifndef GELEMUNITS_H
#define GELEMUNITS_H

// Переименовать файл в canvasGraphicsItems

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
        transferFunction* nextTF;

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
        connectionLine* line;

    public:

        enum { Type = UserType + 1 };

        int type() const
        {
            return Type;
        }

        connectionPort(QGraphicsItem* parent);
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
    connectionPort* startPort;
    connectionPort* endPort;

public:
    connectionLine(QGraphicsItem* parent = nullptr);

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
