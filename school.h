#ifndef SCHOOL_H
#define SCHOOL_H
#include <string>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QFrame>
#include <QGraphicsOpacityEffect>
#include <QPushButton>
#include <QTimer>
//部门指针
using namespace std;
struct SNode {
    int data;
    struct SNode* next;
};
//人员指针
struct PNode {
    int grade;
    int secOrPerName;
    struct PNode* next;
};
//部门节点
struct Sec {
    bool ifEm;
    int name;//名称编号
    int mom;
    struct SNode* son;
    int nexNum;
    struct PNode* man;
    int manNum;
};
//人员节点
struct Per {
    int name;
    struct PNode* secs;
    int secNum;
};
//学校类
class School {
public:
    School();
    Sec sec[100];
    Per per[10000];
    string sections[100];
    string names[10000];
    string grades[3] = { "主管","副主管","其他人员" };
    int secNum;
    int topNum;
    int pnum;
    int ifUG(int sName);
    //人和部门互插
    int InsertSec(int perName, int sName, int grade);
    //初始化
    void Init();
    //初始化某一部门
    void InitS(Sec &s);
    //插入部门
    int Insert(int parentName, int sName);
    //删除部门
    int Dele(int sName);
    //返回名字在names[i]中的下标
    int retNameIndex(string s);
    //搜索一个人的部门和该部门下的职位
    void Search(string s);
    //返回部门在sections[i]中的下标
    int nameInt(string s1);
    //是否唯一
    int ifUP(string name);
    //加人
    int AddP(string name);
    //
    int Fdata(string sn);
    //判断该部门是否已存在
    int ifUD(string s);
};

#endif // SCHOOL_H
