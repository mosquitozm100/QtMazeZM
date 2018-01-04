#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<iostream>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QMouseEvent>
#include<time.h>
#include<QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene())
{
    ui->setupUi(this);
    connect(ui->generate_maze,QPushButton::clicked,this,get_maze);
    connect(ui->generate_answer1,QPushButton::clicked,this,get_path1);
    connect(ui->generate_answer2,QPushButton::clicked,this,get_path2);
    connect(ui->col_input,QLineEdit::textChanged,this,init);
    connect(ui->row_input,QLineEdit::textChanged,this,init);
    ui->show_maze->setScene(scene);
    scene->setSceneRect(0,0,580,580);

    W = scene->width();
    H = scene->height();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::init(){
    col = ui->col_input->text().toInt();
    row = ui->row_input->text().toInt();
}

void MainWindow::draw()
{
    if(true)
    {
        if(hasItems())
        {
            scene->clear();
        }
        scene->clear();
        QGraphicsLineItem *fl;
        QGraphicsRectItem *fr;
        qreal w = W / col;
        qreal h = H / row;
        qreal step = 0;
        for(int i=0;i<=row;i++){
            fl = new QGraphicsLineItem(0,step,W,step);
            scene->addItem(fl);
            step = step + h;
        }

        step = 0;
        for(int i=0;i<=col;i++){
            fl = new QGraphicsLineItem(step,0,step,H);
            scene->addItem(fl);
            step = step + w;
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(maze[i][j]==0){
                    fr = new QGraphicsRectItem(QRectF(w*j,i*h,w,h));
                    fr->setBrush(Qt::gray);
                    scene->addItem(fr);
                }
                else if(maze[i][j] == 1){
                        fr = new QGraphicsRectItem(QRectF(w*j,i*h,w,h));
                        fr->setBrush(Qt::white);
                        scene->addItem(fr);
                }
                else if(maze[i][j] == -1) {
                    fr = new QGraphicsRectItem(QRectF(w*j,i*h,w,h));
                    fr->setBrush(Qt::blue);
                    scene->addItem(fr);
                }
                else if(maze[i][j] == -2) {
                    fr = new QGraphicsRectItem(QRectF(w*j,i*h,w,h));
                    fr->setBrush(Qt::red);
                    scene->addItem(fr);
                }
            }
        isClear = false;
    }
}
int MainWindow::find(int x) {return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
int MainWindow::getOP(int x) {return x * 2 - 1;}
void MainWindow::make_maze(int nrow, int ncol)
{
    //preparation and initialization
    memset(maze,0,sizeof(maze));
    record.clear();
    int m = 0;
    for(int i = 1;i <= nrow;i++){
        for(int j = 1;j <= ncol;j++){
            m++;
            p[m] = make_pair(i,j);
            map1[p[m]] = m;
        }
    }
    memset(fa,0,sizeof(fa));
    for(int i = 1;i <= m;i++) fa[i] = i;
    int numOfEdges = 0;
    for(int i = 1;i <= m;i++){
        int nx = p[i].first, ny = p[i].second + 1;
        if(nx <= nrow && ny <= ncol) {
            edges[numOfEdges++] = make_pair(i,map1[make_pair(nx,ny)]);
        }
        nx = p[i].first + 1; ny = p[i].second;
        if(nx <= nrow && ny <= ncol) {
            edges[numOfEdges++] = make_pair(i,map1[make_pair(nx,ny)]);
        }
    }

    //random
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    shuffle(edges, edges + numOfEdges,default_random_engine (seed));

    //get spanning tree
    int cnt = m,i = 0;
    while(cnt > 1){
        int x = find(edges[i].first), y = find(edges[i].second);
        if(x != y) {fa[x] = y;cnt--;record.push_back(edges[i]);}
        i++;
    }

    //save results
    memset(maze,0,sizeof(maze));
    for(int i = 1;i <= m;i++) {
        maze[getOP(p[i].first)][getOP(p[i].second)] = 1;
    }
    for(int i = 0;i < record.size();i++){
        int a = record[i].first;
        int b = record[i].second;
        int c = (getOP(p[a].first) + getOP(p[b].first)) / 2;
        int d = (getOP(p[a].second) + getOP(p[b].second)) / 2;
        maze[c][d] = 1;
    }
    maze[1][0] = maze[row - 2][col - 1] = 1;
}
void MainWindow::get_maze(){
    int nrow = row / 2, ncol = col / 2;
    make_maze(nrow,ncol);
    draw();
}

bool MainWindow::hasItems()
{
    return !scene->items().length()==0;
}
bool MainWindow::dfs(pair<int, int> from, pair<int, int> to, int row, int col)
{
    if(from == to) return true;
    int xx = from.first, yy = from.second;
    for(int i = 0;i < 4;i++){
        int nx = xx + dx[i];
        int ny = yy + dy[i];
        if(nx >= 0 && nx < row && ny >= 0 && ny < col && maze[nx][ny] == 1 && vis[nx][ny] != 1){
            vis[nx][ny] = 1;
            bool ok = dfs(make_pair(nx,ny), to, row, col);
            if(ok) {maze[nx][ny] = -1;return true;}
            vis[nx][ny] = 0;
        }
    }
    return false;
}
void MainWindow::search_path1(int row, int col){        //DFS
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            if(maze[i][j] < 0) maze[i][j] = 1;
        }
    }
    pair<int, int> from = make_pair(1,0);
    pair<int, int> to = make_pair(row - 2,col - 1);
    memset(vis,0,sizeof(vis));
    vis[from.first][from.second] = 1;
    maze[from.first][from.second] = -1;
    bool ok = dfs(from,to,row,col);

}
void MainWindow::get_path1() {
    clock_t t1 = clock();
    search_path1(row,col);
    draw();
    int t = (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000;
    QString str = QString("%1").arg(t);
    ui->time1->setText(str);
}
void MainWindow::search_path2(int row,int col){		//BFS
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            if(maze[i][j] < 0) maze[i][j] = 1;
        }
    }
    map<pair<int, int>, pair<int, int> > from;
    pair<int, int> start = make_pair(1,0);
    pair<int, int> end = make_pair(row - 2,col - 1);
    queue<pair<int, int> > q;
    q.push(start);
    from[start] = make_pair(0,0);
    memset(vis,0,sizeof(vis));
    vis[start.first][start.second] = 1;
    maze[start.first][start.second] = -2;
    while(!q.empty()){
        pair<int, int> e = q.front();q.pop();
        if(e == end) break;
        int xx = e.first, yy = e.second;
        for(int i = 0;i < 4;i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && maze[nx][ny] == 1 && vis[nx][ny] != 1){
                vis[nx][ny] = 1;
                q.push(make_pair(nx,ny));
                from[make_pair(nx,ny)] = e;
            }
        }
    }
    pair<int, int> x = end;
    while(from[x] != make_pair(0,0)){
        maze[x.first][x.second] = -2;
        x = from[x];
    }
}

void MainWindow::get_path2() {
    clock_t t1 = clock();
    search_path2(row,col);
    draw();
    int t = (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000;
    QString str = QString("%1").arg(t);
    ui->time2->setText(str);
}
