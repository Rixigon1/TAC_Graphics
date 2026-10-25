#include "canvasView.h"

canvasView::canvasView(QGraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent) {
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::NoAnchor);
    setMouseTracking(true);
    viewport()->setMouseTracking(true);


}



void canvasView::setGridStep(qreal newStep) {
    step = newStep;
}

qreal canvasView::gridStep() {
    return step;
}

//переписать в drawBackground
void canvasView::gridOn() {
    isGridOn = true;
    viewport()->update();
}

void canvasView::gridOff() {
    isGridOn = false;
    viewport()->update();
}

void canvasView::mousePressEvent(QMouseEvent* event) {

    // Сделать перемещение на среднюю кнопку мыши
    if(event->button() == Qt::MiddleButton) {
        isPanning = true;
        lastMousePos = event->pos();

        setCursor(Qt::ClosedHandCursor);

        event->accept();
        return;
    }

    QGraphicsView::mousePressEvent(event);
}

void canvasView::mouseMoveEvent(QMouseEvent* event) {
    if(isPanning) {
        QPointF delta = event->pos() - lastMousePos;
        lastMousePos = event->pos();

        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());

        event->accept();
        return;
    }

    QGraphicsView::mouseMoveEvent(event);
}

void canvasView::mouseReleaseEvent(QMouseEvent* event) {
    if(event->button() == Qt::MiddleButton) {
        isPanning = false;

        unsetCursor();
        event->accept();
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void canvasView::wheelEvent(QWheelEvent* event) {

    if(event->angleDelta().y() > 0) {
        scale(zoom, zoom);
    } else if(event->angleDelta().y() < 0) {
        scale(1 / zoom, 1 / zoom);
    }

    event->accept();
}

void canvasView::drawBackground(QPainter* painter, const QRectF &rect) {
    QGraphicsView::drawBackground(painter, rect);
    if(!isGridOn) {
        return;
    }

    QPen pen(Qt::NoPen);
    QBrush brush(Qt::black);
    pen.setCosmetic(true);

    const qreal x0Fix = std::floor(rect.left() / step) * step;
    const qreal y0Fix = std::floor(rect.top() / step) * step;

    for(qreal xCur = x0Fix; xCur <= rect.right(); xCur += step) {
        for(qreal yCur = y0Fix; yCur <= rect.bottom(); yCur += step) {
            painter->drawPoint(QPointF(xCur, yCur));
        }
    }
    return;
}

