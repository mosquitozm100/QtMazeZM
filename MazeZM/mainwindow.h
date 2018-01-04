#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
const int maxn = 200 + 10;
const int maxm = 40010;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int find(int x);
    int getOP(int x);
    void init();
    void make_maze(int nrow, int ncol);
    bool hasItems();
    void search_path1(int row, int col);       //DFS
    void search_path2(int row,int col);         //BFS
    bool dfs(pair<int, int> from, pair<int, int> to, int row, int col);
    void get_path1();
    void get_path2();
    void get_maze();
    void draw();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    qreal W;
    qreal H;
    int row = 61;
    int col = 61;
    bool isClear = true;
    int maze[201][201];
    int nrow, ncol;		//计算时的行列
    pair<int, int> p[maxm];		//记录每一个计算点的坐标
    pair<int, int> edges[maxm];		//记录每一条计算边（pair内的点时计算点的编号
    vector<pair<int, int> > record;		//记录拆掉的墙
    map<pair<int, int>,int> map1;		//计算点坐标换算为编号
    int fa[maxm];		//并查集
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int vis[maxn][maxn];

};

#endif // MAINWINDOW_H
