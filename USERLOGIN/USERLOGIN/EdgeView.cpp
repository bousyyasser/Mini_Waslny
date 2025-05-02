#include "EdgeView.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include <QLineF>
#include <QFont>
#include <QtMath>

EdgeView::EdgeView(QGraphicsItem* startNode, QGraphicsItem* endNode, QGraphicsScene* scene, int distance, QGraphicsLineItem* parent)
    : QObject(nullptr), QGraphicsLineItem(parent),
    startNode(startNode),
    endNode(endNode),
    distanceLabel(nullptr),
    scene(scene),
    distance(distance)
{
    setPen(QPen(Qt::black, 2));
    scene->addItem(this);

    distanceLabel = scene->addText(QString::number(distance));
    distanceLabel->setDefaultTextColor(Qt::black);
    distanceLabel->setFont(QFont("Arial", 10, QFont::Bold));
    updatePosition();

    connect(scene, &QGraphicsScene::changed, this, &EdgeView::updatePosition);
}

void EdgeView::setDistance(int newDistance)
{
    distance = newDistance;
    if (distanceLabel) {
        distanceLabel->setPlainText(QString::number(distance));
    }
}

void EdgeView::updatePosition()
{
    if (!startNode || !endNode)
        return;

    QPointF p1 = startNode->boundingRect().center() + startNode->pos();
    QPointF p2 = endNode->boundingRect().center() + endNode->pos();

    
    QPointF direction = p2 - p1;
    qreal length = qSqrt(direction.x() * direction.x() + direction.y() * direction.y());

 
    if (length < 1)
        return;

    
    QPointF normalized = direction / length;

    
    qreal radius = 20;

   
    QPointF startPoint = p1 + normalized * radius;
    QPointF endPoint = p2 - normalized * radius;

    
    setLine(QLineF(startPoint, endPoint));

    
    if (distanceLabel) {
        QPointF midPoint = (startPoint + endPoint) / 2;
   
        distanceLabel->setPos(midPoint);
    }
}


bool EdgeView::connectsToCity(QGraphicsItem* city)
{
    return(startNode == city || endNode == city);
}
int EdgeView::getDistance() const
{
    return distance;
}

QString EdgeView::getSource() const
{
    return startNode->data(0).toString();
}
QString EdgeView::getDestination() const
{
    return endNode->data(0).toString();
}
EdgeView::~EdgeView()
{
    if (distanceLabel && scene)
    {
        scene->removeItem(distanceLabel);
    }
}