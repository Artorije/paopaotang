/**
* @class CShell
* @brief 炮弹类
*
*CSell是游戏中的具有推进游戏进展的关键的类
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
	CvPoint m_pos;/**<炮弹当前像素点的位置 */
	int m_state;/**< 炸弹图片信息的位置下标*/
	int power;
	IplImage **m_picture;/**< 炸弹图片信息的图片 */
	CObserver* observer;
	
	void SetImage(IplImage ** pimg);/**<获取图片  */
	void ReleaseImg();/**<释放图片  */
	void DrawtoBK(IplImage *pbk);/**<描绘炸弹  */
	void ChangeShep();/**< 改变炸弹数组的下标 */
	bool Boom();/**< 判断炸弹是否爆炸的信息 */
	int GetPositionx();/**< 返回炸弹位置的x轴 */
	int GetPositiony();/**< 返回炸弹位置的y轴 */
	void DraeEffects(IplImage * pbk,int x,int y,int id);/**< 绘制炸弹特效 */
	void SetObserver(CObserver* observer);
	void NotityObserver();
};

