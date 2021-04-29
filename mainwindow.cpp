#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "youtubeannotationstore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->videoplayer, &YoutubePlayer::youtubeDataUpdated, this, &MainWindow::onYoutubeData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAnnotate_clicked()
{
    //TODO: add an annotation for current video at current video position
    ui->listAnnotations->addAnnotation(latestVideoState);
}

void MainWindow::onYoutubeData(const YoutubeVideoState &data)
{
    latestVideoState = data;
    ui->statusbar->showMessage(QString("%1 at %2").arg(data.videoUrlAsString()).arg(data.PlayerDuration()));
}
