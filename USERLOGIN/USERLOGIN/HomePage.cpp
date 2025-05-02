#include "HomePage.h"
#include "USERLOGIN.h"
#include "GraphView.h"
#include "Graph.h"
#include "EdgeView.h"

HomePage::HomePage(QString username, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setupUI();


    ui.welcomeLabel->setText("Welcome, " + username + "!");
    ui.welcomeLabel->setAlignment(Qt::AlignCenter);
    ui.welcomeLabel->setStyleSheet(
        "font-size: 40px;" 
        "color: black; "
        "font-weight: bold; "
        "font-family: 'Lucida Calligraphy', cursive;"
        "qproperty-alignment: AlignCenter;");

    
    ui.desLabel->setStyleSheet(
        "font-family: 'Times New Roman';"
        "font-size: 14px;"
        "font-weight: normal;"
        "color:#B0B0B0;"
    );
    ui.desLabel->setText(
        "Welcome to Mini-Waslny!\n\n"
        "Your goal is to reach your destination in the shortest path possible.\n"
        "This system allows you to:\n"
        "- Add cities and the distances between them.\n"
        "- Display and update your graph.\n" 
        "- Traverse graph using BFS or DFS.\n"
        "- Find the shortest route between two cities using Dijkstra's algorithm.\n"
        "Enjoy exploring the smart way to travel!"
    );

    ui.frame->setStyleSheet(
        "background-color: #ffffff; "
        "border-radius: 15px; "
        "padding: 20px;"
    );
}



void HomePage::setupUI()
{
    // Set left panel style
    ui.leftPanel->setStyleSheet("background-color: #2e2e2e;");

    // Setup button styles
    QString buttonStyle = R"(
        QPushButton {
            background-color: #2e2e2e;
            color: white;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: none;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        QPushButton:hover {
            background-color: #505050;
            color: white;
        }
        QPushButton:pressed {
            background-color: #606060;
        }
    )";

    ui.homeButton->setStyleSheet(buttonStyle);
    ui.addGraphButton->setStyleSheet(buttonStyle);
    ui.traverseButton->setStyleSheet(buttonStyle);
    ui.shortestPathButton->setStyleSheet(buttonStyle);

    // Style back button
    ui.back->setStyleSheet(R"(
        QPushButton {
            background-color: transparent;
            border: none;
        }
        QPushButton:hover {
            background-color: rgba(0, 0, 0, 0.05);
        }
        QPushButton:pressed {
            background-color: rgba(0, 0, 0, 0.1);
        }
    )");

    // Style logout button
    ui.logoutButton->setStyleSheet(R"(
        QPushButton {
            background-color: #4d4d4d;
            color: white;
            font-weight: bold;
            font-size: 12px;
            border: none;
            padding: 4px 8px;
            border-radius: 10px;
            min-width: 0px;
            min-height: 20px;
        }
        QPushButton:hover {
            background-color: #6e6e6e;
        }
        QPushButton:pressed {
            background-color: #3a3a3a;
        }
    )");

    // Add/Edit Graph button styles
    QString addDeleteButtonStyle = R"(
        QPushButton {
            background-color: white;
            color: black;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: 2px solid #d1d1d1;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        QPushButton:hover {
            background-color: #f0f0f0;
            color: black;
        }
        QPushButton:pressed {
            background-color: #e0e0e0;
        }
    )";

    ui.addCityBtn->setStyleSheet(addDeleteButtonStyle);
    ui.addEdgeBtn->setStyleSheet(addDeleteButtonStyle);

    // Style undo button
    ui.undoButton->setStyleSheet(R"(
        QPushButton {
            background-color: white;
            color: black;
            font-family: 'Segoe UI', 'Arial', 'Helvetica', 'sans-serif'; 
            font-weight: bold;
            font-size: 12px;
            border: 2px solid #d1d1d1;
            padding: 4px 8px;
            border-radius: 10px;
            min-width: 0px;
            min-height: 20px;
        }
        QPushButton:hover {
            background-color: #f0f0f0;
            color: black;
        }
        QPushButton:pressed {
            background-color: #e0e0e0;
        }
    )");

    // Delete button styles
    QString deleteButtonStyle = R"(
        QPushButton {
            background-color: #ff4d4d;
            color: white;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: none;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        QPushButton:hover {
            background-color: #ff3333;
            color: white;
        }
        QPushButton:pressed {
            background-color: #e60000;
        }
    )";

    ui.deleteCityBtn->setStyleSheet(deleteButtonStyle);
    ui.deleteEdgeBtn->setStyleSheet(deleteButtonStyle);

    //adjacency list 
    adjacencyListLabel = new QLabel("Graph Adjacency List");
    adjacencyListLabel->setStyleSheet(R"(
        font-family: 'Segoe UI', 'Arial';
        font-size: 16px;
        font-weight: bold;
        color: #333333;
    )");

    adjacencyListDisplay = new QTextEdit();
    adjacencyListDisplay->setReadOnly(true);
    adjacencyListDisplay->setStyleSheet(R"(
        background-color: white;
        border: 2px solid #d1d1d1;
        border-radius: 10px;
        padding: 10px;
        font-family: 'Consolas', 'Courier New', monospace;
        font-size: 12px;
        color: #333333;
    )");
    adjacencyListDisplay->setMinimumHeight(200);  
    adjacencyListDisplay->setMinimumWidth(250);

    QVBoxLayout* graphViewLayout = new QVBoxLayout();
    graphViewLayout->addWidget(ui.graphView);

  
    QVBoxLayout* rightSideLayout = new QVBoxLayout();
    rightSideLayout->addWidget(adjacencyListLabel);
    rightSideLayout->addWidget(adjacencyListDisplay);

    
    QGridLayout* buttonGridLayout = new QGridLayout();
    buttonGridLayout->addWidget(ui.addCityBtn, 0, 0);
    buttonGridLayout->addWidget(ui.deleteCityBtn, 0, 1);
    buttonGridLayout->addWidget(ui.addEdgeBtn, 1, 0);
    buttonGridLayout->addWidget(ui.deleteEdgeBtn, 1, 1);
    buttonGridLayout->addWidget(ui.undoButton, 2, 0, 1, 2, Qt::AlignCenter);

   
    rightSideLayout->addLayout(buttonGridLayout);
    rightSideLayout->addStretch();

   
    QHBoxLayout* graphPageLayout = new QHBoxLayout(ui.addGraphWidget);

    graphPageLayout->addLayout(graphViewLayout, 1); 
    graphPageLayout->addLayout(rightSideLayout);

   
    graphPageLayout->setContentsMargins(10, 10, 10, 10);
    graphPageLayout->setSpacing(15);

    
    ui.addGraphWidget->setLayout(graphPageLayout);

    //back button on top
    ui.back->raise();

   //initiate btns&graph scene
    setUpConnections();
    setUpGraphScene();
}
void HomePage::setUpConnections()
{
    connect(ui.homeButton, &QPushButton::clicked, this, &HomePage::showHomePage);
    connect(ui.addGraphButton, &QPushButton::clicked, this, &HomePage::showAddGraphPage);
    connect(ui.traverseButton, &QPushButton::clicked, this, &HomePage::showTraversePage);
    connect(ui.shortestPathButton, &QPushButton::clicked, this, &HomePage::showShortestPathPage);
    connect(ui.back, &QPushButton::clicked, this, &HomePage::goBack);
    connect(ui.logoutButton, &QPushButton::clicked, this, &HomePage::logout);
  
    connect(ui.addCityBtn, &QPushButton::clicked, this, &HomePage::onAddCity);
    connect(ui.addEdgeBtn, &QPushButton::clicked, this, &HomePage::onAddEdge);
    connect(ui.deleteCityBtn, &QPushButton::clicked, this, &HomePage::onDeleteCity);
    connect(ui.deleteEdgeBtn, &QPushButton::clicked, this, &HomePage::onDeleteEdge);
    connect(ui.undoButton, &QPushButton::clicked, this, &HomePage::onUndo);
}

/*visualization on add graph*/
void HomePage::setUpGraphScene()
{
    scene = new QGraphicsScene(this);
    ui.graphView->setScene(scene);
    connect(ui.graphView, &GraphView::canvasClicked, this, &HomePage::onCanvasClicked);
}


void HomePage::showHomePage()
{
    ui.leftPanel->setVisible(true);
    ui.rightPanel->setCurrentIndex(0);
}

void HomePage::showAddGraphPage()
{
    ui.leftPanel->setVisible(false);
    ui.rightPanel->setGeometry(0, 0, this->width(), this->height());
    ui.rightPanel->setCurrentIndex(1);
}

void HomePage::showTraversePage()
{
    ui.rightPanel->setCurrentIndex(2);
}

void HomePage::showShortestPathPage()
{
    ui.rightPanel->setCurrentIndex(3);
}


/*return home*/
void HomePage::goBack()
{
    ui.leftPanel->setVisible(true);
    ui.rightPanel->setGeometry(ui.leftPanel->width(), 0, this->width() - ui.leftPanel->width(), this->height());
    ui.rightPanel->setCurrentIndex(0);
}


/*Add graph methods handling*/
void HomePage::onAddCity()
{
    if (addEdgeOn) {
        addEdgeOn = false;
        firstNode = nullptr;
        resetAddButton(ui.addEdgeBtn, addEdgeOn);
    }
    if (deleteCityOn)
    {
        deleteCityOn = false;
        resetDeleteButton(ui.deleteCityBtn, deleteCityOn);
    }
    if (deleteEdgeOn)
    {
        deleteEdgeOn = false;
        resetDeleteButton(ui.deleteEdgeBtn, deleteEdgeOn);
    }

   
    addCityOn = true;
    ui.graphView->setCursor(Qt::CrossCursor);

    ui.addCityBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #f0f0f0;
            color: black;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: 2px solid #d1d1d1;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
    )");
}
void HomePage::onAddEdge()
{
    
    if (addCityOn) {
        addCityOn = false;
        resetAddButton(ui.addCityBtn, addCityOn);
    }
    if (deleteCityOn)
    {
        deleteCityOn = false;
        resetDeleteButton(ui.deleteCityBtn, deleteCityOn);
    }
    if (deleteEdgeOn)
    {
        deleteEdgeOn = false;
        resetDeleteButton(ui.deleteEdgeBtn, deleteEdgeOn);
    }
    addEdgeOn = true;
    firstNode = nullptr;
    ui.graphView->setCursor(Qt::CrossCursor);

    ui.addEdgeBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #f0f0f0;
            color: black;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: 2px solid #d1d1d1;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
    )");
}
void HomePage::onDeleteCity()
{
    if (addCityOn)
    {
       addCityOn = false;
       resetAddButton(ui.addCityBtn, addCityOn);
    }

    if (addEdgeOn)
    {
        addEdgeOn = false;
        resetAddButton(ui.addEdgeBtn, addEdgeOn);
    }
    if (deleteEdgeOn)
    {
        deleteEdgeOn = false;
        resetDeleteButton(ui.deleteEdgeBtn, deleteEdgeOn);
    }
  
    deleteCityOn = true;
    ui.graphView->setCursor(Qt::PointingHandCursor);



    ui.deleteCityBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #e60000;
            color: white;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: none;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
      
    )");
 
}
void HomePage::onDeleteEdge()
{
    if (addCityOn)
    {
        addCityOn = false;
        resetAddButton(ui.addCityBtn, addCityOn);
    }
    if (addEdgeOn)
    {
        addEdgeOn = false;
        resetAddButton(ui.addEdgeBtn, addEdgeOn);
    }
    if (deleteCityOn)
    {
        deleteCityOn = false;
        resetDeleteButton(ui.deleteCityBtn, deleteCityOn);
    }

    deleteEdgeOn = true;
    ui.graphView->setCursor(Qt::PointingHandCursor);

    ui.deleteEdgeBtn->setStyleSheet(R"(
    QPushButton {
            background-color: #e60000;
            color: white;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: none;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
      
    )");

}
void HomePage::onUndo()
{
    if (graph.isUndoEmpty())
    {
        showAlert("Undo", "There exists no graph to undo.", QMessageBox::Critical);
        return;
    }


    graph.undo();
    updateAdjacencyListDisplay();
    updateGraphScene();
}

void HomePage::updateGraphScene()
{
    const auto& adjacencyList = graph.getAdjacencyList();

   
    QSet<QString> currentCities;
    QMap<QString, QGraphicsItemGroup*> cityNodesMap;

    for (QGraphicsItem* item : scene->items())
    {
        QGraphicsItemGroup* group = qgraphicsitem_cast<QGraphicsItemGroup*>(item);
        if (group)
        {
            QString name = group->data(0).toString();
            cityNodesMap[name] = group;
            currentCities.insert(name);
        }
    }

    
    QSet<QString> shouldExistCities;
    for (const auto& cityPair : adjacencyList)
    {
        const string& cityName = cityPair.first;
        QString qcityName = QString::fromStdString(cityName);
        shouldExistCities.insert(qcityName);
    }

   
    QSet<QString> citiesToRemove = currentCities - shouldExistCities;
    for (const QString& cityToRemove : citiesToRemove)
    {
        QGraphicsItemGroup* group = cityNodesMap[cityToRemove];
        if (group)
        {
            cityPositions[cityToRemove] = group->pos();
            scene->removeItem(group);
            delete group;
            cityNodesMap.remove(cityToRemove);
        }
    }

   
    QSet<QString> citiesToAdd = shouldExistCities - currentCities;
    for (const QString& cityToAdd : citiesToAdd)
    {
      
        qreal x = 100 + (rand() % 400);
        qreal y = 100 + (rand() % 300);

        
        if (cityPositions.contains(cityToAdd))
        {
            x = cityPositions[cityToAdd].x();
            y = cityPositions[cityToAdd].y();
        }
        else
        { 
           
            cityPositions[cityToAdd] = QPointF(x, y);
        }

        QGraphicsEllipseItem* node = scene->addEllipse(0, 0, 40, 40, QPen(Qt::black), QBrush(Qt::lightGray));

        QGraphicsTextItem* label = scene->addText(cityToAdd);
        QFont font = label->font();
        font.setBold(true);
        label->setFont(font);
        QRectF textRect = label->boundingRect();
        label->setPos(20 - textRect.width() / 2, 20 - textRect.height() / 2);

        QGraphicsItemGroup* group = scene->createItemGroup({ node, label });
        group->setFlag(QGraphicsItem::ItemIsMovable);
        group->setFlag(QGraphicsItem::ItemIsSelectable);
        group->setData(0, cityToAdd);
        group->setPos(x, y);

       
        cityNodesMap[cityToAdd] = group;
    }

   
    for (EdgeView* edge : edges)
    {
        scene->removeItem(edge);
        delete edge;
    }
    edges.clear();

    
    for (const auto& cityPair : adjacencyList)
    {
        const string& source = cityPair.first;
        QString qsource = QString::fromStdString(source);

        for (const Edge& edge : cityPair.second)
        {
            const string& dest = edge.destination;
            QString qdest = QString::fromStdString(dest);

           
            if (qsource < qdest)
            {
                QGraphicsItemGroup* sourceNode = cityNodesMap.value(qsource, nullptr);
                QGraphicsItemGroup* destNode = cityNodesMap.value(qdest, nullptr);

                if (sourceNode && destNode)
                {
                    EdgeView* edgeView = new EdgeView(sourceNode, destNode, scene, edge.distance);
                    edges.append(edgeView);
                }
            }
        }
    }

    updateAdjacencyListDisplay();
}

/*visualization add graph logic*/
void HomePage::onCanvasClicked(QPointF pos)
{
    if (addCityOn)
    {
        handleAddCity(pos);
        resetAddButton(ui.addCityBtn, addCityOn);
    }
    else if (addEdgeOn)
    {
        handleAddEdge(pos);
    }
    else if (deleteCityOn)
    {
        handleDeleteCity(pos);
    }

    else if (deleteEdgeOn)
    {
        handleDeleteEdge(pos);
    }
}
void HomePage::handleAddEdge(QPointF pos)
{
    QGraphicsItem* clickedItem = scene->itemAt(pos, QTransform());
    if (clickedItem == nullptr)
    {
        if (firstNode)
        {
            highlightNode(firstNode, false);
            firstNode = nullptr;
        }
        resetAddButton(ui.addEdgeBtn, addEdgeOn);
        return;
    }
  
   QGraphicsItemGroup* group = qgraphicsitem_cast<QGraphicsItemGroup*>(clickedItem->group());

    if (!group)
        return;

    if (!firstNode)
    {
        firstNode = group;
        highlightNode(firstNode, true);
    }
    else
    {
        QGraphicsItemGroup* secondNode = group;

        highlightNode(secondNode, true);
        QString sourceCity = firstNode->data(0).toString();
        QString destinationCity = secondNode->data(0).toString();


        if ((firstNode == secondNode))
        {
            showAlert("Invalid", "Cannot add an edge between the same city!", QMessageBox::Warning);
            resetAddButton(ui.addEdgeBtn, addEdgeOn);
            highlightNode(firstNode, false);
            firstNode = nullptr;
            return;
        }

        if (graph.EdgeExists(sourceCity.toStdString(), destinationCity.toStdString()))
        {
            showAlert("Duplicate Edges", "There's an Edge exists between two cities.", QMessageBox::Warning);
            resetAddButton(ui.addEdgeBtn, addEdgeOn);
            highlightNode(firstNode, false);
            highlightNode(secondNode, false);
            firstNode = nullptr;
            return;
        }

        bool check;
        QString distanceTxt = QInputDialog::getText(this, "Distance", "Enter Distance between both cities", QLineEdit::Normal, "", &check);
        if (!check)
        {
            resetAddButton(ui.addEdgeBtn, addEdgeOn);
            highlightNode(firstNode, false);
            highlightNode(secondNode, false);
            firstNode = nullptr;
            return;
        }

        int distance = distanceTxt.toInt();
        if (distance <= 0)
        {
            showAlert("Invalid Distance", "Please Enter valid distance between cities.", QMessageBox::Warning);
            resetAddButton(ui.addEdgeBtn, addEdgeOn);
            highlightNode(firstNode, false);
            highlightNode(secondNode, false);
            firstNode = nullptr;
            return;
        }

        EdgeView* edge = new EdgeView(firstNode, secondNode, scene, distance);
        edges.append(edge);

        if (!sourceCity.isEmpty() && !destinationCity.isEmpty())
        {
            graph.addEdge(sourceCity.toStdString(), destinationCity.toStdString(), distance);
            updateAdjacencyListDisplay();
        }

        highlightNode(firstNode, false);
        highlightNode(secondNode, false);
        firstNode = nullptr;
        addEdgeOn = false;
        ui.graphView->setCursor(Qt::ArrowCursor);
        resetAddButton(ui.addEdgeBtn, addEdgeOn);
    }
}
void HomePage::handleAddCity(QPointF pos)
{
    bool check;
    QString cityName = QInputDialog::getText(this, "City Name", "Enter City Name: ", QLineEdit::Normal, "", &check);

    if (!check || cityName.isEmpty())
    {
        resetAddButton(ui.addCityBtn, addCityOn);
        return;
    }

    if (graph.cityExists(cityName.toStdString()))
    {
        showAlert("Duplicate City", "This City Already Exists!", QMessageBox::Warning);
        resetAddButton(ui.addCityBtn, addCityOn);
        return;
    }

    QGraphicsEllipseItem* node = scene->addEllipse(pos.x(), pos.y(), 40, 40, QPen(Qt::black), QBrush(Qt::lightGray));
    QGraphicsTextItem* label = scene->addText(cityName);
    QFont font = label->font();
    font.setBold(true);
    label->setFont(font);
    QRectF textRect = label->boundingRect();
    qreal textX = pos.x() + 20 - textRect.width() / 2;
    qreal textY = pos.y() + 20 - textRect.height() / 2;
    label->setPos(textX, textY);

    //to move node with its label
    QGraphicsItemGroup* group = scene->createItemGroup({ node, label });
    group->setFlag(QGraphicsItem::ItemIsMovable);
    group->setFlag(QGraphicsItem::ItemIsSelectable);

    group->setData(0, cityName);

    graph.addCity(cityName.toStdString());
    updateAdjacencyListDisplay();
    addCityOn = false;
    ui.graphView->setCursor(Qt::ArrowCursor);
}
void HomePage::handleDeleteCity(QPointF pos)
{
    QGraphicsItem* clickedItem = scene->itemAt(pos, QTransform());

    if (!clickedItem)
    {
        resetDeleteButton(ui.deleteCityBtn, deleteCityOn);
        return;
    }

    QGraphicsItemGroup* group = qgraphicsitem_cast<QGraphicsItemGroup*>(clickedItem->group());
    if (!group)
    {
        return;
    }
    QString cityName = group->data(0).toString();
    highlightDeletedNode(group, true);

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Delete City", "Are you sure you want to delete: " + cityName + " ?",
        QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes)
    {
        graph.deleteCity(cityName.toStdString());
        updateAdjacencyListDisplay();

        for (int i = edges.size() - 1; i >= 0; --i)
        {
            EdgeView* edge = edges[i];
            if (edge->connectsToCity(group))
            {
                scene->removeItem(edge);
                delete edge;
                edges.removeAt(i);
            }
        }
        highlightDeletedNode(group, false);
        scene->removeItem(group);
        delete group;
    }
    else
    {
        highlightDeletedNode(group, false);

    }

    deleteCityOn = false;
    resetDeleteButton(ui.deleteCityBtn, deleteCityOn);
  
}
void HomePage::handleDeleteEdge(QPointF pos)
{
    QGraphicsItem* clickedItem = scene->itemAt(pos, QTransform());
    if (!clickedItem)
    {
        resetDeleteButton(ui.deleteEdgeBtn, deleteEdgeOn);
        return;
    }

    EdgeView* clickedEdge = dynamic_cast<EdgeView*>(clickedItem);

    if (!clickedEdge)
    {
        for (EdgeView* edge : edges)
        {
            if (edge->contains(pos))
            {
                clickedEdge = edge;
                break;
            }
        }
    }

    if (!clickedEdge)
    {
        resetDeleteButton(ui.deleteEdgeBtn, deleteEdgeOn);
        return;

    }
       
    highlightEdge(clickedEdge, true);
    QString src = clickedEdge->getSource();
    QString dest = clickedEdge->getDestination();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Delete Edge", "Are you sure you want to delete the edge between " + src + " and " + dest + "?",
        QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes)
    {
        graph.deleteEdge(src.toStdString(), dest.toStdString());
        updateAdjacencyListDisplay();
        edges.removeOne(clickedEdge);

        delete clickedEdge;

    }
    else
    {
        highlightEdge(clickedEdge, false);
    }
    deleteEdgeOn = false;
    resetDeleteButton(ui.deleteEdgeBtn, deleteEdgeOn);
}


/*After adding city or edge -> reset objects*/
void HomePage::resetAddButton(QPushButton* btn, bool& flag)
{
    flag = false;
    ui.graphView->setCursor(Qt::ArrowCursor);
   btn->setStyleSheet(R"(
        QPushButton {
            background-color: white;
            color: black;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: 2px solid #d1d1d1;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        QPushButton:hover {
            background-color: #f0f0f0;
            color: black;
        }
        QPushButton:pressed {
            background-color: #e0e0e0;
        }
    )");
}
void HomePage::resetButtonStyle()
{
    QString defaultStyle = R"(
        QPushButton {
            background-color: white;
            color: black;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: 2px solid #d1d1d1;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        QPushButton:hover {
            background-color: #f0f0f0;
            color: black;
        }
        QPushButton:pressed {
            background-color: #e0e0e0;
        }
    )";
    ui.addCityBtn->setStyleSheet(defaultStyle);
    ui.addEdgeBtn->setStyleSheet(defaultStyle);
}
void HomePage::resetDeleteButton(QPushButton* btn, bool& flag)
{
    flag = false;
    ui.graphView->setCursor(Qt::ArrowCursor);
    btn->setStyleSheet(R"(
        QPushButton {
            background-color: #ff4d4d;
            color: white;
            font-weight: bold;
            font-family: 'Segoe UI', 'Arial';
            font-size: 14px;
            border: none;
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        QPushButton:hover {
            background-color: #ff3333;
            color: white;
        }
        QPushButton:pressed {
            background-color: #e60000;
        }
    )");
  
}

/*Highlight nodes when selected*/
void HomePage::highlightNode(QGraphicsItemGroup* nodes, bool highlight)
{
    QList<QGraphicsItem*> items = nodes->childItems();

    for (QGraphicsItem* item : items)
    {
        QGraphicsEllipseItem* node = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
        if (node)
        {
            if (highlight)
                node->setBrush(QBrush(Qt::yellow));
            else
                node->setBrush(QBrush(Qt::lightGray));
        }
    }
}
void HomePage::highlightDeletedNode(QGraphicsItemGroup* nodes, bool highlight)
{
    QList<QGraphicsItem*> items = nodes->childItems();

    for (QGraphicsItem* item : items)
    {
        QGraphicsEllipseItem* node = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
        if (node)
        {
            if (highlight)
                node->setBrush(QBrush(Qt::darkRed));
            else
                node->setBrush(QBrush(Qt::lightGray));
        }
    }
}
void HomePage::highlightEdge(EdgeView* edge, bool highlight)
{
    if (edge)
    {
        if (highlight)
        {
            edge->setPen(QPen(Qt::red, 4));
        }
        else
        {
            edge->setPen(QPen(Qt::black, 2));
        }
    }
}

/*display graph*/
void HomePage::updateAdjacencyListDisplay()
{
    const auto& adjacencyList = graph.getAdjacencyList();
    QString displayText;
    displayText = R"(
        <html>
        <head>
            <style>
                body { font-family: 'Segoe UI', Arial, sans-serif; font-size: 14px; }
                h3 { color: #333; margin-bottom: 10px; }
                table { width: 100%; border-collapse: collapse; }
                th { text-align: left; padding: 5px; background-color: #f5f5f5; }
                td { padding: 5px; border-bottom: 1px solid #ddd; vertical-align: top; }
                .city { font-weight: bold; }
                .arrow { color: #0066cc; }
                .distance { color: #666; font-size: 90%; }
                .no-connections { font-style: italic; color: #999; }
            </style>
        </head>
        <body>
            <h3>Graph Structure</h3>
    )";

    if (adjacencyList.empty()) {
        displayText += "<p class='no-connections'>No cities added yet.</p>";
    }
    else {
        displayText += "<table>";
        displayText += "<tr><th>City</th><th>Connections</th></tr>";

        for (const auto& cityPair : adjacencyList) {
            const string& city = cityPair.first;
            const list<Edge>& edges = cityPair.second;

            displayText += "<tr>";
            displayText += "<td class='city'>" + QString::fromStdString(city) + "</td>";
            displayText += "<td>";

            if (edges.empty()) {
                displayText += "<span class='no-connections'>No connections</span>";
            }
            else {
                for (const auto& edge : edges) {
                    QString destination = QString::fromStdString(edge.destination);
                    int distance = edge.distance;

                    displayText += QStringLiteral("<div><span class='arrow'>-></span> ");
                    displayText += destination;
                    displayText += QStringLiteral(" <span class='distance'>(");
                    displayText += QString::number(distance);
                    displayText += QStringLiteral(" km)</span></div>");
                }
            }

            displayText += "</td></tr>";
        }

        displayText += "</table>";
    }

    displayText += "</body></html>";
    adjacencyListDisplay->setHtml(displayText);
}

/*Alert msg box and logout*/
void HomePage::showAlert(const QString& title, const QString& message, QMessageBox::Icon icon)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setIcon(icon);
    msgBox.setWindowTitle(title);

    msgBox.setStyleSheet(R"(
        QMessageBox {
            background-color: #f5f5f5;
            border-radius: 10px;
            padding: 20px;
            font-family: 'Segoe UI', sans-serif;
        }

        QMessageBox QPushButton {
            background-color: #1c3b6f;
            color: white;
            font-size: 14px;
            font-family: 'Segoe UI', sans-serif;
            border-radius: 8px;
            padding: 8px 20px;
        }

        QMessageBox QPushButton:hover {
            background-color: #162e59;
        }

        QMessageBox QPushButton:pressed {
            background-color: #0f2244;
        }
    )");

    msgBox.exec();
}
void HomePage::logout()
{
    USERLOGIN* loginWindow = new USERLOGIN();
    loginWindow->setWindowFlags(Qt::Window);
    loginWindow->show();
    this->close();
}

HomePage::~HomePage()
{
}

