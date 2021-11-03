#include "widget.h"
#include "ui_widget.h"
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    s=new Speci;
    s1=new Speci;
    a=new adds;
    ifTop=0,curr=-1,curr2=-1;
    //for(int i=0;i<9000;i++) {
        //if(!sc.names[i].empty()) ui->edit->append(QString::asprintf("%d",i)+QString::fromStdString(sc.names[i]));
    //}
    //初始化
    int tn=0;
    string stop[5]={"院系总览","党群机构","行政机构","直属单位","附属单位"};
    int pName = sc.nameInt("null");
    for(int i=0;i<5;i++) {
        sc.sections[sc.secNum] = stop[i];
        sc.Insert(pName, sc.secNum);
    }
    string stemp[42]={
        "新生院","建筑与城市规划学院","土木工程学院","机械与能源工程学院","经济与管理学院","环境科学与工程学院","材料科学与工程学院","电子与信息工程学院","人文学院","外国语学院",
        "纪律检查委员会","党委办公室","组织部","党校","宣传部","统战部","教师工作部","学生工作部","保卫部","武装部",
        "校长办公室","宣传处","发展规划部","审计处","本科生院","监察处","招生办公室","基建处","研究生院","资产与实验室管理处",
        "同济大学中德学院","同济大学档案馆","同济大学继续教育学院","同济大学出版社","同济大学校史馆","同济大学中芬中心","同济大学高等研究院","同济大学新闻中心","同济大学中德学部","同济大学图书馆",
        "同济医院","同济大学附属口腔医院"
    };
    pName = sc.nameInt("院系总览");
    for(int i=0;i<10;i++) {
        sc.sections[sc.secNum] = stemp[i];
        sc.Insert(pName, sc.secNum);
        sc.InsertSec(sc.retNameIndex(sc.names[tn++]), sc.nameInt(stemp[i]),0);
    }
    pName = sc.nameInt("党群机构");
    for(int i=10;i<20;i++) {
        sc.sections[sc.secNum] = stemp[i];
        sc.Insert(pName, sc.secNum);
        sc.InsertSec(sc.retNameIndex(sc.names[tn++]), sc.nameInt(stemp[i]),0);
    }
    pName = sc.nameInt("行政机构");
    for(int i=20;i<30;i++) {
        sc.sections[sc.secNum] = stemp[i];
        sc.Insert(pName, sc.secNum);
        sc.InsertSec(sc.retNameIndex(sc.names[tn++]), sc.nameInt(stemp[i]),0);
    }
    pName = sc.nameInt("直属单位");
    for(int i=30;i<40;i++) {
        sc.sections[sc.secNum] = stemp[i];
        sc.Insert(pName, sc.secNum);
        sc.InsertSec(sc.retNameIndex(sc.names[tn++]), sc.nameInt(stemp[i]),0);
    }
    pName = sc.nameInt("附属单位");
    for(int i=40;i<42;i++) {
        sc.sections[sc.secNum] = stemp[i];
        sc.Insert(pName, sc.secNum);
        sc.InsertSec(sc.retNameIndex(sc.names[tn++]), sc.nameInt("党委办公室"),1);
    }
    int tin;
    for(int i=0;i<42;i++){
        tin=rand()%(50-i);
        sc.InsertSec(sc.retNameIndex(sc.names[i]), tin+i,rand()%2+1);
    }
    for(int i=42;i<1000;i++){
        tin=rand()%40;
        sc.InsertSec(sc.retNameIndex(sc.names[i]), tin+5,rand()%2+1);
        sc.InsertSec(sc.retNameIndex(sc.names[i]), tin+6,rand()%2+1);
        sc.InsertSec(sc.retNameIndex(sc.names[i]), tin+10,rand()%2+1);
    }
    for(int i=1000;i<9000;i++){
        tin=rand()%30;
        sc.InsertSec(sc.retNameIndex(sc.names[i]), tin+10,rand()%2+1);
        sc.InsertSec(sc.retNameIndex(sc.names[i]), tin+20,rand()%2+1);
    }
    //sc.InsertSec(sc.retNameIndex("王明德"), sc.nameInt("党委办公室"),1);
    //sc.InsertSec(sc.retNameIndex("王明德"), sc.nameInt("新生院"), 0);
    //sc.InsertSec(sc.retNameIndex("秦明辉"), sc.nameInt("新生院"), 2);

    myf= new QFrame(this);
    myf->setGeometry(30,35,200,600);
    myf->setStyleSheet("QFrame{"
                       "background-color:#415a77;"
                       "border-radius:10px;"
                       "}");
    setTable(myf,10,1,1);
    newTable(myf,0,10);

    spcf= new QFrame(this);
    spcf->setGeometry(250,60,590,575);
    spcf->setStyleSheet("QFrame{"
                       "background-color:#415a77;"
                       "border-radius:10px;"
                       "}");
    setTable(spcf,50,2,0);
    IFTable(spcf,10);
    IFTable1(myf,sc.topNum);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(addNew()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Del()));
    timer->start(100);
}
//析构函数
Widget::~Widget() {
    delete ui;
}
//初始化
void Widget::setTable(QFrame*f,int x,int y,int color) {
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            mb *bt = new mb(f);           
            if(color){
                bt->setGeometry(j*108, i*58, 200, 58);
                bt->setStyleSheet(
                            "QPushButton{"
                                "background-color:#bfdbf7;"
                                "border-style:outset;"
                                "border-width:4px;"
                                "border-radius:19px;"
                                "border-color:rgba(255,255,255,30);"
                                "font:bold 24px;"
                                "color:rgba(54,37,17,200);"
                                "padding:6px;"
                                "}"
                                "QPushButton:pressed{"
                                "background-color:#e1e5f2;"
                                "border-color:rgba(255,255,255,30);"
                                "border-style:inset;"
                                "color:rgba(0,0,0,100);"
                                "}"
                                "QPushButton:hover{"
                                "background-color:#e1e5f2;"
                                "border-color:rgba(255,255,255,200);"
                                "color:rgba(0,0,0,200);"
                                "}"
                            );
            }
            else {
                    bt->setGeometry(j*280+20, i*63+20, 270,58);
                    bt->setStyleSheet(
                            "QPushButton{"
                                "background-color:#bfdbf7;"
                                "border-style:outset;"
                                "border-width:4px;"
                                "border-radius:19px;"
                                "border-color:rgba(255,255,255,30);"
                                "font:bold 24px;"
                                "color:rgba(54,37,17,200);"
                                "padding:6px;"
                                "}"
                                "QPushButton:pressed{"
                                "background-color:#e1e5f2;"
                                "border-color:rgba(255,255,255,30);"
                                "border-style:inset;"
                                "color:rgba(0,0,0,100);"
                                "}"
                                "QPushButton:hover{"
                                "background-color:#e1e5f2;"
                                "border-color:rgba(255,255,255,200);"
                                "color:rgba(0,0,0,200);"
                                "}"
                            );
            }
            QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
            bt->setGraphicsEffect(opacityEffect);
            opacityEffect->setOpacity(0);
            bt->setEnabled(false);
        }
    }
}
//更新子部门界面
void Widget::newTable(QFrame*f,int which,int cou){
    int i=0;
    SNode* pp = sc.sec[which].son;
    mb *bt = (mb *)(f->children().at(i));
    while (pp != NULL) {
        bt->setText(QString::fromStdString(sc.sections[sc.sec[pp->data].name]));
        QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
        bt->setGraphicsEffect(opacityEffect);
        opacityEffect->setOpacity(1);
        bt->setEnabled(true);
        pp = pp->next;
        i++;
        bt = (mb *)(f->children().at(i));
    }
    for(;i<cou;i++){
        bt = (mb *)(f->children().at(i));
        bt->setText("");
        QGraphicsOpacityEffect *opacityEffect1=new QGraphicsOpacityEffect;
        bt->setGraphicsEffect(opacityEffect1);
        opacityEffect1->setOpacity(0);
        bt->setEnabled(false);
    }
}
//显示部门人员
void Widget::IFTable(QFrame*f,int cou) {
    for(int i=0;i<cou;i++) {
        mb *bt = (mb *)(f->children().at(i));
        connect(bt,&mb::clicked,[=]() {
               s->model = new QStandardItemModel(s);
               s->model->setColumnCount(2);
               s->model->setHeaderData(0,Qt::Horizontal, "姓名");
               s->model->setHeaderData(1,Qt::Horizontal, "职务");
               s->model->setRowCount(100);
               int te=0;
               PNode* pp = sc.sec[sc.Fdata(bt->text().toStdString())].man;
               curr2=sc.Fdata(bt->text().toStdString());
               while (pp != NULL) {
                   s->model->setItem(te,0, new QStandardItem(QString::fromStdString(sc.names[pp->secOrPerName])));
                   s->model->item(te,0)->setTextAlignment(Qt::AlignCenter);
                   s->model->setItem(te,1, new QStandardItem(QString::fromStdString(sc.grades[pp->grade])));
                   s->model->item(te,1)->setTextAlignment(Qt::AlignCenter);
                   pp = pp->next;
                   te++;
               }
               s->setModel(s->model);
               s->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
               s->show();
        });
    }
}
//点击后显示子部门
void Widget::IFTable1(QFrame*f,int cou) {
    for(int i=0;i<cou;i++) {
        mb *bt = (mb *)(f->children().at(i));
        connect(bt,&mb::clicked,[=]() {
           curr=sc.Fdata(bt->text().toStdString());
           newTable(spcf,sc.Fdata(bt->text().toStdString()),100);
        });
    }
}
//删除部门
void Widget::Del() {
    for(int i=0;i<sc.topNum;i++) {//删除顶层部门
        mb * bt = (mb *)(myf->children().at(i));
        if(bt->ifDe==1) {
            sc.Dele(sc.nameInt(bt->text().toStdString()));
            newTable(myf,0,10);
            setTable(spcf,10,10,0);
            bt->ifDe=0;
        }
    }
    for(int i=0;i<100;i++) {//删除子部门
        mb * bt = (mb *)(spcf->children().at(i));
        if(bt->ifDe==1) {
            curr=sc.Dele(sc.nameInt(bt->text().toStdString()));
            newTable(spcf,curr,100);
            bt->ifDe=0;
        }
    }
}
//添加后更新部门人员
void Widget::newIFTable(int cur) {
    s->model = new QStandardItemModel(s);
    s->model->setColumnCount(2);
    s->model->setHeaderData(0,Qt::Horizontal, "姓名");
    s->model->setHeaderData(1,Qt::Horizontal, "职务");
    s->model->setRowCount(100);
   int te=0;
   PNode* pp = sc.sec[cur].man;
   while (pp != NULL) {
       s->model->setItem(te,0, new QStandardItem(QString::fromStdString(sc.names[pp->secOrPerName])));
       s->model->setItem(te,1, new QStandardItem(QString::fromStdString(sc.grades[pp->grade])));
       pp = pp->next;
       te++;
   }
   s->setModel(s->model);
   s->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
   s->show();
}
//添加顶层部门
void Widget::on_a1_clicked() {
    a->show();
    a->ifClose=0;
    ifTop=1;
}
//添加子部门
void Widget::on_a2_clicked() {
    a->show();
    a->ifClose=0;
    ifTop=0;
}
//添加新部门
void Widget::addNew() {
    if(a->ifClose==1){
        if(ifTop){
            sc.sections[sc.secNum] = a->s.toStdString();

            if(sc.ifUD(a->s.toStdString())) QMessageBox::about(NULL, "About", "添加失败，该部门已存在！");
            else{
                curr=sc.Insert(sc.nameInt("null"), sc.secNum);
                newTable(myf,0,10);
                newTable(spcf,curr,100);
                IFTable1(myf,sc.topNum);
            }
        }
        else{
            sc.sections[sc.secNum] = a->s.toStdString();           
            if(sc.ifUD(a->s.toStdString()))
                QMessageBox::about(NULL, "About", "添加失败，该部门已存在！");
            else{
                int curr0=sc.Insert(sc.sec[curr].name,sc.secNum);
                newTable(spcf,curr,100);
                IFTable(spcf,sc.sec[curr0].nexNum);
            }
        }
        a->ifClose=0;
    }
    if(s->p->ifClose==1){
        if(s->p->ifNew) if(sc.AddP(s->p->s.toStdString())==-1) QMessageBox::about(NULL, "About", "添加失败，该人名已存在！");
        if(!s->p->ifNew) if(sc.AddP(s->p->s.toStdString())==1) QMessageBox::about(NULL, "About", "成功添加为新员工！");
        if(!sc.InsertSec(sc.retNameIndex(s->p->s.toStdString()),curr2,s->p->gra)) QMessageBox::about(NULL, "About", "添加失败，该部门已有主管！");
        newIFTable(curr2);
        IFTable(spcf,10);
        s->p->ifClose=0;
    }
}
//显示搜索结果
void Widget::find() {
    if(sc.retNameIndex(ui->who->text().toStdString())==-1) QMessageBox::about(NULL, "About", "查无此人！");
    else{
        PNode* pp = sc.per[sc.retNameIndex(ui->who->text().toStdString())].secs;
        s1->model = new QStandardItemModel(s1);
        s1->model->setColumnCount(2);
        s1->model->setHeaderData(0,Qt::Horizontal, "所在部门");
        s1->model->setHeaderData(1,Qt::Horizontal, "职务");
        s1->model->setRowCount(100);
        int te=0;
        while(pp) {
            s1->model->setItem(te,0, new QStandardItem(QString::fromStdString(sc.sections[pp->secOrPerName])));
            s1->model->item(te,0)->setTextAlignment(Qt::AlignCenter);
            s1->model->setItem(te,1, new QStandardItem(QString::fromStdString(sc.grades[pp->grade])));
            s1->model->item(te,1)->setTextAlignment(Qt::AlignCenter);
            pp = pp->next,te++;
        }
        s1->setModel(s1->model);
        s1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        s1->show();
    }
}
//搜索槽函数
void Widget::on_find_clicked() {
    find();
}
