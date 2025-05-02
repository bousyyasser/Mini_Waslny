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
#include "Graph.h"
#include "EdgeView.h"

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

private:
    Ui::HomePageClass ui;
    QGraphicsScene* scene;
    Graph graph;
    QList<EdgeView*> edges;
    QMap<QString, QPointF> cityPositions;
    QTextEdit* adjacencyListDisplay;
    QLabel* adjacencyListLabel;


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
    void setupGraphTypeOption();
    void setUpConnections();
    void setUpGraphScene();

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
    void showAlert(const QString& title, const QString& message, QMessageBox::Icon icon);
};
