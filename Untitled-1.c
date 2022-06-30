#include"yiqing.h"

int NowStudentNums = 0;
int NowHealthNums = 0;
int NowTestNums = 0;
int NowVaccineNums = 0;

ADM AdminUser; //定义一个管理员
STU StuArry[n]; //定义一个结构体数组存放n名学生的全部信息
Health health[n];//定义一个结构体数组存放n名学生的健康信息
Test test[n];//定义一个结构体数组存放n名学生的核酸信息
Vaccine vaccine[n];//定义一个结构体数组存放n名学生的疫苗信息


//首页
void FirstPage() {
	ReadInfor();//只要进入程序就读取数据——获取当前全部学生信息，避免反复读入！
	ReadHealth();
	ReadTest();
	ReadVaccine();
	initgraph(760, 760);//窗口大小
	MOUSEMSG m1;//鼠标操作1
	cleardevice();
	IMAGE picture1;
	loadimage(&picture1, "images/firstbg1.png", 760, 760);
	putimage(0, 0, &picture1);
	setbkmode(TRANSPARENT);
	setfillcolor(GREEN);

	//大标题
	char FirstTitle[20] = { "疫情防控管理系统" };
	settextstyle(60, 0, "宋体");
	outtextxy(150, 100, FirstTitle);

	//三个选项的背景
	fillrectangle(230, 445, 560, 490);
	fillrectangle(230, 505, 560, 550);
	fillrectangle(230, 565, 560, 610);

	setbkmode(TRANSPARENT);

	//三个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//三个选项

	char FirstSelect1[20] = { "管理员操作界面" };
	char FirstSelect2[20] = { "学生操作界面" };
	char FirstSelect3[20] = { "退出程序" };
	RECT R[3] = { {230, 445, 560, 490},{230, 505, 560, 550},{230, 565, 560, 610} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//进入主界面选项操作界面
	while (1) {
		m1 = GetMouseMsg();//获取鼠标操作
		if (m1.x >= 230 && m1.x <= 560 && m1.y >= 445 && m1.y <= 490)//管理员界面
		{
			setlinecolor(RED);
			rectangle(230, 445, 560, 490);
			if (m1.uMsg == WM_LBUTTONDOWN) {     //当单击鼠标左键时触发事件
				AdminSignIn(); //管理员登录界面，只有账号密码正确才执行AdminPage函数
			}
		}
		else if (m1.x >= 230 && m1.x <= 560 && m1.y >= 505 && m1.y <= 550)//学生用户界面
		{
			setlinecolor(RED);
			rectangle(230, 505, 560, 550);
			if (m1.uMsg == WM_LBUTTONDOWN) {     //当单击鼠标左键时触发事件
				StuSignIn();
			}
		}
		else if (m1.x >= 230 && m1.x <= 560 && m1.y >= 565 && m1.y <= 610)//退出
		{
			setlinecolor(RED);
			rectangle(230, 565, 560, 610);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				exit(0);
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 445, 560, 490);
			rectangle(230, 505, 560, 550);
			rectangle(230, 565, 560, 610);
		}
	}

}

//读入学生信息
void ReadInfor() {
	FILE* fp;
	fopen_s(&fp, "StudentInforFile.txt", "r");
	if (fp == NULL) {
		return;
	}
	//将文件中的数据读取到当前的结构体数组中
	for (int i = 0; i < n; i++) {
		fscanf_s(fp, "%s\t%s\t%s\t%s\t%s\t%s\n",
			StuArry[i].ID, 10,
			StuArry[i].name, len,
			StuArry[i].password, len,
			StuArry[i].email, len,
			StuArry[i].phone, 15,
			StuArry[i].faculty, len);
	}

	int FileStudentNums = 0;//辅助先得到文件中的人数
	//读取出文件中数据的人数个数
	for (int k = 0; k < n; k++) {
		if (strlen(StuArry[k].name) != 0) {
			//当前人数——FileStudentNums不能设全局变量，否则多次读取的时候会出现问题
			NowStudentNums = ++FileStudentNums; //nowstudentnums是全局变量
		}
	}
	fclose(fp);
}

//管理员登录
void AdminSignIn() {
	//打开文件将账号和密码读过来
	FILE* fp;
	fopen_s(&fp, "AdminSignIn.txt", "r");
	if (fp == NULL) {
		return;
	}
	fscanf_s(fp, "%s\t%s\n", AdminUser.name, len, AdminUser.password, len);//读取到对应的管理员结构体数组
	fclose(fp);//关闭文件

	char ReceAcctNumber[64]; //记录输入的用户名字符串
	TCHAR InputAcct[] = _T("请输入用户名");
	InputBox(ReceAcctNumber, 10, InputAcct);

	char ReceAcctpassword[64]; //记录输入的密码字符串
	TCHAR InputPass[] = _T("请输入密码");
	InputBox(ReceAcctpassword, 10, InputPass);

	//如果用户名和密码都正确才进度到管理员界面，否则弹窗提示错误
	if (strcmp(AdminUser.name, ReceAcctNumber) == 0 && strcmp(AdminUser.password, ReceAcctpassword) == 0) {
		cleardevice();
		AdminPage();
	}
	//弹窗错误提示，需要先实例化SignError对象
	else {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "用户名或密码错误!", "提示", MB_OK);
	}
}

//管理员界面
void AdminPage() {
	initgraph(760, 760);//先清除一下
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/firstbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };

	fillrectangle(50, 145, 100, 565);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);

	setbkmode(TRANSPARENT);

	//五个选项的背景
	fillrectangle(230, 90, 560, 135);
	fillrectangle(230, 225, 560, 270);
	fillrectangle(230, 360, 560, 405);
	fillrectangle(230, 495, 560, 540);
	fillrectangle(230, 630, 560, 675);
	setbkmode(TRANSPARENT);

	//五个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//管理员界面的5个选项
	char FirstSelect1[20] = { "学生信息管理" };
	char FirstSelect2[20] = { "查看填报记录" }; //查看健康、核酸、疫苗填报记录
	char FirstSelect3[20] = { "健康状况异常学生" };
	char FirstSelect4[20] = { "统计分析" };
	char FirstSelect5[20] = { "返回" };
	RECT R[5] = { {230, 90, 560, 135},{230, 225, 560, 270},{230, 360, 560, 405},{230, 495, 560, 540},{230, 630, 560, 675} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect4, &R[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect5, &R[4], DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 90 && m2.y <= 135) {
			setlinecolor(RED);
			rectangle(230, 90, 560, 135);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//学生信息管理
				cleardevice();
				StuInfo();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 225 && m2.y <= 270) {
			setlinecolor(RED);
			rectangle(230, 225, 560, 270);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查看填报记录
				cleardevice();
				StuRecord();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 405) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 405);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查询
				cleardevice();
				StuProblem();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 495 && m2.y <= 540) {
			setlinecolor(RED);
			rectangle(230, 495, 560, 540);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//统计分析
				cleardevice();
				StuAnalyse();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 630 && m2.y <= 675) {
			setlinecolor(RED);
			rectangle(230, 630, 560, 675);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				FirstPage();
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 90, 560, 135);
			rectangle(230, 225, 560, 270);
			rectangle(230, 360, 560, 405);
			rectangle(230, 495, 560, 540);
			rectangle(230, 630, 560, 675);
		}
	}
}

//学生信息的增删改查界面
void StuInfo() {
	//鼠标操作
	MOUSEMSG SL;
	initgraph(760, 760);

	cleardevice();
	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 760, 760);
	putimage(0, 0, &picture2);
	setbkmode(TRANSPARENT);
	setfillcolor(GREEN);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };

	fillrectangle(50, 145, 100, 565);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);

	fillrectangle(300, 90, 460, 140);//增
	fillrectangle(300, 190, 460, 240);//删
	fillrectangle(300, 290, 460, 340);//查
	fillrectangle(300, 390, 460, 440);//改
	fillrectangle(300, 490, 460, 540);//清空
	fillrectangle(300, 590, 460, 640);//返回

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "黑体");
	outtextxy(330, 90, "添加");
	outtextxy(330, 190, "删除");
	outtextxy(330, 290, "查找");
	outtextxy(330, 390, "修改");
	outtextxy(330, 490, "清空");
	outtextxy(330, 590, "返回");

	//进入鼠标操作环节
	while (1) {
		SL = GetMouseMsg();
		if (SL.x >= 300 && SL.x <= 460 && SL.y >= 90 && SL.y <= 140) {

			setlinecolor(RED);
			rectangle(300, 90, 460, 140);
			if (SL.uMsg == WM_LBUTTONDOWN) {
				//添加
				InputInfor();
				cleardevice();
				//完成操作重新载入——刷新
				StuInfo();
			}
		}
		else if (SL.x >= 300 && SL.x <= 460 && SL.y >= 190 && SL.y <= 240) {

			setlinecolor(RED);
			rectangle(300, 190, 460, 240);
			if (SL.uMsg == WM_LBUTTONDOWN) {
				//删除
				DeSomeStu();
				//完成操作重新载入——刷新
				StuInfo();
			}
		}
		else if (SL.x >= 300 && SL.x <= 460 && SL.y >= 290 && SL.y <= 340) {

			setlinecolor(RED);
			rectangle(300, 290, 460, 340);
			if (SL.uMsg == WM_LBUTTONDOWN) {
				//查询
				FindInfo();
				//完成操作重新载入——刷新
				StuInfo();
			}
		}
		else if (SL.x >= 300 && SL.x <= 460 && SL.y >= 390 && SL.y <= 440) {
			setlinecolor(RED);
			rectangle(300, 390, 460, 440);
			if (SL.uMsg == WM_LBUTTONDOWN) {
				//修改
				ModifyStudInfor();
				//完成操作重新载入——刷新
				StuInfo();
			}
		}
		else if (SL.x >= 300 && SL.x <= 460 && SL.y >= 490 && SL.y <= 540) {
			setlinecolor(RED);
			rectangle(300, 490, 460, 540);
			if (SL.uMsg == WM_LBUTTONDOWN) {
				//确保误删——弹窗加以提示
				HWND hwndDel = GetHWnd();
				int isok = MessageBox(hwndDel, "确认清空?", "提示", MB_OKCANCEL);
				if (isok == IDOK) {
					//调用清空函数
					DeleteStuInfor();
					//完成操作重新载入——刷新
					StuInfo();
					//弹窗提示
					int tips1 = MessageBox(hwndDel, "清空成功！", "提示", MB_OK);
				}
				else if (isok == IDCANCEL) {
					//点击取消不做反应
				}
			}
		}
		else if (SL.x >= 300 && SL.x <= 460 && SL.y >= 590 && SL.y <= 640) {
			//返回
			setlinecolor(RED);
			rectangle(300, 590, 460, 640);
			if (SL.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//完成操作重新载入——刷新
				AdminPage();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(300, 90, 460, 140);//增
			rectangle(300, 190, 460, 240);//删
			rectangle(300, 290, 460, 340);//查
			rectangle(300, 390, 460, 440);//改
			rectangle(300, 490, 460, 540);//清空
			rectangle(300, 590, 460, 640);//返回

		}
	}
}

//录入信息——通过弹窗输入
void InputInfor() {
	//InputBox中的数字参数——限制输入内容的位数

	//名字可以重复但是学号不能重复
	//通过循环来检查是否有重复的

	//输入学号
	while (1) {
		TCHAR InputWindow0[] = _T("请输入该学生的学号");
		InputBox(StuArry[NowStudentNums].ID, 9, InputWindow0);

		int FlagInput2 = 0;
		//计算输入的字符串长度
		int nums = strlen(StuArry[NowStudentNums].ID);
		//判断输入的是否是纯数字
		for (int i = 0; i < nums; i++) {
			if (StuArry[NowStudentNums].ID[i] < '0' || StuArry[NowStudentNums].ID[i] > '9')//如果不是数字
			{
				FlagInput2 = 1;
				HWND hwndInput2 = GetHWnd();
				int isok = MessageBox(hwndInput2, "输入格式有误，请重新输入", "提示", MB_OK);
				break;
			}
		}

		if (FlagInput2 == 0) {
			//判断是否输入重复
			int FlagInput1 = 0;
			for (int i = 0; i < NowStudentNums; i++) {
				if (strcmp(StuArry[NowStudentNums].ID, StuArry[i].ID) == 0) {
					FlagInput1 = 1;
				}
			}
			if (FlagInput1 == 1) {
				HWND hwndInput1 = GetHWnd();
				int isok = MessageBox(hwndInput1, "该学生已经存在，请重新输入", "提示", MB_OK);
			}
			if (FlagInput1 == 0) {
				break;//输入成功，进而输入姓名学院等信息
			}
		}
	}
	//如果满足上述两个条件则进行下面的：
	//输入姓名、密码、邮箱、电话、学院六项信息
	TCHAR InputWindow1[] = _T("请输入该学生的姓名");
	InputBox(StuArry[NowStudentNums].name, 10, InputWindow1);

	TCHAR InputWindow2[] = _T("请输入该学生的密码");
	InputBox(StuArry[NowStudentNums].password, 10, InputWindow2);

	TCHAR InputWindow3[] = _T("请输入该学生的邮箱");
	InputBox(StuArry[NowStudentNums].email, 20, InputWindow3);

	TCHAR InputWindow4[] = _T("请输入该学生的电话");
	InputBox(StuArry[NowStudentNums].phone, 20, InputWindow4);

	TCHAR InputWindow5[] = _T("请输入该学生的学院");
	InputBox(StuArry[NowStudentNums].faculty, 10, InputWindow5);

	SaveInfor();
}

//保存数据到文件中
void SaveInfor() {
	//如果学号和姓名都不是空的才写入文件
	if (strlen(StuArry[NowStudentNums].ID) != 0 && strlen(StuArry[NowStudentNums].name) != 0) {
		FILE* fp;
		fopen_s(&fp, "StudentInforFile.txt", "a");
		if (fp == NULL) {
			return;
		}
		fprintf(fp, "%-10s\t%-8s\t%-10s\t%-15s\t%-15s\t%-10s\n",
			StuArry[NowStudentNums].ID,
			StuArry[NowStudentNums].name,
			StuArry[NowStudentNums].password,
			StuArry[NowStudentNums].email,
			StuArry[NowStudentNums].phone,
			StuArry[NowStudentNums].faculty);
		fclose(fp);
		NowStudentNums++; //保存完毕人数++
	}
}

//返回要查找/修改/删除人所在结构体的下标
int ReturnPosi() {
	//接收用户输入，在删改查三个功能中调用此函数
	char ReceInput[64];
	TCHAR InputWindowFI[] = _T("请输入学号或者姓名以进行查找/修改/删除");
	InputBox(ReceInput, 10, InputWindowFI);

	//进行循环查找，一旦相同就跳出循环
	for (int w = 0; w < NowStudentNums; w++) {
		if (strcmp(StuArry[w].name, ReceInput) == 0 || strcmp(StuArry[w].ID, ReceInput) == 0)//返回0表示两个字符串相等
		{
			return w;
		}
	}
	//如果没找到这人就返回-1
	return -1;
}

//查询——这个负责最终的调用
void FindInfo() {
	//定义一个变量用来接收下标
	int TempPosi = ReturnPosi();
	if (TempPosi == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsF = GetHWnd();
		//用一个字符数组来总结句子
		int isok = MessageBox(hndtipsF, "查无此人!", "提示", MB_OK);
	}
	else//找到了——打印输出
	{
		cleardevice();
		PrintFindInfor(TempPosi);
	}
}

//打印找到人的信息
void PrintFindInfor(int Position) {
	//鼠标操作
	MOUSEMSG PFI;
	initgraph(600, 360);
	cleardevice();
	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 600, 360);
	putimage(0, 0, &picture2);
	setfillcolor(GREEN);
	fillrectangle(420, 315, 580, 345);//返回
	fillrectangle(20, 15, 350, 45);//学号
	fillrectangle(20, 75, 350, 105);//姓名
	fillrectangle(20, 135, 350, 165);//密码
	fillrectangle(20, 195, 350, 225);//邮箱
	fillrectangle(20, 255, 350, 285);//电话
	fillrectangle(20, 315, 350, 345);//学院
	setbkmode(TRANSPARENT);

	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("楷体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 30;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//表头文字部分
	outtextxy(25, 15, "学号:");
	outtextxy(25, 75, "姓名:");
	outtextxy(25, 135, "密码:");
	outtextxy(25, 195, "邮箱:");
	outtextxy(25, 255, "电话:");
	outtextxy(25, 315, "学院:");
	outtextxy(470, 315, "返回");

	//打印被查找人的信息
	//学号
	outtextxy(100, 15, StuArry[Position].ID);
	//姓名
	outtextxy(100, 75, StuArry[Position].name);
	//密码
	outtextxy(100, 135, StuArry[Position].password);
	//邮箱
	outtextxy(100, 195, StuArry[Position].email);
	//电话
	outtextxy(100, 255, StuArry[Position].phone);
	//学院
	outtextxy(100, 315, StuArry[Position].faculty);
	//照片
	char path[20] = "StuPhoto/";
	strcat_s(path, StuArry[Position].ID);
	strcat_s(path, ".jpg");
	//showPhoto(StuArry[Position].ID, picture2);
	IMAGE photo1;
	loadimage(&photo1, path, 140, 210);
	putimage(420, 15, &photo1);
	setbkmode(TRANSPARENT);

	while (1) {
		PFI = GetMouseMsg();
		if (PFI.x >= 420 && PFI.x <= 580 && PFI.y >= 315 && PFI.y <= 345) {
			//返回
			setlinecolor(RED);
			rectangle(420, 315, 580, 345);
			if (PFI.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				StuInfo();
			}
		}
		//鼠标不在选项上
		else {
			setlinecolor(WHITE);
			rectangle(420, 315, 580, 345);
		}

	}
}

//删除某个学生的信息
void DeSomeStu() {
	//先进行查找，找到返回下标，然后依次将该下标后面的数据往前推，最后人数--,没找到就查无此人
	int TempDelt = ReturnPosi();
	if (TempDelt == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsD = GetHWnd();
		//用一个字符数组来总结句子
		int isok = MessageBox(hndtipsD, "查无此人!", "提示", MB_OK);
	}
	else//找到了，确认是否删除
	{
		//找到了就提示是否确定删除
		HWND hndtipsDS = GetHWnd();
		//用一个字符数组来总结句子
		int isok = MessageBox(hndtipsDS, "确定删除？", "提示", MB_OKCANCEL);
		if (isok == IDOK) {
			//确定删除操作,将这个元素的后一个依次迁移
			for (int d = TempDelt; d < NowStudentNums - 1; d++) {
				StuArry[d] = StuArry[d + 1];
			}
			//现在的人数-1
			NowStudentNums--;
			//删除完成只是将当前结构体里面的数据清除了，但是文件中并没有作出更改,需要更新到文件中
			SaveInforModi();//用这个全部清空的函数，再对文件进行重写
		}
		else if (isok == IDCANCEL) {
			//取消删除不执行任何操作
		}
	}

}

//抹除全部数据再保存——主要用于修改功能
void SaveInforModi() {
	//先删掉，但是不将人数置空所以不能调用之前的删除函数
	//如果学号和姓名都不是空的才写入文件
	FILE* fp;
	fopen_s(&fp, "StudentInforFile.txt", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < NowStudentNums; i++) {
		if (strlen(StuArry[i].ID) != 0 && strlen(StuArry[i].name) != 0) {
			fprintf(fp, "%-10s\t%-8s\t%-10s\t%-15s\t%-15s\t%-10s\n",
				StuArry[i].ID,
				StuArry[i].name,
				StuArry[i].password,
				StuArry[i].email,
				StuArry[i].phone,
				StuArry[i].faculty);
		}
	}
	fclose(fp);
}

//修改学生信息，找到返回下标，重新给他赋值，保存，否则直接弹窗警告
void ModifyStudInfor() {
	//直接套用上面查找的操作，在此基础上加一行修改前
	//因为需要得到要修改人在结构体数组中的位置-下标，所以不能将函数直接拿过来用，得粘贴过来
	int TempModi = ReturnPosi();//定义一个变量用来接收下标
	if (TempModi == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsM = GetHWnd();
		int isok = MessageBox(hndtipsM, "查无此人!", "提示", MB_OK);
	}
	else//找到了这个学生进行下面的操作
	{
		cleardevice();		MOUSEMSG Modi;//鼠标操作
		initgraph(960, 760);

		IMAGE picture2;
		loadimage(&picture2, "images/secondbg.png", 960, 760);
		putimage(0, 0, &picture2);

		setfillcolor(GREEN);
		fillrectangle(690, 590, 850, 640);
		fillrectangle(10, 40, 950, 180);
		fillrectangle(10, 240, 950, 380);

		//表头文字部分
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "宋体");
		outtextxy(40, 40, "修改前");
		outtextxy(40, 240, "修改后");
		settextstyle(30, 0, "宋体");
		outtextxy(10, 100, "学号");
		outtextxy(110, 100, "姓名");
		outtextxy(220, 100, "密码");
		outtextxy(320, 100, "邮箱");
		outtextxy(560, 100, "电话");
		outtextxy(800, 100, "学院");
		outtextxy(740, 600, "返回");

		outtextxy(10, 300, "学号");
		outtextxy(110, 300, "姓名");
		outtextxy(220, 300, "密码");
		outtextxy(320, 300, "邮箱");
		outtextxy(560, 300, "电话");
		outtextxy(800, 300, "学院");

		//打印被查找人的信息,修改前
		//学号
		outtextxy(10, 140, StuArry[TempModi].ID);
		//姓名
		outtextxy(110, 140, StuArry[TempModi].name);
		//密码
		outtextxy(220, 140, StuArry[TempModi].password);
		//邮箱
		outtextxy(320, 140, StuArry[TempModi].email);
		//电话
		outtextxy(560, 140, StuArry[TempModi].phone);
		//学院
		outtextxy(800, 140, StuArry[TempModi].faculty);

		//加入输入弹窗——重新书写内容
		//修改学号
		while (1) {
			char TempModiNums[64];//用于接收输入的学号，先覆盖进去

			TCHAR InputWindow0[] = _T("请输入该学生的学号");
			InputBox(TempModiNums, 9, InputWindow0);

			if (strcmp(TempModiNums, StuArry[TempModi].ID) == 0)//如果输入的学号和本身位置的学号相同,则结束修改学号这个循环
			{
				//不作出变化,直接break
				break;
			}
			else//如果输入的学号和本身位置的学号不同，则需要判断与整个结构体中是否有重复的
			{
				int FlagInput3 = 0;
				int nums = strlen(TempModiNums);

				//判断输入的是否是纯数字
				for (int i = 0; i < nums; i++) {
					if (TempModiNums[i] < '0' || TempModiNums[i] > '9')//如果不是数字
					{
						FlagInput3 = 1;//这个flag用于判断输入的是不是数字，如果是数字则保持为1，可进入下面的if判断
						HWND hwndInput3 = GetHWnd();
						int isok = MessageBox(hwndInput3, "输入格式有误，请重新输入", "提示", MB_OK);
						break;
					}
				}

				if (FlagInput3 == 0) { //输入的是数字的话
					//判断是否输入重复
					int FlagInput4 = 0;
					for (int i = 0; i < NowStudentNums; i++) {
						if (strcmp(TempModiNums, StuArry[i].ID) == 0) {
							FlagInput4 = 1;
							break;
						}
					}
					if (FlagInput4 == 1) {
						HWND hwndInput4 = GetHWnd();
						int isok = MessageBox(hwndInput4, "该学生已经存在，请重新输入", "提示", MB_OK);
					}
					else if (FlagInput4 == 0) {
						//覆盖,memcpy用于内存赋值，可以复制各种数据类型（包括结构体），而strcpy只能复制字符串
						//memcpy(TempModiNums, StuArry[TempModi].ID, nums);
						memcpy(StuArry[TempModi].ID, TempModiNums, nums);
						break;
					}
				}
			}
		}
		//修改姓名
		TCHAR InputWindow1[] = _T("请输入该学生的姓名");
		InputBox(StuArry[TempModi].name, 10, InputWindow1);

		//修改密码
		TCHAR InputWindow2[] = _T("请输入该学生的密码");
		InputBox(StuArry[TempModi].password, 10, InputWindow2);

		//修改邮箱
		TCHAR InputWindow3[] = _T("请输入该学生的邮箱");
		InputBox(StuArry[TempModi].email, 20, InputWindow3);

		//修改电话
		TCHAR InputWindow4[] = _T("请输入该学生的电话");
		InputBox(StuArry[TempModi].phone, 20, InputWindow4);

		//修改学院
		TCHAR InputWindow5[] = _T("请输入该学生的学院");
		InputBox(StuArry[TempModi].faculty, 10, InputWindow5);

		//打印被查找人的信息
		//学号
		outtextxy(10, 340, StuArry[TempModi].ID);
		//姓名
		outtextxy(110, 340, StuArry[TempModi].name);
		//密码
		outtextxy(220, 340, StuArry[TempModi].password);
		//邮箱
		outtextxy(320, 340, StuArry[TempModi].email);
		//电话
		outtextxy(560, 340, StuArry[TempModi].phone);
		//学院
		outtextxy(800, 340, StuArry[TempModi].faculty);

		if (strlen(StuArry[TempModi].name) != 0 && strlen(StuArry[TempModi].password) != 0 && strlen(StuArry[TempModi].email) != 0 &&
			strlen(StuArry[TempModi].phone) != 0 && strlen(StuArry[TempModi].faculty) != 0) {
			//保存文件
			SaveInforModi();
		}
		else {
			HWND SignError = GetHWnd();
			int isok = MessageBox(SignError, "请勿输入空语句!", "提示", MB_OK);
		}

		while (1) {
			Modi = GetMouseMsg();
			if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
				//返回
				setlinecolor(RED);
				setlinecolor(RED);

				rectangle(690, 590, 850, 640);
				if (Modi.uMsg == WM_LBUTTONDOWN) {
					cleardevice();
					//回到增删查改界面
					StuInfo();
				}
			}
			//鼠标不悬停
			else {
				setlinecolor(WHITE);
				rectangle(690, 590, 850, 640);

			}
		}
	}
}

//删除学生信息
void DeleteStuInfor() {
	//删除文件
	remove("StudentInforFile.txt");
	//置空当前人数
	NowStudentNums = 0;
}

//截至目前，实现了管理员对学生个人信息的增删改查，写的好像有点长......

//下面是管理员对学生健康、核酸等信息的操作
//查看学生的填报记录
void StuRecord() {
	initgraph(760, 760);//先清除一下
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/firstbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };

	fillrectangle(50, 145, 100, 565);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);

	setbkmode(TRANSPARENT);

	//五个选项的背景
	fillrectangle(230, 90, 560, 135);
	fillrectangle(230, 225, 560, 270);
	fillrectangle(230, 360, 560, 405);
	fillrectangle(230, 495, 560, 540);
	setbkmode(TRANSPARENT);

	//五个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//管理员界面的5个选项
	char FirstSelect1[20] = { "每日健康记录" };
	char FirstSelect2[20] = { "核酸检测记录" };
	char FirstSelect3[20] = { "疫苗接种记录" };
	char FirstSelect4[20] = { "返回" };
	RECT R[5] = { {230, 90, 560, 135},{230, 225, 560, 270},{230, 360, 560, 405},{230, 495, 560, 540} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect4, &R[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 90 && m2.y <= 135) {
			setlinecolor(RED);
			rectangle(230, 90, 560, 135);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查看健康记录
				cleardevice();
				ShowHealthRecord();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 225 && m2.y <= 270) {
			setlinecolor(RED);
			rectangle(230, 225, 560, 270);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查看核酸记录
				cleardevice();
				ShowTestRecord();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 405) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 405);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查看疫苗记录
				cleardevice();
				ShowVaccineRecord();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 495 && m2.y <= 540) {
			setlinecolor(RED);
			rectangle(230, 495, 560, 540);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				AdminPage();
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 90, 560, 135);
			rectangle(230, 225, 560, 270);
			rectangle(230, 360, 560, 405);
			rectangle(230, 495, 560, 540);
		}
	}
}

//显示健康信息
void ShowHealthRecord() {
	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "日期");
	outtextxy(200, 40, "体温(早)");
	outtextxy(340, 40, "体温(中)");
	outtextxy(480, 40, "体温(晚)");
	outtextxy(620, 40, "是否咳嗽");
	outtextxy(740, 600, "返回");

	char StuID[64];//用于接收输入的日期，先覆盖进去
	TCHAR InputWindow0[] = _T("请输入您想查看的学生学号");
	InputBox(StuID, 15, InputWindow0);

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowHealthNums; i++) {
		if (strcmp(health[i].ID, StuID) == 0) {
			//日期
			outtextxy(10, 80 + y, health[i].date);
			//体温
			outtextxy(200, 80 + y, health[i].temperature1);
			outtextxy(260, 80 + y, "℃");
			outtextxy(340, 80 + y, health[i].temperature2);
			outtextxy(400, 80 + y, "℃");
			outtextxy(480, 80 + y, health[i].temperature3);
			outtextxy(540, 80 + y, "℃");
			//是否咳嗽
			outtextxy(620, 80 + y, health[i].cough);
			y += 35;
		}
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "没有此学生的健康信息!", "提示", MB_OK);
	}



	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuRecord();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

//显示核酸检测信息
void ShowTestRecord() {
	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "学号");
	outtextxy(200, 40, "日期");
	outtextxy(390, 40, "结果");
	outtextxy(740, 600, "返回");

	char StuID[64];//用于接收输入的日期，先覆盖进去
	TCHAR InputWindow0[] = _T("请输入您想查看的学生学号");
	InputBox(StuID, 15, InputWindow0);

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowTestNums; i++) {
		if (strcmp(test[i].ID, StuID) == 0) {
			outtextxy(10, 80 + y, test[i].ID);
			outtextxy(200, 80 + y, test[i].date);
			outtextxy(390, 80 + y, test[i].result);
			y += 35;
		}
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "没有此学生的核酸检测信息!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuRecord();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

//显示疫苗接种记录
void ShowVaccineRecord() {
	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "学号");
	outtextxy(200, 40, "日期");
	outtextxy(390, 40, "型号");
	outtextxy(740, 600, "返回");

	char StuID[64];//用于接收输入的日期，先覆盖进去
	TCHAR InputWindow0[] = _T("请输入您想查看的学生学号");
	InputBox(StuID, 15, InputWindow0);

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowVaccineNums; i++) {
		if (strcmp(vaccine[i].ID, StuID) == 0) {
			outtextxy(10, 80 + y, vaccine[i].ID);
			outtextxy(200, 80 + y, vaccine[i].date);
			outtextxy(390, 80 + y, vaccine[i].type);
			y += 35;
		}
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "没有此学生的疫苗接种信息!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuRecord();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

//查看健康情况异常的学生
void StuProblem() {
	initgraph(760, 760);//先清除一下
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/firstbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };

	fillrectangle(50, 145, 100, 565);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);

	setbkmode(TRANSPARENT);

	//五个选项的背景
	fillrectangle(230, 90, 560, 135);
	fillrectangle(230, 225, 560, 270);
	fillrectangle(230, 360, 560, 405);
	setbkmode(TRANSPARENT);

	//五个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//管理员界面的5个选项
	char FirstSelect1[len] = { "体温异常的学生" };
	char FirstSelect2[20] = { "有咳嗽状况的学生" };
	char FirstSelect3[20] = { "返回" };
	RECT R[3] = { {230, 90, 560, 135},{230, 225, 560, 270},{230, 360, 560, 405} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 90 && m2.y <= 135) {
			setlinecolor(RED);
			rectangle(230, 90, 560, 135);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//发烧
				cleardevice();
				ShowFeverStudent();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 225 && m2.y <= 270) {
			setlinecolor(RED);
			rectangle(230, 225, 560, 270);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//咳嗽
				cleardevice();
				ShowCoughStudent();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 405) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 405);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查询
				cleardevice();
				AdminPage();
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 90, 560, 135);
			rectangle(230, 225, 560, 270);
			rectangle(230, 360, 560, 405);
		}
	}
}

//显示发烧学生
void ShowFeverStudent() {
	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "学号");
	outtextxy(200, 40, "日期");
	outtextxy(390, 40, "发烧时段");
	outtextxy(740, 600, "返回");

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowHealthNums; i++) {
		if (atof(health[i].temperature1) > 37.3) {
			outtextxy(10, 80 + y, health[i].ID);
			outtextxy(200, 80 + y, health[i].date);
			outtextxy(390, 80 + y, "早上发烧");
			y += 35;
		}
		if (atof(health[i].temperature2) > 37.3) {
			outtextxy(10, 80 + y, health[i].ID);
			outtextxy(200, 80 + y, health[i].date);
			outtextxy(390, 80 + y, "中午发烧");
			y += 35;
		}
		if (atof(health[i].temperature3) > 37.3) {
			outtextxy(10, 80 + y, health[i].ID);
			outtextxy(200, 80 + y, health[i].date);
			outtextxy(390, 80 + y, "晚上发烧");
			y += 35;
		}
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "没有同学发烧!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuProblem();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);
		}
	}
}

//显示咳嗽学生
void ShowCoughStudent() {
	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "学号");
	outtextxy(200, 40, "日期");
	outtextxy(390, 40, "是否咳嗽");
	outtextxy(740, 600, "返回");

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowHealthNums; i++) {
		if (strcmp(health[i].cough, "是") == 0) {
			outtextxy(10, 80 + y, health[i].ID);
			outtextxy(200, 80 + y, health[i].date);
			outtextxy(390, 80 + y, "是");
			y += 35;
		}
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "没有同学有咳嗽症状!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuProblem();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

//分析学生情况
void StuAnalyse() {
	initgraph(760, 760);//先清除一下
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/firstbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };

	fillrectangle(50, 145, 100, 565);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);

	setbkmode(TRANSPARENT);

	//五个选项的背景
	fillrectangle(230, 90, 560, 135);
	fillrectangle(230, 225, 560, 270);
	fillrectangle(230, 360, 560, 405);
	fillrectangle(230, 495, 560, 540);
	setbkmode(TRANSPARENT);

	//五个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//管理员界面的5个选项
	char FirstSelect1[20] = { "降序排列学生体温" };
	char FirstSelect2[20] = { "降序排列核酸次数" };
	char FirstSelect3[20] = { "核酸次数排查" };
	char FirstSelect4[20] = { "返回" };
	RECT R[5] = { {230, 90, 560, 135},{230, 225, 560, 270},{230, 360, 560, 405},{230, 495, 560, 540} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect4, &R[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 90 && m2.y <= 135) {
			setlinecolor(RED);
			rectangle(230, 90, 560, 135);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//体温排序
				SortTemperature();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 225 && m2.y <= 270) {
			setlinecolor(RED);
			rectangle(230, 225, 560, 270);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				SortTest();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 405) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 405);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//查询
				CheckTestTimes();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 495 && m2.y <= 540) {
			setlinecolor(RED);
			rectangle(230, 495, 560, 540);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				AdminPage();
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 90, 560, 135);
			rectangle(230, 225, 560, 270);
			rectangle(230, 360, 560, 405);
			rectangle(230, 495, 560, 540);
		}
	}
}

//将体温降序排列
void SortTemperature() {
	//首先确定是根据上午还是下午还是晚上的体温进行排序！
	char ReceAcctNumber[64]; //记录输入的用户名字符串
	TCHAR InputAcct[] = _T("请输入:1.按上午体温排序；2.按下午体温排序；3.按晚上体温排序");
	InputBox(ReceAcctNumber, 10, InputAcct);

	int flagSortTemprature = -1;
	if (strcmp(ReceAcctNumber, "1") == 0) {
		flagSortTemprature = 1;
		for (int i = 0; i < NowHealthNums - 1; i++) {
			for (int j = 0; j < NowHealthNums - i - 1; j++) {
				if (atof(health[j].temperature1) < atof(health[j + 1].temperature1)) {
					Health tempHealth;
					tempHealth = health[j];
					health[j] = health[j + 1];
					health[j + 1] = tempHealth;
				}
			}
		}
	}
	else if (strcmp(ReceAcctNumber, "2") == 0) {
		flagSortTemprature = 2;
		for (int i = 0; i < NowHealthNums - 1; i++) {
			for (int j = 0; j < NowHealthNums - i - 1; j++) {
				if (atof(health[j].temperature2) < atof(health[j + 1].temperature2)) {
					Health tempHealth;
					tempHealth = health[j];
					health[j] = health[j + 1];
					health[j + 1] = tempHealth;
				}
			}
		}
	}
	else if (strcmp(ReceAcctNumber, "3") == 0) {
		flagSortTemprature = 3;
		for (int i = 0; i < NowHealthNums - 1; i++) {
			for (int j = 0; j < NowHealthNums - i - 1; j++) {
				if (atof(health[j].temperature3) < atof(health[j + 1].temperature3)) {
					Health tempHealth;
					tempHealth = health[j];
					health[j] = health[j + 1];
					health[j + 1] = tempHealth;
				}
			}
		}
	}
	else {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "请输入1/2/3以进行选择", "提示", MB_OK);
	}

	if (flagSortTemprature == 1) {
		SaveModifyHealth();
		HWND SignError1 = GetHWnd();
		int isok = MessageBox(SignError1, "已按照上午体温进行排序", "提示", MB_OK);
	}
	else if (flagSortTemprature == 2) {
		SaveModifyHealth();
		HWND SignError2 = GetHWnd();
		int isok = MessageBox(SignError2, "已按照中午体温进行排序", "提示", MB_OK);
	}
	else if (flagSortTemprature == 3) {
		SaveModifyHealth();
		HWND SignError3 = GetHWnd();
		int isok = MessageBox(SignError3, "已按照晚上体温进行排序", "提示", MB_OK);
	}

	//显示排序后的体温结果
	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(960, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 960, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 950, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "ID");
	outtextxy(110, 40, "日期");
	outtextxy(350, 40, "体温(早)");
	outtextxy(510, 40, "体温(中)");
	outtextxy(670, 40, "体温(晚)");
	outtextxy(830, 40, "是否咳嗽");
	outtextxy(740, 600, "返回");

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < 14; i++) {
		outtextxy(10, 80 + y, health[i].ID);
		//日期
		outtextxy(110, 80 + y, health[i].date);
		//体温
		outtextxy(350, 80 + y, health[i].temperature1);
		outtextxy(410, 80 + y, "℃");
		outtextxy(510, 80 + y, health[i].temperature2);
		outtextxy(570, 80 + y, "℃");
		outtextxy(670, 80 + y, health[i].temperature3);
		outtextxy(730, 80 + y, "℃");
		//是否咳嗽
		outtextxy(830, 80 + y, health[i].cough);
		y += 35;
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "暂无体温记录!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuAnalyse();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

//先生成TextFile文件记录核酸次数，此文件已经实现排序
void getTestTimes() {
	for (int k = 0; k < NowStudentNums; k++) {
		StuArry[k].TestTimes = 0;//初始化当前学生的检测次数
		for (int m = 0; m < NowTestNums; m++) {
			if (strcmp(test[m].ID, StuArry[k].ID) == 0) {
				StuArry[k].TestTimes++;
			}
		}
	}

	for (int i = 0; i < NowStudentNums - 1; i++) {
		for (int j = 0; j < NowStudentNums - i - 1; j++) {
			if (StuArry[j].TestTimes < StuArry[j + 1].TestTimes) {
				STU tempstudent;
				tempstudent = StuArry[j];
				StuArry[j] = StuArry[j + 1];
				StuArry[j + 1] = tempstudent;
			}
		}
	}

	FILE* fp;
	fopen_s(&fp, "TestTimes.txt", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < NowStudentNums; i++) {
		fprintf(fp, "%-10s\t%-10s\t%-5d\n",
			StuArry[i].ID,
			StuArry[i].name,
			StuArry[i].TestTimes);

	}
	fclose(fp);
}

//将核酸检测结果降序排列
void SortTest() {
	getTestTimes();

	HWND SignError1 = GetHWnd();
	int isok = MessageBox(SignError1, "已按照核酸检测次数生成文件", "提示", MB_OK);

	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "学号");
	outtextxy(200, 40, "姓名");
	outtextxy(390, 40, "核酸检测次数");
	outtextxy(740, 600, "返回");

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowStudentNums; i++) {

		outtextxy(10, 80 + y, StuArry[i].ID);
		outtextxy(200, 80 + y, StuArry[i].name);
		char tempTestTimes[10];//临时存放核酸次数
		_itoa_s(StuArry[i].TestTimes, tempTestTimes, 10);//将整数转换成字符串存储
		outtextxy(390, 80 + y, tempTestTimes);
		y += 35;
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "暂无核酸检测记录!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuAnalyse();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

//管理员输入一个数，找到核酸检测次数小于这个值的学生
void CheckTestTimes() {
	getTestTimes();

	char times[64]; //记录输入的用户名字符串
	TCHAR InputAcct[] = _T("您想找到核酸次数少于几次的学生？");
	InputBox(times, 10, InputAcct);



	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(860, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(8, 40, 850, 570);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 40, "学号");
	outtextxy(200, 40, "姓名");
	outtextxy(390, 40, "核酸检测次数");
	outtextxy(740, 600, "返回");

	int y = 0;//用于循环过程中改变outtextxy的纵轴位置

	for (int i = 0; i < NowStudentNums; i++) {
		if (StuArry[i].TestTimes < atof(times)) {
			outtextxy(10, 80 + y, StuArry[i].ID);
			outtextxy(200, 80 + y, StuArry[i].name);
			char tempTestTimes[10];
			_itoa_s(StuArry[i].TestTimes, tempTestTimes, 10);
			outtextxy(390, 80 + y, tempTestTimes);
			y += 35;
		}
	}
	if (y == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "暂无满足要求的记录!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StuAnalyse();
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}
}

/*===========================================================================*/


//接下来写写学生界面
void StudentPage(int flagNowStu) {
	initgraph(760, 760);//先清除一下
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/firstbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "学" };
	char SecondTitle2[5] = { "生" };
	char SecondTitle3[5] = { "用" };
	char SecondTitle4[5] = { "户" };
	char SecondTitle5[5] = { "操" };
	char SecondTitle6[5] = { "作" };
	char SecondTitle7[5] = { "界" };
	char SecondTitle8[5] = { "面" };

	fillrectangle(50, 145, 100, 625);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);
	outtextxy(50, 570, SecondTitle8);

	setcolor(RED);
	settextstyle(30, 0, "宋体");
	char NowStuID[len] = "当前用户ID:";
	strcat_s(NowStuID, StuArry[flagNowStu].ID);
	outtextxy(450, 720, NowStuID);
	setcolor(WHITE);

	setbkmode(TRANSPARENT);

	//五个选项的背景
	fillrectangle(230, 90, 560, 135);
	fillrectangle(230, 225, 560, 270);
	fillrectangle(230, 360, 560, 405);
	fillrectangle(230, 495, 560, 540);
	fillrectangle(230, 630, 560, 675);
	setbkmode(TRANSPARENT);

	//四个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//学生界面的5个选项
	char FirstSelect1[20] = { "修改个人信息" };
	char FirstSelect2[20] = { "每日健康记录" }; //填写体温、是否咳嗽、是否发烧
	char FirstSelect3[20] = { "核酸检测记录" };
	char FirstSelect4[20] = { "疫苗接种记录" };
	char FirstSelect5[20] = { "返回" };
	RECT R[5] = { {230, 90, 560, 135},{230, 225, 560, 270},{230, 360, 560, 405},{230, 495, 560, 540},{230, 630, 560, 675} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect4, &R[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect5, &R[4], DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 90 && m2.y <= 135) {
			setlinecolor(RED);
			rectangle(230, 90, 560, 135);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//修改个人信息
				ModifyStudInfor2(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 225 && m2.y <= 270) {
			setlinecolor(RED);
			rectangle(230, 225, 560, 270);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//每日健康记录
				cleardevice();
				HealthRecord(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 405) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 405);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//核酸检测记录
				cleardevice();
				TestRecord(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 495 && m2.y <= 540) {
			setlinecolor(RED);
			rectangle(230, 495, 560, 540);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//疫苗接种记录
				cleardevice();
				VaccineRecord(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 630 && m2.y <= 675) {
			setlinecolor(RED);
			rectangle(230, 630, 560, 675);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				FirstPage();
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 90, 560, 135);
			rectangle(230, 225, 560, 270);
			rectangle(230, 360, 560, 405);
			rectangle(230, 495, 560, 540);
			rectangle(230, 630, 560, 675);
		}
	}
}

//学生登录
void StuSignIn() {
	//打开文件将账号和密码读过来
	FILE* fp;
	fopen_s(&fp, "StudentInforFile.txt", "r");
	if (fp == NULL) {
		return;
	}
	int flagNowStu = -1;
	//读取到对应的学生结构体数组
	for (int i = 0; i < NowStudentNums; i++) {
		fscanf_s(fp, "%s\t%s\t%s\t%s\t%s\t%s\n",
			StuArry[i].ID, 10,
			StuArry[i].name, len,
			StuArry[i].password, len,
			StuArry[i].email, len,
			StuArry[i].phone, 15,
			StuArry[i].faculty, len);
	}
	fclose(fp);//关闭文件

	char ReceAcctNumber[64]; //记录输入的用户名字符串
	TCHAR InputAcct[] = _T("请输入学号");
	InputBox(ReceAcctNumber, 10, InputAcct);

	char ReceAcctpassword[64]; //记录输入的密码字符串
	TCHAR InputPass[] = _T("请输入密码");
	InputBox(ReceAcctpassword, 10, InputPass);

	//如果用户名和密码都正确才进度到学生界面，否则弹窗提示错误
	for (int j = 0; j < NowStudentNums; j++) {
		if (strcmp(StuArry[j].ID, ReceAcctNumber) == 0 && strcmp(StuArry[j].password, ReceAcctpassword) == 0) {
			cleardevice();
			flagNowStu = j;
		}
	}

	if (flagNowStu != -1) {
		cleardevice();
		StudentPage(flagNowStu);
	}
	//弹窗错误提示，需要先实例化SignError对象
	else {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "用户名或密码错误!", "提示", MB_OK);
	}
}

//修改学生信息，找到返回下标，重新给他赋值，保存，否则直接弹窗警告
void ModifyStudInfor2(int flagNowStu) {
	//直接套用上面查找的操作，在此基础上加一行修改前
	//因为需要得到要修改人在结构体数组中的位置-下标，所以不能将函数直接拿过来用，得粘贴过来

	cleardevice();		MOUSEMSG Modi;//鼠标操作
	initgraph(960, 760);

	IMAGE picture2;
	loadimage(&picture2, "images/secondbg.png", 960, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	fillrectangle(10, 40, 950, 180);
	fillrectangle(10, 240, 950, 380);

	//表头文字部分
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "宋体");
	outtextxy(40, 40, "修改前");
	outtextxy(40, 240, "修改后");
	settextstyle(30, 0, "宋体");
	outtextxy(10, 100, "学号");
	outtextxy(110, 100, "姓名");
	outtextxy(220, 100, "密码");
	outtextxy(320, 100, "邮箱");
	outtextxy(560, 100, "电话");
	outtextxy(800, 100, "学院");
	outtextxy(740, 600, "返回");

	outtextxy(10, 300, "学号");
	outtextxy(110, 300, "姓名");
	outtextxy(220, 300, "密码");
	outtextxy(320, 300, "邮箱");
	outtextxy(560, 300, "电话");
	outtextxy(800, 300, "学院");

	setcolor(RED);
	settextstyle(30, 0, "宋体");
	char NowStuID[len] = "当前用户ID:";
	strcat_s(NowStuID, StuArry[flagNowStu].ID);
	outtextxy(450, 720, NowStuID);
	setcolor(WHITE);

	//打印被查找人的信息,修改前
	//学号
	outtextxy(10, 140, StuArry[flagNowStu].ID);
	//姓名
	outtextxy(110, 140, StuArry[flagNowStu].name);
	//密码
	outtextxy(220, 140, StuArry[flagNowStu].password);
	//邮箱
	outtextxy(320, 140, StuArry[flagNowStu].email);
	//电话
	outtextxy(560, 140, StuArry[flagNowStu].phone);
	//学院
	outtextxy(800, 140, StuArry[flagNowStu].faculty);

	//加入输入弹窗——重新书写内容
	//修改学号
	while (1) {
		char TempModiNums[64];//用于接收输入的学号，先覆盖进去

		TCHAR InputWindow0[] = _T("请输入您的新学号");
		InputBox(TempModiNums, 9, InputWindow0);

		if (strcmp(TempModiNums, StuArry[flagNowStu].ID) == 0)//如果输入的学号和本身位置的学号相同,则结束修改学号这个循环
		{
			//不作出变化,直接break
			break;
		}
		else//如果输入的学号和本身位置的学号不同，则需要判断与整个结构体中是否有重复的
		{
			int FlagInput3 = 0;
			int nums = strlen(TempModiNums);

			//判断输入的是否是纯数字
			for (int i = 0; i < nums; i++) {
				if (TempModiNums[i] < '0' || TempModiNums[i] > '9')//如果不是数字
				{
					FlagInput3 = 1;//这个flag用于判断输入的是不是数字，如果是数字则保持为1，可进入下面的if判断
					HWND hwndInput3 = GetHWnd();
					int isok = MessageBox(hwndInput3, "输入格式有误，请重新输入", "提示", MB_OK);
					break;
				}
			}

			if (FlagInput3 == 0) { //输入的是数字的话
				//判断是否输入重复
				int FlagInput4 = 0;
				for (int i = 0; i < NowStudentNums; i++) {
					if (strcmp(TempModiNums, StuArry[i].ID) == 0) {
						FlagInput4 = 1;
						break;
					}
				}
				if (FlagInput4 == 1) {
					HWND hwndInput4 = GetHWnd();
					int isok = MessageBox(hwndInput4, "您输入的学号已经存在，请重新输入", "提示", MB_OK);
				}
				else if (FlagInput4 == 0) {
					//覆盖,memcpy用于内存赋值，可以复制各种数据类型（包括结构体），而strcpy只能复制字符串
					memcpy(StuArry[flagNowStu].ID, TempModiNums, 10);
					break;
				}
			}
		}
	}
	//修改姓名
	TCHAR InputWindow1[] = _T("请输入您的新姓名");
	InputBox(StuArry[flagNowStu].name, 10, InputWindow1);

	//修改密码
	TCHAR InputWindow2[] = _T("请输入您的新密码");
	InputBox(StuArry[flagNowStu].password, 10, InputWindow2);

	//修改邮箱
	TCHAR InputWindow3[] = _T("请输入您的新邮箱");
	InputBox(StuArry[flagNowStu].email, 10, InputWindow3);

	//修改电话
	TCHAR InputWindow4[] = _T("请输入您的新电话");
	InputBox(StuArry[flagNowStu].phone, 10, InputWindow4);

	//修改学院
	TCHAR InputWindow5[] = _T("请输入您的新学院");
	InputBox(StuArry[flagNowStu].faculty, 10, InputWindow5);

	//打印被查找人的信息
	//学号
	outtextxy(10, 340, StuArry[flagNowStu].ID);
	//姓名
	outtextxy(110, 340, StuArry[flagNowStu].name);
	//密码
	outtextxy(220, 340, StuArry[flagNowStu].password);
	//邮箱
	outtextxy(320, 340, StuArry[flagNowStu].email);
	//电话
	outtextxy(560, 340, StuArry[flagNowStu].phone);
	//学院
	outtextxy(800, 340, StuArry[flagNowStu].faculty);

	if (strlen(StuArry[flagNowStu].name) != 0 && strlen(StuArry[flagNowStu].password) != 0 && strlen(StuArry[flagNowStu].email) != 0 &&
		strlen(StuArry[flagNowStu].phone) != 0 && strlen(StuArry[flagNowStu].faculty) != 0) {
		//保存文件
		SaveInforModi();
	}
	else {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "请勿输入空语句!", "提示", MB_OK);
	}

	while (1) {
		Modi = GetMouseMsg();
		if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
			//返回
			setlinecolor(RED);
			setlinecolor(RED);

			rectangle(690, 590, 850, 640);
			if (Modi.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				//回到增删查改界面
				StudentPage(flagNowStu);
			}
		}
		//鼠标不悬停
		else {
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);

		}
	}

}

//用于某学生填写健康情况
void HealthRecord(int flagNowStu) {
	initgraph(760, 760);
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/secondbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "学" };
	char SecondTitle2[5] = { "生" };
	char SecondTitle3[5] = { "用" };
	char SecondTitle4[5] = { "户" };
	char SecondTitle5[5] = { "操" };
	char SecondTitle6[5] = { "作" };
	char SecondTitle7[5] = { "界" };
	char SecondTitle8[5] = { "面" };

	fillrectangle(50, 145, 100, 625);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);
	outtextxy(50, 570, SecondTitle8);

	setbkmode(TRANSPARENT);

	setcolor(RED);
	settextstyle(30, 0, "宋体");
	char NowStuID[len] = "当前用户ID:";
	strcat_s(NowStuID, StuArry[flagNowStu].ID);
	outtextxy(450, 720, NowStuID);
	setcolor(WHITE);

	//3个选项的背景
	fillrectangle(230, 160, 560, 200);
	fillrectangle(230, 360, 560, 400);
	fillrectangle(230, 560, 560, 600);
	setbkmode(TRANSPARENT);

	//3个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//学生界面的5个选项
	char FirstSelect1[20] = { "添加健康情况" };
	char FirstSelect2[20] = { "修改健康情况" };
	char FirstSelect3[20] = { "返回" };
	RECT R[3] = { {230, 160, 560, 200},{230, 360, 560, 400},{230, 560, 560, 600} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 160 && m2.y <= 200) {
			setlinecolor(RED);
			rectangle(230, 160, 560, 200);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//添加健康情况
				InputHealth(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 400) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 400);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//修改健康情况
				ModifyHealth(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 560 && m2.y <= 600) {
			setlinecolor(RED);
			rectangle(230, 560, 560, 600);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				StudentPage(flagNowStu);
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 160, 560, 200);
			rectangle(230, 360, 560, 400);
			rectangle(230, 560, 560, 600);
		}
	}
}

//录入健康信息——通过弹窗输入
void InputHealth(int flagNowStu) {
	//首先获得学生想填写的日期
	char date[15];
	TCHAR InputWindow0[] = _T("请输入填报的日期");
	InputBox(date, 15, InputWindow0);

	//首先检测此学生的信息是否已经存在，若已存在则提示使用修改功能
	for (int i = 0; i < NowHealthNums; i++) {
		if (strcmp(StuArry[flagNowStu].ID, health[i].ID) == 0 && strcmp(date, health[i].date) == 0) {
			HWND hwndInput1 = GetHWnd();
			int isok = MessageBox(hwndInput1, "你已经输入过健康信息，请使用修改功能", "提示", MB_OK);
			HealthRecord(flagNowStu);
		}
	}
	//如果满足上述条件则进行下面的：
	strcpy_s(health[NowHealthNums].ID, StuArry[flagNowStu].ID);
	strcpy_s(health[NowHealthNums].date, date);
	TCHAR InputWindow1[] = _T("请输入你早上的体温");
	InputBox(health[NowHealthNums].temperature1, 10, InputWindow1);

	TCHAR InputWindow2[] = _T("请输入你中午的体温");
	InputBox(health[NowHealthNums].temperature2, 10, InputWindow2);

	TCHAR InputWindow3[] = _T("请输入你晚上的体温");
	InputBox(health[NowHealthNums].temperature3, 10, InputWindow3);

	TCHAR InputWindow4[] = _T("请输入你是否咳嗽");
	InputBox(health[NowHealthNums].cough, 10, InputWindow4);

	if (strlen(health[NowHealthNums].date) != 0 && strlen(health[NowHealthNums].temperature1) != 0 && strlen(health[NowHealthNums].temperature2) != 0 &&
		strlen(health[NowHealthNums].temperature3) != 0 && strlen(health[NowHealthNums].cough) != 0)
		SaveHealth();
	else {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "请勿输入空语句！", "提示", MB_OK);
	}
}

//保存健康数据到文件中
void SaveHealth() {
	if (strlen(health[NowHealthNums].temperature1) == 0 || strlen(health[NowHealthNums].temperature2) == 0 ||
		strlen(health[NowHealthNums].temperature3) == 0 || strlen(health[NowHealthNums].cough) == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "请勿输入空语句!", "提示", MB_OK);
		return;
	}
	else {
		FILE* fp;
		fopen_s(&fp, "HealthFile.txt", "a");
		if (fp == NULL) {
			return;
		}
		fprintf(fp, "%-10s\t%-15s\t%-5s\t%-5s\t%-5s\t%-5s\n",
			health[NowHealthNums].ID,
			health[NowHealthNums].date,
			health[NowHealthNums].temperature1,
			health[NowHealthNums].temperature2,
			health[NowHealthNums].temperature3,
			health[NowHealthNums].cough);
		fclose(fp);
		NowHealthNums++; //保存完毕人数++
	}
}

//找到健康信息对应位置
int ReturnHealthPosision(int flagNowStu) {
	//找到待修改的学号、日期对应的位置
	char ReceInput[64];
	TCHAR InputWindowFI[] = _T("请输入待修改项对应的日期");
	InputBox(ReceInput, 15, InputWindowFI);

	//进行循环查找，一旦相同就跳出循环
	for (int w = 0; w < NowHealthNums; w++) {
		if (strcmp(health[w].date, ReceInput) == 0 && strcmp(StuArry[flagNowStu].ID, health[w].ID) == 0)//日期和ID都要一致才能修改
		{
			return w;
		}
	}
	//如果没找到这人就返回-1
	return -1;
}

//修改健康信息
void ModifyHealth(int flagNowStu) {
	int TempModi = ReturnHealthPosision(flagNowStu);//定义一个变量用来接收下标
	if (TempModi == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsM = GetHWnd();
		int isok = MessageBox(hndtipsM, "没有您的健康信息记录，请先填写健康信息!", "提示", MB_OK);
	}
	else//找到了这个学生进行下面的操作
	{
		cleardevice();		MOUSEMSG Modi;//鼠标操作
		initgraph(860, 760);

		IMAGE picture2;
		loadimage(&picture2, "images/secondbg.png", 860, 760);
		putimage(0, 0, &picture2);

		setfillcolor(GREEN);
		fillrectangle(690, 590, 850, 640);
		fillrectangle(10, 40, 850, 180);
		fillrectangle(10, 240, 850, 380);

		//表头文字部分
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "宋体");
		outtextxy(40, 40, "修改前");
		outtextxy(40, 240, "修改后");
		settextstyle(30, 0, "宋体");
		outtextxy(10, 100, "日期");
		outtextxy(200, 100, "体温(早)");
		outtextxy(340, 100, "体温(中)");
		outtextxy(480, 100, "体温(晚)");
		outtextxy(620, 100, "是否咳嗽");
		outtextxy(740, 600, "返回");

		outtextxy(10, 300, "日期");
		outtextxy(200, 300, "体温(早)");
		outtextxy(340, 300, "体温(中)");
		outtextxy(480, 300, "体温(晚)");
		outtextxy(620, 300, "是否咳嗽");

		setcolor(RED);
		settextstyle(30, 0, "宋体");
		char NowStuID[len] = "当前用户ID:";
		strcat_s(NowStuID, StuArry[flagNowStu].ID);
		outtextxy(450, 720, NowStuID);
		setcolor(WHITE);

		//打印被查找人的信息,修改前
		//日期
		outtextxy(10, 140, health[TempModi].date);
		//体温
		outtextxy(200, 140, health[TempModi].temperature1);
		outtextxy(260, 140, "℃");
		outtextxy(340, 140, health[TempModi].temperature2);
		outtextxy(400, 140, "℃");
		outtextxy(480, 140, health[TempModi].temperature3);
		outtextxy(540, 140, "℃");
		//是否咳嗽
		outtextxy(620, 140, health[TempModi].cough);

		//加入输入弹窗——重新书写内容
		//修改日期
		while (1) {
			char TempModiNums[64];//用于接收输入的日期，先覆盖进去
			TCHAR InputWindow0[] = _T("请输入修改后的日期");
			InputBox(TempModiNums, 15, InputWindow0);

			if (strcmp(TempModiNums, health[TempModi].date) == 0)//如果输入的日期和本身位置的日期相同,则结束修改日期这个循环
			{
				//不作出变化,直接break
				break;
			}
			else//如果输入的日期和本身位置的日期不同，则需要判断与整个结构体中是否有重复的
			{
				int nums = strlen(TempModiNums);
				//判断是否输入重复
				int FlagInput4 = 0;
				for (int i = 0; i < NowHealthNums; i++) {
					if (strcmp(TempModiNums, health[i].date) == 0 && strcmp(health[i].ID, StuArry[flagNowStu].ID) == 0) {
						FlagInput4 = 1;
						break;
					}
				}
				if (FlagInput4 == 1) {
					//从老日期改到新日期，需要避免新日期与其它日期重复
					HWND hwndInput4 = GetHWnd();
					int isok = MessageBox(hwndInput4, "您输入的日期已经存在，请重新输入", "提示", MB_OK);
				}
				else if (FlagInput4 == 0) {
					//覆盖,memcpy用于内存赋值，可以复制各种数据类型（包括结构体），而strcpy只能复制字符串
					memcpy(health[TempModi].date, TempModiNums, 15);
					break;
				}

			}
		}
		//修改体温
		TCHAR InputWindow1[] = _T("请输入修改后的体温(早)");
		InputBox(health[TempModi].temperature1, 10, InputWindow1);

		TCHAR InputWindow2[] = _T("请输入修改后的体温(中)");
		InputBox(health[TempModi].temperature2, 10, InputWindow2);

		TCHAR InputWindow3[] = _T("请输入修改后的体温(晚)");
		InputBox(health[TempModi].temperature3, 10, InputWindow3);

		//是否咳嗽
		TCHAR InputWindow4[] = _T("请输入你当天是否咳嗽");
		InputBox(health[TempModi].cough, 10, InputWindow4);

		//打印被查找人的信息
		//学号
		outtextxy(10, 340, health[TempModi].date);
		//姓名
		outtextxy(200, 340, health[TempModi].temperature1);
		outtextxy(260, 340, "℃");
		//密码
		outtextxy(340, 340, health[TempModi].temperature2);
		outtextxy(400, 340, "℃");
		//邮箱
		outtextxy(480, 340, health[TempModi].temperature3);
		outtextxy(540, 340, "℃");
		//电话
		outtextxy(620, 340, health[TempModi].cough);

		if (strlen(health[TempModi].date) != 0 && strlen(health[TempModi].temperature1) != 0 && strlen(health[TempModi].temperature2) != 0 &&
			strlen(health[TempModi].temperature3) != 0 && strlen(health[TempModi].cough) != 0) {
			//保存文件
			SaveModifyHealth();
		}
		else {
			HWND SignError = GetHWnd();
			int isok = MessageBox(SignError, "请勿输入空语句！", "提示", MB_OK);
		}


		while (1) {
			Modi = GetMouseMsg();
			if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
				//返回
				setlinecolor(RED);

				rectangle(690, 590, 850, 640);
				if (Modi.uMsg == WM_LBUTTONDOWN) {
					cleardevice();
					//回到增删查改界面
					HealthRecord(flagNowStu);
				}
			}
			//鼠标不悬停
			else {
				setlinecolor(WHITE);
				rectangle(690, 590, 850, 640);

			}
		}
	}
}

//保存修改的健康数据
void SaveModifyHealth() {
	//先删掉，但是不将人数置空所以不能调用之前的删除函数
	//如果学号和姓名都不是空的才写入文件
	FILE* fp;
	fopen_s(&fp, "HealthFile.txt", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < NowHealthNums; i++) {
		fprintf(fp, "%-10s\t%-15s\t%-5s\t%-5s\t%-5s\t%-5s\n",
			health[i].ID,
			health[i].date,
			health[i].temperature1,
			health[i].temperature2,
			health[i].temperature3,
			health[i].cough);

	}
	fclose(fp);
}

//读取健康信息
void ReadHealth() {
	FILE* fp;
	fopen_s(&fp, "HealthFile.txt", "r");
	if (fp == NULL) {
		return;
	}
	//将文件中的数据读取到当前的结构体数组中
	for (int i = 0; i < n; i++) {
		fscanf_s(fp, "%s\t%s\t%s\t%s\t%s\t%s\n",
			health[i].ID, 10,
			health[i].date, len,
			health[i].temperature1, 5,
			health[i].temperature2, 5,
			health[i].temperature3, 5,
			health[i].cough, 5);
	}

	int FileHealthNums = 0;//辅助先得到文件中的人数
	//读取出文件中数据的人数个数
	for (int k = 0; k < n; k++) {
		if (strlen(health[k].ID) != 0) {
			NowHealthNums = ++FileHealthNums; //nowhealthnums是全局变量
		}
	}
	fclose(fp);
}

//用于某学生填写核酸检测情况
void TestRecord(int flagNowStu) {
	initgraph(760, 760);
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/secondbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "学" };
	char SecondTitle2[5] = { "生" };
	char SecondTitle3[5] = { "用" };
	char SecondTitle4[5] = { "户" };
	char SecondTitle5[5] = { "操" };
	char SecondTitle6[5] = { "作" };
	char SecondTitle7[5] = { "界" };
	char SecondTitle8[5] = { "面" };

	fillrectangle(50, 145, 100, 625);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);
	outtextxy(50, 570, SecondTitle8);

	setbkmode(TRANSPARENT);

	//3个选项的背景
	fillrectangle(230, 160, 560, 200);
	fillrectangle(230, 360, 560, 400);
	fillrectangle(230, 560, 560, 600);
	setbkmode(TRANSPARENT);

	setcolor(RED);
	settextstyle(30, 0, "宋体");
	char NowStuID[len] = "当前用户ID:";
	strcat_s(NowStuID, StuArry[flagNowStu].ID);
	outtextxy(450, 720, NowStuID);
	setcolor(WHITE);

	//3个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//学生界面的5个选项
	char FirstSelect1[20] = { "添加核酸检测情况" };
	char FirstSelect2[20] = { "修改核酸检测情况" };
	char FirstSelect3[20] = { "返回" };
	RECT R[3] = { {230, 160, 560, 200},{230, 360, 560, 400},{230, 560, 560, 600} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 160 && m2.y <= 200) {
			setlinecolor(RED);
			rectangle(230, 160, 560, 200);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//添加核酸检测情况
				InputTest(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 400) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 400);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//修改核酸检测情况
				ModifyTest(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 560 && m2.y <= 600) {
			setlinecolor(RED);
			rectangle(230, 560, 560, 600);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				StudentPage(flagNowStu);
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 160, 560, 200);
			rectangle(230, 360, 560, 400);
			rectangle(230, 560, 560, 600);
		}
	}
}

//录入核酸检测信息——通过弹窗输入
void InputTest(int flagNowStu) {
	//首先获得学生想填写的日期
	char date[15];
	TCHAR InputWindow0[] = _T("请输入核酸检测的日期");
	InputBox(date, 15, InputWindow0);

	//首先检测此学生的信息是否已经存在，若已存在则提示使用修改功能
	for (int i = 0; i < NowTestNums; i++) {
		if (strcmp(StuArry[flagNowStu].ID, test[i].ID) == 0 && strcmp(date, test[i].date) == 0) {
			HWND hwndInput1 = GetHWnd();
			int isok = MessageBox(hwndInput1, "你已经输入过这条核酸检测信息，请使用修改功能", "提示", MB_OK);
			HealthRecord(flagNowStu);
		}
	}
	//如果满足上述条件则进行下面的：
	strcpy_s(test[NowTestNums].ID, StuArry[flagNowStu].ID);
	strcpy_s(test[NowTestNums].date, date);
	TCHAR InputWindow1[] = _T("请输入你本次的核酸检测结果");
	InputBox(test[NowTestNums].result, 10, InputWindow1);

	SaveTest();
}

//保存核酸检测数据到文件中
void SaveTest() {
	if (strlen(test[NowTestNums].result) == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "请勿输入空语句!", "提示", MB_OK);
		return;
	}
	else {
		FILE* fp;
		fopen_s(&fp, "TestFile.txt", "a");
		if (fp == NULL) {
			return;
		}
		fprintf(fp, "%s\t%s\t%s\n",
			test[NowTestNums].ID,
			test[NowTestNums].date,
			test[NowTestNums].result);
		fclose(fp);
		NowTestNums++; //保存完毕人数++
	}
}

//找到核酸检测信息对应位置
int ReturnTestPosision(int flagNowStu) {
	//找到待修改的学号、日期对应的位置
	char ReceInput[64];
	TCHAR InputWindowFI[] = _T("请输入待修改项对应的日期");
	InputBox(ReceInput, 15, InputWindowFI);

	//进行循环查找，一旦相同就跳出循环
	for (int w = 0; w < NowTestNums; w++) {
		if (strcmp(test[w].date, ReceInput) == 0 && strcmp(StuArry[flagNowStu].ID, test[w].ID) == 0)//日期和ID都要一致才能修改
		{
			return w;
		}
	}
	//如果没找到这人就返回-1
	return -1;
}

//修改核酸检测信息
void ModifyTest(int flagNowStu) {
	int TempModi = ReturnTestPosision(flagNowStu);//定义一个变量用来接收下标
	if (TempModi == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsM = GetHWnd();
		int isok = MessageBox(hndtipsM, "没有您的核酸检测信息记录，请先填写健康信息!", "提示", MB_OK);
	}
	else//找到了这个学生进行下面的操作
	{
		cleardevice();		MOUSEMSG Modi;//鼠标操作
		initgraph(860, 760);

		IMAGE picture2;
		loadimage(&picture2, "images/secondbg.png", 860, 760);
		putimage(0, 0, &picture2);

		setfillcolor(GREEN);
		fillrectangle(690, 590, 850, 640);
		fillrectangle(10, 40, 850, 180);
		fillrectangle(10, 240, 850, 380);

		//表头文字部分
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "宋体");
		outtextxy(40, 40, "修改前");
		outtextxy(40, 240, "修改后");
		settextstyle(30, 0, "宋体");
		outtextxy(10, 100, "学号");
		outtextxy(200, 100, "日期");
		outtextxy(390, 100, "结果");
		outtextxy(740, 600, "返回");

		outtextxy(10, 300, "学号");
		outtextxy(200, 300, "日期");
		outtextxy(390, 300, "结果");

		setcolor(RED);
		settextstyle(30, 0, "宋体");
		char NowStuID[len] = "当前用户ID:";
		strcat_s(NowStuID, StuArry[flagNowStu].ID);
		outtextxy(450, 720, NowStuID);
		setcolor(WHITE);

		//打印被查找人的信息,修改前
		//日期
		outtextxy(10, 140, test[TempModi].ID);
		//体温
		outtextxy(200, 140, test[TempModi].date);

		outtextxy(390, 140, test[TempModi].result);

		//加入输入弹窗——重新书写内容
		//修改日期
		while (1) {
			char TempModiNums[64];//用于接收输入的日期，先覆盖进去
			TCHAR InputWindow0[] = _T("请输入修改后的日期");
			InputBox(TempModiNums, 15, InputWindow0);

			if (strcmp(TempModiNums, test[TempModi].date) == 0)//如果输入的日期和本身位置的日期相同,则结束修改日期这个循环
			{
				//不作出变化,直接break
				break;
			}
			else//如果输入的日期和本身位置的日期不同，则需要判断与整个结构体中是否有重复的
			{
				int nums = strlen(TempModiNums);
				//判断是否输入重复
				int FlagInput4 = 0;
				for (int i = 0; i < NowTestNums; i++) {
					if (strcmp(TempModiNums, test[i].date) == 0 && strcmp(test[i].ID, StuArry[flagNowStu].ID) == 0) {
						FlagInput4 = 1;
						break;
					}
				}
				if (FlagInput4 == 1) {
					//从老日期改到新日期，需要避免新日期与其它日期重复
					HWND hwndInput4 = GetHWnd();
					int isok = MessageBox(hwndInput4, "您输入的日期已经存在，请重新输入", "提示", MB_OK);
				}
				else if (FlagInput4 == 0) {
					//覆盖,memcpy用于内存赋值，可以复制各种数据类型（包括结构体），而strcpy只能复制字符串
					memcpy(test[TempModi].date, TempModiNums, 15);
					break;
				}

			}
		}
		//修改体温
		TCHAR InputWindow1[] = _T("请输入修改后检测结果");
		InputBox(test[TempModi].result, 10, InputWindow1);

		//打印被查找人的信息
		//学号
		outtextxy(10, 340, test[TempModi].ID);
		//姓名
		outtextxy(200, 340, test[TempModi].date);
		//密码
		outtextxy(390, 340, test[TempModi].result);

		//保存文件
		SaveModifyTest();

		while (1) {
			Modi = GetMouseMsg();
			if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
				//返回
				setlinecolor(RED);

				rectangle(690, 590, 850, 640);
				if (Modi.uMsg == WM_LBUTTONDOWN) {
					cleardevice();
					//回到增删查改界面
					TestRecord(flagNowStu);
				}
			}
			//鼠标不悬停
			else {
				setlinecolor(WHITE);
				rectangle(690, 590, 850, 640);

			}
		}
	}
}

//保存修改的核酸检测数据
void SaveModifyTest() {
	//先删掉，但是不将人数置空所以不能调用之前的删除函数
	//如果学号和姓名都不是空的才写入文件
	FILE* fp;
	fopen_s(&fp, "TestFile.txt", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < NowTestNums; i++) {
		fprintf(fp, "%s\t%s\t%s\n",
			test[i].ID,
			test[i].date,
			test[i].result);
	}
	fclose(fp);
}

//读取核酸检测信息
void ReadTest() {
	FILE* fp;
	fopen_s(&fp, "TestFile.txt", "r");
	if (fp == NULL) {
		return;
	}
	//将文件中的数据读取到当前的结构体数组中
	for (int i = 0; i < n; i++) {
		fscanf_s(fp, "%s\t%s\t%s\n",
			test[i].ID, 10,
			test[i].date, len,
			test[i].result, 10);
	}

	int FileTestNums = 0;//辅助先得到文件中的人数
	//读取出文件中数据的人数个数
	for (int k = 0; k < n; k++) {
		if (strlen(test[k].ID) != 0) {
			NowTestNums = ++FileTestNums; //nowhealthnums是全局变量
		}
	}
	fclose(fp);
}

用于某学生填写疫苗接种情况
void VaccineRecord(int flagNowStu) {
	initgraph(760, 760);
	cleardevice();
	MOUSEMSG m2;//定义第二个鼠标操作
	cleardevice();

	IMAGE picture1;
	loadimage(&picture1, "images/secondbg.png", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "学" };
	char SecondTitle2[5] = { "生" };
	char SecondTitle3[5] = { "用" };
	char SecondTitle4[5] = { "户" };
	char SecondTitle5[5] = { "操" };
	char SecondTitle6[5] = { "作" };
	char SecondTitle7[5] = { "界" };
	char SecondTitle8[5] = { "面" };

	fillrectangle(50, 145, 100, 625);
	settextstyle(50, 0, "宋体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);
	outtextxy(50, 570, SecondTitle8);

	setbkmode(TRANSPARENT);

	//3个选项的背景
	fillrectangle(230, 160, 560, 200);
	fillrectangle(230, 360, 560, 400);
	fillrectangle(230, 560, 560, 600);
	setbkmode(TRANSPARENT);

	setcolor(RED);
	settextstyle(30, 0, "宋体");
	char NowStuID[len] = "当前用户ID:";
	strcat_s(NowStuID, StuArry[flagNowStu].ID);
	outtextxy(450, 720, NowStuID);
	setcolor(WHITE);

	//3个选项的文字
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    //设置输出效果为抗锯齿，不会那么模糊
	f.lfHeight = 40;					//设置字体大小
	settextstyle(&f);                     // 设置字体样式

	//学生界面的5个选项
	char FirstSelect1[20] = { "添加疫苗接种情况" };
	char FirstSelect2[20] = { "修改疫苗接种情况" };
	char FirstSelect3[20] = { "返回" };
	RECT R[3] = { {230, 160, 560, 200},{230, 360, 560, 400},{230, 560, 560, 600} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//进入主界面选项操作界面
	while (1) {
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 160 && m2.y <= 200) {
			setlinecolor(RED);
			rectangle(230, 160, 560, 200);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//添加核酸检测情况
				InputVaccine(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 360 && m2.y <= 400) {
			setlinecolor(RED);
			rectangle(230, 360, 560, 400);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//修改核酸检测情况
				ModifyVaccine(flagNowStu);
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 560 && m2.y <= 600) {
			setlinecolor(RED);
			rectangle(230, 560, 560, 600);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				//返回
				cleardevice();
				StudentPage(flagNowStu);
			}
		}
		//鼠标不在上面悬停
		else {
			setlinecolor(WHITE);
			rectangle(230, 160, 560, 200);
			rectangle(230, 360, 560, 400);
			rectangle(230, 560, 560, 600);
		}
	}
}

//录入疫苗接种信息——通过弹窗输入
void InputVaccine(int flagNowStu) {
	//首先获得学生想填写的日期
	char date[15];
	TCHAR InputWindow0[] = _T("请输入接种疫苗的日期");
	InputBox(date, 15, InputWindow0);

	//首先检测此学生的信息是否已经存在，若已存在则提示使用修改功能
	for (int i = 0; i < NowVaccineNums; i++) {
		if (strcmp(StuArry[flagNowStu].ID, vaccine[i].ID) == 0 && strcmp(date, vaccine[i].date) == 0) {
			HWND hwndInput1 = GetHWnd();
			int isok = MessageBox(hwndInput1, "你已经输入过这条核酸检测信息，请使用修改功能", "提示", MB_OK);
			HealthRecord(flagNowStu);
		}
	}
	//如果满足上述条件则进行下面的：
	strcpy_s(vaccine[NowVaccineNums].ID, StuArry[flagNowStu].ID);
	strcpy_s(vaccine[NowVaccineNums].date, date);
	TCHAR InputWindow1[] = _T("请输入你本次的疫苗接种型号");
	InputBox(vaccine[NowVaccineNums].type, 10, InputWindow1);

	SaveVaccine();
}

//保存疫苗接种数据到文件中
void SaveVaccine() {
	if (strlen(vaccine[NowVaccineNums].type) == 0) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "请勿输入空语句!", "提示", MB_OK);
		return;
	}
	else {
		FILE* fp;
		fopen_s(&fp, "VaccineFile.txt", "a");
		if (fp == NULL) {
			return;
		}
		fprintf(fp, "%s\t%s\t%s\n",
			vaccine[NowVaccineNums].ID,
			vaccine[NowVaccineNums].date,
			vaccine[NowVaccineNums].type);
		fclose(fp);
		NowVaccineNums++; //保存完毕人数++
	}
}

//找到疫苗接种信息对应位置
int ReturnVaccinePosision(int flagNowStu) {
	//找到待修改的学号、日期对应的位置
	char ReceInput[64];
	TCHAR InputWindowFI[] = _T("请输入待修改项对应的日期");
	InputBox(ReceInput, 15, InputWindowFI);

	//进行循环查找，一旦相同就跳出循环
	for (int w = 0; w < NowVaccineNums; w++) {
		if (strcmp(vaccine[w].date, ReceInput) == 0 && strcmp(StuArry[flagNowStu].ID, vaccine[w].ID) == 0)//日期和ID都要一致才能修改
		{
			return w;
		}
	}
	//如果没找到这人就返回-1
	return -1;
}

//修改疫苗接种信息
void ModifyVaccine(int flagNowStu) {
	int TempModi = ReturnVaccinePosision(flagNowStu);//定义一个变量用来接收下标
	if (TempModi == -1)//没找到
	{
		//获取窗口句柄
		HWND hndtipsM = GetHWnd();
		int isok = MessageBox(hndtipsM, "没有您的核酸检测信息记录，请先填写健康信息!", "提示", MB_OK);
	}
	else//找到了这个学生进行下面的操作
	{
		cleardevice();		MOUSEMSG Modi;//鼠标操作
		initgraph(860, 760);

		IMAGE picture2;
		loadimage(&picture2, "images/secondbg.png", 860, 760);
		putimage(0, 0, &picture2);

		setfillcolor(GREEN);
		fillrectangle(690, 590, 850, 640);
		fillrectangle(10, 40, 850, 180);
		fillrectangle(10, 240, 850, 380);

		//表头文字部分
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "宋体");
		outtextxy(40, 40, "修改前");
		outtextxy(40, 240, "修改后");
		settextstyle(30, 0, "宋体");
		outtextxy(10, 100, "学号");
		outtextxy(200, 100, "日期");
		outtextxy(390, 100, "结果");
		outtextxy(740, 600, "返回");

		outtextxy(10, 300, "学号");
		outtextxy(200, 300, "日期");
		outtextxy(390, 300, "结果");

		setcolor(RED);
		settextstyle(30, 0, "宋体");
		char NowStuID[len] = "当前用户ID:";
		strcat_s(NowStuID, StuArry[flagNowStu].ID);
		outtextxy(450, 720, NowStuID);
		setcolor(WHITE);

		//打印被查找人的信息,修改前
		//日期
		outtextxy(10, 140, vaccine[TempModi].ID);
		//体温
		outtextxy(200, 140, vaccine[TempModi].date);

		outtextxy(390, 140, vaccine[TempModi].type);

		//加入输入弹窗——重新书写内容
		//修改日期
		while (1) {
			char TempModiNums[64];//用于接收输入的日期，先覆盖进去
			TCHAR InputWindow0[] = _T("请输入修改后的日期");
			InputBox(TempModiNums, 15, InputWindow0);

			if (strcmp(TempModiNums, vaccine[TempModi].date) == 0)//如果输入的日期和本身位置的日期相同,则结束修改日期这个循环
			{
				//不作出变化,直接break
				break;
			}
			else//如果输入的日期和本身位置的日期不同，则需要判断与整个结构体中是否有重复的
			{
				int nums = strlen(TempModiNums);
				//判断是否输入重复
				int FlagInput4 = 0;
				for (int i = 0; i < NowVaccineNums; i++) {
					if (strcmp(TempModiNums, vaccine[i].date) == 0 && strcmp(vaccine[i].ID, StuArry[flagNowStu].ID) == 0) {
						FlagInput4 = 1;
						break;
					}
				}
				if (FlagInput4 == 1) {
					//从老日期改到新日期，需要避免新日期与其它日期重复
					HWND hwndInput4 = GetHWnd();
					int isok = MessageBox(hwndInput4, "您输入的日期已经存在，请重新输入", "提示", MB_OK);
				}
				else if (FlagInput4 == 0) {
					//覆盖,memcpy用于内存赋值，可以复制各种数据类型（包括结构体），而strcpy只能复制字符串
					memcpy(vaccine[TempModi].date, TempModiNums, 15);
					break;
				}

			}
		}
		//修改体温
		TCHAR InputWindow1[] = _T("请输入修改后的接种型号");
		InputBox(vaccine[TempModi].type, 10, InputWindow1);

		//打印被查找人的信息
		//学号
		outtextxy(10, 340, vaccine[TempModi].ID);
		//姓名
		outtextxy(200, 340, vaccine[TempModi].date);
		//密码
		outtextxy(390, 340, vaccine[TempModi].type);

		//保存文件
		SaveModifyVaccine();

		while (1) {
			Modi = GetMouseMsg();
			if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640) {
				//返回
				setlinecolor(RED);

				rectangle(690, 590, 850, 640);
				if (Modi.uMsg == WM_LBUTTONDOWN) {
					cleardevice();
					//回到增删查改界面
					VaccineRecord(flagNowStu);
				}
			}
			//鼠标不悬停
			else {
				setlinecolor(WHITE);
				rectangle(690, 590, 850, 640);

			}
		}
	}
}

//保存修改的疫苗接种数据
void SaveModifyVaccine() {
	//先删掉，但是不将人数置空所以不能调用之前的删除函数
	//如果学号和姓名都不是空的才写入文件
	FILE* fp;
	fopen_s(&fp, "VaccineFile.txt", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < NowVaccineNums; i++) {
		fprintf(fp, "%s\t%s\t%s\n",
			vaccine[i].ID,
			vaccine[i].date,
			vaccine[i].type);
	}
	fclose(fp);
}

//读取疫苗接种信息
void ReadVaccine() {
	FILE* fp;
	fopen_s(&fp, "VaccineFile.txt", "r");
	if (fp == NULL) {
		return;
	}
	//将文件中的数据读取到当前的结构体数组中
	for (int i = 0; i < n; i++) {
		fscanf_s(fp, "%s\t%s\t%s\n",
			vaccine[i].ID, 10,
			vaccine[i].date, len,
			vaccine[i].type, 10);
	}

	int FileVaccineNums = 0;//辅助先得到文件中的人数
	//读取出文件中数据的人数个数
	for (int k = 0; k < n; k++) {
		if (strlen(test[k].ID) != 0) {
			NowVaccineNums = ++FileVaccineNums; //nowhealthnums是全局变量
		}
	}
	fclose(fp);
}



int main() {
	FirstPage();
	system("pause");
	return 0;
}
