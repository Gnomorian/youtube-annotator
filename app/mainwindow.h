#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "youtubevideostate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAnnotate_clicked();
    void onYoutubeData(const YoutubeVideoState& data);
private:
    Ui::MainWindow *ui;
    YoutubeVideoState latestVideoState;
};
#endif // MAINWINDOW_H
