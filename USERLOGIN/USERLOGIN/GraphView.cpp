#include "GraphView.h"

GraphView::GraphView(QWidget *parent)
	: QGraphicsView(parent)
{}

void GraphView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		QPointF scenePos = mapToScene(event->pos());
		emit canvasClicked(scenePos);
	}
	QGraphicsView::mousePressEvent(event);
}

GraphView::~GraphView()
{}
