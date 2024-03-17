#include <QApplication>
#include <QComboBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QtPlugin>
#include <iostream>

#include "sdr.h"

Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);

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

  //  Create a button to start the SDR
  QPushButton *startButton = new QPushButton("Start");
  layout->addWidget(startButton);

  // If the button is clicked, start the SDR
  QObject::connect(startButton, &QPushButton::clicked, [&sdr, &comboBox]()
                   { std::cout << "Starting SDR with device: " << comboBox->currentText().toStdString() << std::endl; });

  mainWindow.setWindowTitle("Dropdown Example");
  mainWindow.show();

  return app.exec();
}