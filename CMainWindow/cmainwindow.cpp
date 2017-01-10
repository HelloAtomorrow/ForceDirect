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
	�˴������˵��Ͱ�ť
	*/
	m_pOpenAction = new QAction(tr("Open"), this);								//�������ļ�Action
	connect(m_pOpenAction, SIGNAL(triggered()), this, SLOT(TotalOperation()));	//�����¼�������TotalOperation����
	m_pIncreaseAction = new QAction(tr("Increase"), this);						//�����Ŵ�Action
	m_pDecreaseAction = new QAction(tr("Decrease"), this);						//������СAction

	QMenu *pMenuFile = menuBar()->addMenu(tr("&File"));							//�����˵�File
	pMenuFile->addAction(m_pOpenAction);										//��Open����������˵�

	QMenu *pMenuOperation = menuBar()->addMenu(tr("Operation"));				//�����˵�Operation
	pMenuOperation->addAction(m_pIncreaseAction);								//��Increase����������˵�
	pMenuOperation->addAction(m_pDecreaseAction);								//��Decrease����������˵�

	QToolBar *pToolBar = addToolBar(tr("&File"));								//����������	
	pToolBar->addAction(m_pOpenAction);											//��Open���������������
	QLineEdit *pFileAddress = new QLineEdit();									//����һ�������ַ��
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
	
	QMessageBox::information(NULL, tr("Open"), tr("Open a file"));			//�¼��������������ڡ�
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
