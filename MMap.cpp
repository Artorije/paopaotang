#include "MMap.h"

CMMap::CMMap()
{
	cout << "地图已经单例化" << endl;
}
CMMap::~CMMap()
{
}

//void CMMap::InitImage()
//{
//	int i;
//	char fliename[] = ".\\source\\s01.png";
//	for (i = 0; i < 15; i++)
//	{
//		sprintf_s(fliename, ".\\source\\s%02d.png", i);
//		m_paththings[i] = cvLoadImage(fliename,1);
//		if (m_paththings[i] == NULL)
//		{
//			cout << "敲到马带";
//			exit(0);
//		}
//	}
//}

void CMMap::ReadTxtmappath()
{
	fstream maptxt;
	cout << "请选择图一或者图二"<<endl;
	IplImage *ss;
	ss = cvLoadImage(".\\source\\地图选择.png");
	cvNamedWindow("122");
	while (true)
	{
		cvShowImage("122", ss);
		choose = cvWaitKey(0);
		if (choose == '1')
		{
			cout << "chooese1" << endl;
			maptxt.open(".\\map\\path.txt", ios::in);
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					maptxt >> m_Map[i][j];
				}
			}
			maptxt.close();
			break;
		}
		if (choose == '2')
		{
			cout << "chooese2" << endl;
			maptxt.open(".\\map\\path1.txt", ios::in);
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					maptxt >> m_Map[i][j];
				}
			}
			maptxt.close();
			break;
		}
		if (choose == '3')
		{
			cout << "chooese3" << endl;
			maptxt.open(".\\map\\path2.txt", ios::in);
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					maptxt >> m_Map[i][j];
				}
			}
			maptxt.close();
			break;
		}
		if (choose == '4')
		{
			cout << "chooese4" << endl;
			cout << "yese" << endl;
			maptxt.open(".\\map\\path3.txt", ios::in);
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					maptxt >> m_Map[i][j];
				}
			}
			maptxt.close();
			break;
		}
	}
}

void CMMap::AddBrick()
{
	int px = 0, py = 0;
	for (int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 16; col++)
		{
			int key = m_Map[row][col];
			CBrick* b = new CBrick;
			char fliename[] = ".\\source\\s00.png";
			b->FixBrick(cvLoadImage(fliename, 1));
			if (key > 0) {
				CBrick* c = new CBrick;
				sprintf_s(fliename, ".\\source\\s%02d.png", key);
				c->FixBrick(cvLoadImage(fliename, 1));
				b->subordinates.push_back(c);
			}
			bricks[row][col] = b;
		}
	}
}

void CMMap::CreateBKimg()
{
	m_pBK = cvLoadImage(".\\source\\背景图1.png");
	int px = 0, py = 0;
	for (int blockr = 0; blockr < 15; blockr++)
	{
		px = 0;
		for (int blockc = 0; blockc < 16; blockc++)
		{

			IplImage* pimg = bricks[blockr][blockc]->brick_image;
			if (pimg == NULL)
			{
				cout << "WTF?空指针！";
				exit(0);
			}
			for (int i = 0; i < pimg->height; i++)
			{
				for (int j = 0; j < pimg->width; j++)
				{
					int bv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
					int gv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
					int rv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
					if (!(bv == 0 && gv == 0 && rv == 0))
					{
						CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 0) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 1) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 2) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
					}
				}
			}
			if(!(bricks[blockr][blockc]->subordinates.empty())){
				pimg = bricks[blockr][blockc]->subordinates[0]->brick_image;
				for (int i = 0; i < pimg->height; i++)
				{
					for (int j = 0; j < pimg->width; j++)
					{
						int bv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
						int gv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
						int rv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
						if (!(bv == 0 && gv == 0 && rv == 0))
						{
							CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 0) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
							CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 1) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
							CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 2) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
						}
					}
				}
			}
			px += 32;
		}
		py += 32;
	}
}

void CMMap::Release()
{
	cvReleaseImage(&m_pBK);
	for (int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 16; col++)
		{
			cvReleaseImage(&bricks[row][col]->brick_image);
			if (!(bricks[row][col]->subordinates.empty())) {
				cvReleaseImage(&bricks[row][col]->subordinates[0]->brick_image);
			}
		}
	}
}

void CMMap::FixUp(int x, int y)
{
	m_Map[x][y] = 15;
}

void CMMap::FixClear(int x, int y,int pow)
{
	int nowid,i;
	m_Map[x][y] = 0;
	for (i = 1; i <= pow; i++)
	{
		if (x - i < 0|| m_Map[x - i][y] > 3)
			break;
		if (m_Map[x - i][y] == 1 || m_Map[x - i][y] == 2 || m_Map[x - i][y] == 3)
		{
			if(!(bricks[x - i][y]->subordinates.empty())){
				bricks[x - i][y]->subordinates.pop_back();
			}
			srand((unsigned)time(NULL));
			nowid = rand() % 10;
			if (nowid == 1) {
				m_Map[x - i][y] = 11;
				CTool* a_tool = new CToolShell;
				a_tool->LoadImage();
				a_tool->InitPos(x - i, y);
				tools.push_back(a_tool);
			}
			else if (nowid == 2) {
				int newmedid = rand() % 2;
				CTool* a_tool = new CToolPower(); 
				if (newmedid == 0) {
					m_Map[x - i][y] = 24;
					CTool* purplemed = new CToolDecoratorPurplePotion(a_tool);
					purplemed->LoadImage();
					purplemed->InitPos(x - i, y);
					tools.push_back(purplemed);
				}
				else {
					m_Map[x - i][y] = 12;
					a_tool->LoadImage();
					a_tool->InitPos(x - i, y);
					tools.push_back(a_tool);
				}
			}
			else if (nowid == 3) {
				m_Map[x - i][y] = 13;
				CTool* a_tool = new CToolShoe;
				a_tool->LoadImage();
				a_tool->InitPos(x - i, y);
				tools.push_back(a_tool);
			}
			else
				m_Map[x - i][y] = 0;
			break;
		}
	}
	for (i = 1; i <= pow; i++)
	{
		if (x + i >= 15 || m_Map[x + i][y] > 3)
			break;
		if (!(bricks[x + i][y]->subordinates.empty())) {
			bricks[x + i][y]->subordinates.pop_back();
		}
		if (m_Map[x + i][y] == 1 || m_Map[x + i][y] == 2 || m_Map[x + i][y] == 3)
		{
			srand((unsigned)time(0));
			nowid = rand() % 10;
			if (nowid == 1) {
				m_Map[x + i][y] = 11;
				CTool* a_tool = new CToolShell;
				a_tool->LoadImage();
				a_tool->InitPos(x + i, y);
				tools.push_back(a_tool);
			}
			else if (nowid == 2) {
				int newmedid = rand() % 2;
				CTool* a_tool = new CToolPower();
				if (newmedid == 0) {
					m_Map[x + i][y] = 24;
					CTool* purplemed = new CToolDecoratorPurplePotion(a_tool);
					purplemed->LoadImage();
					purplemed->InitPos(x + i, y);
					tools.push_back(purplemed);
				}
				else {
					m_Map[x + i][y] = 12;
					a_tool->LoadImage();
					a_tool->InitPos(x + i, y);
					tools.push_back(a_tool);
				}
			}
			else if (nowid == 3) {
				m_Map[x + i][y] = 13;
				CTool* a_tool = new CToolShoe;
				a_tool->LoadImage();
				a_tool->InitPos(x + i, y);
				tools.push_back(a_tool);
			}
			else
				m_Map[x + i][y] = 0;
			break;
		}
	}
	for (i = 1; i <= pow; i++)
	{
		if (y - i < 0|| m_Map[x][y - i] > 3)
			break;
		if (m_Map[x][y - i] == 1 || m_Map[x][y - i] == 2 || m_Map[x][y - i] == 3)
		{
			if (!(bricks[x][y - i]->subordinates.empty())) {
				bricks[x][y - i]->subordinates.pop_back();
			}
			srand((unsigned)time(0));
			nowid = rand() % 10;
			if (nowid == 1) {
				m_Map[x][y - i] = 11;
				CTool* a_tool = new CToolShell;
				a_tool->LoadImage();
				a_tool->InitPos(x, y - i);
				tools.push_back(a_tool);
			}
			else if (nowid == 2) {
				int newmedid = rand() % 2;
				CTool* a_tool = new CToolPower();
				if (newmedid == 0) {
					m_Map[x][y - i] = 24;
					CTool* purplemed = new CToolDecoratorPurplePotion(a_tool);
					purplemed->LoadImage();
					purplemed->InitPos(x, y - i);
					tools.push_back(purplemed);
				}
				else {
					m_Map[x][y - i] = 12;
					a_tool->LoadImage();
					a_tool->InitPos(x, y - i);
					tools.push_back(a_tool);
				}
			}
			else if (nowid == 3) {
				m_Map[x][y - i] = 13;
				CTool* a_tool = new CToolShoe;
				a_tool->LoadImage();
				a_tool->InitPos(x, y - i);
				tools.push_back(a_tool);
			}
			else
				m_Map[x][y - i] = 0;
			break;
		}
	}
	for (i = 1; i <= pow; i++)
	{
		if (y + i >= 16|| m_Map[x][y + i] > 3)
			break;
		if (m_Map[x][y + i] == 1 || m_Map[x][y + i] == 2 || m_Map[x][y + i] == 3)
		{
			if (!(bricks[x][y + i]->subordinates.empty())) {
				bricks[x][y + i]->subordinates.pop_back();
			}
			srand((unsigned)time(0));
			nowid = rand() % 10;
			if (nowid == 1) {
				m_Map[x][y + i] = 11;
				CTool* a_tool = new CToolShell;
				a_tool->LoadImage();
				a_tool->InitPos(x, y + i);
				tools.push_back(a_tool);
			}
			else if (nowid == 2) {
				int newmedid = rand() % 2;
				CTool* a_tool = new CToolPower();
				if (newmedid == 0) {
					m_Map[x][y + i] = 24;
					CTool* purplemed = new CToolDecoratorPurplePotion(a_tool);
					purplemed->LoadImage();
					purplemed->InitPos(x, y + i);
					tools.push_back(purplemed);
				}
				else {
					m_Map[x][y + i] = 12;
					a_tool->LoadImage();
					a_tool->InitPos(x, y + i);
					tools.push_back(a_tool);
				}
			}
			else if (nowid == 13) {
				m_Map[x][y + i] = 13;
				CTool* a_tool = new CToolShoe;
				a_tool->LoadImage();
				a_tool->InitPos(x, y + i);
				tools.push_back(a_tool);
			}
			else
				m_Map[x][y + i] = 0;
			break;
		}
	}
}

void CMMap::SetTool(IplImage ** pimg)
{
	m_tools = pimg;
}

void CMMap::UpMap()
{
	int px = 0, py = 0;
	for (int blockr = 0; blockr < 15; blockr++)
	{
		px = 0;
		for (int blockc = 0; blockc < 16; blockc++)
		{
			//IplImage *pimg = m_paththings[m_Map[blockr][blockc]];
			IplImage* pimg = bricks[blockr][blockc]->brick_image;
			if (pimg == NULL)
			{
				cout << "WTF?空指针！";
				exit(0);
			}
			for (int i = 0; i < pimg->height; i++)
			{
				for (int j = 0; j < pimg->width; j++)
				{

					int bv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
					int gv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
					int rv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
					if (!(bv == 0 && gv == 0 && rv == 0))
					{
						CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 0) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 1) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 2) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
					}
				}
			}
			if (!(bricks[blockr][blockc]->subordinates.empty())) {
				pimg = bricks[blockr][blockc]->subordinates[0]->brick_image;
				for (int i = 0; i < pimg->height; i++)
				{
					for (int j = 0; j < pimg->width; j++)
					{
						int bv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
						int gv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
						int rv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
						if (!(bv == 0 && gv == 0 && rv == 0))
						{
							CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 0) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
							CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 1) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
							CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 2) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
						}
					}
				}
			}

			vector<CTool*>::iterator iter;
			for (iter = tools.begin(); iter < tools.end(); iter++)
			{
				int toolx = (*iter)->posx;
				int tooly = (*iter)->posy;
				if (toolx == blockr && tooly == blockc) {
					IplImage* pimg;
					pimg = (*iter)->tool_image;
					for (int i = 0; i < pimg->height; i++)
					{
						for (int j = 0; j < pimg->width; j++)
						{

							int bv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
							int gv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
							int rv = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
							if (!(bv == 0 && gv == 0 && rv == 0))
							{
								CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 0) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 0);
								CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 1) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
								CV_IMAGE_ELEM(m_pBK, uchar, py + i, (px + j) * 3 + 2) = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);
							}
						}
					}
				}
			}
			px += 32;
		}
		py += 32;
	}
}

void CMMap::Delet_Tools(int x, int y)
{
	vector<CTool*>::iterator iter;
	for (iter = tools.begin(); iter < tools.end();iter++)
	{
		if ((*iter)->posx == x && (*iter)->posy==y) {
			tools.erase(iter);
			break;
		}
	}
}

CMMap* CMMap::GetInstance()
{
	if (_instance == NULL) {
		_instance = new CMMap();
	}
	return _instance;
}
CMMap* CMMap::_instance = nullptr;
