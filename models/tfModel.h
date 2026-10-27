#ifndef TFMODEL_H
#define TFMODEL_H

#include <QAbstractItemModel>
#include <QPointF>

struct block {
    int ID;
    QString function;
    QPointF position;

    QVector<int> inPorts;
    QVector<int> outPorts;
    QHash<int, int> inConnectionsIDs; // portID, conID
    QMultiHash<int, int> outConnectionsIDs; // portID, conID
};

struct connection {
    int ID;
    int sourceBlockID;
    int targetBlockID;

    int sourcePortID;
    int targetPortID;
};

// Заготовка под Undo/Redo
enum actionType {DELELE, ADD, MOVE, EDIT};
enum fieldType {};

struct action {

};

class tfModel : public QObject {
    private:
        bool isSaved = false;
        static int IDBlockCounter;
        static int IDConnectionCounter;
        QHash<int, block> blocks;
        QHash<int, connection> connections;


    public:
        tfModel(QObject* parent = nullptr);

        int addBlock(QString function, int inPortCountm, int outPortCount, QPointF pos);
        void deleteBlock(int ID);

        int addConnection(int sourceBlockID, int targetBlockID, int sourcePortID, int targetPortID);
        void deleteConnection(int ID);

        void clear();


        // Помнить про синхронизацию счетчиков ID
        void saveToJSON();
        // Загрузчик будет проверять корректность файла
        // Если блока с ID из соединения не существует
        // То соединение не будет создано и должно быть выдано предупреждение о нарушении целостности файла и структурной схемы
        void loadFromJSON();

    signals:
        void blockAdded(int ID);
        void blockDeleted(int ID);
        void connectionAdded(int ID, int sourceBlockID, int targetBlockID, int sourcePortID, int targetPortID);
        void connectionDeleted(int ID);

        // Сигналы ошибок
        void portIDRangeError(int value, bool isInPort);
        void portIDCountError(int value, bool isInPort);
        void noSuchPort(int blockID, int portID);
        void tooManyConnectionsForInPort(int blockID, int targetPortID);
        void selfBlockConnection(int blockID);
};

#endif // TFMODEL_H
