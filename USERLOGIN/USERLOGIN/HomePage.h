#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HomePage.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QInputDialog>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QTimer>
#include <QThread>
#include <QPropertyAnimation>
#include <QGraphicsColorizeEffect>
#include <QGraphicsDropShadowEffect>
#include "Graph.h"
#include "EdgeView.h"
#include"GraphTraversal.h"

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    HomePage(QString username, QWidget* parent = nullptr);
    ~HomePage();

private slots:
    void showHomePage();
    void showAddGraphPage();
    void showTraversePage();
    void showShortestPathPage();
    void goBack();
    void logout();

    // Graph operations
    void onAddCity();
    void onAddEdge();
    void onDeleteCity();
    void onDeleteEdge();
    void onUndo();
    void onCanvasClicked(QPointF pos);
    void onRunDFS(); 
    void onRunBFS();

  



private:
    Ui::HomePageClass ui;
    QGraphicsScene* scene;
    QGraphicsScene* traverseScene;
    QGraphicsScene* shortestPathScene;
    QList<EdgeView*>traverseEdges;
    QList<EdgeView*>shortestPathEdges;
    QList<EdgeView*> edges;
    QMap<QString, QPointF> cityPositions;
    QTextEdit* adjacencyListDisplay;
    QLabel* adjacencyListLabel;
    QTextEdit* traversalOutputDisplay;
    QLabel* traversalOutputLabel;
    Graph graph;
    GraphTraversal* traversal;


    // State flags
    bool addCityOn = false;
    bool addEdgeOn = false;
    bool deleteCityOn = false;
    bool deleteEdgeOn = false;
    bool isUndo = false;

    // For edge drawing
    QGraphicsItemGroup* firstNode = nullptr;



    // Setup methods
    void setupUI();

    void setUpConnections();
    void setUpGraphScene();


    void setupTraverseGraphScene();
    void setupShortestPathGraphScene();
    void updateTraverseGraphScene();
    void updateShortestPathGraphScene();
    void layoutNodesCircular(QGraphicsScene* targetScene,
        const unordered_map<string,list<Edge>>& adjacencyList,
        QMap<QString, QGraphicsItemGroup*>& cityNodesMap,
        QMap<QString, QPointF>& cityPositions);
  
  

    // Helper methods
    void handleAddCity(QPointF pos);
    void handleAddEdge(QPointF pos);
    void handleDeleteCity(QPointF pos);
    void handleDeleteEdge(QPointF pos);
    void updateGraphScene();
    void updateAdjacencyListDisplay();
    void resetAddButton(QPushButton* btn, bool& flag);
    void resetDeleteButton(QPushButton* btn, bool& flag);
    void resetButtonStyle();
    void highlightNode(QGraphicsItemGroup* nodes, bool highlight);
    void highlightDeletedNode(QGraphicsItemGroup* nodes, bool highlight);
    void highlightEdge(EdgeView* edge, bool highlight);
    void highlightTraversalNode(const QString& cityName, QGraphicsScene* scene, QColor color);
    void resetTraversalNodeColors(QGraphicsScene* scene);
    void showAlert(const QString& title, const QString& message, QMessageBox::Icon icon);
};
