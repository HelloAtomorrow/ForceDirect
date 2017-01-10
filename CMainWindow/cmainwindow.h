/*
*此类用于图形化界面
*设置menu，Toolbar和最终显示节点网络的画布
*画图采用QGraphics框架
*/
#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_cmainwindow.h"
#include "CDataManager.h"
#include "SDataStructure.h"

using namespace std;


class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

	bool DrawGuidance(CDataManager dataManager);//画图函数

private slots:
	void TotalOperation();														//总处理函数,在此函数中创建数据预处理对象，得到vector<vector<string> > totalEdge

private:																				//而后创建算法对象，得到vector<SNode> sNode和vector<SEdge> sEdge，最后调用画图函数。
	void AddPointItem(QGraphicsScene *scene, const vector<SNode> &nodeData);	//画图过程中添加点的函数
	void AddLineItem(QGraphicsScene *scene, const vector<SNode> &nodeData);		//画图过程中添加边的函数
	void IcreaseFigure();														//放大图形的函数
	void DecreaseFigure();														//缩小图形的函数

private:
	Ui::CMainWindowClass ui;
	QAction *m_pOpenAction;			//打开文件Action
	QAction *m_pIncreaseAction;		//放大Action
	QAction *m_pDecreaseAction;		//缩小Action
};

#endif // CMAINWINDOW_H
