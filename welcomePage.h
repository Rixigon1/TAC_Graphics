#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include <QLabel>

class welcomePage : public QWidget {
    Q_OBJECT
    private:
        QLabel* project_lbl;

    public:
        welcomePage(QWidget *parent = nullptr);

    signals:
};

#endif // WELCOMEPAGE_H
