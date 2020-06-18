#include "mainwindow.h"
#include <algorithm>
#include "./ui_mainwindow.h"
#include <experimental/random>

using namespace std;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MakePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//@todo: clean this function when real data can be read
void MainWindow::MakePlot()
{
    // sample data
    //@todo: get real data
    const int       time         = 60;
    const int       n_samples_s1 = 1500;
    QVector<double> signal_1(n_samples_s1);
    for (int i = 0; i < n_samples_s1; ++i)
    {
        signal_1[i] = i * std::sin(i / 100) - 500;
    }

    const int       n_samples_s2 = 400;
    QVector<double> signal_2(n_samples_s2);
    for (int i = 0; i < n_samples_s2; ++i)
    {
        signal_2[i] = i;
    }

    const int       n_samples_s3 = 100;
    QVector<double> signal_3(n_samples_s3);
    for (int i = 0; i < n_samples_s3; ++i)
    {
        signal_3[i] = 500 * std::cos(i / 10) - 500;
    }

    PlotSignal(signal_1, time);
    PlotSignal(signal_2, time);
    PlotSignal(signal_3, time);
    auto       vetor_type = signal_1.toStdVector();
    const auto min        = std::min_element(vetor_type.begin(), vetor_type.end());
    const auto max        = std::max_element(vetor_type.begin(), vetor_type.end());
    // give the axes some labels:
    ui->plot_container->xAxis->setLabel("Time");
    ui->plot_container->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot_container->yAxis->setRange(*min, *max);
    ui->plot_container->xAxis->setRange(0, time);
    ui->plot_container->legend->setVisible(true);
    ui->plot_container->replot();
}

void MainWindow::PlotSignal(const QVector<double> signal, const double seconds)
{
    QVector<double> time_coordinates(signal.size());
    const double    delta_time = seconds / signal.size();
    for (int iterator = 0; iterator < time_coordinates.size(); ++iterator)
    {
        time_coordinates[iterator] = delta_time * iterator;
    }
    ui->plot_container->addGraph();
    ui->plot_container->graph()->setData(time_coordinates, signal);
    QPen aux_pen(QColor(std::experimental::randint(0, 255), std::experimental::randint(0, 255),
                        std::experimental::randint(0, 255)),
                 2);
    ui->plot_container->graph()->setPen(aux_pen);
}