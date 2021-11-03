#include "school.h"
#include <QCoreApplication>
//读名字
School::School()
{
    QString s=QCoreApplication::applicationDirPath()+"/names2.txt";
    ifstream in(s.toStdString().c_str());
    int t = 0;
    if (in) while (getline(in, names[t])&&t<8999) t++;
    else qDebug() << "no such file" ;
    Init();
    sections[0] = "null";
    topNum=0;
}
//判断该部门中是否已有主管
int School::ifUG(int sName) {
    PNode* pp = sec[sName].man;
    while (pp) {
        if (pp->grade == 0) return 1;
        pp = pp->next;
    }
    return 0;
}
//判断该部门是否已存在
int School::ifUD(string s) {
    for(int i=0;i<100;i++) {
        if((!sec[i].ifEm)&&sections[sec[i].name]==s) return 1;
    }
    return 0;
}
//人和部门双向插入
int School::InsertSec(int perName, int sName, int grade) {
    if (ifUG(sName) && (!grade)) return 0;//确保主管只有一个
    PNode* newPNode = new struct PNode;
    newPNode->secOrPerName = sName;
    newPNode->grade = grade;
    newPNode->next = NULL;
    PNode* p = per[perName].secs;
    if (p == NULL) per[perName].secs = newPNode;
    else {
        while (p->next != NULL) p = p->next;
        p->next = newPNode;
    }
    per[perName].secNum++;

    sec[sName].manNum++;
    PNode* newNode = new struct PNode;
    newNode->secOrPerName= perName;
    newNode->grade = grade;
    newNode->next = NULL;
    PNode* pp = sec[sName].man;
    if (pp == NULL) sec[sName].man = newNode;
    else {
        while (pp->next != NULL) pp = pp->next;
        pp->next = newNode;
    }
    return 1;
}
//初始化
void School::Init(){
    secNum = 1;
    for (int i = 0; i < 100; i++) {
        sec[i].ifEm = 1,sec[i].mom = -1,sec[i].name = -1;
        sec[i].nexNum = 0,sec[i].manNum = 0;
        sec[i].son= new SNode;
        sec[i].son= NULL;
        sec[i].man = new PNode;
        sec[i].man = NULL;
    }
    sec[0].ifEm = 0,sec[0].name = 0;//初始化NULL
    pnum = 9000;//既有人员9000人
    for (int i = 0; i < pnum; i++)
        per[i].name = i, per[i].secs = NULL, per[i].secNum = 0;
}
//初始化某一部门
void School::InitS(Sec &s) {
    if (s.ifEm) {
        s.mom = -1, s.nexNum = 0;
        SNode* p = s.son;
        PNode* p1 = s.man;
        while (p) {
            SNode* temp = p;
            p = p->next;
            delete temp;
        }
        while (p1) {
            PNode* temp1 = p1;
            p1 = p1->next;
            delete temp1;
        }
        p=NULL,p1=NULL;
        s.son= new SNode;
        s.son = NULL;
        s.man= new PNode;
        s.man = NULL;

        s.nexNum = 0, s.manNum = 0;
    }
}
//插入部门
int School::Insert(int parentName, int sName) {
    if(parentName==0) topNum++;
    secNum++;
    int temp = -1, mom=-1, ret=-1;
    for (int i = 0; i < 100; i++) {
        if (sec[i].ifEm&&(temp==-1)) temp = i,ret=i;
        if (sec[i].name == parentName&&(mom==-1)) mom = i;
        if ((temp != -1) && (mom != -1)) break;
    }
    InitS(sec[temp]);
    sec[temp].ifEm = 0;
    sec[temp].name = sName;
    sec[temp].mom = mom;
    sec[mom].nexNum++;
    SNode* newNode = new struct SNode;
    newNode->data = temp;
    newNode->next = NULL;
    SNode* p = sec[mom].son;
    if (p == NULL) sec[mom].son = newNode;
    else {
        while (p->next != NULL) p = p->next;
        p->next = newNode;
    }
    return ret;
}
//删除部门
int School::Dele(int sName) {
    int ret;
    for (int i = 0; i < 100; i++) {
        if (sec[i].name == sName) {          
            PNode* pp = sec[i].man;//删除下面的员工
            while(pp) {
                PNode* pp1 = per[pp->secOrPerName].secs;
                per[pp->secOrPerName].secNum--;
                if (pp1->secOrPerName == sName) {
                    if(pp1->next==NULL) per[pp->secOrPerName].secs=NULL;
                    else per[pp->secOrPerName].secs=pp1->next;
                }
                else {
                    while (pp1->next->secOrPerName != sName) pp1 = pp1->next;
                    pp1->next = pp1->next->next;
                }
                pp=pp->next;
            }
            SNode* p = sec[sec[i].mom].son;//删除妈妈的儿子
            ret=sec[i].mom;
            if(sec[i].mom==0) topNum--;
            if (p->data == i) {
                if(p->next==NULL) sec[sec[i].mom].son=NULL;
                else sec[sec[i].mom].son=p->next;
            }
            else {
                while (p->next->data != i) p = p->next;
                p->next = p->next->next;
            }
            sec[sec[i].mom].nexNum--;
            SNode* p1 = sec[i].son;//删除自己的儿子
            while (p1) {
                sec[p1->data].ifEm = 1;
                InitS(sec[p1->data]);
                p1 = p1->next;
            }
            SNode* ttt = sec[0].son;
            while(ttt!=NULL) {
                qDebug()<<QString::fromStdString(sections[sec[ttt->data].name]);
                ttt=ttt->next;
            }
            sec[i].ifEm = 1;//删除自己
            InitS(sec[i]);
            return ret;
        }
    }
}
//返回名字在names[i]中的下标
int School::retNameIndex(string s) {
    for (int i = 0; i < 9999; i++) {
        if (names[i] == s) return i;
    }
    return -1;//查无此人
}
//搜索一个人的部门和该部门下的职位
void School::Search(string s) {
    PNode* pp = per[retNameIndex(s)].secs;
    while(pp) {
        cout << sections[pp->secOrPerName] << " " << grades[pp->grade] << endl;
        pp = pp->next;
    }
}
//返回部门在sections[i]中的下标
int School::nameInt(string s1) {
    for (int i = 0; i < 100; i++) if (sections[i] == s1) return i;
}
//是否唯一
int School::ifUP(string name) {
    for (int i = 0; i < pnum; i++) if (names[i] == name) return 0;
    return 1;
}
//加人
int School::AddP(string name) {
    for(int i=0;i<pnum;i++){
        if(names[i]==name) return -1;
    }
    if (ifUP(name)) {
        names[pnum++] = name;
        return 1;
    }
    else return 0;
}

int School::Fdata(string sn) {
    for (int i = 0; i < 100; i++) {
        if (sections[sec[i].name] == sn) return i;
    }
    return -1;
}
