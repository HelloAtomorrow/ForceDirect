#include <QLineEdit>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMessageBox>
#include <string>
#include "cmainwindow.h"
#include "CFileOperation.h"
#include "CForceGuidanceAlgorithm.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*
	此处创建菜单和按钮
	*/
	m_pOpenAction = new QAction(tr("Open"), this);								//创建打开文件Action
	connect(m_pOpenAction, SIGNAL(triggered()), this, SLOT(TotalOperation()));	//连接事件，调用TotalOperation函数
	m_pIncreaseAction = new QAction(tr("Increase"), this);						//创建放大Action
	m_pDecreaseAction = new QAction(tr("Decrease"), this);						//创建缩小Action

	QMenu *pMenuFile = menuBar()->addMenu(tr("&File"));							//创建菜单File
	pMenuFile->addAction(m_pOpenAction);										//将Open操作添加至菜单

	QMenu *pMenuOperation = menuBar()->addMenu(tr("Operation"));				//创建菜单Operation
	pMenuOperation->addAction(m_pIncreaseAction);								//将Increase操作添加至菜单
	pMenuOperation->addAction(m_pDecreaseAction);								//将Decrease操作添加至菜单

	QToolBar *pToolBar = addToolBar(tr("&File"));								//创建工具栏	
	pToolBar->addAction(m_pOpenAction);											//将Open操作添加至工具栏
	QLineEdit *pFileAddress = new QLineEdit();									//创建一个输入地址栏
	pToolBar->addWidget(pFileAddress);
	pToolBar->addAction(m_pIncreaseAction);
	pToolBar->addAction(m_pDecreaseAction);
}

CMainWindow::~CMainWindow()
{
	
}

void CMainWindow::TotalOperation()
{
	std::string fileName = "test.txt";
	CDataManager dataManager;
	CFileOperation::ReadFile(fileName, dataManager);
	
	CForceGuidanceAlgorithm forceGuidance;
	forceGuidance.AlgorithmCompute(dataManager, 100, 100, 1);
	
	QMessageBox::information(NULL, tr("Open"), tr("Open a file"));			//事件操作，弹出窗口。
	DrawGuidance(dataManager);
}

bool CMainWindow::DrawGuidance(CDataManager dataManager)
{
	const vector<SNode> &nodeData = dataManager.GetNodeData();
	QGraphicsScene *scene = new QGraphicsScene;
	QGraphicsView *view = new QGraphicsView(scene);
	view->setRenderHints(QPainter::Antialiasing);
	setCentralWidget(view);
	AddPointItem(scene, nodeData);
	AddLineItem(scene, nodeData);
	return true;
}

void CMainWindow::AddPointItem(QGraphicsScene *scene, const vector<SNode> &nodeData)
{
	for (int i = 0; i < nodeData.size(); i++)
	{
		QGraphicsEllipseItem *pNodeItem = new QGraphicsEllipseItem(nodeData[i].label_x, nodeData[i].label_y, 10, 10);
		pNodeItem->setBrush(Qt::red);
		scene->addItem(pNodeItem);
	}
}

void CMainWindow::AddLineItem(QGraphicsScene *scene, const vector<SNode> &nodeData)
{
	for (int i = 0; i < nodeData.size(); i++)
	{
		for (int j = i; j < nodeData.size(); j += 2)
		{
			QGraphicsLineItem *pEdgeItem = new QGraphicsLineItem(nodeData[i].label_x + 5, nodeData[i].label_y + 5, nodeData[j].label_x + 5, nodeData[j].label_y + 5);
			pEdgeItem->setPen(QPen(Qt::black, 1.5, Qt::SolidLine, Qt::RoundCap));
			scene->addItem(pEdgeItem);
		}
	}
}
