#pragma once

#include <QGraphicsLineItem>
#include <QObject>

class QGraphicsTextItem;
class QGraphicsScene;

class EdgeView : public QObject, public QGraphicsLineItem {
    Q_OBJECT 

public:
    EdgeView(QGraphicsItem* startNode, QGraphicsItem* endNode, QGraphicsScene* scene, int distance, QGraphicsLineItem* parent = nullptr);
    ~EdgeView();

    void setDistance(int distance);
    int getDistance() const;
    QString getSource() const;
    QString getDestination() const;
    bool connectsToCity(QGraphicsItem* city);
    

public slots:
    void updatePosition(); 

private:
    QGraphicsItem* startNode;
    QGraphicsItem* endNode;
    QGraphicsTextItem* distanceLabel;
    QGraphicsScene* scene;
    int distance;
};

