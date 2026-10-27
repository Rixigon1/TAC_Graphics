#include "tfModel.h"

tfModel::tfModel(QObject* parent) : QObject(parent) {
    IDBlockCounter = 0;
    IDConnectionCounter = 0;
}

int tfModel::addBlock(QString function, int inPortCount, int outPortCount, QPointF pos) {
    if(inPortCount < 1) {
        emit portIDCountError(inPortCount, true);
        return -1;
    }
    if(outPortCount < 1) {
        emit portIDCountError(outPortCount, false);
        return -1;
    }

    block newBlock;
    newBlock.ID = ++IDBlockCounter;
    newBlock.function = function;

    for(int i = 1; i <= inPortCount; i++) {
        newBlock.inPorts.append(i);
    }
    for(int i = inPortCount+1; i <= inPortCount + outPortCount; i++) {
        newBlock.outPorts.append(i);
    }

    newBlock.position = pos;

    blocks.insert(newBlock.ID, newBlock);
    emit blockAdded(newBlock.ID);

    return newBlock.ID;
}

void tfModel::deleteBlock(int ID) {
    auto inConnectionsIDs = blocks[ID].inConnectionsIDs;
    for(auto iter : inConnectionsIDs) {
        deleteConnection(iter);
    }

    auto outConnectionsIDs = blocks[ID].outConnectionsIDs;
    for(auto iter : outConnectionsIDs) {
        deleteConnection(iter);
    }

    blocks.remove(ID);
    emit blockDeleted(ID);
}

int tfModel::addConnection(int sourceBlockID, int targetBlockID, int sourcePortID, int targetPortID) {
    if(sourcePortID < 1) {
        emit portIDRangeError(sourcePortID, false);
        return -1;
    }
    if(targetPortID < 1) {
        emit portIDRangeError(targetPortID, true);
        return -1;
    }
    if(!blocks[sourceBlockID].outPorts.contains(sourcePortID)) {
        emit noSuchPort(sourceBlockID, sourcePortID);
        return -1;
    }
    if(!blocks[targetBlockID].inPorts.contains(targetPortID)) {
        emit noSuchPort(targetBlockID, targetPortID);
        return -1;
    }
    if(sourceBlockID == targetBlockID) {
        emit selfBlockConnection(sourceBlockID);
        return -1;
    }
    if(blocks[targetBlockID].inConnectionsIDs.contains(targetPortID)) {
        emit tooManyConnectionsForInPort(targetBlockID, targetPortID);
        return -1;
    }

    connection newConnection;
    newConnection.ID = ++IDConnectionCounter;
    newConnection.sourceBlockID = sourceBlockID;
    newConnection.targetBlockID = targetBlockID;
    newConnection.sourcePortID = sourcePortID;
    newConnection.targetPortID = targetPortID;

    blocks[targetBlockID].inConnectionsIDs.insert(targetPortID, newConnection.ID);
    blocks[sourceBlockID].outConnectionsIDs.insert(sourcePortID, newConnection.ID);

    connections.insert(newConnection.ID, newConnection);

    emit connectionAdded(newConnection.ID, sourceBlockID, targetBlockID, sourcePortID, targetPortID);
    return newConnection.ID;
}

void tfModel::deleteConnection(int ID) {
    auto connection = connections[ID];
    block& sourceBlock = blocks[connection.sourceBlockID];
    block& targetBlock = blocks[connection.targetBlockID];
    sourceBlock.outConnectionsIDs.remove(connection.sourcePortID, ID);
    targetBlock.inConnectionsIDs.remove(connection.targetPortID);

    connections.remove(ID);
    emit connectionDeleted(ID);
}

