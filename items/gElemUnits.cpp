#include "gElemUnits.h"

transferFunction::transferFunction() : QGraphicsItem() {
    out = new connectionPort(this);
    out->setPos(50, 0);

    setFlags(ItemIsMovable | ItemIsSelectable);
}

QRectF transferFunction::boundingRect() const {
    return QRectF(-50, -20, 110, 40);
}

void transferFunction::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPen pen(Qt::black);
    QBrush brush(Qt::white);
    QRectF rectBorder(-50, -20, 100, 40);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(rectBorder);
    painter->drawText(rectBorder, Qt::AlignCenter, "Transfer function");


}

void transferFunction::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if(event->button() == Qt::LeftButton && event->pos() == QPointF(0, 0)) {

    }
    QGraphicsItem::mousePressEvent(event);
}

void transferFunction::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void transferFunction::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

//-----------------------------------------------------------------------------------------------------------------


connectionPort::connectionPort(QGraphicsItem* parent) : QGraphicsItem(parent) {
    setFlags(ItemIsMovable | ItemIsSelectable);
}

QRectF connectionPort::boundingRect() const {
    return QRectF(-2.5, -2.5, 5, 5);
}

void connectionPort::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPen pen(Qt::black);
    QBrush brush(Qt::black);
    QRectF rect(-2.5, -2.5, 5, 5);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPie(rect, -90*16, 180*16);
}

QPainterPath connectionPort::shape() const {
    QPainterPath path;
    QRectF rect(-2.5, -2.5, 5.5, 5.5);
    path.moveTo(0, 2.5);
    path.arcTo(rect, -90, 180);
    path.closeSubpath();
    return path;
}

void connectionPort::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "Button pressed: " << event->button();
    if(event->button() == Qt::LeftButton) {

    }
    QGraphicsItem::mousePressEvent(event);
}

void connectionPort::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void connectionPort::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}


//-----------------------------------------------------------------------------------------------------------------


connectionLine::connectionLine(QGraphicsItem* parent) : QGraphicsItem(parent) {
    setFlags(ItemIsMovable | ItemIsSelectable);
}

QRectF connectionLine::boundingRect() const {
    return QRectF(-2.5, -2.5, 5, 5);
}

void connectionLine::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPen pen(Qt::black);
    QBrush brush(Qt::black);
    QRectF rect(-2.5, -2.5, 5, 5);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPie(rect, -90*16, 180*16);
}

QPainterPath connectionLine::shape() const {
    QPainterPath path;
    QRectF rect(-2.5, -2.5, 5.5, 5.5);
    path.moveTo(0, 2.5);
    path.arcTo(rect, -90, 180);
    path.closeSubpath();
    return path;
}

void connectionLine::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "Button pressed: " << event->button();
    if(event->button() == Qt::LeftButton) {

    }
    QGraphicsItem::mousePressEvent(event);
}

void connectionLine::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void connectionLine::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}




