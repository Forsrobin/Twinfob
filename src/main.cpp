#include <QApplication>
#include <QComboBox>
#include <QVBoxLayout>
#include <QMainWindow>

#include <iostream>
#include "sdr.h"

int main(int argc, char *argv[])
{
  SDR sdr;
  std::vector<std::string> devices = sdr.getDevices();

  QApplication app(argc, argv);

  QMainWindow mainWindow;
  QWidget *centralWidget = new QWidget(&mainWindow);
  mainWindow.setCentralWidget(centralWidget);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  QComboBox *comboBox = new QComboBox();
  for (int i = 0; i < devices.size(); ++i)
  {
    comboBox->addItem(QString::fromStdString(devices[i]));
  }

  layout->addWidget(comboBox);

  mainWindow.setWindowTitle("Dropdown Example");
  mainWindow.show();

  return app.exec();
}