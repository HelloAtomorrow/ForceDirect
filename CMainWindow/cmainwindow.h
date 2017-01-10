/*
*��������ͼ�λ�����
*����menu��Toolbar��������ʾ�ڵ�����Ļ���
*��ͼ����QGraphics���
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

	bool DrawGuidance(CDataManager dataManager);//��ͼ����

private slots:
	void TotalOperation();														//�ܴ�����,�ڴ˺����д�������Ԥ������󣬵õ�vector<vector<string> > totalEdge

private:																				//���󴴽��㷨���󣬵õ�vector<SNode> sNode��vector<SEdge> sEdge�������û�ͼ������
	void AddPointItem(QGraphicsScene *scene, const vector<SNode> &nodeData);	//��ͼ��������ӵ�ĺ���
	void AddLineItem(QGraphicsScene *scene, const vector<SNode> &nodeData);		//��ͼ��������ӱߵĺ���
	void IcreaseFigure();														//�Ŵ�ͼ�εĺ���
	void DecreaseFigure();														//��Сͼ�εĺ���

private:
	Ui::CMainWindowClass ui;
	QAction *m_pOpenAction;			//���ļ�Action
	QAction *m_pIncreaseAction;		//�Ŵ�Action
	QAction *m_pDecreaseAction;		//��СAction
};

#endif // CMAINWINDOW_H
