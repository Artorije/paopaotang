/**
* @class CShell
* @brief �ڵ���
*
*CSell����Ϸ�еľ����ƽ���Ϸ��չ�Ĺؼ�����
*/
#pragma once
#include<time.h>
#include<opencv2\opencv.hpp>
//#include"CObserver.h"
//#include"CObserverJudgeHurt.h"
using namespace std;
class CObserver;
class CObserverJudgeHurt;
class CShell
{
public:
	CShell();
	~CShell();
	clock_t start;
	clock_t end;
	CvPoint m_pos;/**<�ڵ���ǰ���ص��λ�� */
	int m_state;/**< ը��ͼƬ��Ϣ��λ���±�*/
	int power;
	IplImage **m_picture;/**< ը��ͼƬ��Ϣ��ͼƬ */
	CObserver* observer;
	
	void SetImage(IplImage ** pimg);/**<��ȡͼƬ  */
	void ReleaseImg();/**<�ͷ�ͼƬ  */
	void DrawtoBK(IplImage *pbk);/**<���ը��  */
	void ChangeShep();/**< �ı�ը��������±� */
	bool Boom();/**< �ж�ը���Ƿ�ը����Ϣ */
	int GetPositionx();/**< ����ը��λ�õ�x�� */
	int GetPositiony();/**< ����ը��λ�õ�y�� */
	void DraeEffects(IplImage * pbk,int x,int y,int id);/**< ����ը����Ч */
	void SetObserver(CObserver* observer);
	void NotityObserver();
};

