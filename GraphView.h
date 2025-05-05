#pragma once

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QPointF>

class GraphView  : public QGraphicsView
{
	Q_OBJECT

public:
	GraphView(QWidget *parent=nullptr);
	~GraphView();

signals:
	void canvasClicked(QPointF pos);

protected:
	void mousePressEvent(QMouseEvent* event) override;
	
};
