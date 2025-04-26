#pragma once

#include <QMainWindow>
#include "ui_HomePage.h"
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QPushButton>
#include <QTimer>
#include "graph.h"
#include "GraphView.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QInputDialog>
#include "EdgeView.h"
#include <QMessageBox>


class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QString username = "", QWidget* parent = nullptr);
    ~HomePage();

private slots:
    void showHomePage();
    void showAddGraphPage();
    void showTraversePage();
    void showShortestPathPage();
    void goBack();
    void logout();
    void onAddCity();
    void onAddEdge();
    void onDeleteCity();
    void onDeleteEdge();


    //for visualization
    void onCanvasClicked(QPointF pos);

private:
    void setupUI();  
    void setUpConnections();
    void setUpGraphScene();
   
    void handleAddCity(QPointF);
    void handleAddEdge(QPointF);
    void handleDeleteCity(QPointF);
    void handleDeleteEdge(QPointF);
    void resetButtonStyle();
    void resetAddButton(QPushButton* btn, bool& flag);
    void resetDeleteButton(QPushButton* btn, bool& flag);
    void highlightNode(QGraphicsItemGroup* nodes, bool highlight);
    void highlightDeletedNode(QGraphicsItemGroup* nodes, bool highlight);
    void highlightEdge(EdgeView* edge, bool highlight);



    void showAlert(const QString& title, const QString& message, QMessageBox::Icon icon);






    Ui::HomePageClass ui;
    /*Visualizing Graph on Add graph btn*/
    QGraphicsScene* scene;
    Graph graph;
    bool addCityOn = false;
    bool addEdgeOn = false;
    bool deleteCityOn = false;
    bool deleteEdgeOn = false;
    QGraphicsItemGroup* firstNode = nullptr;
    QList<EdgeView*>edges;


};

