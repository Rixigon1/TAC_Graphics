#ifndef CANVASVIEW_H
#define CANVASVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>

#include <cmath>

enum gridType {POINT, LINE, HALF_LINE, POINT_HALF_LINE}; // Реализовать разную сетку

class canvasView : public QGraphicsView {
    Q_OBJECT
    private:
        bool isPanning = false;
        bool isGridOn = false;
        // Сделать чтение параметра из QSettings
        qreal step = 20;
        qreal zoom = 1.1;

        QPointF lastMusePos;


    public:
        canvasView(QGraphicsScene* scene, QWidget* parent = nullptr);


        QPointF bindGrid();

        void setGridStep(qreal newStep);
        qreal gridStep();
        void setZoom(qreal newZoom);
        qreal Zoom();
        void gridOn();
        void gridOff();


    protected:
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void wheelEvent(QWheelEvent* event);
        void drawBackground(QPainter* painter, const QRectF &rect);

    // signals:
        // void viewportPosUpdated();


    // public slots:
    //     void slotViewportPosUpdated();
};

#endif // CANVASVIEW_H
