#include "QMessageBox"
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <cmath>

#include "./ui_mainwindow.h"
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  double start, end, step, x, y;
  QString s1, s2, s3, str("");

  s1 = ui->lineEdit->text();
  start = s1.toDouble();
  s2 = ui->lineEdit_2->text();
  end = s2.toDouble();
  s3 = ui->lineEdit_3->text();
  step = s3.toDouble();

  series = new QLineSeries();

  for (x = start; x <= end; x = x + step) {
    y = pow(M_E, abs(2.5 + x));
    series->append(x, y);
    str = str + "x=" + s1.number(x) + "\ty=" + s1.number(y) + "\n";
  }

  QMessageBox::information(this, "Result:", str);
}

void MainWindow::on_grapgh_clicked() {
  QChart *chart = new QChart();

  chart->setAnimationOptions(QChart::AllAnimations);
  chart->legend()->hide();
  chart->addSeries(series);
  chart->createDefaultAxes();
  chart->setTitle("Graph of function y(x) = e^|2.5+x|");

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setMinimumSize(640, 480);

  QMainWindow *window = new QMainWindow();
  window->setCentralWidget(chartView);
  window->show();
}
